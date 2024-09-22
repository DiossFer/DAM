#include <iostream>
#include <ctime>
#include "Enteros.h"
#include "Tiempo.h"

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
                                                   * Modulos sets y gets de la estructura Time *
 ***************************************************************************************************************************************/


void sethoraF12(Time &t, int unahora){
    t.hora = unahora;
}


void setAm(Time &t, bool ampm){
    t.am = ampm;
}


void setminuto(Time &t, int unminuto){
    t.minuto = unminuto;
}


void setsegundo(Time &t, int unasegundo){
    t.segundo = unasegundo;
}


int gethora(const Time &t){
    //Código necesario antes, que no involucre a E/S (couts, cin, etc.)    
    return t.hora;
}


bool getAm(const Time &t){
    return t.am;
}


int getsegundo(const Time &t){
    return t.segundo;
}


int getminuto(const Time &t){
    return t.minuto;
}


void sethoraF24(Time &t, int unahora){
    if (unahora>12){
        unahora-=12;
        sethoraF12 (t, unahora);
        setAm(t, false);//pm
    }
    else{//<12
        sethoraF12 (t, unahora);
        setAm(t, true);//am
    }
}

/***************************************************************************************************************************************
                                                       * Modulos Front de la estructura Time *
 ***************************************************************************************************************************************/


void printTime(const Time &t){

    if (gethora(t) < 10){
        cout << 0;
    }

    cout << gethora(t) << ":" ;

    if (getminuto(t) < 10){
        cout << 0;
    }

    cout << getminuto(t) << ":" ;

    if (getsegundo(t) < 10){
        cout << 0;
    }

    cout << getsegundo(t);

    if (getAm(t)){
        cout << " AM";
    }

    else{
        cout << " PM";
    }

}







void Poner_hora (Time &t, int hora, bool am, int minuto, int segundo){
    t.hora=hora;
    t.am=am;
    t.minuto=minuto;
    t.segundo=segundo;
}


void Introducir_Time (Time &t){
    int aux_hora=0;
    bool aux_am=false;
    int aux_minuto=0;
    int aux_segundo=0;

    aux_hora = introducir_int_filtrado ("Introduzca la hora 0-11: \n", -1, 12, "La hora esta mal introducida \n");
    aux_am = introducir_int_filtrado ("Introduzca si es am (1) o pm (0): \n", -1, 2, "Se ha introducido mal el am-pm \n");
    aux_minuto = introducir_int_filtrado ("Introduzca los minutos 0-59: \n", -1, 60, "Los minutos estan mal introducidos \n");
    aux_segundo = introducir_int_filtrado ("Introduzca los segundos 0-59: \n", -1, 60, "Los minutos estan mal introducidos \n");

    Poner_hora (t, aux_hora, aux_am, aux_minuto, aux_segundo);
}

/***************************************************************************************************************************************
                                                       * Modulos Back de la estructura Time *
 ***************************************************************************************************************************************/


void Copiar_Time (const Time &t1, Time &t2){
    int aux_hora=0;
    bool aux_am=false;
    int aux_minuto=0;
    int aux_segundo=0;

    aux_hora=gethora (t1);
    aux_am=getAm (t1);
    aux_minuto=getsegundo (t1);
    aux_segundo=getminuto (t1);


    sethoraF12 (t2, aux_hora);
    setAm (t2, aux_am);
    setminuto (t2, aux_minuto);
    setsegundo (t2, aux_segundo);

}

void calcular_am_pm_24 (Time &ahora){
    
    ahora.am=(ahora.hora<12);
    
}




void actualizar_hora_formato_24_a_12 (Time &ahora){
    if (!ahora.am){
        ahora.hora-=12;
    }
}


void segundos_a_resto_Y_actualizar_structure (Time &t, int segundos){
    int hora=segundos/3600;
    segundos%=3600;

    bool am=(hora<12);
    if (!am){
        hora-=12;
    }

    int minuto=segundos/60;
    segundos%=60;

    Poner_hora (t, hora, am, minuto, segundos);
    
}




void CogerTiempoActual(Time &t){
    const int SEG_DIA=86400;//60*60*24
    const int DIFF_GMT=1*3600;// GMT +2 horas
    int aux_seg=0;
    time_t horaSistema;
    // Coger Segundos 1/1/1970 0:0:0GMT (hora local)

    horaSistema=time(0)+DIFF_GMT;

    aux_seg=horaSistema % SEG_DIA;


    segundos_a_resto_Y_actualizar_structure (t, aux_seg);
}





int pasar_todo_a_segundos (const Time &t){

    int segundos_t=t.hora*3600 + t.minuto*60 + t.segundo;

    if (!t.am){
        segundos_t+=3600*12;
    }
    return segundos_t;
}


void diferencia_Time(const Time &desde, const Time &hasta, Time &diferencia){
    int segundos_desde=0;
    int segundos_hasta=0;

    int segundos_diferencia=0;

    segundos_desde=pasar_todo_a_segundos(desde);

    segundos_hasta=pasar_todo_a_segundos(hasta);


    segundos_diferencia = segundos_hasta - segundos_desde;

    segundos_a_resto_Y_actualizar_structure(diferencia, segundos_diferencia);

}