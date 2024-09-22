#include <iostream>
using namespace std;
int main(){

	//declaramos los dos numeros y el bool donde se guardara si es false o true el que sea mayor o menor uno a otro

	double numero_1, numero_2;
	bool A;
	
	//pedimos los datos
	
	cout << "Inserte dos numero y veamos cual es el mayor." << endl;
	
	cout << "Inserte el primer numero: ";
	cin >> numero_1;
	
	cout << "Inserte el segundo numero: ";
	cin >> numero_2;
	
	//guardamos en A si es false o true
	
	A = numero_1 < numero_2;
	
	
	//Aqui tenemos dos if, dependiendo de cual if se cumpla nos dara la solucion
	
	if (A==true){
		cout << "El segundo numero es el mayor:  " << numero_2 << " > " << numero_1 << endl;
	}
	
	
	if (A==false){
		cout << "El primer numero es el mayor:  " << numero_1 << " > " << numero_2 << endl;
	}
	
}
