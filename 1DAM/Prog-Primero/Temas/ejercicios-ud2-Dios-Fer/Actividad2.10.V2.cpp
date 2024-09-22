#include <iostream>
#include <cmath>//spoiler me he liado mucho y complicado la vida a un nivel exagerado
using namespace std;//para quitarme de lios podria hacerlo apartado a apartado
int main (){
	//Declaraciones de variables
	bool apartado1, apartado2, apartado3, apartado4, apartado5, apartado6, apartado7;//(puedo reutilizar tras mostrar)
	double A=0.0;
	int AE=0;
	
	//Introducir el numero
	cout << "Introduce el valor que quieres comparar con la rubrica de los distintos apartados de la actividad2.10: ";
	cin >> A;
	
	//El Apartado 5 es algo chapucero, tras mi intento de intentar jugar entre enteros y reales y ver que no lo conseguia, procedi a poner todo real para que no halla fallos de que se permite hasta 10 y el programa permite1.1 o que solo admite dos y da 2.5 como valido. Para solucionarlo y que no diera error con el modulo use la galeria cmath y trunc(), para truncar ese valor y que todo a exceppccion de determinados casos en el apartado 5 funcione bien.
	AE=(trunc(A));
	//Ahi esta el truncado para el apartado 5
	
	//Operaciones logicas
	apartado1 = A==1.0 || A==2.0 || A==3.0 || A==4.0 || A==5.0 || A==6.0;//(mejor mas parentesis separando todo)-(((a>=1) && (a<=6))) (con int) (<--esto con solo enteros funciona)
	apartado2 = A<=-5.0 || A>=5.0;
	apartado3 = A<-5.0 || A>3.0;
	apartado4 = (A==1.0 || A==2.0 || A==3.0) || (A>=10.0 && A<20.0);
	apartado5 = (AE%2) == 0 || ((AE%2) != 0 && (A>0 && A<10));//me ha faltado un parentesis y pueden llegar a sobrar cosas como el impar pues si no es par con estar entre 0 y 10 ya sabemos que es impar
	apartado6 = (A>=0.0 && A<=10.0) || (A >=20.0 && A<=30.0);
	apartado7 = A<0.0 || (A>=10.0 && A<=20.0) || A>30.0;
	
	//Salidas
	cout << "Siendo 1 true y 2 false vemas cada caso: " << endl;
	
	cout << "en el primer caso es: " << apartado1 << endl;
	cout << "en el segundo caso es: " << apartado2 << endl;
	cout << "en el tercer caso es: " << apartado3 << endl;
	cout << "en el cuarto caso es: " << apartado4 << endl;
	cout << "en el quinto caso es: " << apartado5 << endl;
	cout << "en el sexto caso es: " << apartado6 << endl;
	cout << "en el setimo caso es: " << apartado7 << endl;

}
