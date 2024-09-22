package com.example.peliculeitor.api;

import com.example.peliculeitor.modelos.Actor.Actores;
import com.example.peliculeitor.modelos.Actor.Details.ActorDetails;


import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;
import retrofit2.http.Query;

public interface ActorService {



    final static String User = "api_key=83e2a5129e960ef35c31d1a07b7afcd3";
    final static String URL = "https://api.themoviedb.org/3/";

    @GET("movie/{movie_id}/credits" + "?" + User)
    Call<Actores> getActoresByMovieId(@Path("movie_id") int id, @Query("language") String language);

    @GET("tv/{movie_id}/credits" + "?" + User)
    Call<Actores> getActoresBySerieId(@Path("movie_id") int id, @Query("language") String language);

    @GET("person/{person_id}" + "?" + User)
    Call<ActorDetails> getActorById(@Path("person_id") int id, @Query("language") String language);


}