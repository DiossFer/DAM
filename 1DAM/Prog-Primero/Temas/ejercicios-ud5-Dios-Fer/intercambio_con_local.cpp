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
 * @brief Módulo para copiar ciertas celdas de un vector en la dimension de otro siempre que cuente con el espacio suficiente (sin condiciones)
 * @pre util_vector <= DIM_COPIA (Esto se puede lograr llamando al modulo comparar_tamaños)
 * @param int vector[] (vector que se "copia")
 * @param int util_vector (los utiles que son copiados)
 * @param int copia[] (vector en el que se "pega")
 * @param int &util_copia (debera de actualizarse) 
 * @param const int DIM_VECTOR_RESULTADO (este nos servira para que al copiar no nos pasemos de la dimension)
 * @post el vector copia contendra lo mismo que el vector original
 * @version 1
 * @author Dios-Fer
 * @date 2023-08-04
 */
void copiarVector(int vector[], int util_vector, int copia[], int &util_copia, const int DIM_VECTOR_RESULTADO){
    util_copia=0;//Vamos a sustituir por completo el contenido

    int j=0;//para los ya agregados

    for (int i=0; i<util_vector && j<DIM_VECTOR_RESULTADO; i++){
        
            agregarNuevoEnteroenVectorEnteros(copia, util_copia, vector[i]);
            j++;
    }


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
 * @brief Módulo introducir un numero sin filtro alguno y con cout refiriendose a la solicitud de copiar o no un vector a medias
 * @return int numero
 * @version 1
 * @author Dios-Fer
 * @date 2023-07-04
 */
int Solicitar_accion(){
    int numero=0;

    cout << "El vector es mas grande que donde se intenta copiar, ¿quiere copiar lo que se pueda e ignorar lo que sobre? "<< endl << "Introduzca 0 para no hacer nada o cualquier numero para copiar lo que se pueda"<<endl;
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
 * @brief Módulo (Controlador) para la gestion del copiado 
 * @param const int DIM_VECTOR_2 Dimension del vector donde se copiara la infomacion 
 * @param int &util_vector1 util del vector que copiaremos
 * @param int vector1 [] vector que copiaremos
 * @param int vector_2 [] vector donde se copiara la informacion
 * @param int &util_vector_2 actualizaremos las utiles del vector en el que se ha copiado la informacion
 * @version 0.2
 * @author Dios-Fer
 * @date 2023-12-04
 */

void modulo_controlador_de_copiado (const int DIM_VECTOR_2, int &util_vector1, int vector1 [], int vector_2 [], int &util_vector_2){

    int pregunta=0;

    if (comparar_tamaños(DIM_VECTOR_2, util_vector1, vector1)){
        copiarVector(vector1, util_vector1, vector_2, util_vector_2, DIM_VECTOR_2);
    }

    else {

        pregunta=Solicitar_accion();

        if (pregunta !=0 ){
            copiarVector(vector1, util_vector1, vector_2, util_vector_2, DIM_VECTOR_2);
        }
        
    }
}


/**
 * @brief Módulo (Controlador (pues tiene llamada a un controlador)) para intercabiar dos vectores
 * @param const int DIM_VECTOR2 Dimension del vector 2
 * @param int &util_vector1 util del vector 1
 * @param int vector1 [] vector 1
 * @param int vector2 [] vector 2
 * @param int &util_vector2 util del vector 2
 * @param const int DIM_VECTOR1 Dimension del vector 1
 * @post interior de V esta en V2 e interior de V2 esta en V1
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-12-04
 */
void intercambiar_vectores (const int DIM_VECTOR2, int &util_vector1, int vector1 [], int vector2 [], int &util_vector2, const int DIM_VECTOR1){

    const int DIM_AUX=50;
    int vector_aux [DIM_AUX]={0};
    int util_v_aux=0;

    modulo_controlador_de_copiado (DIM_AUX, util_vector1, vector1, vector_aux, util_v_aux);//Copiar V1 en V_Aux 

    modulo_controlador_de_copiado (DIM_VECTOR1, util_vector2, vector2, vector1, util_vector1);//Copiar V2 en V1

    modulo_controlador_de_copiado (DIM_VECTOR2, util_v_aux, vector_aux, vector2, util_vector2);//Copiar V_Aux en V2

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
