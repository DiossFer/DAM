package com.mycompany.pruebabdxml;

/**
 *
 * @author diosfer
 */
public class Perfil {
    private Long id;
    private String nombreUsuario;
    private String login;
    private String pasword;
    private String email;
    
    private static Long idActual = 0l;

    public Perfil(String login, String pasword, String nombreUsuario, String email) {
        idActual++;
        this.id=idActual;
        this.nombreUsuario = nombreUsuario;
        this.login = login;
        this.pasword = pasword;
        this.email = email;
    }
    public Perfil(Long id, String login, String pasword, String nombreUsuario, String email) {
        
        if (id>idActual){
            idActual = id;
        }
        this.id=id;
        this.nombreUsuario = nombreUsuario;
        this.login = login;
        this.pasword = pasword;
        this.email = email;
    }

    public String getNombreUsuario() {
        return nombreUsuario;
    }

    public void setNombreUsuario(String nombreUsuario) {
        this.nombreUsuario = nombreUsuario;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getPasword() {
        return pasword;
    }

    public void setPasword(String pasword) {
        this.pasword = pasword;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public static Long getIdActual() {
        return idActual;
    }

    public static void setIdActual(Long idActual) {
        Perfil.idActual = idActual;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }
    

    @Override
    public String toString() {
        String salida="";
        salida += "Perfil Id-" + this.getId()+": \n";
        salida += "Login: " + this.getLogin() + "\n";
        salida += "Pasword: " + this.getPasword()+ "\n";
        salida += "Email: " + this.getEmail()+ "\n";
        salida += "UserName: " + this.getNombreUsuario()+ "\n";
        return salida;
    }
    
    
}
