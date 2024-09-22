#include <iostream>
#include "Cadenas.h"
#include "Enteros.h"
#include "Viaje.h"


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
                                                   * Modulos sets y gets de la estructura Viaje *
 ***************************************************************************************************************************************/

void set_coche_que_viaja (Viaje &v, const Coche &c){    
    copiar_coche(c, v.coche_que_viaja);
}

void set_trayecto_que_se_realiza (Viaje &v, const Trayecto &t){    
    copiar_trayecto(t, v.trayecto_que_se_realiza);
}


void set_hora_salida (Viaje &v, const Time &t){    
    Copiar_Time(t, v.hora_salida);
}


void set_hora_llegada (Viaje &v, const Time &t){    
    Copiar_Time(t, v.hora_llegada);
}


void set_fecha_salida (Viaje &v, const Fecha &f){    
    Copiar_Fecha(f, v.fecha_salida);
}


void set_fecha_llegada (Viaje &v, const Fecha &f){    
    Copiar_Fecha(f, v.fecha_llegada);
}


void set_numero_asiento_ofertados (Viaje &v, int num_asi){
    v.numero_asientos_ofertados=num_asi;
}




void get_coche_que_viaja (const Viaje &v, Coche &c){
    copiar_coche(v.coche_que_viaja, c);
}

void get_trayecto_que_se_realiza (const Viaje &v, Trayecto &t){
    copiar_trayecto(v.trayecto_que_se_realiza, t);
}


void get_hora_salida (const Viaje &v, Time &t){
    Copiar_Time(v.hora_salida, t);
}


void get_hora_llegada (const Viaje &v, Time &t){
    Copiar_Time(v.hora_llegada, t);
}


void get_fecha_salida (const Viaje &v, Fecha &f){
    Copiar_Fecha(v.fecha_salida, f);
}


void get_fecha_llegada (const Viaje &v, Fecha &f){
    Copiar_Fecha(v.fecha_llegada, f);
}


int get_numero_asiento_ofertados (const Viaje &v){
    return v.numero_asientos_ofertados;
}

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Viaje Front*
 ***************************************************************************************************************************************/

void mostrar_viaje (const Viaje &v){

    int aux=0;
    Coche aux_c;
    Trayecto aux_tr;
    Fecha aux_f;
    Time aux_ti;

    cout <<endl<< "     Coche en el que se viaja"<<endl<<endl;
    get_coche_que_viaja (v, aux_c);
    mostrar_coche (aux_c);

    cout <<endl<< "     Trayecto viajado"<<endl<<endl;
    get_trayecto_que_se_realiza (v, aux_tr);
    mostrar_trayecto(aux_tr);

    cout <<endl<< "     Hora salida"<<endl<<endl;
    get_hora_salida (v, aux_ti);
    printTime (aux_ti);

    cout <<endl<< "     Hora llegada"<<endl<<endl;
    get_hora_llegada (v, aux_ti);
    printTime (aux_ti);

    cout <<endl<< "     Fecha salida"<<endl<<endl;
    get_fecha_salida (v, aux_f);
    mostrar_fecha (aux_f);

    cout <<endl<< "     Fecha llegada"<<endl<<endl;
    get_fecha_llegada (v, aux_f);
    mostrar_fecha (aux_f);

    
    aux=get_numero_asiento_ofertados (v);
    cout <<endl<< "     Asientos_ofertados--> "<< aux<<endl;
}


void introducir_viaje (Viaje &v){
    int aux=0;
    Coche aux_c;
    Trayecto aux_tr;
    Fecha aux_f;
    Time aux_ti;


    cout << endl<<"     Introduzca el coche del viaje: "<<endl<<endl;
    introducir_coche (aux_c);
    set_coche_que_viaja (v, aux_c);

    cout <<endl<< "     Introduzca el trayecto del viaje: "<<endl<<endl;
    introducir_trayecto (aux_tr);
    set_trayecto_que_se_realiza (v, aux_tr);


    cout <<endl<< "     Introduzca la hora de salida del viaje: "<<endl<<endl;
    Introducir_Time (aux_ti);
    set_hora_salida (v, aux_ti);


    cout <<endl<< "     Introduzca la hora de llegada del viaje: "<<endl<<endl;
    Introducir_Time (aux_ti);
    set_hora_llegada (v, aux_ti);

    cout <<endl<< "     Introduzca la fecha de salida del viaje: "<<endl<<endl;
    introducir_Fecha (aux_f);
    set_fecha_salida (v, aux_f);

    cout <<endl<< "     Introduzca la fecha de llegada del viaje: "<<endl<<endl;
    introducir_Fecha (aux_f);
    set_fecha_llegada (v, aux_f);



    aux = introducir_int_filtrado ("Introduzca el numero de asientos ofertados: \n", -1, (get_numero_asientos(v.coche_que_viaja)+1), "Asientos_ofertados no validos");
    cin.ignore(10000, '\n');
    set_numero_asiento_ofertados(v, aux);
}




/***************************************************************************************************************************************
                                                        * Modulos de la estructura Viaje Back*
 ***************************************************************************************************************************************/



/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/
