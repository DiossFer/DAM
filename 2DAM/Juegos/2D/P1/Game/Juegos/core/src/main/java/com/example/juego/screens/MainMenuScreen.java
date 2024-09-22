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
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.example.juego.MyGdxGame;
import com.example.juego.management.Textures;

/**
 *
 * @author DiosFer
 */
public class MainMenuScreen implements Screen {
    private final MyGdxGame game;
    private Stage stage;
    private OrthographicCamera camera;
    Textures texturas;
    

    public MainMenuScreen(MyGdxGame game) {
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

        TextButton startButton = new TextButton("Start", textButtonStyle);
        startButton.getLabel().setColor(Color.BROWN);
        
        startButton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                game.setScreen(new MainScreen(game));
                dispose();  
            }
        });
        table.add(startButton).padBottom(5);

        TextButton settingButton = new TextButton("Settings", textButtonStyle);
        settingButton.getLabel().setColor(Color.BROWN);
        
        settingButton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                game.setScreen(new SettingsScreen(game));
                dispose();
            }
        });
        table.row();
        table.add(settingButton).padBottom(5);
        
        TextButton personaje = new TextButton("Character", textButtonStyle);
        personaje.getLabel().setColor(Color.BROWN);
        personaje.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                game.setScreen(new CharacterScreen(game));
                dispose();
            }
        });
        table.row();
        table.add(personaje).padBottom(5);
        
        TextButton puntos = new TextButton("Score", textButtonStyle);
        puntos.getLabel().setColor(Color.BROWN);
        puntos.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                game.setScreen(new PointsScreen(game));
                dispose();  
            }
        });
        table.row();
        table.add(puntos).padBottom(5);
        
        TextButton exitButton = new TextButton("Exit", textButtonStyle);
        exitButton.getLabel().setColor(Color.BROWN);
        exitButton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                Gdx.app.exit();
            }
        });
        table.row();
        table.add(exitButton).padBottom(5);
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