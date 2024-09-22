#include <iostream>
using namespace std;

int factorial (int numero){


	int resultado=1;


	for (int i=1; i<=numero; ++i){
		resultado = i*resultado;
	}
	
	return (resultado);
}



int main (){
	int numero=0, resultado=1;
	
	cout << "Inserte el numero para hacer el factorial: ";
	cin >> numero;
	
	
	resultado = factorial (numero);
	
	
	cout << "El factorial de tu numero " << numero << " es: " << resultado << endl;
	
}
