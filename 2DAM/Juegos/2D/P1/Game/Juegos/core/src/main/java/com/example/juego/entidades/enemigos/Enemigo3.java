package com.example.juego.entidades.enemigos;

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
public class Enemigo3 extends Entidad {     // Enemigo3 con inteligencia artificial persiguiendo al personaje

    boolean right;
    public Entidad playerInfo;
    public Enemigo3() {
        right = true;
        MAX_VELOCITY = 6f;
                
        final float width = 16;
        final float height = 16;
        
        this.setSize(1, height / width);

        Texture koalaTexture = Textures.ojo;
        
        TextureRegion[][] grid = TextureRegion.split(koalaTexture, (int) width, (int) height);
        this.hitBox = new Rectangle(this.getX(), this.getY(), this.getWidth(), this.getHeight());
        
        stand = grid[0][0];
        jump = grid[0][3];
        walk = new Animation(0.15f, grid[0][2], grid[0][1], grid[0][2]);
        walk.setPlayMode(Animation.PlayMode.LOOP_PINGPONG);
    }

    @Override
    public void act(float delta) {
        time = time + delta;
        
        hitBox.setX(this.getX());
        hitBox.setY(this.getY());
        
        
        if (this.getX()<playerInfo.getX()){
            right=true;
        }else{
            right=false;
        }
        
        
        
        if (!right) {
            xVelocity = -1 * MAX_VELOCITY;
        }

        
        if (right) {
            xVelocity = MAX_VELOCITY;
        }

        yVelocity = 0;

        float x = this.getX();
        float y = this.getY();
        float xChange = xVelocity * delta;
        float yChange = yVelocity * delta;

        if (canMoveTo(x + xChange, y, false) == false) {
            xVelocity = xChange = 0;
            right = !right;
            
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
        this.remove();
        Sounds.playSound(Sounds.enemyDamage);
    }
}
