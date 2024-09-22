#include <iostream>
using namespace std;
int main (){

bool s=false, p=false;//condicion de muerte 

int poblacion=0; 

int peter=0, stark=0;//posiciones

int intervalo=0;

int casos=0;

do{
	cin >> casos;
	if (casos<0){
		cout << "No puedes hacer casos negativos"<<endl;
	}
	
}while(casos<0);
cout << endl;
for (int caso=1; caso<=casos; caso++){
	//inicializamos
	s=false;
	p=false;


	cout << "================================================"<<endl;
	do{//filtro que pide el enunciado 

		cin >> poblacion;//numero total (n)


		cin >> stark;//posicion stark (s)


		cin >> peter;//posicion peter (p)


		cin >> intervalo;//los que se libran (k)

		if (!(poblacion>=2 && poblacion<=1000)){
			cout << "La poblacion total esta mal introducida"<<endl;
		}
		if (!(stark>=1 && peter>=1 && stark<=poblacion && peter<=poblacion && peter!=stark)){
			cout << "La posicion de Peter o Stark estal mal introducidas"<<endl;
		}
		if (!(intervalo >= 0 && intervalo <= 20)){
			cout << "Intervalo mal introducido"<<endl;
		}
		
		cout << "================================================"<<endl<<endl;
		
	}while (!(stark>=1 && peter>=1 && stark<=poblacion && peter<=poblacion && peter!=stark) && !(poblacion>=2 && poblacion<=1000) && !(intervalo >= 0 && intervalo <= 20));


	intervalo++; //si saltamos 2 es el tercero el que muere
	int siguiente=0;
	
	if ((poblacion % 2)!=0){//si es impar tiramos uno por encima	
	poblacion++;
	}
	
	for (int contador_m=0; contador_m != poblacion/2;contador_m++){	



		siguiente+=intervalo;
		
		if (siguiente > poblacion){//reinicio del circulo
			siguiente = poblacion-siguiente;
		}
		
		//condiciones de vida
		if (siguiente==stark){
			s=true;
		}
		
		if (siguiente==peter){
			p=true;
		}



	}
		//salidas
		if ((s==true && p==true) || (s==false && p==false)){
			cout << "No hay abrazo" << endl<<endl;
		}
		
		else if (s==false && p==true){
			cout << "No quiero irme, Sr. Stark!" << endl<<endl;
		}
		
		else if (s==true && p==false){
			cout << "No quiero irme, Peter!" << endl<<endl;
		}
		
		
}
}
