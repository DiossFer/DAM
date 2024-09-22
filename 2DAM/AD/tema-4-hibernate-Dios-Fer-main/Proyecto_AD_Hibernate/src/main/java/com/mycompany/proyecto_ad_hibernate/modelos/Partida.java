/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto_ad_hibernate.modelos;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.OneToMany;
import jakarta.persistence.OneToOne;
import jakarta.persistence.PrimaryKeyJoinColumn;
import jakarta.persistence.Table;
import jakarta.persistence.Transient;
import jakarta.persistence.UniqueConstraint;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author DiosFer
 */
@Entity
//@org.hibernate.annotations.Entity(optimisticLock = OptimisticLockType.ALL)
@Table(name = "partidas", uniqueConstraints = {
    @UniqueConstraint(columnNames = "IdPartida"),
    @UniqueConstraint(columnNames = "NumEspectadores"),
    @UniqueConstraint(columnNames = "ServerPartida")})
public class Partida {
    
    
    /********************************
     ********   Atributos   *********
     ********************************/
    @Id
    @Column(name = "IdPartida", unique = true, nullable = true, length = 100)
    private String IdPartida; //genearda automaticamente o cargada
    
    @Column(name = "NumEspectadores", unique = false, nullable = true, length = 100)
    private int NumEspectadores;
    
    @OneToOne(cascade = CascadeType.ALL)
    @JoinColumn(name="ServerPartida")
    private Servidor ServerPartida;
    
    
    @OneToMany(mappedBy="partidaEnJugador", cascade=CascadeType.MERGE, fetch = FetchType.EAGER)
    private List<Jugador> jugadores;
    

    
    private static int generar=0;

    /********************************
     *******   Constructor   ********
     ********************************/
    
    public Partida() {
        setIdPartida ("");
        setNumEspectadores (0);
        setServerPartida (null);
        setJugadores (new ArrayList<Jugador>());
    }
    
    /**
     * @brief Constructor de Partida con id existente (constructor de carga)
     *        Los jugadores se introduciran por medio de set's
     * @post se actualizara la variable utilizada para la generacion de los id
     * @param String Id
     * @param String NickName
     * @param int nivel
     */
    public Partida(String Id, int NumEspectadores, Servidor s) {
        setIdPartida (Id);
        setNumEspectadores (NumEspectadores);
        setServerPartida (s);
        setJugadores (new ArrayList<Jugador>());
        
        if ((Integer.valueOf(Id.substring(2)))>generar){
            generar = (Integer.valueOf(Id.substring(2)));
        }
    }
    
    /**
     * @brief Constructor de Partida generando id a partir de la variable 
     *        Los jugadores se introduciran por medio de set's
     * @pre se deberan de haber cargado los datos para que se actualize la variable generadora de id
     * @post se actualizara la variable utilizada para la generacion de los id
     * @param int NumEspectadores
     * @param Servidor s -> servidor previamente cargado en el sistema
     */
    public Partida(int NumEspectadores, Servidor s) {
        generar++;
        setIdPartida("P-" + generar);

        setNumEspectadores (NumEspectadores);
        setServerPartida (s);

        setJugadores (new ArrayList<Jugador>());

    }
    
    /********************************
     **********   Set's   ***********
     ********************************/
    
    public void setIdPartida(String IdPartida) {
        this.IdPartida=IdPartida;
    }

    public void setNumEspectadores(int NumEspectadores) {
        this.NumEspectadores = NumEspectadores;
    }
    
    public void setServerPartida(Servidor s) {
        this.ServerPartida = s;
    }
    
    //@OneToMany(mappedBy="partidaEnJugador", cascade=CascadeType.ALL)
    public void setJugadores(List<Jugador> j) {
        this.jugadores=j;
    }
    
    public void setUnJugador (Jugador j){
        this.jugadores.add(j);
    }
    
    public void setGenerar (int n) {
        this.generar = n;
    }
    

    
    /********************************
     **********   Get's   ***********
     ********************************/
    
    public String getIdPartida() {    
        return IdPartida;
    }

    public int getNumEspectadores() {
        return NumEspectadores;
    }
    
    public Servidor getServerPartida() {
        return ServerPartida;
    }

    public Jugador getJugadorpos(int pos) {
        return this.jugadores.get(pos);
    }
    
    public List<Jugador> getJugadores (){
        return this.jugadores;
    }

    public int getGenerar() {
        return generar;
    }
    
}
