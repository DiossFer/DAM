package com.mycompany.CristofyServer;

import com.mycompany.cristofyserver.CristofyServerThread;
import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import com.mycompany.cristofyserver.buffer.Buffer;
/**
 *
 * @author DiosFer
 */
public class HebraCristofyServer implements Runnable {
    
    Thread thr = null;
    Boolean listening;
    
    
    ServerSocket serverSocket;
    
    ArrayList <CristofyServerThread> hebrasServidor;
    
    Buffer buffer;
    
    public HebraCristofyServer(Buffer b) {
        thr = new Thread (this, "HebraServidor");
        buffer = b;
        hebrasServidor = new ArrayList<CristofyServerThread> ();
        buffer.setArrayListCristofyServerThread(hebrasServidor);
    }
    
    @Override
    public void run(){
        Boolean fin = true;

        listening = true;
        
        try 
        {
            serverSocket = new ServerSocket(buffer.getPortNumber());
            
            while (fin) {

                    CristofyServerThread cft = null;
                    
                    try {
                        cft = new CristofyServerThread(buffer, serverSocket.accept());
                    }
                    catch (SocketException e){
                        if (!listening){
                            fin=false;
                        }
                        
                    }
                    
                    
                    
                    
                    if (cft!=null){
                        hebrasServidor.add(cft);
                        cft.startThread();
                    }
                    
                    
                }
            
            }catch (IOException e) {
            System.err.println("Could not listen on port " + buffer.getPortNumber());
            System.exit(-1);
        }
    }
    
    public void Iniciar (){
        thr.start();
    }
    public void Cerrar (){
        try {
            listening=false;
            serverSocket.close();
            
            //Cerrar las conexiones ya abiertas
            for (CristofyServerThread cfst: hebrasServidor){
                cfst.cerarConexion();
            }
            
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
    
    
    
}