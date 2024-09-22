#include <iostream>
#include <ctime>

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

/////////////////////////////////////////////////////////////////////////	struct

struct Time{

	int hora; //0-11
	bool am; //true(am)//false(pm)
	int minuto; //0-59
	int segundo; //0-59

};

struct Fecha{

    int dia;//1-31
    int mes;//1-12
    int ano;

};

/***************************************************************************************************************************************
                                                                  * Modulos INT *
 ***************************************************************************************************************************************/

/**
 * @brief Modulo para la insercion de un numero sin filtrar
 * @param const char mensaje_entrada
 * @return int numero 
 * @date 2023-03-13
 * @version 2.1
 * @author DiosFer
 */
int introducir_int (const char mensaje_entrada[]);

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

/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Time *
 ***************************************************************************************************************************************/

/**
 * @brief Modulo que establece un valor concreto para el miembro hora de una variable de tipo Time.
 * @param Time &t variable de tipo Time (0-11)
 * @param int unahora valor que se le va a asignar a la variable t, para el miembro hora
 */
void sethoraF12(Time &t, int unahora);

/**
 * @brief Modulo que establece un valor concreto para el miembro am de una variable de tipo Time.
 * @param Time &t variable de tipo Time
 * @param bool ampm valor que se le va a asignar a la variable t, para el miembro am
 */
void setAm(Time &t, bool ampm);
/**
 * @brief Modulo que establece un valor concreto para el miembro minuto de una variable de tipo Time.
 * @param Time &t variable de tipo Time
 * @param int unminuto valor que se le va a asignar a la variable t, para el miembro minuto
 */
void setminuto(Time &t, int unminuto);

/**
 * @brief Modulo que establece un valor concreto para el miembro segundo de una variable de tipo Time.
 * @param Time &t variable de tipo Time
 * @param int unsegundo valor que se le va a asignar a la variable t, para el miembro segundo
 */
void setsegundo(Time &t, int unasegundo);

/**
 * @brief Modulo que devuelve el valor del miembro hora de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.hora 
 */
int gethora(const Time &t);

/**
 * @brief Modulo que devuelve el valor del miembro am de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.am 
 */
bool getAm(const Time &t);

/**
 * @brief Modulo que devuelve el valor del miembro segundo de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.segundo
 */
int getsegundo(const Time &t);

/**
 * @brief Modulo que devuelve el valor del miembro minuto de una variable de tipo Time.
 * @param const Time &t variable de tipo Time
 * @return t.minuto
 */
int getminuto(const Time &t);

/**
 * @brief Modulo que establece un valor concreto para el miembro hora de una variable de tipo Time.
 * @param Time &t variable de tipo Time (0-23)
 * @param int unahora valor que se le va a asignar a la variable t, para el miembro hora
 */
void sethoraF24(Time &t, int unahora);

/***************************************************************************************************************************************
											           * Modulos Front de la estructura Time *
 ***************************************************************************************************************************************/

/**
 * @brief Modulo para imprimir la variable de tipo Time t en formato am/pm
 * @param const Time t 
 * @post se mostrara el tiempo en formato HH:MM:SS AM/PM
 */
void printTime(const Time &t);





/**
 * @brief modulo para entrada a una estructura de una hora, am, minuto y segundo
 * @param const Time &t (E/S)
 * @param int &hora (E)
 * @param bool am (E)
 * @param int minuto (E)
 * @param int segundo (E)
 * @post se actualizara la estructura
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
void Poner_hora (Time &t, int hora, bool am, int minuto, int segundo);


void Introducir_Time (Time &t);

/***************************************************************************************************************************************
                                                       * Modulos Back de la estructura Time *
 ***************************************************************************************************************************************/




/**
 * @brief modulo para calcular en funcion de una hora 0-23 si es am o pm
 * @param Time &ahora (E/S)
 * @post am se actualizara
 * @version 1.0
 * @date 2023-03-08
 * @author DiosFer
 */
void calcular_am_pm_24 (Time &ahora);



/**
 * @brief modulo para en funcion de si es am o pm una estructura de tipo Time se actualice su hora a formato 0-11
 * @param Time &ahora (E/S)
 * @pre debe de tener el booleano am actualizado para indicar se es am o pm (se puede usar calcular_am_pm_24)
 * @post se cambiara el formato de la hora en la estructura introducida
 * @version 1.0
 * @date 2023-03-08
 * @author DiosFer
 */
void actualizar_hora_formato_24_a_12 (Time &ahora);

/**
 * @brief modulo para pasar un determinado numero de segundos al formato que tenemos en la estructura Time y actualizar una estructura 
 * @param Time &t (E/S)
 * @param int segundos
 * @post se actualizara la estructura a lo equivalente a los segundos introducidos
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
void segundos_a_resto_Y_actualizar_structure (Time &t, int segundos);



/**
 * @brief modulo para obtener el tiempo actual
 * @param Time &t (S)
 * @version 2.0
 * @date 2023-03-17
 * @author DiosFer
 */
void CogerTiempoActual(Time &t);




/**
 * @brief modulo para pasar una estructura de Time completamente a segundos
 * @param Time &t (E)
 * @return int segundos_t numero de segundos totales que tenia la estructura introducida
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
int pasar_todo_a_segundos (const Time &t);

/**
 * @brief modulo para calcular la diferencia de Time entre dos estructuras Time y guardar la diferencia en una tercera
 * @param const Time &desde (E)
 * @param const Time &hasta (E)
 * @param Time &diferencia (S)
 * @post la diferencia de Time se guardara en Time &diferencia
 * @version 2.0
 * @date 2023-03-08
 * @author DiosFer
 */
void diferencia_Time(const Time &desde, const Time &hasta, Time &diferencia);


  //=====================================================================================================================================\\
 //_______________________________________________________________________________________________________________________________________\\
//_________________________________________________________________________________________________________________________________________\\

int main (){

	Time alarma;
	Time actual;
    Time diferencia;


    CogerTiempoActual(actual);
    printTime (actual);

    Introducir_Time(alarma);
    printTime(alarma);

    diferencia_Time(actual, alarma, diferencia);
    printTime(diferencia);

}





int introducir_int (const char mensaje_entrada[]){
    int numero=0;
    bool EstaBien=true;

    cout << mensaje_entrada;

    do{

        EstaBien=true;
        cin>>numero;

        if(cin.fail()==1){

                cin.clear();
                cin.ignore(10000, '\n');

                cout << BOLDRED << "Por favor introduzca un numero"<<RESET<<endl<<endl;
                EstaBien=false;

        }
        
    }while(EstaBien==false);

    return numero;
}


int introducir_int_filtrado (const char mensaje_entrada[], int NoMenorA, int NoMayorA, const char mensaje_error[]){
    int numero=0;
    bool EstaBien=true;

    

    do{

        EstaBien=true;
        cout << mensaje_entrada;
        cin>>numero;

        if (numero<=NoMenorA || numero>=NoMayorA){
            EstaBien=false;
            cout << mensaje_error<<endl<<endl;
        }

        if(cin.fail()==1 && EstaBien==true){

                cin.clear();
                cin.ignore(10000, '\n');

                cout << BOLDRED << "Por favor introduzca un numero"<<RESET<<endl<<endl;
                EstaBien=false;

        }


    }while(EstaBien==false);

    return numero;
}

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

    cout << endl;
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