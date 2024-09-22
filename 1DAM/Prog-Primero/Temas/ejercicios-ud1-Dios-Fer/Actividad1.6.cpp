#include <iostream>
using namespace std;
int main (){
	double precio, pagado;
	int centimos;
	cout << "Escriba precio y dinero entregado";
	cin >> precio>>pagado;
	centimos = 100 * (pagado-precio);
	cout << "Hay que devolber: " << centimos << " centimos" <<endl;
//Devuelve 46 centimos, la diferencia entre el libro y mi programa es que en versiones mas antiguas da 45 al igual que en el libro, esto por que truncan en vez de aproximar, al usar el double le añadimos esos decimales y junto con la basura que ya habia termina saliendo otro resultado, mientras que en versiones mas modernas el resultado es corrcto. Una posible solucion para esto es poner los centimos tambien como double para mayor exactitud e inicializar todo a 0.0
//El programa fallara en ejecucion si grande o muy pequeño, pues no estara comprendido, acabara truncando caracteres y dando resultados erroneos; otra opccion para que falle es poner una letra o simbolo, recordemos que nuestro programa solo admite numeros.
}

