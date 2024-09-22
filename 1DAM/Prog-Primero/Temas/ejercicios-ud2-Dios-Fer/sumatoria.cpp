#include <iostream>
using namespace std;
int main (){

	int suma=0, numero=0;
	//introducimos el numero
	
	do{
	cout << "Introduce un numero natural y veamos la sumatoria desde 0 hasta llegar a ese numero: ";
	cin >> numero;
	}while (numero<0);
	
	//mientras sea menor o igual al numero sumamos 
	for (int i=1; i<=numero; ++i){
		suma=suma+i;
	}
	//suma de todos los numero hasta llegar al numero en cuestion
	cout << "El resultado de la sumatoria es de: " << suma << endl;
	
}
