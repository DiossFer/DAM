package com.example.juego.management;

/**
 *
 * @author DiosFer
 */
public class Puntos {
    private String nombre;
    private Integer puntos;

    public Puntos(String newnombre, Integer newpuntos) {
        this.nombre = newnombre;
        this.puntos = newpuntos;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Integer getPuntos() {
        return puntos;
    }

    public void setPuntos(Integer puntos) {
        this.puntos = puntos;
    }
    
}
