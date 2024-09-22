#include <iostream>
using namespace std;

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
 * @brief Módulo (main) para la seleccion de numero de alumnos, para la entrada de datos (sin filtro), calculo y salida para la media de las notas correspondientes
 * @version V1V1
 * @date 2023-26-01
 * @author Dios-Fer
 */
int main (){

   const int NUMERO_MAX_DE_NOTAS = 100;
   double notas [NUMERO_MAX_DE_NOTAS]={0}; 
   double media=0;
   int util_notas=0;

   do {

      cout <<BOLDYELLOW<< "Introduzca el numero de alumnos, recuerde que contamos con un maximo de 100: ";
      cin >> util_notas;
      cout << endl << RESET;
   }while(util_notas<1 || util_notas>100);

    for (int i=0; i<util_notas; i++){
    
       cout <<BOLDYELLOW<< "Inserete nota nº" << i+1 <<": ";//ya que es una salida no usare el 0 como numero de nota
       
       cin >> notas [i];
       
    }


    for (int i=0; i<util_notas; i++){
       media = media + notas [i];
    }
    
    media = media / util_notas;
    
    cout <<endl<<BOLDBLUE<< "La meida de tus notas introducidas es: " <<BOLDCYAN<<media << endl<<RESET<<endl; 
    
}
