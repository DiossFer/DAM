#include <iostream>//V1.1
using namespace std;

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


int problema1 () {

	int numero_sonidos=0;
	char caracter=' ';
	bool condicion_fin=false;
	
	
	int marcador1=0, marcador2=0;
	bool direccion=true; //True hacia derecha False hacia izquierda
	
	
	do{//Bucle por lineal
	
		do{//Filtro del numero
		cout << BOLDYELLOW<<"======================================================================================================="<<endl;
		
		cin >> numero_sonidos;//numero inicial 
		if (numero_sonidos<0){
			cout <<BOLDRED<< "Introduzca un numero no negativo"<<RESET<<endl;
		}
		
		}while (numero_sonidos < 0);
		
		
		
		cout << BOLDYELLOW<<endl;
		for (int i=0; i < numero_sonidos-1; i++){//bucle para cada sonido	//Resto 1 para garantizar que el ultimo sea PONG!
			condicion_fin=false;

			for (int j=0; j<=5 && condicion_fin==false; j++){
			//bucle para cada letra del sonido	//ya que debemos introducir palabras, comprobare una por una las letras para ver que palabra es
			
			cin >> caracter;						//Primer caracter 
				
				if (caracter=='P'){//PIC/POC/PONG!
					cin >> caracter;						//Segundo caracter
				
					if (caracter=='I'){//PIC
						cin >> caracter;						//Tercer caracter 
						
						
						if (caracter == 'C'){//PIC
							condicion_fin=true;			/*PIC*/
							
							
							if (direccion==true){//Cambio de sentido
								direccion=false;
							}
							else {
								direccion=true;
							}
						}
						
					}
					
					else if (caracter=='O'){//POC/PONG!
						cin >> caracter;						//Tercer caracter
						
						if (caracter=='C'){//POC
							condicion_fin=true;			/*POC*/

						}
						
						else if (caracter=='N'){//PONG!
							cin >> caracter;						//Cuarto caracter
						
							if (caracter=='G'){//PONG!
								cin >> caracter;						//Quinto caracter

								if (caracter=='!'){//PONG!
									condicion_fin=true;	/*PONG!*/
									
									
									if (direccion==true){ 	//Gol en derecha punto para izquierda (marcador1)
										marcador1++;
										
									}
									else{			//Gol en izquierda punto para derecha (marcador2)
										marcador2++;
									}
									
								}

							}

						}

					}

				}

			}
			
			
		}
		condicion_fin=false;//volvemos a inicializar
		for (int j=0; (j<=5) && (condicion_fin==false) && (numero_sonidos != 0); j++){//El ultimo que tiene que ser PONG!, en caso de ser PIC o POC saltara con un cout
		
		





				cin >> caracter;						//Primer caracter 
				if (caracter=='P'){//PIC/POC/PONG!
					cin >> caracter;						//Segundo caracter
				
					if (caracter=='I'){//PIC
						cin >> caracter;						//Tercer caracter 
						
						
						if (caracter == 'C'){//PIC
							condicion_fin=true;			/*PIC*/		
							cout << BOLDRED <<"PIC no esta permitido como ultimo sonido, tu ultimo PIC ha sido sustituido por un PONG! automaticamente" << RESET << endl; 
							//Sustitucion automatica por PONG!
							if (direccion==true){ 	//Gol en derecha punto para izquierda (marcador1)
								marcador1++;
								
							}
							else{			//Gol en izquierda punto para derecha (marcador2)
								marcador2++;
							}
						
						}
					}
					
					else if (caracter=='O'){//POC/PONG!
						cin >> caracter;						//Tercer caracter
						
						if (caracter=='C'){//POC
							condicion_fin=true;			/*POC*/
							cout << BOLDRED <<"POC no esta permitido como ultimo sonido, tu ultimo POC ha sido sustituido por un PONG! automaticamente" << RESET << endl; 
							
							//Sustitucion automatica por PONG!
							if (direccion==true){ 	//Gol en derecha punto para izquierda (marcador1)
								marcador1++;
								
							}
							else{			//Gol en izquierda punto para derecha (marcador2)
								marcador2++;
							}
							
						}
						
						else if (caracter=='N'){//PONG!
							cin >> caracter;						//Cuarto caracter
						
							if (caracter=='G'){//PONG!
								cin >> caracter;						//Quinto caracter

								if (caracter=='!'){//PONG!
									condicion_fin=true;	/*PONG!*/
									
									
									if (direccion==true){ 	//Gol en derecha punto para izquierda (marcador1)
										marcador1++;
										
									}
									else{			//Gol en izquierda punto para derecha (marcador2)
										marcador2++;
									}
									
								}

							}

						}

					}

				}
		
		}
		
		
		if (numero_sonidos != 0){//Para que no saque marcador al cerrar el programa
			cout << BOLDMAGENTA <<marcador1 << RESET <<" "<< BOLDBLUE<<marcador2 << RESET << endl;
		}
		direccion=true;//Inicializamos post linea
		
		marcador1=0;//Inicializacion del marcador post linea
		marcador2=0;//Inicializacion del marcador post linea
		
		cout << RESET<< endl;
	}while(numero_sonidos!=0);

	return 0;

}

//int problema2 () {}

//int problema3 () {}

int main (){
	int eleccion=0;
	bool cierre=false;
	
	do{
		cout <<endl<<BOLDBLUE<<"======================================================================================================="<<endl<<endl;
		
		cout <<"Introduzaca uno de los siguientes numero dependiendo de que accion quiera realizar"<<RESET<<endl<<endl;
		cout << BOLDYELLOW <<"   "<< "#1		#Problema1, Un homenaje a los Juegos de Atari" << RESET << endl;
		cout << BOLDCYAN <<"   "<< "#2		#Problema2, TituloProblema2" << RESET << endl;
		cout << BOLDGREEN <<"   "<< "#3		#Problema3, TituloProblema3" << RESET << endl;
		cout << BOLDBLUE <<"   "<< "#4		#Cerrar el programa" << RESET << endl<<endl<<endl;
		
		cout << BOLDBLUE <<"   ";
		cin >> eleccion;
		cout << RESET<<endl;
		
		switch (eleccion){//switch para la ejecucion de x problema
		
			case 1://Problema1
				problema1 ();
				break;
				
			case 2://Problema2
				//problema2 ();
				cout << "Problema2"<<endl;
				break;
				
			case 3://Problema3
				//problema3 ();
				cout << "Problema3"<<endl;//cout para indicar que se accede bien
				break;
				
			case 4://Cierre del programa
				cierre=true;
				cout <<BOLDBLUE<<"   "<< "El programa ha finalizado con exito"<<RESET<<endl<<endl;
				break;
			
			default://Otro numero no valido
				cout <<BOLDRED<<"   "<< "Eleccion no vaida"<<RESET<<endl<<endl;
				break;
		
		}
		
	}while(cierre==false);
}




