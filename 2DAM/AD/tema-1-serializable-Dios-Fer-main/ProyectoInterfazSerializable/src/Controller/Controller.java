package Controller;

import Clases.InventarioCompartido;
import Clases.Jugador;
import Clases.Partida;
import Clases.Servidor;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;



/**
 *
 * @author Fernando Ortega Castro
 */
public class Controller { 

    private ArrayList<Servidor> servidores_sistema;
    private ArrayList<InventarioCompartido> inventarios_sistema;
    private ArrayList<Partida> partidas_sistema;
    private ArrayList<Jugador> jugadores_sistema;

    private ArrayList<ArrayList<String>> arrayAuxiliarDeArraysCarga; // Para la carrga de inventarios (parcial)
    
     /**
     * @brief Constructor del controlador con la lectura inicial del serializable
     */
    public Controller () {
            servidores_sistema = new ArrayList<Servidor>();
            inventarios_sistema = new ArrayList<InventarioCompartido>();
            partidas_sistema = new ArrayList<Partida>();
            jugadores_sistema = new ArrayList<Jugador>();
            
            arrayAuxiliarDeArraysCarga = new ArrayList<ArrayList<String>>();
            
            //Carga inicial
            this.leerSerializable_inventario();
            this.leerSerializable_jugador();
            this.leerSerializable_servidor();
            this.leerSerializable_partida();
            
            //Actualizacion de variables de generacion de id
            Servidor.setServidoresActuales(Integer.parseInt((servidores_sistema.get(servidores_sistema.size()-1).getIdServer().substring(2))));
            InventarioCompartido.setInventariosActuales(Integer.parseInt((inventarios_sistema.get(inventarios_sistema.size()-1).getIdInventario().substring(2))));
            Jugador.setJugadoresActuales(Integer.parseInt((jugadores_sistema.get(jugadores_sistema.size()-1).getIdPlayer().substring(2))));
            Partida.setPartidasActuales(Integer.parseInt((partidas_sistema.get(partidas_sistema.size()-1).getIdPartida().substring(2))));

            
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
    public void crearServidor (String region){
        servidores_sistema.add (new Servidor (region));
        this.escribirSerializable_servidor();
    }
    
    /**
     * @brief Modificara un servidor existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se modificara y guardara un servidor 
     * @param String Id -> id del servidor a modificar
     * @param String region -> nuevo dato
     */
    public void ModificarServidor (String Id, String region){
        int i=0;
        for (i=0; i<servidores_sistema.size() && !servidores_sistema.get(i).getIdServer().equals(Id); i++){
        }
        servidores_sistema.get(i).setRegion(region);
        this.escribirSerializable_servidor();
    }
    
    /**
     * @brief Eliminara un servidor existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id del servidor a eliminar
     */
    public void EliminarServidor (String Id){
        int i=0;
        for (i=0; i<servidores_sistema.size() && !servidores_sistema.get(i).getIdServer().equals(Id); i++){
        }
        servidores_sistema.remove(i);
        this.escribirSerializable_servidor();
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
    public void crearInventario (int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios){
        InventarioCompartido inv = new InventarioCompartido (slotsMaximos, slotsOcupados);
        
        
        if (!idsJugadorInventarios[0].trim().equals("")){
            for (String idJ : idsJugadorInventarios){
                inv.setJugadorConAcceso(getJugadorById(idJ));
                getJugadorById(idJ).setInventarioConAcceso(inv);
            }
        }
        
        inventarios_sistema.add (inv);
        
        
        this.escribirSerializable_inventario();
        this.escribirSerializable_jugador();
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
    public void ModificarInventario (String Id, int slotsMaximos, int slotsOcupados, String[] idsJugadorInventarios){
        int i=0;
        InventarioCompartido inv;
        
        for (i=0; i<inventarios_sistema.size() && !inventarios_sistema.get(i).getIdInventario().equals(Id); i++){
        }
        
        inv=inventarios_sistema.get(i);
        inv.setSlotsMaximos(slotsMaximos);
        inv.setSlotsOcupados(slotsOcupados);
        
        
        //retiramos el acceso de todos los jugadores al inventario
        for (Jugador jug : inv.getJugadores()){
            jug.removerInventario(inv.getIdInventario());
        }
        
        //limpiamos los jugadores del inventario
        inv.getJugadores().clear();
        
        //Establecemos los nuevos jugadores
        if (!idsJugadorInventarios[0].trim().equals("")){
            for (String idJ : idsJugadorInventarios){
                inv.setJugadorConAcceso(getJugadorById(idJ));
                getJugadorById(idJ).setInventarioConAcceso(inv);
            }
        }
        
        this.escribirSerializable_inventario();
        this.escribirSerializable_jugador();


    }
    
    /**
     * @brief Eliminara un inventario existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id del inventario a eliminar
     */
    public void EliminarInventario (String Id){
        int i=0;
        for (i=0; i<inventarios_sistema.size() && !inventarios_sistema.get(i).getIdInventario().equals(Id); i++){
        }
        inventarios_sistema.remove(i);
        this.escribirSerializable_inventario();
    }
    
    public ArrayList<InventarioCompartido> getInventarios_sistema() {
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
    public void crearPartida (int numEspectadores, String IdServerPartida, String[] idsjugadores){
        
        Partida p = new Partida (numEspectadores, obtenerServidorId(IdServerPartida));
        
        if (!idsjugadores[0].trim().equals("")){
            for (String idj : idsjugadores){
                p.setUnJugador(getJugadorById(idj));
            }
        }

        partidas_sistema.add (p);
        
        this.escribirSerializable_partida();
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
    public void ModificarPartida (String Id, int numEspectadores, String id_server, String[] idsjugadores){
        int i=0;
        for (i=0; i<partidas_sistema.size() && !partidas_sistema.get(i).getIdPartida().equals(Id); i++){
        }
        partidas_sistema.get(i).setNumEspectadores(numEspectadores);
        partidas_sistema.get(i).setServerPartida(obtenerServidorId(id_server));
        partidas_sistema.get(i).getJugadores().clear();
        
        if (!idsjugadores[0].trim().equals("")){
            for (String idj : idsjugadores){
                partidas_sistema.get(i).setUnJugador(getJugadorById(idj));
            }
        }

        this.escribirSerializable_partida();
    }
    
    /**
     * @brief Eliminara una partida existente obtenida con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id de la partida a eliminar
     */
    public void EliminarPartida (String Id){
        int i=0;
        for (i=0; i<partidas_sistema.size() && !partidas_sistema.get(i).getIdPartida().equals(Id); i++){
        }
        partidas_sistema.remove(i);
        this.escribirSerializable_partida();
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
    public void crearJugador (String NickName, int nivel, String[] idsInventariosJugador){
        
        Jugador j = new Jugador (NickName, nivel);
        
        if (!idsInventariosJugador[0].trim().equals("")){
            for (String idI : idsInventariosJugador){
                j.setInventarioConAcceso(getInventarioById(idI));
                getInventarioById(idI).setJugadorConAcceso(j);
            }
        }

        jugadores_sistema.add (j);
        
        this.escribirSerializable_jugador();
        this.escribirSerializable_inventario();
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
    public void ModificarJugador (String Id, String NickName, int nivel, String [] idsInventariosJugador){
        int i=0;
        Jugador j;
        for (i=0; i<jugadores_sistema.size() && !jugadores_sistema.get(i).getIdPlayer().equals(Id); i++){
        }
        j=jugadores_sistema.get(i);
        j.setNickName(NickName);
        j.setNivel(nivel);
        
        //retiramos el acceso de todos los inventarios del jugador
        for (InventarioCompartido inv : j.getInventarios()){
            inv.removerAcceso(j.getIdPlayer());
        }
        
        //limpiamos los inventarios del jugador
        j.getInventarios().clear();
        
        //Establecemos los nuevos inventarios
        if (!idsInventariosJugador[0].trim().equals("")){
            for (String idI : idsInventariosJugador){
                j.setInventarioConAcceso(getInventarioById(idI));
                getInventarioById(idI).setJugadorConAcceso(j);
            }
        }
        
        this.escribirSerializable_jugador();
        this.escribirSerializable_inventario();
    }
    
    /**
     * @brief Eliminara un jugador existente obtenido con una id 
     * @pre se obtendran y filtraran los datos en la interfaz
     * @post se eliminara y se guardaran los cambios
     * @param String Id -> id del jugador a eliminar
     */
    public void EliminarJugador (String Id){
        int i=0;
        for (i=0; i<jugadores_sistema.size() && !jugadores_sistema.get(i).getIdPlayer().equals(Id); i++){
        }
        
        //retiramos el acceso de todos los inventarios del jugador
        for (InventarioCompartido inv : jugadores_sistema.get(i).getInventarios()){
            inv.removerAcceso(jugadores_sistema.get(i).getIdPlayer());
        }
        
        jugadores_sistema.remove(i);
        
        this.escribirSerializable_jugador();
        this.escribirSerializable_inventario();
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

    /*////////////////////////////////////////////////////////
    //////////////    Serializable_Servidor    //////////////
    //////////////////////////////////////////////////////*/

     /**
     * @brief escribir el serializable de los servidores
     * @post se escribira la instancia actual de los servidores del controlador en un archivo .data
     */
    public void escribirSerializable_servidor(){
        ObjectOutputStream serializador = null;
        try {
            serializador = new ObjectOutputStream(new FileOutputStream("servidores.dat"));
            serializador.writeObject(servidores_sistema);
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (serializador != null)
            try {
                serializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }
    
     /**
     * @brief leer el serializable de los servidores y guardarlo en la instancia del controlador
     * @post leera un archivo .data y guardaran sus datos
     */
    public void leerSerializable_servidor(){
        
        ObjectInputStream deserializador = null;
        try {
            deserializador = new ObjectInputStream(new FileInputStream("servidores.dat"));
            servidores_sistema = (ArrayList<Servidor>)deserializador.readObject();
        } catch (FileNotFoundException fnfe ) {
            fnfe.printStackTrace();
        } catch (ClassNotFoundException cnfe ) {
            cnfe.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (deserializador != null)
            try {
                deserializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }

    /*////////////////////////////////////////////////////////
    /////////////    Serializable_Inventario   //////////////
    //////////////////////////////////////////////////////*/
    
     /**
     * @brief escribir el serializable de los inventarios
     * @post se escribira la instancia actual de los inventarios del controlador en un archivo .data
     */
    public void escribirSerializable_inventario(){
        ObjectOutputStream serializador = null;
        try {
            serializador = new ObjectOutputStream(new FileOutputStream("inventarios.dat"));
            serializador.writeObject(inventarios_sistema);
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (serializador != null)
            try {
                serializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }

     /**
     * @brief leer el serializable de los inventarios y guardarlo en la instancia del controlador 
     * @post leera un archivo .data y guardaran sus datos
     */
    public void leerSerializable_inventario(){ 
        
        ObjectInputStream deserializador = null;
        try {
            deserializador = new ObjectInputStream(new FileInputStream("inventarios.dat"));
            inventarios_sistema = (ArrayList<InventarioCompartido>)deserializador.readObject();
        } catch (FileNotFoundException fnfe ) {
            fnfe.printStackTrace();
        } catch (ClassNotFoundException cnfe ) {
            cnfe.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (deserializador != null)
            try {
                deserializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }
    

    /*////////////////////////////////////////////////////////
    ///////////////    Serializable_Partida  ////////////////
    //////////////////////////////////////////////////////*/

     /**
     * @brief escribir el serializable de las partidas
     * @post se escribira la instancia actual de las partidas del controlador en un archivo .data
     */
    public void escribirSerializable_partida(){
        
        ObjectOutputStream serializador = null;
        try {
            serializador = new ObjectOutputStream(new FileOutputStream("partidas.dat"));
            serializador.writeObject(partidas_sistema);
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (serializador != null)
            try {
                serializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }

     /**
     * @brief leer el serializable de las partidas y guardarlo en la instancia del controlador
     * @post leera un archivo .data y guardaran sus datos
     */
    public void leerSerializable_partida(){
    
        
        ObjectInputStream deserializador = null;
        try {
            deserializador = new ObjectInputStream(new FileInputStream("partidas.dat"));
            partidas_sistema = (ArrayList<Partida>)deserializador.readObject();
        } catch (FileNotFoundException fnfe ) {
            fnfe.printStackTrace();
        } catch (ClassNotFoundException cnfe ) {
            cnfe.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (deserializador != null)
            try {
                deserializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }
    
    /*////////////////////////////////////////////////////////
    //////////////    Serializable_Jugador    ///////////////
    //////////////////////////////////////////////////////*/

     /**
     * @brief escribir el serializable de los jugadores
     * @post se escribira la instancia actual de los jugadores del controlador en un archivo .data
     */
    public void escribirSerializable_jugador(){
        ObjectOutputStream serializador = null;
        try {
            serializador = new ObjectOutputStream(new FileOutputStream("jugadores.dat"));
            serializador.writeObject(jugadores_sistema);
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (serializador != null)
            try {
                serializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }

     /**
     * @brief leer el serializable de los jugadores y guardarlo en la instancia del controlador
     * @post leera un archivo .data y guardaran sus datos
     */
    public void leerSerializable_jugador(){
    
        ObjectInputStream deserializador = null;
        try {
            deserializador = new ObjectInputStream(new FileInputStream("jugadores.dat"));
            jugadores_sistema = (ArrayList<Jugador>)deserializador.readObject();
        } catch (FileNotFoundException fnfe ) {
            fnfe.printStackTrace();
        } catch (ClassNotFoundException cnfe ) {
            cnfe.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            if (deserializador != null)
            try {
                deserializador.close();
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }
    
}
