package com.example.demo.service;

import java.util.List;

import com.example.demo.entity.Cancion;

public interface CancionService {
    
    /**
     * @brief obtiene todos las canciones de la base de datos
     * @return List<Cancion> artistas
     */
    List<Cancion> getAllcanciones();

    /**
     * @brief guarda una cancion en la base de datos
     * @param Cancion std
     * @return Cancion cancion
     */
    Cancion savecancion(Cancion std);

    
    /**
     * @brief guarda los cambios sobre una cancion en la base de datos
     * @param Cancion std
     * @return Cancion cancion
     */
    Cancion updatecancion(Cancion std);

    
    /**
     * @brief obtiene una cancion de la base de datos por la id
     * @param Long id
     * @return Cancion cancion
     */
    Cancion getcancionById(Long id);

    /**
     * @brief elimina una cancion de la base de datos por la id
     * @param Long id
     */
    void deletecancionById(Long id);
}
