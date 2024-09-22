#include <iostream>
#include <string>

//colores
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

int main (){


int lineas=0;
cout << BOLDCYAN<<endl;
cin >> lineas;
cout << RESET<<endl;
cout <<BOLDYELLOW<< "======================="<<RESET<<endl;
for (int linea_actual=1; linea_actual<=lineas; linea_actual++){

	int numero_casillas=0;		//(n)
	int multiplicador_de_salto=0;	//(f)
	int tiempo_pulsado=0;		//(t)

	int nivel_pulsacion=0;		//Digamos que es el numero de casillas totales (multiplicador_de_salto * tiempo_pulsado)

	int barras_completadas=0;	//todas las barras que has llenado hasta la actual

	int salto=0;	//solucion



	do{//Filtro de entradas
		//Entrada de datos (n f t)
		cout << BOLDBLUE;
		cin >> numero_casillas;
		cin >> multiplicador_de_salto;
		cin >> tiempo_pulsado;
		cout << RESET;
		//Mensajes de error
		if (numero_casillas<1 || numero_casillas>100){
			cout <<BOLDRED<< "Nº de casillas mal introducidao, repita la linea"<<RESET<<endl;
		}
		if (multiplicador_de_salto<1 || multiplicador_de_salto>100){
			cout <<BOLDRED<< "Multipliccador de salto mal introducido, repita la linea"<<RESET<<endl;
		}
		if (tiempo_pulsado<1 || tiempo_pulsado > 100000){
			cout <<BOLDRED<< "Tiempo pulsado mal introducido, repita la linea" <<RESET<<endl;
		}
		
	}while((numero_casillas<1 || numero_casillas>100) || (multiplicador_de_salto<1 || multiplicador_de_salto>100) || (tiempo_pulsado<1 || tiempo_pulsado > 100000));



	nivel_pulsacion = multiplicador_de_salto * tiempo_pulsado;	//numero de casillas entre todas las barras


	numero_casillas++;	//contare el paso de la ultima al 0 como una casilla


	barras_completadas = nivel_pulsacion / numero_casillas; 	//veamos que tantas barras llena (al ser division no decimal nos darra solo las llenadas enteras)


	salto = (nivel_pulsacion - (barras_completadas * numero_casillas));	//nuestra solucion sera igual a nuestro salto total (todos los saltos de todas las barras) menos la multiplicacion de las barras completas llenadas y el numero de casillas por barra 		//con esta resta obtienes tus saltos de tu ultima barra (nuestra solucion)

	
	cout << BOLDCYAN << salto<<endl<<endl<<RESET;//Salida por entrada
	cout <<BOLDYELLOW<< "======================="<<RESET<<endl;
	
}
}
