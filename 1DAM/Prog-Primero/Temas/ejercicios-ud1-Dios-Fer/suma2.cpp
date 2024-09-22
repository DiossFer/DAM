#include <iostream>
/*Esto es contexto, nos indica que usaremos entrada y salida (en este caso teclado y pantalla)*/
using namespace std;
/*Esto es algo que debe estar siempre, al igual que el anterior es contexto*/
int main() {
/*esto indica que vamos a iniciar el programa principal, lo que este dentro de "{}", sera nuestro programa*/
	int a, b, res;
/*El int nos esta reservando un espacio en la memoria principal para un numero entrero (se reservan 32  bits)*/
	cout << "Introduce el primer numero: ";
/*cout nos indica que vamos a mostrar en pantalla lo indicado por los menores "<<", lo que esta entre comillas en el codigo sera el mensaje mostrado*/
	cin >> a; 
/*el cin es como meter algo a la memoria por el teclado, y guardarlo en una variable (a)*/
	cout << "Introduce el segundo numero: ";
	cin >> b;
/*las dos anteriores hacen lo mismo que con el primer digito (a), pero con el segundo digito (b)*/
	res = a + b;
/*Aqui le indicamos a la unidad de control que tome el valor numerico que ocupa la posicion de memoria "a" de la memoria principal, lo traiga a la ALU y esta opere, la operacion se le indicara, en nuestro caso en nuestro lenguaje de alto nivel lo indicamos como "+", lo mismo que paso para traer a "a" lo hara con "b". Y tambien le indicamos que tras operar guarde el resultado en un espacio de la memoria principal (variable), el cual es "res"*/
	cout << "El resultado es: "<< res << endl;
/*Traemos a la pantalla el texto entre comillas, ademas de lo que ocupa la variable "res" y por ultimo un salto de linea*/
}
/*nos indica que nuestro programa ha finalizado con exito y tras esto limpia todos los bits empleados*/
