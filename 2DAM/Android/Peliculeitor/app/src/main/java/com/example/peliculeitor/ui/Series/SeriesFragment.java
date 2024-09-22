package com.example.peliculeitor.ui.Series;

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
import com.example.peliculeitor.actividades.SerieActivity;
import com.example.peliculeitor.api.SerieService;
import com.example.peliculeitor.modelos.Serie.Result;
import com.example.peliculeitor.modelos.Serie.Series;
import com.example.peliculeitor.ui.Peliculas.PeliculasFragment;
import com.example.peliculeitor.ui.adapters.PeliculaAdapter;
import com.example.peliculeitor.ui.adapters.SerieAdapter;
import com.example.peliculeitor.ui.adapters.SerieBusquedaAdapter;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;
//import com.example.peliculeitor.ui.models.TVShowFeed;
//import com.example.peliculeitor.ui.retrofit.MovieService;
//import com.example.peliculeitor.ui.retrofit.RetrofitInstance;

public class SeriesFragment extends Fragment {

    private RecyclerView recyclerView1;
    private RecyclerView recyclerView2;
    private List<Result> series1;
    private List<Result> series2;
    private ProgressBar progressBar;
    private EditText barraBusqueda;
    private RecyclerView cuadroBusqueda;
    private RecyclerView recyclerView3;
    private List<Result> series3;
    private String lenguage;
    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {

        View root = inflater.inflate(R.layout.fragment_media_final, container, false);
        lenguage = getResources().getConfiguration().locale.getLanguage();


        series1 = new ArrayList<Result>();
        series2 = new ArrayList<Result>();
        series3 = new ArrayList<Result>();


        progressBar = (ProgressBar) root.findViewById(R.id.progressBar);


        //Inicialización RecyclerView
        recyclerView1 = (RecyclerView) root.findViewById(R.id.recycler_view);
        recyclerView1.setHasFixedSize(false);


        recyclerView3 = (RecyclerView) root.findViewById(R.id.recycler_view_busqueda);
        recyclerView3.setHasFixedSize(false);

        barraBusqueda = (EditText) root.findViewById(R.id.editText);
        cuadroBusqueda = (RecyclerView) root.findViewById(R.id.recycler_view_busqueda);

        //Crea el adaptador, pasándole como parámetro los datos
        final SerieAdapter adaptador1 = new SerieAdapter(series1, new SerieAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(Result j) {

                Intent serie = new Intent(SeriesFragment.this.getContext(), SerieActivity.class);
                serie.putExtra("key", j.getId());
                startActivity(serie);

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
        final SerieAdapter adaptador2 = new SerieAdapter(series2, new SerieAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(Result j) {

                Intent serie = new Intent(SeriesFragment.this.getContext(), SerieActivity.class);
                serie.putExtra("key", j.getId());
                startActivity(serie);

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
                .baseUrl(SerieService.URL)
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        SerieService servicioSerieAPI = retrofit.create(SerieService.class);

        Call<Series> callTopSeries = servicioSerieAPI.getTopRatedSeries(lenguage);

        Call<Series> callPopularSeries = servicioSerieAPI.getPopularsSeries(lenguage);


        callTopSeries.enqueue(new Callback<Series>() {
            @Override
            public void onResponse(Call<Series> call, Response<Series> response) {
                switch(response.code()) {
                    case 200:
                        progressBar.setVisibility(View.INVISIBLE);

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

        callPopularSeries.enqueue(new Callback<Series>() {
            @Override
            public void onResponse(Call<Series> call, Response<Series> response) {
                switch(response.code()) {
                    case 200:
                        progressBar.setVisibility(View.INVISIBLE);

                        Series resultado = response.body();
                        series2 = resultado.getResults();

                        //para que vuelva a renderizar el RecyclerView
                        adaptador2.setDatos(series2);
                        adaptador2.notifyDataSetChanged();
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
                    final SerieBusquedaAdapter adaptador3 = new SerieBusquedaAdapter(series3, new SerieBusquedaAdapter.OnItemClickListener() {
                        @Override
                        public void onItemClick(com.example.peliculeitor.modelos.Serie.Result j) {

                            Intent serie = new Intent(SeriesFragment.this.getContext(), SerieActivity.class);
                            serie.putExtra("key", j.getId());
                            startActivity(serie);

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

                    Call<Series> callResultadosBusquedaSeries = servicioSerieAPI.getSearchSerie(barraBusqueda.getText().toString(), lenguage);

                    callResultadosBusquedaSeries.enqueue(new Callback<Series>() {
                        @Override
                        public void onResponse(Call<Series> call, Response<Series> response) {
                            switch(response.code()) {
                                case 200:
                                    cuadroBusqueda.setVisibility(View.VISIBLE);

                                    Series resultado = response.body();
                                    series3 = resultado.getResults();

                                    //para que vuelva a renderizar el RecyclerView
                                    adaptador3.setDatos(series3);

                                    adaptador3.notifyDataSetChanged();
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


                }
                else{
                    cuadroBusqueda.setVisibility(View.INVISIBLE);

                }
            }
        });


        return root;
    }


}