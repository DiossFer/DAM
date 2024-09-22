#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

/**
 * @brief Módulo que agrega un nuevo número entero en el vector de enteros, al final de las componentes utilizadas.
 EJEMPLO:
 ENTRADA v = { 4 2 7 ? ? ? ? ... ? } util = 3 DIM_VECTOR = 2000 entero = 3
 SALIDA  v = { 4 2 7 3 ? ? ? ... ? } util = 4 DIM_VECTOR = 2000 entero = 3
 
 * @pre El número entero que queremos insertar está filtrado.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por REFERENCIA porque SÍ se va a cambiar el número de componentes utilizadas en el vector.
 * @param entero Es el nuevo número entero que quiero insertar en el vector.
 * @pre util_vector < DIM_VECTOR
 */
void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, int entero){

    vector[util_vector] = entero;
    util_vector++;

}


/**
 * @brief Módulo que imprimirá por pantalla un vector de enteros.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de sólo lectura del vector, lo paso como referencia constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va a cambiar el número de componentes utilizadas en el vector.
 * @post Se imprimirá por la pantalla de la consola el contenido del vector.
 */
void imprimeVectorEnteros(const int vector[], int util_vector){
    cout << "Vector Enteros = { ";
    for (int i=0; i < util_vector; i++){
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
}



/**
 * @brief Módulo para copiar manteniendo el tipo de ordenacion dos vectores ya ordenados (en este caso menor a mayor)
 * @pre los dos vectores deberan de estar ordenados (menor a mayor)
 * @param int vector_1
 * @param int util_vector_1
 * @param int vector_2
 * @param int util_vector_2
 * @param int vector_sol
 * @param int &util_vector_sol
 * @param const int DIM_VECTOR_SOL 
 * @post el vector sol tendra lo que tenia ordenado los otros dos vectores dentro de si mismo pero tambien ordenado
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
void copiar_ordenados_vectores_ordenados_minTOmax(int vector_1[], int util_vector_1, int vector_2[], int util_vector_2, int vector_sol[], int &util_vector_sol, const int DIM_VECTOR_SOL){
    int i=0;//contador de V1
    int j=0;//contador de V2
    for (; ((util_vector_1 > i || util_vector_2 > j) && (util_vector_sol<=DIM_VECTOR_SOL));){
        if (((vector_1[i] <= vector_2[j]) && util_vector_1>i)||util_vector_2<=j){

            agregarNuevoEnteroenVectorEnteros(vector_sol, util_vector_sol, vector_1[i]);
            i++;

        }
            
        else{//V2 menor
            agregarNuevoEnteroenVectorEnteros(vector_sol, util_vector_sol, vector_2[j]);
            j++;
        }

    }
}




int main (){
    const int DIM_VECTOR_1=100;
    int vector_1[DIM_VECTOR_1]={1, 3, 5, 7, 9, 20, 30};//ejemplo
    int util_vector_1=7;


    const int DIM_VECTOR_2=100;
    int vector_2[DIM_VECTOR_2]={2, 4, 6, 8, 10, 11};//ejemplo
    int util_vector_2=6;

    const int DIM_VECTOR_SOL=100;
    int vector_sol[DIM_VECTOR_SOL]={0};
    int util_vector_sol=0;


    copiar_ordenados_vectores_ordenados_minTOmax(vector_1, util_vector_1, vector_2, util_vector_2, vector_sol, util_vector_sol, DIM_VECTOR_SOL);

    imprimeVectorEnteros (vector_sol, util_vector_sol);

}