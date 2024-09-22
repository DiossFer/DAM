#include <iostream>
#include <cmath>
using namespace std;
int main(){

	//Declaramos variables y constantes
	const double π=3.1415926535;
	double radio=0.0, area=0.0, perimetro=0.0;

	//Pedimos los datos
	cout << "Introduce el radio de tu circunferencia: ";
	cin >> radio;
	
	//Si es positivo se ejecuta el programa
	if (radio >=0 ){
		area = π * pow (radio,2);
		perimetro = π * 2 * radio;

		cout << "Teniendo en cuenta el radio introducido de: " << radio << "u" << endl;
		cout << "El area de tu circulo es: " << area << "u" << endl;
		cout << "El perimetro de tu circulo es: " << perimetro << "u" << endl;
		
	}
	
	//Si es negativo no se ejecuta el programa
	if (radio<0){
		cout << "Lo sentimos, pero no se puede introducir un radio negativo" << endl;
	}
}



