package com.example.peliculeitor.ui.adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.modelos.Actor.Serie.CastSerieActor;
import com.squareup.picasso.Picasso;

import java.util.List;

public class ActorSerieAdapter extends RecyclerView.Adapter<ActorSerieAdapter.ActorSerieViewHolder>{


    /*Arraylist donde almaceno los datos que se van a mostrar en el RecylerView*/
    private List<CastSerieActor> datos;

    private final OnItemClickListener listener;




    public void setDatos(List<CastSerieActor> datos) {
        this.datos = datos;
    }

    /* Defino un interface con el OnItemClickListener*/
    public interface OnItemClickListener {
        void onItemClick(CastSerieActor item);
    }

    /* Incluyo el Viewholder en el Adapter */
    public static class ActorSerieViewHolder
            extends RecyclerView.ViewHolder {
        /* Como atributos se incluyen los elementos que van a referenciar a los elementos de la vista*/

        private TextView tvName;
        private ImageView image_view;
        private RatingBar ratingBar;


        /*constructor con parámetro de la vista*/
        public ActorSerieViewHolder(View itemView) {
            super(itemView);
            // Asocia los atributos a los widgets del layout de la vista
            tvName = (TextView)itemView.findViewById(R.id.tv_name);
            image_view = (ImageView)itemView.findViewById(R.id.imageView);
            ratingBar = (RatingBar) itemView.findViewById(R.id.ratingBar);

        }

        /*Muestra los datos de jugador en el item*/
        public void bindActorSerie(CastSerieActor a, final OnItemClickListener listener) {

            tvName.setText(a.getName());
            Picasso.get().load( "https://image.tmdb.org/t/p/original" + a.getPosterPath()).into(image_view);
            ratingBar.setRating(Double.valueOf(a.getVoteAverage()/2.0).floatValue());
            /* Coloco el listener a la vista*/
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override public void onClick(View v) {
                    listener.onItemClick(a);
                }
            });
        }
    }


    /* Constructor con parámetros*/
    public ActorSerieAdapter(List<CastSerieActor> datos, OnItemClickListener listener) {
        this.datos = datos;
        this.listener = listener;
    }

    @Override
    public ActorSerieViewHolder onCreateViewHolder(ViewGroup viewGroup, int viewType) {
        /*Crea la vista de un item y la "pinta"*/
        View itemView = LayoutInflater.from(viewGroup.getContext())
                .inflate(R.layout.layout_movie_item_roundedcorners, viewGroup, false);
        /* Crea un objeto de la clase CocheViewHolder, pasándole la vista anteriormente creada*/
        ActorSerieViewHolder actorVH = new ActorSerieViewHolder(itemView);
        /* devuelve la vissta*/
        return actorVH;
    }

    @Override
    public void onBindViewHolder(ActorSerieViewHolder viewHolder, int pos) {
        CastSerieActor s = datos.get(pos);
        viewHolder.bindActorSerie(s,listener);
    }

    @Override
    public int getItemCount() {
        return datos.size();
    }

}
