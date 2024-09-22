#include <iostream>
using namespace std;

void intercambiar (int &a, int &b){//no llegue a lo que pedia el programa en un primer momento, pues no conocia este metodo//con el & y vinculando las variables se hace sencillo el problema 
	int c=a;
	a=b;
	b=c;
}


int main (){

	int a=1, b=2;
	
	
	cout << endl << "a= " << a << endl << "b= " << b << endl;//debug
	
	intercambiar (a, b);
	
	cout << endl << "a= " << a << endl << "b= " << b << endl;//debug
	
}
