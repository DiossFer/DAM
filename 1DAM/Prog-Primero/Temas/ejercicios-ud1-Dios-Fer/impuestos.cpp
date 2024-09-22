#include<iostream>
using namespace std;
int main () {

	//Costes y salarios
	double coste_de_nomina = 0, salario_bruto = 0, salario_neto = 0, gasto_total = 0, parte_del_estado = 0, ahorro_total = 0, ahorro_total_anual = 0;
	//Constantes para el calculo
	const double CALCULO_SSOCIAL_RECCONJUNTA = 0.255675, CALCULO_IRPF = 0.1116985188, CALCULO_CONTINGENCIAS_COMUNES = 0.0470023175, CALCULO_FORMADCION_DESEMPLEO = 0.0164981695;
	//Parte para el estado
	double SSocial_RECConjunta = 0, IRPF = 0, Contingencias_Comunes = 0, Formacion_Desempleo = 0;
	//Gastos
	double hipoteca = 0, luz = 0, agua = 0, telefono_internet = 0, gasolina = 0, comida = 0, ocio = 0, tabaco = 0, gastos_comunitarios = 0;
	//Constantes para el calculo de los gastos
	const double CALCULO_IMPUESTO_LUZ = 0.569230769231, CALCULO_IMPUESTO_AGUA = 0.01, CALCULO_IMPUESTO_TEL_INT = 0.222222222222, CALCULO_IMPUESTO_GASOLINA = 0.5833333;
	const double CALCULO_IMPUESTO_COMIDA = 0.07, CALCULO_IMPUESTO_OCIO = 0.18333333, CALCULO_IMPUESTO_TABACO = 0.816666666667;
	//Parte para el estado de los gastos
	double luz_estado = 0, agua_estado = 0, telefono_internet_estado = 0, gasolina_estado = 0, comida_estado = 0, ocio_estado = 0, tabaco_estado = 0;
	//Impuesto extra
	double IBI = 0, impuesto_de_circulacion = 0;
	//Pedimos e introducimos el coste de la nomina
	cout << "Buenas, porfavor introduzaca su coste de nomina mensual, no requiere de que introduzca la moneda el programa trabajara con euros: ";
	cin >> coste_de_nomina;

	//Calculamos el salario bruto, el neto y los impuestos que hacen de intermediarios para llegar a estos
	SSocial_RECConjunta = CALCULO_SSOCIAL_RECCONJUNTA * coste_de_nomina;
	salario_bruto = coste_de_nomina - SSocial_RECConjunta;
	IRPF = salario_bruto * CALCULO_IRPF;
	Contingencias_Comunes = salario_bruto * CALCULO_CONTINGENCIAS_COMUNES; 
	Formacion_Desempleo = salario_bruto * CALCULO_FORMADCION_DESEMPLEO;
	salario_neto = salario_bruto - Formacion_Desempleo - Contingencias_Comunes - IRPF;

	//Vamos a pedir e introducir los gastos
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

	//Vamos a calcular los impuestos de cada gasto
	luz_estado = CALCULO_IMPUESTO_LUZ * luz;
	agua_estado = CALCULO_IMPUESTO_AGUA * agua;
	telefono_internet_estado = CALCULO_IMPUESTO_TEL_INT * telefono_internet;
	gasolina_estado = CALCULO_IMPUESTO_GASOLINA * gasolina;
	comida_estado = CALCULO_IMPUESTO_COMIDA * comida;
	ocio_estado = CALCULO_IMPUESTO_OCIO * ocio;
	tabaco_estado = CALCULO_IMPUESTO_TABACO * tabaco;

	//El IBI y el impuesto de circulacion lo pediremos aparte pues depende de la persona
	cout << "Ahora y por ultimo ponga lo que paga mensualmente de estos dos impuestos: " << endl;
	cout << "IBI: ";
	cin >> IBI;
	cout << "Impuesto de circulacion: ";
	cin >> impuesto_de_circulacion;

	//Calculamosel gasto total, el ahorro y lo que se lleva el estado
	gasto_total = hipoteca + luz + agua + telefono_internet + gasolina + comida + ocio + tabaco + gastos_comunitarios + IBI + impuesto_de_circulacion;
	parte_del_estado = coste_de_nomina - salario_neto + luz_estado + agua_estado + telefono_internet_estado + gasolina_estado + comida_estado + ocio_estado + tabaco_estado + IBI + impuesto_de_circulacion;
	ahorro_total = salario_neto - gasto_total;
	ahorro_total_anual = ahorro_total * 12;
	//Mostramos los resultados
	cout << "Partiendo de lo que paga el empresario por ti, tu salario bruto es de: " << salario_bruto << "€, y tu salario neto es de: " << salario_neto << "€" << endl;
	cout << "Lo que usted gasta mensualmente es de: " << gasto_total << "€" << endl;
	cout << "Del dinero que pago el empresario por ti el estado se ha llevado: " << parte_del_estado << "€" << endl;
	cout << "En total lo que te sobra mensualmente y puedes ahorrar es un total de: " << ahorro_total << "€" << endl;
	cout << "Siguiendo este esquema ahorraras en un año un total de: " << ahorro_total_anual << "€" << endl;
}

