#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//Posiciones de las dos circunferencias
	double posicion_blanco_x = 0.0, posicion_blanco_y = 0.0, posicion_disparo_x = 0.0, posicion_disparo_y = 0.0;
	//Radio de cada circunferencia
	double radio_blanco = 0.0, radio_disparo = 0.0; 
	//Distancia entre circunferencias
	double distancia_centros = 0.0;
	
	//Pedimos los datos
	cout << "Introduzca la posicion (x y) de su primer circulo, en este caso el blanco al que dispararemos: ";
	cin >> posicion_blanco_x >> posicion_blanco_y;
	cout << "Ahora el radio de este: ";
	cin >> radio_blanco;
	
	cout << "Lo mismo (x y) pero con el segundo circulo, nuestro disparo: ";
	cin >> posicion_disparo_x >> posicion_disparo_y;
	cout << "Por ultimo el radio de nuestro disparo: ";
	cin >> radio_disparo;
	
	//Para solucionar problemas con radios negativos
	radio_disparo = abs (radio_disparo);
	radio_blanco = abs (radio_blanco);
	
	//Calculamos distancia  
	distancia_centros = (sqrt(pow((posicion_blanco_x - posicion_disparo_x),2.0) + pow((posicion_blanco_y - posicion_disparo_y),2.0)));
	
	
	//Damos los resultados
	
	//Mismo centro
	if (distancia_centros == 0){
		if (radio_blanco == radio_disparo){
			cout << "Le has dado de lleno" << endl;
		}
		else {
			cout << "¡En todo el centro!" << endl;
		}
	}
	
	//Secante
	else if (((distancia_centros > (radio_blanco - radio_disparo))||(distancia_centros == (radio_disparo - radio_blanco)))&&(distancia_centros < (radio_blanco + radio_disparo))){
	
		cout << "Le has dado "<<endl;
	}
	


	//Tangentes
	else if (distancia_centros == (radio_blanco + radio_disparo)){
		cout << "Le has rozado, estuviste cerca" << endl;
	}
	
	else if ((distancia_centros == (radio_blanco - radio_disparo))||(distancia_centros == (radio_disparo - radio_blanco))){
		cout << "Justo pero le has dado entero, buen disparo" << endl;
	}
	

	///No coincide
	else if (distancia_centros > (radio_blanco + radio_disparo)){
		cout << "No le diste" << endl;
	}

	else if ((distancia_centros <= radio_blanco)||(distancia_centros <= radio_disparo)){
		cout << "Le has dado entero" << endl;
	}

	
	/*
	Traduccion de salidas (enfocadas a cod)
	-Misma circunferencia = Le has dado de lleno
	-En el centro pero otra circunferencia = ¡En todo el centro!
	-Tangente interior = Justo pero le has dado entero, buen disparo
	-Tangente exterior = Le has rozado, estuviste cerca
	-Secante = Le has dado 
	-No coincide exterior = No le diste
	-No coincide interior = Le has dado entero
	*/
	

}


