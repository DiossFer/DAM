package com.example.peliculeitor.ui.Favoritos;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.actividades.PeliculaActivity;
import com.example.peliculeitor.actividades.SerieActivity;
import com.example.peliculeitor.api.MovieService;
import com.example.peliculeitor.api.SerieService;
import com.example.peliculeitor.bd.BaseDeDatos;
import com.example.peliculeitor.modelos.Actor.Movie.CastMovieActor;
import com.example.peliculeitor.modelos.Actor.Movie.MoviesActor;
import com.example.peliculeitor.modelos.Pelicula.Details.MovieDetails;
import com.example.peliculeitor.modelos.Pelicula.Result;
import com.example.peliculeitor.modelos.Serie.Details.SerieDetails;
import com.example.peliculeitor.ui.adapters.ActorMoviesAdapter;
import com.example.peliculeitor.ui.adapters.PeliculaAdapter;
import com.example.peliculeitor.ui.adapters.PeliculaFavoritasAdapter;
import com.example.peliculeitor.ui.adapters.SerieFavoritasAdapter;

import java.util.ArrayList;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


public class FavoritosFragment extends Fragment {
    private RecyclerView recyclerView1;
    private ArrayList<MovieDetails>peliculas1;

    private RecyclerView recyclerView2;
    private ArrayList<SerieDetails>series1;
    private String lenguage;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.fragment_favoritos, container, false);

        lenguage = getResources().getConfiguration().locale.getLanguage();

        BaseDeDatos bd = new BaseDeDatos (getContext(), "Favoritos", null, 1);

        recyclerView1 = (RecyclerView) root.findViewById(R.id.recycler_view);
        peliculas1 = new ArrayList<>();

        recyclerView2 = (RecyclerView) root.findViewById(R.id.recycler_view2);
        series1 = new ArrayList<>();



        //Crea el adaptador, pasándole como parámetro los datos
        final PeliculaFavoritasAdapter adaptador1 = new PeliculaFavoritasAdapter(peliculas1, new PeliculaFavoritasAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(MovieDetails j) {
                Intent peliculaI = new Intent(root.getContext(), PeliculaActivity.class);
                peliculaI.putExtra("key", j.getId());
                startActivity(peliculaI);

            }
        });


        //Asocia a recylerView el adaptador
        recyclerView1.setAdapter(adaptador1);

        //Fija un layout linear al recyclerview
        recyclerView1.setLayoutManager(new LinearLayoutManager(getContext(),LinearLayoutManager.HORIZONTAL,false));

        //Pone una división entre items
        recyclerView1.addItemDecoration(
                new DividerItemDecoration(getContext(),DividerItemDecoration.HORIZONTAL));

        // Pone la animación por defecto
        recyclerView1.setItemAnimator(new DefaultItemAnimator());


        //Crea el adaptador, pasándole como parámetro los datos
        final SerieFavoritasAdapter adaptador2 = new SerieFavoritasAdapter(series1, new SerieFavoritasAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(SerieDetails j) {
                Intent serieI = new Intent(root.getContext(), SerieActivity.class);
                serieI.putExtra("key", j.getId());
                startActivity(serieI);

            }
        });


        //Asocia a recylerView el adaptador
        recyclerView2.setAdapter(adaptador2);

        //Fija un layout linear al recyclerview
        recyclerView2.setLayoutManager(new LinearLayoutManager(getContext(),LinearLayoutManager.HORIZONTAL,false));

        //Pone una división entre items
        recyclerView2.addItemDecoration(
                new DividerItemDecoration(getContext(),DividerItemDecoration.HORIZONTAL));

        // Pone la animación por defecto
        recyclerView2.setItemAnimator(new DefaultItemAnimator());

        //y el conversor que vamos a usar
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(MovieService.URL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        MovieService servicioPeliculaAPI = retrofit.create(MovieService.class);


        ArrayList<Integer> peliculasFavoritasID = bd.getPeliculasFavoritas();



        for (int num=0; num < peliculasFavoritasID.size();num++){
            Call<MovieDetails> callPeliculas = servicioPeliculaAPI.getPeliculaById(peliculasFavoritasID.get(num), lenguage);

            callPeliculas.enqueue(new Callback<MovieDetails>() {
                @Override
                public void onResponse(Call<MovieDetails> call, Response<MovieDetails> response) {
                    switch(response.code()) {
                        case 200:

                            MovieDetails resultado = response.body();

                            peliculas1.add(resultado);

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
                public void onFailure(Call<MovieDetails> call, Throwable t) {

                }
            });

        }


            SerieService servicioSerieAPI = retrofit.create(SerieService.class);


            ArrayList<Integer> seriesFavoritasID = bd.getSeriesFavoritas();


            for (int num2=0; num2 < seriesFavoritasID.size();num2++) {
                Call<SerieDetails> callSeries = servicioSerieAPI.getSerieById(seriesFavoritasID.get(num2), lenguage);

                callSeries.enqueue(new Callback<SerieDetails>() {
                    @Override
                    public void onResponse(Call<SerieDetails> call, Response<SerieDetails> response) {
                        switch (response.code()) {
                            case 200:

                                SerieDetails resultado = response.body();

                                series1.add(resultado);

                                //para que vuelva a renderizar el RecyclerView
                                adaptador2.setDatos(series1);
                                adaptador2.notifyDataSetChanged();
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




        return root;
    }


}