#include <iostream>
using namespace std;
int main(){

	//Variables
	int numero_fila = 1, numero = 0, numero_fila_final = 0, resultado = 0;
	
	//Pedimos el numero que quiere multiplicar
	cout << "Indique el numero del que quiere la tabla: ";
	cin >> numero;
	
	//Pedimos que tantas multiplicaciones quiere
	cout << "Indique que tantos multiplos quiere: ";
	cin >> numero_fila_final;
	
	
	//numero de la fila actual (1), se para si este es mayor al que queremos y si ya lo es no entra, ira haciendo multiplicaciones y sumando al contador hasta que deje de cumplirse la condicion
	for (numero_fila=1; numero_fila <= numero_fila_final; numero_fila = numero_fila + 1){
		resultado = (numero * numero_fila);
		cout << numero << "x" << numero_fila << "=" << resultado << endl;
	}
	
}

