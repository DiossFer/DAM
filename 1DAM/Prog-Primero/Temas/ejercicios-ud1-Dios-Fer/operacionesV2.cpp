#include <iostream>
using namespace std;
int main() {
	double numero1=0, numero2=0, resultado_suma=0, resultado_resta=0, resultado_multiplicacion=0, resultado_division=0;
	cout << "Introduce el primer numero, recuerde que debe de ser unicamente un numero (Ejemplos: 6, 54, 7.5) y si cuenta con decimales representelo con un punto (.) : ";
	cin >> numero1; 
	cout << "Introduce el segundo numero, con las mismas reglas que el primero: ";
	cin >> numero2;
	/*Tras introducir los dos numeros se realizan las 4 operaciones*/
	resultado_suma = numero1 + numero2;
	resultado_resta = numero1 - numero2;
	resultado_multiplicacion = numero1 * numero2;
	resultado_division = numero1 / numero2;
	/*Muestra por pantalla las soluciones*/
	cout << "El resultado de la suma entre estos dos numero es: "<< resultado_suma << endl;
	cout << "El resultado de la resta del primer numero menos el segundo es: "<< resultado_resta << endl;
	cout << "El resultado de la multiplicacion entre estos dos numero es: "<< resultado_multiplicacion << endl;
	cout << "El resultado de tu division es: "<< resultado_division << endl;
}
