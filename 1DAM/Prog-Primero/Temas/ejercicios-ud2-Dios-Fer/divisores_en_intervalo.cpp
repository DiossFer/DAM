#include <iostream>
using namespace std;
int main (){
	
	int inicio = 0, fin = 0, numero = 0, contador = 0;
	
	//modificaremos inicio para comprobar los numeros del intervalo
	cout << "Introduce el inicio del intervalo: ";
	cin >> inicio;
	
	cout << "Introduce el final del intervalo: ";
	cin >> fin;
	
	cout << "Introduce el numero del que quieres saber que dibisores tiene dentro del intervalo: ";
	cin >> numero;
	
	cout << "---------------------------------------------------" << endl;
	
	//compueba todos los numero del intervalo hasta terminar con este o llegar al numero en cuestion
	for(inicio; ((inicio <= fin)&&(inicio <= numero)); inicio = inicio + 1){
		//El 0 nos dara error
		if (inicio != 0)
			//Comprueba si son divisores del numero
			if (numero%inicio==0){
				cout << "Dentro de nuestro intervalo: " << inicio << " es divisor de " << numero << endl;
				//V2	// Contador de divisores que tiene en el intervalo
				contador = contador + 1;
			}
	}
	//V2	//Cuantos divisores que tiene en el intervalo
	cout << "---------------------------------------------------" << endl;
	cout << "Dentro del nuestro intervalo, " << numero << " tiene " << contador << " divisores" << endl;
}
