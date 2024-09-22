package com.example.demo.service;

import java.util.List;

import com.example.demo.entity.Perfil;

public interface PerfilService {
    
    /**
     * @brief obtiene todos los perfiles de la base de datos
     * @return List<Perfil> artistas
     */
    List<Perfil> getAllperfiles();

    /**
     * @brief guarda un perfil en la base de datos
     * @param Perfil std
     * @return Perfil perfil
     */
    Perfil saveperfil(Perfil std);

    /**
     * @brief guarda los cambios sobre una playList en la base de datos
     * @param Estadistica std
     * @return Estadistica playList
     */
    Perfil updateperfil(Perfil std);

    /**
     * @brief obtiene un perfil de la base de datos por la id
     * @param Long id
     * @return Perfil perfil
     */
    Perfil getperfilById(Long id);

    /**
     * @brief elimina un perfil de la base de datos por la id
     * @param Long id
     */
    void deleteperfilById(Long id);
    
    /**
     * @brief comprueba si el el login esta usado por un perfil que no sea el que se le ha pasado
     * @param Long id_perfil
     * @param String login
     * @return Boolean usado
     */
    Boolean isLoginUseByAnotherPerfil(Long id_perfil, String login);
    
    /**
     * @brief comprueba si el el email esta usado por un perfil que no sea el que se le ha pasado
     * @param Long id_perfil
     * @param String email
     * @return Boolean usado
     */
    Boolean isEmailUseByAnotherPerfil(Long id_perfil, String email);
}
