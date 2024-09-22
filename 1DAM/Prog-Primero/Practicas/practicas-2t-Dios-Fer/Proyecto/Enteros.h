#include <iostream>
using namespace std;

const bool DEBUG_C_Entero=false;
/***************************************************************************************************************************************
                                                           * Modulos Tipo int *
 ***************************************************************************************************************************************/


/**
 * @brief Modulo para la insercion de un numero filtrado
 * @param const char mensaje_entrada
 * @param int NoMenorA limite por abajo del numero que se quiere introducir
 * @param int NoMayorA limite por arriba del numero que se quiere introducir
 * @param const char mensaje_entrada
 * @return int numero 
 * @date 2023-03-13
 * @version 2.1
 * @author DiosFer
 */
int introducir_int_filtrado (const char mensaje_entrada[], int NoMenorA, int NoMayorA, const char mensaje_error[]);













/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* --------------------------- INTENTO DE ADAPTAR LA MODA --------------------------- */

///////////////////////// Insercion reutilizada para las modas

/**
 * @brief Módulo que agrega un nuevo número entero en el vector de enteros, al final de las componentes utilizadas.
 EJEMPLO:
 ENTRADA v = { 4 2 7 ? ? ? ? ... ? } util = 3 DIM_VECTOR = 2000 entero = 3
 SALIDA  v = { 4 2 7 3 ? ? ? ... ? } util = 4 DIM_VECTOR = 2000 entero = 3
 
 * @pre El número entero que queremos insertar está filtrado.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por REFERENCIA porque SÍ se va a cambiar el número de componentes utilizadas en el vector.
 * @param entero Es el nuevo número entero que quiero insertar en el vector.
 * @pre util_vector < DIM_VECTOR
 */
void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, int entero);





/**
 * @brief Módulo para la entrada de un vector
 * @param int DIM_VECTOR_A_EVALUAR 
 * @param int vector []
 * @param int &util_vector 
 * @version 0.2
 * @author Dios-Fer
 * @date 2023-02-15
 */
void entrada_vector(const int DIM_VECTOR_A_EVALUAR, int vector[], int &util_vector);



/**
 * @brief Módulo para copiar un vector en otro
 * @pre util_vector <= DIM_COPIA (Esto se puede lograr llamando al modulo comparar_tamaños)
 * @param int vector[] (vector que se "copia")
 * @param int util_vector (los utiles que son copiados)
 * @param int copia[] (vector en el que se "pega")
 * @param int &util_copia (debera de actualizarse) 
 * @param const int DIM_VECTOR_RESULTADO (este nos servira para que al copiar no nos pasemos de la dimension)
 * @post el vector copia contendra lo mismo que el vector original
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
void copiarVector(const int vector[], int util_vector, int copia[], int &util_copia, const int DIM_VECTOR_RESULTADO);



/**
 * @brief Módulo para obtener el numero mayor en un vector de enteros
 * @param int vector[] 
 * @param int util_vector
 * @return int mayor (numero mayor)
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
int obrener_numero_mayor_en_vector (int vector[], int util_vector);



/**
 * @brief Módulo para ubicar ubicar con un numero al correspondiente en otro vector con laa mismas posiciones a ese numero en el vector relacionado
 * @param int contador_moda
 * @param int vector_sin_reps[],
 * @param int vector_contadores[]
 * @param int util_numero_o_contador
 * @param int vector_salida_moda_modas []
 * @param int &util_vector_salida_moda_modas
 * @post se obtendra un vector con los numeros deseados
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
void ubicar_numeroYenlazar_salida (int contador_moda, int vector_sin_reps[], int vector_contadores[], int util_numero_o_contador, int vector_salida_moda_modas [], int &util_vector_salida_moda_modas);




/**
 * @brief Módulo para eliminar un numero en una cadena y actualizar todas sus posiciones y su util
 * @param int vector_sin_reps[] vector en el que se elimina la celda
 * @param int j posicion eliminada
 * @param int &util_vector_sin_reps util del vector
 * @post el vector estara sin la celda pero con la estructura ya actualizada
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
void eliminar_numero_cadena(int vector_sin_reps[], int j, int &util_vector_sin_reps);


/**
 * @brief Módulo para de un vector con numeros obtener un vector en el que no se repitan y uno asociado donde pongan las veces que se repetian en el original
 * @param int vector_sin_reps[] vector de entrada del vector a evaluar y de salida tendra los numeros sin repeticiones
 * @param int vector_contadores[] vector cuyas posiciones estaran asociadas a vector_sin_reps (Ejemplo: original={5 3 5} --> vector_sin_reps={5 3} y vector_contadores={2 1}) pues para la posicion i estara el contador asociado a la posicion i del vector sin repeticiones
 * @param int &util_vector_sin_reps util del vector sin reps
 * @param int &util_vector_contadores util del vector de contadores
 * @pre el vector a evaluar debera de estar copiado en vector_sin_reps
 * @post obtendremos los dos vectores de numeros_sin_reps y vector_contadores a partir del original copiado previamente en vector_sin_reps a modo de auxiliar inicial
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
void contarYquitar_Numeros_repetidos (int vector_sin_reps[], int vector_contadores[], int &util_vector_sin_reps, int &util_vector_contadores);


/**
 * @brief Módulo para calcular las modas de un vector
 * @param const int vector_a_evaluar[] vector del que se quiere saber la moda y sus repeticiones de cada entero
 * @param int vector_sin_reps[] vector de salida de los numeros sin que se repitan
 * @param int vector_contadores[] vector donde se encuentran los contadores asociados a las veces que salen los enteros del vector sin repeticiones
 * @param int vector_salida_moda_modas[] vector de salida de la moda / modas (El / los enteros que mas se repitan)
 * @param int &contador_moda las veces que se repite la moda
 * @param int util_vector_a_evaluar util de vector_a_evaluar
 * @param int &util_vector_sin_reps util de vector_sin_reps
 * @param int &util_vector_contadores util de vector_contadores
 * @param int &util_vector_salida_moda_modas util de vector_salida_moda_modas
 * @param const int DIM_VECTOR_SIN_REPS Dimension del vector de repeticiones para copiar el vector a evaluar en el 
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
void calcular_modas(const int vector_a_evaluar[], int vector_sin_reps[], int vector_contadores[], int vector_salida_moda_modas[], int &contador_moda, int util_vector_a_evaluar, int &util_vector_sin_reps, int &util_vector_contadores, int &util_vector_salida_moda_modas, const int DIM_VECTOR_SIN_REPS);




void Moda_minima_Moda_maxima();
