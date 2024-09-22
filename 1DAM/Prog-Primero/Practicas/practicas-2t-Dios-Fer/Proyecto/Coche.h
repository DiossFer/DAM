#include <iostream>
using namespace std;

const bool DEBUG_C_coche=false;

const int DIM_CADENA_NORMAL_C=50;
const int DIM_ID_COCHE=9;
const int DIM_MATRICULA=10;

/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Coche *
 ***************************************************************************************************************************************/

struct Coche{

    char id_coche[DIM_ID_COCHE];
    char marca[DIM_CADENA_NORMAL_C];
    char matricula[DIM_MATRICULA];
    char modelo[DIM_CADENA_NORMAL_C];
    int numero_asientos;

};

/***************************************************************************************************************************************
************************************************************   PROTOTIPOS   ************************************************************
***************************************************************************************************************************************/


/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Coche *
 ***************************************************************************************************************************************/


/**
 * @brief Modulo que establece un valor concreto para el miembro id_coche de una variable de tipo Coche.
 * @param Coche &c variable de tipo Coche 
 * @param char id_c [] vector que se quiere introducir en el miembro id_coche de la variable de tipo Coche c
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void set_id_coche(Coche &c, char id_c[]);


/**
 * @brief Modulo que establece un valor concreto para el miembro marca de una variable de tipo Coche.
 * @param Coche &c variable de tipo Coche 
 * @param char marc [] vector que se quiere introducir en el miembro marca de la variable de tipo Coche c
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void set_marca(Coche &c, char marc[]);


/**
 * @brief Modulo que establece un valor concreto para el miembro matricula de una variable de tipo Coche.
 * @param Coche &c variable de tipo Coche 
 * @param char matric [] vector que se quiere introducir en el miembro matricula de la variable de tipo Coche c
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void set_matricula(Coche &c, char matric[]);


/**
 * @brief Modulo que establece un valor concreto para el miembro modelo de una variable de tipo Coche.
 * @param Coche &c variable de tipo Coche 
 * @param char mod [] vector que se quiere introducir en el miembro modelo de la variable de tipo Coche c
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void set_modelo(Coche &c, char mod[]);


/**
 * @brief Modulo que establece un valor concreto para el miembro numero_asiento de una variable de tipo Coche.
 * @param Coche &c variable de tipo Coche 
 * @param int numero_asiento variable que se quiere introducir en el miembro numero_asiento de la variable de tipo Coche c
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void set_numero_asientos(Coche &c, int num_asientos);


/**
 * @brief Modulo para obtener el valor del miembro id_coche de una variable de tipo Coche
 * @param Coche &c variable de tipo Coche 
 * @param char id_c [] vector en el que se guardara el resultado (en este caso el id_coche del coche introducido)
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void get_id_coche (const Coche &c, char id_c[]);


/**
 * @brief Modulo para obtener el valor del miembro marca de una variable de tipo Coche
 * @param Coche &c variable de tipo Coche 
 * @param char marc [] vector en el que se guardara el resultado (en este caso el marca del coche introducido)
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void get_marca (const Coche &c, char marc[]);



/**
 * @brief Modulo para obtener el valor del miembro matricula de una variable de tipo Coche
 * @param Coche &c variable de tipo Coche 
 * @param char matric [] vector en el que se guardara el resultado (en este caso el matricula del coche introducido)
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void get_matricula (const Coche &c, char matric[]);


/**
 * @brief Modulo para obtener el valor del miembro modelo de una variable de tipo Coche
 * @param Coche &c variable de tipo Coche 
 * @param char mod [] vector en el que se guardara el resultado (en este caso el modelo del coche introducido)
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void get_modelo (const Coche &c, char mod[]);

/**
 * @brief Modulo para obtener el valor del miembro numero_asientos de una variable de tipo Coche
 * @param Coche &c variable de tipo Coche 
 * @return num_asientos numero de asientos de la variable de tipo Coche introducida
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
int get_numero_asientos (const Coche &c);


/**
 * @brief Modulo para añadir un coche a un vector de coches
 * @param Coche &coches[] vector de variables de tipo Coche 
 * @param Coche c variable de tipo Coche que se quiere añadir
 * @param int util util del vector
 * @return num_asientos numero de asientos de la variable de tipo Coche introducida
 * @date 2023-3-26
 * @version 0.9.5
 * @author DiosFer
 */
void set_anadir_coche_en_vector_coches(Coche coches[], Coche c, int &util);


/***************************************************************************************************************************************
                                                        * Modulos de la estructura Coche Front*
 ***************************************************************************************************************************************/
    

/**
 * @brief Modulo para mostrar el valor de todos lo miembros de una variable de tipo Coche
 * @param Coche &c variable de tipo Coche que se quiere mostrar
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void mostrar_coche (const Coche &c);


/**
 * @brief Modulo para mostrar el nombre de los miembros de la variable de tipo coche
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void mostrar_leyenda_coche ();

/**
 * @brief Modulo para mostrar el valor de todos lo miembros de una variable de tipo Coche en una unica linea
 * @param Coche &c variable de tipo Coche que se quiere mostrar
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void mostrar_coche_fila (const Coche &c);

/**
 * @brief Modulo para introducir todos los miembros de una variable de tipo coche
 * @param Coche &c variable de tipo Coche que se quiere rellenar
 * @date 2023-3-19
 * @version 0.8
 * @author DiosFer
 */
void introducir_coche (Coche &c);

/**
 * @brief Modulo para mostrar el valor de todos los miembros de todas las variables de tipo Coche del vector introducido
 * @param const Coche &c []
 * @param util_c
 * @date 2023-3-26
 * @version 0.9.8.1
 * @author DiosFer
 */
void mostrar_vector_coches (const Coche c[], const int util_c);

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Coche Back*
 ***************************************************************************************************************************************/


/**
 * @brief Modulo para buscar un coche por id_coche
 * @param const char id_coche_a_buscar[]
 * @param const Coche vector_para_buscar[]
 * @param const int util_vector
 * @param Coche coche_sol[]
 * @param int &util_vector_solucion
 * @date 2023-3-28
 * @version 1.1
 * @author DiosFer
 */
void buscar_coche_por_id_coche (const char id_coche_a_buscar[], const Coche vector_para_buscar[], const int util_vector, Coche coche_sol[],int &util_vector_solucion);


/**
 * @brief Modulo para copiar una variable de tipo Coche en otra
 * @param const Coche &c1 variable que se quiere copiar
 * @param Coche &c2 variable donde se copia
 * @date 2023-3-20
 * @version 0.8.1
 * @author DiosFer
 */
void copiar_coche (const Coche &c1, Coche &c2);


/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/
