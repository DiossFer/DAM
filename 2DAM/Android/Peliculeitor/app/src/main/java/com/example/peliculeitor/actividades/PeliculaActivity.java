package com.example.peliculeitor.actividades;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.api.ActorService;
import com.example.peliculeitor.api.MovieService;

import com.example.peliculeitor.bd.BaseDeDatos;
import com.example.peliculeitor.modelos.Actor.Actores;
import com.example.peliculeitor.modelos.Actor.Cast;
import com.example.peliculeitor.modelos.Pelicula.Details.MovieDetails;
import com.example.peliculeitor.modelos.Pelicula.Movie;
import com.example.peliculeitor.modelos.Pelicula.Result;
import com.example.peliculeitor.modelos.Vidos.Videos;
import com.example.peliculeitor.ui.adapters.ActorAdapter;
import com.example.peliculeitor.ui.adapters.PeliculaAdapter;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


public class PeliculaActivity extends AppCompatActivity {

    private Integer key;


    private Button button;
    private CheckBox buttonFav;
    private ImageView imageView3;

    private TextView studio;
    private TextView genre;
    private TextView release;
    private TextView titulo;
    private TextView descripcion;

    private RatingBar estrellas;
    private Button buttonBack;
    private RecyclerView recyclerView1;
    private RecyclerView recyclerView2;
    private List<Result> peliculas1;
    private List<Cast> actores;
    private String lenguage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vista_media);

        lenguage = getResources().getConfiguration().locale.getLanguage();

        key = getIntent().getIntExtra("key", 0);
        imageView3 = (ImageView) findViewById(R.id.imageView3);
        button = (Button) findViewById(R.id.button);

        studio = (TextView) findViewById(R.id.bi);
        genre = (TextView) findViewById(R.id.genre);
        release = (TextView) findViewById(R.id.release);
        titulo = (TextView) findViewById(R.id.textView2);
        descripcion = (TextView) findViewById(R.id.textView8);

        estrellas = (RatingBar) findViewById(R.id.ratingBar2);



        buttonBack = (Button) findViewById(R.id.buttonBack);
        buttonFav = (CheckBox) findViewById(R.id.checkBox2);
        buttonBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(MovieService.URL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();


        MovieService servicioMovieAPI = retrofit.create(MovieService.class);


        Call<MovieDetails> callPelicula = servicioMovieAPI.getPeliculaById(key, lenguage);



        callPelicula.enqueue(new Callback<MovieDetails>() {
            @Override
            public void onResponse(Call<MovieDetails> call, Response<MovieDetails> response) {
                switch(response.code()) {
                    case 200:
                        MovieDetails resultado = response.body();

                        BaseDeDatos bd = new BaseDeDatos (getBaseContext(), "Favoritos", null, 1);
                        if (bd.comprobarFavoritoPelicula(key)){
                            buttonFav.setChecked(true);
                        }
                        buttonFav.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                if (buttonFav.isChecked()){
                                    bd.anadirPeliFav(key);
                                }
                                else{
                                    bd.quitarPeliFav(key);
                                }

                            }
                        });

                        Picasso.get().load( "https://image.tmdb.org/t/p/original" + resultado.getPosterPath()).into(imageView3);


                        String aux="";
                        for (int i=0; i<resultado.getGenres().size(); i++){
                            aux+=resultado.getGenres().get(i).getName();
                            if (i==resultado.getGenres().size()-1){
                                aux += ", ";
                            }

                        }
                        genre.setText(aux);

                        aux="";
                        for (int i=0; i<resultado.getProductionCompanies().size(); i++){
                            aux+=resultado.getProductionCompanies().get(i).getName();
                            if (i==resultado.getGenres().size()-1){
                                aux += ", ";
                            }
                        }
                        studio.setText(aux);


                        release.setText(resultado.getReleaseDate());

                        titulo.setText(resultado.getTitle());
                        descripcion.setText(resultado.getOverview());

                        estrellas.setRating(Double.valueOf(resultado.getVoteAverage()/2.0).floatValue());
                        button.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {

                                MovieService servicioVideoAPI = retrofit.create(MovieService.class);

                                Call<Videos> callTopVideos = servicioVideoAPI.getVideosPelicula(key, lenguage);


                                callTopVideos.enqueue(new Callback<Videos>() {
                                    @Override
                                    public void onResponse(Call<Videos> call, Response<Videos> response) {
                                        switch(response.code()) {
                                            case 200:

                                                Videos videos = response.body();
                                                Boolean encontrado=false;
                                                for (int i=0; i<videos.getResults().size() && encontrado==false; i++){
                                                    if (videos.getResults().get(i).getType().equals("Trailer")){
                                                        encontrado=true;
                                                        Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.youtube.com/watch?v=" + videos.getResults().get(i).getKey()));
                                                        startActivity(intent);
                                                    }
                                                }


                                                break;
                                            case 401:
                                                break;
                                            default:
                                                break;
                                        }
                                    }

                                    @Override
                                    public void onFailure(Call<Videos> call, Throwable t) {

                                    }
                                });

                            }
                        });



                        peliculas1 = new ArrayList<>();

                        //Inicialización RecyclerView
                        recyclerView1 = (RecyclerView) findViewById(R.id.recycler_viewCompanies);
                        recyclerView1.setHasFixedSize(false);



                        //Crea el adaptador, pasándole como parámetro los datos
                        final PeliculaAdapter adaptador1 = new PeliculaAdapter(peliculas1, new PeliculaAdapter.OnItemClickListener() {
                            @Override
                            public void onItemClick(Result j) {

                                Intent peliculaI = new Intent(getBaseContext(), PeliculaActivity.class);
                                peliculaI.putExtra("key", j.getId());
                                startActivity(peliculaI);

                            }
                        });



                        //Asocia a recylerView el adaptador
                        recyclerView1.setAdapter(adaptador1);

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

                        Call<Movie> callTopPeliculas = servicioPeliculaAPI.getPeliculasSimilares(key, lenguage);


                        callTopPeliculas.enqueue(new Callback<Movie>() {
                            @Override
                            public void onResponse(Call<Movie> call, Response<Movie> response) {
                                switch(response.code()) {
                                    case 200:

                                        Movie resultado = response.body();
                                        peliculas1 = resultado.getResults();

                                        //para que vuelva a renderizar el RecyclerView
                                        adaptador1.setDatos(peliculas1);
                                        adaptador1.notifyDataSetChanged();
                                        break;
                                    case 401:
                                        break;
                                    default:
                                        break;
                                }
                            }

                            @Override
                            public void onFailure(Call<Movie> call, Throwable t) {

                            }
                        });

                        actores = new ArrayList<>();

                        //Inicialización RecyclerView
                        recyclerView2 = (RecyclerView) findViewById(R.id.recycler_view2);
                        recyclerView2.setHasFixedSize(false);

                        //Crea el adaptador, pasándole como parámetro los datos
                        final ActorAdapter adaptador2 = new ActorAdapter(actores, new ActorAdapter.OnItemClickListener() {
                            @Override
                            public void onItemClick(Cast j) {

                                Intent actor = new Intent(getBaseContext(), ActorActivity.class);
                                actor.putExtra("key", j.getId());
                                startActivity(actor);

                            }
                        });



                        //Asocia a recylerView el adaptador
                        recyclerView2.setAdapter(adaptador2);

                        //Fija un layout linear al recyclerview
                        recyclerView2.setLayoutManager(new LinearLayoutManager(getBaseContext(),LinearLayoutManager.HORIZONTAL,false));

                        //Pone una división entre items
                        recyclerView2.addItemDecoration(
                                new DividerItemDecoration(getBaseContext(),DividerItemDecoration.HORIZONTAL));
                        // Pone la animación por defecto
                        recyclerView2.setItemAnimator(new DefaultItemAnimator());


                        ActorService servicioActorAPI = retrofit.create(ActorService.class);

                        Call<Actores> callTopActores = servicioActorAPI.getActoresByMovieId(key, lenguage);


                        callTopActores.enqueue(new Callback<Actores>() {
                            @Override
                            public void onResponse(Call<Actores> call, Response<Actores> response) {
                                switch(response.code()) {
                                    case 200:

                                        Actores resultado = response.body();
                                        actores = resultado.getCast();

                                        //para que vuelva a renderizar el RecyclerView
                                        adaptador2.setDatos(actores);
                                        adaptador2.notifyDataSetChanged();
                                        break;
                                    case 401:
                                        break;
                                    default:
                                        break;
                                }
                            }

                            @Override
                            public void onFailure(Call<Actores> call, Throwable t) {

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
            public void onFailure(Call<MovieDetails> call, Throwable t) {

            }
        });


    }
}
