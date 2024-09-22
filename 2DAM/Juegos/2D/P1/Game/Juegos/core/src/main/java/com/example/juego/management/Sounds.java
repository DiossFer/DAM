package com.example.juego.management;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.audio.Music;
import com.badlogic.gdx.audio.Sound;

/**
 *
 * @author DiosFer
 */
public class Sounds {
    public static Music backMusic;
    public static Sound enemyDamage;
    public static Sound enemyJumpGdx;
    public static Sound personajeDamageGdx;
    public static Sound personajeJump;
    
    public static Boolean volumen;
    
    public Sounds (){
        
    }
    
    public static void load (){
        backMusic = Gdx.audio.newMusic(Gdx.files.internal("Sounds/BackMusic.mp3"));
        backMusic.setLooping(true);
        enemyDamage = Gdx.audio.newSound(Gdx.files.internal("sounds/EnemyDamage.wav"));
        enemyJumpGdx = Gdx.audio.newSound(Gdx.files.internal("sounds/EnemyJump.wav"));
        personajeDamageGdx = Gdx.audio.newSound(Gdx.files.internal("sounds/PersonajeDamage.wav"));
        personajeJump = Gdx.audio.newSound(Gdx.files.internal("sounds/PersonajeJump.wav"));
        
    }
    
    public static void cambiarSonido (){
        if (volumen){
            volumen=false;
            backMusic.stop();
        }
        else{
            volumen=true;
            backMusic.play();
        }
    }
    
    public static void startBackMusic (){
        if (volumen){
            backMusic.play();
        }
    }
    
    public static void playSound (Sound s){
        if (volumen){
            s.play();
        }
    }
}
