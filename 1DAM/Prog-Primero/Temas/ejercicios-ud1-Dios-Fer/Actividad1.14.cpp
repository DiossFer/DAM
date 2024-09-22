#include <iostream>
#include <cmath>
using namespace std;
int main(){

	double x1=0.0, x2=0.0, x3=0.0, m=0.0, d=0.0;
	//pides los datos
	cout << "Introduce tus tres valores reales: ";
	cin >> x1 >> x2 >> x3;
	//hacemos las operaciones 
	m=((x1+x2+x3) / 3);
	d=sqrt((pow(x1-m,2)+pow(x2-m,2)+pow(x3-m,2))/3);
	//sacamos los dos rseultados
	cout << "La media es: " << m << " y la desviacion tipica es de: " << d << endl;
	
}
