package com.mycompany.cristofyserver;

import com.mycompany.CristofyServer.CristofyProtocol;
import java.net.*;
import java.io.*;
import com.mycompany.cristofyserver.buffer.Buffer;
import com.mycompany.cristofyserver.modelo.Cancion;
import com.mycompany.cristofyserver.modelo.Estadistica;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
/**
 *
 * @author DiosFer
 */
public class CristofyServerThread implements Runnable {
    private Socket socket = null;
    private Thread thr = null;
    private boolean fin = false;
    Boolean finForzado = false;
    Buffer buffer;
    
    PrintWriter out;
    BufferedReader in;
    
    public CristofyServerThread(Buffer b, Socket socket) {
        thr = new Thread (this, "CristofyServerThread");
        this.socket = socket;
        buffer = b;
    }
    
    @Override
    public void run() {
        
        try {
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(
                new InputStreamReader(
                    socket.getInputStream()));
            
            String inputLine, outputLine;
            CristofyProtocol cfp = new CristofyProtocol(buffer, out);
            outputLine = cfp.processInput(null);
            
            
            out.println(outputLine);

            while (!fin) {
                
                inputLine = in.readLine();
                
                if (!finForzado){
                    if ( inputLine == null){
                        fin = true;
                    }
                    else{


                        //System.out.println("DEBUG:: Conexion:: " + socket.getLocalAddress().toString());
                        //System.out.println("DEBUG:: out:: " + outputLine);
                        //System.out.println("DEBUG:: in:: " + inputLine);

                        buffer.setMensaje(socket.getInetAddress().getHostAddress()+ " " + inputLine);
                        
                        System.out.println("DEBUG--Recibo--> "+inputLine);
                        
                        outputLine = cfp.processInput(inputLine);
                        
                        System.out.println("DEBUG--Mando--> "+outputLine);
                        
                        
                        if ((outputLine.split("#").length==8 && outputLine.split("#")[2].equals("GET_SONG")) && outputLine.split("#")[7].equals("FINISHED")){
                            // No requiere de constestacion del server 
                            
                            System.out.println("DEBUG:: Actualizo Reproducciones");
                            
                            //Actualizar las reproducciones
                            buffer.getSemaforoBD().lock();
                            
                            Cancion c = buffer.getConn().getCancionById(Long.parseLong(outputLine.split("#")[3]));
                            
                            Estadistica e = c.getEstadisticaCancion();
                            e.setNumReproducciones(e.getNumReproducciones()+1);
                            buffer.getConn().updateEstadistica(e);
                            
                            
                            buffer.getSemaforoBD().unlock();
                            
                            
                        }else{
                            out.println(outputLine);
                        }
                        
                        
                        // Si se ha validado un cerrado de sesion cerramos la conexion
                        if ((outputLine.split("#").length==6)&&(outputLine.split("#")[2].equals("SEEYOU"))){
                            buffer.getArrayListCristofyServerThread().remove(this);
                            for (CristofyServerThread cfst : buffer.getArrayListCristofyServerThread()){
                                if (cfst!=null){
                                    cfst.enviarMensaje(cfp.prepararMensajeDesconexion());
                                }
                                
                            }
                            break;
                        }
                        

                        //buffer.setMensaje(socket.getInetAddress().getHostAddress()+ " Se ha conectado" + "("+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+")");


                    }
                }else{
                    out.println("Bye");
                    buffer.getMutex().lock();
                    buffer.setMensaje(socket.getLocalAddress().toString() + " Se ha desconectado");
                    buffer.getMutex().unlock();
                }

            }
            
            //System.out.println("Cerrando el Socket");
            socket.close();
            //System.out.println("Cerrado el Socket");
        } catch (IOException e) {
            
        }
    }
    
    public void startThread (){
        thr.start();
    }
    public void cerarConexion(){
        finForzado = true;
        fin = true;
    }
    public void enviarMensaje (String mensaje){
        out.println(mensaje);
    }
}