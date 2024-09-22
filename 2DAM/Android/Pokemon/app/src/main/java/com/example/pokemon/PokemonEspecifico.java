package com.example.pokemon;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.pokemon.api.PokemonService;
import com.example.pokemon.generado.Generado;
import com.example.pokemon.modelos.Resultado;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class PokemonEspecifico extends AppCompatActivity {
    TextView t1;
    TextView t2;
    TextView t3;
    Generado pokemon;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pokemon_especifico);

        t1 = findViewById(R.id.t1);
        t2 = findViewById(R.id.t2);
        t3 = findViewById(R.id.t3);

        String URL_pokemon = getIntent().getStringExtra("URL_pokemon");
        int id = Integer.parseInt(URL_pokemon.substring(8, URL_pokemon.length()-1));



        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(PokemonService.POKEMONURL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();


        PokemonService servicioPokemonAPI = retrofit.create(PokemonService.class);


        Call<Generado> callPokemons = servicioPokemonAPI.getPokemonById(id);


        callPokemons.enqueue(new Callback<Generado>() {
            @Override
            public void onResponse(Call<Generado> call, Response<Generado> response) {
                switch(response.code()) {
                    case 200:

                        Generado resultado = response.body();

                        t1.setText("Nombre: "+resultado.getName());
                        t2.setText("Altura: "+Integer.toString(resultado.getHeight()));
                        t3.setText("Peso: "+Integer.toString(resultado.getWeight()));
                        break;
                    case 401:
                        break;
                    default:
                        break;
                }
            }

            @Override
            public void onFailure(Call<Generado> call, Throwable t) {

            }
        });




    }

}