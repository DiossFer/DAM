#include <iostream>
using namespace std;
int main (){

	//Como Jaime dijo que seria una version muy inicial no me he complicado con cosas como el grosor de los palos
	//A tener en cuenta: larguero, escuadra, palo, gol, porteria correcta, tiro hacia abajo

	//Vorde de la porteria (porteria de 2.5*7)
	double esquina_AbI_x=0.0, esquina_AbI_y=0.0, esquina_ArD_x=7.0, esquina_ArD_y=2.5;
	
	
	
	//double tiro_escuadra_Ix=0.40, tiro_escuadra_Iy=2.10, tiro_escuadra_Dx=6.60, tiro_escuadra_Dy=2.10;
	
	
	
	//Tiro
	double tiro_x = 0.0, tiro_y = 0.0;
	

	
	
	//añadido de la colocacion de la porteria
	
	do{//Primer cuadrante
	do{//Rectangular
	do{//Que cumpla con las medidas (7 x 2.5)
	cout << "Introduzca las coordenadas de la esquina inferior izquierda de la porteria: ";
	cin >> esquina_AbI_x >> esquina_AbI_y;
	
	cout << "Introduzca las coordenadas de la esquina superior derecha de la porteria: ";
	cin >> esquina_ArD_x >> esquina_ArD_y;
	
	if (!(esquina_AbI_x >= 0 && esquina_AbI_y >= 0 && esquina_ArD_x >= 0 && esquina_ArD_y >= 0)){//Primer cuadrante
		cout << "Tu porteria no esta en el primer cuadrante" << endl;
	}
	
	if (esquina_AbI_x==esquina_ArD_x && esquina_AbI_y==esquina_ArD_y){//Rectangular
		cout << "Tu porteria no es rectangular" << endl;
	}
	if (!((esquina_ArD_x-esquina_AbI_x==7 || esquina_ArD_x-esquina_AbI_x==-7)&&(esquina_ArD_y-esquina_AbI_y==2.5 || esquina_ArD_x-esquina_AbI_x==-2.5))){//Que cumpla con las medidas (7 x 2.5)
		cout << "Tus medidas de porteria son erroneas" << endl;
	}
	}while (!((esquina_ArD_x-esquina_AbI_x==7 || esquina_ArD_x-esquina_AbI_x==-7)&&(esquina_ArD_y-esquina_AbI_y==2.5 || esquina_ArD_x-esquina_AbI_x==-2.5)));//Que cumpla con las medidas (7 x 2.5)
	}while (esquina_AbI_x==esquina_ArD_x && esquina_AbI_y==esquina_ArD_y);//Rectangular	//Al dar solo dos esquinas el no ser rectangular solo dependera de si es una linea o un punto
	}while (!(esquina_AbI_x >= 0 && esquina_AbI_y >= 0 && esquina_ArD_x >= 0 && esquina_ArD_y >= 0));//Primer cuadrante
	
	double tiro_escuadra_Ix=esquina_AbI_x+0.40, tiro_escuadra_Iy=esquina_AbI_y+2.10, tiro_escuadra_Dx=esquina_AbI_x+6.60, tiro_escuadra_Dy=esquina_AbI_y+2.10;
	
	
	
	
	
	
	
	
	//Introduccion
	cout << "Tenemos una porteria en el primer cuadrante (x:0->infinito, y:0->infinito) esta porteria mide de 0 a 7 x y de 0 a 2.5 y." << endl;
	cout << "Introduzca dos valores que seran su tiro hacia una porteria, siendo el primero la coordenada x y el segundo la y: ";
	cin >> tiro_x >> tiro_y;
	
	//Dentro de porteria
	if (((tiro_x > esquina_AbI_x) && (tiro_x < esquina_ArD_x)) && ((tiro_y >= esquina_AbI_y) && (tiro_y < esquina_ArD_y))){
		//Escuadra
		if (((tiro_x <= tiro_escuadra_Ix)||(tiro_x >= tiro_escuadra_Dx))&&(tiro_y >= tiro_escuadra_Iy)||(tiro_y >= tiro_escuadra_Dy)){
			cout << "¡Gol por la escuadra!" << endl;
		}
		//Rasa
		else if (((tiro_x > esquina_AbI_x) && (tiro_x < esquina_ArD_x)) && (tiro_y == esquina_AbI_y)){
			cout << "Ha entrado rasa" << endl;
		}
		//Gol normal
		else {
			cout << "¡Gol!" << endl;
		}
	}
	//Larguero
	else if (((tiro_x > esquina_AbI_x) && (tiro_x < esquina_ArD_x)) && (tiro_y == esquina_ArD_y)){
		cout << "Larguero" << endl;
	}
	
	//Palos
	else if (((tiro_y >= esquina_AbI_y) && (tiro_y < esquina_ArD_y))&&(tiro_x == esquina_ArD_x)){
		cout << "Palo derecho" << endl;
	}
		
	else if (((tiro_y >= esquina_AbI_y) && (tiro_y < esquina_ArD_y))&&(tiro_x == esquina_AbI_x)){
		cout << "Palo izquierdo" << endl;
	}
	//Esquinas
	else if ((tiro_x == esquina_AbI_x)&&(tiro_y == esquina_ArD_y)){
		cout << "Esquina Izquierda" << endl;
	}
	
	
	
	else if ((tiro_x == esquina_ArD_x)&&(tiro_y == esquina_ArD_y)){
		cout << "Esquina Derecha" << endl;
	}
	
	
	//Tiro hacia abajo
	else if (((tiro_x > esquina_AbI_x) && (tiro_x < esquina_ArD_x))&&(tiro_y < esquina_AbI_y)){
		cout << "Tiro hacia abajo" << endl;
	}
	
	//Fuera
	else {
		cout << "Fuera" << endl;
	}
	
	
}
