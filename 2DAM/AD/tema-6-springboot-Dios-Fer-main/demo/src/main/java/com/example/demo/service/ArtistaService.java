package com.example.demo.service;

import java.util.List;

import com.example.demo.entity.Artista;

public interface ArtistaService {
    
    /**
     * @brief obtiene todos los atistas de la base de datos
     * @return List<Artista> artistas
     */
    List<Artista> getAllartistas();

    /**
     * @brief guarda un artista en la base de datos
     * @param Artista std
     * @return Artista artista
     */
    Artista saveartista(Artista std);

    /**
     * @brief guarda los cambios sobre un artista en la base de datos
     * @param Artista std
     * @return Artista artista
     */
    Artista updateartista(Artista std);

    /**
     * @brief obtiene un artista de la base de datos por la id
     * @param Long id
     * @return Artista artista
     */
    Artista getartistaById(Long id);

    /**
     * @brief elimina un artista de la base de datos por la id
     * @param Long id
     */
    void deleteartistaById(Long id);
}
