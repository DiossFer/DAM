package com.example.demo.controller;


import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import com.example.demo.entity.Artista;
import com.example.demo.entity.PlayList;
import com.example.demo.entity.Cancion;

import org.springframework.ui.Model;
import com.example.demo.service.ArtistaService;
import com.example.demo.service.PlayListService;

@Controller
public class ArtistaController {

    private ArtistaService artistaSeserv;
    private PlayListService playlistSeserv;

    /**
     * @brief constructor de ArtistaController
     * @param ArtistaService sts
     * @param PlayListService ps
     */
    public ArtistaController(ArtistaService sts, PlayListService ps){
        super();
        this.artistaSeserv = sts;
        this.playlistSeserv = ps;
    }
 
    /**
     * @brief dara los artistas del sistema al html se artistas
     * @param modelo
     * @return "artistas"
     */
    @GetMapping("/artistas")
    public String listartistas(Model modelo){
        modelo.addAttribute("artistas", this.artistaSeserv.getAllartistas());

        return "artistas";
    }

    /**
     * @brief dara un artista vacio al html se create_artista
     * @param modelo
     * @return "create_artista"
     */
    @GetMapping("/artistas/new")
    public String crearartista(Model modelo){
        Artista artista = new Artista();

        modelo.addAttribute("artista", artista);

        return "create_artista";
    }

    /**
     * @brief guardara el artista creado en create_artista y redireccionara a /artistas
     * @param @ModelAttribute("artista") Artista artista
     * @return "redirect:/artistas"
     */
    @PostMapping("/artistas")
    public String saveartista(@ModelAttribute("artista") Artista artista){
        this.artistaSeserv.saveartista(artista);
        return "redirect:/artistas";
    }

    /**
     * @brief dara los datos del artista seleccionado para su modificacion
     * @param @PathVariable Long id_artista
     * @param Model modelo
     * @return "edit_artista"
     */
    @GetMapping("/artistas/edit/{id_artista}")
    public String editarartista(@PathVariable Long id_artista, Model modelo){
        modelo.addAttribute("artista", this.artistaSeserv.getartistaById(id_artista));
        return "edit_artista";
    }

    /**
     * @brief guardara los cambios realizados en la modificacion del artista y redireccionara a /artistas
     * @param @PathVariable Long id_artista
     * @param @ModelAttribute("artista") Artista std
     * @param Model modelo
     * @return "redirect:/artistas"
     */
    @PostMapping("/artistas/{id_artista}")
    public String updateartista(@PathVariable Long id_artista, @ModelAttribute("artista") Artista std, Model modelo){
        Artista artistaCogido = this.artistaSeserv.getartistaById(id_artista);
        
        artistaCogido.setNombreArtista(std.getNombreArtista());

        this.artistaSeserv.updateartista(artistaCogido);

        return "redirect:/artistas";
    }

    /**
     * @brief eliminara el artista seleccionado
     * @param @PathVariable Long id_artista
     * @return "redirect:/artistas"
     */
    @GetMapping("/artistas/{id_artista}")
    public String deleteartista(@PathVariable Long id_artista){
        
        //Actualizacion del atributo NumCanciones
        for (Cancion c : artistaSeserv.getartistaById(id_artista).getCanciones()){
            for (PlayList p : c.getPlayLists()){
                p.setNumCanciones(p.getNumCanciones()-1);
                playlistSeserv.saveplayList(p);
            }
        }
        
        
        
        this.artistaSeserv.deleteartistaById(id_artista);

        return "redirect:/artistas";

    }
}
