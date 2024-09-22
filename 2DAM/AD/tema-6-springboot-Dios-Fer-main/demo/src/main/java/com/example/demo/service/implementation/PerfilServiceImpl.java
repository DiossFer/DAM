package com.example.demo.service.implementation;

import java.util.List;

import org.springframework.stereotype.Service;

import com.example.demo.entity.Perfil;
import com.example.demo.repository.PerfilRepository;
import com.example.demo.service.PerfilService;

@Service
public class PerfilServiceImpl implements PerfilService{

    private PerfilRepository perfilRepo;
    
    /**
     * @brief constructor de PerfilServiceImpl
     * @param PerfilRepository str
     */
    public PerfilServiceImpl(PerfilRepository str){
        super();
        this.perfilRepo = str;
    }

    /**
     * @brief obtiene todos los perfiles de la base de datos
     * @return List<Perfil> artistas
     */
    @Override
    public List<Perfil> getAllperfiles() {
        return this.perfilRepo.findAll();
    }

    /**
     * @brief guarda un perfil en la base de datos
     * @param Perfil std
     * @return Perfil perfil
     */
    @Override
    public Perfil saveperfil(Perfil std) {
        return this.perfilRepo.save(std);
    }

    /**
     * @brief guarda los cambios sobre una estadistica en la base de datos
     * @param Estadistica std
     * @return Estadistica estadistica
     */
    @Override
    public Perfil updateperfil(Perfil std) {
        return this.perfilRepo.save(std);
    }

    /**
     * @brief obtiene un perfil de la base de datos por la id
     * @param Long id
     * @return Perfil perfil
     */
    @Override
    public Perfil getperfilById(Long id) {
        return this.perfilRepo.findById(id).get();
    }

    /**
     * @brief elimina un perfil de la base de datos por la id
     * @param Long id
     */
    @Override
    public void deleteperfilById(Long id) {
        this.perfilRepo.deleteById(id);
    }
    
    /**
     * @brief comprueba si el el login esta usado por un perfil que no sea el que se le ha pasado
     * @param Long id_perfil
     * @param String login
     * @return Boolean usado
     */
    @Override
    public Boolean isLoginUseByAnotherPerfil (Long id_perfil, String login){

        Perfil perfilBD = perfilRepo.findByLogin(login);
        
        return (perfilBD != null) && !(perfilBD.getId_perfil().equals(id_perfil));

        
    }
    
    /**
     * @brief comprueba si el el email esta usado por un perfil que no sea el que se le ha pasado
     * @param Long id_perfil
     * @param String email
     * @return Boolean usado
     */
    @Override
    public Boolean isEmailUseByAnotherPerfil (Long id_perfil, String email){

        Perfil perfilBD = perfilRepo.findByCorreo(email);
        
        return (perfilBD != null) && !(perfilBD.getId_perfil().equals(id_perfil));

        
    }
    
}
