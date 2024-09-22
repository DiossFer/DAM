package com.mycompany.cristofyclient;

/**
 *
 * @author DiosFer
 */
public class Controller {
    
    Buffer buffer;
    
    HebraCristofyClient client;
    
    public Controller (Buffer b){
        buffer = b;
    }
    
    public void establecerConexion (){
        client = new HebraCristofyClient(buffer);
        client.iniciar();
    }
    
}
