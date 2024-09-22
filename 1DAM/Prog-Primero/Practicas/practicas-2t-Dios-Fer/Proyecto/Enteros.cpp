#include <iostream>
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
                                                           * Modulos Tipo int *
 ***************************************************************************************************************************************/



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

        if(cin.fail()==1){

            cin.clear();
            cin.ignore(10000, '\n');

            cout << BOLDRED << "Por favor introduzca un numero"<<RESET<<endl<<endl;
            EstaBien=false;

        }


    }while(EstaBien==false);

    return numero;
}








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* --------------------------- INTENTO DE ADAPTAR LA MODA --------------------------- */

///////////////////////// Insercion reutilizada para las modas




void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, int entero){

    vector[util_vector] = entero;
    util_vector++;

}








void copiarVector(const int vector[], int util_vector, int copia[], int &util_copia, const int DIM_VECTOR_RESULTADO){
    util_copia=0;//Vamos a sustituir por completo el contenido


    for (int i=0; i<util_vector && i<DIM_VECTOR_RESULTADO; i++){

        agregarNuevoEnteroenVectorEnteros(copia, util_copia, vector[i]);
    }


}




int obrener_numero_mayor_en_vector (int vector[], int util_vector){
    int mayor=vector[0];
    for (int i=1; i<util_vector; i++){
        if (vector[i] > mayor){
            mayor=vector[i];
        }
    }
    return mayor;
}




void ubicar_numeroYenlazar_salida (int contador_moda, int vector_sin_reps[], int vector_contadores[], int util_numero_o_contador, int vector_salida_moda_modas [], int &util_vector_salida_moda_modas){
    for (int i=0; i<util_numero_o_contador; i++){
        if (vector_contadores[i]==contador_moda){
            vector_salida_moda_modas[util_vector_salida_moda_modas] = vector_sin_reps[i];
            util_vector_salida_moda_modas++;
            
        }
    }
}



void eliminar_numero_cadena(int vector_sin_reps[], int j, int &util_vector_sin_reps){


    for (j; j<util_vector_sin_reps;j++){


    vector_sin_reps[j]=vector_sin_reps[j+1];

    }

    util_vector_sin_reps--;

}





void contarYquitar_Numeros_repetidos (int vector_sin_reps[], int vector_contadores[], int &util_vector_sin_reps, int &util_vector_contadores){
    for (int i=0; i<util_vector_sin_reps; i++){

        int contador=1;

        for (int j=i+1; j<util_vector_sin_reps; j++){//sumo uno para separar el primero ya que siempre estara 1 vez minimo

            if (vector_sin_reps[i] == vector_sin_reps[j]){

                contador++;
                eliminar_numero_cadena(vector_sin_reps, j, util_vector_sin_reps);
                j--;

            }
            
        }
        vector_contadores[i]=contador;
        util_vector_contadores++;

    }
    
}




void calcular_modas(const int vector_a_evaluar[], int vector_sin_reps[], int vector_contadores[], int vector_salida_moda_modas[], int &contador_moda, int util_vector_a_evaluar, int &util_vector_sin_reps, int &util_vector_contadores, int &util_vector_salida_moda_modas, const int DIM_VECTOR_SIN_REPS){

    copiarVector(vector_a_evaluar, util_vector_a_evaluar, vector_sin_reps, util_vector_sin_reps, DIM_VECTOR_SIN_REPS);

    contarYquitar_Numeros_repetidos (vector_sin_reps, vector_contadores, util_vector_sin_reps, util_vector_contadores);

    contador_moda = obrener_numero_mayor_en_vector (vector_contadores, util_vector_contadores);

    ubicar_numeroYenlazar_salida (contador_moda, vector_sin_reps, vector_contadores, util_vector_sin_reps, vector_salida_moda_modas, util_vector_salida_moda_modas);


}



void Moda_minima_Moda_maxima(){


    const int DIM_VECTOR_A_EVALUAR = 100;
    int vector_a_evaluar[DIM_VECTOR_A_EVALUAR]={0};
    int util_vector_a_evaluar = 0; 


    const int DIM_VECTOR_SIN_REPS = 100;
    int vector_sin_reps[DIM_VECTOR_SIN_REPS]={0};
    int util_vector_sin_reps = 0; 


    const int DIM_VECTOR_CONTADORES = 100;
    int vector_contadores[DIM_VECTOR_CONTADORES]={0};
    int util_vector_contadores = 0; 


    const int DIM_VECTOR_SALIDA_MODA_MODAS = 100;
    int vector_salida_moda_modas[DIM_VECTOR_SALIDA_MODA_MODAS]={0};
    int util_vector_salida_moda_modas = 0; 

    int contador_moda=0;

    //entrada_vector(DIM_VECTOR_A_EVALUAR, vector_a_evaluar, util_vector_a_evaluar);

    //Salida del vector introducido
    cout << endl << "vector: "<<endl;
    //imprimeVectorEnteros(vector_a_evaluar, util_vector_a_evaluar);
    cout << endl << endl<<endl;


    cout << endl << endl<<"--------------------------------------------------------"<<endl;

    //calculamos moda
    calcular_modas(vector_a_evaluar, vector_sin_reps, vector_contadores, vector_salida_moda_modas, contador_moda, util_vector_a_evaluar, util_vector_sin_reps, util_vector_contadores, util_vector_salida_moda_modas, DIM_VECTOR_SIN_REPS);

    
    //Moda 
    //imprime_modas(vector_salida_moda_modas, util_vector_salida_moda_modas, contador_moda);
    cout << endl << endl<<endl;
    

    //Todos los numeros y sus repeticiones pertinentes
    //ranking(vector_sin_reps, vector_contadores, util_vector_sin_reps);
    cout << endl << endl<<endl;
    
}