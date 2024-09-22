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
 * @brief Módulo recibe datos y los va distribuyendo a max o min
 * @param int numero_de_numeros numero total numeros a evaluar
 * @param int &max el numero maximo actual
 * @param int &min el numero minimo actual
 * @pre numero_de_numeros > 0
 * @post max sea el numero maximo introduciudo
 * @post min sea el numero minimo introduciudo
 * @version 2.0
 * @date 2023-15-01
 * @version 2.1 -
 * @date 2023-16-01
 * @author Dios-Fer
 */	
void CalcularMaxMin (int &max, int &min, int numero_de_numeros){

	int numero=0;
	
	//inicializamos max y min al primer numero introducido
	cin>>numero;
	max=numero;
	min=numero;

	for (int i=2; i<=numero_de_numeros; i++){//empezamos en 2 pues el primer numero introducido sera el mas grande y el mas pequeño, nos perjudica inicializar en 0, debemos inicializar en ese primer numero
		cin >> numero;
		
		if (numero>max){
			max=numero;
		}
		if (numero<min){
			min=numero;
		}
	}
	
}


/* *
 * @brief Módulo (main) que pide y filtra datos y da las salidas de calculadora de min y max
 * @return 0;
 * @post que numero_de_numeros sea moyor a 0
 * @post que de las salidas max y min
 * @version 2.0
 * @date 2023-15-01
 * @version 2.1 -
 * @date 2023-16-01
 * @author Dios-Fer
 */
int main (){

	int numero_de_numeros=0, max=0, min=0;
	bool numero_correcto=true;
	
	do{
	cout << BOLDMAGENTA<<endl<<"======================================================================================================================================================="<<endl;
	cout << "Introduzca un numero mayor a 0 para determinar que tantos numero vas a introducir, tras este escribe esos numeros y se te dara el mayor y el menor: "<<endl<<endl;
	
	numero_correcto=true;
	cin >> numero_de_numeros;
	CalcularMaxMin (max, min, numero_de_numeros);
	
	
	if(cin.fail()==1){//filtro para letras
		cin.clear();
		cin.ignore(10000, '\n');
		cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
		numero_correcto=false;
	}
	if (numero_correcto==true){//filtro de numero de numeros mayor a 0
		if (numero_de_numeros<=0){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << BOLDRED <<"El numero de numeros que vas a introducir debe de ser 1 o superior"<<RESET<<endl;
			numero_correcto=false;
		}
	}
	
	}while(numero_correcto==false);
	
	cout << endl<<BOLDYELLOW<<"De los numeros introducidos el "<<BOLDBLUE<<"mayor"<< BOLDYELLOW<<" es: "<<BOLDBLUE<<max << BOLDYELLOW<<" y el "<<BOLDCYAN<<"menor "<<BOLDYELLOW<<"es "<< BOLDCYAN<<min<<endl<<endl;
}
