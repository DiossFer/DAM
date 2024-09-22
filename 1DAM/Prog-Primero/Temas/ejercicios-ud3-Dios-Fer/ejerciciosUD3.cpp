#include <iostream>
#include <cmath>
using namespace std;

//glovales
const bool DEBUG=false;

//colores
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */



 /* *
 * @brief Módulo para calcular el MCD 
 * @param int nuero1 
 * @param int nuero2 
 * @return int mcd siendo el mcd entre los dos numeros
 * @pre numero1 y numero2 son validos
 * @post se dara la solucion al modulo necesario
 * @version aislada 1.1
 * @date aislada 2023-16-01
 * @version 0.6 -
 * @date 2023-16-01
 * @author Dios-Fer
 */
 
int MCD (int numero1, int numero2){
	int mcd=0, resto=0;
	
	if (numero2==0){//si uno es 0 el mcd sera el otro numero comprobaremos el de la derecha para evitar fallos con el uso del modulo (nos da igual que numero1 sea 0)
	
		numero2=numero1;//cambiamos el orden pues nuestro resultado sera el "numero2"
		
	}
	
	else{//Caso comun con el algoritmo de Euclides

		resto = numero1 % numero2;
		
		while(resto != 0){
		
			numero1=numero2;
			numero2=resto;
			resto=numero1 % numero2;
		
		}
	
	
	}
	
	mcd=numero2;//En este algoritmo el mcd es en segundo numero, lo hacemos asi para organizarlo mejor
	
	return mcd;
}
 
 /* *
 * @brief Módulo de pedida y entrada de datos del MCD
 * @post de filtrados dos numeros 
 * @version 0.6.1 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
void pedida_MCD (int &numero1, int &numero2){
	bool numero=true;
	do{
		cout << BOLDYELLOW << "==================================================================="<<endl;
		cout << BOLDYELLOW << "Introduzca dos numero para hacer el mcd de estos: ";
		numero=true;
	
		cin >> numero1 >> numero2;
		
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
			numero=false;
		}
	}while(numero==false);
}
 /* *
 * @brief Módulo que saca el MCD
 * @post salida de resultados
 * @version 0.6.2 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
void salida_MCD (int numero1, int numero2, int mcd){
	cout << endl<<BOLDYELLOW<<"El maximo comun divisor de tus numeros: "<< BOLDBLUE<<numero1 <<BOLDYELLOW<<" y "<<BOLDBLUE<<numero2<<BOLDYELLOW<<" es: " << BOLDCYAN<<mcd << endl<<endl;
}
 
 /* *
 * @brief Módulo que conecta y ejecuta el MCD
 * @version 0.6.1 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
 
void Programa_MCD (){
	int numero1=0, numero2=0;
	int mcd=0;
	pedida_MCD (numero1, numero2);
	mcd = MCD (numero1, numero2);
	salida_MCD (numero1, numero2, mcd);	
}



/* *
 * @brief Módulo que comprueba si un numero es primo o no (con capacidad para entradas negativas)
 * @param int i numero a evaluar
 * @return bool noprimo resultado de la evaluacion (noprimo==true --> no es primo / noprimo==false --> es primo)
 * @version aislada 2.1 
 * @date aislada 2023-16-01
 * @version 0.5 -
 * @date 2023-16-01
 * @author Dios-Fer
 */
 
bool esprimo (int i){

	bool noprimo=false;
	
	if (i<=0){//pondremos 1 como primo y 0/negativos como no primos
	noprimo=true;
	}
	
	else{//mayores a 0 comprobaremos si son primos
		for (int j=2; j<i && noprimo==false; j++){
		
			noprimo=(i%j==0);//noprimo se igualara a true cuando se cumpla la condicion "(i%j==0)" con la cual se ve si NO es primo
			 
		}
	}
	
	return noprimo;
}

		
/* *
 * @brief Módulo que calcula la cantidad de números primos que hay en un intervalo
 * @param int a Extremo menor del intervalo
 * @param int b Extremo mayor del intervalo
 * @return int contador_de_primos (cantidad de primos encontrados en el intervalo)
 * @ pre a > b
 * @post ha contado los primos del intervalo
 * @version 0.6.2 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
int primos_en_intervalo (int a, int b){	//Intervalo ---> a-b
	int contador_de_primos=0;
	bool noprimo=false;//si es true implica que no es primo

	for (int i=a; i<=b; i++){//comprobaremos todas las i entre a y b contando a estos entre los posibles primos
		
		
		noprimo = esprimo (i);//Vemos si el numero es o no primo con la funcion "esprimo"
			
		if (noprimo==false){
			contador_de_primos++;
		}
	
	}
	
	return contador_de_primos;

}


/* *
 * @brief Módulo de pedida del intervalo
 * @post de filtrados dos numeros 
 * @post numero1 > numero2
 * @version 0.6.2 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
void pedida_Intervalo (int &numero1, int &numero2){
	bool numero=true;
	do{
		cout << BOLDYELLOW << "==================================================================="<<endl;
		cout << BOLDYELLOW << "Introduce un intervalo y veamos cuantos numeros primos hay en este: ";
		numero=true;
	
		cin >> numero1 >> numero2;//Intervalo ---> numero1-numero2
		
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
			numero=false;
		}
		if (numero==true && numero1>numero2){//para que no me de problemas el orden en caso de que los introduzca primero el grande y despues el pequeño
			int aux=numero1;
			numero1=numero2;
			numero2=aux;
		}
	}while(numero==false);
}
 /* *
 * @brief Módulo que da el numero de primos
 * @post salida de resultados
 * @version 0.6.2 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
 
 
void salida_numeroDePrimos (int numero_de_primos){
	cout << BOLDBLUE<<endl<<"El numero de primos que hay en tu intervalo es de: " <<BOLDCYAN<<numero_de_primos<< BOLDBLUE<<" numeros primos." << endl<<endl;
}


/* *
 * @brief Módulo conecta para calcular el numero de primos en un intevalo
 * @version 0.6.2 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
void Programa_PrimosEnIntervalo (){

	int numero1=0, numero2=0;//datos (entradas)

	int numero_de_primos=0;//solucion (salida)
	
	pedida_Intervalo (numero1, numero2);
	numero_de_primos = primos_en_intervalo (numero1, numero2);//llamamos a la funcion para que nos devuelva el numero de primos y lo guarde en la variable "numero_de_primos"
	salida_numeroDePrimos (numero_de_primos);
}


/* *
 * @brief Módulo que actualizara el numero mayor
 * @param int max (para actualizarlo)
 * @param int numero (para evaluarlo)
 * @post actualizar el numero maximo
 * @version 0.6.3 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
void comparar_max (int &max, int numero){
	if (numero>max){
		max=numero;
	}
}

/* *
 * @brief Módulo que actualizara el numero menor
 * @param int min (para actualizarlo)
 * @param int numero (para evaluarlo)
 * @post actualizar el numero minimo
 * @version 0.6.3 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
void comparar_min (int &min, int numero){
	if (numero<min){
		min=numero;
	}
}	
		



/* *
 * @brief Módulo de entrada del numero de numeros introducidos
 * @post numero filtrado
 * @version 0.6.3 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
 		
int leer_numero (){
	int numero=0;
	bool numero_correcto=true;
	do{
		numero_correcto=true;
		cin >> numero;
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
			numero_correcto=false;
		}
		
	}while(numero_correcto==false);
	
	return numero;
}

/* *
 * @brief Módulo de salida del maximo y minimo
 * @param int max (numero maximo)
 * @param int min (numero minimo)
 * @post mostrar los resultados
 * @version 0.6.3 -
 * @date 2023-18-01
 * @author Dios-Fer
 */	
void salida_max_min (int max, int min){
		cout << endl<<BOLDYELLOW<<"De los numeros introducidos el "<<BOLDBLUE<<"mayor"<< BOLDYELLOW<<" es: "<<BOLDBLUE<<max << BOLDYELLOW<<" y el "<<BOLDCYAN<<"menor "<<BOLDYELLOW<<"es "<< BOLDCYAN<<min<<endl<<endl;
	}




/* *
 * @brief Módulo de entrada del numero de numeros introducidos
 * @post numero_de_numeros > 0
 * @version 0.6.3 -
 * @date 2023-18-01
 * @author Dios-Fer
 */	
int obtener_numeroDeNumeros (){
	int numero_de_numeros=0;
	bool numero_correcto=true;
	do{
		cout << BOLDMAGENTA<<endl<<"======================================================================================================================================================="<<endl;
		cout << "Introduzca un numero mayor a 0 para determinar que tantos numero vas a introducir, tras este escribe esos numeros y se te dara el mayor y el menor: "<<endl<<endl;
		
		numero_correcto=true;
		cin >> numero_de_numeros;
		
		
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
			numero_correcto=false;
		}
		if (numero_correcto==true){//filtro de numero de numeros mayor a 0
			if (numero_de_numeros<=0){
				cin.clear();
				cin.ignore(10000, '\n');
				cout << BOLDRED <<"El numero de numeros que vas a introducir debe de ser 1 o superior"<<RESET<<endl;
				numero_correcto=false;
			}
		}
	
	}while(numero_correcto==false);
	
	return numero_de_numeros;
	
}


/* *
 * @brief Módulo que recibe y traslada el dato para su posterior evaluacion
 * @param int numero_de_numeros numero total numeros a evaluar
 * @param int &max el numero maximo actual
 * @param int &min el numero minimo actual
 * @pre numero_de_numeros > 0
 * @post max sea el numero maximo introduciudo
 * @post min sea el numero minimo introduciudo
 * @version 0.6.3 -
 * @date 2023-18-01
 * @author Dios-Fer
 */	
void CalcularMaxMin (int &max, int &min, int numero_de_numeros){

	int numero=0;
	
	//inicializamos max y min al primer numero introducido
	numero = leer_numero ();
	max = numero;
	min = numero;


	for (int i=2; i<=numero_de_numeros; i++){//empezamos en 2 pues el primer numero introducido sera el mas grande y el mas pequeño, nos perjudica inicializar en 0, debemos inicializar en ese primer numero
		numero = leer_numero ();
		
		comparar_max (max, numero);
		comparar_min (min, numero);
	}	
}


/* *
 * @brief Módulo que llama a la entrada de datos, el calculo y la salida del programa para calcular maximos y mnimos
 * @return 0;
 * @version 0.6.3 -
 * @date 2023-18-01
 * @author Dios-Fer
 */
 
 
void Programa_CalcularMaxMin (){

	int numero_de_numeros=0, max=0, min=0;
	
	numero_de_numeros = obtener_numeroDeNumeros ();
	
	CalcularMaxMin (max, min, numero_de_numeros);
	
	salida_max_min (max, min);
		
}



  /* *
 * @brief Módulo para introducir los tres parametros (a, b, c) de una ecuacion de segundo grado
 * @param double &a
 * @param double &b
 * @param double &c
 * @post se daran los tres parametros filtrados
 * @version 0.6.4 -
 * @date 2023-19-01
 * @author Dios-Fer
 */
void Pedida_ecuacion (double &a, double &b, double &c){
	bool numerobien;
	
	do{
	cout << BOLDYELLOW << "==============================================================================================="<<endl;
	cout << BOLDYELLOW << "Introduzca los tres parametros de su ecuacion en orden (ax2 + bx + c) (a b c): ";
	numerobien=true;

	cin >> a;
	cin >> b;
	cin >> c;
	
	if(cin.fail()==1){//filtro para letras
		cin.clear();
		cin.ignore(10000, '\n');
		cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
		numerobien=false;
	}
	
	}while(numerobien==false);
	
}

 /* *
 * @brief Módulo marcara un tipo y en funcion resolvera
 * @param double a
 * @param double b
 * @param double c
 * @param double &x1
 * @param double &x2
 * @post dependiendo de como sea la funcion mandara a resolverla y pasara la solucion 
 * @version 0.6.4 -
 * @date 2023-19-01
 * @author Dios-Fer
 */
bool clasificar_resolver_ecuacion (double a, double b, double c, double &x1, double &x2) {
	bool sol=false;//solucion
	
	if (a==0){
		if (b==0){//Igualdad
		sol=false;
		}
		else {//ecuacion de primer grado
			x1=((-c)/b);
			x2=x1;//si ambos son iguales solo hay una solucion 
			sol=true;
		}
	}
	
	else{
		double discriminante=b*b-4*a*c;
		
		if (discriminante<0){
			sol=false;
		}
		else if (discriminante==0){//1 solucion b + 0 = b - 0
			sol=true;
			x1=((-b)/(2*a));
			x2=x1;//si ambos son iguales solo hay una solucion 
		}
		else {
			sol=true;
			x1=(-b+sqrt(discriminante))/(2*a);
			x2=(-b-sqrt(discriminante))/(2*a);
		}
	}
	
	if (DEBUG == true){

        cout << BOLDRED << "DEBUG(clasificar_resolver_ecuacion): Salgo de clasificar_resolver_ecuacion" << RESET << endl;
        cout << BOLDRED << "DEBUG(clasificar_resolver_ecuacion): sol= " << sol << RESET << endl;
	cout << BOLDRED << "DEBUG(clasificar_resolver_ecuacion): x1= " << x1 << " x2= "<<x2 << RESET << endl;

	}
	
	return sol;
}



 /* *
 * @brief Módulo marcara un tipo y en funcion resolvera
 * @param double x1 solucion1
 * @param double x2 solucion2
 * @param bool sol (hay o no solucion)
 * @post dependiendo de como sea la funcion mandara a resolverla y pasara la solucion 
 * @version 0.6.4 -
 * @date 2023-19-01
 * @author Dios-Fer
 */


void Salida_resultado (double x1, double x2, bool sol){
	
	if (sol==true){
		if (x1==x2){
			cout << BOLDYELLOW <<"En tu ecuacion solo hay una solucion x=" <<x1<<endl;
		}
		else {
			cout << BOLDYELLOW <<"Las soluciones de tu ecuacion son: x="<<BOLDGREEN<<x1<<BOLDYELLOW <<" y x="<<BOLDGREEN<<x2<<endl;
		}
	}
	else {//no hay solucion
		cout << BOLDMAGENTA<<"En la ecuacion no hay soluciones"<<endl;
	}

}




 /* *
 * @brief Módulo (main) confeccionar el programa de hacer una ecuacion de segundo grado
 * @version 0.6.4 -
 * @date 2023-19-01
 * @author Dios-Fer
 */
 
void Porgrama_EcuacionSegundoGrado (){
	
	double a=0, b=0, c=0;
	double x1=0, x2=0;
	bool sol=false;
	
	Pedida_ecuacion (a, b, c);//introducir los datos
	sol = clasificar_resolver_ecuacion (a, b, c, x1, x2);//obtener el camino para la solucion y la solucion
	Salida_resultado (x1, x2, sol);//mostrar la solucion
	
}


 /* *
 * @brief Módulo de pedida y entrada de datos del MCM
 * @post de filtrados dos numeros 
 * @version 0.6.5 -
 * @date 2023-19-01
 * @author Dios-Fer
 */
void pedida_MCM (int &numero1, int &numero2){
	bool numero=true;
	do{
		cout << BOLDYELLOW << "==================================================================="<<endl;
		cout << BOLDYELLOW << "Introduzca dos numero para hacer el mcm de estos: ";
		numero=true;
	
		cin >> numero1 >> numero2;
		
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
			numero=false;
		}
	}while(numero==false);
}


/* *
 * @brief Módulo para calcular el MCM
 * @param int nuero1 
 * @param int nuero2 
 * @return int mcm siendo el mcm entre los dos numeros
 * @pre numero1 y numero2 son validos
 * @post se dara la solucion al modulo necesario
 * @version 0.6.6 -
 * @date 2023-20-01
 * @author Dios-Fer
 */
int MCM (int numero1, int numero2){
	int mcd=0, mcm=0;
	mcd = MCD (numero1, numero2);
	mcm = ((numero1 * numero2) / mcd);//Partimos de la ecuacion a*b= MCD (a, b) * MCM (a, b)

	return mcm;
}


 /* *
 * @brief Módulo que saca el MCM
 * @post salida de resultados
 * @version 0.6.7 -
 * @date 2023-20-01
 * @author Dios-Fer
 */
void salida_MCM (int numero1, int numero2, int mcm){
	cout << endl<<BOLDYELLOW<<"El minimo comun multiplo de tus numeros: "<< BOLDBLUE<<numero1 <<BOLDYELLOW<<" y "<<BOLDBLUE<<numero2<<BOLDYELLOW<<" es: " << BOLDCYAN<<mcm << endl<<endl;
}

 /* *
 * @brief Módulo que conecta y ejecuta el MCM
 * @version 0.6.7 -
 * @date 2023-20-01
 * @author Dios-Fer
 */
void Programa_MCM (){
	int numero1=0, numero2=0;
	int mcm=0;
	pedida_MCM (numero1, numero2);
	mcm=MCM (numero1, numero2);
	salida_MCM (numero1, numero2, mcm);
}



 /* *
 * @brief Módulo que obtiene el numero de segundos
 * @post numero filtrado
 * @return int numero_segundos numero total de segundos
 * @version 0.6.8 -
 * @date 2023-20-01
 * @author Dios-Fer
 */
long int pedida_segundos (){
	long int numero_segundos=0;
	bool numero=true;

	do{
		cout << BOLDYELLOW << "==================================================================="<<endl;
		cout << BOLDYELLOW << "Introduzca los segundos que desea convertir: ";
		numero=true;
	
		cin >> numero_segundos;
		
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal el numero"<<RESET<<endl<<endl;
			numero=false;
		}
	}while(numero==false);


	return numero_segundos;
}
 /* *
 * @brief Módulo que reduce el primer numero a menos de sesenta y pasa al segundo la division del primer numero (para pasar de segundos a minutos o de minutos a horas)
 * @post pasar a una unidad superior de tiempo la cual ascienda de 60 en 60
 * @param long int numero_antiguo (numero de segundos (segundos-->minutos) o numero de minutos (minutos-->horas))
 * @param long int numero_nuevo (numero de minutos (segundos-->minutos) o numero de horas (minutos-->horas))
 * @version 0.6.9 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void entre60 (long int &numero_antiguo, long int &numero_nuevo){
	numero_nuevo = numero_antiguo / 60;
	numero_antiguo = numero_antiguo % 60;

	if (DEBUG == true){
    cout << BOLDRED << "DEBUG(entre60): Salgo de entre60" << RESET << endl;
    cout << BOLDRED << "DEBUG(entre60): numero_antiguo = " << numero_antiguo << RESET << endl;
		cout << BOLDRED << "DEBUG(entre60): numero_nuevo = " << numero_nuevo << RESET << endl;

	}
}


 /* *
 * @brief Módulo que reduce el primer numero a menos de 24 y pasa al segundo la division del primer numero (para pasar de horas a dias)
 * @post pasar a una unidad superior de tiempo la cual ascienda de 24 en 24
 * @param long int numero_antiguo (numero de horas (horas-->dias))
 * @param long int numero_nuevo (numero de dias (horas-->dias))
 * @version 0.7 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void entre24 (long int &numero_antiguo, long int &numero_nuevo){
	numero_nuevo = numero_antiguo / 24;
	numero_antiguo = numero_antiguo % 24;

	if (DEBUG == true){
    cout << BOLDRED << "DEBUG(entre60): Salgo de entre24" << RESET << endl;
    cout << BOLDRED << "DEBUG(entre60): numero_antiguo = " << numero_antiguo << RESET << endl;
		cout << BOLDRED << "DEBUG(entre60): numero_nuevo = " << numero_nuevo << RESET << endl;

	}
}

 /* *
 * @brief Módulo para repartir un numero de segundos entre las diferentes unidades de tiempo basicas
 * @post pasar las nuevas unidades bien repartidas
 * @param long int numero_segundos
 * @param long int numero_minutos
 * @param long int numero_horas
 * @param long int numero_dias
 * @version 0.7 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void repartir_segundos (long int &numero_segundos, long int &numero_minutos, long int &numero_horas, long int &numero_dias){
	entre60 (numero_segundos, numero_minutos);
	entre60 (numero_minutos, numero_horas);
	entre24 (numero_horas, numero_dias);
}




 /* *
 * @brief Módulo para mostrar las distintas unidades de tiempo 
 * @post mostrar por pantalla
 * @param long int numero_segundos
 * @param long int numero_minutos
 * @param long int numero_horas
 * @param long int numero_dias
 * @version 0.7 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void salida_tiempo (long int numero_segundos, long int numero_minutos, long int numero_horas, long int numero_dias){
	cout << endl <<BOLDMAGENTA << numero_segundos << " s   "<< numero_minutos << " min   " << numero_horas << " h   "<<numero_dias << " d"<<endl<<endl<<RESET;

}


 /* *
 * @brief Módulo que conecta y ejecuta el procedimiento time
 * @version 0.7 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void Programa_time (){
	long int numero_segundos=0, numero_minutos=0, numero_horas=0, numero_dias=0;
	numero_segundos=pedida_segundos ();
	repartir_segundos (numero_segundos, numero_minutos, numero_horas, numero_dias);
	salida_tiempo (numero_segundos, numero_minutos, numero_horas, numero_dias);
}


 /* *
 * @brief Módulo que indica una posicion no valida de tablero
 * @post muestra en caso de no ser valido, un mensaje de error
 * @version 0.7.1 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void posicion_no_valida (bool posicion_valida){
	if (posicion_valida==false){
		cout <<BOLDRED<< "Posicion no valida, repitala"<<RESET<<endl;
	}
}



 /* *
 * @brief Módulo para introducir coordenadas 
 * @post pasara las coordenadas 
 * @param int X
 * @param int Y
 * @version 0.7.2 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void entrada_posicion (int &X, int &Y){
		bool numero=true;
		do{
			numero=true;
		
			cin >> X >> Y;
			
			if(cin.fail()==1){//filtro para letras
				cin.clear();
				cin.ignore(10000, '\n');
				cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
				numero=false;
			}
		}while(numero==false);
}

 /* *
 * @brief Módulo que comprueba si las coordenadas x y estan dentro de un tablero de ajedrez
 * @return posicion_valida (true dentro, false fuera)
 * @param int X
 * @param int Y
 * @version 0.7.2 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
bool dentro_tablero (int X, int Y){
	bool posicion_valida = true;
	if (X<1 || X>8 || Y<1 || Y>8){
		posicion_valida = false;
	}

	return posicion_valida;
}





 /* *
 * @brief Módulo para diferenciar entrada_posicion en la posicion inicial de la final
 * @post dara un mensaje indicando que se encuentra en la posicion inicial
 * @version 0.7.2 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void Mensaje_PI (){
	cout << "Introduzca la posicion inicial de la X y de la Y siendo esta posicion (1-8) (1-8)"<<endl;
}


 /* *
 * @brief Módulo para diferenciar entrada_posicion en la posicion inicial de la final
 * @post dara un mensaje indicando que se encuentra en la posicion final
 * @version 0.7.2 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void Mensaje_PF (){
	cout << "Introduzca la posicion final de la X y de la Y siendo esta posicion (1-8) (1-8)"<<endl;
}


 /* *
 * @brief Módulo que filtra posiciones del tablero hasta lograr una final e inicial que cumplan con la condicion de estar dentro
 * @post pasara las coordenadas
 * @param int XI
 * @param int YI
 * @param int XF
 * @param int YF
 * @version 0.8 -
 * @date 2023-21-01
 * @author Dios-Fer
 */
void validez_tablero(int &XI, int &YI, int &XF, int &YF){
	bool posicion_valida=true;
	
	do{//Posicion inicial
		Mensaje_PI ();
		entrada_posicion (XI, YI);
		posicion_valida = dentro_tablero (XI, YI);
		posicion_no_valida (posicion_valida);
	}while (posicion_valida==false);

	do{//Posicion inicial
		Mensaje_PF ();
		entrada_posicion (XF, YF);
		posicion_valida = dentro_tablero (XF, YF);
		if ((XF==XI)&&(YI==YF)){//no puedes no moverte
			posicion_valida=false;
		}
		posicion_no_valida (posicion_valida);

	}while (posicion_valida==false);

	if (DEBUG == true){

		cout << BOLDRED << "DEBUG(validez_tablero): Salgo de validez_tablero" << RESET << endl;
		cout << BOLDRED << "DEBUG(validez_tablero): XI= " << XI << "     YI= "<<YI << "     XF= " << XF << "     YF= " << YF<< RESET << endl;

	}
}


 /* *
 * @brief Módulo para introducir la pieza a mover y comprobar que sea una pieza valida
 * @return int ficha pieza a mover (siendo 1-4)
 * @version 0.7.3 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
int entrada_pieza (){

	int ficha=0;
	bool numero=true;

	cout << "Intoduzca la pieza que desea mover:"<<endl;
	cout << "#1 Reina"<<endl;
	cout << "#2 Torre"<<endl;
	cout << "#3 Alfil"<<endl;
	cout << "#4 Caballo"<<endl<<endl;
	cout << " #";
	do{
		numero=true;
	
		cin >> ficha;
		


		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
			numero=false;
		}

		if (ficha != 1 && ficha != 2 && ficha != 3 && ficha != 4){//filtro de piezas admitidas
			cout << BOLDRED << "Pieza no valida"<<RESET<<endl<<endl;
			numero=false;
		}

	}while(numero==false);

	return ficha;
}


 /* *
 * @brief Módulo para comprobar si el movimiento de la torre es valido
 * @param int diferencia_X casillas movidas en la x
 * @param int diferencia_Y casillas movidas en la y
 * @return validez (validez del movimiento para la torre)
 * @version 0.8 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
bool movimiento_torre (int diferencia_X, int diferencia_Y){
	bool validez=false;

	validez = (((diferencia_X == 0) && (diferencia_Y != 0)) || ((diferencia_Y == 0) && (diferencia_X != 0))); //no se mueve en la x y si en la y o si en la y y no en la x

	return validez;
}


 /* *
 * @brief Módulo para comprobar si el movimiento del alfil es valido
 * @param int diferencia_X casillas movidas en la x
 * @param int diferencia_Y casillas movidas en la y
 * @return validez (validez del movimiento para el alfil)
 * @version 0.8 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
bool movimiento_alfil (int diferencia_X, int diferencia_Y){
	bool validez=false;

	validez = (abs(diferencia_X) == abs(diferencia_Y));

	return validez;
}


 /* *
 * @brief Módulo para comprobar si el movimiento del caballo es valido
 * @param int diferencia_X casillas movidas en la x
 * @param int diferencia_Y casillas movidas en la y
 * @return validez (validez del movimiento para el caballo)
 * @version 0.8 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
bool movimiento_caballo (int diferencia_X, int diferencia_Y){
	bool validez=false;

	diferencia_X = abs(diferencia_X);//valor absoluto para reducir los casos
	diferencia_Y = abs(diferencia_Y);//valor absoluto para reducir los casos

	validez = (((diferencia_X == 2)&&(diferencia_Y == 1))|| ((diferencia_X == 1)&&(diferencia_Y == 2)));//la diferencia siempre sera de 2 en uno y 1 en el otro

	return validez;

}



 /* *
 * @brief Módulo para comprobar si el movimiento de la reina es valido
 * @param int diferencia_X casillas movidas en la x
 * @param int diferencia_Y casillas movidas en la y
 * @return validez (validez del movimiento para la reina)
 * @version 0.8 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
bool movimiento_reina (int diferencia_X, int diferencia_Y){
	bool valido=true;
	valido = (!(movimiento_torre(diferencia_X, diferencia_Y) && movimiento_alfil(diferencia_X, diferencia_Y)));//debe de cumplir con uno de los dos 
	return valido;
}




 /* *
 * @brief Módulo para comprobar que un movimiento de una pieza concreta sea valido
 * @pre posiciones (XI, YI, XF, YF) dentro del tablero
 * @pre int ficha (1-4)
 * @param int ficha  
 * @param int XI
 * @param int YI
 * @param int XF
 * @param int YF
 * @return valido (validez del movimiento para la pieza introducida)
 * @version 0.8 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
bool movimiento_pieza (int ficha, int XI, int YI, int XF, int YF){
	bool valido=false;
	int diferencia_X = (XF - XI);
	int diferencia_Y = (YF - YI);

	if (ficha==1){
		valido = movimiento_reina (diferencia_X, diferencia_Y);
	}

	else if (ficha==2){
		valido = movimiento_torre (diferencia_X, diferencia_Y);
	}

	else if (ficha==3){
		valido = movimiento_alfil (diferencia_X, diferencia_Y);
	}

	else if (ficha==4){
		valido = movimiento_caballo (diferencia_X, diferencia_Y);
	}
	return valido;

}


 /* *
 * @brief Módulo para obtener y comprobar el movimiento de una ficha 
 * @return validez_movimiento
 * @version 0.7.3 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
bool validez_pieza (int XI, int YI, int XF, int YF){

	int ficha=0;//1Torre, 2Alfil, 3Reina, 4caballo;
	bool validez_movimiento=true;

	ficha = entrada_pieza ();

	validez_movimiento = movimiento_pieza (ficha, XI, YI, XF, YF);


	return validez_movimiento;
}

 /* *
 * @brief Módulo para la salida de kasparov
 * @post muestra por pantalla la validez del movimiento introducido anteriormente
 * @version 0.7.3 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
void salida_validez (bool validez_movimiento){
	if (validez_movimiento==true){
		cout << "Tu movimiento es valido"<<endl<<endl;
	}
	else{
		cout << "Tu movimiento no es valido"<<endl<<endl;
	}
}

 /* *
 * @brief Módulo que conecta y ejecuta kasparov
 * @version 0.7.3 -
 * @date 2023-22-01
 * @author Dios-Fer
 */
void Programa_kasparov (){
	int XI=0, YI=0, XF=0, YF=0;
	bool validez_movimiento=true;
	validez_tablero (XI, YI, XF, YF);
	validez_movimiento = validez_pieza (XI, YI, XF, YF);
	salida_validez (validez_movimiento);

}



/* *
* @brief Módulo que se encarga de obtener un numero (con un mensaje que hace referencia al programa nocomaco)
* @return int numero
* @version 0.8.1
* @date 2023-22-01
* @author Dios-Fer
*/
int numero_nicomaco (){
	int numero_a_elevar=0;
	bool numero_correcto=true;
	do{
		numero_correcto=true;
		cout << "Introduzca un numero para elevar al cubo: ";
		cin >> numero_a_elevar;
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal el numero"<<RESET<<endl<<endl;
			numero_correcto=false;
		}
		
	}while(numero_correcto==false);
	
	return numero_a_elevar;
}


/* *
* @brief Módulo que se encarga de elevar al cubo por medio del metodo de nocomano
* @param int contador numero del impar vamos subiendo y haciendo mas
* @param int impar calculamos el impar contador (contador=8 calculamos el octavo impar (15))
* @param int i numero que vamos a calcular
* @return int resultado
* @version 0.8.2
* @date 2023-22-01
* @author Dios-Fer
*/
int elevar_al_cubo_nicomaco (int &contador, int &impar, int i){
	int resultado=0;

	for (int j=1; j<=i; j++){

		impar=contador*2-1;

		contador++;

		resultado =resultado+impar;

	}

	return resultado;
}


/* *
* @brief Módulo que se encarga de obtener elevar al cubo todos los numeros hasta llegar al que queremos
* @param int numero_a_elevar el numero que queremos
* @return int resultado_mi_numero mi numero al cubo
* @version 0.8.2
* @date 2023-22-01
* @author Dios-Fer
*/
int elevar_hasta_mi_numero (int numero_a_elevar){
	int impar=1, contador=1;
	int resultado_mi_numero=0;

	for (int i=1; i<=numero_a_elevar; i++){
		resultado_mi_numero=0;

		resultado_mi_numero = elevar_al_cubo_nicomaco (contador, impar, i);
	}

	if (DEBUG == true){
        cout << BOLDRED << "DEBUG(elevar_hasta_mi_numero): Salgo de elevar_hasta_mi_numero" << RESET << endl;
        cout << BOLDRED << "DEBUG(elevar_hasta_mi_numero): res= " << resultado_mi_numero << RESET << endl;
	}


	return resultado_mi_numero;

}

/* *
* @brief Módulo muestra por pantalla el resultado de nocmaco (el numero introducido al cubo)
* @post muestra por pantalla el resultado
* @version 0.9
* @date 2023-22-01
* @author Dios-Fer
*/

void salida_nicomaco (int resultado){
	cout << "El resultado de elevar tu numero al cubo es: "<<resultado<<endl<<endl;
}




/* *
* @brief Módulo que se encarga de obtener elevar al cubo y mostrar un numero
* @version 0.9
* @date 2023-22-01
* @author Dios-Fer
*/
void Programa_nicomaco (){
	int numero_a_elevar=0;
	int resultado=0;
	numero_a_elevar=numero_nicomaco ();
	resultado = elevar_hasta_mi_numero (numero_a_elevar);
	salida_nicomaco (resultado);
}


/* *
* @brief Módulo para la salida de la biseccion
* @param double resultado
* @post mostrara el resultado
* @version 9.2
* @date 2023-22-01
* @author Dios-Fer
*/
void salida_biseccion (double resultado){
	cout << "Tu resultado es: "<<resultado<<endl<<endl;

}



/* *
* @brief Módulo que reajusta el vorde
* @param double &derecha
* @param double &izquierda
* @param centro
* @version 1.0
* @date 2023-22-01
* @author Dios-Fer
*/
void reajuste (double &izquierda, double &derecha, double centro) {

	if ((centro*centro*centro+centro-1) < 0){
		izquierda=centro;
	}	
	
	else {
		derecha=centro;
	}

}

/* *
* @brief Módulo que reajusta el centro
* @param double derecha
* @param double izquierda
* @return centro
* @version 1.0
* @date 2023-22-01
* @author Dios-Fer
*/
double centrar (double izquierda, double derecha) {
	double centro;
	centro = ((derecha+izquierda)/2);
	return centro;
}




/* *
* @brief Módulo que repite el proceso hasta llegar a la pecision deseada
* @param double precision
* @return resultado
* @version 1.0
* @date 2023-22-01
* @author Dios-Fer
*/
double rep_precision (double precision){
	double izquierda=0.0, derecha=1.0;
	double centro = 0.0;
	double resultado = 0.0;

	while ((derecha-izquierda)>precision){
		centro = centrar (izquierda, derecha);
		reajuste (izquierda, derecha, centro);
	}

	resultado = centrar (izquierda, derecha);

	return resultado;
}


/* *
* @brief Módulo que obtiene la precision para la biseccion
* @post precision >0.0 y <1.0
* @return double precision
* @version 0.9.2
* @date 2023-22-01
* @author Dios-Fer
*/
double entrada_precision (){
	bool numero=true;
	double precision=0.0;

	do{
		numero=true;
		cout << "Indique la precision entre 0.0 y 1.0: ";
	
		cin >> precision;
		
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal el numero"<<RESET<<endl<<endl;
			numero=false;
		}
		else if (precision>1.0 || precision<0.0){//precision entre 0.0 y 1.0
			numero=false;
			cout << BOLDRED<<"La precision debde de estar entre 0.0 y 1.0"<<endl<<RESET<<endl;
		}

	}while(numero==false);

	return precision;
}






/* *
* @brief Módulo que ejecuta el programa en conjunto de la biseccion
* @version 0.99.2
* @date 2023-22-01
* @author Dios-Fer
*/
void Programa_biseccion (){
	double precision=0.0;
	double resultado=0.0;

	precision = entrada_precision ();
	resultado = rep_precision (precision);
	salida_biseccion (resultado);

}



 /* *
 * @brief Módulo que muestra el menu
 * @post muestra el menu 
 * @version 0.9.1
 * @date 2023-22-01
 * @author Dios-Fer
 */
void mostrar_menu (){

	cout << endl << BOLDYELLOW << "===================================================================================="<<endl;
	cout << BOLDYELLOW << "De las actividades realizadas a lo largo de la U3 elija que programa desea ejecutar: "<<endl<<endl;
	cout << BOLDGREEN << "     #1 Programa contador de primos en un intevalo" << endl;
	cout << BOLDBLUE << "     #2 Pograma que calcula el maximo y minimo de una serie de numeros introducidos"<<endl;
	cout << BOLDMAGENTA << "     #3 Pograma para calcula el MCD entre dos numeros" <<endl;
	cout << BOLDCYAN << "     #4 Pograma para resolver una ecuacion de segundo grado" <<endl;
	cout << BOLDGREEN << "     #5 Pograma para calcula el MCM entre dos numeros" <<endl;
	cout << BOLDBLUE << "     #6 Pograma que transforma un numero de segundos en su equivalente en dias, horas, minutos y segundos"<<endl;
	cout << BOLDYELLOW << "     #7 Pograma para ver la validez de un movimiento en ajedrez" <<endl;
	cout << BOLDMAGENTA << "     #8 Programa para elevar un numero al cubo (nicomaco)" <<endl;
	cout << BOLDCYAN << "     #9 Programa para la biseccion" <<endl;
	cout << BOLDRED <<endl<< "     #0 Cerrar"<<endl<<endl;
	
	cout << BOLDYELLOW << "     #";
	
}
 
 /* *
 * @brief Módulo que recibe la eleccion del usuario y en funcion ejecuta lo solicitado (con llamadas a los respectivos modulos)
 * @return rep (sera inicializado en true para su repeticion pero una de las opciones sera que cierre el programa, al ser false el modulo en cuestion cortara el bucle y cerrara el programa)
 * @post indica si se cierra o repite el programa
 * @version 0.9.1
 * @date 2023-22-01
 * @author Dios-Fer
 */
 
bool menu_de_ejecucion (){
	char eleccion=' ';//hay 9 programas, usaremos del 1 al nueve para estos y el 0 para cerrar
	bool rep=true;
	
	cin >> eleccion;
	cout << endl;
	
	if (eleccion == '1'){
		Programa_PrimosEnIntervalo ();//Programa para calcular el numero de primos en un intervalo
	}
	
	else if (eleccion == '2'){
		Programa_CalcularMaxMin ();//Programa de calcular el maximo y minimo
	}
	
	else if (eleccion == '3'){
		Programa_MCD ();//Programa para calcular el MCD entre dos numeros
	}
	
	else if (eleccion == '4'){
		Porgrama_EcuacionSegundoGrado ();//Programa para resolver una ecuacion de segundo grado
	}

	else if (eleccion == '5'){
		Programa_MCM ();//Programa para calcular el MCM entre dos numeros
	}

	else if (eleccion == '6'){
		Programa_time ();//Programa para calcular el procedimiento time
	}

	else if (eleccion == '7'){
		Programa_kasparov ();//Programa para ver la validez de un movimiento en ajedrez
	}

	else if (eleccion == '8'){
		Programa_nicomaco ();//Programa elevar un numero al cubo
	}
	else if (eleccion == '9'){
		Programa_biseccion ();//Programa la biseccion
	}
	else if (eleccion == '0'){
		rep=false;
	}
	
	else{//filtro
		cout << BOLDRED << "El caracter introducido no es valido" << endl << endl << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
	return rep;
}
 
  /* *
 * @brief Módulo (main) que tendra la llamada a la salida de menu y a la eleccion del menu adsemas de contar con la repeticion y condicion de cierre del programa completo
 * @param bool rep (vendra del modulo que recibe los datos)
 * @return 0
 * @post detendra el programa cuando se le indique por medio de la llamada a "menu_de_ejecucion"
 * @version 0.1
 * @version 0.2 
 * @date 2023-15-01
 * @version 0.3 -
 * @date 2023-16-01
 * @author Dios-Fer
 */
 
int main (){
	bool rep=true;
	
	do{
	
		mostrar_menu ();
		rep = menu_de_ejecucion ();
		
	}while(rep==true);

}
 
