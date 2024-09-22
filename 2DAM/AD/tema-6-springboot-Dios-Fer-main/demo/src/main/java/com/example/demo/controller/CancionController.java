package com.example.demo.controller;


import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import com.example.demo.entity.Cancion;
import com.example.demo.entity.PlayList;

import org.springframework.ui.Model;
import com.example.demo.service.CancionService;
import com.example.demo.service.ArtistaService;
import com.example.demo.service.PlayListService;

@Controller
public class CancionController {

    private CancionService cancionSeserv;
    
    private ArtistaService artSeserv;
    
    private PlayListService playlistSeserv;

    /**
     * @brief constructor de CancionController
     * @param CancionService sts
     * @param ArtistaService as
     * @param PlayListService ps
     */
    public CancionController(CancionService sts, ArtistaService as, PlayListService ps){
        super();
        this.cancionSeserv = sts;
        this.artSeserv = as;
        this.playlistSeserv = ps;
    }
 
    /**
     * @brief dara las canciones del sistema al html se canciones
     * @param modelo
     * @return "canciones"
     */
    @GetMapping("/canciones")
    public String listcanciones(Model modelo){
        modelo.addAttribute("canciones", this.cancionSeserv.getAllcanciones());

        return "canciones";
    }

    /**
     * @brief dara una cancion vacio al html se create_cancion
     * @param modelo
     * @return "create_cancion"
     */
    @GetMapping("/canciones/new")
    public String crearcancion(Model modelo){
        Cancion cancion = new Cancion();
        
        modelo.addAttribute("cancion", cancion);
        modelo.addAttribute("artistas", this.artSeserv.getAllartistas());
        
        return "create_cancion";
    }

    /**
     * @brief guardara la cancion creada en create_cancion y redireccionara a /canciones
     * @param @ModelAttribute("cancion") Cancion cancion
     * @return "redirect:/canciones"
     */
    @PostMapping("/canciones")
    public String savecancion(@ModelAttribute("cancion") Cancion cancion){
        this.cancionSeserv.savecancion(cancion);
        return "redirect:/canciones";
    }

    /**
     * @brief dara los datos de la cancion seleccionada para su modificacion
     * @param @PathVariable Long id_cancion
     * @param Model modelo
     * @return "edit_cancion"
     */
    @GetMapping("/canciones/edit/{id_cancion}")
    public String editarcancion(@PathVariable Long id_cancion, Model modelo){
        modelo.addAttribute("cancion", this.cancionSeserv.getcancionById(id_cancion));
        
        return "edit_cancion";
    }

    /**
     * @brief guardara los cambios realizados en la modificacion de la cancion y redireccionara a / canciones
     * @param @PathVariable Long id_cancion
     * @param @ModelAttribute("cancion") Cancion std
     * @param Model modelo
     * @return "redirect:/canciones"
     */
    @PostMapping("/canciones/{id_cancion}")
    public String updatecancion(@PathVariable Long id_cancion, @ModelAttribute("cancion") Cancion std, Model modelo){
        Cancion cancionCogida = this.cancionSeserv.getcancionById(id_cancion);
        
        cancionCogida.setTitulo(std.getTitulo());
        cancionCogida.setRuta(std.getRuta());
        cancionCogida.setDuracion(std.getDuracion());
        cancionCogida.setAnioPublicacion(std.getAnioPublicacion());

        this.cancionSeserv.updatecancion(cancionCogida);

        return "redirect:/canciones";
    }

    /**
     * @brief eliminara la cancion seleccionada
     * @param @PathVariable Long id_cancion
     * @return "redirect:/canciones"
     */
    @GetMapping("/canciones/{id_cancion}")
    public String deletecancion(@PathVariable Long id_cancion){
        
        //Actualizacion del atributo NumCanciones
        for (PlayList p : cancionSeserv.getcancionById(id_cancion).getPlayLists()){
            p.setNumCanciones(p.getNumCanciones()-1);
            playlistSeserv.saveplayList(p);
        }
        
        this.cancionSeserv.deletecancionById(id_cancion);

        return "redirect:/canciones";

    }

}
