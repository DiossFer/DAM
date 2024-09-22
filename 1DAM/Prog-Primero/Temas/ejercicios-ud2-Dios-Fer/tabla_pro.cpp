#include <iostream>
using namespace std;
int main(){


	//Variables para tablas unicas
	int numero_fila = 1, numero = 1, numero_fila_final = 10, resultado = 0;
	
	//Variables para cambio de tabla
	int numero_tabla = 1, numero_tabla_final=10;
	
	//Un for para que haga una tabla 10 veces
	for (numero_tabla; numero_tabla <= numero_tabla_final; numero_tabla = numero_tabla +1){
		for (numero_fila=1; numero_fila <= numero_fila_final; numero_fila = numero_fila + 1){//tabla xº
			resultado = (numero * numero_fila);
			cout << numero << "x" << numero_fila << "=" << resultado << endl;
		}
		numero = numero + 1;	//tabla siguiente	//No se si puedo meter esto tambien arriba
		cout << "---------------" << endl;
	}
		
	
	
}
