#include <iostream>
using namespace std;

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
 * @brief Módulo que comprueba si un numero es primo o no (con capacidad para entradas negativas)
 * @param int i numero a evaluar
 * @return bool noprimo resultado de la evaluacion (noprimo==true --> no es primo / noprimo==false --> es primo)
 * @version 2.0
 * @date 2023-14-01
 * @version 2.1 -
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
 * @version 2.0
 * @date 2023-14-01
 * @version 2.1 -
 * @date 2023-16-01
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
 * @brief Módulo (main) que pide y filtra datos y da las salidas de el contador de primos en intervalo
 * @return 0;
 * @post numero1 > numero2
 * @version 2.0
 * @date 2023-14-01
 * @version 2.1 -
 * @date 2023-16-01
 * @author Dios-Fer
 */
int main (){

	int numero1=0, numero2=0;//datos (entradas)

	int numero_de_primos=0;//solucion (salida)
	
	bool numero=true;
	
	do{
		cout << BOLDYELLOW<<endl;
		numero=true;
		
		cout << "======================================================================" << endl;
		cout << "Introduce un intervalo y veamos cuantos numeros primos hay en este: ";

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
	
	
	numero_de_primos = primos_en_intervalo (numero1, numero2);//llamamos a la funcion para que nos devuelva el numero de primos y lo guarde en la variable "numero_de_primos"

	cout << BOLDBLUE<<endl<<"El numero de primos que hay en tu intervalo es de: " <<BOLDCYAN<<numero_de_primos<< BOLDBLUE<<" numeros primos." << endl<<endl;
	
	return 0;
}
