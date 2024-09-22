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
#define gray "\033[0;37m"				   /* gray */

const bool DEBUG_C=false;

using namespace std;


//=========================================================================================================================================//
//VECTORES (aqui pondre modulos de vectores extraidos de la plantilla de vectores o creados aqui para cuando necesite usar alguno)

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
 * @brief modulo para la salida de posiciones guardadas de dos en dos en un vector siendo el primero la fila y el segundo la columna
 * @param int v []
 * @param int util_v
 * @post se veran todas las posiciones que tenga el vector 
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */
void salida_posiciones_f_c (int v[], int util_v){
	for (int i=0; i<util_v;i=i+2){
		cout << "El numero se encuentra en la     Fila " << v[i];
		cout << "     Columna " << v[i+1] << endl;
	}

}




//=========================================================================================================================================//

//------------INT------------//

///Declaramos la DIM de manera global
const int DIM_FIL_MATRIZ_1=20;
const int DIM_COL_MATRIZ_1=30;


/////////////////////////////////////////////////////////////////////////	E/S


/**
 * @brief modulo para insertar tanto las utiles como los valores de una matriz 
 * @param matriz_1 matriz a la que se quiere insertar los datos (S)
 * @param util_fila_matriz_1 util de las filas (S)
 * @param util_columna_matriz_1 util de las columnas (S)
 * @post la matriz tendra los datos introducidos y las utiles estaran actualizadas
 * @version 0.1
 * @date 2023-03-04
 * @author DiosFer
 */
void entrada_matriz(int matriz_1[][DIM_COL_MATRIZ_1], int &util_fila_matriz_1, int &util_columna_matriz_1){

	int f=0;
	int c=0;
	int numero=0;

	do{

		cout << "Inserte el numero de filas de la matriz: ";
		cin >> util_fila_matriz_1;

	}while(util_fila_matriz_1>=DIM_FIL_MATRIZ_1);


	do{

		cout << "Inserte el numero de columnas de la matriz: ";
		cin >> util_columna_matriz_1;

	}while(util_columna_matriz_1>=DIM_COL_MATRIZ_1);


	for (f=0; f<util_fila_matriz_1; f++){

		for (c=0; c<util_columna_matriz_1; c++){

			cout << "Inserte la posicion " << f << " " << c << " de la matriz: ";
			cin >> matriz_1[f][c];

		}

	}

}

/**
 * @brief modulo para mostrar por pantalla que no se he encontrado un numero en una matriz
 * @post se mostrara por pantalla el mensaje
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */
void no_encontrado (){
	cout << "El numero introducido no se encuentra en la matriz"<<endl;
}

/**
 * @brief modulo para mostrar por pantalla una matriz ordenada en filas y columnas
 * @param int matriz_1 matriz que se quiere mostrar (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @post la matriz se mostrara por pantalla con los datos repartidos en fila y en columnas
 * @version 0.2
 * @date 2023-03-04
 * @author DiosFer
 */
void salida_matriz_visual(int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1){
	int f=0;
	int c=0;

	for (f=0; f<util_fila_matriz_1; f++){
		cout << "|"<<"	";
		for (c=0; c<util_columna_matriz_1; c++){

			cout << matriz_1[f][c] << "	";

		}
		cout <<"|"<< endl;

	}

}


/**
 * @brief modulo para mostrar por pantalla una matriz dato a dato con su respectiva columna y fila
 * @param int matriz_1 matriz que se quiere mostrar (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @post la matriz se mostrara por pantalla con los datos de la matriz con una indicacion de su fila y columna
 * @version 0.2
 * @date 2023-03-04
 * @author DiosFer
 */
void salida_matriz_posicion(int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1){
	int f=0;
	int c=0;

	for (f=0; f<util_fila_matriz_1; f++){

		for (c=0; c<util_columna_matriz_1; c++){

			cout << "Fila: "<<f<<"	"<<"Columna: "<<c<< "	"<< "Numero: "<<matriz_1[f][c] <<endl;

		}

	}

}

/**
 * @brief modulo para la insercion de un numero con salida para indicar de que se trate y pedir el numero
 * @return int numero_a_buscar
 * @version 0.3
 * @date 2023-03-04
 * @author DiosFer
 */
int introducir_busqueda (){
	int numero_a_buscar=0;

	cout << "Introduzca el numero que desea buscar: ";
	cin >> numero_a_buscar;

	return numero_a_buscar;
}


/**
 * @brief modulo para una salida indicando si un numero esta o no en la matriz
 * @param bool encontrado (E)
 * @param int numero_a_buscar (E)
 * @post se mostrara un mensaje indicando si se ha encontrado o no el numero
 * @version 0.3
 * @date 2023-03-04
 * @author DiosFer
 */
void esta_o_noesta (bool encontrado, int numero_a_buscar){
	if (encontrado){
		cout << "El numero "<<numero_a_buscar<<" si se encuentra en la matriz"<<endl;
	}
	else {
		cout << "El numero "<<numero_a_buscar<<" no se encuentra en la matriz"<<endl;
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
 * @brief modulo para ordenar una matriz de forma global con el metodo burbuja
 * @param int matriz_1 matriz a ordenar (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @post la matriz estara ordenada de menor a mayor
 * @version 0.5
 * @date 2023-03-05
 * @author DiosFer
 */
void ordenar_global_matriz_menor_mayor_burbuja(int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1){

	int f=0;
	int c=0;
	bool cambio=true;
	while (cambio){
		cambio=false;
		for (f=0; f<util_fila_matriz_1; f++){

			for (c=0; c<util_columna_matriz_1; c++){

				if (c==util_columna_matriz_1-1 && f!=util_fila_matriz_1-1){//ultima posicion, comparamos con la siguiente fila
					if (matriz_1[f][c]>matriz_1[f+1][0]){
						intercambiar_numero (matriz_1[f][c], matriz_1[f+1][0]);
						cambio=true;
					}
				}
				else if (c==util_columna_matriz_1-1 && f==util_fila_matriz_1-1){//ultima posicion no hacemos nada

				}
				else {
					if (matriz_1[f][c]>matriz_1[f][c+1]){
						intercambiar_numero (matriz_1[f][c], matriz_1[f][c+1]);
						cambio=true;
					}
				}
				

			}

		}
	}

}



/**
 * @brief modulo para ordenar una matriz por filas con el metodo burbuja
 * @param int matriz_1 matriz a ordenar (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @post la matriz estara ordenada fila a fila de menor a mayor
 * @version 0.6
 * @date 2023-03-06
 * @author DiosFer
 */
void ordenar_filas_matriz_menor_mayor_burbuja(int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1){
	//Anotacion: Como el gloval pero sin cambio de fila a la hora de ordenar
	int f=0;
	int c=0;
	bool cambio=true;
	while (cambio){
		cambio=false;
		for (f=0; f<util_fila_matriz_1; f++){

			for (c=0; c<util_columna_matriz_1; c++){
				if (c==util_columna_matriz_1-1){

				}
				else if (matriz_1[f][c]>matriz_1[f][c+1]){
					intercambiar_numero (matriz_1[f][c], matriz_1[f][c+1]);
					cambio=true;
				}

				
			}

		}
	}

}

/**
 * @brief modulo para ordenar una matriz por columnas con el metodo burbuja 
 * @param int matriz_1 matriz a ordenar (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @post la matriz estara ordenada columna a columna de menor a mayor
 * @version 0.6
 * @date 2023-03-06
 * @author DiosFer
 */
void ordenar_columnas_matriz_menor_mayor_burbuja(int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1){
	//Anotacion: Como el de las filas pero cambiando el orden de mierar fila por columna 
	int f=0;
	int c=0;
	bool cambio=true;
	while (cambio){
		cambio=false;
		for (c=0; c<util_columna_matriz_1; c++){

			for (f=0; f<util_fila_matriz_1; f++){
				if (f==util_fila_matriz_1-1){

				}
				else if (matriz_1[f][c]>matriz_1[f+1][c]){
					intercambiar_numero (matriz_1[f][c], matriz_1[f+1][c]);
					cambio=true;
				}

				
			}

		}
	}

}

/////////////////////////////////////////////////////////////////////////	BUSQUEDA

/**
 * @brief modulo que comprueba si un numero esta en una matriz 
 * @param int matriz_1 matriz en la que se busca (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @param int numero_a_buscar (E)
 * @return bool esta (True: esta al menos una vez) (False: no esta ni una vez)
 * @version 0.3
 * @date 2023-03-04
 * @author DiosFer
 */
bool ver_si_esta_en_la_matriz (int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1, int numero_a_buscar){

	bool esta=false;
	int f=0;
	int c=0;

	for (f=0; f<util_fila_matriz_1 && esta==false; f++){

		for (c=0; c<util_columna_matriz_1 && esta==false; c++){

			if (numero_a_buscar==matriz_1[f][c]){
				esta=true;
			}
			

		}

	}
	return esta;

}


/**
 * @brief modulo para buscar un numero en una matriz devolviendo un bool en funcion de si se ha encontrado y actualizando un vector con las posiciones en las que se encuentre el numero (de dos en dos 
 *        ejemplo: un numero en la posicion 3 5 y 4 6 debolbera v[0]=3 v[1]=5 v[2]=4 v[3]=6)
 * @param int matriz_1 matriz en la que se busca (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @param int numero_a_buscar (E)
 * @param int vector_resultado_busqueda (S)
 * @param util_vector_resultado_busqueda (S)
 * @return bool esta (true si esta) (false no esta)
 * @post el vector de salida tendra las posiciones en las que se encuentre el numero buscado 
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */
bool buscar_numero_en_matriz (int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1, int numero_a_buscar, int vector_resultado_busqueda[], int &util_vector_resultado_busqueda){

	bool esta=false;
	int f=0;
	int c=0;
	util_vector_resultado_busqueda=0;

	for (f=0; f<util_fila_matriz_1; f++){

		for (c=0; c<util_columna_matriz_1; c++){

			if (numero_a_buscar==matriz_1[f][c]){

				agregarNuevoEnteroenVectorEnteros(vector_resultado_busqueda, util_vector_resultado_busqueda, f);//Añadimos la fila al vector que contara con n1=f1ºencuentro n2=c1ºencuentro, n3=f1ºencuentro, ...

				agregarNuevoEnteroenVectorEnteros(vector_resultado_busqueda, util_vector_resultado_busqueda, c);//Añadimos la columna al vector que contara con n1=f1ºencuentro n2=c1ºencuentro, n3=f1ºencuentro, ...

				esta=true;//Implica que se ha encontrado al menos una vez

			}
			

		}

	}
	return esta;

}
/**
 * @brief modulo (controlador) para buscar un numero en una matriz y devolver por pantalla las posiciones donde se encuentre
 * @param int matriz_1 matriz en la que se busca (E)
 * @param int util_fila_matriz_1 util de las filas (E)
 * @param int util_columna_matriz_1 util de las columnas (E)
 * @post se pedira el numero a buscar, se buscara y se mostrara por pantalla las posiciones o un mensaje en funcion de si esta o no
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */
void controlador_buacado (int matriz_1[][DIM_COL_MATRIZ_1], int util_fila_matriz_1, int util_columna_matriz_1){

	const int DIM_VECTOR_RESULTADO_BUSQUEDA=100;
	int vector_resultado_busqueda[DIM_VECTOR_RESULTADO_BUSQUEDA]={0};
	int util_vector_resultado_busqueda=0;

	bool encontrado=false;
	int numero_a_buscar=0;


	numero_a_buscar=introducir_busqueda();

	encontrado=buscar_numero_en_matriz (matriz_1, util_fila_matriz_1, util_columna_matriz_1, numero_a_buscar, vector_resultado_busqueda, util_vector_resultado_busqueda);

	if (encontrado){
		salida_posiciones_f_c (vector_resultado_busqueda, util_vector_resultado_busqueda);
	}
	else {
		no_encontrado();
	}
}
/////////////////////////////////////////////////////////////////////////	JUEGO

/**
 * @brief modulo para imprimir un tercio de una linea de una fila (cada fila cuenta con 9 lineas)
 * @param c valor del tercio (columna) en cuestion
 * @param i linea actual (0-8)
 * @param bool win (true: pintamos para el tablero ganador) (false: pintamos tablero normal)
 * @version 0.9.2
 * @date 2023-03-09
 * @author DiosFer
 */
void pintar_linea(int c, int i, bool win){
	if (!win){
		if (c==1){
			cout << BOLDBLUE;
		}
		else if (c==2){
			cout << BOLDRED;
		}
	}
	if (i==0){ //fila1/9
		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"      ooooooooo      ";
		}
		else if (c==2){
			cout<<"     o         o     ";
		}
	}
	else if (i==1){ //fila2/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"    oo         oo    ";
		}
		else if (c==2){
			cout<<"      o       o      ";
		}
	}
	else if (i==2){ //fila3/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"  oo             oo  ";
		}
		else if (c==2){
			cout<<"       o     o       ";
		}
	}
	else if (i==3){ //fila4/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"  o               o  ";
		}
		else if (c==2){
			cout<<"        o   o        ";
		}
	}
	else if (i==4){ //fila5/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"  o               o  ";
		}
		else if (c==2){
			cout<<"          o          ";
		}
	}
	else if (i==5){ //fila6/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"  o               o  ";
		}
		else if (c==2){
			cout<<"        o   o        ";
		}
	}
	else if (i==6){ //fila7/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"  oo             oo  ";
		}
		else if (c==2){
			cout<<"       o     o       ";
		}
	}
	else if (i==7){ //fila8/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"    oo         oo    ";
		}
		else if (c==2){
			cout<<"      o       o      ";
		}
	}
	else if (i==8){ //fila9/9

		if (c==0){
			cout<<"                     ";
		}
		else if (c==1){
			cout<<"      ooooooooo      ";
		}
		else if (c==2){
			cout<<"     o         o     ";
		}
	}
	cout <<RESTORE<<"  ||  "; //Separacion

}

/**
 * @brief modulo para pintar una fila del tablero
 * @param c1 valor (sin usar/P1/P2) de la matriz en la columna 1 de esta fila
 * @param c2 valor (sin usar/P1/P2) de la matriz en la columna 2 de esta fila
 * @param c3 valor (sin usar/P1/P2) de la matriz en la columna 3 de esta fila
 * @version 0.9
 * @date 2023-03-07
 * @author DiosFer
 */
void pintar_fila(int c1, int c2, int c3){

	for (int i=0; i<9; i++){
		cout <<"|| "; //Separacion
		pintar_linea(c1, i, 0);
		pintar_linea(c2, i, 0);
		pintar_linea(c3, i, 0);
		cout << endl;

	}

}

/**
 * @brief modulo para pintar una fila del tablero ya tras una jugada ganadora sobresaltando a la linea ganadora (verde) del resto (negro)
 * @param c1 valor (sin_usar/P1/P2) de la matriz en la columna 1 de esta fila
 * @param c2 valor (sin_usar/P1/P2) de la matriz en la columna 2 de esta fila
 * @param c3 valor (sin_usar/P1/P2) de la matriz en la columna 3 de esta fila
 * @param int win1_f posicion fila de uno de los integrantes de la linea ganadora
 * @param int win2_f posicion columna de uno de los integrantes de la linea ganadora
 * @param int win3_f posicion fila de uno de los integrantes de la linea ganadora
 * @param int win1_c posicion columna de uno de los integrantes de la linea ganadora
 * @param int win2_c posicion fila de uno de los integrantes de la linea ganadora
 * @param int win3_c posicion columna de uno de los integrantes de la linea ganadora
 * @param int fila fila actual a pintar
 * @version 0.9.2
 * @date 2023-03-07
 * @author DiosFer
 */
void pintar_fila_ganadora(int c1, int c2, int c3, int win1_f, int win2_f, int win3_f, int win1_c, int win2_c, int win3_c, int fila){

	if (DEBUG_C){///DEBUG
		cout << DEBUG << "Fila: " << fila<<endl<<RESTORE;
		cout << DEBUG << "win 1fc 2fc 3fc: " << win1_f << "//" <<win1_c << "//" <<win2_f << "//" <<win2_c << "//" <<win3_f << "//"<<win3_c <<endl<<RESTORE;
	}

	for (int i=0; i<9; i++){
		cout <<"|| "; //Separacion


			if (fila==win1_f && win1_c==0){
				cout<<BOLDGREEN;
				pintar_linea(c1, i, 1);
				cout<<RESTORE;
			}
			else if (fila==win2_f && win2_c==0){
				cout<<BOLDGREEN;
				pintar_linea(c1, i, 1);
				cout<<RESTORE;
			}
			else if (fila==win3_f && win3_c==0){
				cout<<BOLDGREEN;
				pintar_linea(c1, i, 1);
				cout<<RESTORE;
			}
			else{
				cout << gray;
				pintar_linea(c1, i, 1);
			}


			if (fila==win1_f && win1_c==1){
				cout<<BOLDGREEN;
				pintar_linea(c2, i, 1);
				cout<<RESTORE;
			}
			else if (fila==win2_f && win2_c==1){
				cout<<BOLDGREEN;
				pintar_linea(c2, i, 1);
				cout<<RESTORE;
			}
			else if (fila==win3_f && win3_c==1){
				cout<<BOLDGREEN;
				pintar_linea(c2, i, 1);
				cout<<RESTORE;
			}
			else{
				cout << gray;
				pintar_linea(c2, i, 1);
			}


			if (fila==win1_f && win1_c==2){
				cout<<BOLDGREEN;
				pintar_linea(c3, i, 1);
				cout<<RESTORE;
			}
			else if (fila==win2_f && win2_c==2){
				cout<<BOLDGREEN;
				pintar_linea(c3, i, 1);
				cout<<RESTORE;
			}
			else if (fila==win3_f && win3_c==2){
				cout<<BOLDGREEN;
				pintar_linea(c3, i, 1);
				cout<<RESTORE;
			}
			else{
				cout << gray;
				pintar_linea(c3, i, 1);
			}




	cout << endl;

	}

}


/**
 * @brief modulo para pintar las separaciones entre filas
 * @param int borde indica si es el de arriba (1), el que se encuentra entre filas (2) o el de abajo (3)
 * @version 0.9
 * @date 2023-03-07
 * @author DiosFer
 */
void pintar_separacion (int borde){

	if (borde==1){
		cout<<"========================"<<"======"<<"====================="<<"======"<<"====================="<<"===="<<endl;
		cout<<"||                      "<<"  ||  "<<"                     "<<"  ||  "<<"                       ||  "<<endl;
	}
	else if (borde==2) {
		cout<<"||                      "<<"  ||  "<<"                     "<<"  ||  "<<"                       ||  "<<endl;
		cout<<"||======================"<<"==||=="<<"====================="<<"==||=="<<"====================="<<"==||"<<endl;
		cout<<"||                      "<<"  ||  "<<"                     "<<"  ||  "<<"                       ||  "<<endl;
	}
	else if (borde==3){
		cout<<"||                      "<<"  ||  "<<"                     "<<"  ||  "<<"                       ||  "<<endl;
		cout<<"========================"<<"======"<<"====================="<<"======"<<"====================="<<"===="<<endl;
	}
}

/**
 * @brief modulo para imprimir el tablero completo actual por pantalla
 * @param int matriz_fichas[][DIM_COL_MATRIZ_1] matriz con la informacion de si esta vacio o tiene al P1/P2
 * @param int util_col_matriz_fichas
 * @param int util_fila_matriz_fichas
 * @version 0.9
 * @date 2023-03-07
 * @author DiosFer
 */
void pintar_tablero(int matriz_fichas[][DIM_COL_MATRIZ_1], int util_col_matriz_fichas, int util_fila_matriz_fichas){

	int i=0;//linea actual
	int c1=0;//Que hay en la columna 1
	int c2=0;//Que hay en la columna 2
	int c3=0;//Que hay en la columna 3

	pintar_separacion (1);//1 inicio, 2 intermedio, 3 final

	c1=matriz_fichas[0][0];
	c2=matriz_fichas[0][1];
	c3=matriz_fichas[0][2];
	pintar_fila (c1, c2, c3);//Fila1

	pintar_separacion (2);

	c1=matriz_fichas[1][0];
	c2=matriz_fichas[1][1];
	c3=matriz_fichas[1][2];
	pintar_fila (c1, c2, c3);//Fila2

	pintar_separacion (2);

	c1=matriz_fichas[2][0];
	c2=matriz_fichas[2][1];
	c3=matriz_fichas[2][2];
	pintar_fila (c1, c2, c3);//Fila3

	pintar_separacion (3);

}

/**
 * @brief modulo para imprimir el tablero completo actual por pantalla una vez ganada la partida y resaltando la linea ganadora
 * @param int matriz_fichas[][DIM_COL_MATRIZ_1] matriz con la informacion de si esta vacio o tiene al P1/P2
 * @param int util_col_matriz_fichas
 * @param int util_fila_matriz_fichas
 * @param int win1_f posicion fila de uno de los integrantes de la linea ganadora
 * @param int win2_f posicion columna de uno de los integrantes de la linea ganadora
 * @param int win3_f posicion fila de uno de los integrantes de la linea ganadora
 * @param int win1_c posicion columna de uno de los integrantes de la linea ganadora
 * @param int win2_c posicion fila de uno de los integrantes de la linea ganadora
 * @param int win3_c posicion columna de uno de los integrantes de la linea ganadora
 * @version 0.9.2
 * @date 2023-03-07
 * @author DiosFer
 */
void pintar_tablero_ganador(int matriz_fichas[][DIM_COL_MATRIZ_1], int util_col_matriz_fichas, int util_fila_matriz_fichas, int win1_f, int win2_f, int win3_f,int win1_c, int win2_c, int win3_c ){

	int i=0;//linea actual
	int c1=0;//Que hay en la columna 1
	int c2=0;//Que hay en la columna 2
	int c3=0;//Que hay en la columna 3

	pintar_separacion (1);//1 inicio, 2 intermedio, 3 final

	c1=matriz_fichas[0][0];
	c2=matriz_fichas[0][1];
	c3=matriz_fichas[0][2];
	

	pintar_fila_ganadora (c1, c2, c3, win1_f, win2_f, win3_f, win1_c, win2_c, win3_c, 0);//Fila1

	pintar_separacion (2);

	c1=matriz_fichas[1][0];
	c2=matriz_fichas[1][1];
	c3=matriz_fichas[1][2];
	pintar_fila_ganadora (c1, c2, c3, win1_f, win2_f, win3_f, win1_c, win2_c, win3_c, 1);//Fila2

	pintar_separacion (2);

	c1=matriz_fichas[2][0];
	c2=matriz_fichas[2][1];
	c3=matriz_fichas[2][2];
	pintar_fila_ganadora (c1, c2, c3, win1_f, win2_f, win3_f, win1_c, win2_c, win3_c, 2);//Fila3

	pintar_separacion (3);

}
/**
 * @brief modulo para pedir un movimento fila - columna
 * @param posicion (fila) a la que se quiere mover
 * @param posicion (columna) a la que se quiere mover
 * @param char jugador nombre del jugador que realizara el movimiento
 * @version 1.0
 * @date 2023-03-10
 * @author DiosFer
 */
void pedir_movimiento (int &fila, int &columna, char jugador[]){
	bool numero_bien=true;

	cout << "Es su turno "<<jugador<<", introduca su movimiento (fila columna)" <<endl;
	cout << "#";

	do{//filtro para letras
		numero_bien=true;
		cin >> fila;
		cin >> columna;

		if(cin.fail()==1){
				cin.clear();
				cin.ignore(10000, '\n');
				cout << BOLDRED << "Por favor introduzca un numero"<<RESET<<endl<<endl;
				numero_bien=false;
		}
	}while(numero_bien==false);

	//La sealida estara tal que fila 1, 2, 3 a pesar de ser 0, 1, 2 Aqui traducimos del usuario a las posiciones que usaremos
	fila-=1;
	columna-=1;

}

/**
 * @brief modulo para comprobar si un movimiento es valido revisando tanto si esta dentro como si ya esta ocupado 
 * @pre la matriz estara inicializada en 0 (posicion libre) o con 1 y 2 en funcion de la ficha que la ocupe
 * @param fila movimiento (fila) que se quiere realizar
 * @param columna fila movimiento (columna) que se quiere realizar
 * @param matriz_fichas
 * @param util_fila_matriz_fichas 
 * @param util_col_matriz_fichas   
 * @return bool valido (true movimiento valido // false movimiento no valido)
 * @version 0.9
 * @date 2023-03-07
 * @author DiosFer
 */
bool comprobar_movimiento (int fila, int columna, int matriz_fichas[][DIM_COL_MATRIZ_1], int util_fila_matriz_fichas, int util_col_matriz_fichas){

	bool valido=true;

	if (fila>=util_fila_matriz_fichas || fila<0){
		valido=false;
	}

	if (columna>=util_col_matriz_fichas || columna<0){
		valido=false;
	}

	if (matriz_fichas[fila][columna]!=0){
		valido=false;
	}

	return valido;

}

/**
 * @brief modulo para la revision de si tras un movimiento de x jugador 
 * @param matriz_fichas
 * @param util_fila_matriz_fichas 
 * @param util_col_matriz_fichas   
 * @param fila movimiento (fila) que se ha realizado
 * @param columna fila movimiento (columna) que se ha realizado
 * @return bool win (false: no se ha ganado // true: se ha ganado)
 * @version 0.9.1
 * @date 2023-03-08
 * @author DiosFer
 */
bool comprobar_movimiento_ganador(int matriz_fichas[][DIM_COL_MATRIZ_1], int util_fila_matriz_fichas, int util_col_matriz_fichas, int fila, int columna){
	bool win=true;


	int posible_ganador=matriz_fichas[fila][columna];//nuevo cambio en el tablero
	int f=0;
	int c=0;
	
	//mirar vertical
	for (f=0; f<util_fila_matriz_fichas; f++){
		if (matriz_fichas[f][columna]!=posible_ganador){
			win=false;
		}
	}

	//si no hay hanador en vertical, mirar en horizontal
	if (win==false){
		win=true;
		for (c=0; c<util_fila_matriz_fichas; c++){
			if (matriz_fichas[fila][c]!=posible_ganador){
				win=false;
			}
		}
	}

	//si no hay hanador en vertical ni en horizontal, mirar en diagonal
	if (win==false){
		if (posible_ganador==matriz_fichas[1][1]){//centro coincide con el jugador
			if (matriz_fichas[0][0]==posible_ganador && matriz_fichas[2][2]==posible_ganador){//diagonal ArI a AbB con el mismo jugador
				win=true;
			}
			if (matriz_fichas[0][2]==posible_ganador && matriz_fichas[2][0]==posible_ganador){//diagonal ArI a AbB con el mismo jugador
				win=true;
			}
		}
	}


	return win;

}
/**
 * @brief modulo para con el movimiento ganador obtener 3 posiciones (fil-col(6 en total)) con la ubicacion en la matriz de la linea ganadora
 * @param int matriz_fichas[][DIM_COL_MATRIZ_1] matriz con la informacion de si esta vacio o tiene al P1/P2
 * @param int fila movimiento ganador
 * @param int columna movimiento ganador
 * @param int &win1_f posicion fila de uno de los integrantes de la linea ganadora
 * @param int &win2_f posicion columna de uno de los integrantes de la linea ganadora
 * @param int &win3_f posicion fila de uno de los integrantes de la linea ganadora
 * @param int &win1_c posicion columna de uno de los integrantes de la linea ganadora
 * @param int &win2_c posicion fila de uno de los integrantes de la linea ganadora
 * @param int &win3_c posicion columna de uno de los integrantes de la linea ganadora
 * @version 0.9.2
 * @date 2023-03-07
 * @author DiosFer
 */
void obtener_posicines_ganadoras(int matriz_fichas[][DIM_COL_MATRIZ_1], int fila, int columna, int &win1_f, int &win2_f, int &win3_f, int &win1_c, int &win2_c, int &win3_c){
	int f=0;
	int c=0;
	int win=true;

	//mirar vertical
	for (f=0; f<3; f++){
		if (matriz_fichas[f][columna]!=matriz_fichas[fila][columna]){
			win=false;
		}
	}
	if (win){
		win1_f=0, win1_c=columna, win2_f=1, win2_c=columna, win3_f=2, win3_c=columna;
	}

	else{
		//si no hay hanador en vertical, mirar en horizontal
		win=true;
		for (c=0; c<3; c++){
			if (matriz_fichas[fila][c]!=matriz_fichas[fila][columna]){
				win=false;
			}
		}

		if (win){
			win1_f=fila, win1_c=0, win2_f=fila, win2_c=1, win3_f=fila, win3_c=2;
		}
		else{
			//A esta altura es si o si diagonal
			if (fila==1 && columna==1){
				if (matriz_fichas[fila][columna]==matriz_fichas[0][0] && matriz_fichas[fila][columna]==matriz_fichas[2][2]){
					win1_f=fila, win1_c=columna, win2_f=0, win2_c=0, win3_f=2, win3_c=2;
				}
				else{
					win1_f=fila, win1_c=columna, win2_f=1, win2_c=3, win3_f=3, win3_c=1;
				}
			}
			else{
				win1_f=fila, win1_c=columna;
				win2_f=1, win2_c=1;
				win3_f=(abs(2-fila)), win3_c=(abs(2-columna));	
			}
		}
	}
}

/**
 * @brief modulo para la salida de un mensaje indicando que se introduzca el nombre de un jugador
 * @param char personaje[] jugador que hara el movimiento
 * @param const int DIM_PERSONAJE 
 * @version 1.0
 * @date 2023-03-10
 * @author DiosFer
 */
void introducir_personaje(char personaje[], const int DIM_PERSONAJE){

	cout <<endl<< "Buenas jugador, introduzca su nombre: "<< endl;
	cin.getline(personaje, 50);
	cout << endl;
	cout << "Bienvenido " << personaje << ", sera un placer ser su juego de tres en raya"<<endl<<endl;
}



/**
 * @brief modulo para que uno de los jugadores elija la ficha con la que desea jugar
 * @return bool mantener en funcion de la ficha que se elija se mantendran los valores por defecto o se intercambiara la ficha
 * @version 1.0
 * @date 2023-03-10
 * @author DiosFer
 */
bool elejir_ficha (){
	bool mantener=false;
	char ficha=' ';
	bool mal=false;

	cout << "Que suerte!, hoy te ha tocado elegir ficha elige: 'x' o 'o' "<< endl;
	cout << "#";
	do{
		mal=false;

		cin >> ficha;
		cin.ignore();

		if (ficha=='x'){
			mantener=false;
		}
		else if (ficha=='o'){
			mantener=true;
		}
		else {
			cout << BOLDRED<<"Eleccion no valida" << RESTORE<<endl;
			mal=true;
		}
	}while(mal==true);
	return mantener;
}

/**
 * @brief modulo para la salida de un mensaje de victoria
 * @param personaje jugador que ha ganado
 * @version 1.0
 * @date 2023-03-10
 * @author DiosFer
 */
void gana (char personaje[]){
	cout <<endl<<endl<< "Felicidades, " << personaje << " has ganado la partida"<<endl<<endl;
	//gg //good game
	cout << BOLDGREEN;
	cout <<"oooooo"<<"   "<<"oooooo"<<endl;
	cout <<"oo   o"<<"   "<<"oo   o"<<endl;
	cout <<"oo   o"<<"   "<<"oo   o"<<endl;
	cout <<"oo ooo"<<"   "<<"oo ooo"<<endl;
	cout <<"oooooo"<<"   "<<"oooooo"<<endl;
	cout <<"   ooo"<<"   "<<"   ooo"<<endl;
	cout <<"   oo "<<"   "<<"   oo "<<endl;
	cout <<" ooo  "<<"   "<<" ooo  "<<endl;
	cout<<RESTORE;
}




/**
 * @brief modulo para la salida de un mensaje indicando empate en la partida
 * @version 1.0
 * @date 2023-03-10
 * @author DiosFer
 */
void empate (){
	cout << "Ha sido una partida reñida, no hay ganador suerte la proxima"<<endl<<endl;

	//gg //good game
	cout << BOLDGREEN;
	cout <<"   | |           | |   "<<endl;
	cout <<"   | |           | |   "<<endl;
	cout <<"   | |           | |   "<<endl;
	cout <<"   | |           | |   "<<endl;
	cout <<"   | |           | |   "<<endl;
	cout <<"                       "<<endl;
	cout <<"ooo                 ooo"<<endl;
	cout <<" ooo               ooo "<<endl;
	cout <<"  oooo           oooo  "<<endl;
	cout <<"   ooooooooooooooooo    "<<endl;
	cout <<"      ooooooooooo      "<<endl;
	cout<<RESTORE;
}



/**
 * @brief modulo para la ejecucion de un juego, concretamente el tres en raya
 * @post se habra realizado una partida al juego
 * @version 1.0
 * @date 2023-03-10
 * @author DiosFer
 */
void juego_tres_en_raya (){
	
	//Inicializamos matriz de 3*3 en 0 (lo que equivale a espacio libre)
	//Matriz: casilla con 0 espacio libre, casilla con 1 jugador uno casilla con 2 jugador 2
	
	int matriz_fichas [DIM_FIL_MATRIZ_1][DIM_COL_MATRIZ_1]={0}; //Aprobechare las dimensiones de la anterior matriz
	int util_fila_matriz_fichas=3;
	int util_col_matriz_fichas=3;

	int fila=0;
	int columna=0;

	bool movimiento_valido=true;

	int jugador1=1;
	int jugador2=2;
	int jugador=jugador1;//empieza P1 'o'
	
	int juego_ganado=false;

	int win1_f=0, win1_c=0, win2_f=0, win2_c=0, win3_f=0, win3_c=0; 

	const int DIM_PERSONAJE=100;
	char player1[DIM_PERSONAJE]={'\0'};
	char player2[DIM_PERSONAJE]={'\0'};

	bool mantener=false;

	int P1=jugador1;
	int P2=jugador2;


	introducir_personaje(player1, DIM_PERSONAJE);
	mantener=elejir_ficha ();
	introducir_personaje(player2, DIM_PERSONAJE);

	if (!mantener){
		jugador=jugador2;//ahora jugador uno es jugador2 (jugador2 realmente indica que es x) //ahora empieza el jugador 1 con las fichas que originalmente rean del jugador 2 
		P1=jugador2;
		P2=jugador1;
	}


	if (DEBUG_C){
		cout<< DEBUG<< "1: "<<player1 <<endl<< "2: "<<player2<<endl<<RESTORE;
	}

	pintar_tablero (matriz_fichas, util_col_matriz_fichas, util_fila_matriz_fichas);

	for (int j=0; j<9 && juego_ganado==false; j++){

		do{
			if (jugador==P1){
				pedir_movimiento (fila, columna, player1);
			}
			else{
				pedir_movimiento (fila, columna, player2);
			}

			movimiento_valido=comprobar_movimiento (fila, columna, matriz_fichas, util_fila_matriz_fichas, util_col_matriz_fichas);

		}while(!movimiento_valido);

		matriz_fichas[fila][columna]=jugador;

		if (DEBUG_C){
			cout << DEBUG << "Fila --> " << fila << "     Columna --> " <<columna << endl <<RESTORE;
		}
		
		juego_ganado=comprobar_movimiento_ganador(matriz_fichas, util_fila_matriz_fichas, util_col_matriz_fichas, fila, columna);

		if (DEBUG_C){
			cout << DEBUG << "Partida_Ganada: "<< juego_ganado << endl <<RESTORE;
		}

		if (!juego_ganado){
			pintar_tablero (matriz_fichas, util_col_matriz_fichas, util_fila_matriz_fichas);
			if (jugador==jugador1){
				jugador=jugador2;
			}

			else{
				jugador=jugador1;
			}
		}

		else{
			obtener_posicines_ganadoras(matriz_fichas, fila, columna, win1_f, win2_f, win3_f, win1_c, win2_c, win3_c);
			pintar_tablero_ganador (matriz_fichas, util_col_matriz_fichas, util_fila_matriz_fichas, win1_f, win2_f, win3_f, win1_c, win2_c, win3_c);
			if (jugador==P1){
				gana(player1);
			}
			else{ //jugador==P2
				gana(player2);
			}
		}

		
	}
	if (juego_ganado==false){
		empate ();
	}


}

/////////////////////////////////////////////////////////////////////////	MENU

/**
 * @brief modulo para una salida del menu indicando que se debe de introducir una matriz antes de algunas acciones como por ejemplo buscar un numero en dicha matriz
 * @post se mostrara por pantalla el mensaje
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */
void mensaje_error_menu (){
	cout << BOLDRED << "Debes de introducir la matriz para realizar esta accion"<<RESTORE<<endl;//no se ha introducido matriz alguna sobre la que trabajar
}

/**
 * @brief modulo para la salida del menu y la entrada de la eleccion con filtro
 * @retur int eleccion (entre 0 y 8)
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */
int salida_entrada_menu (){

	int eleccion=0;

	do {//filtro

		//Visualizacion del menu
		cout << endl << endl << "//--------------------MENU--------------------//"<<endl;
		cout << "#0 -->     Insertar la matriz"<<endl;
		cout << "#1 -->     Buscar"<<endl;
		cout << "#2 -->     Ordenar Global"<<endl;
		cout << "#3 -->     Ordenar Local por Filas"<<endl;
		cout << "#4 -->     Ordenar Local por Columnas"<<endl;
		cout << "#5 -->     Imprimir (estilo1) matriz en el estado actual"<<endl;
		cout << "#6 -->     Imprimir (estilo2) matriz en el estado actual"<<endl;
		cout << "#7 -->     JUEGO"<<endl;
		cout << "#8 -->     SALIR"<<endl;
		cout << endl << "    #";

		cin >> eleccion;
		cin.ignore();
		cout << endl;
		if (eleccion<0 || eleccion>8){
			cout<<BOLDRED<<"    Digito no valido"<<endl<<RESTORE;
		}
		

	}while (eleccion<0 || eleccion>8);

	return eleccion;

}


/**
 * @brief modulo (controlador) para en funcion de la eleccion previa realizar una u otra accion
 * @param eleccion (recojida en el modulo salida_entrada_menu) (entre 0 y 8)
 * @param bool introducida indica que ya se ha introducido matriz sobre la que trabajar (E/S)
 * @param matriz_1
 * @param util_fila_matriz_1
 * @param util_columna_matriz_1
 * @retur bool cerrar (sera true cuando se quiera cerrar el programa)
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */
bool menu_funcional (int eleccion, bool &introducida, int matriz_1[][DIM_COL_MATRIZ_1], int &util_fila_matriz_1, int &util_columna_matriz_1) { 
	bool cerrar=false;

	if (eleccion==0){
		entrada_matriz(matriz_1, util_fila_matriz_1, util_columna_matriz_1);
		introducida=true;//Indicamos que se ha introducido una matriz
	}

	else if (eleccion>=1 && eleccion<=6){

		if (introducida==true){

			if (eleccion==1){
				controlador_buacado(matriz_1, util_fila_matriz_1, util_columna_matriz_1);
			}

			else if (eleccion==2){
				ordenar_global_matriz_menor_mayor_burbuja(matriz_1, util_fila_matriz_1, util_columna_matriz_1);
			}

			else if (eleccion==3){
				ordenar_filas_matriz_menor_mayor_burbuja(matriz_1, util_fila_matriz_1, util_columna_matriz_1);
			}

			else if (eleccion==4){
				ordenar_columnas_matriz_menor_mayor_burbuja(matriz_1, util_fila_matriz_1, util_columna_matriz_1);
			}

			else if (eleccion==5){
				salida_matriz_visual(matriz_1, util_fila_matriz_1, util_columna_matriz_1);
			}

			else if (eleccion==6){
				salida_matriz_posicion(matriz_1, util_fila_matriz_1, util_columna_matriz_1);
			}

		}
		
		else {//No se ha introducido ninguna matriz
			mensaje_error_menu();
		}
	}

	else if (eleccion==7){
		juego_tres_en_raya ();
	}

	else if (eleccion==8){
		cerrar=true;
	}
	return cerrar;
}

/**
 * @brief modulo (controlador) para la salida y uso del menu ademas de su repeticion hasta que se le indique
 * @param matriz_1
 * @param util_fila_matriz_1
 * @param util_columna_matriz_1
 * @post el menu se ejecutara hasta que se seleccione la opcion para cerrarlo
 * @version 0.4
 * @date 2023-03-05
 * @author DiosFer
 */

void menu (int matriz_1[][DIM_COL_MATRIZ_1], int &util_fila_matriz_1, int &util_columna_matriz_1){

	int eleccion=0;
	bool introducida=false;
	bool cerrar=false;

	while (!cerrar){

		eleccion=salida_entrada_menu();

		cerrar=menu_funcional(eleccion, introducida, matriz_1, util_fila_matriz_1, util_columna_matriz_1);

	}

}

  //=====================================================================================================================================\\
 //_______________________________________________________________________________________________________________________________________\\
//_________________________________________________________________________________________________________________________________________\\


int main (){

	/**
	 * Este archivo se trabajara con los modulos de matrices (Parte3 T5) (DiosFer)
	 * El main podra tener cosas para ir testando los modulos que se agregen con el tiempo
	 * El main tendra el menu que se indica en la tabla (este tendra ciertas variaciones pero cumpliendo con todo lo indicado)
	 */
	
	//Declaracion de la matriz sobre la que trabajaremos
	int matriz_1[DIM_FIL_MATRIZ_1][DIM_COL_MATRIZ_1]={0};
	int util_fila_matriz_1=0;
	int util_columna_matriz_1=0;

	menu (matriz_1, util_fila_matriz_1, util_columna_matriz_1);
}
