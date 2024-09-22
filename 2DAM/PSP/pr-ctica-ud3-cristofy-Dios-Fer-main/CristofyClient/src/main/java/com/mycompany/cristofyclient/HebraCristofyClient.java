package com.mycompany.cristofyclient;

import com.mycompany.CristofyClient.CristofyProtocol;
import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class HebraCristofyClient implements Runnable {
    
    Buffer buffer;
    
    Thread thr;
    
    CristofyProtocol cp;
    
    HebraCristofyClientEscucha hcce;
    
    public HebraCristofyClient (Buffer b){
         this.buffer = b;
         thr = new Thread(this, "CristofyClient");
         cp = new CristofyProtocol(buffer);
         buffer.setCristofyProtocol(cp);
    }
    
    @Override
    public void run(){
        
        
        
        boolean conexionValidada = false;
        try (
                
            Socket socket = new Socket(buffer.getHostName(), buffer.getPortNumber());
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(
                new InputStreamReader(socket.getInputStream()));
                
        ) {
            
            
            buffer.setOut(out);
            buffer.setIn(in);
            buffer.setSocket(socket);
            
            hcce = new HebraCristofyClientEscucha (buffer);
            hcce.iniciar();
            
            BufferedReader stdIn =
                new BufferedReader(new InputStreamReader(System.in));
            String fromServer;
            String fromUser;



            while (true) { 
                
                /*
                // Mensaje del servidor
                buffer.getLock().lock();
                buffer.setBuffer(socket.getInetAddress().getHostAddress() + " " + fromServer);
                buffer.getLock().unlock();

                cp.processInput(fromServer);
*/
                fromUser = "";
                
                try {
                    //semaforo para esperar la entrada por interfaz
                    buffer.getMutex().acquire();   
                    
                    if (buffer.getAccion().equals("LOGIN")){
                        fromUser = cp.prepareLogin(buffer.getMensaje());
                    }
                    else if (buffer.getAccion().equals("BYEBYE")){
                        fromUser = cp.prepareCloseSesion();
                    }
                    else if (buffer.getAccion().equals("GET_USERS_CONNECTED")){
                        fromUser = cp.prepareGetUserConn();
                    }
                    else if (buffer.getAccion().equals("GET_MUSIC")){
                        fromUser = cp.prepareGetMusic();
                    }
                    else if (buffer.getAccion().equals("GET_SONG")){
                        fromUser = cp.prepareGetSong(buffer.getId_cancion_seleccionada());
                    }
                    
                    else if (buffer.getAccion().equals("GET_MUSIC_BY_STRING")){
                        fromUser = cp.prepareGetSearch(buffer.getMensaje());
                    }
                    else if (buffer.getAccion().equals("GET_ARTIST_SONG")){
                        fromUser = cp.prepareGetArtist(buffer.getId_cancion_seleccionada());
                    }
                    
                    //fromUser = stdIn.readLine();
                } catch (InterruptedException ex) {
                    //Logger.getLogger(HebraCristofyClient.class.getName()).log(Level.SEVERE, null, ex);
                }



                if (fromUser.equals("exit")){ // Si es End es que se quiere terminar
                    out.println(fromUser);

                }
                
                if (fromUser != null) {

                    
                    out.println(fromUser);
                }

                
                
            }
        } catch (UnknownHostException e) {
            System.err.println("Don't know about host " + buffer.getHostName());
            System.exit(1);
        } catch (IOException e) {
            System.err.println("Couldn't get I/O for the connection to " +
                buffer.getHostName());
            System.exit(1);
        }
    }
    
    public void iniciar () {
        thr.start();
        
    }
}