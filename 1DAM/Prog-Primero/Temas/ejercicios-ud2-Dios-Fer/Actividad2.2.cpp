#include <iostream>
using namespace std;
int main(){

	//Variables
	int numero = 0;
	bool par;
	
	//pedimos el numero
	cout << " ______________________________________________________" << endl;
	cout << "|Elije un numero para ver si es par o impar: ";
	cin >> numero;
	cout << "|______________________________________________________" << endl;
	
	par = ((numero % 2) == 0);
	
	//si su resto es 0 (par)
	
	if (par == true){
		cout << "|El numero que has elejido (" << numero << ") es par   " << endl;
		cout << "|______________________________________________________" << endl;
	}
	
	//si su resto no es 0 (impar)
	
	if (par==false){
		cout << "|El numero que has elejido (" << numero << ") es impar " << endl;
		cout << "|______________________________________________________" << endl;
	}
	
}
