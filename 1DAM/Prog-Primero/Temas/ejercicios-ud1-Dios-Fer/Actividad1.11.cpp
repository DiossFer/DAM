#include <iostream>
using namespace std;

int main(){
	
	float nota_teoria, nota_practicas, nota_problemas, nota_final;
	//Tras declarar una variable para cada nota, vamos a pedir tal como nos especifica (una linea) las notas.
	cout << "Introduce en una linea separado por espacios tues notas de teoria, practicas y problemas en ese orden: ";
	cin >> nota_teoria >> nota_practicas >> nota_problemas;
	//Hacemos la cuenta para calcular la nota final
	nota_final = nota_teoria * 0.7 + nota_practicas * 0.2 + nota_problemas * 0.1;
	//Sacamos el resultado, en estte caso la nota de programacion
	cout << "Tu calificacion en la asignatura de Programacion es: " << nota_final << endl;

}
