package com.mycompany.proyecto_ad_hibernate.conexion;

import com.mycompany.proyecto_ad_hibernate.modelos.Jugador;
import com.mycompany.proyecto_ad_hibernate.modelos.Partida;
import com.mycompany.proyecto_ad_hibernate.modelos.Servidor;
import com.mycompany.proyecto_ad_hibernate.modelos.InventarioCompartido;
import java.util.ArrayList;


import java.util.List;

import org.hibernate.Session;
import org.hibernate.query.Query;

/**
 *
 * @author DiosFer
 */
public class Conexion {
    
    /*////////////////////////////////////////////////////////
    /////////////////////    Atributos    ///////////////////
    //////////////////////////////////////////////////////*/
    
    private ArrayList<Servidor> servidores_conexion;
    private ArrayList<Partida> partidas_conexion;
    private ArrayList<InventarioCompartido> inventarios_conexion;
    private ArrayList<Jugador> jugadores_conexion;
    
    private ArrayList<ArrayList<String>> auxIdInv;
        
    private String dbName;
    private String configuration;
    
    
    
         
    /*////////////////////////////////////////////////////////
    ////////////////////    Costructor    ///////////////////
    //////////////////////////////////////////////////////*/
    
    public Conexion (String NewdbName) throws Exception{
        
        this.dbName=NewdbName;
        this.configuration="/"+dbName+"_hibernate.cfg.xml";
        HibernateUtil.setPathIni(configuration);
        
        
        servidores_conexion = new ArrayList<Servidor>();
        inventarios_conexion = new ArrayList<InventarioCompartido>();
        jugadores_conexion = new ArrayList<Jugador>();
        partidas_conexion = new ArrayList<Partida>();
        
        auxIdInv = new ArrayList<ArrayList<String>>();

        
        CargarServidores();
        CargarJugadores();
        CargarInventarios();
        CargarPartidas();
        

    }

    

    
    /*////////////////////////////////////////////////////////
    ///////////////////    abrir-cerrar    //////////////////
    //////////////////////////////////////////////////////*/
    


    
    
    /**
     * @brief Cierra la consexion de la base de datos
     * @pre debe de haber una conexion abierta
     * @post se cerrara la conexion
     * @param 
     */
    public void cerrarConexion () throws Exception{

        HibernateUtil.closeSessionFactory();
        
    }
    
    
    /*////////////////////////////////////////////////////////
    /////////////////////    Insertar    ////////////////////
    //////////////////////////////////////////////////////*/
    
    /**
     * @brief Inserta un servidor en la base de datos y actualiza su id en el sistema
     * @param Servidor s
     * @post se actualizara la id y se añadira a la base de datos
     */
    public void InsertarServidor (Servidor s) throws Exception{

        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        try {
            
            // Comienzo transaccion
            session.beginTransaction();
            
            // Guardo el servidor
            session.save(s);
            
            // Termino transaccion guardando los cambios
            session.getTransaction().commit();
            
        }
        catch(Exception e){
            
            session.getTransaction().rollback();
            
            throw e;
            
        }
        
        
    }
    
    /**
     * @brief Inserta una partida en la base de datos y actualiza su id en el sistema
     * @param Partida p
     * @post se creara la partida en la bd y en el sistema
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String InsertarPartida (int numEspectadores, String IdServerPartida, String[] idsjugadores) throws Exception{
        
        String mensaje="VALIDO";

        //Filtro1
        if (!ExisteServidor(IdServerPartida)){
            mensaje = "No existe Id-Server";
        }
        //Filtro2
        else if (EstaUsadoServidor(IdServerPartida)){
            mensaje = "El servidor ya esta siendo usado";
        }
        //Filtro3
        else if (StringDuplicado(idsjugadores)){
            mensaje = "Hay jugadores duplicados";
        }
        //Filtro4
        else if (!ExistenJugadores(idsjugadores)){
            mensaje = "Algun jugador no existe";
        }
        //Filtro5
        else if (EstaUsadoAlgunJugador(idsjugadores)){
            mensaje = "Algun jugador ya esta en una partida";
        }
        
        /////////////////////////
        //Pasa todos los filtros
        
        else{
            

            
            // Cojo la sesion de usuario
            Session session = HibernateUtil.getCurrentSession();

            // Comienzo transaccion
            session.beginTransaction();
            
            
            Partida p = new Partida(numEspectadores, getServidorById(IdServerPartida));
            if (!idsjugadores[0].trim().equals("")){
                for (String idj : idsjugadores){
                    p.setUnJugador(getJugadorById(idj));
                    
                    //Modificamos el jugador
                    getJugadorById(idj).setpartidaEnJugador(p);
                    Jugador jugador = session.get(Jugador.class, idj);
                    jugador.setpartidaEnJugador(p);
                    session.save(jugador);
                }
            }




            // Guardo el servidor
            session.save(p);

            // Termino transaccion guardando los cambios
            session.getTransaction().commit();


            //Insertamos en el sistema
            partidas_conexion.add(p);
        
        
        }
        
        return mensaje;
    }
    
    /**
     * @brief Inserta un jugador en la base de datos y actualiza su id en el sistema, ademas de insertar su relacion
     * @param Jugador j
     * @post se actualizara la id y se añadira a la base de datos
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String InsertarJugador (String NickName, int nivel, String[] idsInventariosJugador) throws Exception{
        

        String mensaje="VALIDO";
        
        
        //Filtro1
        if (StringDuplicado(idsInventariosJugador)){
            mensaje = "Hay inventarios duplicados";
        }
        //Filtro2
        else if (!ExistenInventarios(idsInventariosJugador)){
            mensaje = "Algun inventario no existe";
        }


        /////////////////////////
        //Pasa todos los filtros
         
        else{
            
            //Creamos el jugador
            Jugador j = new Jugador (NickName, nivel);

            if (!idsInventariosJugador[0].trim().equals("")){
                for (String idI : idsInventariosJugador){
                    j.setInventarioConAcceso(getInventarioById(idI));
                    getInventarioById(idI).setJugadorConAcceso(j);
                }
            }

            jugadores_conexion.add (j);

            
            // Cojo la sesion de usuario
            Session session = HibernateUtil.getCurrentSession();

            // Comienzo transaccion
            session.beginTransaction();

            // Guardo el servidor
            session.save(j);

            // Termino transaccion guardando los cambios
            session.getTransaction().commit();
          
        }
        
        return mensaje;
    }
    
    /**
     * @brief Inserta un inventario en la base de datos y actualiza su id en el sistema, ademas de insertar su relacion
     * @param InventarioCompartido i
     * @post se actualizara la id y se añadira a la base de datos
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String InsertarInventario (int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios) throws Exception{
        
        
        String mensaje="VALIDO";
        
        
        //Filtro1
        if (StringDuplicado(idsJugadorInventarios)){
            mensaje = "Hay jugadores duplicados";
        }
        //Filtro2
        else if (!ExistenJugadores(idsJugadorInventarios)){
            mensaje = "Algun jugador no existe";
        }


        /////////////////////////
        //Pasa todos los filtros
          
        else{
            
            
            // Cojo la sesion de usuario
            Session session = HibernateUtil.getCurrentSession();

            // Comienzo transaccion
            session.beginTransaction();
            
            //Creamos el inventario
            InventarioCompartido i = new InventarioCompartido (slotsMaximos, slotsOcupados);


            if (!idsJugadorInventarios[0].trim().equals("")){
                for (String idJ : idsJugadorInventarios){
                    i.setJugadorConAcceso(getJugadorById(idJ));
                    getJugadorById(idJ).setInventarioConAcceso(i);
                }
            }
            
            //Inserto el inventario en el sistema
            inventarios_conexion.add(i);
            
            // Guardo el servidor
            session.merge(i);

            // Termino transaccion guardando los cambios
            session.getTransaction().commit();


        
             
        }
        
        return mensaje;

        
    }
    
    /*////////////////////////////////////////////////////////
    ////////////////////    Modificar    ////////////////////
    //////////////////////////////////////////////////////*/
    
    /**
     * @brief Modifica un servidor en la base de datos
     * @param Servidor s 
     * @param String region
     * @pre que este el objeto en la base de datos
     * @post se modificara el objeto y la instancia en la base de datos
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public void ModificarServidor (Servidor s, String region) throws Exception{
        
        
        
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        Servidor ss = sesion.get(Servidor.class, s.getIdServer());
        s.setRegion(region);
        ss.setRegion(region);
        
        sesion.save(ss);
        sesion.getTransaction().commit();
        sesion.close();
        
    }
    
    
    /**
     * @brief Modifica una partida en la base de datos
     * @param Partida p 
     * @param int numEspectadores
     * @param String id_server
     * @param String[] idsjugadores
     * @pre que este el objeto en la base de datos
     * @post se modificara el objeto y la instancia en la base de datos
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String ModificarPartida (String IdPartida, int numEspectadores, String id_server, String[] idsjugadores) throws Exception{
        String mensaje = "VALIDO";
        Partida p = getPartidaById(IdPartida);

        //Filtro1
        if (!ExisteServidor(id_server)){
            mensaje = "No existe Id-Server";
        }
        //Filtro2
        else if (EstaUsadoServidor(id_server) && !id_server.equals(p.getServerPartida().getIdServer())){
            mensaje = "El servidor ya esta siendo usado";
        }
        //Filtro3
        else if (StringDuplicado(idsjugadores)){
            mensaje = "Hay jugadores duplicados";
        }
        //Filtro4
        else if (!ExistenJugadores(idsjugadores)){
            mensaje = "Algun jugador no existe";
        }
        //Filtro5
        else if (EstaUsadoAlgunJugador(idsjugadores, p.getJugadores())){
            mensaje = "Algun jugador ya esta en una partida";
        }
        
        /////////////////////////
        //Pasa todos los filtros
                
        else{

            
            // Modificamos en la bd
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            
            
            //Modificamos objetos
            Partida pp = sesion.get(Partida.class, IdPartida);
            //Partida pp = getPartidaById(IdPartida);
            p.setNumEspectadores(numEspectadores);
            pp.setNumEspectadores(numEspectadores);
            
            p.setServerPartida(getServidorById(id_server));
            Servidor ss = sesion.get(Servidor.class, id_server);
            pp.setServerPartida(ss);
            
            /// Modificamos los jugadores
            
            
            //Quitamos los jugadores
            for (Jugador j : p.getJugadores()){
                Jugador jugador = sesion.get(Jugador.class, j.getIdPlayer());
                j.setpartidaEnJugador(null);
                jugador.setpartidaEnJugador(null);
                sesion.save(jugador);
            }
            p.getJugadores().clear();
            pp.getJugadores().clear();
            
            sesion.save(pp);

            
            
            ArrayList<String> idJugadoresPartida = new ArrayList<String>();
            for (String s : idsjugadores){
                if (!s.equals("")) {
                    
                    pp.setUnJugador(getJugadorById(s));
                    
                    idJugadoresPartida.add(s);
                    
                    //Ponemos la partida
                    Jugador jugador = sesion.get(Jugador.class, s);
                    getJugadorById(s).setpartidaEnJugador(p);
                    jugador.setpartidaEnJugador(p);
                    sesion.save(jugador);
                }
            }
            p.setJugadores(pp.getJugadores());

            sesion.save(pp);
            sesion.getTransaction().commit();
            sesion.close();
            
            
        };
        
        return mensaje;
    }
    
    /**
     * @brief Modifica un jugador en la base de datos
     * @param Jugador j
     * @param String NickName
     * @param int nivel
     * @param String [] idsInventariosJugador
     * @pre que este el objeto en la base de datos
     * @post se modificara el objeto y la instancia en la base de datos
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String ModificarJugador (String IdJugador, String NickName, int nivel, String [] idsInventariosJugador) throws Exception{
        
        Jugador j = getJugadorById(IdJugador);

        String mensaje="VALIDO";
        
        
        //Filtro1
        if (StringDuplicado(idsInventariosJugador)){
            mensaje = "Hay inventarios duplicados";
        }
        //Filtro2
        else if (!ExistenInventarios(idsInventariosJugador)){
            mensaje = "Algun inventario no existe";
        }


        /////////////////////////
        //Pasa todos los filtros
          
        else{
            
            
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            Jugador jud = getJugadorById(j.getIdPlayer());

 
            
            jud.setNickName(NickName);
            jud.setNivel(nivel);
            
            ArrayList<String> idJugadoresInventarios;

            //Quitamos el acceso de sus inventarios antiguos
            for (InventarioCompartido in : jud.getInventarios()){
                
                idJugadoresInventarios = new ArrayList<String>();
                InventarioCompartido inv = getInventarioById(in.getIdInventario());
                inv.removerAcceso(jud.getIdPlayer());
                sesion.merge(inv);

                
            }


            //Introducimos sus nuevos inventarios
            jud.getInventarios().clear();
            
            
            
            if (!idsInventariosJugador[0].trim().equals("")){
                for (String idI : idsInventariosJugador){
                    
                    
                    jud.setInventarioConAcceso(getInventarioById(idI));
                    
                    
                    InventarioCompartido inve = getInventarioById(idI);
                    
                    inve.setJugadorConAcceso(jud);
                    sesion.merge(inve);
                    
                    
                }
            }
            sesion.merge(jud);
            sesion.getTransaction().commit();
            sesion.close();
        
        
        
        }
        
        return mensaje;
    }
    
    
    /**
     * @brief Modifica un inventario en la base de datos
     * @param InventarioCompartido inv
     * @param int slotsMaximos
     * @param int slotsOcupados
     * @param String[] idsJugadorInventarios
     * @pre que este el objeto en la base de datos
     * @post se modificara el objeto y la instancia en la base de datos
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String ModificarInventario (String IdInventario, int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios) throws Exception{
        
        InventarioCompartido inv = getInventarioById(IdInventario);

        String mensaje="VALIDO";
        
        
        //Filtro1
        if (StringDuplicado(idsJugadorInventarios)){
            mensaje = "Hay jugadores duplicados";
        }
        //Filtro2
        else if (!ExistenJugadores(idsJugadorInventarios)){
            mensaje = "Algun jugador no existe";
        }


        /////////////////////////
        //Pasa todos los filtros
          
        else{
            
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            InventarioCompartido inve = getInventarioById(inv.getIdInventario());

 
            
            inve.setSlotsMaximos(slotsMaximos);
            inve.setSlotsOcupados(slotsOcupados);
            
            ArrayList<String> idInventariosJugadores;

            //Quitamos el acceso de sus inventarios antiguos
            for (Jugador ju : inve.getJugadores()){
                
                idInventariosJugadores = new ArrayList<String>();

                Jugador jug = getJugadorById(ju.getIdPlayer());
                jug.removerInventario(inve.getIdInventario());
                
                sesion.merge(jug);
                
            }


            
            inve.getJugadores().clear();
            
            
            
            if (!idsJugadorInventarios[0].trim().equals("")){
                for (String idJ : idsJugadorInventarios){
                    
                    
                    inve.setJugadorConAcceso(getJugadorById(idJ));
                    
                    
                    Jugador jug = getJugadorById(idJ);
                    
                    
                    jug.setInventarioConAcceso(inve);
                    
                    sesion.merge(jug);
                    
                }
            }
            sesion.merge(inve);
            sesion.getTransaction().commit();
            sesion.close();
        
        
        
        }
        
        return mensaje;

    }
    /*////////////////////////////////////////////////////////
    /////////////////////    Eliminar    ////////////////////
    //////////////////////////////////////////////////////*/
    /**
     * @brief Eliminara un servidor de la base de datos
     * @param String id 
     * @pre debe de existir el servidor en la base de datos
     * @post se eliminara el servidor
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String EliminarServidor (String idServer) throws Exception{
        String mensaje="VALIDO";
        if (EstaUsadoServidor(idServer)){
            mensaje = "El servidor esta siendo utilizado";
        }
        else{
            
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            Servidor s = sesion.get(Servidor.class, idServer);
            
            
            sesion.delete(s);
            sesion.getTransaction().commit();
            sesion.close();
        }
        
        return mensaje;
    }
    
    
    /**
     * @brief Eliminara una partida de la base de datos
     * @param Partida p
     * @pre debe de existir la partida en la base de datos
     * @post se eliminara la partida
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public void EliminarPartida (Partida p) throws Exception{
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        
        Partida pp = sesion.get(Partida.class, p.getIdPartida());
        
        //Quitamos el server ya que si no lo eliminaria tambien de la bd y en nuestro contexto se mantiene en la bd
        p.setServerPartida(null);
        pp.setServerPartida(null);
        
        //Quitamos los jugadores
        
        for (Jugador j : p.getJugadores()){
            Jugador jugador = sesion.get(Jugador.class, j.getIdPlayer());
            j.setpartidaEnJugador(null);
            jugador.setpartidaEnJugador(null);
            sesion.save(jugador);
        }
        
        
        
        sesion.save(pp);
        
        
        
        //eliminamos la partida
        sesion.delete(pp);
        
        sesion.getTransaction().commit();
        sesion.close();
    }
    
    
    
    /**
     * @brief Eliminara un jugador de la base de datos
     * @param Jugador j
     * @pre debe de existir la partida en la base de datos, el jugador debe de no estar en una partida
     * @post se eliminara el jugador
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String EliminarJugador (String idJugador) throws Exception{
        
        
        Jugador j = getJugadorById(idJugador);
        String mensaje = "VALIDO";
        
        
        if (EstaUsadoJugador(idJugador)){
            mensaje = "No se puede eliminar el jugador, esta en una partida";

        }
        
        /////////////////////////
        //Pasa todos los filtros
        
        else{
            
            
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();

            //Jugador jug = sesion.get(Jugador.class, idJugador);
            Jugador jug = getJugadorById(idJugador);///
            
            for (InventarioCompartido ic : jug.getInventarios()){
                getInventarioById(ic.getIdInventario()).removerAcceso(idJugador);
                
            }
            
            sesion.delete(jug);
            sesion.getTransaction().commit();
            sesion.close();
            
        }
        
        return mensaje;
        
    }
    
    
    /**
     * @brief Eliminara un inventario de la base de datos
     * @param InventarioCompartido i
     * @pre debe de existir el inventario en la base de datos, debe de no tener jugadores con acceso
     * @post se eliminara el inventario
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String EliminarInventario (String IdInventario) throws Exception{
        InventarioCompartido i = getInventarioById(IdInventario);
        String mensaje = "VALIDO";
        
        
        if (i.getJugadores().size()!=0){
            mensaje = "No se puede eliminar el inventario, tiene jugadores con acceso";
        }
        
        /////////////////////////
        //Pasa todos los filtros
        
        else{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            //InventarioCompartido inv = sesion.get(InventarioCompartido.class, IdInventario);
            InventarioCompartido inv = getInventarioById(IdInventario);
            
            for (Jugador jug : inv.getJugadores()){
                getJugadorById(jug.getIdPlayer()).removerInventario(IdInventario);
            }
            sesion.delete(inv);
            sesion.getTransaction().commit();
            sesion.close();
        }
        
        return mensaje;
    }
    
    
    /*////////////////////////////////////////////////////////
    //////////////////////    Cargas    /////////////////////
    //////////////////////////////////////////////////////*/
    
    
     /**
     * @brief Carga en el vector de la conexion los datos de la base de datos
     * @pre debe de haber una conexion abierta
     * @post se actualizara el vector de la conexion 
     */
    public void CargarServidores () throws Exception{
            
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Servidor");
        this.servidores_conexion = (ArrayList<Servidor>) query.list();
        
        

        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        //Actualizamos la id
        for (int i=0; i<this.servidores_conexion.size(); i++){
            if ((Integer.parseInt(servidores_conexion.get(i).getIdServer().substring(2)))>servidores_conexion.get(i).getGenerar()){
                servidores_conexion.get(i).setGenerar((Integer.parseInt(servidores_conexion.get(i).getIdServer().substring(2))));
            }
        }
        
    }

     /**
     * @brief Carga en el vector de la conexion los datos de la base de datos
     * @pre debe de haber una conexion abierta
     * @post se actualizara el vector de la conexion 
     */
    public void CargarInventarios () throws Exception{
        
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM InventarioCompartido");
        this.inventarios_conexion = (ArrayList<InventarioCompartido>) query.list();
        
        

        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        //Actualizamos la id
        for (int i=0; i<this.inventarios_conexion.size(); i++){
            if ((Integer.parseInt(inventarios_conexion.get(i).getIdInventario().substring(2)))>inventarios_conexion.get(i).getGenerar()){
                inventarios_conexion.get(i).setGenerar((Integer.parseInt(inventarios_conexion.get(i).getIdInventario().substring(2))));
            }
        }
    }
    
     /**
     * @brief Carga en el vector de la conexion los datos de la base de datos
     * @pre debe de haber una conexion abierta
     * @post se actualizara el vector de la conexion 
     */
    public void CargarJugadores () throws Exception{
        
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Jugador");
        this.jugadores_conexion = (ArrayList<Jugador>) query.list();
        
        

        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        //Actualizamos la id
        for (int i=0; i<this.jugadores_conexion.size(); i++){
            if ((Integer.parseInt(jugadores_conexion.get(i).getIdPlayer().substring(2)))>jugadores_conexion.get(i).getGenerar()){
                jugadores_conexion.get(i).setGenerar((Integer.parseInt(jugadores_conexion.get(i).getIdPlayer().substring(2))));
            }
        }
        
    }
    

    
     /**
     * @brief Carga en el vector de la conexion los datos de la base de datos
     * @pre debe de haber una conexion abierta
     * @pre debe de haberse cargado previamente los servidores y los jugadores
     * @post se actualizara el vector de la conexion 
     */
    public void CargarPartidas () throws Exception{
        
           
        // Cojo la sesion de usuario
        Session session = HibernateUtil.getCurrentSession();
        
        // Comienzo transaccion
        session.beginTransaction();

        Query query = session.createQuery("FROM Partida");
        this.partidas_conexion = (ArrayList<Partida>) query.list();
        
        

        // Termino transaccion guardando los cambios
        session.getTransaction().commit();
        
        //Actualizamos la id
        for (int i=0; i<this.partidas_conexion.size(); i++){
            if ((Integer.parseInt(partidas_conexion.get(i).getIdPartida().substring(2)))>partidas_conexion.get(i).getGenerar()){
                partidas_conexion.get(i).setGenerar((Integer.parseInt(partidas_conexion.get(i).getIdPartida().substring(2))));
            }
        }
    }
    
    /*////////////////////////////////////////////////////////
    //////////////////////    Get's    //////////////////////
    //////////////////////////////////////////////////////*/
    /**
     * @brief Obtiene una partida del vector de la conexion
     * @param String id
     * @pre debe de existir la partida
     * @return Partida
     */
    public Partida getPartidaById (String id){
        
        Boolean encontrado=false;
        int i=0;
        for (i=0; i<partidas_conexion.size() && encontrado==false; i++){
            if (partidas_conexion.get(i).getIdPartida().equals(id)){
                encontrado=true;
            }
        }
        return partidas_conexion.get(i-1);
    }
    
     /**
     * @brief Obtiene un inventario del vector de la conexion
     * @param String id
     * @pre debe de existir el inventario
     * @return InventarioCompartido
     */
    public InventarioCompartido getInventarioById (String id){
        
        Boolean encontrado=false;
        int i=0;
        for (i=0; i<inventarios_conexion.size() && encontrado==false; i++){
            if (inventarios_conexion.get(i).getIdInventario().equals(id)){
                encontrado=true;
            }
        }
        return inventarios_conexion.get(i-1);
    }
    
     /**
     * @brief Obtiene un jugador del vector de la conexion
     * @param String id
     * @pre debe de existir el jugador
     * @return Jugador
     */
    public Jugador getJugadorById (String id){
        
        Boolean encontrado=false;
        int i=0;
        for (i=0; i<jugadores_conexion.size() && encontrado==false; i++){
            if (jugadores_conexion.get(i).getIdPlayer().equals(id)){
                encontrado=true;
            }
        }
        return jugadores_conexion.get(i-1);
    }
    
    /**
     * @brief Obtiene un jugador del vector de la conexion
     * @param String id
     * @pre debe de existir el servidor
     * @return Servidor
     */
    public Servidor getServidorById (String id){
        
        Boolean encontrado=false;
        int i=0;
        for (i=0; i<servidores_conexion.size() && encontrado==false; i++){
            if (servidores_conexion.get(i).getIdServer().equals(id)){
                encontrado=true;
            }
        }
        return servidores_conexion.get(i-1);
    }
    
      
     /**
     * @brief retorna el vector de la conexion
     * @return ArrayList<Servidor>
     */
    public ArrayList<Servidor> getServidores (){
        return servidores_conexion;
    }
    
     /**
     * @brief retorna el vector de la conexion
     * @return ArrayList<InventarioCompartido>
     */
    public ArrayList<InventarioCompartido> getInventarios (){
        return inventarios_conexion;
    }
        
     /**
     * @brief retorna el vector de la conexion
     * @return ArrayList<Jugador>
     */
    public ArrayList<Jugador> getJugadores (){
        return jugadores_conexion;
    }
    
     /**
     * @brief retorna el vector de la conexion
     * @return ArrayList<Partida>
     */
    public ArrayList<Partida> getPartidas (){
        return partidas_conexion;
    }
    
    /**
     * @brief obtiene un servidor de la base de datos 
     * @param String id
     * @return Servidor s
     */
    public Servidor getServidor_BD_ByID (String idS) throws Exception{
        Servidor s = null;
        
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        
        s = sesion.get(Servidor.class, idS);
        
        sesion.getTransaction().commit();
        sesion.close();
        
        return s;
        
    }
    
    /**
     * @brief obtiene un inventario de la base de datos 
     * @param String id
     * @return InventarioCompartido inv
     */
    public InventarioCompartido getInventario_BD_ByID (String id) throws Exception{
        InventarioCompartido inv = null;
        
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        
        inv = sesion.get(InventarioCompartido.class, id);
        
        sesion.getTransaction().commit();
        sesion.close();
        
        return inv;
    }
    
    /**
     * @brief obtiene una partida parcial de la base de datos 
     * @param String id
     * @return Partida p
     */
    public Partida getPartida_BD_ByID (String id) throws Exception{
        Partida p = null;
        
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        
        p = sesion.get(Partida.class, id);
        
        sesion.getTransaction().commit();
        sesion.close();
        
        return p;
    }
    
    /**
     * @brief obtiene un jugador parcial de la base de datos 
     * @param String id
     * @return Jugador j
     */
    public Jugador getJugador_BD_ByID (String id) throws Exception{
        Jugador jug = null;
        
        Session sesion = HibernateUtil.getCurrentSession();
        sesion.beginTransaction();
        
        jug = sesion.get(Jugador.class, id);
        
        sesion.getTransaction().commit();
        sesion.close();
        
        return jug;
    }
    
    /*////////////////////////////////////////////////////////
    /////////////////////    Metodos    /////////////////////
    //////////////////////////////////////////////////////*/
    
    public Boolean EstaUsadoServidor (String id){
        Boolean usado=false;
        
        for (int i=0; i<partidas_conexion.size() && usado==false; i++){
            
            if (partidas_conexion.get(i).getServerPartida().getIdServer().equals(id)){
                usado=true;
            }
        }
        
        return usado;
    }
    public Boolean ExisteServidor (String id){
        Boolean existe=false;
        
        for (Servidor s : servidores_conexion){
            if (s.getIdServer().equals(id)){
                existe=true;
            }
        }
        
        return existe;
    }
    public Boolean StringDuplicado (String[] ids){
        Boolean duplicidad = false;
        for (int i=0; i<ids.length; i++){
            for (int j=i+1; j<ids.length; j++){
                if (ids[i].equals(ids[j])){
                    duplicidad = true;
                }
            }
        }
        return duplicidad;
    }
    public Boolean ExisteJugador (String idJugador){
        Boolean existe = false;
        for (Jugador j : jugadores_conexion){
            if (j.getIdPlayer().equals(idJugador)){
                existe=true;
            }
        }
        return existe;
    }
    public Boolean ExistenJugadores (String[] idsjugadores){
        Boolean existe = true;
        
        for (int i=0; i < idsjugadores.length && existe==true; i++){
            
            if (!ExisteJugador(idsjugadores[i])){
                existe=false;
                
            }
            
        }
        if (idsjugadores.length==1){
            if (idsjugadores[0].trim().equals("")){
                existe=true;
            }
        }
        return existe;
    }
    public Boolean EstaUsadoJugador (String id){
        Boolean usado = false;
        for (Partida p : partidas_conexion){
            for (Jugador j : p.getJugadores()){
                if (j.getIdPlayer().equals(id)){
                    usado=true;
                }
            }
        }
        return usado;
    }
    
            
    public Boolean EstaUsadoAlgunJugador (String[] idsjugadores){
        Boolean usado=false;
        for (int i=0; i < idsjugadores.length && usado==false; i++){
            if (EstaUsadoJugador(idsjugadores[i])){
                usado = true;
            }
        }
        return usado;
    }
    public Boolean EstaUsadoAlgunJugador (String[] idsjugadores, List<Jugador> jugadoresUsadosActuales){
        Boolean usado=false;
        Boolean usadoPorEl=false;
        for (int i=0; i < idsjugadores.length && usado==false; i++){
            if (EstaUsadoJugador(idsjugadores[i])){
                
                usado = true;
                usadoPorEl=false;
                
                //Puede estar usado por el esto esta para tener en cuenta el modificar
                for (Jugador jug : jugadoresUsadosActuales){
                    if (jug.getIdPlayer().equals(idsjugadores[i])){
                        usadoPorEl=true;
                    }
                }
                
                if (usadoPorEl){
                    usado=false;
                }
            }
        }
        return usado;
    }
    
    public Boolean ExisteInventario (String idInventario){
        Boolean existe = false;
        for (InventarioCompartido i : inventarios_conexion){
            if (i.getIdInventario().equals(idInventario)){
                existe=true;
            }
        }
        return existe;
    }
    public Boolean ExistenInventarios (String[] idsInventarios){
        Boolean existe = true;
        
        for (int i=0; i < idsInventarios.length && existe==true; i++){
            
            if (!ExisteInventario(idsInventarios[i])){
                existe=false;
                
            }
            
        }
        if (idsInventarios.length==1){
            if (idsInventarios[0].trim().equals("")){
                existe=true;
            }
        }
        return existe;
    }
    
}



