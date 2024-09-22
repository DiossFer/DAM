package com.mycompany.CristofyClient;

import com.mycompany.cristofyclient.Buffer;
import java.io.File;
import java.io.FileOutputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Base64;



/**
 *
 * @author DiosFer
 */
public class CristofyProtocol {
    String token = "";
    String login = "";
    Buffer buffer;
    Long tamanioCancionActual;
    
    ArrayList<byte[]> arrayBytes;
    
    public CristofyProtocol (Buffer b){
        buffer=b;
        arrayBytes = new ArrayList<>();
    }
    
    public String processInput(String theInput) {
        String theOutput="";
        

        //PROTOCOLCRISTOFY1.0#<time_origen>#WELLCOME#<user_login>#WITH_TOKEN#<palabra_secreta_aleatoria_generada_en_el_servidor_para_cada_usuario_en_esa_sesion-hash>
        if (theInput.split("#").length==1 && theInput.split("#")[0].equals("Identificate")){
            
        }
        /// Se ha conectado con el cliente
        else if (theInput.split("#").length==6 && theInput.split("#")[2].equals("WELLCOME")){
            
            if (theInput.split("#")[4].equals("WITH_TOKEN")){
                token = theInput.split("#")[5];
                //System.out.println("DEBUG-------->"+this.token);
            }
            buffer.setLoginEstado(true);

        }
        /// Se piden los clientes conectados
        else if (theInput.split("#").length==8 && theInput.split("#")[2].equals("OK_CONNECTED_USERS")){
            buffer.getDatosPerfilesConectados().clear();
            String s = "";
            String [] perfiles = (theInput.split("#")[7]).split("@");
            for (String p : perfiles){
                String [] auxS = p.split("\\|");
                s = auxS[0] + "|" + auxS[1]+ "|"+ auxS[2]+ "|"+ auxS[3]+ "|"+ auxS[4];
                buffer.getDatosPerfilesConectados().add(s);
            }
            buffer.setActualizarUsers(true);
        }
        /// Se piden las canciones
        else if (theInput.split("#").length==8 && theInput.split("#")[2].equals("OK_MUSIC_FOR")){
            buffer.getDatosCancionesSistema().clear();
            String s = "";
            String [] canciones = (theInput.split("#")[7]).split("@");
            for (String c : canciones){
                String [] auxS = c.split("\\|");
                s = auxS[0] + "|" + auxS[1]+ "|"+ auxS[2]+ "|"+ auxS[3]+ "|"+ auxS[4];
                buffer.getDatosCancionesSistema().add(s);
            }
            buffer.setActualizarMusic(true);
            
        }
        else if (theInput.split("#").length==8 && theInput.split("#")[2].equals("OK_MUSIC_BY_STRING_FOR")){
            buffer.getDatosCancionesSistema().clear();
            String s = "";
            String [] canciones = (theInput.split("#")[7]).split("@");
            for (String c : canciones){
                String [] auxS = c.split("\\|");
                s = auxS[0] + "|" + auxS[1]+ "|"+ auxS[2]+ "|"+ auxS[3]+ "|"+ auxS[4];
                buffer.getDatosCancionesSistema().add(s);
            }
            buffer.setActualizarMusic(true);
            
        }
        else if (theInput.split("#").length==9 && theInput.split("#")[2].equals("OK_SONG_FOR")){
            //PROTOCOLCRISTOFY1.0#<time_origen>#OK_SONG_FOR#<id_song>#<user_login>#WITH_TOKEN#<token-hash>#SIZE#<file_size_bytes>

            tamanioCancionActual = Long.parseLong(theInput.split("#")[8]);
            
            String mensaje = "";
            int size = 1024;
            String idSong = theInput.split("#")[3];
            //PROTOCOLCRISTOFY1.0#<time_origen>#READY_TO_RECEIVE#<id_song>#SIZE_PACKAGE#<size_package>#<user_login>#WITH_TOKEN#<token-hash>
            mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                    "#READY_TO_RECEIVE#"+idSong+"#SIZE_PACKAGE#"+size+"#"+login+"#WITH_TOKEN#"+token;

            
            buffer.getOut().println(mensaje);
            
        }
        else if (theInput.split("#").length==12 && theInput.split("#")[2].equals("OK_SONG")){
            //PROTOCOLCRISTOFY1.0#<time_origen>#OK_SONG#<id_song>#FOR#<user_login>#WITH_TOKEN#<token>#ID_PACKAGE#<id_package>#BYTES#<bytes>
            System.out.println("DEBUG:: Leo Paquete de la Cancion");
            
            //Limpiamos la anterior descarga pues empezamos con la nueva
            if (theInput.split("#")[9].equals("0")){
                arrayBytes.clear();
            }
            
            
            
            String byteStringCodificado = theInput.split("#")[11];
            
            byte[] bytesDescodificados = Base64.getDecoder().decode(byteStringCodificado);
            arrayBytes.add(bytesDescodificados);
            
            Long auxI = 0L;
            for (byte[] b : arrayBytes){
                auxI+=b.length;
            }
            System.out.println("Recibidos: "+auxI);
            System.out.println("Esperados: "+tamanioCancionActual);
            
            // actualizaremos como minimo de 1% en 1%
            if (((int)((Float) ((auxI.floatValue() / tamanioCancionActual.floatValue()))*100.0f))>buffer.getProgreso()){
                //Actualizamos el progreso
                buffer.setProgreso(((int)((Float) ((auxI.floatValue() / tamanioCancionActual.floatValue()))*100.0f)));
                buffer.setActualizarProgresBar(true);
            }
            
            
            
            //Mensaje en el ultimo paquete
            
            if (auxI >= tamanioCancionActual){
                System.out.println("DEBUG:: Mando confirmacion FIN");
                
                //PROTOCOLCRISTOFY1.0#<time_origen>#GET_SONG#<id_song>#<user_login>#WITH_TOKEN#<token>#FINISHED
                String mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                    "#GET_SONG#"+theInput.split("#")[3]+"#"+login+"#WITH_TOKEN#"+token+"#FINISHED";

                buffer.getOut().println(mensaje);
                
                // Guardamos la cancion 
                escribirArchivoCancion(arrayBytes, theInput.split("#")[3]);
                
                
                buffer.setRutaCancionCargada("canciones/"+theInput.split("#")[3]+".mp3");
                
                
                buffer.setStartCancion(true);
                
                buffer.setProgreso(100);
                buffer.setActualizarProgresBar(true);
            }
            
        }
        else if (theInput.split("#").length==9 && theInput.split("#")[2].equals("OK_ARTIST_FOR")){
            //PROTOCOLCRISTOFY1.0#<time_origen>#OK_ARTIST_FOR#<user_login>#WITH_TOKEN#<token>#<nombre_artista>#<n_songs>#<data_song1>@<data_song2>@ … <data_songN>
            
            buffer.setNombreArtistaSeleccionado(theInput.split("#")[6]);

            buffer.getDatosCancionesSistema().clear();
            String s = "";
            String [] canciones = (theInput.split("#")[8]).split("@");
            for (String c : canciones){
                String [] auxS = c.split("\\|");
                s = auxS[0] + "|" + auxS[1]+ "|"+ auxS[2]+ "|"+ auxS[3]+ "|"+ auxS[4];
                buffer.getDatosCancionesSistema().add(s);
            }
            buffer.setActualizarMusic(true);
            
        }
        else{
            System.out.println("CRISTOFY-CLIENT-CRISTOFYPROTOCOL-ELSE");
            theOutput = "ERROR";
        }
        return theOutput;
    }
    
    public String prepareLogin (String usserAndPass){
        String mensaje="";
        
        mensaje = "PROTOCOLCRISTOFY1.0#" + 
                LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss")) + 
                "#LOGIN#" + usserAndPass.split("#")[0]+"#"+
                obtenerCadenaEncriptada(usserAndPass.split("#")[1]);
        
        //System.out.println("DEBUG--Pass-->"+obtenerCadenaEncriptada(usserAndPass.split("#")[1]));
        
        
        login = mensaje.split("#")[3];
        
        return mensaje;
    }
    public String obtenerCadenaEncriptada(String cadena) {
        String cadenaEncriptada ="";
        try{
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(cadena.getBytes());
            cadenaEncriptada = Base64.getEncoder().encodeToString(md.digest());
        }
        catch(NoSuchAlgorithmException e){
            //e.printStackTrace();
        }

        return cadenaEncriptada;
    }
    public String prepareCloseSesion (){
        String mensaje="";
        //PROTOCOLCRISTOFY1.0#<time_origen>#BYEBYE#<user_login>#WITH_TOKEN#<token-hash>
        mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#BYEBYE#"+login+"#WITH_TOKEN#"+token;
        
        return mensaje;
    }
    
    public String prepareGetUserConn (){
        String mensaje="";
        //PROTOCOLCRISTOFY1.0#<time_origen>#GET_USERS_CONNECTED#<user_login>#WITH_TOKEN#<token>
        mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#GET_USERS_CONNECTED#"+login+"#WITH_TOKEN#"+token;
        
        return mensaje;
    }
    
    public String prepareGetMusic (){
        String mensaje="";
        //PROTOCOLCRISTOFY1.0#<time_origen>#GET_MUSIC#<user_login>#WITH_TOKEN#<token>
        mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#GET_MUSIC#"+login+"#WITH_TOKEN#"+token;
        
        return mensaje;
    }
    public String prepareGetSong (Long id_song){
        String mensaje="";
        //PROTOCOLCRISTOFY1.0#<time_origen>#GET_SONG#<id_song>#<user_login>#WITH_TOKEN#<token>
        mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#GET_SONG#"+id_song+"#"+login+"#WITH_TOKEN#"+token;
        
        return mensaje;
    }
    
    
    public void escribirArchivoCancion (ArrayList<byte[]> bytes, String idCancion) {
        
        File outputFile = new File("canciones/"+idCancion+".mp3");
        
        FileOutputStream outputStream;
        try {
            
            outputStream = new FileOutputStream(outputFile);

            // Write byte arrays to the output file
            for (byte[] paquete : bytes) {
                outputStream.write(paquete);
            }

            // Close the FileOutputStream
            outputStream.close();
            
        } catch (Exception ex) {
            System.out.println("Error en el cargado de la cancion");
        }
        
    }
    public String prepareGetSearch (String s){
        String mensaje="";
        //PROTOCOLCRISTOFY1.0#<time_origen>#GET_MUSIC_BY_STRING#<cadena_busqueda>#<user_login>#WITH_TOKEN#<token>
        mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+"#GET_MUSIC_BY_STRING#"+
                s+"#"+login+"#WITH_TOKEN#"+token;
        
        return mensaje;
    }
    
    public String prepareGetArtist (Long s){
        String mensaje="";
        //PROTOCOLCRISTOFY1.0#<time_origen>#GET_ARTIST_SONG#<id_song>#<user_login>#WITH_TOKEN#<token>
        
        mensaje = "PROTOCOLCRISTOFY1.0#"+LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"))+
                "#GET_ARTIST_SONG#"+
                s+"#"+login+"#WITH_TOKEN#"+token;
        
        return mensaje;
    }
    
    
    
}

