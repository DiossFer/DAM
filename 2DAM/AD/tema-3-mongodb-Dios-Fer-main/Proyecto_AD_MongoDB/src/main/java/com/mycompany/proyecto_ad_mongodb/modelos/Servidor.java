/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto_ad_mongodb.modelos;

/**
 *
 * @author DiosFer
 */
public class Servidor {
    
    
    /********************************
     ********   Atributos   *********
     ********************************/
    
    private String IdServer; 
    private String region;
    private static int generar=0;
    
    /********************************
     *******   Constructor   ********
     ********************************/
    
    public Servidor() {

    }
    
    /**
     * @brief Constructor de Servidor generando id a partir de la variable
     * @pre 
     * @post 
     * @param String region
     */
    public Servidor(String region) {
        setRegion (region);
        generar++;
        setIdServer("S-" + generar);
        
    }
    
    /**
     * @brief Constructor de Servidor con id existente (constructor de carga)
     * @post 
     * @param String Id
     * @param String region
     */
    public Servidor(String Id, String region) {
        setIdServer (Id);
        setRegion (region);
        if ((Integer.valueOf(Id.substring(2)))>generar){
            generar = (Integer.valueOf(Id.substring(2)));
        }
    }

    /********************************
     **********   Set's   ***********
     ********************************/
    
    public void setIdServer(String IdServer) {
        this.IdServer = IdServer;
    }
    
    public void setRegion(String region) {
        this.region = region;
    }
    
   
      
    /********************************
     **********   Get's   ***********
     ********************************/
        
    public String getIdServer() {
        return IdServer;
    }
    
    public String getRegion() {
        return region;
    }

    
    
}
