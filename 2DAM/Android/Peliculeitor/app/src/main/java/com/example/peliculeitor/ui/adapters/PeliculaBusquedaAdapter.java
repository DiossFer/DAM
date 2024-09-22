package com.example.peliculeitor.ui.adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.modelos.Pelicula.Result;
import com.squareup.picasso.Picasso;

import java.util.List;

public class PeliculaBusquedaAdapter extends RecyclerView.Adapter<PeliculaBusquedaAdapter.PeliculaBusquedaViewHolder>{

    /*Arraylist donde almaceno los datos que se van a mostrar en el RecylerView*/
    private List<Result> datos;

    private final PeliculaBusquedaAdapter.OnItemClickListener listener;




    public void setDatos(List<Result> datos) {
        this.datos = datos;
    }

    /* Defino un interface con el OnItemClickListener*/
    public interface OnItemClickListener {
        void onItemClick(Result item);
    }

    /* Incluyo el Viewholder en el Adapter */
    public static class PeliculaBusquedaViewHolder
            extends RecyclerView.ViewHolder {
        /* Como atributos se incluyen los elementos que van a referenciar a los elementos de la vista*/

        private TextView tvName;
        private ImageView image_view;

        /*constructor con parámetro de la vista*/
        public PeliculaBusquedaViewHolder(View itemView) {
            super(itemView);
            // Asocia los atributos a los widgets del layout de la vista
            tvName = (TextView)itemView.findViewById(R.id.tv_name);
            image_view = (ImageView)itemView.findViewById(R.id.imageView);

        }

        /*Muestra los datos de jugador en el item*/
        public void bindPeliculaBusqueda(Result s, final PeliculaBusquedaAdapter.OnItemClickListener listener) {

            tvName.setText(s.getTitle());

            Picasso.get().load( "https://image.tmdb.org/t/p/original" + s.getPosterPath()).into(image_view);
            /* Coloco el listener a la vista*/
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override public void onClick(View v) {
                    listener.onItemClick(s);
                }
            });
        }
    }


    /* Constructor con parámetros*/
    public PeliculaBusquedaAdapter(List<Result> datos, OnItemClickListener listener) {
        this.datos = datos;
        this.listener = listener;
    }

    @Override
    public PeliculaBusquedaAdapter.PeliculaBusquedaViewHolder onCreateViewHolder(ViewGroup viewGroup, int viewType) {
        /*Crea la vista de un item y la "pinta"*/
        View itemView = LayoutInflater.from(viewGroup.getContext())
                .inflate(R.layout.find_item_layout, viewGroup, false);
        /* Crea un objeto de la clase CocheViewHolder, pasándole la vista anteriormente creada*/
        PeliculaBusquedaAdapter.PeliculaBusquedaViewHolder peliculaVH = new PeliculaBusquedaAdapter.PeliculaBusquedaViewHolder(itemView);
        /* devuelve la vissta*/
        return peliculaVH;
    }

    @Override
    public void onBindViewHolder(PeliculaBusquedaAdapter.PeliculaBusquedaViewHolder viewHolder, int pos) {
        Result s = datos.get(pos);
        viewHolder.bindPeliculaBusqueda(s,listener);
    }

    @Override
    public int getItemCount() {
        return datos.size();
    }

}

