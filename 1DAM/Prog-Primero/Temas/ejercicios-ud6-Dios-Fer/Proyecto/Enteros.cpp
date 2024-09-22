#include <iostream>
#include "Enteros.h"

#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define gray "\033[0;37m"                  /* gray */

using namespace std;


/***************************************************************************************************************************************
                                                           * Modulos Tipo int *
 ***************************************************************************************************************************************/



int introducir_int_filtrado (const char mensaje_entrada[], int NoMenorA, int NoMayorA, const char mensaje_error[]){
    int numero=0;
    bool EstaBien=true;

    

    do{

        EstaBien=true;
        cout << mensaje_entrada;
        cin>>numero;

        if (numero<=NoMenorA || numero>=NoMayorA){
            EstaBien=false;
            cout << mensaje_error<<endl<<endl;
        }

        if(cin.fail()==1){

            cin.clear();
            cin.ignore(10000, '\n');

            cout << BOLDRED << "Por favor introduzca un numero"<<RESET<<endl<<endl;
            EstaBien=false;

        }


    }while(EstaBien==false);

    return numero;
}