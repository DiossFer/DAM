#include <iostream>
using namespace std;
int main (){

	int numero=0, max=0, min=0;
	
	cout << "Introduce 100 numeros y veamos cual es el mayor y menor de todos" << endl;
	
	//Esto es para evitar que tome la inicializacion como numero
	cout << "Introduce un numero: ";
	cin >> numero;
	max=numero;
	min=numero;
	//Metemos los numeros y a la vez comprueba si uno es mayor/menor y los guarda en la respectiva variable
	for (int i=1; i<=99; ++i){
	
		cout << "Introduce un numero: ";
		cin >> numero;
		
		if (numero>max){
			max=numero;
		}
		
		else if (numero<min){
			min=numero;
		}
	}
	//Sacamos el maximo y el minimo
	cout << "------------------------------------" << endl;
	cout << "De los 100 numero el mayor ha sido: " << max << endl;
	cout << "De los 100 numero el menor ha sido: " << min << endl;
}
