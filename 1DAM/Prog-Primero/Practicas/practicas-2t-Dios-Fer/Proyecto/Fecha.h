#include <iostream>

using namespace std;

const bool DEBUG_C_Fecha=false;


/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Fecha *
 ***************************************************************************************************************************************/

struct Fecha{

    int dia;//1-31
    int mes;//1-12
    int ano;//por el momento --> 2020-2024

};

/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Fecha *
 ***************************************************************************************************************************************/

/**
 * @brief Modulo que establece un valor concreto para el miembro dia de una variable de tipo Fecha.
 * @param Fecha &f variable de tipo Fecha 
 * @param int UnDia variable que se quiere introducir en el miembro de la estructura
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
void set_dia(Fecha &f, int UnDia);


/**
 * @brief Modulo que establece un valor concreto para el miembro mes de una variable de tipo Fecha.
 * @param Fecha &f variable de tipo Fecha 
 * @param int UnMes variable que se quiere introducir en el miembro de la estructura
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
void set_mes(Fecha &f, int UnMes);



/**
 * @brief Modulo que establece un valor concreto para el miembro ano de una variable de tipo Fecha.
 * @param Fecha &f variable de tipo Fecha 
 * @param int UnAno variable que se quiere introducir en el miembro de la estructura
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
void set_ano(Fecha &f, int UnAno);


/**
 * @brief Modulo para obtener el valor del miembro dia de una variable de tipo Fecha
 * @param Fecha &f variable de tipo Fecha 
 * @return int f.dia
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
int get_dia (const Fecha &f);

/**
 * @brief Modulo para obtener el valor del miembro mes de una variable de tipo Fecha
 * @param Fecha &f variable de tipo Fecha 
 * @return int f.mes
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
int get_mes (const Fecha &f);

/**
 * @brief Modulo para obtener el valor del miembro ano de una variable de tipo Fecha
 * @param Fecha &f variable de tipo Fecha 
 * @return int f.ano
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
int get_ano (const Fecha &f);

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Fecha Front*
 ***************************************************************************************************************************************/
    



/**
 * @brief Modulo para mostrar por pantalla una variable de tipo Fecha formato AAAA-MM-DD
 * @param Fecha &f variable de tipo Fecha que se quiere mostrar
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
void mostrar_fecha (const Fecha &f);


/**
 * @brief Modulo para introducir las variables correspondiente a una variable de tipo Fecha
 * @param Fecha &f variable de tipo Fecha que se quiere rellenar
 * @param int aux_ano variable para introducir en el miembro f.ano
 * @param int aux_mes variable para introducir en el miembro f.mes
 * @param int aux_dia variable para introducir en el miembro f.dia
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
void Poner_fecha (Fecha &f, int aux_ano, int aux_mes, int aux_dia);


/**
 * @brief Modulo para introducir todos los miembros de la variable de tipo Fecha 
 * @param Fecha &f variable de tipo Fecha que se quiere rellenar
 * @date 2023-3-18
 * @version 0.7
 * @author DiosFer
 */
void introducir_Fecha (Fecha &f);

/***************************************************************************************************************************************
                                                       * Modulos Back de la estructura Fecha *
 ***************************************************************************************************************************************/

/**
 * @brief modulo para copiar una variable de tipo Fecha en otra
 * @param Fecha &t1 variable a copiar
 * @param Fecha &t2 variable para pegar
 * @version 0.9.1
 * @date 2023-03-22
 * @author DiosFer
 */
void Copiar_Fecha (const Fecha &f1, Fecha &f2);