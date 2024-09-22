package com.mycompany.proyecto_ad_hibernate.controller;

import com.mycompany.proyecto_ad_hibernate.conexion.Conexion;
import com.mycompany.proyecto_ad_hibernate.modelos.InventarioCompartido;
import com.mycompany.proyecto_ad_hibernate.modelos.Jugador;
import com.mycompany.proyecto_ad_hibernate.modelos.Partida;
import com.mycompany.proyecto_ad_hibernate.modelos.Servidor;
import java.util.ArrayList;



/**
 *
 * @author DiosFer
 */
public class Controller {

    private Conexion conn;
    
    private ArrayList<Servidor> servidores_sistema;
    private ArrayList<InventarioCompartido> inventarios_sistema;
    private ArrayList<Partida> partidas_sistema;
    private ArrayList<Jugador> jugadores_sistema;

    
     /**
     * @brief Constructor del controlador con la lectura inicial de la base de datos
     */
    public Controller (String dbName)  throws Exception {
            
            conn = new Conexion(dbName) ;
            
            servidores_sistema = conn.getServidores();
            
            inventarios_sistema = conn.getInventarios();
            
            jugadores_sistema = conn.getJugadores();

            partidas_sistema = conn.getPartidas();
            
    }
    
    public void cerrar_conexion ()  throws Exception{
        conn.cerrarConexion();
    }
    
    /*////////////////////////////////////////////////////////
    ///////////////////      Servidor      //////////////////
    //////////////////////////////////////////////////////*/
     
    /**
     * @brief Crear un servidor por medio de sus atributos previamente obtenidos
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se creara y guardara un servidor 
     * @param String region
     */
    public void crearServidor (String region) throws Exception{
        Servidor s = new Servidor (region);
        conn.InsertarServidor(s);
        servidores_sistema.add (s);
    }
    
    /**
     * @brief Modificara un servidor existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se modificara y guardara un servidor 
     * @param String Id -> id del servidor a modificar
     * @param String region -> nuevo dato
     */
    public void ModificarServidor (String Id, String region) throws Exception{
        int i=0;
        for (i=0; i<servidores_sistema.size() && !servidores_sistema.get(i).getIdServer().equals(Id); i++){
        }
        conn.ModificarServidor(servidores_sistema.get(i), region);

    }
    
    /**
     * @brief Eliminara un servidor existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id del servidor a eliminar
     */
    public String EliminarServidor (String Id) throws Exception{
        String mensaje="VALIDO";
        int i=0;
        for (i=0; i<servidores_sistema.size() && !servidores_sistema.get(i).getIdServer().equals(Id); i++){
        }
        mensaje = conn.EliminarServidor(Id);
        if (mensaje.equals("VALIDO")){
            servidores_sistema.remove(i);
        }
        
        return mensaje;
    }
    
    public ArrayList<Servidor> getServidores_sistema() {
        return servidores_sistema;
    }
    
    /*////////////////////////////////////////////////////////
    ///////////////////     Inventario     //////////////////
    //////////////////////////////////////////////////////*/
    
    /**
     * @brief Crear un inventario por medio de sus atributos previamente obtenidos
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se creara y guardara un inventario 
     * @param int slotsMaximos
     * @param int slotsOcupados
     * @param String[] idsJugadorInventarios -> jugadores con acceso a ese inventario
     */
    public String crearInventario (int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios) throws Exception{

        String mensaje = "VALIDO";

        mensaje = conn.InsertarInventario(slotsMaximos, slotsOcupados, idsJugadorInventarios);
        
        return mensaje;
        
    }
    
    /**
     * @brief Modificara un inventario existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se modificara y guardara un inventario 
     * @param String Id -> id del inventario a modificar
     * @param int slotsMaximos
     * @param int slotsOcupados
     * @param String[] idsJugadorInventarios -> jugadores con acceso a ese inventario
     */
    public String ModificarInventario (String Id, int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios) throws Exception{

        String mensaje = "VALIDO";
        
        mensaje = conn.ModificarInventario(Id, slotsMaximos, slotsOcupados, idsJugadorInventarios);
    
        return mensaje;
    }
    
    /**
     * @brief Eliminara un inventario existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id del inventario a eliminar
     */
    public String EliminarInventario (String Id) throws Exception{
        String mensaje = "VALIDO";
        int i=0;
        for (i=0; i<inventarios_sistema.size() && !inventarios_sistema.get(i).getIdInventario().equals(Id); i++){
        }
        mensaje = conn.EliminarInventario(Id);
        if (mensaje.equals("VALIDO")){
            inventarios_sistema.remove(i);
        }
        return mensaje;
        
    }
    
    public ArrayList<InventarioCompartido> getInventarios_sistema(){
        return inventarios_sistema;
    }
    
    /**
     * @brief Comprueba si existe la id de un jugador en la instancia actual del sistema
     * @return Boolean existe 
     * @param String Id -> id del jugador a comprobar
     */
    public Boolean existeIDJugador (String id){
        Boolean existe=false;
        for (int i=0; i<jugadores_sistema.size() && existe==false; i++){
            if (id.equals(jugadores_sistema.get(i).getIdPlayer())){
                existe=true;
            }
        }
        return existe;
    }
    
    /*////////////////////////////////////////////////////////
    ////////////////////     Partida     ////////////////////
    //////////////////////////////////////////////////////*/
    
    
    /**
     * @brief Crear una Partida por medio de sus atributos previamente obtenidos
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se creara y guardara una partida 
     * @param int numEspectadores
     * @param String IdServerPartida -> id de un servidor que sera asignado a la partida
     * @param String[] idsjugadores -> grupo de ids de jugadores que seran usadas para buscar el jugador y asignarlo a la partida
     */
    public String crearPartida (int numEspectadores, String IdServerPartida, String[] idsjugadores) throws Exception{
        
        String mensaje = "VALIDO";

        mensaje = conn.InsertarPartida(numEspectadores, IdServerPartida, idsjugadores);
        
        return mensaje;
    }
    
    /**
     * @brief Modificar una Partida por medio de sus nuevos atributos previamente obtenidos
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se modificara y guardara una partida 
     * @param String Id -> id de la partida a modificar
     * @param int numEspectadores
     * @param String IdServerPartida -> id de un servidor que sera asignado a la partida
     * @param String[] idsjugadores -> grupo de ids de jugadores que seran usadas para buscar el jugador y asignarlo a la partida
     */
    public String ModificarPartida (String Id, int numEspectadores, String id_server, String[] idsjugadores) throws Exception{
        String mensaje = "VALIDO";
        
        mensaje = conn.ModificarPartida(Id, numEspectadores, id_server, idsjugadores);
    
        return mensaje;
    }
    
    /**
     * @brief Eliminara una partida existente obtenida con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id de la partida a eliminar
     */
    public void EliminarPartida (String Id) throws Exception{
        int i=0;
        for (i=0; i<partidas_sistema.size() && !partidas_sistema.get(i).getIdPartida().equals(Id); i++){
        }
        conn.EliminarPartida(partidas_sistema.get(i));
        partidas_sistema.remove(i);
        
    }
    
    public ArrayList<Partida> getPartidas_sistema() {
        return partidas_sistema;
    }
    
    /**
     * @brief Comprueba si existe la id de un servidor en la instancia actual del sistema
     * @return Boolean existe 
     * @param String Id -> id del servidor a comprobar
     */
    public Boolean existeIDServer (String Id){
        Boolean existe=false;
        for (int i=0; i<servidores_sistema.size() && existe==false; i++){
            if (Id.equals(servidores_sistema.get(i).getIdServer())){
                existe=true;
            }
        }
        return existe;
    }
    
    /**
     * @brief Comprueba si un servidor esta usado ya en alguna partida (Se debera tener en cuenta a la hora de editar que ya esta siendo usado)
     * @return Boolean libre 
     * @param String Id -> id del servidor a comprobar
     */
    public Boolean estaLibreIDServer (String Id){
        Boolean libre=true;
        
        for (int i=0; i<partidas_sistema.size() && libre==true; i++){
            
            if (partidas_sistema.get(i).getServerPartida().getIdServer().equals(Id)){
                libre=false;
            }
        }
        return libre;
    }
    
    /**
     * @brief busca y retorna un servidor del sistema por su id
     * @pre debera de existir el servidor
     * @return Servidor s
     * @param String Id -> id del servidor a buscar
     */
    public Servidor obtenerServidorId (String id){
        int i=0;

        for (i=0; i<servidores_sistema.size() && !servidores_sistema.get(i).getIdServer().equals(id); i++ ){
        }

        return servidores_sistema.get(i);
    }
    
    /**
     * @brief Comprueba si existe la id de un jugador en la instancia actual del sistema
     * @return Boolean existe 
     * @param String Id -> id del jugador a comprobar
     */
    public Boolean comprobarExistenciaIdJugador (String id){
        Boolean existe = false;
        
        for (Jugador j : jugadores_sistema){
            if (j.getIdPlayer().equals(id)){
                existe=true;
            }
        }
        
        return existe;
    }
    
    /**
     * @brief Comprueba si un jugador esta dentro de alguna partida (Se debera tener en cuenta a la hora de editar que ya esta siendo usado)
     * @return Boolean usado 
     * @param String Id -> id del jugador a comprobar
     */
    public Boolean comprobarUsoIdJugador (String id){
        Boolean usado = false;
        
        for (Partida p : partidas_sistema){
            for (Jugador j : p.getJugadores()){
                if (j.getIdPlayer().equals(id)){
                    usado=true;
                }
            }
        }
        
        return usado;
    }
    
    /**
     * @brief busca y retorna un jugador del sistema por su id
     * @pre debera de existir el jugador
     * @return Jugador j
     * @param String Id -> id del jugador a buscar
     */
    public Jugador getJugadorById (String id){
        int i=0;

        for (i=0; i<jugadores_sistema.size() && !jugadores_sistema.get(i).getIdPlayer().equals(id); i++ ){
        }

        return jugadores_sistema.get(i);
    }
    
    /*////////////////////////////////////////////////////////
    ////////////////////     Jugador     ////////////////////
    //////////////////////////////////////////////////////*/
    
    /**
     * @brief Crear una Jugador por medio de sus atributos previamente obtenidos
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se creara y guardara una jugador 
     * @param String NickName
     * @param int nivel
     * @param String[] idsInventariosJugador -> grupo de ids de inventarios usados para asignar a estos al jugador 
     */
    public String crearJugador (String NickName, int nivel, String[] idsInventariosJugador) throws Exception{
        

        String mensaje = "VALIDO";

        mensaje = conn.InsertarJugador(NickName, nivel, idsInventariosJugador);
        
        return mensaje; 
        
        
    }
    
    /**
     * @brief Modificar una jugador por medio de sus nuevos atributos previamente obtenidos
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se modificara y guardara el jugador
     * @param String Id -> id del jugador a modificar
     * @param String NickName
     * @param int nivel
     * @param String[] idsInventariosJugador -> grupo de ids de inventarios usados para asignar a estos al jugador      
     */
    public String ModificarJugador (String Id, String NickName, int nivel, String [] idsInventariosJugador) throws Exception{

        
        String mensaje = "VALIDO";
        
        mensaje = conn.ModificarJugador(Id, NickName, nivel, idsInventariosJugador);
    
        return mensaje;
        
        
    }
    
    /**
     * @brief Eliminara un jugador existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id del jugador a eliminar
     */
    public String EliminarJugador (String Id) throws Exception{
        String mensaje = "VALIDO";
        int i=0;
        for (i=0; i<jugadores_sistema.size() && !jugadores_sistema.get(i).getIdPlayer().equals(Id); i++){
        }
        mensaje = conn.EliminarJugador(Id);
        
        if (mensaje.equals("VALIDO")){
            jugadores_sistema.remove(i);
        }
        
        return mensaje;
    }
    
    public ArrayList<Jugador> getJugadores_sistema() {
        return jugadores_sistema;
    }
    
    /**
     * @brief busca y retorna un inventario del sistema por su id
     * @pre debera de existir el inventario
     * @return Inventario inv
     * @param String idI -> id del inventario a buscar
     */
    public InventarioCompartido getInventarioById (String idI){
        int i=0;

        for (i=0; i<inventarios_sistema.size() && !inventarios_sistema.get(i).getIdInventario().equals(idI); i++ ){
        }

        return inventarios_sistema.get(i);
    }
    
    /**
     * @brief Comprueba si existe la id de un inventario en la instancia actual del sistema
     * @return Boolean existe 
     * @param String Id -> id del inventario a comprobar
     */
    public Boolean existeIDInventario (String id){
        Boolean existe=false;
        for (int i=0; i<inventarios_sistema.size() && existe==false; i++){
            if (id.equals(inventarios_sistema.get(i).getIdInventario())){
                existe=true;
            }
        }
        return existe;
    }
    
    
    public Conexion getconn (){
        return this.conn;
    }

    
}
