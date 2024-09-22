/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cerrojosjava.datos_compartidos;

import java.util.ArrayList;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author diosfer
 */
public class datosCompartidos {
    
    private int numHebrasProductoras;

    private boolean terminanProductoras;

    private int numHebrasConsumidoras;

    private boolean terminanConsumidoras;
    
    
    private ArrayList <Integer> buffer;
    
    
    private String colorVerde;
    private String colorRojo;
    private String resetcolor;
    
    
    private int posicionProducir;
    private int posicionConsumir;
    
    
    final Lock mutex;
    
    
    Condition vacio;
    
    Condition elementos;
    
    private int contador;
    

    public datosCompartidos(int tamanioBuffer, int numHebrasProductoras, boolean terminanProductoras, int numHebrasConsumidoras, boolean terminanConsumidoras) {
        
        this.numHebrasProductoras = numHebrasProductoras;
        
        this.terminanProductoras = terminanProductoras;
        
        this.numHebrasConsumidoras = numHebrasConsumidoras;
        
        this.terminanConsumidoras = terminanConsumidoras;
        
        this.buffer = new ArrayList <Integer>();
        
        
        this.colorVerde = "\033[32m";
        
        this.colorRojo = "\033[31m";
        
        this.resetcolor = "\u001B[0m";
        
        
        this.posicionProducir = 0;
        
        this.posicionConsumir = 0;

        
        mutex = new ReentrantLock();
        
        vacio = mutex.newCondition();
        
        elementos = mutex.newCondition();
        
        contador = 0;
        
        for (int i=0; i<tamanioBuffer; i++){
            buffer.add(0);
        }
        
    }

    
    /// Sets
    
    public void setNumHebrasProductoras(int numHebrasProductoras) {
        this.numHebrasProductoras = numHebrasProductoras;
    }

    public void setTerminanProductoras(boolean terminanProductoras) {
        this.terminanProductoras = terminanProductoras;
    }

    public void setNumHebrasConsumidoras(int numHebrasConsumidoras) {
        this.numHebrasConsumidoras = numHebrasConsumidoras;
    }

    public void setTerminanConsumidoras(boolean terminanConsumidoras) {
        this.terminanConsumidoras = terminanConsumidoras;
    }

    public void setBuffer(ArrayList<Integer> buffer) {
        this.buffer = buffer;
    }
    
    public void setBufferPos(int pos, int newDato) {
        this.buffer.set(pos, newDato);
    }
    
    public void setContador(int contador) {
        this.contador = contador;
    }

    
    /// Gets
    
    
    public int getNumHebrasProductoras() {
        return numHebrasProductoras;
    }

    public boolean getTerminanProductoras() {
        return terminanProductoras;
    }

    public int getNumHebrasConsumidoras() {
        return numHebrasConsumidoras;
    }

    public boolean getTerminanConsumidoras() {
        return terminanConsumidoras;
    }

    public ArrayList<Integer> getBuffer() {
        return buffer;
    }
    
    public Integer getBufferpos(int pos) {
        return buffer.get(pos);
    }

    public String getColorVerde() {
        return colorVerde;
    }

    public String getColorRojo() {
        return colorRojo;
    }

    public String getResetColor() {
        return resetcolor;
    }
    
    public int getPosicionProducir() {
        return posicionProducir;
    }
    
    public int getPosicionConsumir() {
        return posicionConsumir;
    }

    public void actualizarPosicionProducir (){
        posicionProducir=(posicionProducir+1)%buffer.size();
    }
    
    public void actualizarPosicionConsumir (){
        posicionConsumir=(posicionConsumir+1)%buffer.size();
    }
    
    public Lock getMutex(){
        return this.mutex;
    }
    
    public Condition getVacio(){
        return this.vacio;
    }
    
    public Condition getElementos(){
        return this.elementos;
    }

    public int getContador() {
        return contador;
    }
    
}
