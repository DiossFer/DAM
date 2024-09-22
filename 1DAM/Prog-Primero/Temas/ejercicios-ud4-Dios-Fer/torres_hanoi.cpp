#include <iostream>
using namespace std;




/**
 * @brief Módulo para en funcion de un numero de piezas realizar los movimientos de manera recursiva de la resolucion de las torres de hanoi (4piezas 3torres) (4-0-0 --> 0-0-4)
 * @param int m piezas en el modulo actual 
 * @param int i espacio de torre donde se encuentra la ficha a mover (torre inicial)
 * @param int j espacio de torre donde se mueve la ficha (torre final)
 * @post el programa mostrara tras la ejecucion de todas sus pilas el procedimiento para realizar los movimientos de las torres de hanoi
 * @version 1.0
 * @author Dios-Fer
 * @date 2023-08-04
 */
void hanoi (int m, int i, int j){

	if (m>0){
	
		//La base del programa esta en hacer movimientos posibles e ir cerrando posibilidades conforme nos acercamos a 0 piezas
	
		//pasara o otro hanoi con un cambio de torre donde mantenemos la acual de i para mover esa ficha y cambiamos j para una nueva ubicacion
		hanoi (m-1, i, 6-i-j);
		
		//Cout del movimiento cuando se halla verificado toda la rama anterior (primera llamada (que conlleva todas las pilas hasta el caso base m=0))
		cout << "Ficha de "<<i<<" a "<<j<<endl;
		
		//Pasamos a la segunda (que conlleva todas las pilas hasta el caso base m=0) llamada para los movimientos restantes que al igual que la primera debera de ir cerrando posibilidades 
		hanoi (m-1, 6-i-j, j);
		
	}
	
}

int main () {
	
	hanoi (4, 1, 3); // ||| caso 4fichas ||| torre inicial=1 ||| torre final=3
	
}
