#include <iostream>
#include <cmath>
using namespace std;

//glovales
const bool DEBUG=false;

//colores
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


 
 
 /* *
 * @brief Módulo para introducir los tres parametros (a, b, c) de una ecuacion de segundo grado
 * @param double &a
 * @param double &b
 * @param double &c
 * @post se daran los tres parametros filtrados
 * @version 0.1 
 * @date 2023-17-01
 * @version 0.3 -
 * @date 2023-17-01
 * @author Dios-Fer
 */
void Pedida_ecuacion (double &a, double &b, double &c){
	bool numerobien;
	
	do{
	cout << BOLDYELLOW << "==============================================================================================="<<endl;
	cout << BOLDYELLOW << "Introduzca los tres parametros de su ecuacion en orden (ax2 + bx + c) (a b c): ";
	numerobien=true;

	cin >> a;
	cin >> b;
	cin >> c;
	
	if(cin.fail()==1){//filtro para letras
		cin.clear();
		cin.ignore(10000, '\n');
		cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
		numerobien=false;
	}
	
	}while(numerobien==false);
	
}

 /* *
 * @brief Módulo marcara un tipo y en funcion resolvera
 * @param double a
 * @param double b
 * @param double c
 * @param double &x1
 * @param double &x2
 * @post dependiendo de como sea la funcion mandara a resolverla y pasara la solucion 
 * @version 0.3 -
 * @date 2023-17-01
 * @author Dios-Fer
 */
bool clasificar_resolver_ecuacion (double a, double b, double c, double &x1, double &x2) {
	bool sol=false;//solucion
	
	if (a==0){
		if (b==0){//Igualdad
		sol=false;
		}
		else {//ecuacion de primer grado
			x1=((-c)/b);
			x2=x1;//si ambos son iguales solo hay una solucion 
			sol=true;
		}
	}
	
	else{
		double discriminante=b*b-4*a*c;
		
		if (discriminante<0){
			sol=false;
		}
		else if (discriminante==0){//1 solucion b + 0 = b - 0
			sol=true;
			x1=((-b)/(2*a));
			x2=x1;//si ambos son iguales solo hay una solucion 
		}
		else {
			sol=true;
			x1=(-b+sqrt(discriminante))/(2*a);
			x2=(-b-sqrt(discriminante))/(2*a);
		}
	}
	
	if (DEBUG == true){

        cout << BOLDRED << "DEBUG(clasificar_resolver_ecuacion): Salgo de clasificar_resolver_ecuacion" << RESET << endl;
        cout << BOLDRED << "DEBUG(clasificar_resolver_ecuacion): sol= " << sol << RESET << endl;
	cout << BOLDRED << "DEBUG(clasificar_resolver_ecuacion): x1= " << x1 << " x2= "<<x2 << RESET << endl;

	}
	
	return sol;
}



 /* *
 * @brief Módulo marcara un tipo y en funcion resolvera
 * @param double x1 solucion1
 * @param double x2 solucion2
 * @param bool sol (hay o no solucion)
 * @post dependiendo de como sea la funcion mandara a resolverla y pasara la solucion 
 * @version 0.3 
 * @date 2023-17-01
 * @version 1 -
 * @date 2023-17-01
 * @author Dios-Fer
 */


void Salida_resultado (double x1, double x2, bool sol){
	
	if (sol==true){
		if (x1==x2){
			cout << BOLDYELLOW <<"En tu ecuacion solo hay una solucion x=" <<x1<<endl;
		}
		else {
			cout << BOLDYELLOW <<"Las soluciones de tu ecuacion son: x="<<BOLDGREEN<<x1<<BOLDYELLOW <<" y x="<<BOLDGREEN<<x2<<endl;
		}
	}
	else {//no hay solucion
		cout << BOLDMAGENTA<<"En la ecuacion no hay soluciones"<<endl;
	}


}




 /* *
 * @brief Módulo (main) confeccionar el programa de hacer una ecuacion de segundo grado
 * @version 0.2 
 * @date 2023-17-01
 * @version 0.3 
 * @date 2023-17-01
 * @version 1 -
 * @date 2023-17-01
 * @author Dios-Fer
 */
 
int main (){
	
	double a=0, b=0, c=0;
	double x1=0, x2=0;
	bool sol=false;
	
	Pedida_ecuacion (a, b, c);//introducir los datos
	sol = clasificar_resolver_ecuacion (a, b, c, x1, x2);//obtener el camino para la solucion y la solucion
	Salida_resultado (x1, x2, sol);//mostrar la solucion
	
}


