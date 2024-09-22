#include <iostream>
using namespace std;//para quitarme de lios podria hacerlo apartado a apartado
int main (){

	//Declaraciones de variables
	bool resultado;
	double numero_real=0.0;
	int numero_entero=0, numero_apartado=1;
	
	//Introduccion
	cout << "===================================================================================================" << endl;
	cout << "Programa 2.10, comprovacion de numeros en distintas rubricas" << endl;
	cout << "===================================================================================================" << endl;
	
	//Apartado 1 (entrada, operacion y posibles salidas)
	//De cierta manera nos permite poner decimales, si ponemos 2.5, no nos dara ningun error, pero tomara el dos lo compovara y pasara el 5 a la siguiente rubrica, esto lo vemos tambien en el 5, pero pasa en cualquiera si ponemos dos numero por ejemplo si ponemos "3 8", no colocara el tres en ese y comprovara el 8 en el siguiente
	cout << "Introduce el valor entero que quieres comparar teniendo en cuenta la rubrica del apartado " << numero_apartado <<": ";
	cin >> numero_entero;
	resultado = ((numero_entero==1) || (numero_entero==2) || (numero_entero==3) || (numero_entero==4) || (numero_entero==5) || (numero_entero==6));// al ser solo enteros tambien se podria con: "((a>=1) && (a<=6))"
	if (resultado==true){
		cout << "Tu numero si entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
	else {
		cout << "Tu numero no entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
		
	numero_apartado = numero_apartado + 1;
	cout << "===================================================================================================" << endl;
	
	//Apartado 2 (entrada, operacion y posibles salidas)
	cout << "Introduce el valor real que quieres comparar teniendo en cuenta la rubrica del apartado " << numero_apartado <<": ";
	cin >> numero_real;
	resultado = ((numero_real<=-5.0) || (numero_real>=5.0));
	if (resultado==true){
		cout << "Tu numero si entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
	else {
		cout << "Tu numero no entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
		
	numero_apartado = numero_apartado + 1;
	cout << "===================================================================================================" << endl;
	
	//Apartado 3 (entrada, operacion y posibles salidas)
	cout << "Introduce el valor real que quieres comparar teniendo en cuenta la rubrica del apartado " << numero_apartado <<": ";
	cin >> numero_real;
	resultado = ((numero_real<-5.0) || (numero_real>3.0));
	if (resultado==true){
		cout << "Tu numero si entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
	else {
		cout << "Tu numero no entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
		
	numero_apartado = numero_apartado + 1;
	cout << "===================================================================================================" << endl;
	
	//Apartado 4 (entrada, operacion y posibles salidas)
	cout << "Introduce el valor real que quieres comparar teniendo en cuenta la rubrica del apartado " << numero_apartado <<": ";
	cin >> numero_real;
	resultado = (((numero_real==1.0) || (numero_real==2.0) || (numero_real==3.0)) || (numero_real>=10.0 && numero_real<20.0));
	if (resultado==true){
		cout << "Tu numero si entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
	else {
		cout << "Tu numero no entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
		
	numero_apartado = numero_apartado + 1;
	cout << "===================================================================================================" << endl;
	
	//Apartado 5 (entrada, operacion y posibles salidas)
	//no hace falta comprovar si es inpar, pues entre 0 y 10 va ha haber solo pares e impares
	cout << "Introduce el valor entero que quieres comparar teniendo en cuenta la rubrica del apartado " << numero_apartado <<": ";
	cin >> numero_entero;
	resultado = (((numero_entero%2) == 0) || (numero_entero>0 && numero_entero<10));
	if (resultado==true){
		cout << "Tu numero si entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
	else {
		cout << "Tu numero no entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
		
	numero_apartado = numero_apartado + 1;
	cout << "===================================================================================================" << endl;
	
	//Apartado 6 (entrada, operacion y posibles salidas)
	cout << "Introduce el valor real que quieres comparar teniendo en cuenta la rubrica del apartado " << numero_apartado <<": ";
	cin >> numero_real;
	resultado = (((numero_real>=0.0) && (numero_real<=10.0)) || ((numero_real >=20.0) && (numero_real<=30.0)));
	if (resultado==true){
		cout << "Tu numero si entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
	else {
		cout << "Tu numero no entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
		
	numero_apartado = numero_apartado + 1;
	cout << "===================================================================================================" << endl;
	
	//Apartado 7 (entrada, operacion y posibles salidas)
	cout << "Introduce el valor real que quieres comparar teniendo en cuenta la rubrica del apartado " << numero_apartado <<": ";
	cin >> numero_real;
	resultado = ((numero_real<0.0) || (numero_real>=10.0 && numero_real<=20.0) || (numero_real>30.0));
	if (resultado==true){
		cout << "Tu numero si entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
	else {
		cout << "Tu numero no entra en la rubrica del apartdo "<< numero_apartado << endl;
		}
		
	numero_apartado = numero_apartado + 1;
	cout << "===================================================================================================" << endl;
}
