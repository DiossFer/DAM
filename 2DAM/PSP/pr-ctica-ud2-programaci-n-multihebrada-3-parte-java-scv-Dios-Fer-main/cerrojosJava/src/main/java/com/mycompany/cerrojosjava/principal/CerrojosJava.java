/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.cerrojosjava.principal;

import com.mycompany.cerrojosjava.hebras.hebraConsumidora;
import com.mycompany.cerrojosjava.hebras.hebraProductora;
import com.mycompany.cerrojosjava.datos_compartidos.datosCompartidos;
import java.util.ArrayList;

/**
 *
 * @author diosfer
 */
public class CerrojosJava {

    public static void main(String[] args) {
        
        
        if (args.length != 5){
            System.out.println("Parametros no validos");
        }
        else{
            
            // Obtenemos los datos
            // tamanioBuffer numHebrasProductoras terminanProductoras numHebrasConsumidoras terminanConsumidoras
            datosCompartidos data = new datosCompartidos(   Integer.parseInt(args[0]), 
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
