#include <iostream>
using namespace std;
int main (){

	int dato = 0, contador = 0;
	
	double media = 0.0, dato_total = 0.0;



	//Pedimos el primer dato

	cout << "Introduzca los datos, el programa finalizara al introducir un numero menor a 0" << endl;

	cin >> dato;
	
	cout << "Recibido: " << dato << endl;
	
	
	
	//Si el primero es negativo, cotador sera 0 y no podemos dividir entre 0 
	if (dato < 0){
		contador = contador + 1;
		cout << "Ignore la media pues no se ha procesado ningun dato" << endl;
	}
	
	
	
	while (dato>=0){
	
		//calculamos el total de datos
		
		dato_total = dato_total + dato;
		
		//Pedir los datos
		cout << "Procesando: " << dato << endl;
		cin >> dato;
		cout << "Recibido: " << dato << endl;
		
		//Contador para ver los numeros utilizados y con ello poder hacer la media
		contador = contador + 1;
		
		
	}
	
	cout << "Fin de la transmision" << endl;
	
	media = dato_total / contador;
	
	cout << "La media de los numeros validos introducidos es: " << media << endl;


}
