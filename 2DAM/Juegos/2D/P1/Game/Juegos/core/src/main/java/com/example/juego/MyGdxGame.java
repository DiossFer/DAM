package com.example.juego;

import com.badlogic.gdx.Game;
import com.badlogic.gdx.graphics.g2d.Batch;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Preferences;
import com.example.juego.management.Puntos;
import com.example.juego.management.Sounds;
import com.example.juego.management.Textures;
import com.example.juego.screens.MainMenuScreen;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

/**
 *
 * @author DiosFer
 */
public class MyGdxGame extends Game {
	
    public Batch batch;
    public String dificultad;
    public Integer personajeActual;
    
    public int tipoPersonaje=1;
    
    private static final String PUNTUAJES = "puntuajes.csv";

    public enum GameState {
            START, RESUME;
    }
    
    public GameState gameState; 

    @Override
    public void create() {
    this.leerPreferencias();
    Textures.load();
    Sounds.load();
    batch = new SpriteBatch();
            setScreen(new MainMenuScreen(this));
    }

    @Override
    public void render() {
            super.render();
    }

    @Override
    public void resize(int width, int height) {
            getScreen().resize(width, height);
    }

    @Override
    public void dispose() {
            getScreen().dispose();
    }

    @Override
    public void pause() {

    }

    @Override
    public void resume()  {

    }

    public void leerPreferencias (){

        Preferences prefs = Gdx.app.getPreferences("AjustesUsuario");

        //Volumen
        Sounds.volumen = prefs.getBoolean("volumen", true); 

        //Dificultad
        dificultad  = prefs.getString("dificultad", "Normal"); 
        
        personajeActual  = prefs.getInteger("personajeActual", 1); 

    }
    
    public void savePreferences (){
        Preferences prefs = Gdx.app.getPreferences("AjustesUsuario");
        prefs.putBoolean("volumen", Sounds.volumen); 
        prefs.putString("dificultad", dificultad); 
        prefs.putInteger("personajeActual", personajeActual); 
        prefs.flush();
    }
    
    
    
    public void savePoints (Integer newPoint){
        
        String newName = "Player-"+personajeActual;
        ArrayList<Integer> oldPoints = readPoints();
        ArrayList<String> oldNames = readNames();
        ArrayList<Puntos> oldPuntos = new ArrayList<>();
        
        for (int i=0; i<oldPoints.size(); i++){
            oldPuntos.add(new Puntos(oldNames.get(i), oldPoints.get(i)));
        }
        if (oldPuntos.size()<10){
            oldPuntos.add(new Puntos(newName, newPoint));
            
            oldPuntos.sort(new Comparator<Puntos>() {
                @Override
                public int compare(Puntos p1, Puntos p2) {
                    return Integer.compare(p2.getPuntos(), p1.getPuntos());
                }

            });
            
            insertarPuntos(oldPuntos);
        }
        else if (newPoint>=oldPoints.get(oldPoints.size()-1)){
            oldPuntos.add(new Puntos(newName, newPoint));
            
            oldPuntos.sort(new Comparator<Puntos>() {
                @Override
                public int compare(Puntos p1, Puntos p2) {
                    return Integer.compare(p2.getPuntos(), p1.getPuntos());
                }

            });
            
            oldPuntos.remove(oldPuntos.size()-1);
            insertarPuntos(oldPuntos);
        }
        
    }
    public void insertarPuntos(ArrayList<Puntos> nuevosPuntos){
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(PUNTUAJES))) {
            for (Puntos punto : nuevosPuntos) {
                bw.write(punto.getNombre() + "," + punto.getPuntos());
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static ArrayList<Integer> readPoints() {
        
        ArrayList<Integer> puntosCSV = new ArrayList<>();
        
        try (BufferedReader br = new BufferedReader(new FileReader(PUNTUAJES))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] nombrePuntos = line.split(",");
                puntosCSV.add(Integer.parseInt(nombrePuntos[1]));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return puntosCSV;
    }
    
    public static ArrayList<String> readNames() {
        
        ArrayList<String> nombresCSV = new ArrayList<>();
        
        try (BufferedReader br = new BufferedReader(new FileReader(PUNTUAJES))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] nombrePuntos = line.split(",");
                nombresCSV.add(nombrePuntos[0]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return nombresCSV;
    }
    
    
    public static String obtenerPuntuajes() {
        
        String s="";
        try (BufferedReader br = new BufferedReader(new FileReader(PUNTUAJES))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] nombrePuntos = line.split(",");
                s+=(nombrePuntos[0]+" ==> Points: "+nombrePuntos[1]+"\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return s;
    }
    
    
    
}