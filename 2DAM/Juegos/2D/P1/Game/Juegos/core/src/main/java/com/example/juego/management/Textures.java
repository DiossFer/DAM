package com.example.juego.management;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;

/**
 *
 * @author DiosFer
 */
public class Textures {
    
    public static Texture corazonTexture;
    public static Texture panelTexture;
    public static Texture luigiTexture;
    public static Texture marioTexture;
    public static Texture koalaTexture;
    public static Texture sonidoOn;
    public static Texture sonidoOff;
    public static Texture panel2Texture;
    public static Texture slime;
    public static Texture plantaRoja;
    public static Texture ojo;
    public static Texture tutorial1;
    public static Texture tutorial2;
    public static Texture tutorial3;
    public static Texture tutorial4;
    public static Texture tutorial5;
    public static Texture tutorial6;
    public static int actualTutorial=1;
    public Textures (){
        
    }
    
    public static void load (){
        corazonTexture = new Texture("ui/corazon.png");
        panelTexture = new Texture(Gdx.files.internal("ui/panel1.png"));
        luigiTexture = new Texture("entities/luigi.png");
        marioTexture = new Texture("entities/fontanero.png");
        koalaTexture = new Texture("entities/koalio.png");
        sonidoOn = new Texture(Gdx.files.internal("ui/sonidoOn.png"));
        sonidoOff = new Texture(Gdx.files.internal("ui/sonidoOff.png"));
        panel2Texture = new Texture(Gdx.files.internal("ui/panel2.png"));
        slime = new Texture("entities/slime.png");
        tutorial1 = new Texture("ui/tutorial/tutorial1.png");
        tutorial2 = new Texture("ui/tutorial/tutorial2.png");
        tutorial3 = new Texture("ui/tutorial/tutorial3.png");
        tutorial4 = new Texture("ui/tutorial/tutorial4.png");
        tutorial5 = new Texture("ui/tutorial/tutorial5.png");
        tutorial6 = new Texture("ui/tutorial/tutorial6.png");
        plantaRoja = new Texture("entities/planta.png");
        ojo = new Texture("entities/ojo.png");
    }
    
    public static Texture getNextTutorial(){
        Texture t;
        if (actualTutorial==1){
            t=tutorial2;
            actualTutorial=2;
        }
        else if (actualTutorial==2){
            t=tutorial3;
            actualTutorial=3;
        }
        else if (actualTutorial==3){
            t=tutorial4;
            actualTutorial=4;
        }
        else if (actualTutorial==4){
            t=tutorial5;
            actualTutorial=5;
        }
        else if (actualTutorial==5){
            t=tutorial6;
            actualTutorial=6;
        }
        else{
            t=tutorial1;
            actualTutorial=1;
        }
        
        return t;
                
    }
    
    
}
