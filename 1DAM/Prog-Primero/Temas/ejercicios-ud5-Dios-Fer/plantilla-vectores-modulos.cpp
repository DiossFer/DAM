//
//  ejemplovectoresmodulos.cpp
//
//
//  Created by Jaime Matas Bustos on 11/1/17.
//
//

#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

//DEBUG
const bool DEBUG_C=true;

/**
 * @brief Módulo para salida de un error al intentar añadir una celda a un vector lleno
 * @post indicara que no se puede añadir mas casillas al vector
 * @version 0.1
 * @author Dios-Fer
 * @date 2023-02-04
 */
void error (){

    cout << "No puedes añadir mas enteros al vector, este esta completamente lleno"<<endl;

}


/**
 * @brief Módulo para comprobar si hay hueco en un vector para añadir una celda mas
 * @post util_vector<DIM_VECTOR -->true 
 * @param DIM_VECTOR Es la constante que me indica la DIMENSIÓN del vector, esto es el número máximo de componentes que podré utilizar. Es fijo y no se puede alterar.
 * @version 1.1
 * @author Dios-Fer
 * @date 2023-06-04
 */


bool comprobar_hueco (int util_vector, const int DIM_VECTOR){

    bool espacio=true;

    if (util_vector>=DIM_VECTOR){

        error ();
        espacio=false;

    }

    return espacio;

}


/**
 * @brief Módulo que agrega un nuevo número entero en el vector de enteros, al principio del vector.
 EJEMPLO:
 ENTRADA v = { 4 2 7 ? ? ? ? ... ? } util = 3 DIM_VECTOR = 2000 entero = 3
 SALIDA  v = { 3 4 2 7 ? ? ? ... ? } util = 4 DIM_VECTOR = 2000 entero = 3
 
 * @pre El número entero que queremos insertar está filtrado.
 * @pre util_vector<DIM_VECTOR (hay hueco en en vector)
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por REFERENCIA porque SÍ se va a cambiar el número de componentes utilizadas en el vector.
 * @param entero Es el nuevo número entero que quiero insertar en el vector.
 * @version 1.1
 * @author Dios-Fer
 * @date 2023-06-04
 */
void AgregarIzquierdaNuevoEnteroenVectorEnteros(int vector[], int &util_vector, int entero){

    util_vector++; //actualizamos util_vector para añadir un numero

    for (int i=0; i<util_vector; i++){ //desplazamos todo uno a la derecha 
        vector[util_vector-i]=vector[util_vector-i-1];
    }

    vector[0]=entero; //añadimos a la izquierda del todo el nuevo entero

}

/**
 * @brief Módulo que agrega un nuevo número entero en el vector de enteros, al final de las componentes utilizadas.
 EJEMPLO:
 ENTRADA v = { 4 2 7 ? ? ? ? ... ? } util = 3 DIM_VECTOR = 2000 entero = 3
 SALIDA  v = { 4 2 7 3 ? ? ? ... ? } util = 4 DIM_VECTOR = 2000 entero = 3
 
 * @pre El número entero que queremos insertar está filtrado.
 * @pre util_vector<DIM_VECTOR (hay hueco en en vector)
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por REFERENCIA porque SÍ se va a cambiar el número de componentes utilizadas en el vector.
 * @param entero Es el nuevo número entero que quiero insertar en el vector.
 * @version 1.1
 * @author Dios-Fer
 * @date 2023-06-04
 */
void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, int entero){
    
    vector[util_vector]=entero; //en el util colocamos el nuevo entero
    util_vector++; //actualizamos el util
 
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
 * @brief Módulo que dobla el valor de cada componente del vector de enteros.
 *    Ejemplo: ENTRADA: v = { 4 2 7 } SALIDA: v = { 8 4 14 }
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va a cambiar el número de componentes utilizadas en el vector.
 * @pre util_vector deberá ser >=0 y < DIM_VECTOR
 * @post El vector cambiará sus valores y serán el doble.
 * @author
 * @version
 */
void doblarValoresDelVectorEnteros(int vector[], int util_vector){
    cout << USER << "Doblando el valor del contenido de las componentes del vector, por favor tenga paciencia..." << RESTORE << endl;
    //cout << DEBUG << "debug: El valor de las utiles antes del bucle es: " << util_vector << RESTORE <<  endl;
    for (int i=0; i < util_vector; i++){
      //  cout << DEBUG << "debug: Entrada en el bucle para doblar valores del vector..." << RESTORE << endl;
        vector[i]  = 2 * vector[i];
    }
    cout << USER << "Se dobló correctamente el vector... Lo comprobará cuando vuelva a imprimirlo..." << RESTORE << endl;
}


/**
 * @brief Módulo para identificar cuando un vector no puede ser copiado en otros por su menor tamaño
 * @post mensaje de error
 * @version 2
 * @author Dios-Fer
 * @date 2023-06-04
 */
void error_tamaños (){

    cout << "ERROR:   El tamaño del vector que intentas copiar es superior al vector en el que lo copias"<<endl;

}


/**
 * @brief Módulo para clasificar si un vector es en sus utiles mayor o igual-menor que otro en su DIM
 * @param DIM_COPIA dimension del vector que debe ser menor-igual
 * @param util_vector utilizados del vector a comparar
 * @return bool copiar (false mayor) (true menor-igual)
 * @version 2
 * @author Dios-Fer
 * @date 2023-06-04
 */
bool comparar_tamaños (const int DIM_COPIA, int util_vector){
    bool copiar=true;

    if (DIM_COPIA<util_vector){ //No podriamos copiarlo, al menos no por completo (optare por no copiarlo directamente pues copiar una parte no le serviria al usuario)
        error_tamaños();
        copiar=false;
    }

    return copiar;
}


/**
 * @brief Módulo para copiar las utiles de un vector en la dimension de otro siempre que cuente con el espacio suficiente
 * @pre util_vector <=DIM_COPIA
 * @param int vector[] (vector que se "copia")
 * @param int util_vector (los utiles que son copiados)
 * @param int copia[] (vector en el que se "pega")
 * @param int &util_copia (debera de actualizarse) 
 * @post el vector copia contendra lo mismo que el vector original
 * @version 2
 * @author Dios-Fer
 * @date 2023-06-04
 */
void copiar_vector(int vector[], int util_vector, int copia[], int &util_copia){

    for (int i=0; i<util_vector; i++){
        agregarNuevoEnteroenVectorEnteros(copia, util_copia, vector[i]);
    }

}


int main(){

    const int DIM_VECTOR = 2000;
    int vector[DIM_VECTOR] = {4,2,7}; //se inicializan las tres primeras componentes y el resto a 0
    int util_vector = 3; //inicializo a 3 porque he llenado el vector en la inicialización
    
    const int DIM_COPIA= 2000;
    int copia[DIM_COPIA] = {0};
    int util_copia = 0;



    cout << USER << "****** EJEMPLO DE VECTORES Y MODULARIZACIÓN ********" << RESTORE << endl;



    if (DEBUG_C==true){
        cout <<DEBUG <<"DEBUG -->    Imprimir vector original"<<endl<<RESTORE;
    }



    imprimeVectorEnteros(vector, util_vector); //{4,2,7}


    if (DEBUG_C==true){
        cout <<endl<<endl<<endl<<endl;
    }

    if (DEBUG_C==true){
        cout <<DEBUG <<"DEBUG -->    Miramos hueco, agregamos entero derecha, imprimimos vector"<<endl<<RESTORE;
    }

    if (comprobar_hueco (util_vector, DIM_VECTOR)){//comprobamos si hay espacio en el vector

    agregarNuevoEnteroenVectorEnteros(vector,util_vector, -1); 
    imprimeVectorEnteros(vector, util_vector); //{4,2,7, -1}

    }

    if (DEBUG_C==true){
        cout <<endl<<endl<<endl<<endl;
    }


    if (DEBUG_C==true){
        cout <<DEBUG <<"DEBUG -->    Miramos hueco, agregamos entero izquierda, imprimimos vector"<<endl<<RESTORE;
    }

    if (comprobar_hueco (util_vector, DIM_VECTOR)){//comprobamos si hay espacio en el vector

    AgregarIzquierdaNuevoEnteroenVectorEnteros(vector,util_vector, -1); 
    imprimeVectorEnteros(vector, util_vector); //{-1, 4,2,7, -1}

    }

    if (DEBUG_C==true){
        cout <<endl<<endl<<endl<<endl;
    }


    if (DEBUG_C==true){
        cout <<DEBUG <<"DEBUG -->    Doblamos e imprimimos el vector"<<endl<<RESTORE;
    }
    doblarValoresDelVectorEnteros(vector, util_vector);
    imprimeVectorEnteros(vector, util_vector); // {-2 8 4 14 -2}

    if (DEBUG_C==true){
        cout <<endl<<endl<<endl<<endl;
    }

    if (DEBUG_C==true){
        cout <<DEBUG <<"DEBUG -->    Comparamos el tamaño (si no cabe no hacemos nada (mensaje de error)) (si cabe lo copiamos e imprimimos en un nuevo vector)"<<endl<<RESTORE;
    }
    if (comparar_tamaños(DIM_COPIA, util_copia)){
        copiar_vector(vector, util_vector, copia, util_copia);
        imprimeVectorEnteros(copia, util_copia);
    }

    if (DEBUG_C==true){
        cout <<endl<<endl<<endl<<endl;
    }

}
