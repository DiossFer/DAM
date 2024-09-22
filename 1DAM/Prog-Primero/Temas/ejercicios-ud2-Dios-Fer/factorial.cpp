#include <iostream>
using namespace std;
int main (){


	int numero=0, resultado=1;	
	
	//Filtro para los negativos pues no tienen factorial
	do {
		cout << "Di un numero para realizar su factorial: ";
		cin >> numero;
	} while (numero<0);
	
	//el factorial de 0 es 1
	if (numero==0){
		resultado=1;
	}
	
	//Calculo de factoriales [1,∞)
	else {
		//calculamos el factorial
		for (int i=1; i!=numero+1; ++i){
			resultado = i*resultado;
			
		}
	}
	
	cout << "El factorial de tu numero: " << numero << " es: " << resultado << endl;
	cout << numero << "! = " << resultado << endl;
	
}
