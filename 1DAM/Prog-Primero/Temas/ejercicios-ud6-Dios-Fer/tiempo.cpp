#include <iostream>
#include <iomanip>
#include <cmath>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
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


struct tiempo{

	int hora;
	bool am;
	int minuto;
	int segundo;

};


int main (){

	//Declaracion
	tiempo ahora;


	//Entrada
	do{
		cout << "Introduce la hora (0-23): ";
		cin >> ahora.hora;
	}while(ahora.hora>23 || ahora.hora<0);


	//Calculo
	ahora.am=(ahora.hora<12);

	if (!ahora.am){
		ahora.hora-=12;
	}


	//Entrada
	do{

		cout << "Introduzca minutos (0-59): ";
		cin >> ahora.minuto;

	}while(ahora.minuto>59 || ahora.minuto<0);

	do{
		cout << "Introduzca segundos (0-59): ";
		cin >> ahora.segundo;
	}while(ahora.segundo>59 || ahora.segundo<0);



	//Salida
	cout <<endl<< "Son las: " << ahora.hora << ":" << ahora.minuto << " y " << ahora.segundo << " segundos ";
	if (ahora.am){
		cout << "am" << endl;
	}
	else {
		cout << "pm" << endl;
	}
}