#include <iostream>
using namespace std;
int main(){
//Lo he hecho asi en lugar de avanzar y hacerlo mas complejo ya que en la siguiente actividad lo pide mas complejo
	int numero_fila = 1, numero = 7;
	
	//
	cout << "Nuestro programa trabajara con la tabla del 7" << endl;
	
	do{
		
		cout << numero << "x" << numero_fila << "=" << numero * numero_fila << endl;
		numero_fila = numero_fila + 1;
		
	} while (numero_fila <= 10);
}
