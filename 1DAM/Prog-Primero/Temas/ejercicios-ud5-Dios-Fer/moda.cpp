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
 * @brief Módulo para la entrada de un vector
 * @param int DIM_VECTOR_A_EVALUAR 
 * @param int vector []
 * @param int &util_vector 
 * @version 0.2
 * @author Dios-Fer
 * @date 2023-02-15
 */
void entrada_vector(const int DIM_VECTOR_A_EVALUAR, int vector[], int &util_vector){
    int numero=0;
    int util_vector_inicial=Insertar_DimensionUtil(DIM_VECTOR_A_EVALUAR);

    for (int i=0; i<util_vector_inicial; i++){//agregar numeros hasta que llegemos al util

        //Introducimos numero
        numero=Insertar_Numero();

        //Agregamos al vector original el numero 
        //hay espacio, pues trabajamos con respecto a la util previamente filtrada
        agregarNuevoEnteroenVectorEnteros(vector,util_vector, numero);

    }
}


/**
 * @brief Módulo para la entrada de un vector
 * @param const int vector_solucion[] vector donde se encuaentra la moda previamente calculada
 * @param int util_vector_solucion 
 * @param int contador_moda numero de veces que se repite la moda
 * @version 0.2
 * @author Dios-Fer
 * @date 2023-02-15
 */
void imprime_modas(const int vector_solucion[], int util_vector_solucion, int contador_moda){
    for (int i=0; i < util_vector_solucion; i++){
        cout <<"Moda: "<< vector_solucion[i] <<endl;
    }
    cout << "Numero de repeticiones: "<<contador_moda<<endl;
}


/**
 * @brief Módulo para la salida de todos los numeros que han sido posibles modas con sus respectivas repeticiones
 * @param int vector_sin_reps vector de los numeros que han podido ser modas sin repetirse
 * @param int vector_contadores vector "paralelo" al anterior (en el sentido de que la posicion i, del vector es equivalente a la posicion i en los contadores) que contiene los contadores de cada numero
 * @param int util_numero_o_contador nos da igual que util escojer pues supuestamente son "paralelos"
 * @version 0.2
 * @author Dios-Fer
 * @date 2023-02-15
 */
void ranking(int vector_sin_reps [], int vector_contadores [], int util_numero_o_contador){

    for (int i=0; i < util_numero_o_contador; i++){
        cout <<"Numero: "<< vector_sin_reps[i] <<"          "<<"Repeticiones: "<<vector_contadores[i]<<endl;
    }

}

/**
 * @brief Módulo para copiar un vector en otro
 * @pre util_vector <= DIM_COPIA (Esto se puede lograr llamando al modulo comparar_tamaños)
 * @param int vector[] (vector que se "copia")
 * @param int util_vector (los utiles que son copiados)
 * @param int copia[] (vector en el que se "pega")
 * @param int &util_copia (debera de actualizarse) 
 * @param const int DIM_VECTOR_RESULTADO (este nos servira para que al copiar no nos pasemos de la dimension)
 * @post el vector copia contendra lo mismo que el vector original
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
void copiarVector(const int vector[], int util_vector, int copia[], int &util_copia, const int DIM_VECTOR_RESULTADO){
    util_copia=0;//Vamos a sustituir por completo el contenido


    for (int i=0; i<util_vector && i<DIM_VECTOR_RESULTADO; i++){

        agregarNuevoEnteroenVectorEnteros(copia, util_copia, vector[i]);
    }


}



/**
 * @brief Módulo para obtener el numero mayor en un vector de enteros
 * @param int vector[] 
 * @param int util_vector
 * @return int mayor (numero mayor)
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
int obrener_numero_mayor_en_vector (int vector[], int util_vector){
    int mayor=vector[0];
    for (int i=1; i<util_vector; i++){
        if (vector[i] > mayor){
            mayor=vector[i];
        }
    }
    return mayor;
}



/**
 * @brief Módulo para ubicar ubicar con un numero al correspondiente en otro vector con laa mismas posiciones a ese numero en el vector relacionado
 * @param int contador_moda
 * @param int vector_sin_reps[],
 * @param int vector_contadores[]
 * @param int util_numero_o_contador
 * @param int vector_salida_moda_modas []
 * @param int &util_vector_salida_moda_modas
 * @post se obtendra un vector con los numeros deseados
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-17
 */
void ubicar_numeroYenlazar_salida (int contador_moda, int vector_sin_reps[], int vector_contadores[], int util_numero_o_contador, int vector_salida_moda_modas [], int &util_vector_salida_moda_modas){
    for (int i=0; i<util_numero_o_contador; i++){
        if (vector_contadores[i]==contador_moda){
            vector_salida_moda_modas[util_vector_salida_moda_modas] = vector_sin_reps[i];
            util_vector_salida_moda_modas++;
            
        }
    }
}


/**
 * @brief Módulo para eliminar un numero en una cadena y actualizar todas sus posiciones y su util
 * @param int vector_sin_reps[] vector en el que se elimina la celda
 * @param int j posicion eliminada
 * @param int &util_vector_sin_reps util del vector
 * @post el vector estara sin la celda pero con la estructura ya actualizada
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
void eliminar_numero_cadena(int vector_sin_reps[], int j, int &util_vector_sin_reps){


    for (j; j<util_vector_sin_reps;j++){


    vector_sin_reps[j]=vector_sin_reps[j+1];

    }

    util_vector_sin_reps--;

}




/**
 * @brief Módulo para de un vector con numeros obtener un vector en el que no se repitan y uno asociado donde pongan las veces que se repetian en el original
 * @param int vector_sin_reps[] vector de entrada del vector a evaluar y de salida tendra los numeros sin repeticiones
 * @param int vector_contadores[] vector cuyas posiciones estaran asociadas a vector_sin_reps (Ejemplo: original={5 3 5} --> vector_sin_reps={5 3} y vector_contadores={2 1}) pues para la posicion i estara el contador asociado a la posicion i del vector sin repeticiones
 * @param int &util_vector_sin_reps util del vector sin reps
 * @param int &util_vector_contadores util del vector de contadores
 * @pre el vector a evaluar debera de estar copiado en vector_sin_reps
 * @post obtendremos los dos vectores de numeros_sin_reps y vector_contadores a partir del original copiado previamente en vector_sin_reps a modo de auxiliar inicial
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
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



/**
 * @brief Módulo para calcular las modas de un vector
 * @param const int vector_a_evaluar[] vector del que se quiere saber la moda y sus repeticiones de cada entero
 * @param int vector_sin_reps[] vector de salida de los numeros sin que se repitan
 * @param int vector_contadores[] vector donde se encuentran los contadores asociados a las veces que salen los enteros del vector sin repeticiones
 * @param int vector_salida_moda_modas[] vector de salida de la moda / modas (El / los enteros que mas se repitan)
 * @param int &contador_moda las veces que se repite la moda
 * @param int util_vector_a_evaluar util de vector_a_evaluar
 * @param int &util_vector_sin_reps util de vector_sin_reps
 * @param int &util_vector_contadores util de vector_contadores
 * @param int &util_vector_salida_moda_modas util de vector_salida_moda_modas
 * @param const int DIM_VECTOR_SIN_REPS Dimension del vector de repeticiones para copiar el vector a evaluar en el 
 * @version 0.4
 * @author Dios-Fer
 * @date 2023-02-16
 */
void calcular_modas(const int vector_a_evaluar[], int vector_sin_reps[], int vector_contadores[], int vector_salida_moda_modas[], int &contador_moda, int util_vector_a_evaluar, int &util_vector_sin_reps, int &util_vector_contadores, int &util_vector_salida_moda_modas, const int DIM_VECTOR_SIN_REPS){

    copiarVector(vector_a_evaluar, util_vector_a_evaluar, vector_sin_reps, util_vector_sin_reps, DIM_VECTOR_SIN_REPS);

    contarYquitar_Numeros_repetidos (vector_sin_reps, vector_contadores, util_vector_sin_reps, util_vector_contadores);

    contador_moda = obrener_numero_mayor_en_vector (vector_contadores, util_vector_contadores);

    ubicar_numeroYenlazar_salida (contador_moda, vector_sin_reps, vector_contadores, util_vector_sin_reps, vector_salida_moda_modas, util_vector_salida_moda_modas);


}



int main(){

    //Declaraciones 

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

    entrada_vector(DIM_VECTOR_A_EVALUAR, vector_a_evaluar, util_vector_a_evaluar);

    //Salida del vector introducido
    cout << endl << "vector: "<<endl;
    imprimeVectorEnteros(vector_a_evaluar, util_vector_a_evaluar);
    cout << endl << endl<<endl;


    cout << endl << endl<<"--------------------------------------------------------"<<endl;

    //calculamos moda
    calcular_modas(vector_a_evaluar, vector_sin_reps, vector_contadores, vector_salida_moda_modas, contador_moda, util_vector_a_evaluar, util_vector_sin_reps, util_vector_contadores, util_vector_salida_moda_modas, DIM_VECTOR_SIN_REPS);

    
    //Moda 
    imprime_modas(vector_salida_moda_modas, util_vector_salida_moda_modas, contador_moda);
    cout << endl << endl<<endl;
    

    //Todos los numeros y sus repeticiones pertinentes
    ranking(vector_sin_reps, vector_contadores, util_vector_sin_reps);
    cout << endl << endl<<endl;
    
}