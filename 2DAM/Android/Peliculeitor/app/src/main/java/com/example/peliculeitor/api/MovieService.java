package com.example.peliculeitor.api;

import com.example.peliculeitor.modelos.Actor.Movie.CastMovieActor;
import com.example.peliculeitor.modelos.Actor.Movie.MoviesActor;
import com.example.peliculeitor.modelos.Pelicula.Details.MovieDetails;
import com.example.peliculeitor.modelos.Pelicula.Movie;
import com.example.peliculeitor.modelos.Vidos.Videos;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;
import retrofit2.http.Query;

public interface MovieService {

    final static String User = "api_key=83e2a5129e960ef35c31d1a07b7afcd3";
    final static String URL = "https://api.themoviedb.org/3/";
    final static String MOVIE_TOP = "movie/top_rated";
    final static String MOVIE_POPULAR = "movie/popular";

    @GET(MOVIE_TOP + "?" + User)
    Call<Movie> getTopRatedPeliculas(@Query("language") String language);

    @GET(MOVIE_POPULAR + "?" + User)
    Call<Movie> getPopularsPeliculas(@Query("language") String language);

    @GET("movie/{movie_id}" + "?" + User)
    Call<MovieDetails> getPeliculaById(@Path("movie_id") int id, @Query("language") String language);

    @GET("movie/{movie_id}/similar" + "?" + User)
    Call<Movie> getPeliculasSimilares(@Path("movie_id") int id, @Query("language") String language);


    @GET("movie/{movie_id}/videos" + "?" + User)
    Call<Videos> getVideosPelicula(@Path("movie_id") int id, @Query("language") String language);

    @GET("person/{person_id}/movie_credits" + "?" + User)
    Call<MoviesActor> getMovieByActor(@Path("person_id") int id, @Query("language") String language);

    @GET("search/movie" + "?" + User)
    Call<Movie> getSearchMovie(@Query("query") String query, @Query("language") String language);
}