/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyserver.controller;

import com.mycompany.CristofyServer.HebraCristofyServer;
import com.mycompany.cristofyserver.buffer.Buffer;

/**
 *
 * @author DiosFer
 */
public class Controller {
    
    HebraCristofyServer server;
    Buffer buffer;
    
    public Controller (Buffer b){
        buffer = b;
    }
    
    public void iniciarServer (){
        //server
        server = new HebraCristofyServer (buffer);
        server.Iniciar();
    }
    
    public void cerrarServer (){
        //server
        server.Cerrar();
    }
    
    
}
