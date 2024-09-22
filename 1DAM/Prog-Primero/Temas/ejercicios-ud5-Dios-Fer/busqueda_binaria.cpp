#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

using namespace std;

/**
 * @brief Módulo que imprimirá por pantalla un vector de enteros.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de sólo lectura del vector, lo paso como referencia constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va vector cambiar el número de componentes utilizadas en el vector.
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
 * @brief modulo para intercambiar dos numeros
 * @post los numeros introducidos cambiaran de lugar
 * @param numero1 (E/S)
 * @param numero2 (E/S)
 * @date 2023-03-01
 * @Version 1.0
 * @author DiosFer
 * @author nanomv3
 */
void intercambiar_numero(int &numero1, int &numero2){
    int aux=numero1;
    numero1=numero2;
    numero2=aux;
}

/**
 * @brief modulo para organizar monticulos de manera que el padre sea mayor a sus hijos 
 * @post el vector introducido tendra al entero a evaluar con su respectivo orden en cuanto a sus hijos
 * @param vector (E/S)
 * @param k posicion de numero que vamos a evaluar y mover en caso de ser necesario (E)
 * @param util_vector (E)
 * @date 2023-03-01
 * @Version 1.0
 * @author DiosFer
 * @author nanomv3
 */
void reestructurar_monticulos(int vector[], int k, int util_vector) {

    int aux = vector[k]; //guardamos el valor que estamos evaluando en una variable
    int hijo=0; //declaramos la variable hijo, el cual sera el posible hijo del que evaluamos y despues podra ser el hijo del hijo, ...
    bool cambio=true;

    while (k <= util_vector / 2 && cambio==true) {//miramos si es mayor o igual al utimo padre del vector (el padre del util) para saber si tiene hijos

        cambio=true;

        hijo = 2 * k; //hijo del que evaluamos actualmente

        if (hijo < util_vector && vector[hijo] < vector[hijo + 1]){//si esta dentro de la parte desordenada y es menor a su hermano, cambiamos de hijo
            
            hijo++;

        }

        if (aux >= vector[hijo]){ //si el hijo es menor al padre no habra cambio

            cambio=false;

        }
        if (cambio==true){
            vector[k] = vector[hijo];//Si hay cambio el que evaluamos pasa a ser el hijo 

            k = hijo; //actualizamos k al nuevo hijo y lo evaluamos si es necesario
        }

    }

    vector[k] = aux; // Cuando ya no hay mas hijos o el padre ya es mayor situamos nuestra variable que guardaba el valor original en el ultimo hijo que cumplia la condicion

}

/**
 * @brief modulo que ordena un vector con el metodo de ordenacion HeapSort realizando multiples llamadas al modulo reestructurar_monticulos
 * @post el vector introducido estara ordenado de menor a mayor
 * @param vector (E/S)
 * @param util_vector (E)
 * @date 2023-03-01
 * @Version 1.0
 * @author DiosFer
 * @author nanomv3
 */
void heapsort(int vector[], int util_vector) {

    for (int i = util_vector / 2; i >= 0; i--){ //Bucle para ordenar el vector en forma de monticulos usando reestructurar_monticulos

        reestructurar_monticulos(vector, i, util_vector - 1);

    }

    for (int i = util_vector - 1; i >= 1; i--) { //Intercambiando y asilando el 1º padre y ordenando de nuevo el monticulo ordenamos de menor a mayor

        intercambiar_numero(vector[0], vector[i]);
        reestructurar_monticulos(vector, 0, i - 1);

    }

}


/**
 * @brief modulo para realizar la busqueda binaria introduciendo el vector para buscar y un vector para las soluciones
 * @param vector (E)
 * @param util_vector (E)
 * @param numero_a_buscar (E)
 * @param vector_posiciones_buscadas (E/S)
 * @param util_vector_posiciones_buscadas (E/S)
 * @pre el vector debera de estar ordenado
 * @return True: se encontro el numero a buscar False: no se encontro el numero a buscar
 * @date 2023-03-02
 * @Version 1.0
 * @author DiosFer
 */
bool busqueda_binaria (int vector[], int util_vector, int numero_a_buscar, int vector_posiciones_buscadas[], int &util_vector_posiciones_buscadas){

    int pos1=0;
    int pos2=util_vector-1;
    bool igual=false;
    int posicion_buscada=0;
    

    while(pos1<=pos2 && igual==false){ //numero > centro

        if (numero_a_buscar>vector[((pos1+pos2)/2)]){

            pos1=((pos1+pos2)/2)+1;

            igual=(vector[pos1]==numero_a_buscar);
            if (igual){
                posicion_buscada=pos1;
            }
        }

        else { //numero <= centro
            pos2=((pos1+pos2)/2)-1;
            igual=(vector[pos2]==numero_a_buscar);
            if (igual){
                posicion_buscada=pos2;
            }
        }
        
    }

    if (igual){ //En caso he haber varios una vez encontrado uno y teniendo en cuenta que al estar ordenado estaran juntos buscamos a sus lados iguales y los añadimos al vector solucion
        int i;
        for (i=posicion_buscada-1; vector[i]==numero_a_buscar && i>=0; i--){
            agregarNuevoEnteroenVectorEnteros(vector_posiciones_buscadas, util_vector_posiciones_buscadas, i);
        }

        agregarNuevoEnteroenVectorEnteros(vector_posiciones_buscadas, util_vector_posiciones_buscadas, posicion_buscada);

        for (i=posicion_buscada+1; vector[i]==numero_a_buscar && i<util_vector; i++){
            agregarNuevoEnteroenVectorEnteros(vector_posiciones_buscadas, util_vector_posiciones_buscadas, i);
        }
    }

    return igual;//En caso de no encontrar el numero sera false
}

/**
 * @brief modulo (controlador) para realizar la busqueda binaria 
 * @param vector (E)
 * @param util_vector (E)
 * @pre el vector debera de estar ordenado
 * @post se mostrara por pantalla las posiciones del vector en las que se encuentre el numero buscado
 * @date 2023-03-02
 * @Version 1.0
 * @author DiosFer
 */
void buscar_numero_binario (int vector[], int util_vector){

    const int DIM_VECTOR_POSICIONES_BUSCADAS=100;
    int vector_posiciones_buscadas[DIM_VECTOR_POSICIONES_BUSCADAS]={0};
    int util_vector_posiciones_buscadas=0;

    int numero_a_buscar=37;//Ejemplo, Aqui se introducira o ya depende del problema se podria modificar este modulo

    bool encontrado=false;

    imprimeVectorEnteros(vector, util_vector);

    heapsort(vector, util_vector);

    imprimeVectorEnteros(vector, util_vector);

    encontrado=busqueda_binaria(vector, util_vector, numero_a_buscar, vector_posiciones_buscadas, util_vector_posiciones_buscadas);

    if (encontrado){//Salida a busqueda de vectores

        heapsort(vector_posiciones_buscadas, util_vector_posiciones_buscadas);//Para sacrlo en orden 
        imprimeVectorEnteros(vector_posiciones_buscadas, util_vector_posiciones_buscadas);// Vector de las posiciones o posicion en las que se encuentra el numero buscado

    }
    else{

        cout << "Numero no encontrado en el vector"<<endl;//No se ha encontrado el numero
        
    }
}

int main (){

    //Ejemplo numeros del 1 al 100
    const int DIM_VECTOR=1000;
    int vector [DIM_VECTOR]={59, 12, 78, 62, 85, 54, 61, 22, 77, 43, 58, 38, 7, 19, 89, 31, 91, 25, 68, 35, 6, 96, 79, 88, 24, 26, 65, 98, 99, 15, 83, 70, 37, 21, 9, 16, 95, 92, 11, 2, 55, 8, 93, 73, 41, 97, 67, 29, 33, 50, 32, 76, 80, 3, 10, 71, 30, 47, 27, 75, 1, 39, 86, 17, 72, 44, 94, 81, 53, 48, 64, 5, 34, 52, 51, 28, 4, 66, 20, 23, 63, 82, 84, 100, 13, 74};    
    int util_vector=100; //En este ejemplo ya que queria testar cuando hay varios iguales aprobeche y puse utiles de mas para mierar las posiciones en las que este el 0

    buscar_numero_binario (vector, util_vector);

    
}