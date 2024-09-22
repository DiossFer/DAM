package com.example.peliculeitor.bd;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

import java.util.ArrayList;

public class BaseDeDatos extends SQLiteOpenHelper {

    private final String NOMBRE_TABLA_PELICULAS_FAV="PeliculasFavoritas";
    private final String NOMBRE_TABLA_SERIES_FAV="SeriesFavoritas";
    private final String NOMBRE_COLUMNA_PELICULAS_FAVORITAS="IdPeliculaFav";
    private final String NOMBRE_COLUMNA_SERIES_FAVORITAS="IdSerieFav";

    public BaseDeDatos(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {

        // Crear la tabla de peliculas favoritas

        String CREATE_TABLE_PELICULAS_FAVORITAS =
                "CREATE TABLE " + NOMBRE_TABLA_PELICULAS_FAV + "(" +
                        NOMBRE_COLUMNA_PELICULAS_FAVORITAS + " INTEGER PRIMARY KEY" +
                        ")";

        // Crear la tabla de series favoritas

        String CREATE_TABLE_SERIES_FAVORITAS =
                "CREATE TABLE " + NOMBRE_TABLA_SERIES_FAV + "(" +
                        NOMBRE_COLUMNA_SERIES_FAVORITAS + " INTEGER PRIMARY KEY" +
                        ")";

        db.execSQL(CREATE_TABLE_PELICULAS_FAVORITAS);

        db.execSQL(CREATE_TABLE_SERIES_FAVORITAS);

    }
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }

    public void anadirPeliFav(int idPelicula) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(NOMBRE_COLUMNA_PELICULAS_FAVORITAS, idPelicula);
        db.insert(NOMBRE_TABLA_PELICULAS_FAV, null, values);
        db.close();
    }

    public void quitarPeliFav(int idPelicula) {
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(NOMBRE_TABLA_PELICULAS_FAV, NOMBRE_COLUMNA_PELICULAS_FAVORITAS + " = ?", new String[]{String.valueOf(idPelicula)});
        db.close();

    }

    public boolean comprobarFavoritoPelicula(int idPelicula){
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + NOMBRE_TABLA_PELICULAS_FAV, null);
        Boolean encontrado = false;
        if (cursor.moveToFirst()) {
            do {
                int idPeli = cursor.getInt(cursor.getColumnIndex(NOMBRE_COLUMNA_PELICULAS_FAVORITAS));

                if(idPeli == idPelicula){
                    encontrado = true;
                }
            } while (cursor.moveToNext());
        }

        cursor.close();
        return encontrado;
    }


    public void anadirSerieFav(int idSerie) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(NOMBRE_COLUMNA_SERIES_FAVORITAS, idSerie);
        db.insert(NOMBRE_TABLA_SERIES_FAV, null, values);
        db.close();
    }

    public void quitarSerieFav(int idSerie) {
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(NOMBRE_TABLA_SERIES_FAV, NOMBRE_COLUMNA_SERIES_FAVORITAS + " = ?", new String[]{String.valueOf(idSerie)});
        db.close();

    }

    public boolean comprobarFavoritoSerie(int id){
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + NOMBRE_TABLA_SERIES_FAV, null);
        Boolean encontrado = false;
        if (cursor.moveToFirst()) {
            do {
                int idSerie = cursor.getInt(cursor.getColumnIndex(NOMBRE_COLUMNA_SERIES_FAVORITAS));

                if(idSerie == id){
                    encontrado = true;
                }
            } while (cursor.moveToNext());
        }

        cursor.close();
        return encontrado;
    }



    public ArrayList<Integer> getPeliculasFavoritas() {
        ArrayList<Integer> peliculasFavoritas = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + NOMBRE_TABLA_PELICULAS_FAV, null);

        if (cursor.moveToFirst()) {
            do {

                int idPelicula = cursor.getInt(cursor.getColumnIndex(NOMBRE_COLUMNA_PELICULAS_FAVORITAS));
                peliculasFavoritas.add(idPelicula);

            } while (cursor.moveToNext());
        }

        cursor.close();
        return peliculasFavoritas;
    }

    public ArrayList<Integer> getSeriesFavoritas() {
        ArrayList<Integer> seriesFavoritas = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + NOMBRE_TABLA_SERIES_FAV, null);

        if (cursor.moveToFirst()) {
            do {

                int idSerie = cursor.getInt(cursor.getColumnIndex(NOMBRE_COLUMNA_SERIES_FAVORITAS));
                seriesFavoritas.add(idSerie);

            } while (cursor.moveToNext());
        }

        cursor.close();
        return seriesFavoritas;
    }
}