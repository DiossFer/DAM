#include <iostream>
using namespace std;
int main(){
	//Declaramos los segundos, minutos, horas y dias
	int numero_segundos = 0, numero_minutos = 0, numero_horas = 0, numero_dias = 0;
	
	cout << "_____________________________________________________" << endl;
	//Pedimos los segundos
	cout << "Introduce el nuumero de segundos que quieres ordenar: ";
	cin >> numero_segundos;
	cout << "Esos segundos equivalen a: " << endl;

	//Calculamos minutos y calculamos lo sobrante de los segundos (asi con cada unidad de tiempo)
	numero_minutos = numero_segundos / 60;
	numero_segundos = numero_segundos % 60;
	
	numero_horas = numero_minutos / 60;
	numero_minutos = numero_minutos % 60;
	
	numero_dias = numero_horas / 24;
	numero_horas = numero_horas % 24;
	
	//Damos el resultado de manera ordenada
	cout << "______________" << endl;
	cout << "Dias: " << numero_dias << endl;
	cout << "Horas: " << numero_horas << endl;
	cout << "Minutos: " << numero_minutos << endl;
	cout << "Segundos: " << numero_segundos << endl;
	cout << "______________" << endl;
}
