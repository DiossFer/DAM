package com.example.peliculeitor.ui.Peliculas;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ProgressBar;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.actividades.PeliculaActivity;
import com.example.peliculeitor.api.MovieService;
import com.example.peliculeitor.modelos.Pelicula.Result;
import com.example.peliculeitor.modelos.Pelicula.Movie;
import com.example.peliculeitor.ui.adapters.PeliculaAdapter;
import com.example.peliculeitor.ui.adapters.PeliculaBusquedaAdapter;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


public class PeliculasFragment extends Fragment {

    private RecyclerView recyclerView1;
    private RecyclerView recyclerView2;
    private List<Result> peliculas1;
    private List<Result> peliculas2;
    private ProgressBar progressBar;
    private EditText barraBusqueda;
    private List<Result> peliculas3;
    private RecyclerView recyclerView3;
    private RecyclerView cuadroBusqueda;
    private String lenguage;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.fragment_media_final, container, false);

        lenguage = getResources().getConfiguration().locale.getLanguage();


        peliculas1 = new ArrayList<Result>();
        peliculas2 = new ArrayList<Result>();
        peliculas3 = new ArrayList<Result>();


        progressBar = (ProgressBar) root.findViewById(R.id.progressBar);


        //Inicialización RecyclerView
        recyclerView1 = (RecyclerView) root.findViewById(R.id.recycler_view);
        recyclerView1.setHasFixedSize(false);

        recyclerView3 = (RecyclerView) root.findViewById(R.id.recycler_view_busqueda);
        recyclerView3.setHasFixedSize(false);

        barraBusqueda = (EditText) root.findViewById(R.id.editText);
        cuadroBusqueda = (RecyclerView) root.findViewById(R.id.recycler_view_busqueda);


        //Crea el adaptador, pasándole como parámetro los datos
        final PeliculaAdapter adaptador1 = new PeliculaAdapter(peliculas1, new PeliculaAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(Result j) {

                Intent peliculaI = new Intent(PeliculasFragment.this.getContext(), PeliculaActivity.class);
                peliculaI.putExtra("key", j.getId());
                startActivity(peliculaI);

            }
        });



        //Asocia a recylerView el adaptador
        recyclerView1.setAdapter(adaptador1);

        //Fija un layout linear al recyclerview
        recyclerView1.setLayoutManager(new LinearLayoutManager(this.getContext(),LinearLayoutManager.HORIZONTAL,false));

        //Pone una división entre items
        recyclerView1.addItemDecoration(
                new DividerItemDecoration(this.getContext(),DividerItemDecoration.HORIZONTAL));
        // Pone la animación por defecto
        recyclerView1.setItemAnimator(new DefaultItemAnimator());




        //Inicialización RecyclerView
        recyclerView2 = (RecyclerView) root.findViewById(R.id.recycler_view2);
        recyclerView2.setHasFixedSize(false);

        //Crea el adaptador, pasándole como parámetro los datos
        final PeliculaAdapter adaptador2 = new PeliculaAdapter(peliculas2, new PeliculaAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(Result j) {

                Intent peliculaI = new Intent(getContext(), PeliculaActivity.class);
                peliculaI.putExtra("key", j.getId());
                startActivity(peliculaI);

            }
        });



        //Asocia a recylerView el adaptador
        recyclerView2.setAdapter(adaptador2);

        //Fija un layout linear al recyclerview
        recyclerView2.setLayoutManager(new LinearLayoutManager(this.getContext(),LinearLayoutManager.HORIZONTAL,false));

        //Pone una división entre items
        recyclerView2.addItemDecoration(
                new DividerItemDecoration(this.getContext(),DividerItemDecoration.HORIZONTAL));
        // Pone la animación por defecto
        recyclerView2.setItemAnimator(new DefaultItemAnimator());




        //y el conversor que vamos a usar
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl(MovieService.URL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        MovieService servicioPeliculaAPI = retrofit.create(MovieService.class);

        Call<Movie> callTopPeliculas = servicioPeliculaAPI.getTopRatedPeliculas(lenguage);

        Call<Movie> callPopularPeliculas = servicioPeliculaAPI.getPopularsPeliculas(lenguage);


        callTopPeliculas.enqueue(new Callback<Movie>() {
            @Override
            public void onResponse(Call<Movie> call, Response<Movie> response) {
                switch(response.code()) {
                    case 200:
                        progressBar.setVisibility(View.INVISIBLE);

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

        callPopularPeliculas.enqueue(new Callback<Movie>() {
            @Override
            public void onResponse(Call<Movie> call, Response<Movie> response) {
                switch(response.code()) {
                    case 200:
                        progressBar.setVisibility(View.INVISIBLE);

                        Movie resultado = response.body();
                        peliculas2 = resultado.getResults();

                        //para que vuelva a renderizar el RecyclerView
                        adaptador2.setDatos(peliculas2);
                        adaptador2.notifyDataSetChanged();
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



        barraBusqueda.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int start, int before, int count) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int start, int before, int count) {

            }

            @Override
            public void afterTextChanged(Editable editable) {
                if (barraBusqueda.getText().toString().length()>=3){

                    //Crea el adaptador, pasándole como parámetro los datos
                    final PeliculaBusquedaAdapter adaptador3 = new PeliculaBusquedaAdapter(peliculas3, new PeliculaBusquedaAdapter.OnItemClickListener() {
                        @Override
                        public void onItemClick(Result j) {

                            Intent peliculaI = new Intent(PeliculasFragment.this.getContext(), PeliculaActivity.class);
                            peliculaI.putExtra("key", j.getId());
                            startActivity(peliculaI);

                        }
                    });



                    //Asocia a recylerView el adaptador
                    recyclerView3.setAdapter(adaptador3);

                    //Fija un layout linear al recyclerview
                    recyclerView3.setLayoutManager(new LinearLayoutManager(getContext(),LinearLayoutManager.VERTICAL,false));

                    //Pone una división entre items
                    recyclerView3.addItemDecoration(
                            new DividerItemDecoration(getContext(),DividerItemDecoration.VERTICAL));
                    // Pone la animación por defecto
                    recyclerView3.setItemAnimator(new DefaultItemAnimator());



                    Call<Movie> callResultadosBusquedaPeliculas = servicioPeliculaAPI.getSearchMovie(barraBusqueda.getText().toString(), lenguage);


                    callResultadosBusquedaPeliculas.enqueue(new Callback<Movie>() {
                        @Override
                        public void onResponse(Call<Movie> call, Response<Movie> response) {
                            switch(response.code()) {
                                case 200:
                                    cuadroBusqueda.setVisibility(View.VISIBLE);

                                    Movie resultado = response.body();
                                    peliculas3 = resultado.getResults();

                                    //para que vuelva a renderizar el RecyclerView
                                    adaptador3.setDatos(peliculas3);

                                    adaptador3.notifyDataSetChanged();
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


                }
                else{
                    cuadroBusqueda.setVisibility(View.INVISIBLE);

                }
            }
        });



        return root;
    }


}