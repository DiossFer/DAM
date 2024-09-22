#include <iostream>
#include "Cadenas.h"

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


void agregarLetraACadena(char vector[], int i, char letra){

    vector[i] = letra;

}


int get_Longitud (const char cadena []){

    int longitud=0;

    while (cadena[longitud] != '\0'){
        longitud++;
    }

    return longitud;

}


void copiarVector_char(const char vector[], char copia[]){

    int longitud_vector=get_Longitud (vector);
    int j=0;

    for (int i=0; i<=longitud_vector; i++){
        agregarLetraACadena(copia, i, vector[i]);
    }
}


void introducir_cadena_numero_caracteres_filtrado (const char mensaje[], char cadena[], const int DIM_AUX, bool minimo_establecido, int minimo, bool maximo_establecido, int maximo, const char mensaje_error[]){
    int longitud=0;
    bool estabien=false;
    bool pasado_dim=false;

    do{
        pasado_dim=false;
        estabien=false;

        cout << mensaje<<endl;

        cin.getline(cadena, DIM_AUX, '\n');

        if (cin.fail()){//si se intenta leer una cantidad superior a la DIM_AUX se detendra y fallara
            cin.clear();
            cin.ignore(10000, '\n');
            pasado_dim=true;
        }


        longitud=get_Longitud(cadena);


        if (minimo_establecido==true){
            if(longitud>=minimo){
                estabien=true;
            }
        }
        else{
            estabien=true;
        }
        if (estabien==true){
            if (maximo_establecido==true){
                if(longitud<=maximo){
                    estabien=true;
                }
                else{
                    estabien=false;
                }
            }
            else{
                estabien=true;
            }
        }


        if (pasado_dim){
            estabien=false;
        }


        if(!estabien){
            cout <<BOLDRED<< mensaje_error << endl<<RESTORE;
        }
        

    }while(!estabien);
    
}


void mostrar_cadena (const char cadena[]){
    for (int i=0; cadena[i]!='\0'; i++){
        cout << cadena[i];
    }
    
}


bool comparar_cadenas(const char c1[], const char c2[]){
    bool igual=true;
    bool fin = false;

    for (int i=0; igual==true && fin==false; i++){
        if (c1[i]!=c2[i]){
            igual=false;
        }
        if(c1[i]=='\0' && c2[i]=='\0'){
            fin=true;
        }
    }
    return igual;
}