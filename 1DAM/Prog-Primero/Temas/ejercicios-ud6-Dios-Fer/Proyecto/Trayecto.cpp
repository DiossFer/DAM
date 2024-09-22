#include <iostream>
#include "Cadenas.h"
#include "Enteros.h"
#include "Trayecto.h"

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
                                                   * Modulos sets y gets de la estructura Trayecto *
 ***************************************************************************************************************************************/

void set_id_trayecto(Trayecto &t, char id_tr[]){
    copiarVector_char(id_tr, t.id_trayecto);
}


void set_origen(Trayecto &t, char o[]){
    copiarVector_char(o, t.origen);
}


void set_destino(Trayecto &t, char d[]){
    copiarVector_char(d, t.destino);
}


void get_id_trayecto(const Trayecto &t, char id_tr[]){
    copiarVector_char(t.id_trayecto, id_tr);
}


void get_origen(const Trayecto &t, char o[]){
    copiarVector_char(t.origen, o);
}


void get_destino(const Trayecto &t, char d[]){
    copiarVector_char(t.destino, d);
}


/***************************************************************************************************************************************
                                                        * Modulos de la estructura Trayecto Front*
 ***************************************************************************************************************************************/
    


void mostrar_trayecto (const Trayecto &t){

    char cadena_aux_dim_id_trayecto[DIM_ID_TRAYECTO]={'\0'};
    char cadena_aux_dim_ubicacion[DIM_UBICACION]={'\0'};


    cout << endl << BOLDBLUE<<endl;

    get_id_trayecto (t, cadena_aux_dim_id_trayecto);
    cout <<"id_trayecto--> ";
    mostrar_cadena(cadena_aux_dim_id_trayecto);
    cout << endl;

    get_origen (t, cadena_aux_dim_ubicacion);
    cout <<"origen--> ";
    mostrar_cadena(cadena_aux_dim_ubicacion);
    cout << endl;


    get_destino (t, cadena_aux_dim_ubicacion);
    cout <<"destino--> ";
    mostrar_cadena(cadena_aux_dim_ubicacion);
    cout << endl;


    cout << endl<<RESTORE;
}


void introducir_trayecto (Trayecto &t){
    char cadena_aux_dim_id_trayecto[DIM_ID_TRAYECTO]={'\0'};
    char cadena_aux_dim_ubicacion[DIM_UBICACION]={'\0'};


    introducir_cadena_numero_caracteres_filtrado("Introduzca el id_trayecto: ", cadena_aux_dim_id_trayecto, DIM_ID_TRAYECTO, true, 8, true, 8, "No cumple con el tamaño establecido");
    set_id_trayecto (t, cadena_aux_dim_id_trayecto);
    
    introducir_cadena_numero_caracteres_filtrado("Introduzca el origen: ", cadena_aux_dim_ubicacion, DIM_UBICACION, false, 0, false, 0, " ");
    set_origen (t, cadena_aux_dim_ubicacion);

    introducir_cadena_numero_caracteres_filtrado("Introduzca el destino: ", cadena_aux_dim_ubicacion, DIM_UBICACION, false, 0, false, 0, " ");
    set_destino (t, cadena_aux_dim_ubicacion);

    if (DEBUG_C_Trayecto==true){
        cout << DEBUG << "DEBUG"<<endl;
        mostrar_trayecto(t);
        cout << "DEBUG"<<RESTORE<<endl;
    }

}


/***************************************************************************************************************************************
                                                        * Modulos de la estructura Trayecto Back*
 ***************************************************************************************************************************************/



void copiar_trayecto (const Trayecto &t1, Trayecto &t2){

    char vector_aux_dim_id_trayecto [DIM_ID_TRAYECTO];
    char vector_aux_dim_ubicacion [DIM_UBICACION];

    get_id_trayecto (t1, vector_aux_dim_id_trayecto);
    set_id_trayecto (t2, vector_aux_dim_id_trayecto);
    

    get_destino (t1, vector_aux_dim_ubicacion);
    set_destino (t2, vector_aux_dim_ubicacion);


    get_origen (t1, vector_aux_dim_ubicacion);
    set_origen (t2, vector_aux_dim_ubicacion);


}


/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/