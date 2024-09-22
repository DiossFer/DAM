package com.example.juego.entidades;

import com.badlogic.gdx.graphics.g2d.*;
import com.badlogic.gdx.maps.tiled.*;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.scenes.scene2d.ui.*;

/**
 *
 * @author DiosFer
 */
public abstract class Entidad extends Image {
    public TextureRegion stand, jump;
    public Animation walk;

    public float time = 0;
    public float xVelocity = 0;
    
    public float yVelocity = 0;
    
    public boolean canJump = false;
    
    public boolean isFacingRight = true;
    
    public TiledMapTileLayer layer;

    public final float GRAVITY = -2.5f;
    
    public float MAX_VELOCITY = 10f;
    
    public final float DAMPING = 0.87f;
    
    public Rectangle hitBox;
    
    public int vidas;
    
    public Integer puntos;
    

    
    public Entidad() {
        
    }

    public abstract void act(float delta);

    public void draw(Batch batch, float parentAlpha) {
        TextureRegion frame;

        if (yVelocity != 0) {
            frame = jump;
        } else if (xVelocity != 0) {
            frame = (TextureRegion)walk.getKeyFrame(time);
        } else {
            frame = stand;
        }

        if (isFacingRight) {
            batch.draw(frame, this.getX(), this.getY(), this.getWidth(), this.getHeight());
        } else {
            batch.draw(frame, this.getX() + this.getWidth(), this.getY(), -1 * this.getWidth(), this.getHeight());
        }
    }
    
    
    protected abstract boolean canMoveTo (float startX, float startY, boolean shouldDestroy);
    
    public abstract void dead ();
    
}
