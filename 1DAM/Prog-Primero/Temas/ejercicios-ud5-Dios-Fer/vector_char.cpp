#include <iostream>
#include <cstring>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

const int DEBUG_C=false;




/**
 * @brief Módulo para introducir una cadena de char (solo tomara lo introducido hasta que ocupe la dimension (Ejemplo DIM=10 9 caracteres + \0 -->si introduzco 10 caracteres solo tomara los nueve primeros))
 * @param cadena [] cadena a rellenar
 * @param DIM_VECTOR dimension del vector
 * @post la cadena paerdera todo su contenido y mantendra unicamente lo introducido
 * @version 0.6
 * @date 2023-02-14
 * @author Dios-Fer
 */
void entrada_cadena (char vector[], const int DIM_VECTOR){

    int i=0;

    for (; vector[i] != '\n' && i<DIM_VECTOR-1; i++){
        vector[i]=cin.get();//recibo char a char contando espacios y teniendo en cuenta \n para cortar la introduccion

        if (vector[i] == '\n'){//si es enter no subimos (bajo-subo) por que lo sustituire por \0
            i--;
        }

    }

    
    vector [i]='\0';//reemplazo el \n por \0

}


/**
 * @brief Módulo que calcula cual es la longuitud actual de una cadena de caracteres
 * @param cadena [] cadena de caracteres
 * @return longuitud (J(0)a(1)i(2)m(3)e(4)\0(5) --> longitud=5)
 * @version 0.3
 * @date 2023-02-13
 * @author Dios-Fer
 */
int get_Longitud (char cadena []){

	int longitud=0;

	while (cadena[longitud] != '\0'){
		longitud++;
	}

	return longitud;

}



/**
 * @brief Módulo que imprime un vector de char caracter a caracter
 * @param vector [] vector a imprimir
 * @post se mostrara por pantalla el vector y un salto de linea tras este
 * @version 0.4
 * @date 2023-02-13
 * @author Dios-Fer
 */
void imprimeVectorChar (char vector []) {
    int i=0;

    while (vector[i]!='\0'){
        cout << vector [i];
        i++;
    }

    cout << endl;
}

/**
 * @brief Módulo para ver si dos vectores son exactamente iguales caracter a caracter
 * @param cadena_1 [] uno de los vectores a evaluar
 * @param cadena_2 [] uno de los vectores a evaluar
 * @return bool igual (false:no igual) (true:igual)
 * @version 1.0
 * @date 2023-02-15
 * @author Dios-Fer
 */

bool comparar_similitud_cadenas (char cadena_1[], char cadena_2[]){

    bool igual=true;

    for (int i=0; cadena_1[i]!='\0' && cadena_2[i]!='\0' && igual==true; i++){
        igual = (cadena_1[i]==cadena_2[i]);
    }

    return igual;
}









/**
 * @brief Módulo que calcula el espacio libre de un vector
 * @param const int DIM_VECTOR
 * @param char vector
 * @return espacio (espacio libre del vector contando el \0)
 * @version 0.4
 * @date 2023-02-13
 * @author Dios-Fer
 */
int calcular_espacio_libre (const int DIM_VECTOR, char vector []){
    int espacio=0;
    espacio = DIM_VECTOR - get_Longitud (vector) - 1;//El -1 es por que debemos de tener en cuenta que \0 estara en una de estas casillas
    return espacio;
}



/**
 * @brief Módulo que informa si se cumple cierta condicion (en este caso que el caracter introducido no se un espacio)
 * @param char letra letra a evaluar
 * @return condicion_ (true se cumple) (false no se cumpla)
 * @version 0.3
 * @date 2023-02-13
 * @author Dios-Fer
 */
bool Condicion (char letra){
	bool condicion_=true;
	if (letra == ' '){
		condicion_=false;
	}
	return condicion_;
}


/**
 * @brief Módulo introducir un numero sin filtro alguno y con cout refiriendose a la solicitud de copiar o no un vector a medias
 * @return int numero
 * @post en funcion del numero se eligira la metodologia a realizar en cuanto a la copia de vectores
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-02-13
 */
int Solicitar_accion(){
    int numero=0;

    cout << "El vector es mas grande que donde se intenta copiar, ¿quiere copiar lo que se pueda e ignorar lo que sobre? "<< endl << "Introduzca 0 para no hacer nada o cualquier numero para copiar lo que se pueda"<<endl;
    cin >> numero;

    return numero;
}



/**
 * @brief Módulo que agrega un nuevo caracter al final de las componentes utilizadas
 * @param vector Es una referencia al vector 
 * @param i es la posicion en la que vamos a introducir el nuevo caracter
 * @param letra Es el nuevo caracter que quiero insertar en el vector.
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-02-13
 */
void agregarLetraACadena(char vector[], int i, char letra){

    vector[i] = letra;

}




/**
 * @brief Módulo para ver si un vector del cual se quieren copiar ciertas celdas cabe o no en otro vector (condicion --> sin espacios)
 * @param DIM_COPIA dimension del vector que debe ser menor-igual
 * @param util_vector utilizados del vector a comparar
 * @param char vector [] 
 * @return bool copiar (false mayor) (true menor-igual)
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-02-13
 */
bool comparar_tamaños_validos (const int DIM_COPIA, int util_vector, char vector []){
    bool copiar=true;
    int numero_que_cumplen=0;

    for (int i=0; i<util_vector; i++){
        if (Condicion (vector[i])){
            numero_que_cumplen++;
        }
    }


    if (DIM_COPIA<numero_que_cumplen){ 
        copiar=false;
    }

    return copiar;
}



/**
 * @brief Módulo para copiar ciertas celdas de un vector en la dimension de otro siempre que cuente con el espacio suficiente (condicion --> sin espacios)
 * @pre numeros_validos <= DIM_COPIA (Esto se puede lograr llamando al modulo comparar_tamaños_validos)
 * @param char vector[] (vector que se "copia")
 * @param int util_vector (los utiles que son copiados)
 * @param char copia[] (vector en el que se "pega")
 * @param const int DIM_VECTOR_RESULTADO (este nos servira para que al copiar no nos pasemos de la dimension)
 * @post el vector copia contendra lo que se requiera del vector original (en este caso coppiarlo sin espacios)
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-02-13
 */
void copiarVector_condicion_NoEspacios(char vector[], char copia[], const int DIM_VECTOR_RESULTADO){

    int longitud_vector=get_Longitud (vector);
    int j=0;

    for (int i=0; i<=longitud_vector && j<DIM_VECTOR_RESULTADO-1; i++){
        if (Condicion (vector[i])){
            agregarLetraACadena(copia, j, vector[i]);
            j++;

        }
    }
}

/**
 * @brief Módulo que concatena dos vectores, poniendo el interior del primero sobre el segundo 
 * @param char vector[] vector que pondremos sobre el otro
 * @param char copia[] vector en el que depositamos el otro vector
 * @param DIM_VECTOR_RESULTADO dimension del vector al que introducimos la informacion
 * @version 0.5
 * @author Dios-Fer
 * @date 2023-02-13
 */
void concatenar(char vector[], char copia[], const int DIM_VECTOR_RESULTADO){

    int longitud_vector=get_Longitud (vector);

    int longitud_copia=get_Longitud (copia);

    int j=longitud_copia;

    for (int i=0; i<=(longitud_vector+longitud_copia) && j<DIM_VECTOR_RESULTADO-1; i++){  
        
            agregarLetraACadena(copia, j, vector[i]);
            j++;
    }
}




/**
 * @brief Módulo para invertir un vector 
 * @param const int DIM_VECTOR_RESULTADO Dimension del vector donde se copiara la infomacion 
 * @param char vector [] vector que copiaremos
 * @param char vector_copia [] vector donde se copiara la informacion
 * @param bool cabe (true cabe, false no cabe)
 * @version 0.7
 * @author Dios-Fer
 * @date 2023-02-15
 */
void copiar_inverso(char vector[], char copia[], const int DIM_VECTOR_RESULTADO, bool cabe){

    int longitud_vector=get_Longitud (vector);
    int j=0;

    //Ininiclizamos el '\0' donde toca
    if (cabe){
        copia [(longitud_vector)]='\0'; //esta posicion mantendra el '\0'
    }
    else {
        copia [DIM_VECTOR_RESULTADO]='\0'; //si se copia a medias el '\0' esta en la ultima que podamos colocar
    }

    for (int i=longitud_vector-1; i>=0 && j<DIM_VECTOR_RESULTADO-1; i--){
        agregarLetraACadena(copia, j, vector[i]);
        j++;
    }

}



/**
 * @brief Módulo (Controlador) para la gestion de invertir un vector en un segundo vector
 * @param const int DIM_VECTOR_2 Dimension del vector donde se copiara la infomacion 
 * @param char vector1 [] vector que copiaremos
 * @param char vector_2 [] vector donde se copiara la informacion
 * @version 0.7
 * @author Dios-Fer
 * @date 2023-02-15
 */
void invertir_cadena(const int DIM_VECTOR_2, char vector1 [], char vector_2 []){

    int longitud_vector=get_Longitud (vector1);
    bool pregunta=true;
    if (longitud_vector<DIM_VECTOR_2){
        copiar_inverso (vector1, vector_2, DIM_VECTOR_2, true);
    }

    else {

        pregunta=Solicitar_accion();

        if (pregunta !=0 ){
            copiar_inverso (vector1, vector_2, DIM_VECTOR_2, false);
        }
        
    }

}



/**
 * @brief Módulo (Controlador) para la gestion del copiado 
 * @param const int DIM_VECTOR_2 Dimension del vector donde se copiara la infomacion 
 * @param char vector1 [] vector que copiaremos
 * @param char vector_2 [] vector donde se copiara la informacion
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-02-13
 */
void modulo_controlador_de_copiado_ConCodicion (const int DIM_VECTOR_2, char vector1 [], char vector_2 []){

    int longitud_Cadena1=get_Longitud(vector1);

    int pregunta=0;

    if (comparar_tamaños_validos(DIM_VECTOR_2, longitud_Cadena1+1, vector1)){
        copiarVector_condicion_NoEspacios(vector1, vector_2, DIM_VECTOR_2);
    }

    else {

        pregunta=Solicitar_accion();

        if (pregunta !=0 ){
            copiarVector_condicion_NoEspacios(vector1, vector_2, DIM_VECTOR_2);
        }
        
    }
}



/**
 * @brief Módulo (controlador) para la concatenacion de dos vectores en un tercero y controlar que las dimensiones sean o no ideales
 * @param char cadena1 [] primera cadena a introducir
 * @param char cadena2 [] segunda cadena a introducir
 * @param char cadena_resultado [] cadena resultante de la concatenacion
 * @param const int DIM_CADENA1 dimension cadena 1
 * @param const int DIM_CADENA2 dimension cadena 2
 * @param const int DIM_CADENA_RES dimension cadena 3
 * @version 0.5
 * @author Dios-Fer
 * @date 2023-02-13
 */
void concatenar_cadena_caracteres (char cadena1 [], char cadena2 [], char cadena_resultado [], const int DIM_CADENA1, const int DIM_CADENA2, const int DIM_CADENA_RES){
    
    int longitud_final=get_Longitud (cadena1) + get_Longitud (cadena2) + 1;//+1 por le \0

    if (longitud_final<=DIM_CADENA_RES){
        concatenar (cadena1, cadena_resultado, DIM_CADENA_RES);
        concatenar (cadena2, cadena_resultado, DIM_CADENA_RES);
    }

    else {

        int pregunta=Solicitar_accion();
        if (pregunta!=0){
            concatenar (cadena1, cadena_resultado, DIM_CADENA_RES);
            concatenar (cadena2, cadena_resultado, DIM_CADENA_RES);
        }
    }
}


/**
 * @brief Módulo (controlador) ver si una frase es palindromo 
 * @param char cadena1 [] vector a evaluar
 * @return bool palin (true es palindromo) (false no es palindromo)
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-02-15
 */
bool palindromo (char cadena1[]){  

    
    const int DIM_VECTOR_2=100;//aux 1
    char cadena2[DIM_VECTOR_2]={'\0'};

    const int DIM_VECTOR_3=100;//aux 2
    char cadena3[DIM_VECTOR_3]={'\0'};

    bool palin=false;


    modulo_controlador_de_copiado_ConCodicion (DIM_VECTOR_3, cadena1, cadena3);//copiar sin espacios en la cadena3

    invertir_cadena (DIM_VECTOR_2, cadena3, cadena2);//invierto la original sin espacios (cadena3)

    
    palin=comparar_similitud_cadenas (cadena2, cadena3); //modulo para mirar si son iguales dos vectores ya sin espacios y uno invertido

    
    return palin;

}




int main (){


	const int DIM_CADENA_1=100;
	char cadena_1 [DIM_CADENA_1]={'\0'};

	const int DIM_CADENA_2=100;
	char cadena_2 [DIM_CADENA_2]={'\0'};

    int espacio_libre=0;


    const int DIM_CADENA_CONCATENADA=100;
    char cadena_concatenada [DIM_CADENA_CONCATENADA]={'\0'};
    bool palin=true;

    //Entrada sin modulo aparte de la cadena 1
    cout << "Introduce el vector de caracteres 1: "<<endl;
	cin.getline(cadena_1, 100);
    /*
    //Copiamos cadena_1 en cadena_2 sin espacio
    modulo_controlador_de_copiado_ConCodicion (DIM_CADENA_2, cadena_1, cadena_2);//Copiar cadena_1 en cadena_2

    cout << endl<<endl<<endl;
    //Salida con cout de la cadena introducida y de la copia de esta sin espacios
	cout <<endl<< "CADENA1 (salida con cout): "<<cadena_1 <<"   Longuitud cadena_1: "<<get_Longitud(cadena_1)<<endl<<endl;
	cout <<endl<< "CADENA2 (copia sin espacios de CADENA_1) (salida con cout): "<<cadena_2 <<"   Longuitud cadena_2: "<<get_Longitud(cadena_2)<<endl<<endl;

    cout << "CADENA2 (salida con modulo): ";
    imprimeVectorChar (cadena_2);
    

    cout << endl<<endl<<endl;
    //Espacio libre
    espacio_libre = calcular_espacio_libre (DIM_CADENA_1, cadena_1);
    cout << "Espacio_libre cadena_1: "<<espacio_libre << endl;

    cout << endl<<endl<<endl;
    //Concatenar cadena
    cout << "Vector concatenado de los dos anteriores: "<<endl;
    concatenar_cadena_caracteres (cadena_1, cadena_2, cadena_concatenada, DIM_CADENA_1, DIM_CADENA_2, DIM_CADENA_CONCATENADA);
    imprimeVectorChar (cadena_concatenada);

    cout << endl<<endl<<endl;
    //Modulo que "sustituye" el cin.getline
    cout << "introduce una cadena: ";
    entrada_cadena (cadena_1, DIM_CADENA_1);
    imprimeVectorChar (cadena_1);
    
    invertir_cadena (DIM_CADENA_2, cadena_1, cadena_2);//Invertir cadena_1 en cadena_2
    cout << cadena_2<<endl;
    */
    palin = palindromo (cadena_1);
    cout <<palin<<endl;
}
