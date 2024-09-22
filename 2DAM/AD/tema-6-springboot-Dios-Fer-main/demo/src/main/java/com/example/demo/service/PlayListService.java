package com.example.demo.service;

import java.util.List;

import com.example.demo.entity.PlayList;

public interface PlayListService {
    
    /**
     * @brief obtiene todas las playLists de la base de datos
     * @return List<PlayList> artistas
     */
    List<PlayList> getAllplayLists();

    /**
     * @brief guarda una playList en la base de datos
     * @param PlayList std
     * @return PlayList playList
     */
    PlayList saveplayList(PlayList std);

    /**
     * @brief guarda los cambios sobre una playList en la base de datos
     * @param PlayList std
     * @return PlayList playList
     */
    PlayList updateplayList(PlayList std);

    /**
     * @brief obtiene una playList de la base de datos por la id
     * @param Long id
     * @return PlayList playList
     */
    PlayList getplayListById(Long id);

    /**
     * @brief elimina una playList de la base de datos por la id
     * @param Long id
     */
    void deleteplayListById(Long id);
}
