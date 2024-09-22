#include <iostream>
using namespace std;
int main(){

	int numero_fila = 1, numero = 0, numero_fila_final=0;
	
	cout << "Introduzca que tabla quiere y cuantos multiplos del numero en cuestion: " << endl;
	//Introducimos el numero del que queremos la tabla
	cout << "Numero: ";
	cin >> numero;
	//Introducimos hasta donde queremos la tabla
	cout << "Multiplos: ";
	cin >> numero_fila_final;
	//Mientras que donde estemos no sea mayor a donde queremos llegar el programa dara multiplos nuevos del numero en cuestion
	do{
		cout << numero << "x" << numero_fila << "=" << numero * numero_fila << endl;
		numero_fila = numero_fila + 1;
		
	} while (numero_fila <= numero_fila_final);
}
