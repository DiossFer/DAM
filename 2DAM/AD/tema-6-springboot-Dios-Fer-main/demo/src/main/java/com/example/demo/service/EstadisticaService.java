package com.example.demo.service;

import java.util.List;

import com.example.demo.entity.Estadistica;

public interface EstadisticaService {
    
    /**
     * @brief obtiene todos las estadisticas de la base de datos
     * @return List<Estadistica> artistas
     */
    List<Estadistica> getAllestadisticas();

    /**
     * @brief guarda una estadistica en la base de datos
     * @param Estadistica std
     * @return Estadistica estadistica
     */
    Estadistica saveestadistica(Estadistica std);

    /**
     * @brief guarda los cambios sobre una estadistica en la base de datos
     * @param Estadistica std
     * @return Estadistica estadistica
     */
    Estadistica updateestadistica(Estadistica std);

    /**
     * @brief obtiene una estadistica de la base de datos por la id
     * @param Long id
     * @return Estadistica estadistica
     */
    Estadistica getestadisticaById(Long id);

    /**
     * @brief elimina una estadistica de la base de datos por la id
     * @param Long id
     */
    void deleteestadisticaById(Long id);
}
