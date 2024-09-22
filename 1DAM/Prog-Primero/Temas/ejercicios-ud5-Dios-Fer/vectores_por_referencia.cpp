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
 * @brief Módulo para imprimir un vector
 * @post mostrara por pantalla un vector
 * @param int v[] vector a mostrar
 * @param int util_v (util del vector)
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
void imprime_vector(int v[], int util_v){
    for (int i=0; i<util_v; i++){
        cout <<BOLDBLUE<< v[i]<<" ";
    }
    cout << endl<<RESET;
}


/* *
 * @brief Módulo para duplicar los valores de un vector
 * @post duplicara el vector introducido
 * @param int v[] vector a duplicar
 * @param int util_v (util del vector)
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
void calcular_doble_vector (int v[], int util_v){
    for (int i=0; i<util_v; i++){
        v[i] *= 2;
    }
}


/* *
 * @brief Módulo (main) para conectar entrada calculo y salida para duplicar un vector (Sin entrada)
 * @version V1
 * @date 2023-02-02
 * @author Dios-Fer
 */
int main (){
    const int DIM_VECTOR = 5;
    int vector[DIM_VECTOR]={4, 2, 7};
    int util_vector=3;
    imprime_vector(vector, util_vector);
    calcular_doble_vector(vector, util_vector);
    imprime_vector(vector, util_vector);
}