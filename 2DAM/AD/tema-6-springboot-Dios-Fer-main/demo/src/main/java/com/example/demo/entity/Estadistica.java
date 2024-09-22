package com.example.demo.entity;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;

@Entity
@Table(name="estadisticas")
public class Estadistica {
    
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id_estadistica;

    @Column(name="numReproducciones")
    private Long numReproducciones;

    @Column(name="vecesIncluidaEnPlayLists")
    private Long vecesIncluidaEnPlayLists;

    @OneToOne(mappedBy="estadisticaCancion", cascade = CascadeType.ALL)
    Cancion cancionEstadistica;

    /**
     * @brief constructor por defecto de Estadistica
     */
    public Estadistica(){
        this.numReproducciones = 0l;
        this.vecesIncluidaEnPlayLists = 0l;
    }

    /**
     * @brief constructor por parametros de Artista
     * @param Long n
     * @param Long v
     * @param Cancion c
     */
    public Estadistica(Long n, Long v, Cancion c){
        this.numReproducciones = n;
        this.vecesIncluidaEnPlayLists = v;
        this.cancionEstadistica = c;
    }
    
    /**
     * @brief get del atributo id_estadistica
     * @return Long id_estadistica
     */
    public Long getId_estadistica(){
        return this.id_estadistica;
    }

    /**
     * @brief get del atributo numReproducciones
     * @return Long numReproducciones
     */
    public Long getNumReproducciones(){
        return this.numReproducciones;
    }

    /**
     * @brief get del atributo vecesIncluidaEnPlayLists
     * @return Long vecesIncluidaEnPlayLists
     */
    public Long getVecesIncluidaEnPlayLists(){
        return this.vecesIncluidaEnPlayLists;
    }
    
    /**
     * @brief get del atributo cancionEstadistica
     * @return Cancion cancionEstadistica
     */
    public Cancion getCancionEstadistica(){
        return this.cancionEstadistica;
    }
        
    /**
     * @brief set del atributo id_estadistica
     * @param Long id_estadistica
     */
    public void setId_estadistica(Long ide){
        this.id_estadistica = ide;
    }

    /**
     * @brief set del atributo numReproducciones
     * @param Long numReproducciones
     */
    public void setNumReproducciones(Long n){
        this.numReproducciones = n;
    }

    /**
     * @brief set del atributo vecesIncluidaEnPlayLists
     * @param Long vecesIncluidaEnPlayLists
     */
    public void setVecesIncluidaEnPlayLists(Long v){
        this.vecesIncluidaEnPlayLists = v;
    }
    
    /**
     * @brief set del atributo cancionEstadistica
     * @param Cancion cancionEstadistica
     */
    public void setCancionEstadistica(Cancion c){
        this.cancionEstadistica = c;
    }

}
