/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.monitorjava.principal;

import com.mycompany.monitorjava.hebras.hebraConsumidora;
import com.mycompany.monitorjava.hebras.hebraProductora;
import com.mycompany.monitorjava.datos_compartidos.Buffer;
import java.util.ArrayList;

/**
 *
 * @author diosfer
 */
public class MonitorJava {

    public static void main(String[] args) {
        
        
        if (args.length != 5){
            System.out.println("Parametros no validos");
        }
        else{
            
            // Obtenemos los datos
            // tamanioBuffer numHebrasProductoras terminanProductoras numHebrasConsumidoras terminanConsumidoras
            Buffer data = new Buffer(   Integer.parseInt(args[0]), 
                                                            Integer.parseInt(args[1]), 
                                                            Boolean.parseBoolean(args[2]), 
                                                            Integer.parseInt(args[3]), 
                                                            Boolean.parseBoolean(args[4])
                                                        );
            
            
            // ArrayList de hebras
            
            ArrayList <hebraProductora> hebrasProductoras = new ArrayList <hebraProductora>();
            
            ArrayList <hebraConsumidora> hebrasConsumidoras = new ArrayList <hebraConsumidora>();
            
            
            
            
            // Iniciamos productoras
            for( int i = 0 ; i < data.getNumHebrasProductoras() ; i++ ){
                hebrasProductoras.add (new hebraProductora(""+i, data));
                hebrasProductoras.get(i).getThread().start();
            }

            // Iniciamos consumidoras
            for( int i = 0 ; i < data.getNumHebrasConsumidoras() ; i++ ){ 
                hebrasConsumidoras.add (new hebraConsumidora(""+i, data));
                hebrasConsumidoras.get(i).getThread().start();
            }


            
            // Esperamos
            for( int i = 0 ; i < data.getNumHebrasProductoras() ; i++ ){
                try {
                    hebrasProductoras.get(i).getThread().join();
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }

            // Esperamos
            for( int i = 0 ; i < data.getNumHebrasConsumidoras() ; i++ ){ 
                try {
                    hebrasConsumidoras.get(i).getThread().join();
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
        
        
        }
    }
}
