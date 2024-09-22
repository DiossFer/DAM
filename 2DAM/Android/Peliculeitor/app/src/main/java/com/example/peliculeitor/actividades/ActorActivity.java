package com.example.peliculeitor.actividades;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.api.ActorService;
import com.example.peliculeitor.api.MovieService;
import com.example.peliculeitor.api.SerieService;
import com.example.peliculeitor.modelos.Actor.Details.ActorDetails;

import com.example.peliculeitor.modelos.Actor.Movie.CastMovieActor;
import com.example.peliculeitor.modelos.Actor.Movie.MoviesActor;
import com.example.peliculeitor.modelos.Actor.Serie.CastSerieActor;
import com.example.peliculeitor.modelos.Actor.Serie.SeriesActor;
import com.example.peliculeitor.modelos.Pelicula.Details.MovieDetails;
import com.example.peliculeitor.modelos.Pelicula.Movie;
import com.example.peliculeitor.modelos.Pelicula.Result;
import com.example.peliculeitor.modelos.Vidos.Videos;
import com.example.peliculeitor.ui.adapters.ActorMoviesAdapter;
import com.example.peliculeitor.ui.adapters.ActorSerieAdapter;
import com.example.peliculeitor.ui.adapters.PeliculaAdapter;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class ActorActivity extends AppCompatActivity {


    String lenguage;
    private int key;
    private ImageView imagen;
    private TextView t8;
    private TextView t12;
    private TextView t14;
    private TextView t16;
    private TextView t18;

    private TextView bi;

    private RecyclerView recyclerView1;
    private RecyclerView recyclerView2;

    private List<CastMovieActor> peliculas1;
    private List<CastSerieActor> series1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vista_actor);

        lenguage = getResources().getConfiguration().locale.getLanguage();


        imagen = (ImageView) findViewById(R.id.imageView3);

        t8 = (TextView) findViewById(R.id.textView8);
        t12 = (TextView) findViewById(R.id.textView12);
        t14 = (TextView) findViewById(R.id.textView14);
        t16 = (TextView) findViewById(R.id.textView16);
        t18 = (TextView) findViewById(R.id.textView18);
        bi = (TextView) findViewById(R.id.bi);

        recyclerView1 = (RecyclerView) findViewById(R.id.moviesActors);
        recyclerView1.setHasFixedSize(false);

        recyclerView2 = (RecyclerView) findViewById(R.id.seriesActors);
        recyclerView2.setHasFixedSize(false);


        key = getIntent().getIntExtra("key", 0);




        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(ActorService.URL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();


        ActorService servicioActorAPI = retrofit.create(ActorService.class);


        Call<ActorDetails> callPelicula = servicioActorAPI.getActorById(key, lenguage);



        callPelicula.enqueue(new Callback<ActorDetails>() {
            @Override
            public void onResponse(Call<ActorDetails> call, Response<ActorDetails> response) {
                switch(response.code()) {
                    case 200:
                        ActorDetails resultado = response.body();

                        Picasso.get().load( "https://image.tmdb.org/t/p/original" + resultado.getProfilePath()).into(imagen);

                        t8.setText(resultado.getBirthday());
                        t12.setText(resultado.getPlaceOfBirth());
                        t14.setText(resultado.getPopularity().toString());
                        t16.setText(resultado.getKnownForDepartment());
                        String aux="";
                        for (int i=0; i<resultado.getAlsoKnownAs().size(); i++){
                            aux+= resultado.getAlsoKnownAs().get(i);
                            if (i==resultado.getAlsoKnownAs().size()-1){
                                aux += ", ";
                            }
                        }

                        t18.setText(aux);

                        bi.setText(resultado.getBiography());





                        peliculas1 = new ArrayList<>();





                        //Crea el adaptador, pasándole como parámetro los datos
                        final ActorMoviesAdapter adaptadorMA = new ActorMoviesAdapter(peliculas1, new ActorMoviesAdapter.OnItemClickListener() {
                            @Override
                            public void onItemClick(CastMovieActor j) {
                                Intent peliculaI = new Intent(getBaseContext(), PeliculaActivity.class);
                                peliculaI.putExtra("key", j.getId());
                                startActivity(peliculaI);

                            }
                        });



                        //Asocia a recylerView el adaptador
                        recyclerView1.setAdapter(adaptadorMA);

                        //Fija un layout linear al recyclerview
                        recyclerView1.setLayoutManager(new LinearLayoutManager(getBaseContext(),LinearLayoutManager.HORIZONTAL,false));

                        //Pone una división entre items
                        recyclerView1.addItemDecoration(
                                new DividerItemDecoration(getBaseContext(),DividerItemDecoration.HORIZONTAL));
                        // Pone la animación por defecto
                        recyclerView1.setItemAnimator(new DefaultItemAnimator());

                        //y el conversor que vamos a usar
                        Retrofit retrofit = new Retrofit.Builder()
                                .baseUrl(MovieService.URL)
                                .addConverterFactory(GsonConverterFactory.create())
                                .build();

                        MovieService servicioPeliculaAPI = retrofit.create(MovieService.class);

                        Call<MoviesActor> callPeliculas = servicioPeliculaAPI.getMovieByActor(key, lenguage);


                        callPeliculas.enqueue(new Callback<MoviesActor>() {
                            @Override
                            public void onResponse(Call<MoviesActor> call, Response<MoviesActor> response) {
                                switch(response.code()) {
                                    case 200:

                                        MoviesActor resultado = response.body();
                                        peliculas1 = resultado.getCast();

                                        //para que vuelva a renderizar el RecyclerView
                                        adaptadorMA.setDatos(peliculas1);
                                        adaptadorMA.notifyDataSetChanged();
                                        break;
                                    case 401:
                                        break;
                                    default:
                                        break;
                                }
                            }

                            @Override
                            public void onFailure(Call<MoviesActor> call, Throwable t) {

                            }
                        });




                        series1 = new ArrayList<>();





                        //Crea el adaptador, pasándole como parámetro los datos
                        final ActorSerieAdapter adaptadorMS = new ActorSerieAdapter(series1, new ActorSerieAdapter.OnItemClickListener() {
                            @Override
                            public void onItemClick(CastSerieActor j) {

                                Intent peliculaI = new Intent(getBaseContext(), SerieActivity.class);
                                peliculaI.putExtra("key", j.getId());
                                startActivity(peliculaI);

                            }
                        });



                        //Asocia a recylerView el adaptador
                        recyclerView2.setAdapter(adaptadorMS);

                        //Fija un layout linear al recyclerview
                        recyclerView2.setLayoutManager(new LinearLayoutManager(getBaseContext(),LinearLayoutManager.HORIZONTAL,false));

                        //Pone una división entre items
                        recyclerView2.addItemDecoration(
                                new DividerItemDecoration(getBaseContext(),DividerItemDecoration.HORIZONTAL));
                        // Pone la animación por defecto
                        recyclerView2.setItemAnimator(new DefaultItemAnimator());



                        SerieService servicioSerieAPI = retrofit.create(SerieService.class);

                        Call<SeriesActor> callSeries = servicioSerieAPI.getSeriesByActor(key, lenguage);


                        callSeries.enqueue(new Callback<SeriesActor>() {
                            @Override
                            public void onResponse(Call<SeriesActor> call, Response<SeriesActor> response) {
                                switch(response.code()) {
                                    case 200:

                                        SeriesActor resultado = response.body();
                                        series1 = resultado.getCast();

                                        //para que vuelva a renderizar el RecyclerView
                                        adaptadorMS.setDatos(series1);
                                        adaptadorMS.notifyDataSetChanged();
                                        break;
                                    case 401:
                                        break;
                                    default:
                                        break;
                                }
                            }

                            @Override
                            public void onFailure(Call<SeriesActor> call, Throwable t) {

                            }
                        });






                        break;
                    case 401:
                        break;
                    default:
                        break;
                }
            }

            @Override
            public void onFailure(Call<ActorDetails> call, Throwable t) {

            }
        });

    }
}
