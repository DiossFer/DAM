#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include <time.h>

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
 * @brief Módulo para mostrar por pantalla la secuencia de fibonacci de manera iterativa
 * @post mostrara por pantalla hasta donde halla introducido el usuario
 * @pre veces>1
 * @version V1
 * @date 2023-30-01
 * @author Dios-Fer
 */
void fibonacci_iterativo(int veces){
    int anterior=1, anterior_anterior=1, res=0;
    cout << BOLDYELLOW << anterior << " ";

    for (veces; veces>1; veces--){

        cout << anterior<<" ";

        res=anterior+anterior_anterior;
        anterior_anterior=anterior;
        anterior=res;

        
    }
    cout << endl;
}


/* *
 * @brief Módulo para mostrar por pantalla la secuencia de fibonacci de manera recursiva
 * @post mostrara por pantalla hasta donde halla introducido el usuario
 * @pre veces>1
 * @version V1
 * @date 2023-30-01
 * @author Dios-Fer
 */
void fibonacci_recursivo(int res, int anterior, int anterior_anterior, int veces){

    res=anterior+anterior_anterior;
    anterior_anterior=anterior;
    anterior=res;

    cout <<BOLDBLUE<<res << " ";

    veces--;
    if (veces>1){
        fibonacci_recursivo (res, anterior, anterior_anterior, veces);
    }


}

/* *
 * @brief Módulo (main) para medir y llamar los tiempos de la ejecucion iterativa y recursiva de la secuencia de fibonacci
 * @post mostrara los tiempos de las dos ejecuciones
 * @version V1
 * @date 2023-30-01
 * @author Dios-Fer
 */
int main(){
    int veces = 0, anterior=1, anterior_anterior=0, res=0;
    bool numero=false;


    //VARIABLES PARA MEDIR TIEMPOS
    clock_t t_iniIter, t_finIter, t_iniRecur, t_finRecur;
    double secsRecur,secsIter;
    

    do{//filtro < 2 y sin letras
        numero=true;

        cout << "¿Cuantos valores de la secuencia de fibonacci quiere?: " << endl;
        cin >> veces;

        if(cin.fail()==1){//filtro para letras
            cin.clear();
            cin.ignore(10000, '\n');
            cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;
            numero=false;
        }

        else if (veces<2){
            numero=false;
            cout << BOLDRED << "Has introducido mal algun numero"<<RESET<<endl<<endl;

        }

    }while(numero==false);
    cout <<endl;



    //iterativo
    t_iniIter = clock();
    fibonacci_iterativo(veces);
    t_finIter = clock();
    


    //Operación de conversión a mili segundos
   secsIter = (double)(t_finIter - t_iniIter) / CLOCKS_PER_SEC;
   cout  << RESET << "Tiempo de Algoritmo Iterativo:\t" << fixed << setprecision(16) << BOLDYELLOW <<  secsIter  << endl;
   cout << endl;
        

    //recursivo
    t_iniRecur = clock();
    cout << BOLDBLUE << anterior << " ";
    fibonacci_recursivo (res, anterior, anterior_anterior, veces);
    cout << endl;
    t_finRecur = clock();
    



    //Operación de conversión a mili segundos
    secsRecur = (double)(t_finRecur - t_iniRecur) / CLOCKS_PER_SEC;
    cout  << RESET << "Tiempo de Algoritmo Recursivo:\t" << fixed << setprecision(16) << BOLDBLUE <<  secsRecur  << RESET << endl;
    cout << endl;

}
