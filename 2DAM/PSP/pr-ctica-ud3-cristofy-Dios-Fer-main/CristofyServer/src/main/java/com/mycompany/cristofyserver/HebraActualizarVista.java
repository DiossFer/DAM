/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyserver;

import com.mycompany.cristofyserver.buffer.Buffer;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTextArea;

/**
 *
 * @author DiosFer
 */
public class HebraActualizarVista implements Runnable {
    JTextArea jta;
    Buffer buffer;
    Thread thr;
    String mensaje;
            
    public HebraActualizarVista (Buffer buf, JTextArea j){
        buffer = buf;
        jta=j;
        thr = new Thread(this);
    }
    
    @Override
    public void run (){
        while (true){
            mensaje="";
            for (String s : buffer.getMensajes()){
                mensaje+=s;
                mensaje+="\n";
            }
            jta.setText(mensaje);
            

            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(HebraActualizarVista.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            
        }
    }
    
    public void startActualizacion(){
        thr.start();
    }
    
}
