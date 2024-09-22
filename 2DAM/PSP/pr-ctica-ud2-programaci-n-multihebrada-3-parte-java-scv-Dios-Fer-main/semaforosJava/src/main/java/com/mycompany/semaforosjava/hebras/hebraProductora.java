/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.semaforosjava.hebras;

import com.mycompany.semaforosjava.datos_compartidos.datosCompartidos;
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
                //Esperamos que halla hueco
                data.getSemaphoreVacio().acquire();
                
                //Esperamos que no se este modificando el buffer
                data.getSemaphoreMutex().acquire();
                
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
                
                
                // Posicionamos la siguiente posicion
                data.actualizarPosicionProducir();
                
                // Indicamos que ha salido de modificar el buffer
                data.getSemaphoreMutex().release();
                
                // Indicamos que ahora hay un elemento mas que consumir
                data.getSemaphoreElementos().release();
                
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }

        }while (!data.getTerminanProductoras());


    }

    public Thread getThread (){
        return thr;
    }
}