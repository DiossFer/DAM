#include <iostream>
#include "Coche.h"
using namespace std;

const int DIM_CADENA_NORMAL_U=50; //Dimension para cadenas que no tienen un limite establecido (para nombres, correos, ...)
const int DIM_DNI=11;
const int DIM_MOVIL=11;
const int DIM_ID_USUARIO=10;

const bool DEBUG_C_Usuario=false;

const int DIM_COCHES=5;

/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Usuario *
 ***************************************************************************************************************************************/
struct Usuario{

    char id_usuario[DIM_ID_USUARIO];
    char DNI[DIM_DNI];

    bool carnet; 

    char nombre_usuario [DIM_CADENA_NORMAL_U]; 

    char nombre [DIM_CADENA_NORMAL_U];
    char apellido1 [DIM_CADENA_NORMAL_U];
    char apellido2 [DIM_CADENA_NORMAL_U];

    int edad; 
    char movil[DIM_MOVIL]; 

    char contrasena[DIM_CADENA_NORMAL_U];
    char mail[DIM_CADENA_NORMAL_U];

    Coche vector_coche_usuario[DIM_COCHES];
    int util_coche_usuario;

};


/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Usuario *
 ***************************************************************************************************************************************/


/**
 * @brief Modulo que establece un valor concreto para el miembro id_usuario de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char id_usuario [] vector que se quiere introducir en el miembro id_usuario de la variable de tipo Usuario usuario
 * @date 2023-3-16
 * @version 0.4
 * @author DiosFer
 */
void set_id_usuario(Usuario &usuario, char id_usuario[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro DNI de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI [] vector que se quiere introducir en el miembro DNI de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_DNI(Usuario &usuario, char DNI[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro carnet de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param bool carnet introducir en el miembro carnet de la variable de tipo Usuario usuario
 * @date 2023-3-22
 * @version 0.9.2
 * @author DiosFer
 */
void set_carnet (Usuario &usuario, bool c);

/**
 * @brief Modulo que establece un valor concreto para el miembro nombre_usuario de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre_usuario [] vector que se quiere introducir en el miembro nombre_usuario de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_nombre_usuario (Usuario &usuario, char nombre_usuario[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro nombre de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre [] vector que se quiere introducir en el miembro nombre de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_nombre (Usuario &usuario, char nombre[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro apellido1 de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido1 [] vector que se quiere introducir en el miembro apellido1 de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_apellido1 (Usuario &usuario, char apellido1[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro apellido2 de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido2 [] vector que se quiere introducir en el miembro apellido2 de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_apellido2 (Usuario &usuario, char apellido2[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro edad de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param int edad variable que se quiere introducir en el miembro edad de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_edad (Usuario &usuario, int edad);

/**
 * @brief Modulo que establece un valor concreto para el miembro movil de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char movil [] vector que se quiere introducir en el miembro movil de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_movil (Usuario &usuario, char movil[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro contrasena de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char contrasena [] vector que se quiere introducir en el miembro contrasena de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_contrasena (Usuario &usuario, char contrasena[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro mail de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char mail [] vector que se quiere introducir en el miembro mail de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_mail (Usuario &usuario, char mail[]);


/**
 * @brief Modulo que establece un valor concreto para el miembro util_coche_usuario de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param int util entero que se quiere introducir en el miembro util_coche_usuario de la variable de tipo Usuario usuario
 * @date 2023-3-20
 * @version 0.8.1
 * @author DiosFer
 */
void set_util_coche_usuario (Usuario &usuario, int util);


/**
 * @brief Modulo que establece un valor concreto para el miembro vector_coches_usuario de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param const Coche c [] vector que se quiere introducir en el miembro vector_coches_usuario de la variable de tipo Usuario usuario
 * @pre const Choche &c[] <-- Su util debera ser la misma que usuario.util_coche_usuario; ya que se quiere introdudir los miembros (coshes) de la cadena en nuestro usuario.vector_coche_usuario
 * @date 2023-3-20
 * @version 0.8.1
 * @author DiosFer
 */
void set_vector_coches_usuario (Usuario &usuario, const Coche c[]);


/**
 * @brief Modulo para obtener el valor del miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char id_usuario_del_usuario [] vector en el que se guardara el resultado (en este caso el id_usuario del usuario introducido)
 * @date 2023-3-16
 * @version 0.4
 * @author DiosFer
 */
void get_id_usuario (const Usuario &usuario, char id_usuario_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_DNI (const Usuario &usuario, char DNI_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro carnet de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char carnet_del_usuario [] vector en el que se guardara el resultado (en este caso el carnet del usuario introducido)
 * @date 2023-3-22
 * @version 0.9.2
 * @author DiosFer
 */
void get_carnet (const Usuario &usuario, char carnet_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro nombre_usuario de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre_usuario_del_usuario [] vector en el que se guardara el resultado (en este caso el nombre_usuario del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_nombre_usuario (const Usuario &usuario, char nombre_usuario_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro nombre de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre_del_usuario [] vector en el que se guardara el resultado (en este caso el nombre del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_nombre (const Usuario &usuario, char nombre_del_usuario[]);


/**
 * @brief Modulo para obtener el valor del miembro apellido1 de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido1_del_usuario [] vector en el que se guardara el resultado (en este caso el apellido1 del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_apellido1 (const Usuario &usuario, char apellido1_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro apellido2 de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido2_del_usuario [] vector en el que se guardara el resultado (en este caso el apellido2 del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_apellido2 (const Usuario &usuario, char apellido2_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro edad de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @return int usuario.edad
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
int get_edad (const Usuario &usuario);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_movil (const Usuario &usuario, char movil_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_contrasena (const Usuario &usuario, char contrasena_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_mail (const Usuario &usuario, char mail_del_usuario[]);


/**
 * @brief Modulo para obtener el valor del miembro util_coche_usuario de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @return int util 
 * @date 2023-3-20
 * @version 0.8.1
 * @author DiosFer
 */
int get_util_coche_usuario (const Usuario &usuario);


/**
 * @brief Modulo para obtener el valor del miembro vector_coche_usuario de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param Coche c [] vector en el que se guardara el resultado (en este caso el vector_coche_usuario del usuario introducido)
 * @date 2023-3-20
 * @version 0.8.1
 * @author DiosFer
 */
void get_coches_usuario (const Usuario &usuario, Coche c[]);



/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Front*
 ***************************************************************************************************************************************/
    


/**
 * @brief Modulo para mostrar el valor de todos lo miembros de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario que se quiere mostrar
 * @date 2023-3-20
 * @version 0.8.1
 * @author DiosFer
 */
void mostrar_usuario (const Usuario &usuario);

/**
 * @brief Modulo para introducir todos los miembros de la variable de tipo Usuario introducida
 * @param Usuario &usuario variable de tipo Usuario que se quiere rellenar
 * @date 2023-3-20
 * @version 0.8.1
 * @author DiosFer
 */
void introducir_Usuario (Usuario &usuario);



/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Back*
 ***************************************************************************************************************************************/




/*****************************************************************************************************************************************
 *****************************************************************************************************************************************
 ****************************************************************************************************************************************/