#include <iostream>
using namespace std;
int main (){

	int posicion_inicial_x=0, posicion_inicial_y=0;
	bool validez;
	int pieza;
	int posicion_final_x=0, posicion_final_y=0;
	int diferencia_posicion_x=0, diferencia_posicion_y=0;
	
	//Explicacion
	cout << "Tomemos un ajedrez y veamos los movimientos validos con el caballo, la torre o la reina." << endl;
	cout << "Aqui tenemos nuestro tablero: " << endl << endl;
	
	//Tablero
	cout << "8 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "7 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "6 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "5 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "4 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "3 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "2 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "1 🔲🔲🔲🔲🔲🔲🔲🔲" << endl;
	cout << "  1 2 3 4 5 6 7 8" << endl << endl;
	
	//Aclaracion e introduccion de la posicion inicial
	cout << "Recueerde que primero de izquierda a derecha y despues de abajo a arriba" << endl;
	cout << "Ahora si, introduzca su posicion inicial: ";
	
	cin >> posicion_inicial_x >> posicion_inicial_y;
	
	
	
	//Validez (dentro del tablero) de la posicion inicial
	validez = ((posicion_inicial_x >= 1)&&(posicion_inicial_x <= 8))&&((posicion_inicial_y >= 1)&&(posicion_inicial_y <= 8));
	
	//Posicion inicial no valida
	if (validez == false){
		cout << "Tu posicion inicial es erronea, esta fuera del tabloero" << endl;
	}
	//Posicion inicial valida
	else{
		//Pedimos la pieza
		cout << "Diga con que ficha realizara el movimiento, recuerde que solo sera valido el caballo (introduzca 1), la torre (introduzca 2) y la reina (introduzca 3): ";
		cin >> pieza;
		
		//Validez de la pieza 
		if ((pieza == 1) || (pieza == 2) || (pieza == 3)){
			
			
			//Pedimos la posicion final
			cout << "Introduzca a donde quiere mover su ficha: ";
			cin >> posicion_final_x >> posicion_final_y;

			//Validez de la posicion final
			validez = ((posicion_final_x >= 1)&&(posicion_final_x <= 8))&&((posicion_final_y >= 1)&&(posicion_final_y <= 8));
			//Posicion final no valida
			if (validez == false){
				cout << "Tu posicion final es erronea, esta fuera del tablero" << endl;
			}
			else if ((posicion_inicial_x == posicion_final_x)&&(posicion_inicial_y == posicion_final_y)){
				cout << "No puedes moverte al mismo sitio." << endl;
			}
			//Posicion final valida
			else {
			diferencia_posicion_x = (posicion_final_x - posicion_inicial_x);
			diferencia_posicion_y = (posicion_final_y - posicion_inicial_y);
				//Caballo
				if (pieza == 1){
					validez = (
							((diferencia_posicion_x == 2)&&(diferencia_posicion_y == 1))||
							((diferencia_posicion_x == 1)&&(diferencia_posicion_y == 2))||
							((diferencia_posicion_x == -2)&&(diferencia_posicion_y == -1))||
							((diferencia_posicion_x == -1)&&(diferencia_posicion_y == -2))||
							((diferencia_posicion_x == 2)&&(diferencia_posicion_y == -1))||
							((diferencia_posicion_x == -1)&&(diferencia_posicion_y == 2))||
							((diferencia_posicion_x == -2)&&(diferencia_posicion_y == 1))||
							((diferencia_posicion_x == 1)&&(diferencia_posicion_y == -2))
							);
					if (validez == false){
						cout << "El movimiento que intentas hacer no es valido." << endl;
					}
					else {
						cout << "El movimiento que intentas hacer es valido." << endl;
					}
					
				}
				//Torre
				else if (pieza == 2){
					if (posicion_inicial_x == posicion_final_x){
						if (posicion_inicial_y == posicion_final_y){
							cout << "El movimiento que intentas hacer no es valido." << endl;
						}
						else{
							cout << "El movimiento que intentas hacer es valido." << endl;
						}
					}
					else if (posicion_inicial_y == posicion_final_y){
						if (posicion_inicial_x == posicion_final_x){
							cout << "El movimiento que intentas hacer no es valido." << endl;
						}
						else{
							cout << "El movimiento que intentas hacer es valido." << endl;
						}
					} 
					else {
						cout << "El movimiento que intentas hacer no es valido." << endl;
					}
					
					
					}
					
				//Reina
				else if (pieza == 3){
					if (posicion_inicial_x == posicion_final_x){
							if (posicion_inicial_y == posicion_final_y){
								cout << "El movimiento que intentas hacer no es valido." << endl;
							}
							else{
								cout << "El movimiento que intentas hacer es valido." << endl;
							}
						}
					else if (posicion_inicial_y == posicion_final_y){
						if (posicion_inicial_x == posicion_final_x){
							cout << "El movimiento que intentas hacer no es valido." << endl;
						}
						else{
							cout << "El movimiento que intentas hacer es valido." << endl;
						}
					} 
					else if (abs(diferencia_posicion_x) == abs(diferencia_posicion_y)){
						cout << "El movimiento que intentas hacer es valido." << endl;
					}
					
					
					else {
						cout << "El movimiento que intentas hacer no es valido." << endl;
					}
				}
			}		
		}
		//Pieza no valida	
		else{
			cout << "La pieza no es valida" << endl;
		}		
		}	
}
