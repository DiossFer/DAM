package com.example.demo.controller;


import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import com.example.demo.entity.Perfil;
import com.example.demo.entity.PlayList;

import org.springframework.ui.Model;
import com.example.demo.service.PerfilService;
import org.springframework.web.bind.annotation.RequestParam;
import com.example.demo.service.PlayListService;
import java.util.List;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

@Controller
public class PerfilController {

    private PerfilService perfilSeserv;
    private PlayListService playListSeserv;

    /**
     * @brief constructor de PerfilController
     * @param PerfilService sts
     * @param PlayListService ps
     */
    public PerfilController(PerfilService sts, PlayListService ps){
        super();
        this.perfilSeserv = sts;
        this.playListSeserv = ps;
    }
    
 
    /**
     * @brief dara los perfiles del sistema al html de perfiles
     * @param modelo
     * @return "perfiles"
     */
    @GetMapping("/perfiles")
    public String listperfiles(Model modelo){
        modelo.addAttribute("perfiles", this.perfilSeserv.getAllperfiles());

        return "perfiles";
    }

    /**
     * @brief dara un perfil vacio al html de create_perfil
     * @param modelo
     * @return "create_perfil"
     */
    @GetMapping("/perfiles/new")
    public String crearperfil(Model modelo){
        Perfil perfil = new Perfil();

        modelo.addAttribute("perfil", perfil);

        return "create_perfil";
    }

    
    /**
     * @brief guardara el perfil creado en create_perfil y redireccionara a /perfiles
     * @param @ModelAttribute("perfil") Perfil perfil
     * @param RedirectAttributes errorAtribute
     * @return "redirect:/perfiles"
     */
    @PostMapping("/perfiles")
    public String saveperfil(@ModelAttribute("perfil") Perfil perfil, RedirectAttributes errorAtribute){
        
        String r = "redirect:/perfiles";
        
        // Filtro para unique
        try {
            
            this.perfilSeserv.saveperfil(perfil);
            
        }catch(Exception e){
            
            if (e.getMessage().contains("@")){ // correo repetido
                errorAtribute.addFlashAttribute("error", "Correo ya esta en uso");
            }else{ // login repetido
                errorAtribute.addFlashAttribute("error", "Login ya esta en uso");
            }
            
            r = "redirect:/perfiles/new";
        }
        
        return r;
    }

    /**
     * @brief dara los datos del perfil seleccionado para su modificacion
     * @param @PathVariable Long id_perfil
     * @param Model modelo
     * @return "edit_perfil"
     */
    @GetMapping("/perfiles/edit/{id_perfil}")
    public String editarperfil(@PathVariable Long id_perfil, Model modelo){
        modelo.addAttribute("perfil", this.perfilSeserv.getperfilById(id_perfil));
        return "edit_perfil";
    }

    /**
     * @brief guardara los cambios realizados en la modificacion del perfil y redireccionara a /perfiles
     * @param @PathVariable Long id_perfil
     * @param @ModelAttribute("perfil") Perfil std
     * @param Model modelo
     * @param RedirectAttributes errorAtribute
     * @return "redirect:/perfiles"
     */
    @PostMapping("/perfiles/{id_perfil}")
    public String updateperfil(@PathVariable Long id_perfil, @ModelAttribute("perfil") Perfil std, Model modelo, RedirectAttributes errorAtribute){
        Perfil perfilCogido = this.perfilSeserv.getperfilById(id_perfil);
        
        perfilCogido.setLogin(std.getLogin());
        perfilCogido.setCorreo(std.getCorreo());
        perfilCogido.setUserName(std.getUserName());
        perfilCogido.setContrasenia(std.getContrasenia());

        

        String r = "redirect:/perfiles";
        
        // Filto para unique
        if (perfilSeserv.isLoginUseByAnotherPerfil(id_perfil, perfilCogido.getLogin())){
            errorAtribute.addFlashAttribute("error", "Login ya esta en uso");
            r = "redirect:/perfiles";
            
        }
        else if (perfilSeserv.isLoginUseByAnotherPerfil(id_perfil, perfilCogido.getLogin())){
            errorAtribute.addFlashAttribute("error", "Correo ya esta en uso");
            r = "redirect:/perfiles";
            
        }
        else{
            this.perfilSeserv.updateperfil(perfilCogido);
        }
        
        return r;
        
        
        
    }

    /**
     * @brief eliminara el artista seleccionado
     * @param @PathVariable Long id_artista
     * @return "redirect:/artistas"
     */
    @GetMapping("/perfiles/{id_perfil}")
    public String deleteperfil(@PathVariable Long id_perfil){
        this.perfilSeserv.deleteperfilById(id_perfil);

        return "redirect:/perfiles";
    }

    /**
     * @brief mandara los datos de las playlist del perfil para su administracion
     * @param @PathVariable Long id_perfil
     * @param Model modelo
     * @return "admin_perfil"
     */
    @GetMapping("/perfiles/admin/{id_perfil}")
    public String administrarplayList(@PathVariable Long id_perfil, Model modelo){
        modelo.addAttribute("perfil", this.perfilSeserv.getperfilById(id_perfil));
                
        Perfil p = this.perfilSeserv.getperfilById(id_perfil);
                
        List <PlayList> playListSistema = this.playListSeserv.getAllplayLists();
        
        List <PlayList> playListsUser = p.getPlayLists();
        
        playListSistema.removeAll(playListsUser);
        modelo.addAttribute("playListsRestantes", playListSistema);

        return "admin_perfil";
    }

    /**
     * @brief añade una playlist en el perfil
     * @param @PathVariable Long id_perfil
     * @param @RequestParam Long id_playList
     * @return "redirect:/perfiles/admin/"+id_perfil"
     */
    @PostMapping("/perfiles/admin/addPlayList/{id_perfil}")
    public String adminUpdatePerfil(@PathVariable Long id_perfil, @RequestParam Long id_playList) {
        
        Perfil perfilCogido = this.perfilSeserv.getperfilById(id_perfil);
        PlayList playListAdd = this.playListSeserv.getplayListById(id_playList);

        //perfilCogido.getPlayLists().add(playListAdd);
        playListAdd.getPerfiles().add(perfilCogido);
        

        //this.perfilSeserv.updateperfil(perfilCogido);
        this.playListSeserv.updateplayList(playListAdd);
        
        return "redirect:/perfiles/admin/"+id_perfil;
    }
    
    /**
     * @brief quita una playlist del perfil
     * @param @PathVariable Long id_perfil
     * @param @PathVariable Long id_playList
     * @return "redirect:/perfiles/admin/"+id_perfil"
     */
    @GetMapping("/perfiles/admin/remove/{id_perfil}/{id_playList}")
    public String removePlayListFromplayList(@PathVariable Long id_perfil, @PathVariable Long id_playList){

        Perfil perfilCogido = this.perfilSeserv.getperfilById(id_perfil);
        
        PlayList playListRemove = this.playListSeserv.getplayListById(id_playList);

        //perfilCogido.getPlayLists().remove(playListRemove);
        
        playListRemove.getPerfiles().remove(perfilCogido);

        this.playListSeserv.updateplayList(playListRemove);
        //this.perfilSeserv.updateperfil(perfilCogido);

        return "redirect:/perfiles/admin/"+id_perfil;

    }
}
