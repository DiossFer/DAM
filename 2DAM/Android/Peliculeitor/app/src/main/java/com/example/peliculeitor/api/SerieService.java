package com.example.peliculeitor.api;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;
import retrofit2.http.Query;


import com.example.peliculeitor.modelos.Actor.Movie.CastMovieActor;
import com.example.peliculeitor.modelos.Actor.Movie.MoviesActor;
import com.example.peliculeitor.modelos.Actor.Serie.CastSerieActor;
import com.example.peliculeitor.modelos.Actor.Serie.SeriesActor;
import com.example.peliculeitor.modelos.Pelicula.Movie;
import com.example.peliculeitor.modelos.Serie.Details.SerieDetails;
import com.example.peliculeitor.modelos.Serie.Series;
import com.example.peliculeitor.modelos.Vidos.Videos;


public interface SerieService {

    final static String User = "api_key=83e2a5129e960ef35c31d1a07b7afcd3";
    final static String URL = "https://api.themoviedb.org/3/";
    final static String SERIE_TOP = "tv/top_rated";
    final static String SERIE_COMING = "tv/popular";

    @GET(SERIE_TOP + "?" + User)
    Call<Series> getTopRatedSeries(@Query("language") String language);

    @GET(SERIE_COMING + "?" + User)
    Call<Series> getPopularsSeries(@Query("language") String language);

    @GET("tv/{serie_id}" + "?" + User)
    Call<SerieDetails> getSerieById(@Path("serie_id") int id, @Query("language") String language);

    @GET("tv/{serie_id}/similar" + "?" + User)
    Call<Series> getSeriesSimilares(@Path("serie_id") int id, @Query("language") String language);

    @GET("tv/{serie_id}/videos" + "?" + User)
    Call<Videos> getVideosSerie(@Path("serie_id") int id, @Query("language") String language);

    @GET("person/{person_id}/tv_credits" + "?" + User)
    Call<SeriesActor> getSeriesByActor(@Path("person_id") int id, @Query("language") String language);

    @GET("search/tv" + "?" + User)
    Call<Series> getSearchSerie(@Query("query") String query, @Query("language") String language);
}