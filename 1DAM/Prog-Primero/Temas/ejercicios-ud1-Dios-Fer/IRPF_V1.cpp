#include <iostream>
using namespace std;
int main () {
	double sueldo_bruto, sueldo_neto, impuesto_IRPF;
	const double IRPF = 0.18, porcentaje_de_sueldo = 0.82;
	cout << "Introduzca su salario bruto: ";
	cin >> sueldo_bruto;
	sueldo_neto = sueldo_bruto * porcentaje_de_sueldo;
	impuesto_IRPF = sueldo_bruto * IRPF;
	cout << "Su salario neto es: " << sueldo_neto << endl;
	cout << "Lo que paga en el IRPF es: " << impuesto_IRPF << endl;
}
