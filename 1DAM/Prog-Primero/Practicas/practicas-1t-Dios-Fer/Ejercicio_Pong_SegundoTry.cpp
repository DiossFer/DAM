#include <iostream>//V1
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

int main (){

	int numero_sonidos=0;
	int numero=0;
	do{//bucle de repeticion de lineas
		char caracter_uno= ' ', caracter_dos= ' ', caracter_tres=' ', caracter_cuatro=' ', caracter_cinco=' ', caracter_seis=' ', caracter_siete=' ';

		bool numero_bien=true;
		bool palabra_fin=false;
		
		int marcador_I=0, marcador_D=0;//puntos que tiene la pala de cada lado
		bool direccion=true;//true=derecha-false=izquierda (hacia)
	



		do{//Numero de sonidos
			
			cout << BOLDYELLOW<<"============================================================================="<<RESET<<endl;
			cout << BOLDBLUE;
			numero_bien=true;
			cin >> numero_sonidos;
			
			if(cin.fail()==1){
				cin.clear();
				cin.ignore(10000, '\n');
				cout << BOLDRED << "Has introducido mal el numero, reescriba su linea, intentando no fallar de nuevo"<<RESET<<endl<<endl;
				numero_bien=false;
			}
		} while (numero_bien==false);

		
		//Para la condicion de salida
		numero=numero_sonidos;


		caracter_uno = cin.get ();//(' ')		

		
		if(caracter_uno==' '){//primer if 	//(espacio inicial)


			for (numero_sonidos; numero_sonidos > 1; numero_sonidos--){//bucle de todos los sonidos (menos el ultimo)

				palabra_fin=false;
				for ( ; palabra_fin==false; ){//bucle de lectura (palabra)
				cout << BOLDBLUE;
					caracter_dos = cin.get ();//('P')
					
					if(caracter_dos=='P'){//segundo if	//(P)
						caracter_tres = cin.get ();//('I')/('O')
						if(caracter_tres=='I'){//tercer if	//(I)
							caracter_cuatro = cin.get ();//('C')
							if(caracter_cuatro == 'C'){//cuarto if	//((I)C)
								caracter_cinco=cin.get();
								if (caracter_cinco==' '){//quinto if (PIC_espacio)
								
									//Fincion del PIC (cambio de direccion)
									if (direccion==true){
									direccion=false;
									}
									else{
									direccion=true;
									}
									
									
									palabra_fin=true;
									
								}//quinto if (PIC_espacio)
							}//cuarto if	//((I)C)
						}//tercer if	//(I)
						
						else if(caracter_tres=='O'){//tercer if	//(O)
							caracter_cuatro = cin.get ();//('C')/('N')
							
							if(caracter_cuatro=='C'){//cuarto if	//((O)C)
								caracter_cinco=cin.get();
								if (caracter_cinco==' '){//quinto if (POC_espacio)

									//Nos da igual
									
									palabra_fin=true;
									
								}//quinto if (POC_espacio)
							}//cuarto if	//((O)C)
							
							else if(caracter_cuatro=='N'){//cuarto if 	//(N)
								caracter_cinco = cin.get ();//('G')
								if(caracter_cinco=='G'){//quinto if 	//(G)
									caracter_seis = cin.get ();//('!')
									if(caracter_seis=='!'){//sexto if 	//(!)
										caracter_siete=cin.get();
										if (caracter_siete==' '){//septimo if (PONG!_espacio)
											
											//Funcion del PONG!
											if (direccion==true){//vamos hacia la derecha punto para la izquierda (marcador_I)
											marcador_I++;
											}
											else{//vamos hacia la izquierda punto para la derecha (marcador_D)
											marcador_D++;
											}
											
											
											palabra_fin=true;
											
										}//septimo if (PONG!_espacio)
									}//sexto if 	//(!)
								}//quinto if 	//(G)
							}//cuarto if 	//(N)
						}//tercer if	//(O)
						
					}//segundo if	//(P)
					
					
					if (palabra_fin==false){//Filtro ante palabra mal introducida
					cout <<BOLDRED<< "Revise en su linea, ha de tener algun error, repita desde ese punto"<<RESET<<endl;
					cin.ignore(10000, '\n');
					cin.clear();
					}//Filtro ante palabra mal introducida
					
					
				}//bucle de lectura (palabra)		
				
			}//bucle de todos los sonidos (menos el ultimo)
			
			
		
			for ( ;numero_sonidos == 1; numero_sonidos--){//Bucle del ultimo sonido 		//Para que acabe en PONG! haremos el ultimo aparte para mas facilidad y optimizacion
				bool palabra_final=true;
				palabra_fin=false;
				cout << BOLDBLUE;
					caracter_dos = cin.get ();//('P')
					
					if(caracter_dos=='P'){//segundo if	//(P)
						caracter_tres = cin.get ();//('I')/('O')
						
						if(caracter_tres=='I'){//tercer if	//(I)
							caracter_cuatro = cin.get ();//('C')
							if(caracter_cuatro == 'C'){//cuarto if	//((I)C)
								caracter_cinco=cin.get();
								if (caracter_cinco=='\n'){//quinto if (PIC_enter)
								

									palabra_fin=true;
									palabra_final=false;
								}//quinto if (PIC_enter)
							}//cuarto if	//((I)C)
						}//tercer if	//(I)
						
						else if(caracter_tres=='O'){//tercer if	//(O)
							caracter_cuatro = cin.get ();//('C')/('N')
							
							if(caracter_cuatro=='C'){//cuarto if	//((O)C)
								caracter_cinco=cin.get();
								if (caracter_cinco=='\n'){//quinto if (POC_enter)


									palabra_fin=true;
									palabra_final=false;
								}//quinto if (POC_enter)
							}//cuarto if	//((O)C)
							
							else if(caracter_cuatro=='N'){//cuarto if 	//(N)
								caracter_cinco = cin.get ();//('G')
								if(caracter_cinco=='G'){//quinto if 	//(G)
									caracter_seis = cin.get ();//('!')
									if(caracter_seis=='!'){//sexto if 	//(!)
										caracter_siete=cin.get();
										if (caracter_siete=='\n'){//septimo if (PONG!_enter)

											//Funcion del PONG!
											if (direccion==true){//vamos hacia la derecha punto para la izquierda (marcador_I)
											marcador_I++;
											}
											else{//vamos hacia la izquierda punto para la derecha (marcador_D)
											marcador_D++;
											}
											

											palabra_fin=true;
											palabra_final=true;
											
										}//septimo if (PONG!_enter)
									}//sexto if 	//(!)
								}//quinto if 	//(G)
							}//cuarto if 	//(N)
						}//tercer if	//(O)
						
					}//segundo if	//(P)
					
					if (palabra_fin==false){//Filtro ante palabra mal introducida
						cout << BOLDRED<<"Revise en su linea, ha de tener algun error, repita desde ese punto"<<RESET<<endl;
						cin.ignore(10000, '\n');
						cin.clear();
						numero_sonidos++;//Para volver a entrar pues no es valido
					}//Filtro ante palabra mal introducida
					
					if (palabra_final==false && palabra_fin==true){//en caso de poner PIC o POC al final
					cout <<BOLDRED<< "El ultimo sonido no es valido, recuerde que debe de acabar en PONG!, repitalo recordando que su unica opcion valida es PONG! "<<RESET<<endl;
					numero_sonidos++;//Para volver a entrar pues no es valido
					}
			}
			
			
			
		}//primer if 	//(espacio inicial)
		
		if (numero != 0){//para que no saque 0 0 en caso de cerrar el programa
		cout << endl<<BOLDCYAN<<marcador_I << " " << BOLDMAGENTA<<marcador_D <<RESET<< endl<<endl;
		}
		
	} while (numero != 0);//bucle de repeticion de lineas
cout << endl;
}//cierre del main
