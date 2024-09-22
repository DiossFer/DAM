#include <iostream>
using namespace std;
int main (){

	int numero1=0, numero2=0, resto=0;
	
	cout << "Introduce 2 numeros para calcular el MCD de estos: ";
	cin >> numero1 >> numero2;
	
	//Para cuando hay dos 0
	if (numero1==0 && numero2==0){
		resto=0;
	}
	//Para evitar errores con el 0 a la derecha
	else if (numero2==0){
		resto=numero1;
		numero1=numero2;
		numero2=resto;
		resto=0;
		
		resto= numero1 % numero2;
	}
	
	//Para casos normales
	else{
	
		resto= numero1 % numero2;
	
	}
	
	//Metodo para sacar el mcd
	while(resto != 0){
	
	numero1=numero2;
	numero2=resto;
	resto=numero1 % numero2;
	
	}
	
	cout << "El MCD de tus dos numeros es: " << numero2 << endl;

}
