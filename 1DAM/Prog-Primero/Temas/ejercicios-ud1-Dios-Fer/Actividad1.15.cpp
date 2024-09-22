#include <iostream>
#include <cmath>
using namespace std;
int main(){

	const double y1=pow(2.0, 1.0/4.0), x0=sqrt(2.0), π0=2.0 + sqrt(2.0);
	double x1=0.0, x2=0.0, y0 =0.0, y2=0.0, π1=0.0, π2=0.0;
	
	cout << "Vamos a calcular π con la formula de Borwein, para hacerlo mas simple solo avanzaremos 3 niveles: " << endl;
	x1=1.0/2.0*(sqrt(x0) + (1.0/sqrt(x0)));
	π1=π0*((x1+1.0)/(y1+1.0));
	
	x2=1.0/2.0*(sqrt(x1) + (1.0/sqrt(x1)));
	y2=(y1*sqrt(x1) + 1.0/sqrt(x1))/(y1+1.0);
	π2=π1*((x2+1.0)/(y2+1.0));
	
	
	cout <<"π0 es igual a: " << π0 << endl;
	cout <<"π1 es igual a: " << π1 << endl;
	cout <<"π2 es igual a: " << π2 << endl;
}

