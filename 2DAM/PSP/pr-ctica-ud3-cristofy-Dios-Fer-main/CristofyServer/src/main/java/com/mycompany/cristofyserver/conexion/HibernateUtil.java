package com.mycompany.cristofyserver.conexion;

import com.mycompany.cristofyserver.modelo.*;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;

public class HibernateUtil {
  private static SessionFactory sessionFactory = null;
  private static Session session = null;
  private static String pathIni = "/CristofyBD_hibernate.cfg.xml";
  /**
   * Crea la factoria de sesiones
   */
  public static void buildSessionFactory(String path) {

    Configuration configuration = new Configuration();
    configuration.configure(path);
    
    // Se registran las clases que hay que mapear con cada tabla de la base de datos
    configuration.addAnnotatedClass(Artista.class);
    configuration.addAnnotatedClass(Cancion.class);
    configuration.addAnnotatedClass(Estadistica.class);
    configuration.addAnnotatedClass(Perfil.class);
    configuration.addAnnotatedClass(PlayList.class);
    
 
    ServiceRegistry serviceRegistry = new StandardServiceRegistryBuilder().applySettings(
      configuration.getProperties()).build();
    sessionFactory = configuration.buildSessionFactory(serviceRegistry);
  }
 
  /**
   * Abre una nueva sesión
   */
  public static void openSession(String path) {
    if (sessionFactory == null)
        buildSessionFactory(path);
        session = sessionFactory.openSession();
  }
 
  /**
   * Devuelve la sesión actual
   * @pre haber iniciado el path de la configuracion
   * @return
   */
  public static Session getCurrentSession() {
 
    if ((session == null) || (!session.isOpen()))
      openSession(pathIni);
 
    return session;
  }
 
  /**
   * Cierra Hibernate
   */
  public static void closeSessionFactory() {
 
    if (session != null)
      session.close();
 
    if (sessionFactory != null)
      sessionFactory.close();
  }
  
  public static void setPathIni (String newPathIni){
      HibernateUtil.pathIni = newPathIni;
  }
}