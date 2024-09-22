#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

const int DEBUG_C=true;


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
 * @brief Módulo para ver si un vector del cual se quieren copiar ciertas celdas cabe o no en otro vector (sin condiciones)
 * @param DIM_COPIA dimension del vector que debe ser menor-igual
 * @param util_vector utilizados del vector a comparar
 * @return bool copiar (false mayor) (true menor-igual)
 * @version 1
 * @author Dios-Fer
 * @date 2023-08-04
 */
bool comparar_tamaños (const int DIM_COPIA, int util_vector, int vector []){
    bool copiar=true;
    int numero_que_cumplen=0;

    for (int i=0; i<util_vector; i++){
            numero_que_cumplen++;
    }


    if (DIM_COPIA<numero_que_cumplen){ 
        copiar=false;
    }

    return copiar;
}



/**
 * @brief Módulo introducir un numero sin filtro alguno y con cout refiriendose a agregar un numero a un vector
 * @return int numero
 * @version 1
 * @author Dios-Fer
 * @date 2023-07-04
 */
int Insertar_Numero(){
    int numero=0;

    cout << "Introduce un número para agregar al vector: ";
    cin >> numero;

    return numero;
}


/**
 * @brief Módulo introducir un numero sin filtro alguno y con cout refiriendose al util de un vector para escribirlo a continuacion
 * @return int numero
 * @version 1
 * @author Dios-Fer
 * @date 2023-07-04
 */
int Insertar_DimensionUtil(const int DIM_VECTOR){
    int numero=0;
    do{
    cout << "Introduce el numero de elementos que introduciras al vector: ";
    cin >> numero;
    }while(numero>DIM_VECTOR);

    return numero;
}



/**
 * @brief Módulo para intercambiar en una posicion determinada los valores de dos vectores
 * @param int i posicion a intercambiar
 * @param int V1[] vector 1 a intercambia
 * @param int V2[] vector 2 a intercambia
 * @post se intercambiaran las posiciones indicadas
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
void intercambiar_numero_misma_posicion_en_vectores (int V1[], int V2[], int i){
    int numero_aux=V1[i];
    V1[i]=V2[i];
    V2[i]=numero_aux;
}



/**
 * @brief Módulo para intercambiar todas las posiciones de un vector 
 * @param int aux_util indica hasta donde se intercambiara, puede ser la util mayor si ambos caben o las dimensiones del mas pequeño si no caben
 * @param int V1[] vector 1 a intercambia
 * @param int V2[] vector 2 a intercambia
 * @post se intercambiaran las posiciones hasta donde se indique
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
void intercambia_todas_las_posiciones_2vectores_sin_cambiar_util (int aux_util, int V1[], int V2[]){
    for (int i=0; i<aux_util; i++){
        intercambiar_numero_misma_posicion_en_vectores (V1, V2, i);
    }
}



/**
 * @brief Módulo para intercambiar dos vectores
 * @param const int DIM_VECTOR2 Dimension del vector 2
 * @param int &util_vector1 util del vector 1
 * @param int vector1 [] vector 1
 * @param int vector2 [] vector 2
 * @param int &util_vector2 util del vector 2
 * @param const int DIM_VECTOR1 Dimension del vector 1
 * @post interior de V esta en V2 e interior de V2 esta en V1 en caso de que quepan ambos en caso contrario se cortara en alguna de las dimensiones
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
void intercambiar_vectores (const int DIM_VECTOR2, int &util_vector1, int vector1 [], int vector2 [], int &util_vector2, const int DIM_VECTOR1){

    //inicializamos una util fija
    int aux_util=0;

    if (util_vector1>DIM_VECTOR2){//caso v1 no cabe en v2

        aux_util=DIM_VECTOR2;

        intercambia_todas_las_posiciones_2vectores_sin_cambiar_util (aux_util, vector1, vector2);

        util_vector1=util_vector2;

        util_vector2=aux_util;

    }

    else if (util_vector2>DIM_VECTOR1){//caso v2 no cabe en v1

        aux_util=DIM_VECTOR1;

        intercambia_todas_las_posiciones_2vectores_sin_cambiar_util (aux_util, vector2, vector1);

        util_vector2=util_vector1;

        util_vector1=aux_util;

    }

    else{//caso ambos caben

        if (util_vector1>util_vector2){
            aux_util=util_vector1;
        }
        else{
            aux_util=util_vector2;
        }
        int aux=util_vector1;


        intercambia_todas_las_posiciones_2vectores_sin_cambiar_util (aux_util, vector1, vector2);

        util_vector1=util_vector2;

        util_vector2=aux;

    }
}

int main(){
    const int DIM_VECTOR = 20;
    int vector[DIM_VECTOR] = {0}; 
    int util_vector = 0; 
    int numero = 0;

    const int DIM_VECTOR_RESULTADO = 5;
    int vector_resultado [DIM_VECTOR_RESULTADO] = {0};
    int util_vector_resultado = 0;
    int util_vector_inicial=0;

    //Pedida vector uno (Posible modularizacion a futuro)
    util_vector_inicial=Insertar_DimensionUtil(DIM_VECTOR);

    for (int i=0; i<util_vector_inicial; i++){//agregar numeros hasta que llegemos al util

        //Introducimos numero
        numero=Insertar_Numero();

        //Agregamos al vector original el numero 
        //hay espacio, pues trabajamos con respecto a la util previamente filtrada

        agregarNuevoEnteroenVectorEnteros(vector,util_vector, numero);

        imprimeVectorEnteros(vector, util_vector);

    }


    //Pedida vector dos (Posible modularizacion a futuro)
    util_vector_inicial=Insertar_DimensionUtil(DIM_VECTOR_RESULTADO);

    for (int i=0; i<util_vector_inicial; i++){//agregar numeros hasta que llegemos al util

        //Introducimos numero
        numero=Insertar_Numero();

        //Agregamos al vector original el numero 
        //hay espacio, pues trabajamos con respecto a la util previamente filtrada

        agregarNuevoEnteroenVectorEnteros(vector_resultado,util_vector_resultado, numero);

        imprimeVectorEnteros(vector_resultado, util_vector_resultado);

    }


    if (DEBUG_C==true){
        cout << DEBUG << "DEBUG: vector 1 "<<RESTORE<<endl;
    }


    imprimeVectorEnteros (vector, util_vector);//Imprimimos el vector 1


    if (DEBUG_C==true){
        cout << endl<<endl;
    }






    if (DEBUG_C==true){
        cout << DEBUG << "DEBUG: vector 2 "<<RESTORE<<endl;
    }


    imprimeVectorEnteros (vector_resultado, util_vector_resultado);//Imprimimos el vector 2


    if (DEBUG_C==true){
        cout << endl<<endl;
    }


    intercambiar_vectores (DIM_VECTOR_RESULTADO, util_vector, vector, vector_resultado, util_vector_resultado, DIM_VECTOR);





    
    if (DEBUG_C==true){
        cout << DEBUG << "DEBUG: vector 1 "<<RESTORE<<endl;
    }


    imprimeVectorEnteros (vector, util_vector);//Imprimimos el vector 1


    if (DEBUG_C==true){
        cout << endl<<endl;
    }






    if (DEBUG_C==true){
        cout << DEBUG << "DEBUG: vector 2 "<<RESTORE<<endl;
    }


    imprimeVectorEnteros (vector_resultado, util_vector_resultado);//Imprimimos el vector 2


    if (DEBUG_C==true){
        cout << endl<<endl;
    }

}
