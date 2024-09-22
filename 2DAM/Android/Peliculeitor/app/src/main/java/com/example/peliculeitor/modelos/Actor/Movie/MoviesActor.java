
package com.example.peliculeitor.modelos.Actor.Movie;

import java.util.List;
//import javax.annotation.Generated;
import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

//@Generated("jsonschema2pojo")
public class MoviesActor {

    @SerializedName("cast")
    @Expose
    private List<CastMovieActor> cast;
    @SerializedName("crew")
    @Expose
    private List<Crew> crew;
    @SerializedName("id")
    @Expose
    private Integer id;

    public List<CastMovieActor> getCast() {
        return cast;
    }

    public void setCast(List<CastMovieActor> cast) {
        this.cast = cast;
    }

    public List<Crew> getCrew() {
        return crew;
    }

    public void setCrew(List<Crew> crew) {
        this.crew = crew;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

}
