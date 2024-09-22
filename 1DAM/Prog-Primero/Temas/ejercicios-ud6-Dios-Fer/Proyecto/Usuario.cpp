#include <iostream>
#include "Usuario.h"
#include "Cadenas.h"
#include "Enteros.h"


#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define gray "\033[0;37m"                  /* gray */

using namespace std;




/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Usuario *
 ***************************************************************************************************************************************/

void set_id_usuario(Usuario &usuario, char id_usuario[]){
    copiarVector_char(id_usuario, usuario.id_usuario);
}

void set_DNI(Usuario &usuario, char DNI[]){
    copiarVector_char(DNI, usuario.DNI);
}


void set_carnet (Usuario &usuario, bool c){
    usuario.carnet=c;
}


void set_nombre_usuario (Usuario &usuario, char nombre_usuario[]){
    copiarVector_char(nombre_usuario, usuario.nombre_usuario);
}


void set_nombre (Usuario &usuario, char nombre[]){
    copiarVector_char(nombre, usuario.nombre);
}


void set_apellido1 (Usuario &usuario, char apellido1[]){
    copiarVector_char(apellido1, usuario.apellido1);
}


void set_apellido2 (Usuario &usuario, char apellido2[]){
    copiarVector_char(apellido2, usuario.apellido2);
}


void set_edad (Usuario &usuario, int edad){
    usuario.edad=edad;
}


void set_movil (Usuario &usuario, char movil[]){
    copiarVector_char(movil, usuario.movil);
}


void set_contrasena (Usuario &usuario, char contrasena[]){
    copiarVector_char(contrasena, usuario.contrasena);
}


void set_mail (Usuario &usuario, char mail[]){
    copiarVector_char(mail, usuario.mail);
}


void set_util_coche_usuario (Usuario &usuario, int util){
    usuario.util_coche_usuario=util;
}




void set_vector_coches_usuario (Usuario &usuario, const Coche c[]){
    int util=get_util_coche_usuario(usuario);
    
    for (int i=0; i<util; i++){
        copiar_coche(c[i], usuario.vector_coche_usuario[i]);
    }
    
}


void get_id_usuario (const Usuario &usuario, char id_usuario_del_usuario[]){
    copiarVector_char(usuario.id_usuario, id_usuario_del_usuario);
}


void get_DNI (const Usuario &usuario, char DNI_del_usuario[]){
    copiarVector_char(usuario.DNI, DNI_del_usuario);
}


bool get_carnet (const Usuario &usuario){
    return usuario.carnet;
}


void get_nombre_usuario (const Usuario &usuario, char nombre_usuario_del_usuario[]){
    copiarVector_char(usuario.nombre_usuario, nombre_usuario_del_usuario);
}


void get_nombre (const Usuario &usuario, char nombre_del_usuario[]){
    copiarVector_char(usuario.nombre, nombre_del_usuario);
}



void get_apellido1 (const Usuario &usuario, char apellido1_del_usuario[]){
    copiarVector_char(usuario.apellido1, apellido1_del_usuario);
}


void get_apellido2 (const Usuario &usuario, char apellido2_del_usuario[]){
    copiarVector_char(usuario.apellido2, apellido2_del_usuario);
}


int get_edad (const Usuario &usuario){
    return usuario.edad;
}


void get_movil (const Usuario &usuario, char movil_del_usuario[]){
    copiarVector_char(usuario.movil, movil_del_usuario);
}


void get_contrasena (const Usuario &usuario, char contrasena_del_usuario[]){
    copiarVector_char(usuario.contrasena, contrasena_del_usuario);
}


void get_mail (const Usuario &usuario, char mail_del_usuario[]){
    copiarVector_char(usuario.mail, mail_del_usuario);
}


int get_util_coche_usuario (const Usuario &usuario){


    return usuario.util_coche_usuario;

}



void get_coches_usuario (const Usuario &usuario, Coche c[]){
    int util=get_util_coche_usuario(usuario);
    
    for (int i=0; i<util; i++){
        copiar_coche(usuario.vector_coche_usuario[i], c[i]);
    }
    
}




/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Front*
 ***************************************************************************************************************************************/
    




void mostrar_usuario (const Usuario &usuario){
    char cadena_aux_dim_id_usuario[DIM_ID_USUARIO]={'\0'};
    char cadena_aux_dim_dni[DIM_DNI]={'\0'};
    char cadena_aux_dim_cadena_normal_u[DIM_CADENA_NORMAL_U]={'\0'};
    char cadena_aux_dim_movil[DIM_MOVIL]={'\0'};
    int aux=0;
    Coche coche_aux[DIM_COCHES];


    cout << endl << BOLDBLUE<<endl;

    get_id_usuario (usuario, cadena_aux_dim_id_usuario);
    cout <<"id_usuario--> ";
    mostrar_cadena(cadena_aux_dim_id_usuario);
    cout << endl;

    get_DNI (usuario, cadena_aux_dim_dni);
    cout <<"DNI--> ";
    mostrar_cadena(cadena_aux_dim_dni);
    cout << endl;

    aux = get_carnet(usuario);
    cout << "carnet--> " << aux << endl;

    get_nombre_usuario (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"nombre_usuario--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_u);
    cout << endl;

    get_nombre (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"nombre--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_u);
    cout << endl;

    get_apellido1 (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"apellido1--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_u);
    cout << endl;

    get_apellido2 (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"apellido2--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_u);
    cout << endl;

    aux=get_edad (usuario);
    cout <<"edad--> "<< aux<<endl;

    get_movil (usuario, cadena_aux_dim_movil);
    cout <<"movil--> ";
    mostrar_cadena(cadena_aux_dim_movil);
    cout << endl;

    get_contrasena (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"contrasena--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_u);
    cout << endl;
    
    get_mail (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"mail--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_u);
    cout << endl;


    aux=get_util_coche_usuario (usuario);
    cout <<"util--> "<< aux<<endl;


    get_coches_usuario (usuario, coche_aux);
    for (int i=0; i<aux; i++){
        mostrar_coche(coche_aux[i]);
    }


    cout << endl<<RESTORE;
}


void introducir_Usuario (Usuario &usuario){
    char cadena_aux_dim_id_usuario[DIM_ID_USUARIO]={'\0'};
    char cadena_aux_dim_dni[DIM_DNI]={'\0'};
    char cadena_aux_dim_cadena_normal_u[DIM_CADENA_NORMAL_U]={'\0'};
    char cadena_aux_dim_movil[DIM_MOVIL]={'\0'};
    int aux=0;
    Coche coche_aux[DIM_COCHES];


    introducir_cadena_numero_caracteres_filtrado("Introduzca el id_usuario: ", cadena_aux_dim_id_usuario, DIM_ID_USUARIO, true, 8, true, 8, "No cumple con el tamaño establecido");
    set_id_usuario (usuario, cadena_aux_dim_id_usuario);
    
    introducir_cadena_numero_caracteres_filtrado("Introduzca el DNI: ", cadena_aux_dim_dni, DIM_DNI, true, 9, true, 9, "No cumple con el tamaño establecido");
    set_DNI (usuario, cadena_aux_dim_dni);


    aux=introducir_int_filtrado ("Introduzca 1 si tiene carnet o 0 si no tiene carnet: \n", -1, 2, "Entrada no valida");
    set_carnet (usuario, aux);
    cin.ignore(10000, '\n');
    
    

    introducir_cadena_numero_caracteres_filtrado("Introduzca el nombre_usuario: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_nombre_usuario (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el nombre: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_nombre (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el apellido1: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_apellido1 (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el apellido2: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_apellido2 (usuario, cadena_aux_dim_cadena_normal_u);


    aux=introducir_int_filtrado ("Introduce la edad: \n", 16, 120, "Edad no valida");
    set_edad (usuario, aux);
    cin.ignore(10000, '\n');

    introducir_cadena_numero_caracteres_filtrado("Introduzca el movil: ", cadena_aux_dim_movil, DIM_MOVIL, true, 9, true, 9, "No cumple con el tamaño establecido");
    set_movil (usuario, cadena_aux_dim_movil);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el contrasena: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, true, 8, false, 0, "No cumple con el tamaño establecido");
    set_contrasena (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el mail: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, "No cumple con el tamaño establecido");
    set_mail (usuario, cadena_aux_dim_cadena_normal_u);


    aux=introducir_int_filtrado ("El numero de coches (max 5): \n", -1, 6, "Edad no valida");
    set_util_coche_usuario (usuario, aux);
    cin.ignore(10000, '\n');




    for (int i=0; i<aux; i++){//aux=util_coche_usuario
        introducir_coche (coche_aux[i]);
    }

    set_vector_coches_usuario (usuario, coche_aux);


    if (DEBUG_C_Usuario==true){
        cout << DEBUG << "DEBUG"<<endl;
        mostrar_usuario(usuario);
        cout << "DEBUG"<<RESTORE<<endl;
    }

}


/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Back*
 ***************************************************************************************************************************************/






/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/