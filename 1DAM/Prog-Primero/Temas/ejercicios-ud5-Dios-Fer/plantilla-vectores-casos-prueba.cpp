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
 * @brief Módulo para salida de un error al intentar añadir una celda a un vector lleno
 * @post indicara que no se puede añadir mas casillas al vector
 * @version 0.1
 * @author Dios-Fer
 * @date 2023-02-04
 */
void error (){

    cout << DEBUG << "ERROR: No hay espacio suficiente en el vector!    Inserte -1 para dejar asi el vector"<< RESTORE<<endl;

}


/**
 * @brief Módulo para comprobar si hay hueco en un vector para añadir una celda mas
 * @post util_vector<DIM_VECTOR -->true 
 * @param DIM_VECTOR Es la constante que me indica la DIMENSIÓN del vector, esto es el número máximo de componentes que podré utilizar. Es fijo y no se puede alterar.
 * @ return bool espacio 
 * @version 1.1
 * @author Dios-Fer
 * @date 2023-06-04
 */
bool comprobar_hueco (int util_vector, const int DIM_VECTOR){

    bool espacio=true;

    if (util_vector>=DIM_VECTOR){
        espacio=false;

    }

    return espacio;

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
        copiar=false;
    }

    return copiar;
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
    cout << DEBUG << "debug: El valor de las utiles antes del bucle es: " << util_vector << RESTORE <<  endl;
    for (int i=0; i < util_vector; i++){
        cout << DEBUG << "debug: Entrada en el bucle para doblar valores del vector..." << RESTORE << endl;
        vector[i]  = 2 * vector[i];
    }
    cout << USER << "Se dobló correctamente el vector... Lo comprobará cuando vuelva a imprimirlo..." << RESTORE << endl;
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
void copiarVector(int vector[], int util_vector, int copia[], int &util_copia){
    util_copia=0;//Vamos a sustituir por completo el contenido

    for (int i=0; i<util_vector; i++){
        agregarNuevoEnteroenVectorEnteros(copia, util_copia, vector[i]);
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

    cout << "Introduce un número para agregar al vector (recuerde que para finalizar este proceso debe de insertar un -1): ";
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



int main(){
    const int DIM_VECTOR = 20;
    int vector[DIM_VECTOR] = {4,2,7,6}; //se inicializan las tres primeras componentes y el resto a 0
    int util_vector = 4; //inicializo a 3 porque he llenado el vector en la inicialización
    int numero = 0;
    const int DIM_VECTOR_RESULTADO = 2;
    int vector_resultado [DIM_VECTOR_RESULTADO] = { 1, 1 };
    int util_vector_resultado = 2;
    
    cout << USER << "****** EJEMPLO DE VECTORES Y MODULARIZACIÓN ********" << RESTORE << endl;
    imprimeVectorEnteros(vector, util_vector); //{4,2,7}
    //doblarValoresDelVectorEnteros(vector, util_vector);
    //imprimeVectorEnteros(vector, util_vector); //{8,4,14}

    do{

        //Introducimos numero
        numero=Insertar_Numero();

        //Agregamos al vector original el numero (si no es -1)
        if (numero != -1){ //agregar numeros hasta que se ponga un "-1" //Estoy algo en desacuerdo con esta metodologia pues nos quita la opcion de poner "-1" pero lo mantendre por venir asi en la plantilla

            //hay espacio, agregamos el numero
            if (comprobar_hueco(util_vector, DIM_VECTOR)){ //está aquí puesto para cumplir la PRE-condición del módulo agregarNuevo... // lo he sustituido por un modulo

                agregarNuevoEnteroenVectorEnteros(vector,util_vector, numero);
                imprimeVectorEnteros(vector, util_vector);

            }

            //no hay espacio, esperamos un -1 para finalizar la introduccion de numeros
            else{

                //mensaje de que no hay mas espacio en el vector
                error();

            }

        }



    } while (numero != -1);


    cout << "****** Y AHORA COPIAMOS EL VECTOR DE ENTRDADA EN OTRO DE SALIDA ****** " << endl;


    if (comparar_tamaños(DIM_VECTOR_RESULTADO, util_vector)){
        copiarVector(vector, util_vector, vector_resultado, util_vector_resultado);
    }

    else {

        numero=Solicitar_accion();//reutilizamos "numero" para esta condicion

        if (numero !=0 ){
            copiarVector(vector, DIM_VECTOR_RESULTADO, vector_resultado, util_vector_resultado);//Cambiamos "util_vector" por "DIM_VECTOR_RESULTADO" para que copiemos hasta llenar el vector
        }
        
    }


    //Imprimimos el vector copia
    imprimeVectorEnteros (vector_resultado, util_vector_resultado);

}
