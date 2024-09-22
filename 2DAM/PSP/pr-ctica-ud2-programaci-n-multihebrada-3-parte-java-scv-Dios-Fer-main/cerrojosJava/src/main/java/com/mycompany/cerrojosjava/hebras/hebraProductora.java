/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cerrojosjava.hebras;

import com.mycompany.cerrojosjava.datos_compartidos.datosCompartidos;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author diosfer
 */
public class hebraProductora implements Runnable{ 
    
  
    private Thread thr ; // objeto hebra encapsulado
  
    private datosCompartidos data;
  
    public hebraProductora( String nombre, datosCompartidos dc){

      this.thr = new Thread( this, nombre );
      this.data = dc;

    }

    @Override
    public void run(){


        do{


            try {
                
                // Cerrojo de entrada
                data.getMutex().lock();
                
                while (data.getContador() == data.getBuffer().size()){
                    
                    data.getElementos().await(); // Esperamos a poder salir con la variable de condicion
                    
                }
                
                
                // produces
                
                data.setBufferPos(data.getPosicionProducir(), 1);
                
                
                // Mensaje
                System.out.print ( "HebraProductora(" + this.getThread().getName()  + ") produce en posición " + data.getPosicionProducir() + "\n" );
                for (int j=0; j < data.getBuffer().size(); j++){
                    
                    if (j==data.getPosicionProducir()){
                        System.out.print ( data.getColorVerde() + data.getBufferpos(j) + " " + data.getResetColor());
                    }
                    else{
                        System.out.print (data.getBufferpos(j)+" ");
                    }
                    
                }
                System.out.print("\n");
                
                // Actualizamos el contador
                data.setContador(data.getContador()+1);
                
                // Posicionamos la siguiente posicion
                data.actualizarPosicionProducir();
                
                // mandamos la señal para el resto de hebras
                data.getVacio().signalAll();
                
                // salimos del cerrojo
                data.getMutex().unlock();
                
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }

        }while (!data.getTerminanProductoras());


    }

    public Thread getThread (){
        return thr;
    }
}