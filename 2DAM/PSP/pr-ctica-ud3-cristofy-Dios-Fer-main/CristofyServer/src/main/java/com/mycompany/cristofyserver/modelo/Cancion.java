package com.mycompany.cristofyserver.modelo;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.OneToOne;
import jakarta.persistence.PrimaryKeyJoinColumn;
import jakarta.persistence.Table;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.annotations.OnDelete;
import org.hibernate.annotations.OnDeleteAction;

@Entity
@Table(name="canciones")
public class Cancion {
    
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id_cancion;

    @Column(name="titulo", nullable=false)
    private String titulo;

    @Column(name="duracion", nullable = false)
    private Integer duracion;

    @Column(name="anioPublicacion", nullable = false)
    private Integer anioPublicacion;
    
    @Column(name="ruta", nullable = true)
    private String ruta;
    
    @Column(name="tamanio", nullable = true)
    private Long tamanio;

    @OneToOne(cascade = CascadeType.ALL)
    @JoinColumn
    Estadistica estadisticaCancion;
    
    @ManyToOne(cascade = CascadeType.DETACH)
    @PrimaryKeyJoinColumn
    Artista artista;
    
    @ManyToMany (cascade = CascadeType.DETACH, mappedBy = "canciones")
    @OnDelete(action = OnDeleteAction.CASCADE)
    List<PlayList> playLists;

    /**
     * @brief constructor por defecto de Cancion
     */
    public Cancion(){
        estadisticaCancion = new Estadistica ();
        playLists = new ArrayList<>();
    }
    
    /**
     * @brief constructor por parametros de Cancion
     * @param String nomb
     * @param Integer d
     * @param Integer ap
     * @param String r
     */
    public Cancion(String t, Integer d, Integer ap, String r){
        this.titulo = t;
        this.duracion = d;
        this.anioPublicacion = ap;
        this.ruta = r;
        estadisticaCancion = new Estadistica ();
        playLists = new ArrayList<>();
        
    }
    
     /**
     * @brief get del atributo id_cancion
     * @return Long id_cancion
     */
    public Long getId_cancion(){
        return this.id_cancion;
    }

     /**
     * @brief get del atributo titulo
     * @return String titulo
     */
    public String getTitulo(){
        return this.titulo;
    }

     /**
     * @brief get del atributo duracion
     * @return Integer duracion
     */
    public Integer getDuracion(){
        return this.duracion;
    }

     /**
     * @brief get del atributo anioPublicacion
     * @return Integer anioPublicacion
     */
    public Integer getAnioPublicacion(){
        return this.anioPublicacion;
    }
    
     /**
     * @brief get del atributo ruta
     * @return String ruta
     */
    public String getRuta(){
        return this.ruta;
    }
    
     /**
     * @brief get del atributo artista
     * @return Artista artista
     */
    public Artista getArtista(){
        return this.artista;
    }

    
     /**
     * @brief get del atributo playLists
     * @return List<PlayList> playLists
     */
    public List<PlayList> getPlayLists (){
        return this.playLists;
    }
    
    /**
     * @brief set del atributo playLists
     * @param List<PlayList> p
     */
    public void setPlayLists (List<PlayList> p){
        this.playLists=p;
    }
    
    /**
     * @brief set del atributo id_cancion
     * @param Long ide
     */
    public void setId_cancion(Long ide){
        this.id_cancion = ide;
    }

    /**
     * @brief set del atributo titulo
     * @param String titulo
     */
    public void setTitulo(String t){
        this.titulo = t;
    }

    /**
     * @brief set del atributo id_cancion
     * @param Long ide
     */
    public void setDuracion(Integer d){
        this.duracion = d;
    }
    
    /**
     * @brief set del atributo anioPublicacion
     * @param Integer anioPublicacion
     */
    public void setAnioPublicacion(Integer ap){
        this.anioPublicacion = ap;
    }
    
    /**
     * @brief set del atributo ruta
     * @param String ruta
     */
    public void setRuta(String r){
        this.ruta = r;
    }

    /**
     * @brief set del atributo artista
     * @param Artista artista
     */
    public void setArtista(Artista a){
        this.artista = a;
    }

    /**
     * @brief get del atributo estadisticaCancion
     * @return Estadistica estadisticaCancion
     */
    public Estadistica getEstadisticaCancion() {
        return estadisticaCancion;
    }

    /**
     * @brief set del atributo estadisticaCancion
     * @param Estadistica estadisticaCancion
     */
    public void setEstadisticaCancion(Estadistica estadisticaCancion) {
        this.estadisticaCancion = estadisticaCancion;
    }

    public Long getTamanio() {
        return tamanio;
    }

    public void setTamanio(Long tamanio) {
        this.tamanio = tamanio;
    }
    
}
