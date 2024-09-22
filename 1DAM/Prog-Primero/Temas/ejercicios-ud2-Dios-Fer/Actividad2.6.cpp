#include <iostream>
#include <cmath>
using namespace std;
int main(){

	double a, b, c;
	double x1, x2;
	
	cout << "Introduce tu ecuación unicamente con los valores y en orden aqui un ejemplo, si tu ecuacion es: 5x²-3x+7 = 0 escribe con espacios 5 -3 7 y presione enter: ";
	cin >> a >> b >> c;
	
	//ax²+bx+c=0 
	
	if ((a == 0) && (b != 0)){
		//x1=0 (a=0) (Ecuacion de primer grado)
		x1=((-c)/b);
		cout << "Usted ha introducido una ecuacion de primer grado, su x = " << x1 << endl;
		
	}
	else if (( a == 0 )&& ( b == 0)){
		//0x² + 0x + c = 0 (Sin incognitas c=0)
		cout << "No podemos hacer ninguna ecuacion sin incognitas" << endl;
	}
	
	else if (((pow(b, 2)) + ((-4)*a*c)) <= 0){
		//Discriminante negativo
		cout << "No hay solucion, nuestro discriminante es negativo" << endl;
		
		}
	else{
		//Ecuacion de segundo grado
		x1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
		x2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
		cout << "La primera posible solucion es x=" << x1 << " y la otra posible solucion es x=" << x2 << endl;
	}
	
}

