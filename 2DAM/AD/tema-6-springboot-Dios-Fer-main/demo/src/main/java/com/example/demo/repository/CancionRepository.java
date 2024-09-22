package com.example.demo.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.example.demo.entity.Cancion;

@Repository
public interface CancionRepository extends JpaRepository<Cancion,Long>{

} 
