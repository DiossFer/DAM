#include <iostream>
#include <iomanip>
#include <cmath>
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


//=========================================================================================================================================//

//------------INT------------//

/////////////////////////////////////////////////////////////////////////	E/S
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

/////////////////////////////////////////////////////////////////////////	COPIA

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
void intercambiar_vectores_con_auxiliar (const int DIM_VECTOR2, int &util_vector1, int vector1 [], int vector2 [], int &util_vector2, const int DIM_VECTOR1){

    const int DIM_AUX=50;
    int vector_aux [DIM_AUX]={0};
    int util_v_aux=0;

    modulo_controlador_de_copiado (DIM_AUX, util_vector1, vector1, vector_aux, util_v_aux);//Copiar V1 en V_Aux 

    modulo_controlador_de_copiado (DIM_VECTOR1, util_vector2, vector2, vector1, util_vector1);//Copiar V2 en V1

    modulo_controlador_de_copiado (DIM_VECTOR2, util_v_aux, vector_aux, vector2, util_vector2);//Copiar V_Aux en V2

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

/////////////////////////////////////////////////////////////////////////	ORDENACION

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
 * @brief Módulo para ordenar un vector con el algoritmo de seleccion
 * @param vector 
 * @param util_vector
 * @post Se ordenara el vector intoducido de menor a mayor
 * @author DiosFer
 */
void ordenar_vector_seleccion(int vector[], int util_vector){

    int aux=0;
    int posicion_min=0;
    for (int i=0; i<util_vector; i++){
        posicion_min=i;
        for(int j=i+1; j<util_vector;j++){
            if (vector[j]<vector[posicion_min]){
                posicion_min=j;
            }
        }
        aux=vector[i];
        vector[i]=vector[posicion_min];
        vector[posicion_min]=aux;
    }
}

/**
 * @brief Módulo para ordenar un vector con el algoritmo de insercion
 * @param vector 
 * @param util_vector
 * @post Se ordenara el vector intoducido de menor a mayor
 * @author DiosFer
 */
void ordenar_vector_insercion(int vector[], int util_vector){

    int i=0, izquierda=0;
    int valor=0;

    for (izquierda=1; izquierda<util_vector; izquierda++){
        valor=vector[izquierda];

        for (i=izquierda; i>0 && valor < vector[i-1]; i--){
            vector[i]=vector[i-1];
        }

        vector[i]=valor;

    }
}


/**
 * @brief Módulo para ordenar un vector con el algoritmo burbuja
 * @param vector 
 * @param util_vector
 * @post Se ordenara el vector intoducido de menor a mayor
 * @author DiosFer
 */
void ordenacion_por_intercambio_directo_burbujas (int vector[], int util_vector){
    int aux=0;

    for (bool hay_cambio=true; hay_cambio==true;){
        hay_cambio=false;

        for (int i=util_vector-1; i>0; i--){
            if (vector[i]<vector[i-1]){
                hay_cambio=true;
                aux=vector[i];
                vector[i]=vector[i-1];
                vector[i-1]=aux;
            }
        }
    }
}


/////////////////////////////////////////////////////////////////////////	BUSQUEDA

/**
 * @brief Módulo para buscar un numero en un vector de numeros y devolver las posiciones donde se encuentre
 * @pre DIM_VECTOR_RES > (cantidad de numeros a buscar en el vector original)
 * @param const int vector[] vector a evaluar
 * @param const int util_vector util vector a evaluar
 * @param const int numero_a_buscar numero que se buscara en el vector
 * @param int vector_resultado[] vector con las/la posicione/s donde se encuentra el numero buscado
 * @param int &util_vector_res util del vector resultado
 * @post el vector res contentra las posiciones del numero buscado
 */
void buscar_numero_en_vector (const int vector[], const int util_vector, const int numero_a_buscar, int vector_resultado[], int &util_vector_res){

	int i=0;

	for (; i<util_vector; i++){

		if (vector[i]==numero_a_buscar){

			vector_resultado[util_vector_res]=i;
			util_vector_res++;
		}

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


/////////////////////////////////////////////////////////////////////////   CALCULO


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


//=========================================================================================================================================//

//------------DOUBLE------------//

/////////////////////////////////////////////////////////////////////////	E/S


/* *
 * @brief Módulo para la salida de los resultados
 * @param media
 * @param desviacion
 * @param varianza
 * @param desviacion_tipica
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
void salida_datos(double media, double desviacion, double varianza, double desviacion_tipica){
   cout<<endl<<BOLDBLUE<< "La media de tus notas introducidas es: " <<BOLDCYAN<<media<<RESET<<endl; 
   cout<<BOLDBLUE<< "La desviacion media de tus notas introducidas es: " <<BOLDCYAN<<desviacion<<RESET<<endl; 
   cout<<BOLDBLUE<< "La varianza de tus notas introducidas es: " <<BOLDCYAN<<varianza << endl<<RESET;
   cout<<BOLDBLUE<< "La desviacion tipica de tus notas introducidas es: " <<BOLDCYAN<<desviacion_tipica << endl<<RESET<<endl; 
}  


/* *
 * @brief Módulo para pedir el numero de notas y las notas
 * @param util_notas util del vector notas
 * @param notas[] vector que guarda un maximo de 100 notas
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
void pedida_datos (int &util_notas, double notas[]){

   do {//Numero de alumnos

      cout <<BOLDYELLOW<< "Introduzca el numero de alumnos, recuerde que contamos con un maximo de 100: ";
      cin >> util_notas;
      cout << endl << RESET;
   }while(util_notas<1 || util_notas>100);

   for (int i=0; i<util_notas; i++){//entrada de datos
    
      cout <<BOLDYELLOW<< "Inserete nota nº" << i+1 <<": ";//ya que es una salida no usare el 0 como numero de nota
       
      cin >> notas [i];
   }

}


/////////////////////////////////////////////////////////////////////////	CALCULOS


/* *
 * @brief Módulo para el calculo de la media
 * @param util_notas util del vecto notas
 * @param notas[] vector que guarda un maximo de 100 notas
 * @return media
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double media_vector(double notas[], int util_notas){
   double media=0.0;
   for (int i=0; i<util_notas; i++){//calcular media
      media = media + notas [i];
   }
   media = media / util_notas;

   return media;
}



/* *
 * @brief Módulo para el calculo de la desviacion media
 * @param util_notas util del vector notas
 * @param notas[] 
 * @param double media dato para el calculo
 * @return desviacion (media)
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double desviacion_vector(double notas[], int util_notas, double media){
   double desviacion=0.0;
   for (int i=0; i<util_notas; i++){//calcular desviacion
      desviacion = desviacion + fabs (notas[i]-media);
   }
   desviacion = desviacion / util_notas;

   return desviacion;
}



/* *
 * @brief Módulo para el calculo de la desviacion tipica
 * @param util_notas util del vector notas
 * @param notas[] vector 
 * @param double varianza dato para el calculo
 * @return desviacion_tipica
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double desviacion_tipica_vector(double notas[], int util_notas, double varianza){
   double desviacion_tipica=0.0;

   desviacion_tipica=sqrt (varianza);

   return desviacion_tipica;
}


/* *
 * @brief Módulo para el calculo de la varianza
 * @param util_notas util del vector notas
 * @param notas[] vector 
 * @param double media dato para el calculo
 * @return varianza
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double varianza_vector(double notas[], int util_notas, double media){
   double varianza=0.0;
   for (int i=0; i<util_notas; i++){
      varianza = varianza + ((notas[i]-media) * (notas[i]-media));
   }
   varianza = varianza / util_notas;

   return varianza;
}


  //=====================================================================================================================================\\
 //_______________________________________________________________________________________________________________________________________\\
//_________________________________________________________________________________________________________________________________________\\


int main (){

/**
 * Este programa es una plantilla con la mayoria de modulos trabajados en el tema (Parte1 y Parte2) (02/03/2023) (DiosFer)
 * En este documento estan la mayoria de modulo numericos, los modulos enfocados a vectores char estan en el documento sobre el cual se trabajaron casi todos (vector_char.cpp)
 */

}