//Actividad 1.7
#include <iostream>
using namespace std;
int main() {
	double numero1=0, numero2=0, resultado_suma=0, resultado_resta=0, resultado_multiplicacion=0, resultado_division=0;
	cout << "Introduzca el primer numero ";
	cin >> numero1; 
	cout << "Introduzca el segundo numero ";
	cin >> numero2;
	/*Tras introducir los dos numeros se realizan las 4 operaciones*/
	resultado_suma = numero1 + numero2;
	resultado_resta = numero1 - numero2;
	resultado_multiplicacion = numero1 * numero2;
	resultado_division = numero1 / numero2;
	/*Muestra por pantalla las soluciones*/
	cout << "El resultado de la suma entre estos dos numero es: "<< resultado_suma << endl;
	cout << "El resultado de la resta es: "<< resultado_resta << endl;
	cout << "El resultado de la multiplicacion es: "<< resultado_multiplicacion << endl;
	cout << "El resultado de tu division es: "<< resultado_division << endl;
//El programa nos fallara a la hora de dividir entre 0 o cuando pongamos una letra/simbolo, tambien con cosas como numeros excesivamente pequeños o muy grandes.
}

