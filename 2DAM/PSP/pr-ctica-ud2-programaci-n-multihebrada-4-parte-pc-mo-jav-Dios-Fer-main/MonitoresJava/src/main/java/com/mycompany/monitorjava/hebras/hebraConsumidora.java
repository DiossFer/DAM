/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.monitorjava.hebras;

import com.mycompany.monitorjava.datos_compartidos.Buffer;

/**
 *
 * @author diosfer
 */
public class hebraConsumidora implements Runnable{ 
    

    private Thread thr; // objeto hebra encapsulado

    private Buffer monitorBuffer;

    public hebraConsumidora( String nombre, Buffer dc){

      this.thr = new Thread( this, nombre );
      this.monitorBuffer = dc;

    }

    @Override
    public void run(){


        do{

            monitorBuffer.consumir(this.getThread().getName());

        }while (!monitorBuffer.getTerminanConsumidoras());


    }

    public Thread getThread (){
        return thr;
    }
}