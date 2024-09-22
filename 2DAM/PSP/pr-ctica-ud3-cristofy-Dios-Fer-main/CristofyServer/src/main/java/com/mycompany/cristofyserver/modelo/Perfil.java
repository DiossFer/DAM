package com.mycompany.cristofyserver.modelo;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.Table;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.annotations.OnDelete;
import org.hibernate.annotations.OnDeleteAction;

@Entity
@Table(name="perfiles")
public class Perfil {
    
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id_perfil;

    @Column(name="login", unique=true, nullable=false)
    private String login;

    @Column(name="correo", unique=true, nullable=false)
    private String correo;

    @Column(name="userName", nullable=false)
    private String userName;

    @Column(name="contrasenia", nullable=false)
    private String contrasenia;
    
    @Column(name="conectado", nullable=false)
    private Boolean conectado;
    
    @Column(name="apellidos", nullable=false)
    private String apellidos;
    
    @ManyToMany (cascade = CascadeType.DETACH, mappedBy = "perfiles")
    @OnDelete(action = OnDeleteAction.CASCADE)
    List<PlayList> playLists;
    
    /**
     * @brief constructor por defecto de Perfil
     */
    public Perfil(){
        playLists = new ArrayList<>();
        conectado=false;
    }

    /**
     * @brief constructor por parametros de Perfil
     * @param String nomb
     * @param String ape
     * @param String em
     * @param String cont
     */
    public Perfil(String nomb, String ape, String em, String cont){
        this.login = nomb;
        this.correo = ape;
        this.userName = em;
        this.contrasenia = cont;
        playLists = new ArrayList<>();
        conectado=false;
    }
    
    /**
     * @brief get del atributo id_perfil
     * @return Long id_perfil
     */
    public Long getId_perfil(){
        return this.id_perfil;
    }

    /**
     * @brief get del atributo login
     * @return String login
     */
    public String getLogin(){
        return this.login;
    }

    /**
     * @brief get del atributo correo
     * @return String correo
     */
    public String getCorreo(){
        return this.correo;
    }

    /**
     * @brief get del atributo userName
     * @return String userName
     */
    public String getUserName(){
        return this.userName;
    }
    
    /**
     * @brief get del atributo contrasenia
     * @return String contrasenia
     */
    public String getContrasenia(){
        return this.contrasenia;
    }
    
    /**
     * @brief get del atributo playLists
     * @return List<PlayList> playLists
     */
    public List<PlayList> getPlayLists (){
        return this.playLists;
    }
    
    /**
     * @brief set del atributo playLists
     * @param List<PlayList> playLists
     */
    public void setPlayLists (List<PlayList> p){
        this.playLists=p;
    }

    /**
     * @brief set del atributo id_perfil
     * @param Long id_perfil
     */
    public void setId_perfil(Long ide){
        this.id_perfil = ide;
    }

    /**
     * @brief set del atributo login
     * @param String login
     */
    public void setLogin(String l){
        this.login = l;
    }

    /**
     * @brief set del atributo correo
     * @param String correo
     */
    public void setCorreo(String c){
        this.correo = c;
    }

    /**
     * @brief set del atributo userName
     * @param String userName
     */
    public void setUserName(String u){
        this.userName = u;
    }
    
    /**
     * @brief set del atributo contrasenia
     * @param String contrasenia
     */
    public void setContrasenia(String c){
        this.contrasenia = c;
    }

    public Boolean getConectado() {
        return conectado;
    }

    public void setConectado(Boolean conectado) {
        this.conectado = conectado;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }
    
    
}
