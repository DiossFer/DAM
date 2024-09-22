/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyserver.conexion;

import com.mycompany.cristofyserver.modelo.Cancion;
import com.mycompany.cristofyserver.modelo.Estadistica;
import com.mycompany.cristofyserver.modelo.Perfil;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.Session;
import org.hibernate.query.Query;

/**
 *
 * @author DiosFer
 */
public class Conexion {
        
    private final String dbName = "cristofybd";
    
    
    public Conexion (){
        
        HibernateUtil.getCurrentSession();
        
    }
    
    public void updatePerfil (Perfil p){
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        sesion.save(p);
        sesion.getTransaction().commit();
        sesion.close();
    }
    
    public List<Perfil> getPerfiles (){
        
        List<Perfil> perfiles = new ArrayList<>();
        
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Perfil");
        perfiles = (ArrayList<Perfil>) query.list();
        
        
        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        return perfiles;
    }
    
    public Perfil getPerfilesById (Long id){
        
        Perfil p1 = null;
        List<Perfil> perfiles = new ArrayList<>();
        
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Perfil WHERE id_perfil= :id");
        query.setParameter("id", id);
        perfiles = (ArrayList<Perfil>) query.list();
        
        if (perfiles.size()==1){
            p1=perfiles.get(0);
        }
        
        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        return p1;
    }
    public Perfil getPerfilesByLogin (String login){
        
        Perfil p1 = null;
        List<Perfil> perfiles = new ArrayList<>();
        
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Perfil WHERE login= :log");
        query.setParameter("log", login);
        perfiles = (ArrayList<Perfil>) query.list();
        
        if (perfiles.size()==1){
            p1=perfiles.get(0);
        }
        
        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        return p1;
    }
    
    public List<Cancion> getCanciones (){
        
        List<Cancion> canciones = new ArrayList<>();
        
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Cancion");
        canciones = (ArrayList<Cancion>) query.list();
        
        
        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        return canciones;
    }
    public Cancion getCancionById (Long id){
        
        Cancion p1 = null;
        List<Cancion> canciones = new ArrayList<>();
        
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Cancion WHERE id_cancion= :id");
        query.setParameter("id", id);
        canciones = (ArrayList<Cancion>) query.list();
        
        if (canciones.size()==1){
            p1=canciones.get(0);
        }
        
        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        return p1;
    }
    
    public void updateEstadistica (Estadistica e){
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        sesion.save(e);
        sesion.getTransaction().commit();
        sesion.close();
    }
}
