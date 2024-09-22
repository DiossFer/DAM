#include <iostream>//V1
using namespace std;

//Colores
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


long double suma (long double numero1, long double numero2){//Suma

	long double resultado=0.0;
	resultado = numero1 + numero2;
	return resultado;
	
}


long double resta (long double numero1, long double numero2){//Resta

	long double resultado=0.0;
	resultado = numero1 - numero2;
	return resultado;

}


long double division_decimal (long double numero1, long double numero2){//Division decimal

	long double resultado=0.0;
	resultado = numero1 / numero2;
	return resultado;

}

long double multiplicacion (long double numero1, long double numero2){//Multiplicacion

	long double resultado=0.0;
	resultado = numero1 * numero2;
	return resultado;
	
}



unsigned long int factorial (unsigned long int numero){//Factorial

	unsigned long int resultado=1;
	
	for (unsigned long int i=1; i<=numero; ++i){
		resultado = i*resultado;
	}
	
	return (resultado);

}

unsigned long int combinatoria (unsigned long int numero1, unsigned long int numero2){//Combinatoria

	unsigned long int resultado=0;
	resultado= (	(factorial(numero1))	/	(	(factorial(numero2))	*	(factorial(	(numero1 - numero2)	)	)	)	);
	return resultado;
	
}

long int division_r (long int numero1, long int numero2){//Division con resto

	long int resultado=0;
	resultado = numero1 / numero2;
	return resultado;
}


long int resto_d (long int numero1, long int numero2){//Resto de la division con resto

	long int resultado=0;
	resultado = numero1 % numero2;
	return resultado;

}


//daltan filtros
int main (){
	int eleccion=0;
	

	do{//Repeticion del programa
	
	
		//no me deja declarar dentro del switch ñas respectivas para cada operacion asi que las declarare fuera 
		long double num1_ld=0.0, num2_ld=0.0;//Para la suma, resta, multiplicacion y division decimal
		long int num1_li=0, num2_li=0;//Para la division y el resto
		unsigned long int num1_uld=0, num2_uld=0;//Para el factorial y la combinatoria 
		
		
		do {//Filtro del menu
		
			//Menu
			cout << BOLDWHITE <<endl<< "=============================================="<<RESET<<endl;
			
			cout << BOLDBLACK << "# Inserte 1 para realizar una suma" <<RESET<< endl;
			cout << BOLDRED << "# Inserte 2 para realizar una resta" <<RESET<< endl;
			cout << BOLDGREEN << "# Inserte 3 para realizar una multiplicacion" <<RESET<< endl;
			cout << BOLDYELLOW << "# Inserte 4 para realizar una division de enteros" <<RESET<< endl;
			cout << BOLDBLUE << "# Inserte 5 para realizar una division decimal" <<RESET<< endl;
			cout << BOLDMAGENTA << "# Inserte 6 para realizar el factorial de un numero" <<RESET<< endl;
			cout << BOLDCYAN << "# Inserte 7 para realizar una combinatoria" <<RESET<< endl;
			
			cout << BOLDWHITE << "                     ";
			cin >> eleccion;
			
			cout << endl<<BOLDWHITE << "=============================================="<<RESET<<endl<<endl;
			
			
			
			switch (eleccion){
			
				case 1://Suma
					cout << BOLDBLACK<<endl;
					//Pedidda de datos
					
					cout << "Elija el primer numero: ";
					cin >> num1_ld;
					cout << "Elija el segundo numero: ";
					cin >> num2_ld;
					
					//Resultado
					cout << BOLDBLACK <<endl<< "El resultado de tu suma es: "<< suma(num1_ld, num2_ld) <<RESET<< endl;
					
					break;
				
				
				case 2://Resta
					cout << BOLDRED <<endl;
					//Pedidda de datos
					
					cout << "Elija el primer numero: ";
					cin >> num1_ld;
					cout << "Elija el segundo numero: ";
					cin >> num2_ld;
					
					//Resultado
					cout << BOLDRED << endl<<"El resultado de tu resta es: " <<resta(num1_ld, num2_ld) <<RESET<< endl;
					break;
				
				case 3://Multiplicacion
				
					cout << BOLDGREEN <<endl;
					//Pedidda de datos
					
					cout << "Elija el primer numero: ";
					cin >> num1_ld;
					cout << "Elija el segundo numero: ";
					cin >> num2_ld;
					
					//Resultado
					cout << BOLDGREEN <<endl<< "El resultado de tu multiplicacion es: " <<multiplicacion(num1_ld, num2_ld) <<RESET<< endl;
					break;
				
				case 4://Division y resto de division
				
					cout << BOLDYELLOW <<endl;
					
					//Pedidda de datos
					
					cout << "Elija el primer numero: ";
					cin >> num1_li;
					do{
					cout << "Elija el segundo numero: ";
					cin >> num2_li;
					}while (num2_li==0);
					
					//Resultado
					cout << BOLDYELLOW <<endl<< "El resultado de tu division es: " << division_r(num1_li, num2_li) << " y su resto es: " << resto_d(num1_li, num2_li) <<RESET<< endl;
					break;
				
				case 5://Division decimal

					
					cout << BOLDBLUE<<endl;
					//Pedidda de datos
					
					cout << "Elija el primer numero: ";
					cin >> num1_ld;
					do{
					cout << "Elija el segundo numero: ";
					cin >> num2_ld;
					}while (num2_ld==0);
					//Resultado

					cout << BOLDBLUE <<endl<<"El resultado de tu division es: "<< division_decimal(num1_ld, num2_ld) <<RESET<< endl;
					break;
				
				case 6://Factorial
				//Al usar el unsigned no puedo poner filtro a los negativos
					cout << BOLDMAGENTA << endl;
					//Pedidda de datos
					cout << "Elija el numero para hacer su factorial: ";
					cin >> num1_uld;
					//Resultado
					cout << BOLDMAGENTA <<endl<<"El resultado de tu factorial es: "<< factorial(num1_uld) <<RESET<< endl;
					break;
				
				case 7://Combinatoria
				//Al usar el unsigned no puedo poner filtro a los negativos
					cout << BOLDCYAN<<endl;
					
					//Pedidda de datos
					cout << "Elija el primer numero: ";
					cin >> num1_uld;
					cout << "Elija el segundo numero: ";
					cin >> num2_uld;
					
					//Resultado
					cout << BOLDCYAN <<endl << "El resultado de tu combinatoria es: " << combinatoria(num1_uld, num2_uld) <<RESET<< endl;
					break;
					
					
				default://No valido
				
					cout << "Digito no valido" << endl;
					eleccion=8;//Condicion para repetir en caso de no ser valido
					break;
					
				}
				
		}while (eleccion==8);
			
			
			
			
			
			//Repeticion del programa reutilizando la variable eleccion
			cout << endl<<BOLDWHITE << "=============================================="<<RESET<<endl<<endl;
			cout << BOLDWHITE << "Inserte 0 si quiere cerrar el programa o cualquier otro numero si quiere repetir la ejecucion"<<RESET<<endl;
			cout << BOLDWHITE << "                          ";
			cin >> eleccion;
			
			if (eleccion==0){//En caso de terminar el programa
				cout << BOLDWHITE <<endl<< "=============================================="<<RESET<<endl<<endl;
			}
			
		
	}while(eleccion!=0);
	
}
