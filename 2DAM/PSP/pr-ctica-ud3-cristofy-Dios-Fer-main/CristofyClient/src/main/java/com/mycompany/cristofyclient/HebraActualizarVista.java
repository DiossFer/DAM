package com.mycompany.cristofyclient;

import javax.swing.JLabel;
import javax.swing.JProgressBar;
import javax.swing.JTextArea;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author DiosFer
 */
public class HebraActualizarVista implements Runnable {
    
    JTextArea jta;
    Buffer buffer;
    Thread thr;
    String mensaje;
    DefaultTableModel jtmp;
    DefaultTableModel jtmc;
    Reproductor rp = null;
    Boolean estaActivo = true;
    JProgressBar jpb;
    JLabel artistaNombre;
            
    public HebraActualizarVista (Buffer buf, JTextArea j, DefaultTableModel jtmp, DefaultTableModel jtmc, JProgressBar jpb, JLabel artistaNombre){
        this.buffer = buf;
        this.jta=j;
        this.thr = new Thread(this);
        this.jtmp = jtmp;
        this.jtmc = jtmc;
        this.jpb = jpb;
        this.artistaNombre=artistaNombre;
    }
    
    @Override
    public void run (){
        
        
        while (estaActivo){
            this.mensaje="";

            
            buffer.getLock().lock();
            for (String s : this.buffer.getBuffer()){

                this.mensaje+=s;
                this.mensaje+="\n";
            }
            buffer.getLock().unlock();
            
            this.jta.setText(this.mensaje);
            
            
            
            /// Limpiamos la tabla
            if (buffer.getActualizarUsers()){
                buffer.setActualizarUsers(false);
                
                for (int i=jtmp.getRowCount()-1; i>=0; i--){
                    jtmp.removeRow(i);
                }
                for (String auxS : buffer.getDatosPerfilesConectados()){
                    jtmp.addRow(new Object[]{auxS.split("\\|")[0], auxS.split("\\|")[1], auxS.split("\\|")[2], auxS.split("\\|")[3], auxS.split("\\|")[4]});
                }
            }
            /// Limpiamos la tabla
            if (buffer.getActualizarMusic()){
                buffer.setActualizarMusic(false);
                
                for (int i=jtmc.getRowCount()-1; i>=0; i--){
                    jtmc.removeRow(i);
                }
                for (String auxS : buffer.getDatosCancionesSistema()){
                    jtmc.addRow(new Object[]{auxS.split("\\|")[0], auxS.split("\\|")[1], auxS.split("\\|")[2], auxS.split("\\|")[3], auxS.split("\\|")[4]});
                }
            }
            
            artistaNombre.setText(buffer.getNombreArtistaSeleccionado());
            
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
            }
            
            if (buffer.getStartCancion()){
                buffer.setStartCancion(false);
                if (rp!=null){
                    rp.stopSong();
                }
                rp = new Reproductor();
                rp.comenzarReproduccion(buffer.getRutaCancionCargada());
            }
            
            
            if (buffer.getActualizarProgresBar()){
                System.out.println("ACTUALIZO PROGRESBAR");
                
                buffer.setActualizarProgresBar(false);
                jpb.setValue(buffer.getProgreso());
            }
        }
    }
    
    public void startActualizacion(){
        this.thr.start();
    }
    public void stopCancion (){
        if (rp!=null){
            rp.stopSong();
        }
    }

    public Boolean getEstaActivo() {
        return estaActivo;
    }

    public void setEstaActivo(Boolean estaActivo) {
        this.estaActivo = estaActivo;
    }
    
    
}
