#include <iostream>
using namespace std;
int main(){
	//El numero en cuestion, un numero para elevarlo y comprobar si es igual al numero que queremos comprobar y un bool que guarda esto
	int posible_cuadrado_perfecto = 0, posible_n_n2= 0;
	bool si_no=false;
	//pedimos el numero
	cout << "Introduce un numero y veamos si es un cuadrado perfecto: ";
	cin >> posible_cuadrado_perfecto;
	//Comprobamos si hay algun numero elevado al cuadrado que de nuestro numero
	for (posible_n_n2; ((posible_n_n2 <= posible_cuadrado_perfecto)&&(si_no==false)); ++posible_n_n2){
		si_no = ((posible_n_n2*posible_n_n2)==posible_cuadrado_perfecto);
	}
	//Salidas
	if (si_no)
		cout << "Tu numero " << posible_cuadrado_perfecto << " es un cuadrado perfecto, su raiz cuadrada es: " << posible_n_n2 - 1 << endl;
	else
		cout << "Tu numero " << posible_cuadrado_perfecto << " no es un cuadrado perfecto" << endl;

}
