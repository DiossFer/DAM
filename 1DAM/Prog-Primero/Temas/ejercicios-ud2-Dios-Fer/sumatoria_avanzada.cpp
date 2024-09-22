#include <iostream>
using namespace std;
int main (){

	int numero=0;
	double suma=0.0;
	
	do{
	//rubrica --> suma= suma + ((1.0-i)/i)	//Introducimos el numero hasta el cual llegaremos
	cout << "Introduce un numero natural y veamos la sumatoria teniendo en cuenta la rubrica de la transparencia desde 0 hasta llegar a ese numero: ";
	cin >> numero;
	}while (numero<0);
	
	//hacemos la sumatoria
	for (int i=1; i<=numero; ++i){
		suma= suma + ((1.0-i)/i);
	}

	cout << "El resultado de la sumatoria es de: " << suma << endl;
	
}
