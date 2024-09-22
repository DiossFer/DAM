/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyserver;

import com.mycompany.cristofyserver.buffer.Buffer;
import com.mycompany.cristofyserver.modelo.Perfil;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

/**
 *
 * @author DiosFer
 */
public class ModelController {
    
    Buffer buffer;
    
    public ModelController (Buffer b){
        buffer = b;
    }
    
    public Boolean validarLogin (String mensaje){
        // mensaje --> "login" + # + "pass"
        String m;
        Boolean esVailido=true;
        String [] mensajes;
        mensajes = mensaje.split("#");
        if (mensajes.length!=2){
            
            
            
            esVailido=false;
            
        }
        else{
            Boolean valido=false;

            String usser = mensajes[0];
            String pass = mensajes[1];
            if (this.existeUser(usser)){
                if (passUsser(pass, usser)){
                    valido=true;
                }
            }

            if (valido){
                
                esVailido=true;
            }
            else{
                esVailido=false;
                m = "PROTOCOLCRISTOFY1.0#"+
                    LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss")) +
                    "#ERROR#BAD_CREDENTIALS";
                

            }
        }

        
        return esVailido;
    }
    
    public Boolean existeUser (String u){
        Boolean existe = false;
        System.out.println("AAAAAAAAAAAAAAA");
        for (Perfil p : buffer.getConn().getPerfiles()){
            if (u.equals(p.getLogin())){
                existe=true;
            }
        }
        System.out.println("--->"+existe);
        return existe;
    }
    
    public Boolean passUsser (String pass, String u){
        Boolean valido = false;
        
        for (Perfil p : buffer.getConn().getPerfiles()){
            if (u.equals(p.getLogin())){
                if (p.getContrasenia().equals(pass)){
                    valido=true;
                }
            }
        }
        System.out.println("--->"+valido);
        return valido;
    }
    
}
