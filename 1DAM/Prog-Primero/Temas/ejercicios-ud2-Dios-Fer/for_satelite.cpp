#include <iostream>
using namespace std;
int main (){
	int dato=0;
	
	//Empezamos con un dato valido (0), si el dato es menor a 0 cortamos, procedemos con el interior, y tocamos el for en el cuerpo, el programa no cambia el for y comprueva ahora con el nuevo valor de este
	for(dato=0; dato>=0; dato){//he visto que esto funciona --->     ;dato>=0;      ahora, no se que tan correcto este

		cout << "Dato: ";
		
		cin >>dato;
		
		//No tengo claro si el negativo entra en recibido, en caso de que no halla que poner recibido con el dato negativo es cuestion de poner un if(dato >= 0) aqui y ya
		cout << "Recibido: " << dato << endl;
		
	}
	
	cout << "Fin de transmision" << endl;
	
}
