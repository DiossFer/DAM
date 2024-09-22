package com.example.pokemon.api;


import com.example.pokemon.generado.Generado;
import com.example.pokemon.modelos.Resultado;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;
import retrofit2.http.Query;


//TODO: (3) Definimos una interfaz
public interface PokemonService {

    //TODO: (4) Defino en una constante la URL de la API
    final static String POKEMONURL = "https://pokeapi.co/api/v2/";

    //TODO: (5) Defino una función que me devolverá el listado de Pokemons en la URL /pokemon
    @GET("pokemon")
    Call<Resultado> getPokemons();

    @GET("pokemon/{id}")
    Call<Generado> getPokemonById(@Path("id") int id);

    @GET("pokemon")
    Call<Resultado> getPokemonsPostId(@Query("limit") int limit, @Query("offset") int offset);
}