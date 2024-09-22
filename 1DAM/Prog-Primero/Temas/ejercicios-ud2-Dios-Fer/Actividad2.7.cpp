#include <iostream>
using namespace std;
int main(){

	//Declaramos las variables (1 por caso y 1 por numero)

	double numero_1 = 0.0, numero_2 = 0.0, numero_3 = 0.0;
	bool orden123, orden132, orden213, orden231, orden312, orden321, igualdad1_23, igualdad2_13, igualdad3_12, igualdad23_1, igualdad13_2, igualdad12_3, igualdad123;
	
	
	//Pedimos los tres numeros
	cout << "Inserte tres numeros y veamos cual es el mayor." << endl;
	
	cout << "Inserte el primer numero: ";
	cin >> numero_1;
	
	cout << "Inserte el segundo numero: ";
	cin >> numero_2;
	
	cout << "Inserte el tercer numero: ";
	cin >> numero_3;
	
	
	//Guardamos todos los casos
	
	orden123 = ((numero_1 > numero_2) && (numero_2 > numero_3));
	orden132 = ((numero_1 > numero_3) && (numero_3 > numero_2));
	orden213 = ((numero_2 > numero_1) && (numero_1 > numero_3));
	orden231 = ((numero_2 > numero_3) && (numero_3 > numero_1));
	orden312 = ((numero_3 > numero_1) && (numero_1 > numero_2));
	orden321 = ((numero_3 > numero_2) && (numero_2 > numero_1));
	igualdad1_23 = ((numero_1 > numero_2) && (numero_2 == numero_3));
	igualdad2_13 = ((numero_2 > numero_1) && (numero_1 == numero_3));
	igualdad3_12 = ((numero_3 > numero_1) && (numero_1 == numero_2));
	igualdad23_1 = ((numero_2 > numero_1) && (numero_2 == numero_3));
	igualdad13_2 = ((numero_1 > numero_2) && (numero_1 == numero_3));
	igualdad12_3 = ((numero_1 > numero_3) && (numero_1 == numero_2));
	igualdad123 = ((numero_1 == numero_2) && (numero_2 == numero_3));
	

	//Hacemos una salida por caso
	
	
	if (orden123==true){
	cout << "El numero de mayor valor es: " << numero_1 << ", quedando nuestro orden de esta forma: " << numero_1 << " > " << numero_2 << " > " << numero_3 << endl;
	}
	
	
	if (orden132==true){
	cout << "El numero de mayor valor es: " << numero_1 << ", quedando nuestro orden de esta forma: " << numero_1 << " > " << numero_3 << " > " << numero_2 << endl;
	}
	
	
	if (orden213==true){
	cout << "El numero de mayor valor es: " << numero_2 << ", quedando nuestro orden de esta forma: " << numero_2 << " > " << numero_1 << " > " << numero_3 << endl;
	}
	
	
	if (orden231==true){
	cout << "El numero de mayor valor es: " << numero_2 << ", quedando nuestro orden de esta forma: " << numero_2 << " > " << numero_3 << " > " << numero_1 << endl;
	}
	
	
	if (orden312==true){
	cout << "El numero de mayor valor es: " << numero_3 << ", quedando nuestro orden de esta forma: " << numero_3 << " > " << numero_1 << " > " << numero_2 << endl;
	}
	
	
	if (orden321==true){
	cout << "El numero de mayor valor es: " << numero_3 << ", quedando nuestro orden de esta forma: " << numero_3 << " > " << numero_2 << " > " << numero_1 << endl;
	}
	
	
	if (igualdad1_23==true){
	cout << "El numero de mayor valor es: " << numero_1 << ", quedando nuestro orden de esta forma: " << numero_1 << " > " << numero_2 << " = " << numero_3 << endl;
	}
	
	
	if (igualdad2_13==true){
	cout << "El numero de mayor valor es: " << numero_2 << ", quedando nuestro orden de esta forma: " << numero_2 << " > " << numero_1 << " = " << numero_3 << endl;
	}
	
	
	if (igualdad3_12==true){
	cout << "El numero de mayor valor es: " << numero_3 << ", quedando nuestro orden de esta forma: " << numero_3 << " > " << numero_1 << " = " << numero_2 << endl;
	}
	
	
	if (igualdad23_1==true){
	cout << "El numero de mayor valor es: " << numero_3 << ", que es igual al numero: " << numero_2 << ", quedando de esta forma: " << numero_3 << " = " << numero_2 << " > " << numero_1 << endl;
	}
	
	
	if (igualdad13_2==true){
	cout << "El numero de mayor valor es: " << numero_3 << ", que es igual al numero: " << numero_1 << ", quedando de esta forma: " << numero_3 << " = " << numero_1 << " > " << numero_2 << endl;
	}
	
	
	if (igualdad12_3==true){
	cout << "El numero de mayor valor es: " << numero_1 << ", que es igual al numero: " << numero_2 << ", quedando de esta forma: " << numero_1 << " = " << numero_2 << " > " << numero_3 << endl;
	}
	
	
	if (igualdad123==true){
	cout << "Todos los numero introducidos son iguales, " << numero_1 << " = " << numero_2 << " = " << numero_3 << endl;
	}
	
}

