/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cerrojosjava.hebras;

import com.mycompany.cerrojosjava.datos_compartidos.datosCompartidos;

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
                
                // Cerrojo de entrada
                data.getMutex().lock();
                
                while (data.getContador() == 0){
                    
                    data.getVacio().await(); // Esperamos a poder salir con la variable de condicion
                    
                }
                
                // consumes
                
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
                
                // Actualizamos el contador
                data.setContador(data.getContador()-1);
                
                // Posicionamos la siguiente posicion
                data.actualizarPosicionConsumir();
                
                // mandamos la señal para el resto de hebras
                data.getElementos().signalAll();
                
                // salimos del cerrojo
                data.getMutex().unlock();
                
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }

        }while (!data.getTerminanConsumidoras());


    }

    public Thread getThread (){
        return thr;
    }
}