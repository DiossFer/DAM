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
 * @pre la entrada debera de estar filtrada
 * @post se habra introducido el valor al miembro
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_coche_que_viaja (Viaje &v, const Coche &c);

/**
 * @brief Modulo que establece un valor concreto para el miembro trayecto_que_se_realiza de una variable de tipo Viaje.
 * @param Viaje &v variable de tipo Viaje 
 * @param const Trayectop t trayecto que se quiere introducir en el miembro trayecto_que_se_realiza de la variable de tipo Viaje v
 * @pre la entrada debera de estar filtrada
 * @post se habra introducido el valor al miembro
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_trayecto_que_se_realiza (Viaje &v, const Trayecto &t);

/**
 * @brief Modulo que establece un valor concreto para el miembro hora_salida de una variable de tipo Viaje.
 * @param Viaje &v variable de tipo Viaje 
 * @param const Time t tiempo que se quiere introducir en el miembro hora_salida de la variable de tipo Viaje v
 * @pre la entrada debera de estar filtrada
 * @post se habra introducido el valor al miembro
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_hora_salida (Viaje &v, const Time &t);

/**
 * @brief Modulo que establece un valor concreto para el miembro hora_llegada de una variable de tipo Viaje.
 * @param Viaje &v variable de tipo Viaje 
 * @param const Time t tiempo que se quiere introducir en el miembro hora_llegada de la variable de tipo Viaje v
 * @pre la entrada debera de estar filtrada
 * @post se habra introducido el valor al miembro
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_hora_llegada (Viaje &v, const Time &t);


/**
 * @brief Modulo que establece un valor concreto para el miembro fecha_salida de una variable de tipo Viaje.
 * @param Viaje &v variable de tipo Viaje 
 * @param const Fecha f fecha que se quiere introducir en el miembro fecha_salida de la variable de tipo Viaje v
 * @pre la entrada debera de estar filtrada
 * @post se habra introducido el valor al miembro
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_fecha_salida (Viaje &v, const Fecha &f);


/**
 * @brief Modulo que establece un valor concreto para el miembro fecha_salida de una variable de tipo Viaje.
 * @param Viaje &v variable de tipo Viaje 
 * @param const Fecha f fecha que se quiere introducir en el miembro fecha_llegada de la variable de tipo Viaje v
 * @pre la entrada debera de estar filtrada
 * @post se habra introducido el valor al miembro
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_fecha_llegada (Viaje &v, const Fecha &f);


/**
 * @brief Modulo que establece un valor concreto para el miembro numero_asiento_ofertados de una variable de tipo Viaje.
 * @param Viaje &v variable de tipo Viaje 
 * @param const int num_asi fecha que se quiere introducir en el miembro numero_asiento_ofertados de la variable de tipo Viaje v
 * @pre la entrada debera de estar filtrada
 * @post se habra introducido el valor al miembro
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void set_numero_asiento_ofertados (Viaje &v, int num_asi);


/**
 * @brief Modulo para obtener el coche que viaja de una variable de tipo Viaje
 * @param Viaje &v variable de tipo Viaje 
 * @param Coche &c coche que se quiere obtener en el miembro coche_que_viaja de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void get_coche_que_viaja (const Viaje &v, Coche &c);

/**
 * @brief Modulo para obtener el trayecto_que_se_realiza de una variable de tipo Viaje
 * @param Viaje &v variable de tipo Viaje 
 * @param Trayecto &t trayecto que se quiere obtener en el miembro trayecto_que_se_realiza de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void get_trayecto_que_se_realiza (const Viaje &v, Trayecto &t);


/**
 * @brief Modulo para obtener la hora_salida de una variable de tipo Viaje
 * @param Viaje &v variable de tipo Viaje 
 * @param Time &t tiempo que se quiere obtener en el miembro hora_salida de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void get_hora_salida (const Viaje &v, Time &t);


/**
 * @brief Modulo para obtener la hora_llegada de una variable de tipo Viaje
 * @param Viaje &v variable de tipo Viaje 
 * @param Time &t tiempo que se quiere obtener en el miembro hora_llegada de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void get_hora_llegada (const Viaje &v, Time &t);


/**
 * @brief Modulo para obtener la fecha_salida de una variable de tipo Viaje
 * @param Viaje &v variable de tipo Viaje 
 * @param Fecha &f tiempo que se quiere obtener en el miembro fecha_salida de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void get_fecha_salida (const Viaje &v, Fecha &f);


/**
 * @brief Modulo para obtener la fecha_llegada de una variable de tipo Viaje
 * @param Viaje &v variable de tipo Viaje 
 * @param Fecha &f tiempo que se quiere obtener en el miembro fecha_llegada de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void get_fecha_llegada (const Viaje &v, Fecha &f);


/**
 * @brief Modulo para obtener el numero_asiento_ofertados de una variable de tipo Viaje
 * @param Viaje &v variable de tipo Viaje 
 * @param int &num_asi num_asientos que se quiere obtener en el miembro numero_asientos_ofertados de la variable de tipo Viaje v
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
int get_numero_asiento_ofertados (const Viaje &v);




/***************************************************************************************************************************************
                                                        * Modulos de la estructura Viaje Front*
 ***************************************************************************************************************************************/
    
/**
 * @brief Modulo para mostrar por pantalla una variable de tipo viaje
 * @param const Viaje &v variable de tipo Viaje 
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void mostrar_viaje (const Viaje &v);




/**
 * @brief Modulo para introducir por pantalla una variable de tipo viaje
 * @param Viaje &v variable de tipo Viaje 
 * @date 2023-3-22
 * @version 0.9.1
 * @author DiosFer
 */
void introducir_viaje (Viaje &v);

/**
 * @brief Modulo para mostrar por pantalla los nombres de los miembros de una variable de tipo viaje en formato fila 
 * @date 2023-3-28
 * @version 0.9.8
 * @author DiosFer
 */
void mostrar_viaje_fila_nombres_no_structs();


/**
 * @brief Modulo para mostrar por pantalla una variable de tipo viaje en formato fila
 * @param const Viaje &v variable de tipo Viaje 
 * @date 2023-3-28
 * @version 0.9.8
 * @author DiosFer
 */
void mostrar_viaje_fila (const Viaje &v);


/**
 * @brief Modulo para mostrar por pantalla una variable de tipo viaje en formato fila
 * @param const Viaje v[] variable de tipo Viaje 
 * @param const int util_v
 * @date 2023-3-28
 * @version 0.9.8.1
 * @author DiosFer
 */
void mostrar_vector_viajes (const Viaje v[], const int util_v);

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Viaje Back*
 ***************************************************************************************************************************************/
/**
 * @brief Modulo para añadir un viaje a un vector de viaje actualizando la util
 * @param const Viaje &v_aux variable de tipo Viaje 
 * @param Viaje viajes_del_sistema[] vector de tipo Viaje 
 * @param int &util_viajes_sistema
 * @date 2023-3-28
 * @version 0.9.8
 * @author DiosFer
 */
void anadir_viaje_a_vector_viajes(const Viaje &v_aux, Viaje viajes_del_sistema[], int &util_viajes_sistema);


/*****************************************************************************************************************************************
 *****************************************************************************************************************************************
 ****************************************************************************************************************************************/
