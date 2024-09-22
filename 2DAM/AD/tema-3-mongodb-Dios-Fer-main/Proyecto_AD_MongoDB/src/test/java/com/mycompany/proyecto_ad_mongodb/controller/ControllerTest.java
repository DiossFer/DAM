package com.mycompany.proyecto_ad_mongodb.controller;

import com.mongodb.MongoException;
import com.mycompany.proyecto_ad_mongodb.controller.Controller;
import com.mycompany.proyecto_ad_mongodb.modelos.InventarioCompartido;
import com.mycompany.proyecto_ad_mongodb.modelos.Jugador;
import com.mycompany.proyecto_ad_mongodb.modelos.Partida;
import com.mycompany.proyecto_ad_mongodb.modelos.Servidor;
import java.util.ArrayList;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;


/**
 *
 * @author DiosFer
 */
public class ControllerTest {
    
    
    private static Controller instance;
    

    public ControllerTest()  throws MongoException {

    }
    
    @BeforeAll
    public static void setUpClass() {
        
        instance = new Controller("ProyectoGamesTest");
        
        String stringAux;
        String [] VstringAux;
        // Vaciamos por si hay algo
        eliminarDatosBD();
                
        
        ////////
        ////  Preparamos la instancia para la BD de pruebas
        ///////
        
        // Preparo instancia inicial para los test
        
        // Servidores
        
        instance.crearServidor("Espania");
        instance.crearServidor("Asia");
        instance.crearServidor("Asia");
        instance.crearServidor("Europa");
        instance.crearServidor("Europa");
        instance.crearServidor("Asia");
        instance.crearServidor("Asia");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        instance.crearServidor("EEUU");
        
        // Inventarios
        
        stringAux = "";
        VstringAux = stringAux.split(", ");
        
        // Crearemos por el momento todos los inventarios sin jugadores
        
        instance.crearInventario(100, 10, VstringAux);
        instance.crearInventario(200, 20, VstringAux);
        instance.crearInventario(300, 30, VstringAux);
        instance.crearInventario(400, 40, VstringAux);
        instance.crearInventario(500, 50, VstringAux);
        instance.crearInventario(600, 60, VstringAux);
        instance.crearInventario(700, 70, VstringAux);
        instance.crearInventario(800, 80, VstringAux);
        
        
        // Jugadores
        
        // J-1 con I-1 y I-2
        stringAux = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", " + instance.getInventarios_sistema().get(1).getIdInventario();
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer1", 10, VstringAux);
        
        // J-2 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer2", 20, VstringAux);
        
        // J-3 con I-1 y I-2
        stringAux = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", " + instance.getInventarios_sistema().get(1).getIdInventario();
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer3", 30, VstringAux);
        
        // J-4 con I-3
        stringAux = "" + instance.getInventarios_sistema().get(2).getIdInventario();
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer4", 40, VstringAux);
        
        // J-5 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer5", 50, VstringAux);
        
        // J-6 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer6", 60, VstringAux);
        
        // J-7 con I-7
        stringAux = "" + instance.getInventarios_sistema().get(6).getIdInventario();
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer7", 70, VstringAux);
        
        // J-8 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer8", 80, VstringAux);
        
        // J-9 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer9", 90, VstringAux);
        
        // J-10 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer10", 100, VstringAux);
        
        // J-11 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer11", 110, VstringAux);
        
        // J-12 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer12", 120, VstringAux);
        
        // J-13 sin inventarios
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer13", 130, VstringAux);
        
        // J-14 con I-1 y I-2
        stringAux = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", " + instance.getInventarios_sistema().get(1).getIdInventario();
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer14", 140, VstringAux);
        
        // J-15 con I-1 y I-2
        stringAux = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", " + instance.getInventarios_sistema().get(1).getIdInventario();
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer15", 150, VstringAux);
        
        // J-16 con I-1 y I-2
        stringAux = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", " + instance.getInventarios_sistema().get(1).getIdInventario();
        VstringAux = stringAux.split(", ");
        instance.crearJugador("Fer16", 160, VstringAux);
        
        // Partidas
        
        // P-1 con J-1 y J-2
        // P-1 con S-1
        stringAux = "" + instance.getJugadores_sistema().get(0).getIdPlayer()+ ", " + instance.getJugadores_sistema().get(1).getIdPlayer();
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(0).getIdServer(), VstringAux);
        
        // P-2 sin jugadores
        // P-2 con S-2
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(1).getIdServer(), VstringAux);
        
        // P-3 con J-3
        // P-3 con S-3
        stringAux = "" + instance.getJugadores_sistema().get(2).getIdPlayer();
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(2).getIdServer(), VstringAux);
        
        // P-4 con J-4
        // P-4 con S-4
        stringAux = "" + instance.getJugadores_sistema().get(3).getIdPlayer();
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(3).getIdServer(), VstringAux);
        
        // P-5 sin jugadores
        // P-5 con S-5
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(4).getIdServer(), VstringAux);
        
        // P-6 sin jugadores
        // P-6 con S-17
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(16).getIdServer(), VstringAux);
        
        // P-7 sin jugadores
        // P-6 con S-18
        stringAux = "";
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(17).getIdServer(), VstringAux);
        
        // P-7 con J-16
        // P-6 con S-19
        stringAux = "" + instance.getJugadores_sistema().get(15);
        VstringAux = stringAux.split(", ");
        instance.crearPartida(10, instance.getServidores_sistema().get(18).getIdServer(), VstringAux);
        
    }
    
    @AfterAll
    public static void tearDownClass()  throws MongoException {
        
        ////////
        ////  Eliminamos todos los datos de la BD de pruebas
        ///////
        eliminarDatosBD();
        
        
        /// Cerramos la conexion con la bd
        instance.cerrar_conexion();
        
    }
    
    /**
     * @brief Metodo para vaciar los datos (si hay) de la bd 
     * @post se eliminaran todos los datos de la BD y el sistema (partidas, servidores, jugadores, inventarios)
     */
    
    public static void eliminarDatosBD (){

        /// Vaciamos Partidas

        for (int i = instance.getPartidas_sistema().size(); i>0; i--){
            instance.EliminarPartida(instance.getPartidas_sistema().get(i-1).getIdPartida());
        }

        /// Vaciamos Servidores
        for (int i = instance.getServidores_sistema().size(); i>0; i--){
            instance.EliminarServidor(instance.getServidores_sistema().get(i-1).getIdServer());
        }

        /// Vaciamos Jugadores
        for (int i = instance.getJugadores_sistema().size(); i>0; i--){
            instance.EliminarJugador(instance.getJugadores_sistema().get(i-1).getIdPlayer());
        }

        /// Vaciamos Inventarios
        for (int i = instance.getInventarios_sistema().size(); i>0; i--){
            instance.EliminarInventario(instance.getInventarios_sistema().get(i-1).getIdInventario());
        }

    }
    
    /**
     * Prueba 0
     * Partimos de que nuestra bd tiene instancias (preparada en el before all) y la lectura inicial es en la creacion del controlador
     * por tanto esta lectura debera de haber rellenado los vectores del controlador cosa que se comprueba en este test
     */
    @Test
    public void testLectura(){
        
        Boolean condicion=true;
        
        if (instance.getServidores_sistema().size()==0){
            condicion=false;
        }
        
        if (instance.getInventarios_sistema().size()==0){
            condicion=false;
        }
        
        else if (instance.getJugadores_sistema().size()==0){
            condicion=false;
        }
        
        else if (instance.getPartidas_sistema().size()==0){
            condicion=false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    
    /**
     * Test 1
     * Realizamos la creacion de un servidor 
     * Comprobamos que no salten excepciones, que se añada al sistema y que se añada a la BD
     */
    @Test 
    public void testCrearServidor_1(){
        
        int numActual = instance.getServidores_sistema().size();
        Boolean condicion = true;
        
        try {
            instance.crearServidor("Asia");
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getServidores_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getServidor_BD_ByID(instance.getServidores_sistema().get(instance.getServidores_sistema().size()-1).getIdServer())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }

    /**
     * Test 2
     * Realizamos la modificacion de un servidor
     * Comprobamos que se elimine ni cree nada y que se modifiquen de manera correcta los campos seleccionados
     */
    @Test
    public void testModificarServidor_1(){
        
        int numActual = instance.getServidores_sistema().size();
        Boolean condicion = true;
        Servidor sMod = null;
        
        String RegionMod = "EEUU";
        
        try {
            instance.ModificarServidor(instance.getServidores_sistema().get(0).getIdServer(), RegionMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getServidores_sistema().size()){
            condicion = false;
        }
        
        sMod = instance.getconn().getServidor_BD_ByID(instance.getServidores_sistema().get(0).getIdServer());

        if (sMod!=null){
            if (!sMod.getRegion().equals(RegionMod)){
                condicion = false;
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }

    /**
     * Test 3
     * Eliminamops un servidor que no este en ninguna partida
     * Comprobamos que se halla eliminado
     */
    @Test
    public void testEliminarServidor_1(){
        
        
        int numActual = instance.getServidores_sistema().size();
        Boolean condicion = true;
        
        Servidor sEliminado = null;
        
        String idEliminado = instance.getServidores_sistema().get(7).getIdServer(); // S-8 no se usa
        
        try {
            instance.EliminarServidor(idEliminado);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if ((numActual-1) != instance.getServidores_sistema().size()){
            condicion = false;
        }
        
        sEliminado = instance.getconn().getServidor_BD_ByID(idEliminado);

        if (sEliminado != null){
            condicion = false;
        }
        
        
        assertEquals(true, condicion);
        
    }
    
     /**
     * Test 4
     * Eliminar servidor que este en una partida
     * Comprobamos que no se halla eliminado nada
     */
    @Test
    public void testEliminarServidor_2(){
        
        int numActual = instance.getServidores_sistema().size();
        Boolean condicion = true;
        
        Servidor sEliminado = null;
        
        String idEliminado = instance.getServidores_sistema().get(0).getIdServer(); // S-1 se usa en P1
        
        try {
            instance.EliminarServidor(idEliminado);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getServidores_sistema().size()){
            condicion = false;
        }
        
        sEliminado = instance.getconn().getServidor_BD_ByID(idEliminado);

        if (sEliminado == null){
            condicion = false;
        }

        assertEquals(true, condicion);
        
    }


    /**
     * Test 5
     * Creamos inventario sin jugadores
     * Comprobamos que se halla creado en el sistema y en la BD
     */
    @Test
    public void testCrearInventario_1(){
        
         
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "";
            VstringAux = stringAux.split(", ");
            
            instance.crearInventario(1000, 100, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getInventario_BD_ByID(instance.getInventarios_sistema().get(instance.getInventarios_sistema().size()-1).getIdInventario())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }

    
     /**
     * Test 6
     * Creamos un inventario con un jugador
     */
    @Test
    public void testCrearInventario_2(){
        

         
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "" + instance.getJugadores_sistema().get(0).getIdPlayer();
            VstringAux = stringAux.split(", ");
            
            instance.crearInventario(2000, 200, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getInventario_BD_ByID(instance.getInventarios_sistema().get(instance.getInventarios_sistema().size()-1).getIdInventario())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
        
    }
    
    /**
     * Test 7
     * Creamos inventario con varios jugadores
     * 
     */
    @Test
    public void testCrearInventario_3(){
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "" + instance.getJugadores_sistema().get(0).getIdPlayer()+ ", " + instance.getJugadores_sistema().get(1).getIdPlayer();
            VstringAux = stringAux.split(", ");
            
            instance.crearInventario(2000, 200, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getInventario_BD_ByID(instance.getInventarios_sistema().get(instance.getInventarios_sistema().size()-1).getIdInventario())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);        
    }
    
     /**
     * Test 8
     * Creamos un inventario con un jugador inexistente
     */
    @Test
    public void testCrearInventario_4(){
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "" + instance.getJugadores_sistema().get(0).getIdPlayer()+ ", " + "Jugador1234";
            VstringAux = stringAux.split(", ");
            
            instance.crearInventario(2000, 200, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }
        
        assertEquals(true, condicion);        
        
    }
    
    /**
     * Test 9
     * 
     */
    @Test
    public void testCrearInventario_5(){
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        stringAux = "" + instance.getJugadores_sistema().get(0).getIdPlayer() + ", " + instance.getJugadores_sistema().get(0).getIdPlayer();
        VstringAux = stringAux.split(", ");
        
        try {
            
            
            instance.crearInventario(2000, 200, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }
        
        assertEquals(true, condicion);  
        
    }
    
    
    /**
     * Test 10
     * Modificamos un inventario quitandole los jugadores que tenga
     */
    @Test
    public void testModificarInventario_1(){
        
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        InventarioCompartido iMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "";
        VstringAuxMod = stringAuxMod.split(", ");
        
        int sMaxMod = 10;
        int sOcpMod = 1;
        
        try {
            instance.ModificarInventario(instance.getInventarios_sistema().get(0).getIdInventario(), sMaxMod, sOcpMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }

        iMod = instance.getconn().getInventario_BD_ByID(instance.getInventarios_sistema().get(0).getIdInventario());

        if (iMod!=null){
            if (iMod.getSlotsMaximos() != sMaxMod){
                condicion = false;
            }
            else if (iMod.getSlotsOcupados()!= sOcpMod){
                condicion = false;
            }
            else {
                String aux = "";
                
                for (int k = 0; k < iMod.getJugadores().size(); k++){
                    aux += iMod.getJugadores().get(k).getIdPlayer();
                    if (k != iMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 11
     * Añadir un jugador a un inventario
     */
    @Test
    public void testModificarInventario_2(){
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        InventarioCompartido iMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getJugadores_sistema().get(0).getIdPlayer();
        VstringAuxMod = stringAuxMod.split(", ");
        
        int sMaxMod = 10;
        int sOcpMod = 1;
        
        try {
            instance.ModificarInventario(instance.getInventarios_sistema().get(3).getIdInventario(), sMaxMod, sOcpMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }

        iMod = instance.getconn().getInventario_BD_ByID(instance.getInventarios_sistema().get(3).getIdInventario());

        if (iMod!=null){
            if (iMod.getSlotsMaximos() != sMaxMod){
                condicion = false;
            }
            else if (iMod.getSlotsOcupados()!= sOcpMod){
                condicion = false;
            }
            else {
                String aux = "";
                
                for (int k = 0; k < iMod.getJugadores().size(); k++){
                    aux += iMod.getJugadores().get(k).getIdPlayer();
                    if (k != iMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 12
     * Añadir un jugador que no exista a un inventario
     */
    @Test
    public void testModificarInventario_3(){
        
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        InventarioCompartido iMod = null;
        
        String idInventarioMod = instance.getInventarios_sistema().get(3).getIdInventario();
        
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "Jugador1234";
        VstringAuxMod = stringAuxMod.split(", ");
        
        int sMaxMod = 10;
        int sOcpMod = 1;
        
        try {
            instance.ModificarInventario(idInventarioMod, sMaxMod, sOcpMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }

        iMod = instance.getconn().getInventario_BD_ByID(idInventarioMod);

        if (iMod!=null){
            if (iMod.getSlotsMaximos() != instance.getconn().getInventarioById(idInventarioMod).getSlotsMaximos()){
                condicion = false;
            }
            else if (iMod.getSlotsOcupados()!= instance.getconn().getInventarioById(idInventarioMod).getSlotsOcupados()){
                condicion = false;
            }
            else {
                String aux = "";
                String aux2 = "";
                
                for (int k = 0; k < iMod.getJugadores().size(); k++){
                    aux += iMod.getJugadores().get(k).getIdPlayer();
                    if (k != iMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                for (int k = 0; k<instance.getconn().getInventarioById(idInventarioMod).getJugadores().size(); k++){
                    aux2 += instance.getconn().getInventarioById(idInventarioMod).getJugadores().get(k).getIdPlayer();
                    
                    if (k != instance.getconn().getInventarioById(idInventarioMod).getJugadores().size()-1){
                        aux2 += ", ";
                    }
                }
                
                if (!aux.equals(aux2)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 13
     * Añadir un jugador repetido a un inventario
     */
    @Test
    public void testModificarInventario_4(){
        
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        InventarioCompartido iMod = null;
        
        String idInventarioMod = instance.getInventarios_sistema().get(4).getIdInventario();
        
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = instance.getJugadores_sistema().get(0) + ", " + instance.getJugadores_sistema().get(0);
        VstringAuxMod = stringAuxMod.split(", ");
        
        int sMaxMod = 10;
        int sOcpMod = 1;
        
        try {
            instance.ModificarInventario(idInventarioMod, sMaxMod, sOcpMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }

        iMod = instance.getconn().getInventario_BD_ByID(idInventarioMod);

        if (iMod!=null){
            if (iMod.getSlotsMaximos() != instance.getconn().getInventarioById(idInventarioMod).getSlotsMaximos()){
                condicion = false;
            }
            else if (iMod.getSlotsOcupados()!= instance.getconn().getInventarioById(idInventarioMod).getSlotsOcupados()){
                condicion = false;
            }
            else {
                String aux = "";
                String aux2 = "";
                
                for (int k = 0; k < iMod.getJugadores().size(); k++){
                    aux += iMod.getJugadores().get(k).getIdPlayer();
                    if (k != iMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                for (int k = 0; k<instance.getconn().getInventarioById(idInventarioMod).getJugadores().size(); k++){
                    aux2 += instance.getconn().getInventarioById(idInventarioMod).getJugadores().get(k).getIdPlayer();
                    
                    if (k != instance.getconn().getInventarioById(idInventarioMod).getJugadores().size()-1){
                        aux2 += ", ";
                    }
                }
                
                if (!aux.equals(aux2)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
    }
    
    /**
     * Test 14
     * Modificar dejandolo igual
     */
    @Test
    public void testModificarInventario_5(){
        
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        InventarioCompartido iMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;

        String idInventarioMod = instance.getInventarios_sistema().get(4).getIdInventario();
        
        stringAuxMod = "";
        
        
        
        for (int k = 0; k < instance.getconn().getInventarioById(idInventarioMod).getJugadores().size(); k++){
            idInventarioMod += instance.getconn().getInventarioById(idInventarioMod).getJugadores().get(k).getIdPlayer();
            if (k != instance.getconn().getInventarioById(idInventarioMod).getJugadores().size()-1){
                idInventarioMod += ", ";
            }
        }
        
        VstringAuxMod = stringAuxMod.split(", ");
        
        int sMaxMod = 10;
        int sOcpMod = 1;
        
        try {
            instance.ModificarInventario(idInventarioMod, sMaxMod, sOcpMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }

        iMod = instance.getconn().getInventario_BD_ByID(idInventarioMod);

        if (iMod!=null){
            if (iMod.getSlotsMaximos() != sMaxMod){
                condicion = false;
            }
            else if (iMod.getSlotsOcupados()!= sOcpMod){
                condicion = false;
            }
            else {
                String aux = "";
                
                for (int k = 0; k < iMod.getJugadores().size(); k++){
                    aux += iMod.getJugadores().get(k).getIdPlayer();
                    if (k != iMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }

    /**
     * Test 15
     * Eliminar inventario que no tenga jugadores
     */
    @Test
    public void testEliminarInventario_1(){
        
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        
        String stringAux = instance.getInventarios_sistema().get(7).getIdInventario();
        
        try {
            
            
            instance.EliminarInventario(stringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual-1 != instance.getInventarios_sistema().size()){
            condicion = false;
        }
        
        else if (instance.getconn().getInventario_BD_ByID(stringAux)!=null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 16
     * Eliminar inventario que tenga jugadores
     */
    @Test
    public void testEliminarInventario_2(){
        
         
        int numActual = instance.getInventarios_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        
        try {
            stringAux = "";
            VstringAux = stringAux.split(", ");
            
            instance.EliminarInventario(instance.getInventarios_sistema().get(6).getIdInventario());
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getInventarios_sistema().size()){
            condicion = false;
        }
        
        else if (instance.getconn().getInventario_BD_ByID(instance.getInventarios_sistema().get(6).getIdInventario())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }


    /**
     * Test 17
     * Crear partida sin jugadores
     */
    @Test
    public void testCrearPartida_1(){
        
         
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "";
            VstringAux = stringAux.split(", ");
            
            instance.crearPartida (10, instance.getServidores_sistema().get(8).getIdServer(), VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getPartida_BD_ByID(instance.getPartidas_sistema().get(instance.getPartidas_sistema().size()-1).getIdPartida())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 18
     * Crear partida con varios jugadores
     */
    @Test
    public void testCrearPartida_2(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "" + instance.getJugadores_sistema().get(4).getIdPlayer() + ", " + instance.getJugadores_sistema().get(7).getIdPlayer() ;
            VstringAux = stringAux.split(", ");
            
            instance.crearPartida (10, instance.getServidores_sistema().get(9).getIdServer(), VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getPartida_BD_ByID(instance.getPartidas_sistema().get(instance.getPartidas_sistema().size()-1).getIdPartida())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 19
     * Crear partida con algun jugador inexistente
     */
    @Test
    public void testCrearPartida_3(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "Jugador1234";
            VstringAux = stringAux.split(", ");
            
            instance.crearPartida (10, instance.getServidores_sistema().get(12).getIdServer(), VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }
        
        
        
        assertEquals(true, condicion);
        
    }

    /**
     * Test 20
     * Crear partida con algun jugador que este en otra partida
     */
    @Test
    public void testCrearPartida_4(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "" + instance.getJugadores_sistema().get(0).getIdPlayer();
            VstringAux = stringAux.split(", ");
            
            instance.crearPartida (10, instance.getServidores_sistema().get(12).getIdServer(), VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }
        
        
        
        assertEquals(true, condicion);
      
    }
    /**
     * Test 21
     * Crear partida con algun jugador repetido
     */
    @Test
    public void testCrearPartida_5(){
        
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "" + instance.getJugadores_sistema().get(8).getIdPlayer() + ", " + instance.getJugadores_sistema().get(8).getIdPlayer();
            VstringAux = stringAux.split(", ");
            
            instance.crearPartida (10, instance.getServidores_sistema().get(12).getIdServer(), VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }
        
        
        
        assertEquals(true, condicion);
      
    }
    

    /**
     * Test 22
     * Crear partida con un servidor inexistente
     */
    @Test
    public void testCrearPartida_6(){
        
         
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "";
            VstringAux = stringAux.split(", ");
            
            instance.crearPartida (10, "Servidor1234", VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }
        
        
        
        assertEquals(true, condicion);
        
      
    }
    
     /**
     * Test 23
     * Crear partida con algun servidor ya usado
     */
    @Test
    public void testCrearPartida_7(){
        
         
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "";
            VstringAux = stringAux.split(", ");
            
            instance.crearPartida (10, instance.getServidores_sistema().get(0).getIdServer(), VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }
        
        
        
        assertEquals(true, condicion);
        
      
    }
    
    /**
     * Test 24
     * Modificar partida dejandola igual
     */
    @Test
    public void testModificarPartida_1(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        stringAuxMod = "";
        String IdpMod = instance.getPartidas_sistema().get(1).getIdPartida();
        
        for (int k = 0; k < instance.getconn().getPartidaById(IdpMod).getJugadores().size(); k++){
            stringAuxMod += instance.getconn().getPartidaById(IdpMod).getJugadores().get(k).getIdPlayer();
            if (k != instance.getconn().getPartidaById(IdpMod).getJugadores().size()-1){
                stringAuxMod += ", ";
            }
        }
        
        VstringAuxMod = stringAuxMod.split(", ");
        
        int numEspectadoresMod = instance.getconn().getPartidaById(IdpMod).getNumEspectadores();
        String idServerMod=instance.getconn().getPartidaById(IdpMod).getServerPartida().getIdServer();
        
        
        
        try {
            instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }

        pMod = instance.getconn().getPartida_BD_ByID(IdpMod);

        if (pMod!=null){
            if (pMod.getNumEspectadores()!= numEspectadoresMod){
                condicion = false;
            }
            else if (!pMod.getServerPartida().getIdServer().equals(idServerMod)){
                condicion = false;

            }
            else {
                String aux = "";
                
                for (int k = 0; k < pMod.getJugadores().size(); k++){
                    aux += pMod.getJugadores().get(k).getIdPlayer();
                    if (k != pMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 25
     * Modificar partida quitando los jugadores
     */
    @Test
    public void testModificarPartida_2(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "";
        VstringAuxMod = stringAuxMod.split(", ");
        
        int numEspectadoresMod = 10;
        String idServerMod=instance.getServidores_sistema().get(15).getIdServer();
        
        String IdpMod = instance.getPartidas_sistema().get(3).getIdPartida();
        
        try {
            instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }

        pMod = instance.getconn().getPartida_BD_ByID(IdpMod);

        if (pMod!=null){
            if (pMod.getNumEspectadores()!= numEspectadoresMod){
                condicion = false;
            }
            else if (!pMod.getServerPartida().getIdServer().equals(idServerMod)){
                condicion = false;

            }
            else {
                String aux = "";
                
                for (int k = 0; k < pMod.getJugadores().size(); k++){
                    aux += pMod.getJugadores().get(k).getIdPlayer();
                    if (k != pMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 26
     * Modificar partida agregando jugadores
     */
    @Test
    public void testModificarPartida_3(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getJugadores_sistema().get(10).getIdPlayer() + ", " + instance.getJugadores_sistema().get(11).getIdPlayer();
        VstringAuxMod = stringAuxMod.split(", ");
        
        int numEspectadoresMod = 10;
        String idServerMod=instance.getServidores_sistema().get(16).getIdServer();
        
        String IdpMod = instance.getPartidas_sistema().get(5).getIdPartida();
        
        try {
            instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getPartidas_sistema().size()){
            condicion = false;
        }

        pMod = instance.getconn().getPartida_BD_ByID(IdpMod);

        if (pMod!=null){
            if (pMod.getNumEspectadores()!= numEspectadoresMod){
                condicion = false;
            }
            else if (!pMod.getServerPartida().getIdServer().equals(idServerMod)){
                condicion = false;

            }
            else {
                String aux = "";
                
                for (int k = 0; k < pMod.getJugadores().size(); k++){
                    aux += pMod.getJugadores().get(k).getIdPlayer();
                    if (k != pMod.getJugadores().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 27
     * Modificar partida agregando jugadores inexistentes
     */
    @Test
    public void testModificarPartida_4(){

        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "Jugador1234";
        VstringAuxMod = stringAuxMod.split(", ");
        
        String mensajeMod="VALIDO";
        
        int numEspectadoresMod = 10;
        String idServerMod=instance.getServidores_sistema().get(16).getIdServer();
        
        String IdpMod = instance.getPartidas_sistema().get(5).getIdPartida();
        
        try {
            mensajeMod=instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }
        if (mensajeMod.equals("VALIDO")){ // en los casoso donde no entra a modificar da otro texto
            condicion = false;
        }

        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 28
     * Modificar partida agregando jugadores ya usado en otra
     */
    @Test
    public void testModificarPartida_5(){
        
         
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getJugadores_sistema().get(0).getIdPlayer();
        VstringAuxMod = stringAuxMod.split(", ");
        
        String mensajeMod="VALIDO";
        
        int numEspectadoresMod = 10;
        String idServerMod=instance.getServidores_sistema().get(16).getIdServer();
        
        String IdpMod = instance.getPartidas_sistema().get(5).getIdPartida();
        
        try {
            mensajeMod=instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (mensajeMod.equals("VALIDO")){ // en los casoso donde no entra a modificar da otro texto
            condicion = false;
        }

        
        assertEquals(true, condicion);
        
    }
    /**
     * Test 29
     * Modificar partida agregando jugador ya agregado
     */
    @Test
    public void testModificarPartida_6(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getJugadores_sistema().get(12).getIdPlayer() + ", "+instance.getJugadores_sistema().get(12).getIdPlayer();
        VstringAuxMod = stringAuxMod.split(", ");
        
        String mensajeMod="VALIDO";
        
        int numEspectadoresMod = 10;
        String idServerMod=instance.getServidores_sistema().get(16).getIdServer();
        
        String IdpMod = instance.getPartidas_sistema().get(5).getIdPartida();
        
        try {
            mensajeMod=instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (mensajeMod.equals("VALIDO")){ // en los casoso donde no entra a modificar da otro texto
            condicion = false;
        }

        
        assertEquals(true, condicion);
        
    }
    /**
     * Test 30
     * Modificar cambiando el servidor a uno inexistente
     */
    @Test
    public void testModificarPartida_7(){
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getJugadores_sistema().get(12).getIdPlayer();
        VstringAuxMod = stringAuxMod.split(", ");
        
        String mensajeMod="VALIDO";
        
        int numEspectadoresMod = 10;
        String idServerMod=instance.getServidores_sistema().get(0).getIdServer();
        
        String IdpMod = instance.getPartidas_sistema().get(5).getIdPartida();
        
        try {
            mensajeMod=instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (mensajeMod.equals("VALIDO")){ // en los casoso donde no entra a modificar da otro texto
            condicion = false;
        }

        
        assertEquals(true, condicion);
        
    }
    /**
     * Test 31
     * Modificar cambiando el servidor a uno ya usado
     */
    @Test
    public void testModificarPartida_8(){
        
        
        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        Partida pMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getJugadores_sistema().get(12).getIdPlayer();
        VstringAuxMod = stringAuxMod.split(", ");
        
        String mensajeMod="VALIDO";
        
        int numEspectadoresMod = 10;
        String idServerMod="Servidor1234";
        
        String IdpMod = instance.getPartidas_sistema().get(5).getIdPartida();
        
        try {
            mensajeMod=instance.ModificarPartida(IdpMod, numEspectadoresMod, idServerMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (mensajeMod.equals("VALIDO")){ // en los casoso donde no entra a modificar da otro texto
            condicion = false;
        }

        
        assertEquals(true, condicion);
        
    }

    /**
     * Test 32
     * Eliminar partida
     */
    @Test
    public void testEliminarPartida_1(){

        int numActual = instance.getPartidas_sistema().size();
        Boolean condicion = true;
        
        Partida pEliminado = null;
        
        String idEliminado = instance.getPartidas_sistema().get(6).getIdPartida(); 
        
        try {
            instance.EliminarPartida(idEliminado);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if ((numActual-1) != instance.getPartidas_sistema().size()){
            condicion = false;
        }
        
        pEliminado = instance.getconn().getPartida_BD_ByID(idEliminado);

        if (pEliminado != null){
            condicion = false;
        }
        
        
        assertEquals(true, condicion);
        
    }
    


    /**
     * Test 33
     * Crear jugador sin inventarios
     */
    @Test
    public void testCrearJugador_1(){
        
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "";
            VstringAux = stringAux.split(", ");
            
            instance.crearJugador("FerPrueba", 100, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getJugadores_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getJugador_BD_ByID(instance.getJugadores_sistema().get(instance.getJugadores_sistema().size()-1).getIdPlayer())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 34
     * Crear jugador con inventarios
     */
    @Test
    public void testCrearJugador_2(){
        
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", " +instance.getInventarios_sistema().get(1).getIdInventario();
            VstringAux = stringAux.split(", ");
            
            instance.crearJugador("FerPrueba", 100, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getJugadores_sistema().size()-1){
            condicion = false;
        }
        
        else if (instance.getconn().getJugador_BD_ByID(instance.getJugadores_sistema().get(instance.getJugadores_sistema().size()-1).getIdPlayer())==null){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /** 35
     * Test 
     * Crear jugador con inventarios que no existen
     */
    @Test
    public void testCrearJugador_3(){
        
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = instance.getInventarios_sistema().get(0).getIdInventario()+ ", " + "Inventario1234";
            VstringAux = stringAux.split(", ");
            
            instance.crearJugador("FerPrueba", 100, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getJugadores_sistema().size()){
            condicion = false;
        }
        
        assertEquals(true, condicion);       
        
    }
    
    /**
     * Test 36
     * Crear jugador con inventarios repetidos
     */
    @Test
    public void testCrearJugador_4(){
        
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        
        String stringAux;
        String [] VstringAux;
        
        try {
            stringAux = instance.getInventarios_sistema().get(0).getIdInventario()+ ", " + instance.getInventarios_sistema().get(0).getIdInventario();
            VstringAux = stringAux.split(", ");
            
            instance.crearJugador("FerPrueba", 100, VstringAux);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getJugadores_sistema().size()){
            condicion = false;
        }
        
        assertEquals(true, condicion);  
        
    }

    /**
     * Test 37
     * Modificar el jugador quitandole sus inventarios 
     */
    @Test
    public void testModificarJugador_1(){
    
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        Jugador jMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "";
        VstringAuxMod = stringAuxMod.split(", ");
        
        String nickNameMod = "FerMod";
        int nivelMod = 10;
        
        try {
            instance.ModificarJugador(instance.getJugadores_sistema().get(13).getIdPlayer(), nickNameMod, nivelMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getJugadores_sistema().size()){
            condicion = false;
        }

        jMod = instance.getconn().getJugador_BD_ByID(instance.getJugadores_sistema().get(13).getIdPlayer());

        if (jMod!=null){
            if (!jMod.getNickName().equals(nickNameMod)){
                condicion = false;
            }
            else if (jMod.getNivel()!= nivelMod){
                condicion = false;
            }
            else {
                String aux = "";
                
                for (int k = 0; k < jMod.getInventarios().size(); k++){
                    aux += jMod.getInventarios().get(k).getIdInventario();
                    if (k != jMod.getInventarios().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 38
     * agregarle inventarios a un jugador
     */
    @Test
    public void testModificarJugador_2(){
    
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        Jugador jMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", "+instance.getInventarios_sistema().get(1).getIdInventario();
        VstringAuxMod = stringAuxMod.split(", ");
        
        String nickNameMod = "FerMod";
        int nivelMod = 10;
        
        try {
            instance.ModificarJugador(instance.getJugadores_sistema().get(13).getIdPlayer(), nickNameMod, nivelMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
            
        }

        if (numActual != instance.getJugadores_sistema().size()){
            condicion = false;
        }

        jMod = instance.getconn().getJugador_BD_ByID(instance.getJugadores_sistema().get(13).getIdPlayer());

        if (jMod!=null){
            if (!jMod.getNickName().equals(nickNameMod)){
                condicion = false;
            }
            else if (jMod.getNivel()!= nivelMod){
                condicion = false;
            }
            else {
                String aux = "";
                
                for (int k = 0; k < jMod.getInventarios().size(); k++){
                    aux += jMod.getInventarios().get(k).getIdInventario();
                    if (k != jMod.getInventarios().size()-1){
                        aux += ", ";
                    }
                }
                
                if (!aux.equals(stringAuxMod)){
                    condicion=false;
                }
                
            }
        }
        
        else{
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
        
    }
    
    /**
     * Test 39
     * agregar un inventario inexistente al jugador
     */
    @Test
    public void testModificarJugador_3(){
    
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        Jugador jMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", "+"Inventario1234";
        VstringAuxMod = stringAuxMod.split(", ");
        
        String nickNameMod = "FerMod";
        int nivelMod = 10;
        String mensaje="VALIDO";
        try {
            mensaje=instance.ModificarJugador(instance.getJugadores_sistema().get(13).getIdPlayer(), nickNameMod, nivelMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getJugadores_sistema().size()){
            condicion = false;
        }

        if(mensaje.equals("VALIDO")){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }
    
    /**
     * Test 40
     * agregar un inventario ya agregado al jugador
     */
    @Test
    public void testModificarJugador_4(){
    
        
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        Jugador jMod = null;
                
        String stringAuxMod;
        String [] VstringAuxMod;
        
        stringAuxMod = "" + instance.getInventarios_sistema().get(0).getIdInventario() + ", "+instance.getInventarios_sistema().get(0).getIdInventario();
        VstringAuxMod = stringAuxMod.split(", ");
        
        String nickNameMod = "FerMod";
        int nivelMod = 10;
        String mensaje="VALIDO";
        try {
            mensaje=instance.ModificarJugador(instance.getJugadores_sistema().get(13).getIdPlayer(), nickNameMod, nivelMod, VstringAuxMod);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if (numActual != instance.getJugadores_sistema().size()){
            condicion = false;
        }

        if(mensaje.equals("VALIDO")){
            condicion = false;
        }
        
        assertEquals(true, condicion);
        
    }

    
    /**
     * Test 41
     * Eliminar jugador que este en partida
     */
    @Test
    public void testEliminarJugador_1(){
    
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        
        Jugador jEliminado = null;
        
        String idEliminado = instance.getJugadores_sistema().get(0).getIdPlayer(); 
        
        try {
            instance.EliminarJugador(idEliminado);
        }
        catch (MongoException me) {
            condicion = false;
        }

        if ((numActual) != instance.getJugadores_sistema().size()){
            condicion = false;

        }
        
        jEliminado = instance.getconn().getJugador_BD_ByID(idEliminado);

        if (jEliminado == null){
            condicion = false;

        }
        
        
        assertEquals(true, condicion);
        
    }
    
    

    /**
     * Test 42
     * eliminar jugador que no este en partida
     */
    @Test
    public void testEliminarJugador_2(){
    
        int numActual = instance.getJugadores_sistema().size();
        Boolean condicion = true;
        
        Jugador jEliminado = null;
        
        String idEliminado = instance.getJugadores_sistema().get(14).getIdPlayer(); 
        
        try {
            instance.EliminarJugador(idEliminado);
        }
        catch (MongoException me) {
            condicion = false;

        }

        if ((numActual-1) != instance.getJugadores_sistema().size()){
            condicion = false;

        }
        
        jEliminado = instance.getconn().getJugador_BD_ByID(idEliminado);

        if (jEliminado != null){
            condicion = false;
        }
        
        
        assertEquals(true, condicion);
        
    }
    
    
}
