#include <iostream>

using namespace std;

const bool DEBUG_C_Time=false;

/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Time *
 ***************************************************************************************************************************************/
struct Time{

    int hora; //0-11
    bool am; //true(am)//false(pm)
    int minuto; //0-59
    int segundo; //0-59

};


/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Time *
 ***************************************************************************************************************************************/

/**
 * @brief Modulo que establece un valor concreto para el miembro hora de una variable de tipo Time.
 * @param Time &t variable de tipo Time (0-11)
 * @param int unahora valor que se le va a asignar a la variable t, para el miembro hora
 */
void sethoraF12(Time &t, int unahora);

/**
 * @brief Modulo que establece un valor concreto para el miembro am de una variable de tipo Time.
 * @param Time &t variable de tipo Time
 * @param bool ampm valor que se le va a asignar a la variable t, para el miembro am
 */
void setAm(Time &t, bool ampm);
/**
 * @brief Modulo que establece un valor concreto para el miembro minuto de una variable de tipo Time.
 * @param Time &t variable de tipo Time
 * @param int unminuto valor que se le va a asignar a la variable t, para el miembro minuto
 */
void setminuto(Time &t, int unminuto);

/**
 * @brief Modulo que establece un valor concreto para el miembro segundo de una variable de tipo Time.
 * @param Time &t variable de tipo Time
 * @param int unsegundo valor que se le va a asignar a la variable t, para el miembro segundo
 */
void setsegundo(Time &t, int unasegundo);

/**
 * @brief Modulo que devuelve el valor del miembro hora de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.hora 
 */
int gethora(const Time &t);

/**
 * @brief Modulo que devuelve el valor del miembro am de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.am 
 */
bool getAm(const Time &t);

/**
 * @brief Modulo que devuelve el valor del miembro segundo de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.segundo
 */
int getsegundo(const Time &t);

/**
 * @brief Modulo que devuelve el valor del miembro minuto de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.minuto
 */
int getminuto(const Time &t);

/**
 * @brief Modulo que establece un valor concreto para el miembro hora de una variable de tipo Time.
 * @param Time &t variable de tipo Time (0-23)
 * @param int unahora valor que se le va a asignar a la variable t, para el miembro hora
 */
void sethoraF24(Time &t, int unahora);

/***************************************************************************************************************************************
                                                       * Modulos Front de la estructura Time *
 ***************************************************************************************************************************************/

/**
 * @brief Modulo para imprimir la variable de tipo Time t en formato am/pm
 * @param const Time t 
 * @post se mostrara el tiempo en formato HH:MM:SS AM/PM
 */
void printTime(const Time &t);





/**
 * @brief modulo para entrada a una estructura de una hora, am, minuto y segundo
 * @param const Time &t (E/S)
 * @param int &hora (E)
 * @param bool am (E)
 * @param int minuto (E)
 * @param int segundo (E)
 * @post se actualizara la estructura
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
void Poner_hora (Time &t, int hora, bool am, int minuto, int segundo);


void Introducir_Time (Time &t);

/***************************************************************************************************************************************
                                                       * Modulos Back de la estructura Time *
 ***************************************************************************************************************************************/


/**
 * @brief modulo para copiar una variable de tipo Time en otra
 * @param Time &t1 variable a copiar
 * @param Time &t2 variable para pegar
 * @version 0.9
 * @date 2023-03-22
 * @author DiosFer
 */
void Copiar_Time (const Time &t1, Time &t2);





/**
 * @brief modulo para calcular en funcion de una hora 0-23 si es am o pm
 * @param Time &ahora (E/S)
 * @post am se actualizara
 * @version 1.0
 * @date 2023-03-08
 * @author DiosFer
 */
void calcular_am_pm_24 (Time &ahora);



/**
 * @brief modulo para en funcion de si es am o pm una estructura de tipo Time se actualice su hora a formato 0-11
 * @param Time &ahora (E/S)
 * @pre debe de tener el booleano am actualizado para indicar se es am o pm (se puede usar calcular_am_pm_24)
 * @post se cambiara el formato de la hora en la estructura introducida
 * @version 1.0
 * @date 2023-03-08
 * @author DiosFer
 */
void actualizar_hora_formato_24_a_12 (Time &ahora);

/**
 * @brief modulo para pasar un determinado numero de segundos al formato que tenemos en la estructura Time y actualizar una estructura 
 * @param Time &t (E/S)
 * @param int segundos
 * @post se actualizara la estructura a lo equivalente a los segundos introducidos
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
void segundos_a_resto_Y_actualizar_structure (Time &t, int segundos);



/**
 * @brief modulo para obtener el tiempo actual
 * @param Time &t (S)
 * @version 2.0
 * @date 2023-03-17
 * @author DiosFer
 */
void CogerTiempoActual(Time &t);




/**
 * @brief modulo para pasar una estructura de Time completamente a segundos
 * @param Time &t (E)
 * @return int segundos_t numero de segundos totales que tenia la estructura introducida
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
int pasar_todo_a_segundos (const Time &t);

/**
 * @brief modulo para calcular la diferencia de Time entre dos estructuras Time y guardar la diferencia en una tercera
 * @param const Time &desde (E)
 * @param const Time &hasta (E)
 * @param Time &diferencia (S)
 * @post la diferencia de Time se guardara en Time &diferencia
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
void diferencia_Time(const Time &desde, const Time &hasta, Time &diferencia);


/*****************************************************************************************************************************************
 *****************************************************************************************************************************************
 ****************************************************************************************************************************************/