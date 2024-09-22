package com.example.juego.screens;

import com.badlogic.gdx.*;
import com.badlogic.gdx.graphics.*;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.maps.tiled.*;
import com.badlogic.gdx.maps.tiled.renderers.*;
import com.badlogic.gdx.scenes.scene2d.*;
import com.badlogic.gdx.scenes.scene2d.ui.Image;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.example.juego.MyGdxGame;
import com.example.juego.entidades.Entidad;
import com.example.juego.entidades.enemigos.Enemigo1;
import com.example.juego.entidades.enemigos.Enemigo2;
import com.example.juego.entidades.enemigos.Enemigo3;
import com.example.juego.entidades.personajes.Personaje1;
import com.example.juego.entidades.personajes.Personaje2;
import com.example.juego.entidades.personajes.Personaje3;
import com.example.juego.management.Sounds;
import com.example.juego.management.Textures;
import java.util.ArrayList;

/**
 *
 * @author DiosFer
 */
public class MainScreen implements Screen {
    Stage stage;
    Stage informacion;
    TiledMap map;
    OrthogonalTiledMapRenderer renderer;
    OrthographicCamera camera;
    Entidad player;
    MyGdxGame game;
    ArrayList<Entidad> enemigos;
    
    int mapaActual;
    Table tableLeft;
    Label pointsLabel;
    Table tableRigth;
    
    
    public MainScreen (MyGdxGame g){
        this.game = g;
        this.mapaActual = 1;
        enemigos = new ArrayList<>();
       
    }
    
    @Override
    public void show() {
        Sounds.startBackMusic();
        
        if (mapaActual>=1 && mapaActual<=4){
            
            game.personajeActual++;
            game.savePreferences();
            
            map = new TmxMapLoader().load("levels/level"+this.mapaActual+".tmx");
            final float pixelsPerTile = 16;
            renderer = new OrthogonalTiledMapRenderer(map, 1 / pixelsPerTile);
            camera = new OrthographicCamera();

            stage = new Stage();
            stage.getViewport().setCamera(camera);
            
            informacion = new Stage();

            if (game.tipoPersonaje==2){
                player = new Personaje2();
            }else if (game.tipoPersonaje==3){
                player = new Personaje3();
            }
            else{
                player = new Personaje1();
            }
            
            
            player.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            player.setPosition(6, 5);
            stage.addActor(player);
            
            
            pointsLabel = new Label("POINTS: "+player.puntos.toString(), new Label.LabelStyle(new BitmapFont(), Color.BLACK));
            pointsLabel.setFontScale(1.5f);
            
            tableLeft = new Table();
            tableLeft.setFillParent(true);
            tableLeft.top();
            tableLeft.left();
            tableLeft.add().pad(10);
            
            tableRigth = new Table();
            tableRigth.setFillParent(true);
            tableRigth.top();
            tableRigth.right();
            tableRigth.add().pad(10);
            tableRigth.add(pointsLabel);
            
            
            informacion.addActor(tableLeft);
            informacion.addActor(tableRigth);

            prepararEnemigosLvL();
        }
        else{
            mapaActual=1;
            MainMenuScreen mms = new MainMenuScreen(game);
            game.setScreen(mms);
        }
        
    }

    @Override
    public void render(float delta) {
        
        // Pintamos el fondo
        
        Gdx.gl.glClearColor(0.608f, 0.812f, 0.922f, 1);
        
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        
        // Pintamos el hub
        tableLeft.clear();
        
        for (int i=0; i<player.vidas; i++){
            Image cora = new Image(Textures.corazonTexture);
            tableLeft.add(cora);
        }
        
        pointsLabel.setText("POINTS: "+player.puntos.toString());
        
        // Camara
        
        camera.position.x = player.getX();
        camera.update();

        renderer.setView(camera);
        renderer.render();

        
        // Actores
        stage.act(delta);
        stage.draw();
        
        
        informacion.act(delta);
        informacion.draw();
        
        
        

        // Colisione entre entidades
        
        for (int i=enemigos.size()-1; i>=0; i--){
            
            Entidad enm = enemigos.get(i);
            
            if ((enm.hitBox.overlaps(player.hitBox))&& enm instanceof Enemigo1){ // Puedes pisar a los enemigos1
                
                if (player.yVelocity<0.0f){
                    enemigos.remove(enm);
                    enm.dead();
                    player.puntos+=200;
                    player.yVelocity+=50f;
                    
                }else{
                    player.dead();
                }
            }
            else if ((enm.hitBox.overlaps(player.hitBox))){ // Mueres si te toca el enemigo 2 o enemigo3
                player.dead();
            }
        }
        

        // Pantalla de pause
        
        if (Gdx.input.isKeyPressed(Input.Keys.ESCAPE)){
            game.setScreen(new PauseScreen(game, this));
        }
        
        // Comprobacion de vidas
        if (player.vidas<0){
            MainMenuScreen mms = new MainMenuScreen(game);
            game.setScreen(mms);
        }
        
        // Fin del nivel
        if (finMapa()){
            
            player.puntos+=player.vidas*300;
            
            game.savePoints(player.puntos);
            
            mapaActual++;
            show();
            resize(Gdx.graphics.getWidth(), Gdx.graphics.getHeight());
        }
        
    }

    @Override
    public void dispose() {
    }

    @Override
    public void hide() {
    }

    @Override
    public void pause() {
    }

    @Override
    public void resize(int width, int height) {
        camera.setToOrtho(false, 20 * width / height, 20);
        
    }

    @Override
    public void resume() {
    }
    
    public void prepararEnemigosLvL(){
        
        enemigos.clear();
        
        
        if (this.mapaActual==1){

            Enemigo1 enemigo;

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(60, 7);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(100, 3);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(130, 3);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(170, 3);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            
        }
        
        else if (this.mapaActual==2){

            Enemigo1 enemigo;

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(107, 3);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(137, 8);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            Enemigo2 enemigo2;
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(105, 2);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(120, 2);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            
            Enemigo3 enemigo3;

            enemigo3 = new Enemigo3();
            enemigo3.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo3.setPosition(130, 8);
            stage.addActor(enemigo3);
            enemigo3.playerInfo=player;
            enemigos.add(enemigo3);

        }
        
        else if (this.mapaActual==3){

            Enemigo1 enemigo;

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(20, 5);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(137, 8);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            Enemigo2 enemigo2;
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(92, 5);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(98, 5);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(99, 5);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(100, 5);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(106, 5);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(137, 4);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(151, 4);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(173, 4);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(182, 4);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            Enemigo3 enemigo3;
            
            enemigo3 = new Enemigo3();
            enemigo3.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo3.setPosition(38, 10);
            stage.addActor(enemigo3);
            enemigo3.playerInfo=player;
            enemigos.add(enemigo3);
            
            enemigo3 = new Enemigo3();
            enemigo3.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo3.setPosition(83, 8);
            stage.addActor(enemigo3);
            enemigo3.playerInfo=player;
            enemigos.add(enemigo3);
            
        }
        
        else if (this.mapaActual==4){

            Enemigo1 enemigo;

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(60, 3);
            stage.addActor(enemigo);

            enemigos.add(enemigo);

            enemigo = new Enemigo1();
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(140, 8);
            stage.addActor(enemigo);

            enemigos.add(enemigo);
            
            enemigo = new Enemigo1();
            
            enemigo.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo.setPosition(85, 8);
            stage.addActor(enemigo);

            enemigos.add(enemigo);
            
            Enemigo2 enemigo2;
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(52, 2);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(59, 6);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);

            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(60, 6);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(61, 6);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(148, 7);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(149, 7);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(150, 7);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(151, 7);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(153, 7);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(154, 7);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            enemigo2 = new Enemigo2();
            enemigo2.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo2.setPosition(155, 7);
            stage.addActor(enemigo2);

            enemigos.add(enemigo2);
            
            Enemigo3 enemigo3;

            enemigo3 = new Enemigo3();
            enemigo3.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo3.setPosition(15, 5);
            stage.addActor(enemigo3);
            enemigo3.playerInfo=player;
            enemigos.add(enemigo3);
            
            enemigo3 = new Enemigo3();
            enemigo3.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo3.setPosition(70, 12);
            stage.addActor(enemigo3);
            enemigo3.playerInfo=player;
            enemigos.add(enemigo3);
            
            enemigo3 = new Enemigo3();
            enemigo3.layer = (TiledMapTileLayer) map.getLayers().get("walls");
            enemigo3.setPosition(170, 7);
            stage.addActor(enemigo3);
            enemigo3.playerInfo=player;
            enemigos.add(enemigo3);
            
        }
        
        for (Entidad ent: enemigos){
            
            if (game.dificultad.equals("Dificil")){
                if (ent instanceof Enemigo1) {
                    ((Enemigo1) ent).MAX_VELOCITY=12;
                } 
                else if (ent instanceof Enemigo2) {
                    ((Enemigo2) ent).reduccionGravedad=1;
                    ((Enemigo2) ent).MAX_VELOCITY=10;
                }
                else if (ent instanceof Enemigo3) {
                    ((Enemigo3) ent).MAX_VELOCITY=7;
                }
            }
            else if (game.dificultad.equals("Facil")){
                if (ent instanceof Enemigo1) {
                    ((Enemigo1) ent).MAX_VELOCITY=3;
                } 
                else if (ent instanceof Enemigo2) {
                    ((Enemigo2) ent).reduccionGravedad=5;
                    ((Enemigo2) ent).MAX_VELOCITY=3;
                }
                else if (ent instanceof Enemigo3) {
                    ((Enemigo3) ent).MAX_VELOCITY=4;
                }
            }
            else{ // Normal
                // Valores por defecto
            }
            
        }
    }
    public Boolean finMapa(){
        Boolean fin = false;
        
        if (this.mapaActual==1){
            if (player.getX()>=200){
                fin = true;
            }
        }
        else if (this.mapaActual==2){
            if (player.getX()>=200){
                fin = true;
            }
        }
        else if (this.mapaActual==3){
            if (player.getX()>=197){
                fin = true;
            }
        }
        else if (this.mapaActual==4){
            if (player.getX()>=188){
                fin = true;
            }
        }
        
        return fin;
    }
}
