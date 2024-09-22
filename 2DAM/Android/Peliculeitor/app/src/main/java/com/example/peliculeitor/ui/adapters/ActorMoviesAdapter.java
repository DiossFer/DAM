package com.example.peliculeitor.ui.adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import com.example.peliculeitor.R;
import com.example.peliculeitor.modelos.Actor.Movie.CastMovieActor;
import com.squareup.picasso.Picasso;

import java.util.List;

public class ActorMoviesAdapter extends RecyclerView.Adapter<ActorMoviesAdapter.ActorMoviesViewHolder>{


    /*Arraylist donde almaceno los datos que se van a mostrar en el RecylerView*/
    private List<CastMovieActor> datos;

    private final OnItemClickListener listener;




    public void setDatos(List<CastMovieActor> datos) {
        this.datos = datos;
    }

    /* Defino un interface con el OnItemClickListener*/
    public interface OnItemClickListener {
        void onItemClick(CastMovieActor item);
    }

    /* Incluyo el Viewholder en el Adapter */
    public static class ActorMoviesViewHolder
            extends RecyclerView.ViewHolder {
        /* Como atributos se incluyen los elementos que van a referenciar a los elementos de la vista*/

        private TextView tvName;
        private ImageView image_view;
        private RatingBar ratingBar;


        /*constructor con parámetro de la vista*/
        public ActorMoviesViewHolder(View itemView) {
            super(itemView);
            // Asocia los atributos a los widgets del layout de la vista
            tvName = (TextView)itemView.findViewById(R.id.tv_name);
            image_view = (ImageView)itemView.findViewById(R.id.imageView);
            ratingBar = (RatingBar) itemView.findViewById(R.id.ratingBar);

        }

        /*Muestra los datos de jugador en el item*/
        public void bindActorMovies(CastMovieActor a, final OnItemClickListener listener) {

            tvName.setText(a.getTitle());
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
    public ActorMoviesAdapter(List<CastMovieActor> datos, OnItemClickListener listener) {
        this.datos = datos;
        this.listener = listener;
    }

    @Override
    public ActorMoviesViewHolder onCreateViewHolder(ViewGroup viewGroup, int viewType) {
        /*Crea la vista de un item y la "pinta"*/
        View itemView = LayoutInflater.from(viewGroup.getContext())
                .inflate(R.layout.layout_movie_item_roundedcorners, viewGroup, false);
        /* Crea un objeto de la clase CocheViewHolder, pasándole la vista anteriormente creada*/
        ActorMoviesViewHolder actorVH = new ActorMoviesViewHolder(itemView);
        /* devuelve la vissta*/
        return actorVH;
    }

    @Override
    public void onBindViewHolder(ActorMoviesViewHolder viewHolder, int pos) {
        CastMovieActor s = datos.get(pos);
        viewHolder.bindActorMovies(s,listener);
    }

    @Override
    public int getItemCount() {
        return datos.size();
    }

}
