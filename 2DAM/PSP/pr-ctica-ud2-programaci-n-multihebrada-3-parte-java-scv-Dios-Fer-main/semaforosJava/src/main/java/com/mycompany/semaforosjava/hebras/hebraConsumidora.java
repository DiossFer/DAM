/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.semaforosjava.hebras;

import com.mycompany.semaforosjava.datos_compartidos.datosCompartidos;

/**
 *
 * @author diosfer
 */
public class hebraConsumidora implements Runnable{ 
    

    private Thread thr ; // objeto hebra encapsulado

    private datosCompartidos data;

    public hebraConsumidora( String nombre, datosCompartidos dc){

      this.thr = new Thread( this, nombre );
      this.data = dc;

    }

    @Override
    public void run(){


        do{


            try {
                //Esperamos que halla hueco
                data.getSemaphoreElementos().acquire();
                
                //Esperamos que no se este modificando el buffer
                data.getSemaphoreMutex().acquire();
                
                // produces
                
                data.setBufferPos(data.getPosicionConsumir(), 0);
                
                
                // Mensaje
                System.out.print ( "HebraConsumidora(" + this.getThread().getName() + ") consume en posición " + data.getPosicionConsumir() + "\n" );
                for (int j=0; j < data.getBuffer().size(); j++){
                    
                    if (j==data.getPosicionConsumir()){
                        System.out.print ( data.getColorRojo()+ data.getBufferpos(j) + " " + data.getResetColor());
                    }
                    else{
                        System.out.print (data.getBufferpos(j)+" ");
                    }
                    
                }
                System.out.print("\n");
                
                
                // Posicionamos la siguiente posicion
                data.actualizarPosicionConsumir();
                
                // Indicamos que ha salido de modificar el buffer
                data.getSemaphoreMutex().release();
                
                // Indicamos que ahora hay un elemento mas que consumir
                data.getSemaphoreVacio().release();
                
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }

        }while (!data.getTerminanConsumidoras());


    }

    public Thread getThread (){
        return thr;
    }
}