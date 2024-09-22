#include <iostream>
using namespace std;
int main (){

	int numero=0, resultado=0, impar=1;

	int nuevo_contador=1;
	
	
	do{//Filtro para no aceptar numeros negativos
		cout << "Introduce al numero al que quieres elevar al cubo: ";
		cin >> numero;
	} while (numero<0);

	
	//Hacemos esto para calcular en que inicio de suma de impares estamos, aqui un ejemplo: numero=2 --> empezamos en el 2º impar, numero=4 --> 7º impar
	for (int i=0; i<numero; i++){
		
		nuevo_contador+=i;	

	}
	
	//Con esto calculamos el cubo del numero partiendo del impar donde nos encontremos y avanzando los impares necesarios para dicho numero
	for (int j=1; j<=numero; j++){
			impar=nuevo_contador*2-1;
			nuevo_contador++;
			resultado = resultado+impar;
		}
		
	
	//Sacamos el cubo del numero calculado
	cout << "El cubo de tu numero es: " << resultado << endl;
}

