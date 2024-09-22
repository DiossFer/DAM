#include <iostream>
using namespace std;
int main (){
	
	int numero = 0, comprobador = 2;
	bool primo = true;
	
	cout << "Inserte un numero y comprobaremos si es primo o no: ";
	cin >> numero;
	
	//Cortara al llegar al numero en cuestion o en mi caso (linea 19) al comprobarse que no es primo por primera vez
	for (comprobador=2; comprobador < numero; comprobador = comprobador + 1){
		
		//SI es divisible (resto=0) entre un numero que no sea el o el 1 sera primo
		if ((numero % comprobador) == 0){
		primo = false;
	
		//Esto es para qu no compruebe el reso, una vez que encuentre uno corte el bucle
		comprobador = numero;

		}
	}
	
	if (primo == true)
		cout << "El numero " << numero << " es primo" << endl;
	else
		cout << "El numero " << numero << " no es primo" << endl;


}
