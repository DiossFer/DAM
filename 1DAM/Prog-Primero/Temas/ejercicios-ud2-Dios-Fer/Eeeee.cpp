#include <iostream>
#include <iomanip>
using namespace std;
int main (){

	int numero_final = 0;
	long double sumatoria = 0.0, resultado_factorial=0.0;
	int k=0;
	char repetir='n';

	
	do{//repeticion del programa  guardando valores
		do{//filtro de segundnumero mayor a primero (en caso de repetirse)
			do{//filtro
				//Tomamos datos
				cout << "Ingrese que tantos avances hacia el numero e quieres: ";
				cin >> numero_final;
			}while(numero_final <= 0);
		}while(numero_final <= k && repetir=='s');
		//Factorial

		for (k; k <= numero_final; k++){
			//Factorial
			if (k==0){
				resultado_factorial=1.0;
			}
			
			
			else {
				
				for (int i=k; i!=k+1; ++i){
					resultado_factorial = i*resultado_factorial;
					
				}
			}
			
			//Sumatoria
			sumatoria = sumatoria + (1.0/resultado_factorial);
		
		}


		//Mostramos sumatoria final<--->e
		cout << setprecision (100) << sumatoria << endl;
		
		do{
			
			cout << "Quieres avanzar aun mas, presione s (Si) o n (No) dependiendo de su respuesta y tras esto introduzca su nuevo limite: ";
			cin >> repetir;
			
		}while(repetir!='n' && repetir!='s');
		
		k-=1;
		
	}while (repetir=='s');//gracias a no inixcializar en el bucle mantenemos los valores y en caso de repetir no empezamos de 0
	
	
}

