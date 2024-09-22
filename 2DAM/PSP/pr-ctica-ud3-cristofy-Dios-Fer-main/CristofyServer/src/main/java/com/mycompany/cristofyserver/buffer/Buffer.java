/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyserver.buffer;

import com.mycompany.cristofyserver.CristofyServerThread;
import com.mycompany.cristofyserver.conexion.Conexion;
import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author DiosFer
 */
public class Buffer {
    
    Integer portNumber;
    
    final Lock mutex;
    
    final Lock semaforoBD;
    
    ArrayList <String> mensajes;
    ArrayList <CristofyServerThread> arrayListCristofyServerThread;
    
    private Conexion conn = new Conexion ();
    
    public Buffer (Integer pn){
        
        portNumber = pn;
        
        mutex = new ReentrantLock();
        semaforoBD = new ReentrantLock();
        mensajes = new ArrayList<>();
        
    }
    
    public Integer getPortNumber (){
        return this.portNumber;
    }
    
    public Lock getMutex(){
        return this.mutex;
    }
    public Lock getSemaforoBD(){
        return this.semaforoBD;
    }
    
    public ArrayList<String> getMensajes(){
        return this.mensajes;
    }
    
    public void setMensaje(String s){
        mensajes.add(s);
    }

    public ArrayList<CristofyServerThread> getArrayListCristofyServerThread() {
        return arrayListCristofyServerThread;
    }

    public void setArrayListCristofyServerThread(ArrayList<CristofyServerThread> arrayListCristofyServerThread) {
        this.arrayListCristofyServerThread = arrayListCristofyServerThread;
    }

    public Conexion getConn() {
        return conn;
    }

    
}
