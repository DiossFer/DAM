package com.mycompany.proyecto_ad_mongodb.conexion;

import com.mycompany.proyecto_ad_mongodb.modelos.Jugador;
import com.mycompany.proyecto_ad_mongodb.modelos.Partida;
import com.mycompany.proyecto_ad_mongodb.modelos.Servidor;
import com.mycompany.proyecto_ad_mongodb.modelos.InventarioCompartido;
import java.util.ArrayList;


import com.mongodb.*;
import org.bson.BsonDocument;
import org.bson.BsonInt64;
import org.bson.Document;
import org.bson.conversions.Bson;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.FindIterable;
import com.mongodb.client.MongoCursor;
import static com.mongodb.client.model.Filters.eq;
import static com.mongodb.client.model.Updates.set;
import java.util.List;

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
    
    MongoClient mongoClient;
    MongoDatabase database;
    
    MongoCollection<Document> coleccionServidores;
    MongoCollection<Document> coleccionJugadores;
    MongoCollection<Document> coleccionPartidas;
    MongoCollection<Document> coleccionInventarios;
            
    /*////////////////////////////////////////////////////////
    ////////////////////    Costructor    ///////////////////
    //////////////////////////////////////////////////////*/
    
    public Conexion (String NewdbName) throws MongoException{
        
        this.dbName=NewdbName;
        
        mongoClient = null;
        database = null;
                
        this.getConection();
        
        servidores_conexion = new ArrayList<Servidor>();
        inventarios_conexion = new ArrayList<InventarioCompartido>();
        jugadores_conexion = new ArrayList<Jugador>();
        partidas_conexion = new ArrayList<Partida>();
        
        auxIdInv = new ArrayList<ArrayList<String>>();
        
        
        CargarServidores();
        CargarInventariosParcial();
        CargarJugadores();
        CargarInventariosFinal();
        CargarPartidas();

    }

    
    /*////////////////////////////////////////////////////////
    ///////////////////    getConection    //////////////////
    //////////////////////////////////////////////////////*/
    
     /**
     * @brief Abre una conexion en caso de no estar ya abierta una
     * @pre 
     * @post 
     * @param 
     */
    public MongoClient getConection () throws MongoException{
        
        if (mongoClient==null){
            this.abrirConexion();
        }
        
        return mongoClient;
    }
    
    /*////////////////////////////////////////////////////////
    ///////////////////    abrir-cerrar    //////////////////
    //////////////////////////////////////////////////////*/
    

    /**
     * @brief Abre una conexion en la base de datos
     * @pre no debe de haber una conexion abierta ya
     * @post se abrira una conexion 
     * @param 
     */
    private void abrirConexion () throws MongoException{
        
        // Conexion Mongo
        // ABRIR CONEXION
        
        // Replace the placeholder with your MongoDB connection string
        String uri = "mongodb://localhost:27017";
        
        // Construct a ServerApi instance using the ServerApi.builder() method
        ServerApi serverApi = ServerApi.builder()
                .version(ServerApiVersion.V1)
                .build();
        
        MongoClientSettings settings = MongoClientSettings.builder()
                .applyConnectionString(new ConnectionString(uri))
                .serverApi(serverApi)
                .build();
        
        // Create a new client and connect to the server
        // Primeroe me conecto con el mongoClient y luego abro la base de datos
        try {
            mongoClient = MongoClients.create(settings);
            database = mongoClient.getDatabase(dbName);
            try {
                // Send a ping to confirm a successful connection
                Bson command = new BsonDocument("ping", new BsonInt64(1));
                Document commandResult = database.runCommand(command);
                //System.out.println("Pinged your deployment. You successfully connected to MongoDB!");
                //System.out.println("ABIERTA");
            } catch (MongoException me) {
                //System.err.println(me);
                //System.out.println("FALLO");
                throw me;
            }
        }
        catch (MongoException me) {
            throw me;
        }
    }
    
    
    /**
     * @brief Cierra la consexion de la base de datos
     * @pre debe de haber una conexion abierta
     * @post se cerrara la conexion
     * @param 
     */
    public void cerrarConexion () throws MongoException{
        
        try {
            mongoClient.close();
            //System.out.println("Conexion cerrada correctamente"); 
        }
        catch (MongoException me) {
            throw me;
        }
        
        
    }
    
    
    /*////////////////////////////////////////////////////////
    /////////////////////    Insertar    ////////////////////
    //////////////////////////////////////////////////////*/
    
    /**
     * @brief Inserta un servidor en la base de datos y actualiza su id en el sistema
     * @param Servidor s
     * @post se actualizara la id y se añadira a la base de datos
     */
    public void InsertarServidor (Servidor s) throws MongoException{


        // Cojo la coleccion de servidores para realizar operaciones sobre ella
        coleccionServidores = database.getCollection("servidores");

        // INSERCION

        // Creo un nuevo servidor
        Document nuevoServidor = new Document("id", s.getIdServer())
                .append("region", s.getRegion());

        // Inserto el servidor en la coleccion
        coleccionServidores.insertOne(nuevoServidor);
    
    }
    
    /**
     * @brief Inserta una partida en la base de datos y actualiza su id en el sistema
     * @param Partida p
     * @post se creara la partida en la bd y en el sistema
     * @return mensaje --> VALIDO si se ha hecho todo correcto / un mensaje de error si ha habido algun fallo
     */
    public String InsertarPartida (int numEspectadores, String IdServerPartida, String[] idsjugadores) throws MongoException{
        
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
            //Creo la partida
            Partida p = new Partida(numEspectadores, getServidorById(IdServerPartida));
            if (!idsjugadores[0].trim().equals("")){
                for (String idj : idsjugadores){
                    p.setUnJugador(getJugadorById(idj));
                }
            }
            
            
            // Cojo la coleccion de partidas para realizar operaciones sobre ella
            coleccionPartidas = database.getCollection("partidas");

            // INSERCION
            ArrayList<String> idJugadoresPartida = new ArrayList<String>();
            for (Jugador j : p.getJugadores()){
                idJugadoresPartida.add(j.getIdPlayer());
            }

            // Creo una nueva partida
            Document nuevaPartida = new Document("id", p.getIdPartida())
                    .append("numEspectadores", p.getNumEspectadores())
                    .append("servidorPartida", p.getServerPartida().getIdServer())
                    .append("jugadoresPartida", idJugadoresPartida);

            // Inserto la partida en la coleccion
            coleccionPartidas.insertOne(nuevaPartida);
            
            //Insertamos en el sistema
            partidas_conexion.add(p);
        }
        return mensaje;
    }
    
    /**
     * @brief Inserta un jugador en la base de datos y actualiza su id en el sistema, ademas de insertar su relacion
     * @param Jugador j
     * @post se actualizara la id y se añadira a la base de datos
     */
    public String InsertarJugador (String NickName, int nivel, String[] idsInventariosJugador) throws MongoException{
        

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



            // Cojo la coleccion de jugadores para realizar operaciones sobre ella
            coleccionJugadores = database.getCollection("jugadores");

            // INSERCION
            ArrayList<String> idInventariosConAcceso = new ArrayList<String>();
            for (InventarioCompartido i : j.getInventarios()){
                idInventariosConAcceso.add(i.getIdInventario());
            }

            // Creo un nuevo jugador
            Document nuevoJugador = new Document("id", j.getIdPlayer())
                    .append("nickName", j.getNickName())
                    .append("nivel", j.getNivel())
                    .append("inventariosConAcceso", idInventariosConAcceso);



            // Inserto el jugador en la coleccion
            coleccionJugadores.insertOne(nuevoJugador);

            ArrayList<String> ArrayAux;

            //Lo introduzco en los inventarios correspondientes
            for (InventarioCompartido inv : j.getInventarios()){
                ArrayAux = new ArrayList<String>();


                for (Jugador Jsinv : inv.getJugadores()){
                    ArrayAux.add(Jsinv.getIdPlayer());
                }

                coleccionInventarios = database.getCollection("inventarios");
                coleccionInventarios.updateOne(eq("id", inv.getIdInventario()), set("jugadoresConAcceso", ArrayAux));
            }
        }
        
        return mensaje;
    }
    
    /**
     * @brief Inserta un inventario en la base de datos y actualiza su id en el sistema, ademas de insertar su relacion
     * @param InventarioCompartido i
     * @post se actualizara la id y se añadira a la base de datos
     */
    public String InsertarInventario (int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios) throws MongoException{
        

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

            // Cojo la coleccion de inventarios para realizar operaciones sobre ella
            coleccionInventarios = database.getCollection("inventarios");

            // INSERCION
            ArrayList<String> idJugadoresConAcceso = new ArrayList<String>();
            for (Jugador j : i.getJugadores()){
                idJugadoresConAcceso.add(j.getIdPlayer());
            }

            // Creo un nuevo inventario
            Document nuevoInventario = new Document("id", i.getIdInventario())
                    .append("slotsMaximos", i.getSlotsMaximos())
                    .append("slotsOcupados", i.getSlotsOcupados())
                    .append("jugadoresConAcceso", idJugadoresConAcceso);

            // Inserto el inventario en la coleccion
            coleccionInventarios.insertOne(nuevoInventario);

            ArrayList<String> ArrayAux;

            //Lo introduzco en los jugadores correspondientes
            for (Jugador j : i.getJugadores()){
                ArrayAux = new ArrayList<String>();


                for (InventarioCompartido Isjug : j.getInventarios()){
                    ArrayAux.add(Isjug.getIdInventario());
                }

                coleccionJugadores = database.getCollection("jugadores");
                coleccionJugadores.updateOne(eq("id", j.getIdPlayer()), set("inventariosConAcceso", ArrayAux));
            }
            
            
                
                
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
     */
    public void ModificarServidor (Servidor s, String region) throws MongoException{
        // Cojo la coleccion de servidores para realizar operaciones sobre ella
        coleccionServidores = database.getCollection("servidores");

        // MODIFICACION

        //actualizo los datos del servidor
        coleccionServidores.updateOne(eq("id", s.getIdServer()), set("region", region));

        //actualizo los datos del objeto
        s.setRegion(region);
    }
    
    
    /**
     * @brief Modifica una partida en la base de datos
     * @param Partida p 
     * @param int numEspectadores
     * @param String id_server
     * @param String[] idsjugadores
     * @pre que este el objeto en la base de datos
     * @post se modificara el objeto y la instancia en la base de datos
     */
    public String ModificarPartida (String IdPartida, int numEspectadores, String id_server, String[] idsjugadores) throws MongoException{
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

            // Cojo la coleccion de partidas para realizar operaciones sobre ella
            coleccionPartidas = database.getCollection("partidas");

            // MODIFICACION

            //actualizo los datos de la partida
            coleccionPartidas.updateOne(eq("id", p.getIdPartida()), set("numEspectadores", numEspectadores));
            p.setNumEspectadores(numEspectadores);

            coleccionPartidas.updateOne(eq("id", p.getIdPartida()), set("servidorPartida", getServidorById(id_server).getIdServer()));
            p.setServerPartida(getServidorById(id_server));

            p.getJugadores().clear();
            ArrayList<String> idJugadoresPartida = new ArrayList<String>();
            for (String s : idsjugadores){
                if (!s.equals("")) {
                    p.setUnJugador(getJugadorById(s));
                    idJugadoresPartida.add(s);
                }
            }

            coleccionPartidas.updateOne(eq("id", p.getIdPartida()), set("jugadoresPartida", idJugadoresPartida));
        }
        
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
     */
    public String ModificarJugador (String IdJugador, String NickName, int nivel, String [] idsInventariosJugador) throws MongoException{
        
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


            // Cojo la coleccion de jugadores para realizar operaciones sobre ella
            coleccionPartidas = database.getCollection("jugadores");

            // MODIFICACION

            //actualizo los datos del jugador
            coleccionPartidas.updateOne(eq("id", j.getIdPlayer()), set("nickName", NickName));
            j.setNickName(NickName);

            coleccionPartidas.updateOne(eq("id", j.getIdPlayer()), set("nivel", nivel));
            j.setNivel(nivel);

            ArrayList<String> idJugadoresInventarios;

            //Quitamos el acceso de sus inventarios antiguos
            for (InventarioCompartido inv : j.getInventarios()){
                coleccionInventarios = database.getCollection("inventarios");
                idJugadoresInventarios = new ArrayList<String>();

                inv.removerAcceso(j.getIdPlayer());

                for (Jugador jug : inv.getJugadores()){
                    idJugadoresInventarios.add(jug.getIdPlayer());
                }

                coleccionInventarios.updateOne(eq("id", inv.getIdInventario()), set("jugadoresConAcceso", idJugadoresInventarios));


            }


            //Introducimos sus nuevos inventarios
            j.getInventarios().clear();
            ArrayList<String> idInventariosJugador = new ArrayList<String>();

            for (String s : idsInventariosJugador){
                if (!s.equals("")) {
                    // Meter en el jugador
                    j.setInventarioConAcceso(getInventarioById(s));

                    // Meter en el auxiliar para la bd
                    idInventariosJugador.add(s);

                    // Meter en el inventario
                    getInventarioById(s).setJugadorConAcceso(j);

                    // Meter en el inventario bd
                    ArrayList <String> strAuxJugInv = new ArrayList<String>();
                    for (Jugador jaux : getInventarioById(s).getJugadores()){
                        strAuxJugInv.add(jaux.getIdPlayer());
                    }
                    coleccionInventarios.updateOne(eq("id", getInventarioById(s).getIdInventario()), set("jugadoresConAcceso", strAuxJugInv));
                }
            }


            coleccionJugadores.updateOne(eq("id", j.getIdPlayer()), set("inventariosConAcceso", idInventariosJugador));

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
     */
    public String ModificarInventario (String IdInventario, int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios) throws MongoException{
        
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



            // Cojo la coleccion de inventarios para realizar operaciones sobre ella
            coleccionInventarios = database.getCollection("inventarios");

            // MODIFICACION

            //actualizo los datos del jugador
            coleccionInventarios.updateOne(eq("id", inv.getIdInventario()), set("slotsMaximos", slotsMaximos));
            inv.setSlotsMaximos(slotsMaximos);

            coleccionInventarios.updateOne(eq("id", inv.getIdInventario()), set("slotsOcupados", slotsOcupados));
            inv.setSlotsOcupados(slotsOcupados);

            ArrayList<String> idInventariosJugadores;

            //Quitamos el acceso de sus inventarios antiguos
            for (Jugador jug : inv.getJugadores()){
                coleccionJugadores = database.getCollection("jugadores");
                idInventariosJugadores = new ArrayList<String>();

                jug.removerInventario(inv.getIdInventario());

                for (InventarioCompartido i : jug.getInventarios()){
                    idInventariosJugadores.add(i.getIdInventario());
                }

                coleccionJugadores.updateOne(eq("id", jug.getIdPlayer()), set("inventariosConAcceso", idInventariosJugadores));


            }


            //Introducimos sus nuevos inventarios
            inv.getJugadores().clear();
            ArrayList<String> idJugadoresInventario = new ArrayList<String>();

            for (String s : idsJugadorInventarios){
                if (!s.equals("")) {
                    // Meter en el inventario
                    inv.setJugadorConAcceso(getJugadorById(s));

                    // Meter en el auxiliar para la bd
                    idJugadoresInventario.add(s);

                    // Meter en el jugador
                    getJugadorById(s).setInventarioConAcceso(inv);

                    // Meter en el jugador bd
                    ArrayList <String> strAuxInvJug = new ArrayList<String>();
                    for (InventarioCompartido iaux : getJugadorById(s).getInventarios()){
                        strAuxInvJug.add(iaux.getIdInventario());
                    }
                    coleccionJugadores.updateOne(eq("id", getJugadorById(s).getIdPlayer()), set("inventariosConAcceso", strAuxInvJug));
                }
            }

            coleccionInventarios.updateOne(eq("id", inv.getIdInventario()), set("jugadoresConAcceso", idJugadoresInventario));
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
     */
    public String EliminarServidor (String idServer) throws MongoException{
        String mensaje="VALIDO";
        if (EstaUsadoServidor(idServer)){
            mensaje = "El servidor esta siendo utilizado";
        }
        else{


            // Cojo la coleccion de servidores para realizar operaciones sobre ella
            coleccionServidores = database.getCollection("servidores");

            //Filtro
            Document filtro = new Document("id", idServer);

            //Eliminamos
            coleccionServidores.deleteOne(filtro);

        }
        return mensaje;
    }
    
    
    /**
     * @brief Eliminara una partida de la base de datos
     * @param Partida p
     * @pre debe de existir la partida en la base de datos
     * @post se eliminara la partida
     */
    public void EliminarPartida (Partida p) throws MongoException{
        // Cojo la coleccion de partidas para realizar operaciones sobre ella
        coleccionPartidas = database.getCollection("partidas");

        //Filtro
        Document filtro = new Document("id", p.getIdPartida());
        
        //Eliminamos
        coleccionPartidas.deleteOne(filtro);
    }
    
    
    
    /**
     * @brief Eliminara un jugador de la base de datos
     * @param Jugador j
     * @pre debe de existir la partida en la base de datos, el jugador debe de no estar en una partida
     * @post se eliminara el jugador
     */
    public String EliminarJugador (String idJugador) throws MongoException{
        
        
        Jugador j = getJugadorById(idJugador);
        String mensaje = "VALIDO";
        
        
        if (EstaUsadoJugador(idJugador)){
            mensaje = "No se puede eliminar el jugador, esta en una partida";

        }
        
        /////////////////////////
        //Pasa todos los filtros
        
        else{
            

            // Cojo la coleccion de jugadores para realizar operaciones sobre ella
            coleccionJugadores = database.getCollection("jugadores");

            //Filtro
            Document filtro = new Document("id", j.getIdPlayer());

            //Eliminamos
            coleccionJugadores.deleteOne(filtro);

            ArrayList<String> ArrayAux;

            for (InventarioCompartido inv : j.getInventarios()){
                ArrayAux = new ArrayList<String>();

                inv.removerAcceso(j.getIdPlayer());

                for (Jugador Jsinv : inv.getJugadores()){
                    ArrayAux.add(Jsinv.getIdPlayer());
                }

                coleccionInventarios = database.getCollection("inventarios");
                coleccionInventarios.updateOne(eq("id", inv.getIdInventario()), set("jugadoresConAcceso", ArrayAux));
            }
        }
        return mensaje;
        
    }
    
    
    /**
     * @brief Eliminara un inventario de la base de datos
     * @param InventarioCompartido i
     * @pre debe de existir el inventario en la base de datos, debe de no tener jugadores con acceso
     * @post se eliminara el inventario
     */
    public String EliminarInventario (String IdInventario) throws MongoException{
        InventarioCompartido i = getInventarioById(IdInventario);
        String mensaje = "VALIDO";
        
        
        if (i.getJugadores().size()!=0){
            mensaje = "No se puede eliminar el inventario, tiene jugadores con acceso";

        }
        
        /////////////////////////
        //Pasa todos los filtros
        
        else{
            // Cojo la coleccion de inventarios para realizar operaciones sobre ella
            coleccionInventarios = database.getCollection("inventarios");

            //Filtro
            Document filtro = new Document("id", i.getIdInventario());

            //Eliminamos
            coleccionInventarios.deleteOne(filtro);
            
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
    public void CargarServidores () throws MongoException{
            Servidor s;
            
            // Cojo la coleccion de servidores para realizar operaciones sobre ella
            coleccionServidores = database.getCollection("servidores");
            
            // Cojo todos los documentos de la coleccion servidores
            FindIterable<Document> documentos = coleccionServidores.find();
            
            // Creo un cursor para moverme entre esos documentos
            MongoCursor<Document> cursor = documentos.iterator();
            
            // Leo todos los documentos mientras haya mas e introduzco al vector
            while(cursor.hasNext()){
                Document documentito = cursor.next();
                s = new Servidor (documentito.getString("id"), documentito.getString("region"));
                servidores_conexion.add(s);
            }
        
    }

     /**
     * @brief Carga en el vector de la conexion los datos de la base de datos, tambien se usara un vector inical para guardar las id de los jugadores pes no se pueden referenciar ya que aun no se han cargado
     * @pre debe de haber una conexion abierta
     * @post se actualizara el vector de la conexion 
     */
    public void CargarInventariosParcial () throws MongoException{
        InventarioCompartido inv;
        List<String> auxArray;
        
            // Cojo la coleccion de inventarios para realizar operaciones sobre ella
            coleccionInventarios = database.getCollection("inventarios");
            
            // Cojo todos los documentos de la coleccion inventarios
            FindIterable<Document> documentos = coleccionInventarios.find();
            
            // Creo un cursor para moverme entre esos documentos
            MongoCursor<Document> cursor = documentos.iterator();
            
            // Leo todos los documentos mientras haya mas e introduzco al vector
            int i=0;
            while(cursor.hasNext()){
                
                Document documentito = cursor.next();
                inv = new InventarioCompartido (documentito.getString("id"), documentito.getInteger("slotsMaximos"), documentito.getInteger("slotsOcupados"));
                
                auxArray = documentito.getList("jugadoresConAcceso", String.class);
                if (auxArray == null){
                    auxArray = new ArrayList<String>();
                }
                
                //Introduzco las Ids de los jugadores del inventario en el vector auxiliar para su posterior carga tras la carga de los jugadores
                auxIdInv.add(new ArrayList<String>());
                for (int j=0; j < auxArray.size(); j++){
                    auxIdInv.get(i).add(auxArray.get(j));
                }
                
                i++;
                
                inventarios_conexion.add(inv);
            }
    }
    
     /**
     * @brief Carga en el vector de la conexion los datos de la base de datos
     * @pre debe de haber una conexion abierta
     * @post se actualizara el vector de la conexion 
     */
    public void CargarJugadores () throws MongoException{
        Jugador jug;
        List<String> auxArray;

            // Cojo la coleccion de jugadores para realizar operaciones sobre ella
            coleccionJugadores = database.getCollection("jugadores");
            
            // Cojo todos los documentos de la coleccion jugadores
            FindIterable<Document> documentos = coleccionJugadores.find();
            
            // Creo un cursor para moverme entre esos documentos
            MongoCursor<Document> cursor = documentos.iterator();
            
            // Leo todos los documentos mientras haya mas e introduzco al vector
            while(cursor.hasNext()){
                
                Document documentito = cursor.next();
                jug = new Jugador (documentito.getString("id"), documentito.getString("nickName"), documentito.getInteger("nivel"));
                
                auxArray = documentito.getList("inventariosConAcceso", String.class);
                if (auxArray == null){
                    auxArray = new ArrayList<String>();
                }
                for (int i=0; i < auxArray.size(); i++){
                    jug.setInventarioConAcceso(getInventarioById(auxArray.get(i)));
                }
                
                
                jugadores_conexion.add(jug);
            }
            
    }
    
     /**
     * @brief Modulo para partiendo del vector auxiliar de la carga parcial de inventtarios se terminen de cargar las dependencias de los inventarios
     * @pre debe de haber una conexion abierta
     * @pre debe de haberse cargado previamente los jugadores e inventariosParciales
     * @post se actualizara los vectores de la conexion 
     */
    public void CargarInventariosFinal () throws MongoException{
        //Enlazo el vector auxiliar de Ids de inventarios con los jugadores e inventarios parciales ya cargados
        for (int i=0; i < inventarios_conexion.size(); i++){
            for (int j=0; j<auxIdInv.get(i).size(); j++){
                inventarios_conexion.get(i).setJugadorConAcceso(getJugadorById(auxIdInv.get(i).get(j)));
            }
        }
    }
    
     /**
     * @brief Carga en el vector de la conexion los datos de la base de datos
     * @pre debe de haber una conexion abierta
     * @pre debe de haberse cargado previamente los servidores y los jugadores
     * @post se actualizara el vector de la conexion 
     */
    public void CargarPartidas () throws MongoException{
        Partida p;
        List<String> auxArray;

            // Cojo la coleccion de partidas para realizar operaciones sobre ella
            coleccionPartidas = database.getCollection("partidas");
            
            // Cojo todos los documentos de la coleccion partidas
            FindIterable<Document> documentos = coleccionPartidas.find();
            
            // Creo un cursor para moverme entre esos documentos
            MongoCursor<Document> cursor = documentos.iterator();
            
            // Leo todos los documentos mientras haya mas e introduzco al vector
            while(cursor.hasNext()){
                
                Document documentito = cursor.next();
                p = new Partida (documentito.getString("id"), documentito.getInteger("numEspectadores"), getServidorById(documentito.getString("servidorPartida")));
                
                auxArray = documentito.getList("jugadoresPartida", String.class);
                if (auxArray == null){
                    auxArray = new ArrayList<String>();
                }
                for (int i=0; i < auxArray.size(); i++){
                    p.setUnJugador(getJugadorById(auxArray.get(i)));
                }
                
                
                partidas_conexion.add(p);
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
    public Servidor getServidor_BD_ByID (String idS) throws MongoException{
        Servidor s = null;
            
        // Cojo la coleccion de servidores para realizar operaciones sobre ella
        coleccionServidores = database.getCollection("servidores");

        //Filtro
        Document filtro = new Document("id", idS);

        // Cojo todos los documentos de la coleccion servidores
        FindIterable<Document> documentos = coleccionServidores.find(filtro);

        // Creo un cursor para moverme entre esos documentos
        MongoCursor<Document> cursor = documentos.iterator();

        // Leo todos los documentos mientras haya mas e introduzco al vector
        while(cursor.hasNext()){
            Document documentito = cursor.next();
            s = new Servidor (documentito.getString("id"), documentito.getString("region"));
        }
        
        return s;

    }
    
    /**
     * @brief obtiene un inventario de la base de datos 
     * @param String id
     * @return InventarioCompartido inv
     */
    public InventarioCompartido getInventario_BD_ByID (String id) throws MongoException{
        InventarioCompartido inv = null;

        List<String> auxArray;
        
            // Cojo la coleccion de inventarios para realizar operaciones sobre ella
            coleccionInventarios = database.getCollection("inventarios");
            
            //Filtro
            Document filtro = new Document("id", id);
        
            // Cojo todos los documentos de la coleccion inventarios
            FindIterable<Document> documentos = coleccionInventarios.find(filtro);
            
            // Creo un cursor para moverme entre esos documentos
            MongoCursor<Document> cursor = documentos.iterator();
            
            // Leo todos los documentos mientras haya mas e introduzco al vector

            while(cursor.hasNext()){
                
                Document documentito = cursor.next();
                inv = new InventarioCompartido (documentito.getString("id"), documentito.getInteger("slotsMaximos"), documentito.getInteger("slotsOcupados"));
                
                auxArray = documentito.getList("jugadoresConAcceso", String.class);
                if (auxArray == null){
                    auxArray = new ArrayList<String>();
                }
                
                
                for (int j=0; j < auxArray.size(); j++){
                    inv.setJugadorConAcceso(getJugadorById(auxArray.get(j)));
                }

            }
    
        return inv;
    }
    
    /**
     * @brief obtiene una partida parcial de la base de datos 
     * @param String id
     * @return Partida p
     */
    public Partida getPartida_BD_ByID (String id) throws MongoException{
        Partida p = null;
        
        List<String> auxArray;

        
        //Filtro
        Document filtro = new Document("id", id);

        // Cojo la coleccion de partidas para realizar operaciones sobre ella
        coleccionPartidas = database.getCollection("partidas");

        // Cojo todos los documentos de la coleccion partidas
        FindIterable<Document> documentos = coleccionPartidas.find(filtro);

        // Creo un cursor para moverme entre esos documentos
        MongoCursor<Document> cursor = documentos.iterator();

        // Leo todos los documentos mientras haya mas e introduzco al vector
        while(cursor.hasNext()){

            Document documentito = cursor.next();
            p = new Partida (documentito.getString("id"), documentito.getInteger("numEspectadores"), getServidorById(documentito.getString("servidorPartida")));

            auxArray = documentito.getList("jugadoresPartida", String.class);
            if (auxArray == null){
                auxArray = new ArrayList<String>();
            }
            for (int i=0; i < auxArray.size(); i++){
                p.setUnJugador(getJugadorById(auxArray.get(i)));
            }


        }

        return p;
    }
    
    /**
     * @brief obtiene un jugador parcial de la base de datos 
     * @param String id
     * @return Jugador j
     */
    public Jugador getJugador_BD_ByID (String id) throws MongoException{
        Jugador jug = null;
        

        List<String> auxArray;
        //Filtro
        Document filtro = new Document("id", id);
        // Cojo la coleccion de jugadores para realizar operaciones sobre ella
        coleccionJugadores = database.getCollection("jugadores");

        // Cojo todos los documentos de la coleccion jugadores
        FindIterable<Document> documentos = coleccionJugadores.find(filtro);

        // Creo un cursor para moverme entre esos documentos
        MongoCursor<Document> cursor = documentos.iterator();

        // Leo todos los documentos mientras haya mas e introduzco al vector
        while(cursor.hasNext()){

            Document documentito = cursor.next();
            jug = new Jugador (documentito.getString("id"), documentito.getString("nickName"), documentito.getInteger("nivel"));

            auxArray = documentito.getList("inventariosConAcceso", String.class);
            if (auxArray == null){
                auxArray = new ArrayList<String>();
            }
            for (int i=0; i < auxArray.size(); i++){
                jug.setInventarioConAcceso(getInventarioById(auxArray.get(i)));
            }


        }

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
    public Boolean EstaUsadoAlgunJugador (String[] idsjugadores, ArrayList<Jugador> jugadoresUsadosActuales){
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



