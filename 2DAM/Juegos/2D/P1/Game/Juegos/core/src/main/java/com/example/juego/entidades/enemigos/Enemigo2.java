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
public class Enemigo2 extends Entidad {     // Enemigo2 planta que salta

    boolean goJump;
    
    public TextureRegion jump1, jump2, jump3;

    public Integer reduccionGravedad=3;
    
    public Enemigo2() {
        goJump = true;
        MAX_VELOCITY = 5f;
        
        
        final float width = 17;
        final float height = 16;
        
        this.setSize(1, height / width);

        Texture koalaTexture = Textures.plantaRoja;
        
        TextureRegion[][] grid = TextureRegion.split(koalaTexture, (int) width, (int) height);
        this.hitBox = new Rectangle(this.getX(), this.getY(), this.getWidth(), this.getHeight());
        
        stand = grid[0][0];
        
        jump1 = grid[0][0];
        jump2 = grid[0][1];
        jump3 = grid[0][2];
        
    }

    @Override
    public void act(float delta) {
        time = time + delta;
        
        hitBox.setX(this.getX());
        hitBox.setY(this.getY());
        
        if (goJump) {
            
            if (canJump) {
                Sounds.playSound(Sounds.personajeJump);
                yVelocity = yVelocity + MAX_VELOCITY * 4;
            }
            
            canJump = false;
        }



        yVelocity = yVelocity + GRAVITY/reduccionGravedad;

        float x = this.getX();
        float y = this.getY();
        float xChange = xVelocity * delta;
        float yChange = yVelocity * delta;



        if (canMoveTo(x, y + yChange, yVelocity > 0) == false) {
            canJump = yVelocity < 0;
            yVelocity = yChange = 0;
            
        }
        
        this.setPosition(x + xChange, y + yChange);

        xVelocity = xVelocity * DAMPING;
        
        if (Math.abs(xVelocity) < 0.5f) {
            xVelocity = 0;
        }
        
        
        if (yVelocity<0.1&&yVelocity>-0.1){
            jump=jump1;
        }else if (yVelocity<0){
            jump=jump2;
        }else{
            jump=jump3;
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
