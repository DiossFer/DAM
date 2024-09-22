#include <iostream>
using namespace std;
int main(){

	//"Variables"
	int numero_fila = 1, numero = 7, numero_fila_final = 10, resultado = 0;
	
	
	
	//numero de la fila actual (1), se para si este es mayor al que queremos (10) y si ya lo es no entra, ira haciendo multiplicaciones y sumando al contador hasta que deje de cumplirse la condicion
	for (numero_fila=1; numero_fila <= numero_fila_final; numero_fila = numero_fila + 1){
		resultado = (numero * numero_fila);
		cout << numero << "x" << numero_fila << "=" << resultado << endl;
	}
	
}

