#include <iostream>
using namespace std;

//Color azul para las salidas y magenta para las entradas
#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */

int main (){//V2


	//Para cumplir con primero las entradas y luego las salidas he guardado resultados por linea para mostrarlos al final (esto implica que debo poner un tope (en mi caso de 10 lineas de toros))
	//Para cortar en la linea que quieras sin tener por que llegar al tope debes poner el numero de toros como 0


	//variables (1 variable por linea)
	int numero_toros=0, v_toro=0, v_max1=0, v_max2=0, v_max3=0, v_max4=0, v_max5=0, v_max6=0, v_max7=0, v_max8=0, v_max9=0, v_max10=0, v_max=0;


	for (int j=1; j<=10; j++){
		cout << MAGENTA;
		//mumero de toros

		cin >> numero_toros;
		//velocidades para cada toro hasta que no queden toros por asignar
		
		if (numero_toros!=0){
		
		
			for (int i=1; i<=numero_toros; ++i){

				do {//Filtro >0 <40 (era 10⁹ pero por realismo y comodidad he usado 40 (la velocidad maxima de un toro en la vida real))

					cin >> v_toro;
					
				if (!((v_toro > 0) && (v_toro<=40))){
					cout <<"Has introduciodo la velocidad " << v_toro << " mal, vuelbe a introducir unicamente esa"<<endl;
				}
				
				}while((v_toro < 0) || (v_toro>=40));
				
				
				
				
				
				if (v_toro>v_max){
				//la velocidad del toro mas rapido
				v_max=v_toro;
				}
					
			}
			
			//Guardamos resultado de cada linea en una variable
			if (j==1){
				v_max1=v_max;
			}
			else if (j==2){
				v_max2=v_max;
			}
			else if (j==3){
				v_max3=v_max;
			}
			else if (j==4){
				v_max4=v_max;
			}
			else if (j==5){
				v_max5=v_max;
			}
			else if (j==6){
				v_max6=v_max;
			}
			else if (j==7){
				v_max7=v_max;
			}
			else if (j==8){
				v_max8=v_max;
			}
			else if (j==9){
				v_max9=v_max;
			}
			else if (j==10){
				v_max10=v_max;
			}
			
			v_max=0;
		}
		else if (numero_toros==0){
			j=11;
		}
		
	}//Una salida por linea, esto para que al cortar antes de los 10 no saque ceros y es anidado para que no compruebe todos si corta antes
	if (v_max1 != 0){
		cout << endl << BLUE << v_max1 << endl << RESET;
		if (v_max2 != 0){
			cout << BLUE << v_max2 << endl << RESET;
			if (v_max3 != 0){
				cout << BLUE << v_max3 << endl << RESET;
				if (v_max4 != 0){
					cout << BLUE << v_max4 << endl << RESET;
					if (v_max5 != 0){
						cout << BLUE << v_max5 << endl << RESET;
						if (v_max6 != 0){
							cout << BLUE << v_max6 << endl << RESET;
							if (v_max7 != 0){
								cout << BLUE << v_max7 << endl << RESET;
								if (v_max8 != 0){
									cout << BLUE << v_max8 << endl << RESET;
									if (v_max9 != 0){
										cout << BLUE << v_max9 << endl << RESET;	
										if (v_max10 != 0){
											cout << BLUE << v_max10 << endl << RESET;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
