#include<iostream>
using namespace std;
int main () {

	//coste de nomina
	const double COSTE_DE_NOMINA = 50000, COSTE_DE_NOMINA_MENSUAL = COSTE_DE_NOMINA / 12;
	//Costes y salarios
	double salario_bruto = 0, salario_neto = 0, gasto_total = 0, parte_del_estado_mensual = 0, ahorro_total_mensual = 0, ahorro_total_anual = 0, parte_del_estado_anual = 0, ahorro_total_mensual_anual = 0;
	//Constantes para el calculo



	//retenciones en conjunto
	const double CALC_RETENCION_EMPRESA = 1.314, CALC_RETENCION_TRABAJADOR = 0.7565;


	//Parte para el estado
	double retencion_empresa = 0, retencion_trabajador = 0;
	//Gastos
	double hipoteca = 0, luz = 0, agua = 0, telefono_internet = 0, gasolina = 0, comida = 0, ocio = 0, tabaco = 0, gastos_comunitarios = 0;
	//Constantes para el calculo de los gastos
	const double CALCULO_IMPUESTO_LUZ = 1.1511, CALCULO_IMPUESTO_AGUA = 1.10, CALCULO_IMPUESTO_TEL_INT = 1.21, CALCULO_IMPUESTO_GASOLINA = 1.21;
	const double CALCULO_IMPUESTO_COMIDA = 1.10, CALCULO_IMPUESTO_OCIO = 1.21, CALCULO_IMPUESTO_TABACO = 1.72;
	//Parte para el estado de los gastos
	double luz_estado = 0, agua_estado = 0, telefono_internet_estado = 0, gasolina_estado = 0, comida_estado = 0, ocio_estado = 0, tabaco_estado = 0;
	//Impuesto extra
	double IBI = 0, impuesto_de_circulacion = 0;
	//La nomina la tomamos como constante
	

	//Calculamos el salario bruto, el neto y los impuestos que hacen de intermediarios para llegar a estos
	retencion_empresa = COSTE_DE_NOMINA_MENSUAL - COSTE_DE_NOMINA_MENSUAL / CALC_RETENCION_EMPRESA;
	
	salario_bruto = COSTE_DE_NOMINA_MENSUAL - retencion_empresa;

	retencion_trabajador = salario_bruto - salario_bruto * CALC_RETENCION_TRABAJADOR;
	salario_neto = salario_bruto - retencion_trabajador;
	
	cout << "_____________________________Sueldo Bruto y Sueldo Neto_____________________________" << endl;
	//Diremos el salario bruto y neto mensual y anual del trabajador
	cout << "Partiendo de que su coste de nomina sea 50000€ anuales." << endl;
	cout << "Su salario bruto es de: " << salario_bruto << "€ mensuales/ " << salario_bruto * 12 << "€ anuales"<< endl;
	cout << "Su salario neto es de: " << salario_neto << "€ mensuales/ " << salario_neto * 12 << "€ anuales"<< endl;
	cout << "_____________________________________Gastos_____________________________________" << endl;
	//Vamos a pedir e introducir los gastos a la vez que vamos a calcular los impuestos de cada gasto
	cout << "Introduzca lo que gasta mensualmente en los siguiente ambitos: " << endl;
	cout << "Hipoteca: ";
	cin >> hipoteca;
	cout << "Luz: ";
	cin >> luz;
	cout << "Agua: ";
	cin >> agua;
	cout << "Telefono/Internet: ";
	cin >> telefono_internet;
	cout << "Gasolina: ";
	cin >> gasolina;
	cout << "Comida: ";
	cin >> comida;
	cout << "Ocio: ";
	cin >> ocio;
	cout << "Tabaco: ";
	cin >> tabaco;
	cout << "Gastos comunitarios: ";
	cin >> gastos_comunitarios;

	//
	luz_estado = luz - luz / CALCULO_IMPUESTO_LUZ;
	agua_estado = agua - agua / CALCULO_IMPUESTO_AGUA;
	telefono_internet_estado = telefono_internet - telefono_internet / CALCULO_IMPUESTO_TEL_INT;
	gasolina_estado = gasolina - gasolina / CALCULO_IMPUESTO_GASOLINA;
	comida_estado = comida - comida / CALCULO_IMPUESTO_COMIDA;
	ocio_estado = ocio - ocio / CALCULO_IMPUESTO_OCIO;
	tabaco_estado = tabaco - tabaco / CALCULO_IMPUESTO_TABACO;
	cout << "________________________________Impuestos Extra________________________________" << endl;
	//El IBI y el impuesto de circulacion lo pediremos aparte pues depende de la persona
	cout << "Ahora y por ultimo ponga lo que paga mensualmente de estos dos impuestos: " << endl;
	cout << "IBI: ";
	cin >> IBI;
	cout << "Impuesto de circulacion: ";
	cin >> impuesto_de_circulacion;

	//Calculamosel gasto total, el ahorro y lo que se lleva el estado
	gasto_total = hipoteca + luz + agua + telefono_internet + gasolina + comida + ocio + tabaco + gastos_comunitarios + IBI + impuesto_de_circulacion;
	parte_del_estado_mensual = salario_bruto - salario_neto + luz_estado + agua_estado + telefono_internet_estado + gasolina_estado + comida_estado + ocio_estado + tabaco_estado + IBI + impuesto_de_circulacion;
	parte_del_estado_anual = parte_del_estado_mensual * 12;
	ahorro_total_mensual = salario_neto - gasto_total;
	ahorro_total_anual = ahorro_total_mensual * 12;
	//Mostramos los resultados
	cout << "______________________________Ahorro e Impuestos______________________________" << endl;
	cout << "Tu gasto total es de: " << gasto_total << "€" << endl;
	cout << "Ahorro mensual: " << ahorro_total_mensual << "€" << endl;
	cout << "Ahorro anual: " << ahorro_total_anual << "€" << endl;
	cout << "Impuestos anuales al usuario: " << parte_del_estado_mensual << "€" << endl;
	cout << "Impuestos mensuales al usuario: " << parte_del_estado_anual << "€" << endl;
}

