package com.example.demo.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.example.demo.entity.Perfil;

@Repository
public interface PerfilRepository extends JpaRepository<Perfil,Long>{

    /**
     * @brief metodo para obtener el perfil por un login 
     * @param String login
     */
    public Perfil findByLogin(String login);

    /**
     * @brief metodo para obtener el perfil por un correo 
     * @param String email
     */
    public Perfil findByCorreo(String email);

} 
