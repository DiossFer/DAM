#include <iostream>
using namespace std;
int main (){
	
	//Declaramos dato
	int dato=0;
	
	do{
		//Entrada de dato
		cin >> dato;
		cout << "Recibido: " << dato << endl;
		
	//Si es negativo cortamos la transmision (MIENTRAS que sea positivo o 0 seguimos)
	} while (dato >= 0);
		
	//Fin de la transmision
	cout << "Fin" << endl;
	
}
