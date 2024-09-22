package com.example.demo.service.implementation;

import java.util.List;

import org.springframework.stereotype.Service;

import com.example.demo.entity.Estadistica;
import com.example.demo.repository.EstadisticaRepository;
import com.example.demo.service.EstadisticaService;

@Service
public class EstadisticaServiceImpl implements EstadisticaService{

    private EstadisticaRepository estadisticaRepo;
    
    /**
     * @brief constructor de EstadisticaServiceImpl;
     * @param EstadisticaRepository str
     */
    public EstadisticaServiceImpl(EstadisticaRepository str){
        super();
        this.estadisticaRepo = str;
    }

    /**
     * @brief obtiene todos las estadisticas de la base de datos
     * @return List<Estadistica> artistas
     */
    @Override
    public List<Estadistica> getAllestadisticas() {
        return this.estadisticaRepo.findAll();
    }

    /**
     * @brief guarda una estadistica en la base de datos
     * @param Estadistica std
     * @return Estadistica estadistica
     */
    @Override
    public Estadistica saveestadistica(Estadistica std) {
        return this.estadisticaRepo.save(std);
    }

    /**
     * @brief guarda los cambios sobre una estadistica en la base de datos
     * @param Estadistica std
     * @return Estadistica estadistica
     */
    @Override
    public Estadistica updateestadistica(Estadistica std) {
        return this.estadisticaRepo.save(std);
    }

    /**
     * @brief obtiene una estadistica de la base de datos por la id
     * @param Long id
     * @return Estadistica estadistica
     */
    @Override
    public Estadistica getestadisticaById(Long id) {
        return this.estadisticaRepo.findById(id).get();
    }

    /**
     * @brief elimina una estadistica de la base de datos por la id
     * @param Long id
     */
    @Override
    public void deleteestadisticaById(Long id) {
        this.estadisticaRepo.deleteById(id);
    }
    
}
