package com.mycompany.CristofyServer;

import com.mycompany.cristofyserver.ModelController;
import com.mycompany.cristofyserver.buffer.Buffer;
import com.mycompany.cristofyserver.modelo.Cancion;
import com.mycompany.cristofyserver.modelo.Perfil;
import com.mycompany.cristofyserver.modelo.PlayList;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.security.SecureRandom;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Base64;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author DiosFer
 */
public class CristofyProtocol {
    ModelController mc;
    String estado = "Inicia";
    String token = "";
    String login = "";
    Buffer buffer;
    PrintWriter out;
    int sizePackage = 1024;
    
    public CristofyProtocol (Buffer b, PrintWriter out){
        buffer = b;
        this.mc = new ModelController(b);
        this.out=out;
    }
    
    public String processInput(String theInput) {
        String theOutput="";
        
        if (estado.equals("Inicia")){
            theOutput = "Identificate";
            estado = "Iniciado";
        }
        else{
            
            /// Se ha conectado con el cliente
            if (theInput.split("#").length==5 && theInput.split("#")[2].equals("LOGIN")){ 
                //PROTOCOLCRISTOFY1.0#<time_origen>#LOGIN#<user_login>#<pass>
                
                
                if (mc.validarLogin(theInput.split("#")[3]+"#"+ theInput.split("#")[4])){
                    
                    theOutput="PROTOCOLCRISTOFY1.0#"+
                        LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss")) +
                        "#WELLCOME#" + (theInput.split("#")[3]+"#"+ theInput.split("#")[4]).split("#")[0] + 
                            "#WITH_TOKEN#" + "<token>"; 
                    
                    login = theOutput.split("#")[3];
                
                    String t = generarToken();
                    theOutput = theOutput.replace("<token>", t);
                    this.token = t;
                    buffer.getSemaforoBD().lock();
                    Perfil pcon = buffer.getConn().getPerfilesByLogin(login);
                    pcon.setConectado(true);
                    buffer.getConn().updatePerfil(pcon);
                    buffer.getSemaforoBD().unlock();

                }else{
                    theOutput = "PROTOCOLCRISTOFY1.0#"+
                    LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss")) +
                    "#ERROR#BAD_CREDENTIALS";
                }
                

                //System.out.println("DEBUG-------->"+this.token);
            }
            else if (theInput.split("#").length==6 && theInput.split("#")[2].equals("BYEBYE")){ 
                //PROTOCOLCRISTOFY1.0#<time_origen>#BYEBYE#<user_login>#WITH_TOKEN#<token-hash>
                //System.out.println("cerrar");
                //theOutput = "cerrar";
                buffer.getSemaforoBD().lock();
                Perfil pcon = buffer.getConn().getPerfilesByLogin(login);
                pcon.setConectado(false);
                buffer.getConn().updatePerfil(pcon);
                buffer.getSemaforoBD().unlock();
                
                if ((theInput.split("#")[3].equals(login)) && (theInput.split("#")[5].equals(token))){
                    //PROTOCOLCRISTOFY1.0#<time_origen>#SEEYOU#<user_login>#WITH_TOKEN#<token-hash>
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#SEEYOU#"+login+"#WITH_TOKEN#"+token;
                }else{
                    //PROTOCOLCRISTOFY1.0#<time_origen>#ERROR#BAD_CREDENTIALS
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#ERROR#BAD_CREDENTIALS";
                }
                
            }
            else if (theInput.split("#").length==6 && theInput.split("#")[2].equals("GET_USERS_CONNECTED")){ 
                if ((theInput.split("#")[3].equals(login)) && (theInput.split("#")[5].equals(token))){
                    //PROTOCOLCRISTOFY1.0#<time_origen>#OK_CONNECTED_USERS#<user_login>#WITH_TOKEN#<token>#<n_users>#<data_user1>@<data_user2>@ … <data_userN>
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                            "#OK_CONNECTED_USERS#"+login+"#WITH_TOKEN#"+token+prepareConectedUsers();
                }else{
                    //PROTOCOLCRISTOFY1.0#<time_origen>#ERROR#CANT_GET_USERS
                    
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#ERROR#CANT_GET_USERS";
                }
            }
            else if (theInput.split("#").length==6 && theInput.split("#")[2].equals("GET_MUSIC")){ 
                if ((theInput.split("#")[3].equals(login)) && (theInput.split("#")[5].equals(token))){

                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                            "#OK_MUSIC_FOR#"+login+"#WITH_TOKEN#"+token+prepareMusic();
                }else{

                    
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#ERROR#CANT_GET_MUSIC";
                }
            }
            else if (theInput.split("#").length==7 && theInput.split("#")[2].equals("GET_SONG")){ 
                //PROTOCOLCRISTOFY1.0#<time_origen>#GET_SONG#<id_song>#<user_login>#WITH_TOKEN#<token>
                //PROTOCOLCRISTOFY1.0#<time_origen>#OK_SONG_FOR#<id_song>#<user_login>#WITH_TOKEN#<token-hash>#SIZE#<file_size_bytes>
                if ((theInput.split("#")[4].equals(login)) && (theInput.split("#")[6].equals(token))){
                    buffer.getSemaforoBD().lock();
                    Cancion cancionPedida = buffer.getConn().getCancionById(Long.parseLong(theInput.split("#")[3]));
                    buffer.getSemaforoBD().unlock();
                    
                    
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                            "#OK_SONG_FOR#"+cancionPedida.getId_cancion()+"#"+login+"#WITH_TOKEN#"+token+"#SIZE#"+cancionPedida.getTamanio();
                }else{

                    
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#ERROR#CANT_GET_SONG";
                }
            }
            else if (theInput.split("#").length==9 && theInput.split("#")[2].equals("READY_TO_RECEIVE")){ 

                if ((theInput.split("#")[6].equals(login)) && (theInput.split("#")[8].equals(token))){
                    
                    
                    System.out.println("---ENTRAMOS EN EL ENVIO DE LA CANCION---");
                    buffer.getSemaforoBD().lock();
                    Cancion cancionPedida = buffer.getConn().getCancionById(Long.parseLong(theInput.split("#")[3]));
                    buffer.getSemaforoBD().unlock();
                    byte[] bytes = leerBytes(cancionPedida.getRuta());

                    ArrayList <String> mensajes;
                    
                    mensajes = prepararMensajesCancion(bytes, cancionPedida.getId_cancion().toString());
                    
                    int i=0;
                    for (i=0; i<mensajes.size()-1; i++){
                        out.println(mensajes.get(i));
                    }
                          
                    sizePackage = Integer.parseInt(theInput.split("#")[5]);
                    
                            
                    theOutput = mensajes.get(i);
                    
                }else{

                    
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#ERROR#CANT_GET_SONG";
                }
            }
            else if ((theInput.split("#").length==8 && theInput.split("#")[2].equals("GET_SONG")) && theInput.split("#")[7].equals("FINISHED")){
                //PROTOCOLCRISTOFY1.0#<time_origen>#GET_SONG#<id_song>#<user_login>#WITH_TOKEN#<token>#FINISHED
                System.out.println("RECIBO CONFIRMACION FIN CANCION");
                theOutput=theInput;
                
            }
            else if (theInput.split("#").length==7 && theInput.split("#")[2].equals("GET_MUSIC_BY_STRING")){
                //PROTOCOLCRISTOFY1.0#<time_origen>#GET_MUSIC_BY_STRING#<cadena_busqueda>#<user_login>#WITH_TOKEN#<token>
                //PROTOCOLCRISTOFY1.0#<time_origen>#OK_MUSIC_BY_STRING_FOR#<user_login>#WITH_TOKEN#<token>#<n_songs>#<data_song1>@<data_song2>@ … <data_songN>
                if ((theInput.split("#")[4].equals(login)) && (theInput.split("#")[6].equals(token))){
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                            "#OK_MUSIC_BY_STRING_FOR#"+login+"#WITH_TOKEN#"+token+prepareMusicByString(theInput.split("#")[3]);
                    System.out.println("===>>>"+theOutput);
                }else{

                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#ERROR#CANT_GET_MUSIC";
                }
                
                
            }
            else if (theInput.split("#").length==7 && theInput.split("#")[2].equals("GET_ARTIST_SONG")){
                //PROTOCOLCRISTOFY1.0#<time_origen>#GET_ARTIST_SONG#<id_song>#<user_login>#WITH_TOKEN#<token>
                //PROTOCOLCRISTOFY1.0#<time_origen>#OK_ARTIST_FOR#<user_login>#WITH_TOKEN#<token>#<nombre_artista>#<n_songs>#<data_song1>@<data_song2>@ … <data_songN>
                if ((theInput.split("#")[4].equals(login)) && (theInput.split("#")[6].equals(token))){
                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                            "#OK_ARTIST_FOR#"+login+"#WITH_TOKEN#"+token+prepareMusicByIdToArtist(theInput.split("#")[3]);
                    
                }else{

                    theOutput = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#ERROR#CANT_GET_MUSIC";
                }
                
                
            }
            
            else{
                System.out.println("CRISTOFY-SERVER-CRISTOFYPROTOCOL-ELSE");
                theOutput = "PROTOCOLCRISTOFY1.0#ERROR#BAD_CREDENTIALS";
            }
            
        }
        return theOutput;
    }
    
    public String generarToken() {
        SecureRandom random = new SecureRandom();
        byte[] tokenBytes = new byte[32];
        random.nextBytes(tokenBytes);
        String token = Base64.getEncoder().encodeToString(tokenBytes);;
        return token;
    }
    
    
    //PROTOCOLCRISTOFY1.0#<time_origen>#<user_login>#IS_DISCONNECTED.
    public String prepararMensajeDesconexion() {
        
        String mensaje;
        mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                "#"+login+"#IS_DISCONNECTED";
        return mensaje;
    }
    public String prepareConectedUsers (){
        // #<n_users>#<data_user1>@<data_user2>@ … <data_userN>
        //<n_users> → entero que indica el número de usuarios que va a devolver en total el server
        //<data_userX> → <login><nombre><apellidos><total_playlist><total_canciones>
        
        String auxS = "";
        String dataUser = "";
        int auxI = 0;
        int numConectedUser = 0;
        
        buffer.getSemaforoBD().lock();
        List<Perfil> perfiles = buffer.getConn().getPerfiles();
        buffer.getSemaforoBD().unlock();
        
        for (Perfil p : perfiles){
            if (p.getConectado()){
                auxI=0;
                
                numConectedUser++;
                
                //Calculamos las canciones
                for (PlayList pl : p.getPlayLists()){
                    auxI+=pl.getCanciones().size();
                }
                
                dataUser += p.getLogin()+"|"+p.getUserName()+"|"+p.getApellidos()+"|"+p.getPlayLists().size()+"|"+auxI+"@";
                
                
            }
        }
        auxS+="#"+numConectedUser+"#"+dataUser;
        
        return auxS;
    }
    public String prepareMusic (){
        
        
        String auxS = "";
        String dataSong = "";
        int numSongs = 0;
        buffer.getSemaforoBD().lock();
        List <Cancion> canciones = buffer.getConn().getCanciones();
        buffer.getSemaforoBD().unlock();
        
        
        
        for (Cancion c : canciones){

            numSongs++;

            //Calculamos las canciones

            dataSong += c.getId_cancion()+"|"+c.getTitulo()+"|"+c.getArtista().getNombreArtista()+"|"+c.getEstadisticaCancion().getNumReproducciones()+"|"+c.getEstadisticaCancion().getVecesIncluidaEnPlayLists()+"@";


        }
        auxS+="#"+canciones.size()+"#"+dataSong;
        
        return auxS;
    }
    
    
    public byte[] leerBytes (String ruta){
        byte[] bytes = null;
        try {
            
            File cancion = new File(ruta);

            FileInputStream cancionIS = new FileInputStream(cancion);
            
            
            bytes = new byte[(int) cancion.length()];
            

            cancionIS.read(bytes);

            cancionIS.close();

            
        } catch (Exception ex) {
            System.out.println("ERROR");
            
        }
        return bytes;
        
    }
    
    public ArrayList<String> dividirBytes (byte[] bytes){
        ArrayList<String> base64Packets1024 = new ArrayList<>();
        int offset = 0;
        int packetSize = 1024;
        while (offset < bytes.length) {
            
            int length = Math.min(bytes.length - offset, packetSize);
            
            byte[] packet = new byte[length];
            System.arraycopy(bytes, offset, packet, 0, length);
            String base64Packet = Base64.getEncoder().encodeToString(packet);
            base64Packets1024.add(base64Packet);
            offset += length;
            
        }
        return base64Packets1024;
    }
    
    public ArrayList<String> prepararMensajesCancion (byte[] bytes, String idSong){
        //PROTOCOLCRISTOFY1.0#<time_origen>#OK_SONG#<id_song>#FOR#<user_login>#WITH_TOKEN#<palabra_secreta_aleatoria_generada_en_el_servidor_para_cada_usuario_en_esa_sesion-hash>#ID_PACKAGE#<id_package>#BYTES#<bytes>
        ArrayList <String> paquetes = dividirBytes (bytes);
        ArrayList <String> mensajes = new ArrayList<>();
        String m = "";
        int contador = 0;
        for (String p : paquetes){
            
            m = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                    "#OK_SONG#"+idSong+"#FOR#"+login+"#WITH_TOKEN#"+token+
                    "#ID_PACKAGE#"+contador+"#BYTES#"+p;
            mensajes.add(m);
            
            contador++;
        }
        

        return mensajes;
    }
    
    public String prepareMusicByString (String s){
        
        
        String auxS = "";
        String dataSong = "";
        int numSongs = 0;
        buffer.getSemaforoBD().lock();
        List <Cancion> canciones = buffer.getConn().getCanciones();
        buffer.getSemaforoBD().unlock();
        
        
        
        for (Cancion c : canciones){
            
            if (c.getTitulo().contains(s)) {
                numSongs++;

                //Calculamos las canciones

                dataSong += c.getId_cancion()+"|"+c.getTitulo()+"|"+c.getArtista().getNombreArtista()+"|"+c.getEstadisticaCancion().getNumReproducciones()+"|"+c.getEstadisticaCancion().getVecesIncluidaEnPlayLists()+"@";

            }
            

        }
        auxS+="#"+numSongs+"#"+dataSong;
        
        return auxS;
    }
    public String prepareMusicByIdToArtist (String s){
        
        
        String auxS = "";
        String dataSong = "";
        int numSongs = 0;
        buffer.getSemaforoBD().lock();
        List <Cancion> canciones = buffer.getConn().getCancionById(Long.parseLong(s)).getArtista().getCanciones();
        buffer.getSemaforoBD().unlock();
        
        
        
        for (Cancion c : canciones){
            
                numSongs++;

                //Calculamos las canciones

                dataSong += c.getId_cancion()+"|"+c.getTitulo()+"|"+c.getArtista().getNombreArtista()+"|"+c.getEstadisticaCancion().getNumReproducciones()+"|"+c.getEstadisticaCancion().getVecesIncluidaEnPlayLists()+"@";

            

        }
        auxS+="#"+canciones.get(0).getArtista().getNombreArtista()+"#"+canciones.size()+"#"+dataSong;
        
        return auxS;
    }
    
}

