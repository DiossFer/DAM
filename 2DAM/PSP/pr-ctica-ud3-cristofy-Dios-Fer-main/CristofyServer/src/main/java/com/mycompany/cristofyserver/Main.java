/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyserver;

import com.mycompany.cristofyserver.buffer.Buffer;
import com.mycompany.cristofyserver.vista.VentanaServer;
import java.io.IOException;

/**
 *
 * @author DiosFer
 */
public class Main {
    
    public static void main(String[] args) throws IOException {
        
        if (args.length != 1) {
            System.err.println("Usage: java CristofyServer <port number>");
            System.exit(1);
        }
        
        Buffer buffer = new Buffer(Integer.parseInt(args[0]));
        
        VentanaServer v1;
        
        try{
            v1=new VentanaServer(buffer);
            v1.setVisible(true);
        }
        catch(Exception e){
            e.printStackTrace();
        }  
    }
         
    
}
