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
 * @brief Módulo para la salida de los resultados
 * @param media
 * @param desviacion
 * @param varianza
 * @param desviacion_tipica
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
void salida_datos(double media, double desviacion, double varianza, double desviacion_tipica){
   cout<<endl<<BOLDBLUE<< "La media de tus notas introducidas es: " <<BOLDCYAN<<media<<RESET<<endl; 
   cout<<BOLDBLUE<< "La desviacion media de tus notas introducidas es: " <<BOLDCYAN<<desviacion<<RESET<<endl; 
   cout<<BOLDBLUE<< "La varianza de tus notas introducidas es: " <<BOLDCYAN<<varianza << endl<<RESET;
   cout<<BOLDBLUE<< "La desviacion tipica de tus notas introducidas es: " <<BOLDCYAN<<desviacion_tipica << endl<<RESET<<endl; 
}  



/* *
 * @brief Módulo para el calculo de la media
 * @param util_notas util del vecto notas
 * @param notas[] vector que guarda un maximo de 100 notas
 * @return media
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double media_vector(double notas[], int util_notas){
   double media=0.0;
   for (int i=0; i<util_notas; i++){//calcular media
      media = media + notas [i];
   }
   media = media / util_notas;

   return media;
}



/* *
 * @brief Módulo para el calculo de la desviacion media
 * @param util_notas util del vector notas
 * @param notas[] 
 * @param double media dato para el calculo
 * @return desviacion (media)
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double desviacion_vector(double notas[], int util_notas, double media){
   double desviacion=0.0;
   for (int i=0; i<util_notas; i++){//calcular desviacion
      desviacion = desviacion + fabs (notas[i]-media);
   }
   desviacion = desviacion / util_notas;

   return desviacion;
}



/* *
 * @brief Módulo para el calculo de la desviacion tipica
 * @param util_notas util del vector notas
 * @param notas[] vector 
 * @param double varianza dato para el calculo
 * @return desviacion_tipica
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double desviacion_tipica_vector(double notas[], int util_notas, double varianza){
   double desviacion_tipica=0.0;

   desviacion_tipica=sqrt (varianza);

   return desviacion_tipica;
}


/* *
 * @brief Módulo para el calculo de la varianza
 * @param util_notas util del vector notas
 * @param notas[] vector 
 * @param double media dato para el calculo
 * @return varianza
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
double varianza_vector(double notas[], int util_notas, double media){
   double varianza=0.0;
   for (int i=0; i<util_notas; i++){
      varianza = varianza + ((notas[i]-media) * (notas[i]-media));
   }
   varianza = varianza / util_notas;

   return varianza;
}


/* *
 * @brief Módulo para pedir el numero de notas y las notas
 * @param util_notas util del vector notas
 * @param notas[] vector que guarda un maximo de 100 notas
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
void pedida_datos (int &util_notas, double notas[]){

   do {//Numero de alumnos

      cout <<BOLDYELLOW<< "Introduzca el numero de alumnos, recuerde que contamos con un maximo de 100: ";
      cin >> util_notas;
      cout << endl << RESET;
   }while(util_notas<1 || util_notas>100);

   for (int i=0; i<util_notas; i++){//entrada de datos
    
      cout <<BOLDYELLOW<< "Inserete nota nº" << i+1 <<": ";//ya que es una salida no usare el 0 como numero de nota
       
      cin >> notas [i];
   }

}


/* *
 * @brief Módulo (main) para montar el programa de calcular_meda_desviacion_varianza_desviaciontipica
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
int main (){

   const int NUMERO_MAX_DE_NOTAS = 100;
   double notas [NUMERO_MAX_DE_NOTAS]={0.0}; 
   double media=0.0;
   int util_notas=0;
   double desviacion=0.0;
   double varianza=0.0;
   double desviacion_tipica=0.0;



   pedida_datos(util_notas, notas);


   media=media_vector(notas, util_notas);

   desviacion=desviacion_vector(notas, util_notas, media);

   varianza=varianza_vector(notas, util_notas, media);

   desviacion_tipica=desviacion_tipica_vector(notas, util_notas, varianza);
   

   salida_datos(media, desviacion, varianza, desviacion_tipica);

}
