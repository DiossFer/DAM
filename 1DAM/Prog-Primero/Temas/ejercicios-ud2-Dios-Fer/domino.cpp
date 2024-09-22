#include <iostream>
using namespace std;
int main (){
	
	int numeroI=0, numeroD=0;
	
	for (int i=0; i<=6; i++){
	
		//tenemos i como uno de los lados, este sera el lado principla siendo el que mas cambie j para que se mueva por los dijitos	//j dependsera de i para que no se repitan fichas
		for (int j=i; j<=6; j++){
		
			if (i==0){//Para lo que pide de que 0 este en blanco
			
				if (j==0){
					cout << " " << " | " << " " << endl;
				}
				else{
					cout << " " << " | " << j << endl;
				}
			}
			else{//Para los casos en los que no hay 0
				cout << i << " | " << j << endl;
			}
		}
	}

}
