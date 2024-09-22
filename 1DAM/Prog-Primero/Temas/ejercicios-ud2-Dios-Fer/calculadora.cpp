#include <iostream>
using namespace std;
int main (){
	
	double numero1=0.0, numero2=0.0, resultado=0.0;
	char operacion, eleccion;
	
	do {//Bucle de calculadora
	//Pedimos los numeros
	cout << "Introduzca el primer numero: ";
	cin >> numero1;
	cout << "Introduzca el segundo numero: ";
	cin >> numero2;
	
		do {//Bucle de operacion
		
			do{//Filotro de operacion
				cout << "Introduzca la operacion que quiere realizar (Suma (+), resta (-), multiplicacion (*) o division (/)): ";
				cin >> operacion;
				
					//Elejir operacion
					switch (operacion){
					
						case '+' :
							resultado = numero1 + numero2;
							break;
						
						case '-' :
							resultado = numero1 - numero2;
							break;
						
						case '/' :
							if (numero2==0){
							cout << "La operacion que intentas realizar no tiene solucion, el resultado saldra erroneo" << endl;
							}
							else {
							resultado = numero1 / numero2;
							}
							break;
						
						case '*' :
							resultado = numero1 * numero2;
							break;
						
						default://Operacion erronea
							cout << "Has puesto un simbolo no valido" << endl;
					}
					
			} while ((operacion != '+') && (operacion != '-') && (operacion != '*') && (operacion != '/'));//Filotro de operacion
					//Una vez filtrado si se ha hecho bien la operacion sacamos el resultado
					cout << "Tu resultado es: " << resultado << endl;
			do {//Filtro eleccion	
			
				//Elejimos si queremos cambiar numeros, si queremos cambiar de operacion o si queremos cerrar el programa
				cout << "Pulsa \"R\" para repetir con otros numeros, pula \"O\" para repetir con otra operacion o pulsa \"C\" para cerrar el programa: ";	
				cin >> eleccion;
				
				//Eleccion erronea
				if (eleccion != 'R' && eleccion != 'O' && eleccion != 'C'){
					cout << "Tu orden no es valida revise si ha escrito un caracter permitido" << endl;
				}
				
			} while (eleccion != 'R' && eleccion != 'O' && eleccion != 'C');//Filtro eleccion
		
		} while (eleccion =='O');//Bucle de operacion
		
	} while (eleccion == 'R');//Bucle de calculadora
	
	
}
