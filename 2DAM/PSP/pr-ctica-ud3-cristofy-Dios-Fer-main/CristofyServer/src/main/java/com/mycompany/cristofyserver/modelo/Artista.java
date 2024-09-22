package com.mycompany.cristofyserver.modelo;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name="artistas")
public class Artista {
    
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id_artista;

    @Column(name="nombreArtista", nullable = false)
    private String nombreArtista;

    @OneToMany(mappedBy="artista", cascade = CascadeType.ALL)
    List <Cancion> canciones = new ArrayList<Cancion>();
    
    /**
     * @brief constructor por defecto de Artista
     */
    public Artista(){

    }

    /**
     * @brief constructor por parametros de Artista
     * @param String nomb
     */
    public Artista(String nomb){
        this.nombreArtista = nombreArtista;
    }
    
     /**
     * @brief get del atributo id_artista
     * @return Long id_artista
     */
    public Long getId_artista(){
        return this.id_artista;
    }

     /**
     * @brief get del atributo nombreArtista
     * @return String nombreArtista
     */
    public String getNombreArtista(){
        return this.nombreArtista;
    }
    
    /**
     * @brief set del atributo nombreArtista
     * @param Long id_artista
     */
    public void setId_artista(Long ide){
        this.id_artista = ide;
    }

    /**
     * @brief set del atributo nombreArtista
     * @param String nombreArtista
     */
    public void setNombreArtista(String l){
        this.nombreArtista = l;
    }

    /**
     * @brief get del atributo canciones
     * @return List<Cancion> canciones
     */
    public List<Cancion> getCanciones() {
        return canciones;
    }

    /**
     * @brief set del atributo canciones
     * @param List<Cancion> canciones
     */
    public void setCanciones(List<Cancion> canciones) {
        this.canciones = canciones;
    }

}
