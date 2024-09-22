#include <iostream>
#include <cmath>
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
 * @brief Módulo (main) para calcular la media, desviacion y varianza de una serie de notas introducidas (no mas de 100)
 * @post mostrara por pantalla los tres resultados
 * @version V1
 * @date 2023-26-01
 * @author Dios-Fer
 */
int main (){

   const int NUMERO_MAX_DE_NOTAS = 100;
   double notas [NUMERO_MAX_DE_NOTAS]={0.0}; 
   double media=0.0;
   int util_notas=0;
   double desviacion=0.0;
   double varianza=0.0;

   do {//Numero de alumnos

      cout <<BOLDYELLOW<< "Introduzca el numero de alumnos, recuerde que contamos con un maximo de 100: ";
      cin >> util_notas;
      cout << endl << RESET;
   }while(util_notas<1 || util_notas>100);

   for (int i=0; i<util_notas; i++){//entrada de datos
    
      cout <<BOLDYELLOW<< "Inserete nota nº" << i+1 <<": ";//ya que es una salida no usare el 0 como numero de nota
       
      cin >> notas [i];
   }


   for (int i=0; i<util_notas; i++){//calcular media
      media = media + notas [i];
   }
   media = media / util_notas;


   for (int i=0; i<util_notas; i++){//calcular desviacion
      desviacion = desviacion + fabs (notas[i]-media);
   }
   desviacion = desviacion / util_notas;


   for (int i=0; i<util_notas; i++){
      varianza = varianza + ((notas[i]-media) * (notas[i]-media));
   }
   varianza = varianza / util_notas;

   //salidas    
   cout<<endl<<BOLDBLUE<< "La media de tus notas introducidas es: " <<BOLDCYAN<<media<<RESET<<endl; 
   cout<<BOLDBLUE<< "La desviacion de tus notas introducidas es: " <<BOLDCYAN<<desviacion<<RESET<<endl; 
   cout<<BOLDBLUE<< "La varianza de tus notas introducidas es: " <<BOLDCYAN<<varianza << endl<<RESET<<endl;     
}
