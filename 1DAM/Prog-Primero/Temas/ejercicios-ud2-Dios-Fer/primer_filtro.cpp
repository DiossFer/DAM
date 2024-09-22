#include <iostream>
using namespace std;
int main (){

	double numero1, numero2;
	
	
	cout << "Introduce dos numeros, recuerda que ambos deben de ser mayores a 0: ";
	
	do{
	
	cin >> numero1 >> numero2;
	if (!(numero1>0.0 && numero2>0.0)){
		cout << "Tus numeros no son validos" << endl;
		cout << "Prueba con otros numeros: ";
		
	}
	
	}while (!(numero1>0.0 && numero2>0.0));
	
	cout << "Tus numeros son validos" << endl;

}
