#include <iostream>
using namespace std;
int main(){
//version simple (solo tabla del 7 y hasta 10)
	int numero_fila = 1, numero = 7;
	
	//
	cout << "Nuestro programa trabajara con la tabla del 7" << endl;
	
	while (numero_fila <= 10){
		
		cout << numero << "x" << numero_fila << "=" << numero * numero_fila << endl;
		numero_fila = numero_fila + 1;
		
	}
}
