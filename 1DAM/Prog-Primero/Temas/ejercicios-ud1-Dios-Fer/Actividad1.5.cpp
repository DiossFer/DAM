#include <iostream>
#include <cmath> //falta para poder hacer el logaritmo
using namespace std;//falta el using namespace std;
int main(){
	double valor, base; //sobra la mayuscula
	cout << "Indique base: "; cin >> base; //las flechas estan al reves y falta el ;
	cout << "Indique valor: "; cin >> valor;
	cout << "El log en base" << base << "de" 
	<< valor << "es";  //la V es en minuscula (v), faltan "" al es ("es")
	cout << log(valor)/log(base) <<endl; //los menores estan separados, el endl esta mal escrito (end) 
//A la pregunta que hace de si podria provocar un erron en tiempo de jecucion si hablamos del programa con errores directamente ni se compilaria y si hablamos del arreglado si que podria tener errores por ejemplo poner una letra, o los errores caracteristicos de un logaritmo como 0, numeros negativos, ...
}
