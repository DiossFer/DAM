#ifndef POLINOMIO_h
#define POLINOMIO_h

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define OK "\033[1;32m"
#define DEBUG "\033[1;34m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define gray "\033[0;37m"                  /* gray */


const bool DEBUG_C_Polinomio=true;



/*-------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  Polinomio  / -----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Polinomio{
    private:

        ///Atributos

        float* coef; //vector de coeficientes del polinomio

        int grado_actual; //grado actual que tiene el polinomio

        int grado_max; //coincide con la DIM del VECTOR DE COEFICIENTES - 1



    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief Constructor del objeto Polinomio: reserva por defecto un vector de coeficientes de dimensión 10, de tal manera que el máximo grado permitido será 9. Todos los coeficientes tendrán como valor 0.0. Y el grado_actual será por lo tanto 0.
         * @post El objeto Polinomio estará construido con la memoria del vector reservada y los valores por defecto.
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        Polinomio();


        /**
         * @brief Constructor del objeto Polinomio: creara un polinomio con los valores de otro
         * @param const Polinomio &p polinomio del que se quiere partir
         * @post El objeto Polinomio estará construido con con los mimos valores que el introducido
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        Polinomio(const Polinomio &p);

        /**
         * @brief Destructor del objeto Polinomio: reserva por defecto un vector de coeficientes de dimensión 10, de tal manera que el máximo grado permitido será 9. Todos los coeficientes tendrán como valor 0.0. Y el grado_actual será por lo tanto 0.
         * @post El objeto Polinomio se destruira junto a la reserva de memoria
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        ~Polinomio();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

    

        /**
         * @brief modulo (get) para el atributo grado_actual de un Polinomio
         * @return int grado_actual
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        int getGrado() const;

        /**
         * @brief modulo (get) para el atributo grado_max de un Polinomio
         * @return int grado_max
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        int getMaxGrado() const;

        /**
         * @brief modulo (get) para el atributo coef de un Polinomio en un grado especifico
         * @param int grado 
         * @return *coef
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        float getCoef(int grado) const;

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/
    private:
        /**
         * @brief modulo (set) para el atributo grado_actual de un Polinomio
         * @param int nuevo_grado
         * @pre el grado debe de ser positivo
         * @post se actualizara el grado_actual del polinomio
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void setGrado(int nuevo_grado);

        /**
         * @brief modulo (set) para el atributo grado_max de un Polinomio
         * @param int nuevo_grado_max
         * @post se actualizara el grado_max del polinomio
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        void setMaxGrado(int nuevo_grado_max);


    public:

        /**
         * @brief modulo (set) para el coeficiente indicando el grado donde se introducira
         * @param int grado
         * @param float coeficiente
         * @post en la posicion grado del vector se habra introducido el coeficiente
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void setCoeficiente_V2(int grado, float coeficiente);


        /**
         * @brief modulo (set) para el coeficiente indicando el grado donde se introducira
         * @param int grado
         * @param float coeficiente
         * @post en la posicion grado del vector se habra introducido el coeficiente
         * @date 2023-5-16
         * @version 1.2
         * @author DiosFer
         */
        void setCoeficiente_V3(int grado, float coeficiente);

        
        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/


        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/
    private:

        /**
         * @brief modulo para redimensionar el atributo vector coef
         * @post se mantendran los mismos datos del vector pero con una dimension (y maxgrado) aumentada
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void resize_Coef(int new_dim);


        public:

        /**
         * @brief modulo para copiar en este polinomio otro polinomio introducido
         * @post se obtendra un polinomio exactamente igual que el introducido 
         * @param Polinomio *p
         * @date 2023-5-6
         * @version 0.5
         * @author DiosFer
         */
        void CopiarPolinomio(Polinomio *p);


        
        /**
         * @brief modulo para sumar dos polinomios y guardar el resultado en el que hace la llamada                             ///V1
         * @pre grado=maxGrado (uso de la v3 en los sets) 
         * @post se modificara el polinomio a la solucion, perdiendo el polinomio original 
         * @param const Polinomio &p2
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        void sumar(const Polinomio &p2);


        /**
         * @brief modulo para sumar dos polinomios externos y guardar el resultado en el que hace la llamada                    ///V2
         * @pre el polinomio estara vacio
         * @post se modificara el polinomio a la solucion, perdiendo el polinomio original 
         * @param const Polinomio &p2
         * @param const Polinomio &p3
         * @date 2023-5-9
         * @version 0.7
         * @author DiosFer
         */
        void sumar(const Polinomio &p2,const Polinomio &p3);



        /**
         * @brief modulo para sumar un polinomio y otro externo y dar el resultado                                              ///V3
         * @post se dara el resultado 
         * @post se mantendran los polinomios intactos
         * @param const Polinomio &p2
         * @return polinomio
         * @date 2023-5-14
         * @version 0.9.1
         * @author DiosFer
         */
        Polinomio operator+(const Polinomio &p2);

        /**
         * @brief modulo para sumar un polinomio por puntero y otro polinomio por puntero y dar un puntero de polinomio         ///V4
         * @post se dara el resultado 
         * @post se mantendran los polinomios intactos
         * @param const Polinomio &p2
         * @return polinomio*
         * @date 2023-5-14
         * @version 0.9.1
         * @author DiosFer
         */
        Polinomio* operator+(const Polinomio *p2);


        /**
         * @brief modulo para igualar un polinomio a otro
         * @post el Polinomio que realice la llamada tomara los valores del que se iguale 
         * @return Polinomio&
         * @param const Polinomio &p
         * @date 2023-5-15
         * @version 1.1
         * @author DiosFer
         */
        Polinomio& operator=(const Polinomio &p);


        /**
         * @brief modulo para igualar un polinomio a otro
         * @post el Polinomio que realice la llamada tomara los valores del que se iguale 
         * @return Polinomio*
         * @param const Polinomio *p
         * @date 2023-5-15
         * @version 1.1
         * @author DiosFer
         */
        Polinomio* operator=(const Polinomio *p);

        /**
         * @brief modulo para inicializar a 0 un polinomio
         * @post se pondran los coeficientes, grado y max_grado a 0 (con el redimensionamiento adecuado)
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        void inicializarPolinomio();


    private:

        /**
         * @brief modulo para buscar el nuevo grado mas grande de un vector de coeficientes
         * @return int grado
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        int calcularGrado();


        /**************************************************************************************************************************************
        ***************************************************** -  VectorFloat-Prototipos  - ****************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para crear un vector de float con una dimension concreta
         * @post se reservara la memoria del vector en el heap
         * @return float* 
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        float* crear_vector_float (int dim);


        /**
         * @brief modulo para elimniar un vector float 
         * @post se limpiara la memoria reservada y se anulara el puntero
         * @return float* 
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        float* dropVectorFloat(float *v);

        /**
         * @brief modulo para copiar un vcetor de float (solo en caso de caber en el vector (util_copiado<dim_copia))
         * @post se copiaran los paramtros de v* en new_v*
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void copiarVectorFloatConEspacio (float v[], int util_v, float new_v[], int new_dim_v);
                
        /**
         * @brief modulo (frien) para la salida de un polinomio por medio de un cout
         * @post se mostrara por pantalla el polinomio en su posicion de cout
         * @date 2023-5-15
         * @version 1.1
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, const Polinomio &p);

        /**
         * @brief modulo (frien) para la entrada de un polinomio
         * @post guardara lo introducido en el polinomio 
         * @date 2023-5-16
         * @version 1.2
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Polinomio &p);

};


#endif