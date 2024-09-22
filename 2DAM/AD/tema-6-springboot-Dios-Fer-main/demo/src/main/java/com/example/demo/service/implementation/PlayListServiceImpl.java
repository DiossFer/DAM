package com.example.demo.service.implementation;

import java.util.List;

import org.springframework.stereotype.Service;

import com.example.demo.entity.PlayList;
import com.example.demo.repository.PlayListRepository;
import com.example.demo.service.PlayListService;

@Service
public class PlayListServiceImpl implements PlayListService{

    private PlayListRepository playListRepo;
    
    /**
     * @brief constructor de PlayListServiceImpl
     * @param PlayListRepository str
     */
    public PlayListServiceImpl(PlayListRepository str){
        super();
        this.playListRepo = str;
    }

    /**
     * @brief obtiene todas las playLists de la base de datos
     * @return List<PlayList> artistas
     */
    @Override
    public List<PlayList> getAllplayLists() {
        return this.playListRepo.findAll();
    }

    /**
     * @brief guarda una playList en la base de datos
     * @param PlayList std
     * @return PlayList playList
     */
    @Override
    public PlayList saveplayList(PlayList std) {
        return this.playListRepo.save(std);
    }

    /**
     * @brief guarda los cambios sobre una playList en la base de datos
     * @param PlayList std
     * @return PlayList playList
     */
    @Override
    public PlayList updateplayList(PlayList std) {
        return this.playListRepo.save(std);
    }

    /**
     * @brief obtiene una playList de la base de datos por la id
     * @param Long id
     * @return PlayList playList
     */
    @Override
    public PlayList getplayListById(Long id) {
        return this.playListRepo.findById(id).get();
    }

    /**
     * @brief elimina una playList de la base de datos por la id
     * @param Long id
     */
    @Override
    public void deleteplayListById(Long id) {
        this.playListRepo.deleteById(id);
    }
    
}
