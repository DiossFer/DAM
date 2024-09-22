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
import jakarta.persistence.JoinTable;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.ManyToOne;
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
@Table(name = "jugadores", uniqueConstraints = {
    @UniqueConstraint(columnNames = "IdPlayer"),
    @UniqueConstraint(columnNames = "NickName"),
    @UniqueConstraint(columnNames = "nivel")})
public class Jugador {
    
    
    /********************************
     ********   Atributos   *********
     ********************************/
    
    @Id
    @Column(name = "IdPlayer", unique = true, nullable = true, length = 100)
    private String IdPlayer;  //genearda automaticamente o cargada
    
    @Column(name = "NickName", unique = false, nullable = true, length = 100)
    private String NickName; 
    
    @Column(name = "nivel", unique = false, nullable = true)
    private int nivel;
    
    @ManyToOne
    @JoinColumn(name = "partidaEnJugador")
    private Partida partidaEnJugador;
    
    @ManyToMany(cascade = CascadeType.DETACH, fetch = FetchType.EAGER)
    @JoinTable(name="accesos",
        joinColumns={@JoinColumn(name="IdPlayer")},
        inverseJoinColumns={@JoinColumn(name="IdInventario")})
    List<InventarioCompartido> inventariosConAcceso;
    
    private static int generar=0;
    
    /********************************
     *******   Constructor   ********
     ********************************/
    

    /**
     * @brief Constructor de Jugador con id existente (constructor de carga)
     * @post se actualizara la variable utilizada para la generacion de los id
     * @param String Id
     * @param String NickName
     * @param int nivel
     */
    public Jugador(String Id, String NickName, int nivel) {
        setIdPlayer (Id);
        setNickName (NickName);
        setNivel (nivel);
        inventariosConAcceso = new ArrayList<InventarioCompartido>();
        
        if ((Integer.valueOf(Id.substring(2)))>generar){
            generar = (Integer.valueOf(Id.substring(2)));
        }
    }
    
    /**
     * @brief Constructor de Jugador generando id a partir de la variable 
     * @pre se deberan de haber cargado los datos para que se actualize la variable generadora de id
     * @post se actualizara la variable utilizada para la generacion de los id
     * @param String NickName
     * @param int nivel
     */
    public Jugador(String NickName, int nivel) {
        generar++;
        setIdPlayer("J-" + generar);
        setNickName (NickName);
        setNivel (nivel);
        inventariosConAcceso = new ArrayList<InventarioCompartido>();
    }
    
    public Jugador() {
        
        setIdPlayer("");
        setNickName ("");
        setNivel (0);
        inventariosConAcceso = new ArrayList<InventarioCompartido>();
    }
    
    
    /********************************
     **********   Set's   ***********
     ********************************/
    
    public void setIdPlayer(String IdPlayer) {
        this.IdPlayer = IdPlayer;
    }
    
    public void setNickName(String NickName) {
        this.NickName = NickName;
    }

    public void setNivel(int nivel) {
        this.nivel = nivel;
    }
    
    
    
    public void setInventarioConAcceso (InventarioCompartido i){
        inventariosConAcceso.add (i);
    }
    
    public void setInventarioCompartido (ArrayList<InventarioCompartido> ic){
        inventariosConAcceso = ic;
    }

    /********************************
     **********   Get's   ***********
     ********************************/
    
    public List<InventarioCompartido> getInventarioCompartido (){
        return inventariosConAcceso;
    }
    
    public String getIdPlayer() {
        return IdPlayer;
    }
    
    public String getNickName() {
        return NickName;
    }

    public int getNivel() {
        return nivel;
    }
    

    
    public InventarioCompartido getInventarioConAcceso (int pos){
        return inventariosConAcceso.get (pos);
    }
    
    public List<InventarioCompartido> getInventarios (){
        return inventariosConAcceso;
    }
    
    /**
     * @brief Quitar el acceso de un jugador a un inventario
     * @pre debera de existir el id del inventario y el jugador tener acceso al el
     * @post se actualizaran los inventarios a los que tieneacceso el jugador
     * @param String IdInventario
     */
    public void removerInventario (String IdInventario){
        int i=0;
        for (i=0; i < this.getInventarios().size() && !this.getInventarioConAcceso(i).getIdInventario().equals(IdInventario); i++){
        }
        this.getInventarios().remove(i);
    }
    
    
    public Partida getpartidaEnJugador (){
        return partidaEnJugador;
    }
    
    public void setpartidaEnJugador (Partida p){
        partidaEnJugador=p;
    }
    
    public void setGenerar (int i){
        generar=i;
    }
    public int getGenerar (){
        return generar;
    }

}

