#include <iostream>
using namespace std;
int main (){

	int frase_actual=1, frase_final=0;
	
	//Numero final
	cout << "Di cuantas veces deseas escribir la frase: ";
	cin >> frase_final;
	
	//Que repita siempre que se cumpla que..
	//Aui vemos una ventaja, al no hacer siempre una nos quitamos cuando pedimos que haga 0 o un numero negativo

	while(frase_actual <= frase_final){
		cout << "No debo copiar en clase" << endl;
		frase_actual = frase_actual + 1;
	}
}
