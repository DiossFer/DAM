/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto_ad_hibernate.modelos;

import jakarta.persistence.CascadeType;
import java.io.Serializable;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.OneToOne;
import jakarta.persistence.PrimaryKeyJoinColumn;
import jakarta.persistence.Table;
import jakarta.persistence.UniqueConstraint;

/**
 *
 * @author DiosFer
 */
@Entity
//@org.hibernate.annotations.Entity(optimisticLock = OptimisticLockType.ALL)
@Table(name = "servidores", uniqueConstraints = {
    @UniqueConstraint(columnNames = "IdServer"),
    @UniqueConstraint(columnNames = "region") })
public class Servidor implements Serializable {
    
    
    /********************************
     ********   Atributos   *********
     ********************************/
    private static final long serialVersionUID = -1798070786993154676L;

    @Id
    @Column(name = "IdServer", unique = true, nullable = true, length = 100)
    private String IdServer; 
    
    @Column(name = "region", unique = false, nullable = true, length = 100)
    private String region;
    

    
    
    private static int generar=0;
    
    /********************************
     *******   Constructor   ********
     ********************************/
    
    public Servidor() {
        setIdServer("");
        setRegion("");
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
    
    public void setGenerar(int generar) {
        this.generar = generar;
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
    
    public int getGenerar() {
        return generar;
    }
    

    
    
}
