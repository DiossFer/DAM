#include <iostream>
using namespace std;
int main (){
	int contador=1, numero=0, resultado=0, impar=1;
	
	//Introducimos los datos
	
	do{//Filtro para no aceptar numeros negativos
		cout << "Introduce al numero al que quieres elevar al cubo: ";
		cin >> numero;
	} while (numero<0);
	
	//mientras que i sea menor al numero entratremos al bucle que hace todos los cubos de numeros 		//y no pararemos hasta optener el cubo que queremos
	for (int i=1; i<=numero; i++){
		resultado=0;
		
		//mientras que j sea menor a la i donde estemos calculararemos un el cubo correspondiente; al guardar el contador los impares no se reiniciaran
		for (int j=1; j<=i; j++){
			impar=contador*2-1;
			contador++;
			resultado =resultado+impar;
		}
		
	}
	//Sacamos unicamente el cubo que queremos a pesar de habrelos calculado todos hasta este
	cout << "El cubo de tu numero es: " << resultado << endl;
	}
