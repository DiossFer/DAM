package com.example.peliculeitor.ui.adapters;

        import android.util.Log;
        import android.view.LayoutInflater;
        import android.view.View;
        import android.view.ViewGroup;
        import android.widget.ImageView;
        import android.widget.RatingBar;
        import android.widget.TextView;

        import androidx.recyclerview.widget.RecyclerView;

        import com.example.peliculeitor.R;
        import com.example.peliculeitor.modelos.Actor.Cast;
        import com.example.peliculeitor.modelos.Serie.Details.SerieDetails;
        import com.squareup.picasso.Picasso;

        import java.util.List;

public class SerieFavoritasAdapter extends RecyclerView.Adapter<SerieFavoritasAdapter.SerieDetailsViewHolder>{


    /*Arraylist donde almaceno los datos que se van a mostrar en el RecylerView*/
    private List<SerieDetails> datos;

    private final OnItemClickListener listener;




    public void setDatos(List<SerieDetails> datos) {
        this.datos = datos;
    }

    /* Defino un interface con el OnItemClickListener*/
    public interface OnItemClickListener {
        void onItemClick(SerieDetails item);
    }

    /* Incluyo el Viewholder en el Adapter */
    public static class SerieDetailsViewHolder
            extends RecyclerView.ViewHolder {
        /* Como atributos se incluyen los elementos que van a referenciar a los elementos de la vista*/

        private TextView tvName;
        private ImageView image_view;
        private RatingBar estrellas;


        /*constructor con parámetro de la vista*/
        public SerieDetailsViewHolder(View itemView) {
            super(itemView);
            // Asocia los atributos a los widgets del layout de la vista
            tvName = (TextView)itemView.findViewById(R.id.tv_name);
            image_view = (ImageView)itemView.findViewById(R.id.imageView);
            estrellas = (RatingBar) itemView.findViewById(R.id.ratingBar);

        }

        /*Muestra los datos de jugador en el item*/
        public void bindActor(SerieDetails a, final OnItemClickListener listener) {

            tvName.setText(a.getName());
            Picasso.get().load( "https://image.tmdb.org/t/p/original" + a.getPosterPath()).into(image_view);
            estrellas.setRating(Double.valueOf(a.getVoteAverage()/2.0).floatValue());
            /* Coloco el listener a la vista*/
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override public void onClick(View v) {
                    listener.onItemClick(a);
                }
            });
        }
    }


    /* Constructor con parámetros*/
    public SerieFavoritasAdapter(List<SerieDetails> datos, OnItemClickListener listener) {
        this.datos = datos;
        this.listener = listener;
    }

    @Override
    public SerieDetailsViewHolder onCreateViewHolder(ViewGroup viewGroup, int viewType) {
        /*Crea la vista de un item y la "pinta"*/
        View itemView = LayoutInflater.from(viewGroup.getContext())
                .inflate(R.layout.layout_movie_item_roundedcorners, viewGroup, false);
        /* Crea un objeto de la clase CocheViewHolder, pasándole la vista anteriormente creada*/
        SerieDetailsViewHolder serie = new SerieDetailsViewHolder(itemView);
        /* devuelve la vissta*/
        return serie;
    }

    @Override
    public void onBindViewHolder(SerieDetailsViewHolder viewHolder, int pos) {
        SerieDetails s = datos.get(pos);
        viewHolder.bindActor(s,listener);
    }

    @Override
    public int getItemCount() {
        return datos.size();
    }

}
