#include <iostream>
using namespace std;

const bool DEBUG_C_Trayecto=false;

const int DIM_ID_TRAYECTO=10;
const int DIM_UBICACION=50;

/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Trayecto *
 ***************************************************************************************************************************************/
struct Trayecto{
    char id_trayecto [DIM_ID_TRAYECTO];
    char destino [DIM_UBICACION];
    char origen [DIM_UBICACION];
};


/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Trayecto *
 ***************************************************************************************************************************************/


/**
 * @brief Modulo que establece un valor concreto para el miembro id_trayecto de una variable de tipo Trayecto.
 * @param Trayecto &t variable de tipo Trayecto 
 * @param char id_t [] vector que se quiere introducir en el miembro id_trayecto de la variable de tipo Trayecto t
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void set_id_trayecto(Trayecto &t, char id_t[]);


/**
 * @brief Modulo que establece un valor concreto para el miembro origen de una variable de tipo Trayecto.
 * @param Trayecto &t variable de tipo Trayecto 
 * @param char o [] vector que se quiere introducir en el miembro origen de la variable de tipo Trayecto t
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void set_origen(Trayecto &t, char o[]);


/**
 * @brief Modulo que establece un valor concreto para el miembro origen de una variable de tipo Trayecto.
 * @param Trayecto &t variable de tipo Trayecto 
 * @param char d [] vector que se quiere introducir en el miembro destino de la variable de tipo Trayecto t
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void set_destino(Trayecto &t, char d[]);




/**
 * @brief Modulo para obtener el valor del miembro id_trayecto de una variable de tipo Trayecto.
 * @param Trayecto &t variable de tipo Trayecto 
 * @param char id_tr [] vector para obtener el valor
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void get_id_trayecto(const Trayecto &t, char id_tr[]);


/**
 * @brief Modulo qpara obtener el valor del miembro origen de una variable de tipo Trayecto.
 * @param Trayecto &t variable de tipo Trayecto 
 * @param char o [] vector para obtener el valor
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void get_origen(const Trayecto &t, char o[]);


/**
 * @brief Modulo para obtener el valor del miembro destino de una variable de tipo Trayecto.
 * @param Trayecto &t variable de tipo Trayecto 
 * @param char d [] vector para obtener el valor
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void get_destino(const Trayecto &t, char d[]);




/***************************************************************************************************************************************
                                                        * Modulos de la estructura Trayecto Front*
 ***************************************************************************************************************************************/
    

/**
 * @brief Modulo para mostrar el valor de todos lo miembros de una variable de tipo Trayecto
 * @param Trayecto &t variable de tipo Trayecto que se quiere mostrar
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void mostrar_trayecto (const Trayecto &t);

/**
 * @brief Modulo para introducir todos los miembros de la variable de tipo Trayecto introducida
 * @param Trayecto &t variable de tipo Trayecto que se quiere rellenar
 * @date 2023-3-21
 * @version 0.9
 * @author DiosFer
 */
void introducir_trayecto (Trayecto &t);

 /**
 * @brief modulo para mostrar mostrar los titulos de una fila de trayecto
 * @version 0.9.7
 * @date 2023-03-27
 * @author DiosFer
 */
void mostrar_titulos_trayecto();

 /**
 * @brief modulo para mostrar en una fila el contenido de una variable de tipo trayecto
 * @param const Trayecto t[]
 * @version 0.9.7
 * @date 2023-03-27
 * @author DiosFer
 */
void mostrar_trayecto_fila(const Trayecto &t);


 /**
 * @brief modulo para mostrar un vector de trayectos
 * @param const Trayecto t[]
 * @param const int util_trayectos
 * @version 0.9.7
 * @date 2023-03-27
 * @author DiosFer
 */
void mostrar_vector_trayectos (const Trayecto t[], const int util_trayectos);

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Trayecto Back*
 ***************************************************************************************************************************************/

/**
 * @brief Modulo para buscar un trayecto por id_trayecto
 * @param const char id_trayecto_a_buscar[]
 * @param const Trayecto vector_para_buscar[]
 * @param const int util_vector
 * @param Trayecto t_sol[]
 * @param int &util_vector_solucion
 * @date 2023-3-28
 * @version 1.1
 * @author DiosFer
 */
void buscar_trayecto_por_id_trayecto (const char id_trayecto_a_buscar[], const Trayecto vector_para_buscar[], const int util_vector, Trayecto t_sol[],int &util_vector_solucion);



 /**
 * @brief modulo para añadir un trayecto a un vector de trayectos
 * @param const Trayecto &t_aux trayecto que se quiere añair
 * @param Trayecto &trayectos_del_sistema []
 * @param int &util_trayectos_sistema
 * @version 0.9.7
 * @date 2023-03-27
 * @author DiosFer
 */
void anadir_trayecto_a_vector_trayectos (const Trayecto &t_aux, Trayecto trayectos_del_sistema[], int &util_trayectos_sistema);



 /**
 * @brief modulo para copiar una variable de tipo Trayecto en otra
 * @param Trayecto &t1 variable a copiar
 * @param Trayecto &t2 variable para pegar
 * @version 0.9.1
 * @date 2023-03-22
 * @author DiosFer
 */
void copiar_trayecto (const Trayecto &t1, Trayecto &t2);


/*****************************************************************************************************************************************
 *****************************************************************************************************************************************
 ****************************************************************************************************************************************/