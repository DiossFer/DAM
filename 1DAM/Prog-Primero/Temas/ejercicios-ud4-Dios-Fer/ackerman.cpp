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
 * @brief Módulo para la salida de un resultado
 * @post mostrara la solucion del problema
 * @param int res (resultado del problema) (S)
 * @version V1
 * @date 2023-1-02
 * @author Dios-Fer
 */
void salida_resultado(int res){
    cout << res << endl;
}



/* *
 * @brief Módulo para la introduccion de dos valores (sin filtros)
 * @post pasara los valores introducidos
 * @param int m dato 1 (E/S)
 * @param int n dato 2 (E/S)
 * @version V1
 * @date 2023-1-02
 * @author Dios-Fer
 */ 
void pedida_datos(int &m, int &n){
    cin >> m;
    cin >> n;
}


/* *
 * @brief Módulo recursivo para el calculo de la funcion ackerman
 * @post dara el resultado de la funcion
 * @pre dos datos filtrados
 * @return sol (solucion)
 * @version V1
 * @date 2023-1-02
 * @author Dios-Fer
 */
 int ackerman (int m, int n){
    int sol=0;

    if (m==0){
        sol=n+1;
    }
    else if (m>0 && n==0){
        sol=ackerman((m-1),1);
    }
    else if (n>0 && m>0){
        sol=ackerman((m-1), (ackerman(m, n-1)));
    }

    return sol;
}



/* *
 * @brief Módulo (main) que conecta modulos para la pedida, realizacion y salida de la funcion ackerman
 * @version V1
 * @date 2023-1-02
 * @author Dios-Fer
 */
int main (){
    int m=0, n=0;
    int res=0;

    pedida_datos(m, n);

    res=ackerman(m, n);

    salida_resultado(res);

}
