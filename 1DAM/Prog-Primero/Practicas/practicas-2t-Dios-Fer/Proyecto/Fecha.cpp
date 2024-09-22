#include <iostream>
#include "Fecha.h"
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

using namespace std;


/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Fecha *
 ***************************************************************************************************************************************/


void set_dia(Fecha &f, int UnDia){
    f.dia=UnDia;
}

void set_mes(Fecha &f, int UnMes){
    f.mes=UnMes;
}

void set_ano(Fecha &f, int UnAno){
    f.ano=UnAno;
}

int get_dia (const Fecha &f){
    return f.dia;
}

int get_mes (const Fecha &f){
    return f.mes;
}

int get_ano (const Fecha &f){
    return f.ano;
}



/***************************************************************************************************************************************
                                                        * Modulos de la estructura Fecha Front*
 ***************************************************************************************************************************************/
    




void mostrar_fecha (const Fecha &f){

    int aux=0;
    cout << BOLDBLUE;
    

    aux=get_ano(f);
    cout << aux <<"-";


    aux=get_mes(f);

    if (aux<10){
        cout << "0";
    }

    cout << aux <<"-";


    aux=get_dia(f);

    if (aux<10){
        cout << "0";
    }

    cout << aux;


    cout << RESTORE;

}

void Poner_fecha (Fecha &f, int aux_ano, int aux_mes, int aux_dia){
    set_ano (f, aux_ano);

    set_mes (f, aux_mes);

    set_dia(f, aux_dia);

}

void introducir_Fecha (Fecha &f){
    int aux_ano=0;
    int aux_mes=0;
    int aux_dia=0;

    aux_ano = introducir_int_filtrado ("Introduzca el año: \n", 2019, 2025, "el año esta mal introducido \n");

    aux_mes = introducir_int_filtrado ("Introduzca el mes (1-12): \n", 0, 13, "Se ha introducido mal el mes \n");

    aux_dia = introducir_int_filtrado ("Introduzca el dia (1-31): \n", 0, 32, "El dia esta mal introducido \n");

    Poner_fecha (f, aux_ano, aux_mes, aux_dia);

}

/***************************************************************************************************************************************
                                                       * Modulos Back de la estructura Fecha *
 ***************************************************************************************************************************************/

void Copiar_Fecha (const Fecha &f1, Fecha &f2){
    int aux=0;

    aux=get_dia (f1);
    set_dia (f2, aux);

    aux=get_mes (f1);
    set_mes (f2, aux);

    aux=get_ano (f1);
    set_ano (f2, aux);

}