package com.mycompany.pruebabdxml;

import java.util.ArrayList;
import java.util.List;
import org.xmldb.api.base.*;
import org.xmldb.api.modules.*;
import org.xmldb.api.*;
import org.exist.xmldb.EXistResource;


/**
 *
 * @author diosfer
 */
public class PruebaBDXML {

    private static final String URI = "xmldb:exist://localhost:8080/exist/xmlrpc/db/PruebaXML";
        
    private static final String collection = "/Perfiles";
    
    private static List<Perfil> perfilesSistema;
    
    public static void main(String[] args) throws Exception{
        
        // Driver
        final String driver = "org.exist.xmldb.DatabaseImpl";
        
        // initialize database driver
        Class cl = Class.forName(driver);
        Database database = (Database) cl.newInstance();
        database.setProperty("create-database", "true");
        DatabaseManager.registerDatabase(database);
        
        // Coleccion que obtendremos
        Collection col = null;
        
        try {
            
            // Obtenemos la coleccion
            col = DatabaseManager.getCollection(URI+collection, "admin", "contrasenia1234");
            
            
            /// LECTURA ///
            
            // Obtenemos los perfiles de la coleccion a traves del metodo
            perfilesSistema = getPerfilesFromCollection(col);
            
            /// DEBUG Comprobamos que se hallan obtenido los perfiles
            for (Perfil p : perfilesSistema){
                System.out.println(p);
            }
            

            /// INSERTADO ///
            
            // Creamos un nuevo perfil
            
            System.out.println("Insertamos un nuevo perfil");
            
            Perfil newp = new Perfil ("nuevoPerfilLogin", "nuevoPerfilContrasenia", "nuevoPerfilUserName", "nuevoPerfilEmail");
            
            setNewPerfilToCollection(col, newp);
            
            
            /// MODIFICADO ///
            
            System.out.println("Modificamos el perfil perfiamente añadido");
            
            Perfil pmod = newp;
            pmod.setLogin("loginMod");
            pmod.setPasword("contraseniaMod");
            pmod.setEmail("emailMod");
            pmod.setNombreUsuario("userNameMod");
            
            savePerfilToCollection(col, pmod);
            
            /// ELIMINADO ///
            
            System.out.println("Eliminamos el perfil perfiamente modificado");

            Perfil pdel = pmod;
            deletePerfilToCollection(col, pdel);
            
        }
        catch (Exception e){
            e.printStackTrace();
        }
        finally {
            //Cerramos la coleccion
            if(col != null) {
                //Cerramos la coleccion
                try { col.close(); } catch(XMLDBException xe) {xe.printStackTrace();}
            }
        }
    }
    
    public static List<Perfil> getPerfilesFromCollection (Collection col) throws Exception{
        
        // Leer preparando una consulta de XPath
        XPathQueryService xpqs = (XPathQueryService)col.getService("XPathQueryService", "1.0");
        xpqs.setProperty("indent", "yes");
        
        // Guardaremos los perfiles obtenidos de la consulta
        List<Perfil> perfiles = new ArrayList<>();
        Perfil p;
        
        // Consulta para obtener todos los perfiles de la coleccion
        ResourceSet result = xpqs.query("for $perfil in collection(\"/\")/perfiles/perfil\n"+
        "return concat($perfil/id, ', ', $perfil/login, ', ', $perfil/contrasenia, ', ', $perfil/nombreUsuario, ', ', $perfil/email)");
        
        // Iteramos en el resultado de la consulta
        ResourceIterator i = result.getIterator();
        
        Resource res = null;
        
        while(i.hasMoreResources()) {
            
            try {
                
                // Obtenemos el resultado de la consulta
                res = i.nextResource();
                
                // DEBUG
                //System.out.println("-->"+res.getContent().toString());
                
                // Dividimos el resultado en cada atributo
                String [] datos = res.getContent().toString().split(", ");
                
                // Rellenamos el perfil con los datos obtenidos
                p = new Perfil(Long.parseLong(datos[0].trim()), datos[1].trim(), datos[2].trim(), datos[3].trim(), datos[4].trim());
                
                // Añadimos el perfil al vector                
                perfiles.add(p);
                
            } finally {
                // Limpiamos el resultado
                try { ((EXistResource)res).freeResources(); } catch(XMLDBException xe) {xe.printStackTrace();}
            }
            
        }
        
        // Retornamos los perfiles obtenidos
        return perfiles;
    } 
    
    
    
    public static void setNewPerfilToCollection (Collection col, Perfil newp) throws XMLDBException{
        
        // Obtenemos el xml de perfiles
        XMLResource res = (XMLResource) col.getResource("perfiles.xml");
        
        // Pasamos los perfiles a String para manejarlos
        String perfilesBD = (String) res.getContent();

        // Para agregar el nuevo perfil lo insertamos en el string para mas tarde reemplazzar el archivo
        perfilesBD = perfilesBD.replace("</perfiles>", perfilToXML(newp)+"</perfiles>");
        
        // Reemplazamos el contenido del archivo por el nuevo contenido con el perfil ya insertado
        res.setContent(perfilesBD);
        
        // Guardamos el archivo
        col.storeResource(res);
        
    }
    
    public static void savePerfilToCollection (Collection col, Perfil pmod) throws XMLDBException{
        
        // Obtenemos el xml de perfiles
        XMLResource res = (XMLResource) col.getResource("perfiles.xml");
        
        // Pasamos los perfiles a String para manejarlos
        String perfilesBD = (String) res.getContent();
        
        // reemplazamos el perfil seleccionado por sus nuevos datos
        perfilesBD = perfilesBD.replaceAll("<perfil>[\\s]*?<id>"+pmod.getId()+"</id>[\\s\\S]*?</perfil>", perfilToXML(pmod));
        
        // Reemplazamos el contenido del archivo por el nuevo contenido con el perfil ya modificado
        res.setContent(perfilesBD);
        
        // Guardamos el archivo
        col.storeResource(res);
        
    }
    
    public static void deletePerfilToCollection (Collection col, Perfil pdel) throws XMLDBException{
        
        // Obtenemos el xml de perfiles
        XMLResource res = (XMLResource) col.getResource("perfiles.xml");
        
        // Pasamos los perfiles a String para manejarlos
        String perfilesBD = (String) res.getContent();

        // eliminamos el perfil seleccionado
        perfilesBD = perfilesBD.replaceAll("<perfil>[\\s]*?<id>"+pdel.getId()+"</id>[\\s\\S]*?</perfil>", "");
        
                
        // Reemplazamos el contenido del archivo por el nuevo contenido sin el perfil
        res.setContent(perfilesBD);
        
        // Guardamos el archivo
        col.storeResource(res);
        
    }
    
    
    /**
     * @brief metodo para pasar un perfil a xml 
     * @param perfil
     * @return String perfilxml
     */
    public static String perfilToXML (Perfil perfil){
        String perfilxml="";
        perfilxml+="<perfil>";
        perfilxml+="<id>"+perfil.getId()+"</id>";
        perfilxml+="<login>"+perfil.getLogin()+"</login>";
        perfilxml+="<contrasenia>"+perfil.getPasword()+"</contrasenia>";
        perfilxml+="<nombreUsuario>"+perfil.getNombreUsuario()+"</nombreUsuario>";
        perfilxml+="<email>"+perfil.getEmail()+"</email>";
        perfilxml+="</perfil>";
        return perfilxml;
    }
}

