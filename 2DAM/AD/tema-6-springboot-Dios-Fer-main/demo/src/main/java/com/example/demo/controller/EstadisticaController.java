package com.example.demo.controller;


import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import org.springframework.ui.Model;
import com.example.demo.service.EstadisticaService;

@Controller
public class EstadisticaController {

    private EstadisticaService estadisticaSeserv;

    /**
     * @brief constructor de EstadisticaController
     * @param EstadisticaService sts
     */
    public EstadisticaController(EstadisticaService sts){
        super();
        this.estadisticaSeserv = sts;
    }
 
    /**
     * @brief dara las estadisticas del sistema al html de estadisticas
     * @param modelo
     * @return "estadisticas"
     */
    @GetMapping("/estadisticas")
    public String listestadisticas(Model modelo){
        modelo.addAttribute("estadisticas", this.estadisticaSeserv.getAllestadisticas());

        return "estadisticas";
    }

    
}
