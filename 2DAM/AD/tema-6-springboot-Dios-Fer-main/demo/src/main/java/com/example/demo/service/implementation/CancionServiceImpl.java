package com.example.demo.service.implementation;

import java.util.List;

import org.springframework.stereotype.Service;

import com.example.demo.entity.Cancion;
import com.example.demo.repository.CancionRepository;
import com.example.demo.service.CancionService;

@Service
public class CancionServiceImpl implements CancionService{

    private CancionRepository cancionRepo;
    
    /**
     * @brief constructor CancionServiceImpl
     * @param CancionRepository str
     */
    public CancionServiceImpl(CancionRepository str){
        super();
        this.cancionRepo = str;
    }

    /**
     * @brief obtiene todos las canciones de la base de datos
     * @return List<Cancion> artistas
     */
    @Override
    public List<Cancion> getAllcanciones() {
        return this.cancionRepo.findAll();
    }

    /**
     * @brief guarda una cancion en la base de datos
     * @param Cancion std
     * @return Cancion cancion
     */
    @Override
    public Cancion savecancion(Cancion std) {
        return this.cancionRepo.save(std);
    }
    
    /**
     * @brief guarda los cambios sobre una cancion en la base de datos
     * @param Cancion std
     * @return Cancion cancion
     */
    @Override
    public Cancion updatecancion(Cancion std) {
        return this.cancionRepo.save(std);
    }

    /**
     * @brief obtiene una cancion de la base de datos por la id
     * @param Long id
     * @return Cancion cancion
     */
    @Override
    public Cancion getcancionById(Long id) {
        return this.cancionRepo.findById(id).get();
    }

    /**
     * @brief elimina una cancion de la base de datos por la id
     * @param Long id
     */
    @Override
    public void deletecancionById(Long id) {
        this.cancionRepo.deleteById(id);
    }
    
}
