/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.monitorjava.datos_compartidos;

import java.util.ArrayList;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author diosfer
 */
public class Buffer {
    
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
    
    
    
    private int contador;
    

    public Buffer(int tamanioBuffer, int numHebrasProductoras, boolean terminanProductoras, int numHebrasConsumidoras, boolean terminanConsumidoras) {
        
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

        
        contador = 0;
        
        for (int i=0; i<tamanioBuffer; i++){
            buffer.add(0);
        }
        
    }

    /// Operaciones Monitor
    
    public synchronized void producir (String id){
        try {

            // Entrada en exclusiuon mutua

            while (this.getContador() == this.getBuffer().size()){

                wait(); //Esperamos pues no podemos producir
            }


            // produces

            this.setBufferPos(this.getPosicionProducir(), 1);


            // Mensaje
            System.out.print ( "HebraProductora(" + id  + ") produce en posición " + this.getPosicionProducir() + "\n" );
            for (int j=0; j < this.getBuffer().size(); j++){

                if (j==this.getPosicionProducir()){
                    System.out.print ( this.getColorVerde() + this.getBufferpos(j) + " " + this.getResetColor());
                }
                else{
                    System.out.print (this.getBufferpos(j)+" ");
                }

            }
            System.out.print("\n");

            // Actualizamos el contador
            this.setContador(this.getContador()+1);

            // Posicionamos la siguiente posicion
            this.actualizarPosicionProducir();

            notifyAll(); // Notificamos que ya hemos consumido

            

        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }
    }
    
    public synchronized void consumir (String id){
        
        try {

            // Entrada en exclusiuon mutua

            while (this.getContador() == 0){

                wait(); //Esperamos pues no podemos consumir
            }

            // consumes

            this.setBufferPos(this.getPosicionConsumir(), 0);


            // Mensaje
            System.out.print ( "HebraConsumidora(" + id + ") consume en posición " + this.getPosicionConsumir() + "\n" );
            for (int j=0; j < this.getBuffer().size(); j++){

                if (j==this.getPosicionConsumir()){
                    System.out.print ( this.getColorRojo()+ this.getBufferpos(j) + " " + this.getResetColor());
                }
                else{
                    System.out.print (this.getBufferpos(j)+" ");
                }

            }
            System.out.print("\n");

            // Actualizamos el contador
            this.setContador(this.getContador()-1);

            // Posicionamos la siguiente posicion
            this.actualizarPosicionConsumir();

            
            notifyAll(); // Notificamos que ya hemos consumido

            

        } catch (InterruptedException ex) {
            ex.printStackTrace();
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
    

    public int getContador() {
        return contador;
    }
    
}
