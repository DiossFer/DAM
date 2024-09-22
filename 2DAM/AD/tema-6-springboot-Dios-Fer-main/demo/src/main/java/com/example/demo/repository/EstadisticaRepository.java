
package com.example.demo.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.example.demo.entity.Estadistica;

@Repository
public interface EstadisticaRepository extends JpaRepository<Estadistica,Long>{

} 
