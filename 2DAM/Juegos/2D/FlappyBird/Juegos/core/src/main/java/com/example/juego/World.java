/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.example.juego;

import com.badlogic.gdx.math.MathUtils;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.utils.Array;
import com.badlogic.gdx.utils.TimeUtils;

/**
 *
 * @author DiosFer
 */
public class World {
    public static final float gravedad = 0.35f;
    public static float velocidad;
            
    
    public static Rectangle bird;
    public static Array<Rectangle> tuberias;
    public static Array<Rectangle> espacio;
    
    public World (){
        velocidad = 0f;
        
        // create a Rectangle to logically represent the bird
        bird = new Rectangle();
        bird.x = 60; // center the bird horizontally
        bird.y = 480 / 2 - 64 / 2; // bottom left corner of the bird is 20 pixels above
                                        // the bottom screen edge
        bird.width = 34;
        bird.height = 24;

        // create the tuberias array and spawn the first spawn
        tuberias = new Array<Rectangle>();

        espacio = new Array<Rectangle>();
        
        
    }
    public long spawnTuberia() {
        
        int num = MathUtils.random(120, 360);
        
        //tuberia1
        Rectangle tubo1 = new Rectangle();
        tubo1.y = num+51;
        tubo1.x = 800;
        tubo1.width = 52;
        tubo1.height = 320;
        tuberias.add(tubo1);

        //tuberia2
        Rectangle tubo2 = new Rectangle();
        tubo2.y = num-320-51;
        tubo2.x = 800;
        tubo2.width = 52;
        tubo2.height = 320;
        tuberias.add(tubo2);

        //hueco
        Rectangle tubo3 = new Rectangle();
        tubo3.y = tubo2.y+tubo2.height;
        tubo3.x = 800;
        tubo3.width = 52;
        tubo3.height = 320;
        espacio.add(tubo3);
        
        long delta=TimeUtils.nanoTime();
        return delta;

    }
    
}
