package com.example.juego.entidades.personajes;

import com.badlogic.gdx.*;
import com.badlogic.gdx.graphics.*;
import com.badlogic.gdx.graphics.g2d.*;
import com.badlogic.gdx.math.Rectangle;
import com.example.juego.entidades.Entidad;
import com.example.juego.management.Sounds;
import com.example.juego.management.Textures;

/**
 *
 * @author DiosFer
 */
public class Personaje1 extends Entidad {  // Personaje 1 --> Personaje normal

    
    public Personaje1() {
        this.vidas = 3;
        puntos = 0;
        
                
        final float width = 20;
        final float height = 30;
        
        this.setSize(1, height / width);

        Texture koalaTexture = Textures.luigiTexture;
        TextureRegion[][] grid = TextureRegion.split(koalaTexture, (int) width, (int) height);

        stand = grid[0][0];
        jump = grid[0][1];
        walk = new Animation(0.15f, grid[0][2], grid[0][3], grid[0][4]);
        walk.setPlayMode(Animation.PlayMode.LOOP_PINGPONG);
        
        hitBox = new Rectangle(this.getX(), this.getY(), this.getWidth(), this.getHeight());
        
    }

    @Override
    public void act(float delta) {
        time = time + delta;

        hitBox.setX(this.getX());
        hitBox.setY(this.getY());
        
        
        boolean upTouched = Gdx.input.isTouched() && Gdx.input.getY() < Gdx.graphics.getHeight() / 2;
        
        if (Gdx.input.isKeyJustPressed(Input.Keys.UP) || upTouched) {
            
            if (canJump) {
                Sounds.playSound(Sounds.personajeJump);
                yVelocity = yVelocity + MAX_VELOCITY * 4;
            }
            
            canJump = false;
        }

        boolean leftTouched = Gdx.input.isTouched() && Gdx.input.getX() < Gdx.graphics.getWidth() / 3;
        if (Gdx.input.isKeyPressed(Input.Keys.LEFT) || leftTouched) {
            xVelocity = -1 * MAX_VELOCITY;
            isFacingRight = false;
        }

        boolean rightTouched = Gdx.input.isTouched() && Gdx.input.getX() > Gdx.graphics.getWidth() * 2 / 3;
        if (Gdx.input.isKeyPressed(Input.Keys.RIGHT) || rightTouched) {
            xVelocity = MAX_VELOCITY;
            isFacingRight = true;
        }

        yVelocity = yVelocity + GRAVITY;

        float x = this.getX();
        float y = this.getY();
        float xChange = xVelocity * delta;
        float yChange = yVelocity * delta;

        if (canMoveTo(x + xChange, y, false) == false) {
            xVelocity = xChange = 0;
        }

        if (canMoveTo(x, y + yChange, yVelocity > 0) == false) {
            canJump = yVelocity < 0;
            yVelocity = yChange = 0;
        }

        this.setPosition(x + xChange, y + yChange);

        xVelocity = xVelocity * DAMPING;
        if (Math.abs(xVelocity) < 0.5f) {
            xVelocity = 0;
        }
        
        if (this.getY()<0){
            dead();
            
        }
        
    }

    
    @Override
    protected boolean canMoveTo (float startX, float startY, boolean shouldDestroy) {
        float endX = startX + this.getWidth();
        float endY = startY + this.getHeight();

        int x = (int) startX;
        while (x < endX) {

            int y = (int) startY;
            while (y < endY) {
                if (layer.getCell(x, y) != null) {
                    if (shouldDestroy) {
                        layer.setCell(x, y, null);
                        puntos+=100;
                    }
                    return false;
                }
                y = y + 1;
            }
            x = x + 1;
        }

        return true;
    }
    
    @Override
    public void dead (){
        Sounds.playSound(Sounds.personajeDamageGdx);
        this.vidas--;
        this.setPosition(6, 5);
    }
    
}
