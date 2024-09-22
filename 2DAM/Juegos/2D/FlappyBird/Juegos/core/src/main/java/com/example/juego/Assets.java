/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.example.juego;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.audio.Music;
import com.badlogic.gdx.audio.Sound;
import com.badlogic.gdx.graphics.Texture;

/**
 *
 * @author DiosFer
 */
public class Assets {
	public static Texture fondoNoche;
	

	public static Music backMusic;
        
        
	public static Sound jumpSound;
	public static Sound highJumpSound;
        
	public static Texture imagenTubo1;
        public static Texture suelo;
        public static Texture fondoDia;
        public static Texture imagenTubo2;
        public static Texture birdImage;
        
        public static Sound pointSound;
        public static Sound hitSound;
    
	public static Texture loadTexture (String file) {
		return new Texture(Gdx.files.internal(file));
	}

	public static void load () {
            fondoNoche = new Texture(Gdx.files.internal("sprites/background-night.png"));
            imagenTubo1 = new Texture(Gdx.files.internal("sprites/pipe-green1.png"));
            imagenTubo2 = new Texture(Gdx.files.internal("sprites/pipe-green2.png"));
            fondoDia =  new Texture(Gdx.files.internal("sprites/background-day.png"));
            suelo =  new Texture(Gdx.files.internal("sprites/base.png"));
            birdImage = new Texture(Gdx.files.internal("sprites/yellowbird-upflap.png"));
            
            pointSound = Gdx.audio.newSound(Gdx.files.internal("audio/point.wav"));
            hitSound = Gdx.audio.newSound(Gdx.files.internal("audio/hit.wav"));
            
            backMusic = Gdx.audio.newMusic(Gdx.files.internal("audio/musicChill.mp3"));
            backMusic.setLooping(true);
		
	}

	public static void playSound (Sound sound) {
		sound.play();
	}
        
}