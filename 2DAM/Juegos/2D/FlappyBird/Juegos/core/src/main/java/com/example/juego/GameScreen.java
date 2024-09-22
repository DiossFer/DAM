package com.example.juego;

import java.util.Iterator;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input.Keys;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.utils.TimeUtils;




public class GameScreen implements Screen {

    final FlappyBird game;
    
    OrthographicCamera camera;

    
    long lastGeneredTime;
    int points;
    
    World world;
    

    
    public GameScreen(final FlappyBird gam) {
        this.game = gam;

        // Inicializamos
        world = new World();
        // create the camera and the SpriteBatch
        camera = new OrthographicCamera();
        camera.setToOrtho(false, 800, 480);
        lastGeneredTime = world.spawnTuberia();

    }

    

    @Override
    public void render(float delta) {

        // tell the camera to update its matrices.
        camera.update();

        // tell the SpriteBatch to render in the
        // coordinate system specified by the camera.
        game.batch.setProjectionMatrix(camera.combined);



        // begin a new batch 
        game.batch.begin();
        

        // Pintamos el fondo
        game.batch.draw(Assets.fondoDia, 0, 0);
        game.batch.draw(Assets.fondoDia, 288, 0);
        game.batch.draw(Assets.fondoDia, 288+288, 0);
        

        // Contador de puntos
        game.font.draw(game.batch, "Points: " + points, 0, 480);

        // Dibujamos el pajaro
        game.batch.draw(Assets.birdImage, world.bird.x, world.bird.y);
        
        //Dibujamso las tuberias
        int num1=0;
        for (Rectangle rec : world.tuberias) {
                num1++;
                if(num1%2!=0){
                    game.batch.draw(Assets.imagenTubo1, rec.x, rec.y);
                }
                else{
                    game.batch.draw(Assets.imagenTubo2, rec.x, rec.y);
                }

        }
        
        // Pintamos el suelo
        game.batch.draw(Assets.suelo, 0, -60);
        game.batch.draw(Assets.suelo, 288, -60);
        game.batch.draw(Assets.suelo, 288+288, -60);

        // terminamos el batch
        game.batch.end();

        //Bird Jump
        if (Gdx.input.justTouched()) {

            world.velocidad = 6.4f;

        }

        //Bird Jump
        if (Gdx.input.isKeyJustPressed(Keys.SPACE)){
            world.velocidad = 6.4f;
        }

        // Actualizamos variables y posicion
        world.velocidad -= world.gravedad;
        world.bird.y += world.velocidad;


        // limites del pajaro
        
        if (world.bird.y < 51){
            world.bird.y = 51;
            Assets.playSound(Assets.hitSound);
            game.setScreen(new MainMenuScreen(game));
        }
                
        if (world.bird.y > 480 - 64){
            world.bird.y = 480 - 64;
        }
                

        // crear tuberias cada segundo y medio
        if (TimeUtils.nanoTime() - lastGeneredTime > 1500000000){
            lastGeneredTime = world.spawnTuberia();
        }
                

        // mover las tuberias y comprobar colisiones
        Iterator<Rectangle> iter = world.tuberias.iterator();
        while (iter.hasNext()) {
            Rectangle rec = iter.next();
            rec.x -= 200 * Gdx.graphics.getDeltaTime();

            if (rec.x + 64 < 0){

                iter.remove();

            }


            if (rec.overlaps(world.bird)) {
                    Assets.playSound(Assets.hitSound);
                    game.setScreen(new MainMenuScreen(game));
            }
        }

        Iterator<Rectangle> iter2 = world.espacio.iterator();

        while (iter2.hasNext()) {

            Rectangle espacio1 = iter2.next();
            espacio1.x -= 200 * Gdx.graphics.getDeltaTime();

            if (espacio1.x + 64 < 120){

                points++;
                iter2.remove();
                Assets.playSound(Assets.pointSound);
            }

        }

    }

    @Override
    public void resize(int width, int height) {
    }

    @Override
    public void show() {
            // Empezamos la musica de fondo
            Assets.backMusic.play();
    }

    @Override
    public void hide() {
    }

    @Override
    public void pause() {
    }

    @Override
    public void resume() {
    }

    @Override
    public void dispose() {
        
        Assets.imagenTubo1.dispose();
        Assets.imagenTubo2.dispose();
        Assets.birdImage.dispose();
        Assets.pointSound.dispose();
        Assets.hitSound.dispose();
        Assets.fondoDia.dispose();
        Assets.suelo.dispose();
        Assets.backMusic.dispose();
        
    }

}
