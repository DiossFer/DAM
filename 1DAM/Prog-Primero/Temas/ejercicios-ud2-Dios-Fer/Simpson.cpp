#include <iostream>
using namespace std;
int main (){

	int frase_actual=1, frase_final=0;
	
	//Numero final
	cout << "Di cuantas veces deseas escribir la frase: ";
	cin >> frase_final;
	
	//Mientras que sea menor o igual al numero final
	do {
	cout << "No debo copiar en clase" << endl;
	frase_actual = frase_actual + 1;
	
	}while(frase_actual <= frase_final);
	
}
