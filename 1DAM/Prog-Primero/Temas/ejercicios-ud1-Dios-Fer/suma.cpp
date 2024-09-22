#include <iostream>
using namespace std;
/*Lo de arriba entiendo que es el contexto, donde estamos trabajando. Algo que simpre que se valla a hacer un programa debemos de incluir*/
int main() {
/*Creo que es como el inicio del programa una primera "etiqueta" para indicar que vamos a comenzar*/
	int a, b, res;
/*Aqui estamos declarando las variables decimos pues que a=x siendo x un valor que daremos mas adelante*/
	cout << "Introduce el primer numero: ";
/*El cout debe de ser coo el print en python algo que se va a comunicar un mensaje que usara la pantalla como dispositivo de salida de una manera grafica*/
	cin >> a; 
/*Aqui indicamos que se debe dar valor a la variable "a"; El texto de arriba nos indica que le demos el valor a la variable "a" por medio del dispositivo de entrada (teclado)*/
	cout << "Introduce el segundo numero: ";
	cin >> b;
/*Estos dos lo mismo que con a*/
	res = a + b;
/*Aqui se le indica al programa el orden y tipo de la operacion, este realiza la operacion y la guarda como la variable "res"*/
	cout << "El resultado es: "<< res << endl;
/*Nos muestra el mensaje ("El resultado es: ")y la solucion (res) por pantalla*/
}
/*Tanto el de inicio como el de cierre debe de aconpañar al programa dejando claro su inicio y final*/
