package com.mycompany.cristofyclient;

import com.mycompany.CristofyClient.CristofyProtocol;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author DiosFer
 */
public class Buffer {
    
    
    private String hostName;
    private Integer portNumber;
    String nombreArtistaSeleccionado="";
    
    
    Semaphore S_mutex;
    String mensaje;
    String accion;
    Lock loc;
    Long id_cancion_seleccionada;
    
    String rutaCancionCargada;
    
    Boolean startCancion = false;
    Boolean stopCancion = false;
    Boolean actualizarUsers = false;
    Boolean actualizarMusic = false;
    
    ArrayList<String> buffer;
    Boolean loginEstado = false;
    
    ArrayList<String> datosPerfilesConectados;
    ArrayList<String> datosCancionesSistema;
    
    Socket socket;
    PrintWriter out;
    BufferedReader in;
    
    int progreso = 0;
    
    CristofyProtocol cristofyProtocol;
    
    Boolean actualizarProgresBar=false;
    
    public Buffer (Integer pn, String hn){
        this.portNumber = pn;
        this.hostName = hn;
        S_mutex = new Semaphore (0);
        buffer = new ArrayList<String>();
        loc = new ReentrantLock();
        datosPerfilesConectados=new ArrayList<>();
        datosCancionesSistema=new ArrayList<>();
        rutaCancionCargada="";
    }
    
    public String getHostName (){
        return this.hostName;
    }
    
    public Integer getPortNumber (){
        return this.portNumber;
    }
    
    public Semaphore getMutex (){
        return this.S_mutex;
    }
    
    
    public void setMensaje (String s){
        mensaje = s;
    }
    public String getMensaje (){
        return this.mensaje;
    }
    public void setBuffer(String s){
        buffer.add(s);
    }
    public ArrayList<String> getBuffer(){
        return buffer;
    }
    
    public Lock getLock (){
        return loc;
    }

    public String getAccion() {
        return accion;
    }

    public void setAccion(String accion) {
        this.accion = accion;
    }

    public Socket getSocket() {
        return socket;
    }

    public void setSocket(Socket socket) {
        this.socket = socket;
    }

    public PrintWriter getOut() {
        return out;
    }

    public void setOut(PrintWriter out) {
        this.out = out;
    }

    public BufferedReader getIn() {
        return in;
    }

    public void setIn(BufferedReader in) {
        this.in = in;
    }

    public CristofyProtocol getCristofyProtocol() {
        return cristofyProtocol;
    }

    public void setCristofyProtocol(CristofyProtocol cristofyProtocol) {
        this.cristofyProtocol = cristofyProtocol;
    }

    public ArrayList<String> getDatosPerfilesConectados() {
        return datosPerfilesConectados;
    }

    public void setDatosPerfilesConectados(ArrayList<String> datosPerfilesConectados) {
        this.datosPerfilesConectados = datosPerfilesConectados;
    }

    public ArrayList<String> getDatosCancionesSistema() {
        return datosCancionesSistema;
    }

    public void setDatosCancionesSistema(ArrayList<String> datosCancionesSistema) {
        this.datosCancionesSistema = datosCancionesSistema;
    }

    public Long getId_cancion_seleccionada() {
        return id_cancion_seleccionada;
    }

    public void setId_cancion_seleccionada(Long id_cancion_seleccionada) {
        this.id_cancion_seleccionada = id_cancion_seleccionada;
    }

    public Boolean getStartCancion() {
        return startCancion;
    }

    public void setStartCancion(Boolean startCancion) {
        this.startCancion = startCancion;
    }

    public Boolean getStopCancion() {
        return stopCancion;
    }

    public void setStopCancion(Boolean stopCancion) {
        this.stopCancion = stopCancion;
    }

    public String getRutaCancionCargada() {
        return rutaCancionCargada;
    }

    public void setRutaCancionCargada(String rutaCancionCargada) {
        this.rutaCancionCargada = rutaCancionCargada;
    }

    public Boolean getActualizarProgresBar() {
        return actualizarProgresBar;
    }

    public void setActualizarProgresBar(Boolean actualizarProgresBar) {
        this.actualizarProgresBar = actualizarProgresBar;
    }

    public int getProgreso() {
        return progreso;
    }

    public void setProgreso(int progreso) {
        this.progreso = progreso;
    }

    public Boolean getLoginEstado() {
        return loginEstado;
    }

    public void setLoginEstado(Boolean loginEstado) {
        this.loginEstado = loginEstado;
    }

    public Boolean getActualizarUsers() {
        return actualizarUsers;
    }

    public void setActualizarUsers(Boolean actualizarUsers) {
        this.actualizarUsers = actualizarUsers;
    }

    public Boolean getActualizarMusic() {
        return actualizarMusic;
    }

    public void setActualizarMusic(Boolean actualizarMusic) {
        this.actualizarMusic = actualizarMusic;
    }

    public String getNombreArtistaSeleccionado() {
        return nombreArtistaSeleccionado;
    }

    public void setNombreArtistaSeleccionado(String nombreArtistaSeleccionado) {
        this.nombreArtistaSeleccionado = nombreArtistaSeleccionado;
    }
    
    
    
}
