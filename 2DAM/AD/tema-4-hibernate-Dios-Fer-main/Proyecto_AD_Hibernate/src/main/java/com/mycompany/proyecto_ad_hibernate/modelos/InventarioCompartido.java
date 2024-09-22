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
@Table(name = "inventarios", uniqueConstraints = {
    @UniqueConstraint(columnNames = "IdInventario"),
    @UniqueConstraint(columnNames = "SlotsMaximos"),
    @UniqueConstraint(columnNames = "SlotsOcupados")})
public class InventarioCompartido {
    
    
    /********************************
     ********   Atributos   *********
     ********************************/
    
    @Id
    @Column(name = "IdInventario", unique = true, nullable = true, length = 100)
    private String IdInventario; //genearda automaticamente o cargada
    
    @Column(name = "SlotsMaximos", unique = false, nullable = true)
    private int SlotsMaximos;
    
    @Column(name = "SlotsOcupados", unique = false, nullable = true)
    private int SlotsOcupados;
    
    @ManyToMany(cascade = CascadeType.DETACH, mappedBy = "inventariosConAcceso", fetch = FetchType.EAGER)
    List<Jugador> jugadoresAccesoInventario;
    
    private static int generar=0;

    /********************************
     *******   Constructor   ********
     ********************************/
    

    
    /**
     * @brief Constructor de Inventario con id existente (constructor de carga)
     * @post se actualizara la variable utilizada para la generacion de los id
     * @param String Id
     * @param int SlotsMaximos
     * @param int SlotsOcupados
     */
    public InventarioCompartido(String Id, int SlotsMaximos, int SlotsOcupados) {
        setIdInventario(Id);
        setSlotsMaximos(SlotsMaximos);
        setSlotsOcupados(SlotsOcupados);
        jugadoresAccesoInventario = new ArrayList<Jugador>();
        
        if ((Integer.valueOf(Id.substring(2)))>generar){
            generar = (Integer.valueOf(Id.substring(2)));
        }
        
    }
    
    /**
     * @brief Constructor de Inventario generando id a partir de la variable 
     * @pre se deberan de haber cargado los datos para que se actualize la variable generadora de id
     * @post se actualizara la variable utilizada para la generacion de los id
     * @param int SlotsMaximos
     * @param int SlotsOcupados
     */
    public InventarioCompartido(int SlotsMaximos, int SlotsOcupados) {
        
        setSlotsMaximos(SlotsMaximos);
        setSlotsOcupados(SlotsOcupados);
        jugadoresAccesoInventario = new ArrayList<Jugador>();
        generar++;
        setIdInventario ("I-" + generar);
        
    }
    public InventarioCompartido() {
        
        setSlotsMaximos(0);
        setSlotsOcupados(0);
        jugadoresAccesoInventario = new ArrayList<Jugador>();
        setIdInventario ("");
        
    }

    /********************************
     **********   Set's   ***********
     ********************************/
    
    public void setJugadorConAcceso (Jugador j){
        jugadoresAccesoInventario.add (j);
    }
    
    public void setJugadoresAccesoInventario (ArrayList<Jugador> js){
        jugadoresAccesoInventario=js;
    }
    
    public void setIdInventario (String IdInventario){
        this.IdInventario=IdInventario;
    }

    public void setSlotsMaximos(int SlotsMaximos) {
        this.SlotsMaximos = SlotsMaximos;
    }
    
    public void setSlotsOcupados(int SlotsOcupados) {
        this.SlotsOcupados = SlotsOcupados;
    }
    


    /********************************
     **********   Get's   ***********
     ********************************/
    
    public List<Jugador> getJugadoresAccesoInventario (){
        return jugadoresAccesoInventario;
    }
    
    public String getIdInventario (){
        return IdInventario;
    }

    public int getSlotsMaximos() {
        return SlotsMaximos;
    }
    
    public int getSlotsOcupados() {
        return SlotsOcupados;
    }
    

    
    public Jugador getJugadorConAcceso (int pos){
        return jugadoresAccesoInventario.get (pos);
    }
    
    public List<Jugador> getJugadores (){
        return jugadoresAccesoInventario;
    }
    public int getGenerar (){
        return generar;
    }
    public void setGenerar (int i){
        generar=i;
    }
    
    /**
     * @brief Quitar el acceso de un jugador a un inventario
     * @pre debera de existir el id del jugado y tener acceso al inventario
     * @post se actualizaran los jugadores con acceso al inventario
     * @param String IdPlayer
     */
    public void removerAcceso (String IdPlayer){
        int i=0;
        for (i=0; i < this.getJugadores().size() && !this.getJugadorConAcceso(i).getIdPlayer().equals(IdPlayer); i++){
        }
        this.getJugadores().remove(i);
    }
}
