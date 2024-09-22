package com.example.demo.controller;


import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import com.example.demo.entity.PlayList;
import com.example.demo.entity.Cancion;
import com.example.demo.entity.Estadistica;
import com.example.demo.entity.Perfil;

import org.springframework.ui.Model;
import com.example.demo.service.PlayListService;
import com.example.demo.service.EstadisticaService;
import com.example.demo.service.PerfilService;
import com.example.demo.service.CancionService;
import org.springframework.web.bind.annotation.RequestParam;
import java.util.List;

@Controller
public class PlayListController {

    private PlayListService playListSeserv;
    private PerfilService perfilSeserv;
    private CancionService cancionSeserv;
    private EstadisticaService estadisticaSeserv;

    /**
     * @brief constructor de PerfilController
     * @param PlayListService sts
     * @param PerfilService ps
     * @param CancionService cs
     * @param EstadisticaService es
     */
    public PlayListController(PlayListService sts, PerfilService ps, CancionService cs, EstadisticaService es){
        super();
        this.playListSeserv = sts;
        this.perfilSeserv = ps;
        this.cancionSeserv = cs;
        this.estadisticaSeserv =es;

    }
 
    /**
     * @brief dara las playlist del sistema al html de playlist
     * @param modelo
     * @return "playLists"
     */
    @GetMapping("/playLists")
    public String listplayLists(Model modelo){
        modelo.addAttribute("playLists", this.playListSeserv.getAllplayLists());
        
        return "playLists";
    }

    /**
     * @brief dara una playlist vacia al html de create_playList
     * @param modelo
     * @return "create_playList"
     */
    @GetMapping("/playLists/new")
    public String crearplayList(Model modelo){
        PlayList playList = new PlayList();

        modelo.addAttribute("playList", playList);
        modelo.addAttribute("perfiles", this.perfilSeserv.getAllperfiles());

        return "create_playList";
    }

    /**
     * @brief guardara la playList creada en create_playList y redireccionara a /playLists
     * @param @ModelAttribute("playList") PlayList playList
     * @return "redirect:/playLists"
     */
    @PostMapping("/playLists")
    public String saveplayList(@ModelAttribute("playList") PlayList playList){
        this.playListSeserv.saveplayList(playList);
        
        Perfil creador = perfilSeserv.getperfilById(playList.getIdCreador());
        
        PlayList pModPostUser = this.playListSeserv.getplayListById(playList.getId_playList());
        pModPostUser.getPerfiles().add(creador);
        this.playListSeserv.saveplayList(pModPostUser);
        
        return "redirect:/playLists";
    }

    /**
     * @brief dara los datos de la playList seleccionada para su modificacion
     * @param @PathVariable Long id_playList
     * @param Model modelo
     * @return "edit_playList"
     */
    @GetMapping("/playLists/edit/{id_playList}")
    public String editarplayList(@PathVariable Long id_playList, Model modelo){
                
        modelo.addAttribute("playList", this.playListSeserv.getplayListById(id_playList));
        
        
        return "edit_playList";
    }
    

    /**
     * @brief guardara los cambios realizados en la modificacion de la playList y redireccionara a /playLists
     * @param @PathVariable Long id_playList
     * @param @ModelAttribute("playList") Perfil std
     * @param Model modelo
     * @return "redirect:/playLists"
     */
    @PostMapping("/playLists/{id_playList}")
    public String updateplayList(@PathVariable Long id_playList, @ModelAttribute("playList") PlayList std, Model modelo){
        PlayList playListCogido = this.playListSeserv.getplayListById(id_playList);
        
        playListCogido.setNombrePlayList(std.getNombrePlayList());        

        this.playListSeserv.updateplayList(playListCogido);

        return "redirect:/playLists";
    }

    /**
     * @brief eliminara la playList seleccionado
     * @param @PathVariable Long id_playList
     * @return "redirect:/playLists"
     */
    @GetMapping("/playLists/{id_playList}")
    public String deleteplayList(@PathVariable Long id_playList){
        
        //Actualizacion del atributo VecesIncluidaEnPlayLists
        
        for (Cancion c : this.playListSeserv.getplayListById(id_playList).getCanciones()){
            
            Estadistica e = c.getEstadisticaCancion();
        
            e.setVecesIncluidaEnPlayLists(e.getVecesIncluidaEnPlayLists()-1);

            this.estadisticaSeserv.updateestadistica(e);
            
        }
        
        this.playListSeserv.deleteplayListById(id_playList);

        
        
        
        return "redirect:/playLists";

    }
    
    /**
     * @brief mandara los datos de las canciones de la playList para su administracion
     * @param @PathVariable Long id_playList
     * @param Model modelo
     * @return "admin_playList"
     */
    @GetMapping("/playLists/admin/{id_playList}")
    public String administrarplayList(@PathVariable Long id_playList, Model modelo){
        modelo.addAttribute("playList", this.playListSeserv.getplayListById(id_playList));
                
        PlayList pl = this.playListSeserv.getplayListById(id_playList);
                
        List <Cancion> cancionesSistema = this.cancionSeserv.getAllcanciones();
        
        List <Cancion> cancionesUser = pl.getCanciones();
        
        cancionesSistema.removeAll(cancionesUser);
        
        modelo.addAttribute("cancionesRestantes", cancionesSistema);

        return "admin_playList";
    }
    
    /**
     * @brief añade una cancion en la playList
     * @param @PathVariable Long id_playList
     * @param @RequestParam Long id_cancion
     * @return "redirect:/playLists/admin/"+id_playList
     */
    @PostMapping("/playLists/admin/addCancion/{id_playList}")
    public String adminUpdatePlayList(@PathVariable Long id_playList, @RequestParam Long id_cancion) {
        
        PlayList playListCogido = this.playListSeserv.getplayListById(id_playList);
        Cancion cancionAdd = this.cancionSeserv.getcancionById(id_cancion);

        playListCogido.getCanciones().add(cancionAdd);
        playListCogido.setNumCanciones(playListCogido.getNumCanciones()+1);
        
        this.playListSeserv.updateplayList(playListCogido);
        
        //Actualizacion del atributo VecesIncluidaEnPlayLists
        Estadistica e = cancionAdd.getEstadisticaCancion();
        
        e.setVecesIncluidaEnPlayLists(e.getVecesIncluidaEnPlayLists()+1);
        
        this.estadisticaSeserv.updateestadistica(e);
        

        return "redirect:/playLists/admin/"+id_playList;
    }
    
    /**
     * @brief quita una cancion de la playList
     * @param @PathVariable Long id_playList
     * @param @PathVariable Long id_cancion
     * @return "redirect:/playLists/admin/"+id_playList
     */
    @GetMapping("/playLists/admin/remove/{id_playList}/{id_cancion}")
    public String removeCancionFromplayList(@PathVariable Long id_playList, @PathVariable Long id_cancion){

        PlayList playListCogido = this.playListSeserv.getplayListById(id_playList);
        Cancion cancionRemove = this.cancionSeserv.getcancionById(id_cancion);

        playListCogido.getCanciones().remove(cancionRemove);
        playListCogido.setNumCanciones(playListCogido.getNumCanciones()-1);
        
        this.playListSeserv.updateplayList(playListCogido);

        //Actualizacion del atributo VecesIncluidaEnPlayLists
        Estadistica e = cancionRemove.getEstadisticaCancion();
        
        e.setVecesIncluidaEnPlayLists(e.getVecesIncluidaEnPlayLists()-1);
        
        this.estadisticaSeserv.updateestadistica(e);
        
        return "redirect:/playLists/admin/"+id_playList;

    }
    
}
