#include <iostream>
#include <cmath>
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
 * @brief Módulo (main) para introducir la variable util, intoducir valores (sin filtros) y copiar los utilizados del vector 1 al vector 2 y sacar estos mismos ya en el vector 2 por pantalla
 * @post mostrara los espacios utilizados e introducidos en el vector1 por medio de un cout del vector2
 * @version V1
 * @date 2023-1-02
 * @author Dios-Fer
 */
int main(){

	const int DIM_1=5, DIM_2=5;

	int vector_1[DIM_1]={0};
	int vector_2[DIM_2]={0};

	int util_vector_2=0, util_vector_1=0;

	do {

		cout<<BOLDYELLOW<<"Siendo el maximo 5, cuantos valores deseas guardar: ";
		cin >> util_vector_1;
		util_vector_1=util_vector_1-1;//esto para que el usuario la posicion 0 sea realmente guardar un valor

	}while(util_vector_1<0 || util_vector_1>5);

	//Como queremos copiar, para optimizar copiaremos solo las utiles por tanto igualare las utiles
	util_vector_2=util_vector_1;

	cout<<BOLDBLUE<<endl;

	for (int i=0; i<=util_vector_1; i++){
		cin >> vector_1[i];
	}

	for (int i; i<=util_vector_2; i++){
		vector_2[i]=vector_1[i];
	}
		
	for (int i; i<=util_vector_2; i++){
		cout <<BOLDGREEN<< "//" << vector_2[i]<<RESET<<endl;
	}

}