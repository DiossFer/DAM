#include <iostream>
using namespace std;
int main (){
	
	int numero = 0, suma = 0;
	
	cout << "Introduzca un numero, recuerde que si introduce el 0 detendra la introduccion de numeros: ";
	cin >> numero
	
	//He usado while para ahorrarme cuando metan un 0 al principio
	while(numero != 0){
		suma = suma + numero;
		cout << "Introduzca un numero, recuerde que si introduce el 0 detendra la introduccion de numeros: ";
		cin >> numero;
	}
	
	
	//Resultado
	cout << "El total de la suma de todos los numeros introducidos es: " << suma << endl;

}
