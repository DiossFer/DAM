/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.monitorjava.hebras;

import com.mycompany.monitorjava.datos_compartidos.Buffer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author diosfer
 */
public class hebraProductora implements Runnable{ 
    
  
    private Thread thr ; // objeto hebra encapsulado
  
    private Buffer monitorBuffer;
  
    public hebraProductora( String nombre, Buffer dc){

      this.thr = new Thread( this, nombre );
      this.monitorBuffer = dc;

    }

    @Override
    public void run(){


        do{

            monitorBuffer.producir(this.getThread().getName());
            

        }while (!monitorBuffer.getTerminanProductoras());


    }

    public Thread getThread (){
        return thr;
    }
}