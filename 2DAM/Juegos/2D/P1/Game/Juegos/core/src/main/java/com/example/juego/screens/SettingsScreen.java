package com.example.juego.screens;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.ImageButton;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;
import com.badlogic.gdx.scenes.scene2d.utils.Drawable;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.example.juego.MyGdxGame;
import com.example.juego.management.Sounds;
import com.example.juego.management.Textures;

/**
 *
 * @author DiosFer
 */
public class SettingsScreen implements Screen {
    private final MyGdxGame game;
    private Stage stage;
    private OrthographicCamera camera;

    public SettingsScreen(MyGdxGame game) {
        this.game = game;
        this.camera = new OrthographicCamera();
        this.camera.setToOrtho(false, 800, 480);
        this.stage = new Stage(new FitViewport(800, 480, camera));
    }

    @Override
    public void render(float delta) {
        Gdx.gl.glClearColor(0.95f, 0.85f, 0.7f, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        stage.act(delta);
        stage.draw();
    }

    @Override
    public void resize(int width, int height) {
        stage.getViewport().update(width, height, true);
    }

    @Override
    public void show() {
        Gdx.input.setInputProcessor(stage);
        createUI();
    }

    private void createUI() {
        Table table = new Table();
        table.setFillParent(true);
        stage.addActor(table);
        
        Texture texture = Textures.panelTexture;
        TextureRegion textureRegion = new TextureRegion(texture);
        TextureRegionDrawable textureDrawable = new TextureRegionDrawable(textureRegion);
        Label.LabelStyle labelStyle = new Label.LabelStyle();
        BitmapFont font = new BitmapFont();
        labelStyle.font = font;
        font.getData().setScale(1.6f);
        font.getData().markupEnabled = true;
        TextButton.TextButtonStyle textButtonStyle = new TextButton.TextButtonStyle();
        textButtonStyle.up = textureDrawable;
        textButtonStyle.down = textureDrawable;
        textButtonStyle.checked = textureDrawable;
        textButtonStyle.font = labelStyle.font;
        
        
        TextButton backButton = new TextButton("Back", textButtonStyle);
        backButton.getLabel().setColor(Color.BROWN);
        backButton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                game.setScreen(new MainMenuScreen(game));
                dispose();  
            }
        });
        table.row();
        table.add(backButton).padBottom(10);

        
        
        TextButton helButton = new TextButton("Help", textButtonStyle);
        helButton.getLabel().setColor(Color.BROWN);
        helButton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                game.setScreen(new TutorialScreen(game));
                dispose();  
            }
        });
        table.row();
        table.add(helButton).padBottom(10);
                
        
        
        
        TextButton dificultadBoton = new TextButton(game.dificultad, textButtonStyle);
        dificultadBoton.getLabel().setColor(Color.BROWN);
        dificultadBoton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                if (game.dificultad.equals("Hard")){
                    game.dificultad="Easy";
                }
                else if (game.dificultad.equals("Normal")){
                    game.dificultad="Hard";
                }
                else{
                    game.dificultad="Normal";
                }
                
                dificultadBoton.setText(game.dificultad);
                game.savePreferences();
            }
        });
        
        table.row();
        table.add(dificultadBoton).padBottom(10);
        
        
        
        Drawable d1;

        ImageButton.ImageButtonStyle sonido = new ImageButton.ImageButtonStyle();
        sonido.up = textureDrawable;
        
        Texture texturesonido1 = Textures.sonidoOn;
        Drawable d2 = new TextureRegionDrawable(new TextureRegion(texturesonido1));
        
        
        Texture texturesonido2 = Textures.sonidoOff;
        Drawable d3 = new TextureRegionDrawable(new TextureRegion(texturesonido2));
        
        
        
        if (Sounds.volumen==true){
            d1=d2;
        }
        else{
            d1=d3;
        }
        sonido.imageUp = d1;
        
        ImageButton musicaOnOff = new ImageButton (sonido);
        
        musicaOnOff.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                
                if (Sounds.volumen==true){
                    Sounds.cambiarSonido();
                    musicaOnOff.getStyle().imageUp=d3;
                    game.savePreferences();
                    
                }else{
                    Sounds.cambiarSonido();
                    musicaOnOff.getStyle().imageUp=d2;
                    game.savePreferences();
                }
            }
        });
        table.row();
        table.add(musicaOnOff).padBottom(10);
                
    }

    @Override
    public void hide() {
        Gdx.input.setInputProcessor(null);
    }

    @Override
    public void pause() {
    }

    @Override
    public void resume() {
    }

    @Override
    public void dispose() {
        stage.dispose();
    }
}