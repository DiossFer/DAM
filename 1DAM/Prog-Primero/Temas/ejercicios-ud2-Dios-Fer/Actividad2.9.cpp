#include <iostream>
using namespace std;
int main(){

	double nota=0.0;

	cout << "Intoduzca su nota: ";
	cin >> nota;
	//suspender
	if ((nota>=0.0) && (nota<5.0)){
		cout << "Estas suspenso."<<endl;
	}
	//numero no valido
	else if (nota<0.0){
		cout << "¿Tu nota es negativa? O se te da mal eso de escribir." << endl;
	}
	//numero no valido
	else if (nota>10.0){
		cout << "Estamos operando con notas del 0 al 10 o has escrito mal o operas con una rubrica mayor." << endl;
	}
	//aprobar
	else{
		//aprobado
		if((nota>=5.0) && (nota<7.0)){
			cout << "Has aprobado." << endl;
		}
		//notable
		else if ((nota>=7.0) && (nota<9.0)){
			cout << "Felicidades has sacado un notable." << endl;
		//sobresaliente
		}
		else {
			cout << "¡Enhorabuena! Has sacado un sobresaliente." << endl;
		}
	}
		

}
