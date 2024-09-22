package com.example.peliculeitor.actividades;


import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.api.ActorService;
import com.example.peliculeitor.api.SerieService;
import com.example.peliculeitor.bd.BaseDeDatos;
import com.example.peliculeitor.modelos.Actor.Actores;
import com.example.peliculeitor.modelos.Actor.Cast;
import com.example.peliculeitor.modelos.Serie.Details.SerieDetails;
import com.example.peliculeitor.modelos.Serie.Series;
import com.example.peliculeitor.modelos.Serie.Result;
import com.example.peliculeitor.modelos.Vidos.Videos;
import com.example.peliculeitor.ui.adapters.ActorAdapter;
import com.example.peliculeitor.ui.adapters.SerieAdapter;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


public class SerieActivity extends AppCompatActivity {


    private Integer key;


    private Button button;
    private ImageView imageView3;

    private TextView studio;
    private TextView genre;
    private TextView release;

    private RatingBar estrellas;
    private Button buttonBack;
    private RecyclerView recyclerView1;
    private RecyclerView recyclerView2;
    private List<Result> series1;
    private List<Cast> actores;
    private ProgressBar progressBar;

    private TextView seasons;
    private TextView episodes;
    private TextView status;
    private TextView titulo;
    private TextView descripcion;
    private CheckBox buttonFav;
    private String lenguage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vista_media_serie);
        lenguage = getResources().getConfiguration().locale.getLanguage();


        key = getIntent().getIntExtra("key", 0);
        imageView3 = (ImageView) findViewById(R.id.imageView3);
        button = (Button) findViewById(R.id.button);

        studio = (TextView) findViewById(R.id.bi);
        genre = (TextView) findViewById(R.id.genre);
        release = (TextView) findViewById(R.id.release);

        estrellas = (RatingBar) findViewById(R.id.ratingBar2);

        progressBar = (ProgressBar)findViewById(R.id.progressLoading);

        buttonBack = (Button) findViewById(R.id.buttonBack);
        seasons = (TextView) findViewById(R.id.textView25);
        episodes = (TextView) findViewById(R.id.textView27);
        status = (TextView) findViewById(R.id.textView29);
        titulo = (TextView) findViewById(R.id.textView2);
        descripcion = (TextView) findViewById(R.id.textView8);

        buttonFav = (CheckBox) findViewById(R.id.checkBox2);


        buttonBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(SerieService.URL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();


        SerieService servicioSeriesAPI = retrofit.create(SerieService.class);


        Call<SerieDetails> callSerie = servicioSeriesAPI.getSerieById(key, lenguage);



        callSerie.enqueue(new Callback<SerieDetails>() {
            @Override
            public void onResponse(Call<SerieDetails> call, Response<SerieDetails> response) {
                switch(response.code()) {
                    case 200:
                        SerieDetails resultado = response.body();
                        progressBar.setVisibility(View.INVISIBLE);


                        BaseDeDatos bd = new BaseDeDatos (getBaseContext(), "Favoritos", null, 1);
                        if (bd.comprobarFavoritoSerie(key)){
                            buttonFav.setChecked(true);
                        }
                        buttonFav.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                if (buttonFav.isChecked()){
                                    bd.anadirSerieFav(key);
                                }
                                else{
                                    bd.quitarSerieFav(key);
                                }

                            }
                        });

                        Picasso.get().load( "https://image.tmdb.org/t/p/original" + resultado.getPosterPath()).into(imageView3);

                        titulo.setText(resultado.getName());
                        descripcion.setText(resultado.getOverview());


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
                            if (i==resultado.getProductionCompanies().size()-1){
                                aux += ", ";
                            }
                        }
                        studio.setText(aux);


                        release.setText(resultado.getFirstAirDate());


                        estrellas.setRating(Double.valueOf(resultado.getVoteAverage()/2.0).floatValue());

                        Integer num = resultado.getSeasons().size();
                        seasons.setText(num.toString());


                        episodes.setText(resultado.getNumberOfEpisodes().toString());
                        status.setText(resultado.getStatus());



                        button.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                SerieService servicioVideoAPI = retrofit.create(SerieService.class);

                                Call<Videos> callTopVideos = servicioVideoAPI.getVideosSerie(key, lenguage);


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



                        series1 = new ArrayList<>();

                        //Inicialización RecyclerView
                        recyclerView1 = (RecyclerView) findViewById(R.id.recycler_viewCompanies);
                        recyclerView1.setHasFixedSize(false);



                        //Crea el adaptador, pasándole como parámetro los datos
                        final SerieAdapter adaptador1 = new SerieAdapter(series1, new SerieAdapter.OnItemClickListener() {
                            @Override
                            public void onItemClick(Result j) {

                                Intent serieI = new Intent(getBaseContext(), SerieActivity.class);
                                serieI.putExtra("key", j.getId());
                                startActivity(serieI);

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
                                .baseUrl(SerieService.URL)
                                .addConverterFactory(GsonConverterFactory.create())
                                .build();

                        SerieService servicioSerieAPI = retrofit.create(SerieService.class);

                        Call<Series> callTopSeries = servicioSerieAPI.getSeriesSimilares(key, lenguage);


                        callTopSeries.enqueue(new Callback<Series>() {
                            @Override
                            public void onResponse(Call<Series> call, Response<Series> response) {
                                switch(response.code()) {
                                    case 200:

                                        Series resultado = response.body();
                                        series1 = resultado.getResults();

                                        //para que vuelva a renderizar el RecyclerView
                                        adaptador1.setDatos(series1);
                                        adaptador1.notifyDataSetChanged();
                                        break;
                                    case 401:
                                        break;
                                    default:
                                        break;
                                }
                            }

                            @Override
                            public void onFailure(Call<Series> call, Throwable t) {

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

                        Call<Actores> callTopActores = servicioActorAPI.getActoresBySerieId(key, lenguage);


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
            public void onFailure(Call<SerieDetails> call, Throwable t) {

            }
        });


    }
}
