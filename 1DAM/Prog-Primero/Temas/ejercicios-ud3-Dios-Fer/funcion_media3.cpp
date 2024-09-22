#include <iostream>
using namespace std;
double media3 (double numero1, double numero2, double numero3){
	double resultado=0.0;
	//reutilizamos el primer numero para la sumatoria
	numero1+=numero2;
	numero1+=numero3;
	//sumatoria/numero total (3)
	resultado=((numero1)/3);
	//resultado de la media
	return resultado;
}


int main (){
	double n1=0.0, n2=0.0, n3=0.0;
	double res=0.0;
	
	cin >> n1 >> n2 >> n3;
	
	//Calculo de la media
	res = media3 (n1, n2, n3);
	
	cout << res << endl;
}
