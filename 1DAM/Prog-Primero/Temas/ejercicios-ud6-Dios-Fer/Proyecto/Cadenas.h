#include <iostream>
using namespace std;

const bool DEBUG_C_Cadena=false;

/***************************************************************************************************************************************
                                                           * Modulos Tipo char *
 ***************************************************************************************************************************************/

/**
 * @brief Módulo que agrega un nuevo caracter al final de las componentes utilizadas
 * @param vector Es una referencia al vector 
 * @param i es la posicion en la que vamos a introducir el nuevo caracter
 * @param letra Es el nuevo caracter que quiero insertar en el vector.
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-02-13
 */
void agregarLetraACadena(char vector[], int i, char letra);


/**
 * @brief Módulo que calcula cual es la longuitud actual de una cadena de caracteres
 * @param cadena [] cadena de caracteres
 * @return longuitud (J(0)a(1)i(2)m(3)e(4)\0(5) --> longitud=5)
 * @version 0.3
 * @date 2023-02-13
 * @author Dios-Fer
 */
int get_Longitud (const char cadena []);

/**
 * @brief Módulo para copiar por completo un vector char en otro 
 * @pre longitud_vector < DIM_COPIA 
 * @param char vector[] (vector que se "copia")
 * @param char copia[] (vector en el que se "pega")
 * @post el vector copia en el otro vector
 * @version 0.1
 * @author Dios-Fer
 * @date 2023-03-13
 */
void copiarVector_char(const char vector[], char copia[]);

/**
 * @brief Módulo para introducir un vector char filtrando o no en funcion de dos booleanos el numero de caracteres tanto maximos como minimos o a eleccion
 * @param const char mensaje[] mensaje que se mostrara por pantalla antes de la introduccion de la cadena
 * @param char cadena[] cadena que se introduce (S)
 * @param const int DIM_AUX dimension de la cadena que introduciremos, en este caso al ser global se introducira desde el modulo que lo llame para su aislamiento 
 * @param bool minimo_establecido (true:se filtrara el minimo de carcteres)(false: no se filtrara el minimo de carcteres)
 * @param int minimo numero minimo de caracteres (no importara si minimo_establecido==false)
 * @param bool maximo_establecido (true:se filtrara el maximo de carcteres)(false: no se filtrara el maximo de carcteres)
 * @param int maximo numero maximo de caracteres (no importara si maximo_establecido==false)
 * @param const char mensaje_error[] mensaje que se mostrara por pantalla en caso de fallar con el numero de caracteres (no importara si ambos filtros estan desactivados)
 * @pre el minimo o maximo no puede superar la dimension
 * @pre min<=max
 * @version 0.9
 * @author Dios-Fer
 * @date 2023-03-21
 */
void introducir_cadena_numero_caracteres_filtrado (const char mensaje[], char cadena[], const int DIM_AUX, bool minimo_establecido, int minimo, bool maximo_establecido, int maximo, const char mensaje_error[]);

/**
 * @brief Módulo para mostrar por pantalla un vector de tipo char
 * @param const char cadena[] vector de tipo char que se mostrara por pantalla
 * @version 0.5
 * @author Dios-Fer
 * @date 2023-03-16
 */
void mostrar_cadena (const char cadena[]);
