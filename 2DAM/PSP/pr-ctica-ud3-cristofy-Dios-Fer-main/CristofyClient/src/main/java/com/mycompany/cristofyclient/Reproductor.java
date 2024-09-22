/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyclient;

import java.io.File;
import java.io.FileInputStream;
import javazoom.jl.player.Player;
/**
 *
 * @author DiosFer
 */
public class Reproductor implements Runnable{
    
    Thread thr;
    FileInputStream fis;
    Player player;
    String ruta;
    
    public Reproductor (){
        thr = new Thread(this);
    }
    
    @Override
    public void run (){
        startSong();
    }
    
    public void startSong (){
        try {
            
            fis = new FileInputStream(ruta);
                
            player = new Player(fis);


            player.play();

        } catch (Exception ex) {
            System.out.println("ERROR");
            //ex.printStackTrace();
        }
    }
    
    public void stopSong (){
        if (player!=null && player.isComplete()==false){
            player.close();
        }
        
        
    }
    
    public void comenzarReproduccion (String ruta){
        this.ruta=ruta;
        thr.start();
        
    }
}
