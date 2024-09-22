#include <iostream>
using namespace std;
int main() {
	int a, b, resResto1, resResto2, resSum, resResta1, resResta2, resDiv1, resDiv2, resMul;
	cout << "Introduce el primer numero: ";
	cin >> a; 
	cout << "Introduce el segundo numero: ";
	cin >> b;
	resSum = a + b;
	resResta1 = a - b;
	resResta2 = b - a;
	resMul = a * b;
	resDiv1 = a / b;
	resResto1 = a % b;
	resDiv2 = b / a;
	resResto2 = b % a;
	cout << "El resultado de la suma entre estos dos numero es: "<< resSum << endl;
	cout << "El resultado de la resta del primer numero menos el segundo es: "<< resResta1 << endl;
	cout << "El resultado de la resta del segundo numero menos el primero es: "<< resResta2 << endl;
	cout << "El resultado de la multiplicacion entre estos dos numero es: "<< resMul << endl;
	cout << "El resultado de la division del primer numero entre el segundo es: "<< resDiv1 << " y su resto es: " << resResto1<< endl;
	cout << "El resultado de la division del segundo numero entre el primero es: "<< resDiv2 << " y su resto es: " << resResto2 << endl;
}
