#include <iostream>
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


 
 
 /* *
 * @brief Módulo para calcular el MCD 
 * @param int nuero1 
 * @param int nuero2 
 * @return int mcd siendo el mcd entre los dos numeros
 * @pre numero1 y numero2 son validos
 * @post se dara la solucion al modulo necesario
 * @version 0.1
 * @version 0.2 
 * @version 1.0 
 * @date 2023-15-01
 * @version 1.1 -
 * @date 2023-16-01
 * @author Dios-Fer
 */
int MCD (int numero1, int numero2){
	int mcd=0, resto=0;
	
	if (numero2==0){//si uno es 0 el mcd sera el otro numero comprobaremos el de la derecha para evitar fallos con el uso del modulo (nos da igual que numero1 sea 0)
	
		numero2=numero1;//cambiamos el orden pues nuestro resultado sera el "numero2"
		
	}
	
	else{//Caso comun con el algoritmo de Euclides

		resto = numero1 % numero2;
		
		while(resto != 0){
		
			numero1=numero2;
			numero2=resto;
			resto=numero1 % numero2;
		
		}
	
	
	}
	
	mcd=numero2;//En este algoritmo el mcd es en segundo numero, lo hacemos asi para organizarlo mejor
	
	return mcd;
}
 
 
 
 /* *
 * @brief Módulo (main) entrada y salida de datos
 * @post numero1 numero2 como validos para el programa, y por ultimo la slida de resultados
 * @version 0.1
 * @version 0.2
 * @version 1.0
 * @date 2023-15-01
 * @version 1.1 -
 * @date 2023-16-01
 * @author Dios-Fer
 */
 
int main (){
	int numero1=0, numero2=0;
	int mcd=0;
	bool numero=true;
	
	do{
		cout << BOLDYELLOW << "==================================================================="<<endl;
		cout << BOLDYELLOW << "Introduzca dos numero para hacer el mcd de estos: ";
		numero=true;
	
		cin >> numero1 >> numero2;
		
		if(cin.fail()==1){//filtro para letras
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
			numero=false;
		}
	}while(numero==false);
	
	mcd = MCD (numero1, numero2);
	
	cout << endl<<BOLDYELLOW<<"El maximo comun divisor de tus numeros: "<< BOLDBLUE<<numero1 <<BOLDYELLOW<<" y "<<BOLDBLUE<<numero2<<BOLDYELLOW<<" es: " << BOLDCYAN<<mcd << endl<<endl;
	
}
 
