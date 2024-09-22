package com.mycompany.cristofyclient;

import com.mycompany.CristofyClient.CristofyProtocol;
import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class HebraCristofyClientEscucha implements Runnable {
    
    Buffer buffer;
    
    Thread thr;
    
    
    public HebraCristofyClientEscucha (Buffer b){
         this.buffer = b;
         thr = new Thread(this, "CristofyClientEscucha");
         
    }
    
    @Override
    public void run(){
        String fromServer;
        
        try {
            while ((fromServer = buffer.getIn().readLine()) != null) {
                
                System.out.println("<=====DEBUG=====>");
                
                // Mensaje del servidor
                buffer.getLock().lock();
                buffer.setBuffer(buffer.getSocket().getInetAddress().getHostAddress() + " " + fromServer);
                buffer.getLock().unlock();
                
                System.out.println("DEBUG:: fromServer: "+fromServer);
                
                buffer.getCristofyProtocol().processInput(fromServer);
                
                
            }
        } catch (IOException ex) {
            //Logger.getLogger(HebraCristofyClientEscucha.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
    }
    
    public void iniciar () {
        thr.start();
        
    }
}