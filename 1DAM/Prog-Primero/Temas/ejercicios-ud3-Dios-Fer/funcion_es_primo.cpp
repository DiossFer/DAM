#include <iostream>
using namespace std;

bool primo (int numero){
	bool solucion = true;
	//el 0 y el 1 no son primos al igual que los negativos; en caso de no pertenecer a estos entrara en el bucle
	if (numero<2){
		solucion=false;
	}
	//es primo hasta que se demuestre lo contrario
	for (int i=2; ((i<numero) && (solucion==true)); i++){
		//si alguna division entre un nmero que no sea el o uno tiene de resto 0 dejara de ser primo para ser no primo
		if (numero % i == 0){
			solucion=false;
		}
	}
	return solucion;
}


int main () {
	int num=0;
	bool p=false;
	
	cin >> num;
	//calculamos si el numero es primo
	p=primo(num);

	//devolbemos si primo es false (no primo) o si es true (primo)
	if (p==false){
		cout << "El numero " << num << " no es primo" << endl;
	}
	else{
		cout << "El numero " << num << " es primo" << endl;
	}


}
