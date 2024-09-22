/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristofyclient;

import com.mycompany.cristofyclient.vista.VentanaClient;
import java.io.IOException;

/**
 *
 * @author DiosFer
 */
public class Main {
    
    public static void main(String[] args) throws IOException {

        
        VentanaClient v1;
        
        try{
            v1 = new VentanaClient();
            v1.setVisible(true);
        }
        catch(Exception e){
            //e.printStackTrace();
        }  
    }
         
    
}
