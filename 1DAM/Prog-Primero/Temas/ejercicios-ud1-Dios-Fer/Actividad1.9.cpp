#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double a, b, c, x1, x2;
	cout << "Introduce tu ecuación unicamente con los valores y en orden aqui un ejemplo si tu ecuacion es: 2x²+3x-1 escribe con espacios 2 3 -1 y presione enter: ";
	cin >> a >> b >> c;
	//ax2+bx+c=0
	x1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
	x2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
	cout << "La primera posible solucion es x=" << x1 << " y la otra posible solucion es x=" << x2 << endl;
}
