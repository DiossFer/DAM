#include <iostream>
#include "Usuario.h"//incluye coche.h
#include "Tiempo.h"
#include "Fecha.h"
#include "Trayecto.h"

using namespace std;


/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Viaje *
 ***************************************************************************************************************************************/
struct Viaje{
    Time hora_salida;
    Fecha fecha_salida;

    int numero_asientos_ofertados;

    Time hora_llegada;
    Fecha fecha_llegada;

    Coche coche_que_viaja;
    Trayecto trayecto_que_se_realiza;
};

/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Viaje *
 ***************************************************************************************************************************************/

/**
 * @brief Modulo que establece un valor concreto para el miembro coche_que_viaja de una variable de tipo Viaje.
 * @param Viaje &v variable de tipo Viaje 
 * @param const Coche c coche que se quiere introducir en el miembro coche_que_viaja de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_coche_que_viaja (Viaje &v, const Coche &c);


void set_trayecto_que_se_realiza (Viaje &v, const Trayecto &t);


void set_hora_salida (Viaje &v, const Time &t);


void set_hora_llegada (Viaje &v, const Time &t);



void set_fecha_salida (Viaje &v, const Fecha &f);



void set_fecha_llegada (Viaje &v, const Fecha &f);



void set_numero_asiento_ofertados (Viaje &v, int num_asi);



void get_coche_que_viaja (const Viaje &v, Coche &c);


void get_trayecto_que_se_realiza (const Viaje &v, Trayecto &t);



void get_hora_salida (const Viaje &v, Time &t);



void get_hora_llegada (const Viaje &v, Time &t);



void get_fecha_salida (const Viaje &v, Fecha &f);



void get_fecha_llegada (const Viaje &v, Fecha &f);



void get_numero_asiento_ofertados (const Viaje &v, int &num_asi);




/***************************************************************************************************************************************
                                                        * Modulos de la estructura Viaje Front*
 ***************************************************************************************************************************************/
    

void mostrar_viaje (const Viaje &v);





void introducir_viaje (Viaje &v);







/***************************************************************************************************************************************
                                                        * Modulos de la estructura Viaje Back*
 ***************************************************************************************************************************************/




/*****************************************************************************************************************************************
 *****************************************************************************************************************************************
 ****************************************************************************************************************************************/
