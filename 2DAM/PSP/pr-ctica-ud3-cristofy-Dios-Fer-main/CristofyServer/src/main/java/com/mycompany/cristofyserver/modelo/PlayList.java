package com.mycompany.cristofyserver.modelo;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.JoinTable;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.Table;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name="playlists")
public class PlayList {
    
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id_playList;

    @Column(name="nombrePlayList", nullable = false)
    private String nombrePlayList;

    @Column(name="idCreador", nullable = false)
    private Long idCreador;

    @Column(name="numCanciones")
    private Integer numCanciones;
    
    @ManyToMany (cascade = CascadeType.DETACH)
    @JoinTable (
            name="CancionesPlayList",
            joinColumns = {@JoinColumn(name="id_playList")},
            inverseJoinColumns = {@JoinColumn(name="id_cancion")})
    private List <Cancion> canciones;
    
    @ManyToMany (cascade = CascadeType.DETACH)
    @JoinTable (
            name="PerfilesPlayList",
            joinColumns = {@JoinColumn(name="id_playList")},
            inverseJoinColumns = {@JoinColumn(name="id_perfil")})
    private List <Perfil> perfiles;
    
    /**
     * @brief constructor por defecto de PlayList
     */
    public PlayList(){
        this.numCanciones=0;
        this.canciones = new ArrayList<Cancion>();
        this.perfiles = new ArrayList<Perfil>();
    }

    /**
     * @brief constructor por parametros de PlayList
     * @param String nomb
     * @param Long idC
     * @param Integer n
     */
    public PlayList(String nomb, Long idC, Integer n){ 
        this.idCreador=idC;
        this.nombrePlayList=nomb;
        this.numCanciones=n;
        this.canciones = new ArrayList<Cancion>();
        this.perfiles = new ArrayList<Perfil>();
    }
    
    /**
     * @brief get del atributo id_playList
     * @return Long id_playList
     */
    public Long getId_playList(){
        return this.id_playList;
    }

    /**
     * @brief get del atributo nombrePlayList
     * @return String nombrePlayList
     */
    public String getNombrePlayList(){
        return this.nombrePlayList;
    }

    /**
     * @brief get del atributo idCreador
     * @return Long idCreador
     */
    public Long getIdCreador(){
        return this.idCreador;
    }

    /**
     * @brief get del atributo numCanciones
     * @return Integer numCanciones
     */
    public Integer getNumCanciones(){
        return this.numCanciones;
    }
    
    /**
     * @brief get del atributo canciones
     * @return List<Cancion> canciones
     */
    public List<Cancion> getCanciones (){
        return this.canciones;
    }
    
    /**
     * @brief get del atributo perfiles
     * @return List<Perfil> perfiles
     */
    public List<Perfil> getPerfiles (){
        return this.perfiles;
    }
    
    /**
     * @brief set del atributo id_playList
     * @param Long id_playList
     */
    public void setId_playList(Long ide){
        this.id_playList = ide;
    }

    /**
     * @brief set del atributo nombrePlayList
     * @param String nombrePlayList
     */
    public void setNombrePlayList(String l){
        this.nombrePlayList = l;
    }

    /**
     * @brief set del atributo idCreador
     * @param Long idCreador
     */
    public void setIdCreador(Long u){
        this.idCreador = u;
    }
    
    /**
     * @brief set del atributo numCanciones
     * @param Integer numCanciones
     */
    public void setNumCanciones(Integer c){
        this.numCanciones = c;
    }
    
    /**
     * @brief set del atributo canciones
     * @param List<Cancion> canciones
     */
    public void setCanciones (List<Cancion> c){
        this.canciones=c;
    }
    
    /**
     * @brief set del atributo perfiles
     * @param List<Perfil> perfiles
     */
    public void setPerfiles (List<Perfil> p){
        this.perfiles=p;
    }

}
