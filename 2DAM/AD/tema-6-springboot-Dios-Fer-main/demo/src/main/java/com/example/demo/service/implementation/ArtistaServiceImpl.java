package com.example.demo.service.implementation;

import java.util.List;

import org.springframework.stereotype.Service;

import com.example.demo.entity.Artista;
import com.example.demo.repository.ArtistaRepository;
import com.example.demo.service.ArtistaService;

@Service
public class ArtistaServiceImpl implements ArtistaService{

    private ArtistaRepository artistaRepo;
    
    /**
     * @brief constructor ArtistaServiceImpl 
     * @param ArtistaRepository str
     */
    public ArtistaServiceImpl(ArtistaRepository str){
        super();
        this.artistaRepo = str;
    }

     /**
     * @brief obtiene todos los atistas de la base de datos
     * @return List<Artista> artistas
     */
    @Override
    public List<Artista> getAllartistas() {
        return this.artistaRepo.findAll();
    }

    /**
     * @brief guarda un artista en la base de datos
     * @param Artista std
     * @return Artista artista
     */
    @Override
    public Artista saveartista(Artista std) {
        return this.artistaRepo.save(std);
    }

    /**
     * @brief guarda los cambios sobre un artista en la base de datos
     * @param Artista std
     * @return Artista artista
     */
    @Override
    public Artista updateartista(Artista std) {
        return this.artistaRepo.save(std);
    }

    /**
     * @brief obtiene un artista de la base de datos por la id
     * @param Long id
     * @return Artista artista
     */
    @Override
    public Artista getartistaById(Long id) {
        return this.artistaRepo.findById(id).get();
    }

    /**
     * @brief elimina un artista de la base de datos por la id
     * @param Long id
     */
    @Override
    public void deleteartistaById(Long id) {
        this.artistaRepo.deleteById(id);
    }
    
}
