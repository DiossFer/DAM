#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int numero_final = 0;
	long double sumatoria = 0.0, pi = 0.0;
	int n=0;
	char repetir='n';
	
	
	do{//repeticion del programa  guardando valores
	do{//filtro de segundnumero mayor a primero (en caso de repetirse)
	do{//filtro
		//Tomamos datos
		cout << "Ingrese que tantos avances hacia pi quieres: ";
		cin >> numero_final;
	}while(numero_final <= 0);
	}while(numero_final <= n && repetir=='s');
	

	//Sumatoria
	for (n; n <= numero_final; n++){
		sumatoria = sumatoria + (pow (-1,n) / pow(((2*n)+1),3));
	
	}
	
	//Pi
	pi = cbrt(32*sumatoria);

	//Mostramos
	cout << setprecision (100) << pi << endl;
	
	do{
	cout << "Quieres avanzar aun mas, presione s (Si) o n (No) dependiendo de su respuesta y tras esto introduzca su nuevo limite: ";
	cin >> repetir;
	
	}while(repetir!='n' && repetir!='s');
	n-=1;
	}while (repetir=='s');//gracias a no inixcializar en el bucle mantenemos los valores y en caso de repetir no empezamos de 0
	
}

