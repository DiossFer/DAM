package com.example.pokemon;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.example.pokemon.api.PokemonService;
import com.example.pokemon.modelos.Resultado;
import com.example.pokemon.modelos.Pokemon;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.*;

public class MainActivity extends AppCompatActivity {

    RecyclerView recyclerView;
    List<Pokemon> pokemons;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //TODO: (6) Inicializo datos a vacío
        pokemons = new ArrayList<Pokemon>();

        //Inicialización RecyclerView
        recyclerView = (RecyclerView) findViewById(R.id.RecView);
        recyclerView.setHasFixedSize(false);

        //Crea el adaptador, pasándole como parámetro los datos
        final PokemonAdapter adaptador = new PokemonAdapter(pokemons, new PokemonAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(Pokemon j) {
                Log.i("aaaaa", "POKEMOOON");
                Intent pokemonEspecifico = new Intent(getBaseContext(), PokemonEspecifico.class);
                pokemonEspecifico.putExtra("URL_pokemon", j.getUrl().substring(26));
                startActivity(pokemonEspecifico);

            }
        });

        //Asocia a recylerView el adaptador
        recyclerView.setAdapter(adaptador);

        //Fija un layout linear al recyclerview
        recyclerView.setLayoutManager(new LinearLayoutManager(this,LinearLayoutManager.VERTICAL,false));

        //Pone una división entre items
        recyclerView.addItemDecoration(
                new DividerItemDecoration(this,DividerItemDecoration.VERTICAL));
        // Pone la animación por defecto
        recyclerView.setItemAnimator(new DefaultItemAnimator());

        //TODO: (7) Creo una instancia de la clase Retrofit, a la que le indico la URL de la API
        //y el conversor que vamos a usar
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(PokemonService.POKEMONURL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        //TODO: (8) Creo un objeto del servicio Pokemon
        PokemonService servicioPokemonAPI = retrofit.create(PokemonService.class);

        //TODO: (9) Creo que un objeto de llamada a la función
        Call<Resultado> callPokemons = servicioPokemonAPI.getPokemons();

        //TODO: (10) Ese objeto lo encolo, para que se ejecute de forma asíncrona
        callPokemons.enqueue(new Callback<Resultado>() {
            @Override
            public void onResponse(Call<Resultado> call, Response<Resultado> response) {
                switch(response.code()) {
                    case 200:
                        //TODO: (11) En caso de que haya éxito en la respuesta, extraigo el campo result, mediante getPokemons
                        Resultado resultado = response.body();
                        pokemons = resultado.getPokemons();
                        //TODO: (12) Cambio los datos del adaptador, que hasta ahora eran vacíos, y notifico que han cambiado
                        //para que vuelva a renderizar el RecyclerView
                        adaptador.setDatos(pokemons);
                        adaptador.notifyDataSetChanged();
                        break;
                    case 401:
                        break;
                    default:
                        break;
                }
            }

            @Override
            public void onFailure(Call<Resultado> call, Throwable t) {

            }
        });
        recyclerView.addOnScrollListener(new RecyclerView.OnScrollListener() {
            @Override
            public void onScrolled(RecyclerView recyclerView, int dx, int dy) {
                super.onScrolled(recyclerView, dx, dy);

                Retrofit retrofit = new Retrofit.Builder()
                        .baseUrl(PokemonService.POKEMONURL)
                        .addConverterFactory(GsonConverterFactory.create())
                        .build();

                //TODO: (8) Creo un objeto del servicio Pokemon
                PokemonService servicioPokemonAPI = retrofit.create(PokemonService.class);

                //TODO: (9) Creo que un objeto de llamada a la función
                Call<Resultado> callPokemons = servicioPokemonAPI.getPokemonsPostId(20, 20);

                //TODO: (10) Ese objeto lo encolo, para que se ejecute de forma asíncrona
                callPokemons.enqueue(new Callback<Resultado>() {
                    @Override
                    public void onResponse(Call<Resultado> call, Response<Resultado> response) {
                        switch(response.code()) {
                            case 200:
                                //TODO: (11) En caso de que haya éxito en la respuesta, extraigo el campo result, mediante getPokemons
                                Resultado resultado = response.body();
                                pokemons = resultado.getPokemons();
                                //TODO: (12) Cambio los datos del adaptador, que hasta ahora eran vacíos, y notifico que han cambiado
                                //para que vuelva a renderizar el RecyclerView
                                adaptador.setDatos(pokemons);

                                adaptador.notifyDataSetChanged();//cambiar el set datos a un add datos y poner la funcion en la primer ir llamando de 20 en 20
                                break;
                            case 401:
                                break;
                            default:
                                break;
                        }
                    }

                    @Override
                    public void onFailure(Call<Resultado> call, Throwable t) {

                    }
                });
















            }
        });

    }
}