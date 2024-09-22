#ifndef vista_h
#define vista_h

#include "polinomio.h"

const bool DEBUG_C_Vista=true;



/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------- /  Vista  / --------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Vista{
    private:

        ///Atributos

        bool salir;

        Polinomio* vector_polinomios;


        int total_polinomios;//La util sera igual a la dimension //estilo el grado con el max_grado


    public:

        ///Métodos

        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/
    

        /**
         * @brief modulo (constructor) para el objeto Vista
         * @post se creara el objeto y sus atributos (tanto estatico como dinamico) ademas de inicializarse
         * @date 2023-5-18
         * @version 1.4
         * @author DiosFer
         */
        Vista();


        /**
         * @brief modulo (destructor) para el objeto Vista
         * @post destruira el objeto Vista
         * @date 2023-5-18
         * @version 1.4
         * @author DiosFer
         */
        ~Vista();


        /**************************************************************************************************************************************
        ************************************************************* -  SET's  - *************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief modulo (set) para el atributo bool salir del objeto vista
         * @param bool new_status
         * @post se actualizara el atributo salida
         * @date 2023-5-18
         * @version 1.4
         * @author DiosFer
         */
        void set_salida(bool new_status);


        /**
         * @brief modulo (set) para el atributo int total_polinomios del objeto vista
         * @param int new_total
         * @post se actualizara el atributo total_polinomios
         * @date 2023-5-18
         * @version 1.5
         * @author DiosFer
         */
        void set_total_polinomios (int new_total);


        /**
         * @brief modulo (set) para introducir un polinomio en una nueva posicion al final del vector de polinomios
         * @param Polinomio p
         * @post se introducira el Polinomio
         * @date 2023-5-18
         * @version 1.5
         * @author DiosFer
         */
        void set_Polinomio_vista (Polinomio p);


        /**************************************************************************************************************************************
        ************************************************************* -  GET's  - *************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief modulo (get) para el atributo bool salir del objeto vista
         * @return bool salir
         * @date 2023-5-18
         * @version 1.4
         * @author DiosFer
         */
        bool get_salida();


        /**
         * @brief modulo (get) para el atributo int total_polinomios del objeto vista
         * @return int total_polinomios
         * @date 2023-5-18
         * @version 1.4
         * @author DiosFer
         */
        int get_total_polinomios ();


        /**
         * @brief modulo (get) para un polinomio del vector de polinomios
         * @param int posicion
         * @return Polinomio p
         * @date 2023-5-18
         * @version 1.4
         * @author DiosFer
         */
        Polinomio get_Polinomio_vista (int posicion);


        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief modulo para dar la bienvenida al programa y poner la salida a false
         * @post se pondra salida a false y se mostrara por pantalla un mensaje
         * @date 2023-5-18
         * @version 1.4
         * @author DiosFer
         */
        void bienvenida();


        /**
         * @brief modulo para acceder al menu 
         * @post se accedera al menu con todas sus funcionalidades
         * @date 2023-5-18
         * @version 1.5
         * @author DiosFer
         */
        void menu();


        /**
         * @brief modulo para imprimir por pantalla un vector de polinomios del objeto vista
         * @post se mostrara por pantalla el vector
         * @date 2023-5-18
         * @version 1.5
         * @author DiosFer
         */
        void print();


        
        /**
         * @brief para realizar una suma y obtener un resultado con la composicion de pedida de dos polinomios y obtencion de resultado con opcion de guardarlo
         *          actualmente y ya que no hemos especificado el como hacerlo o si es que se tiene que hacer he decidido hacer una especie de calculadora donde metes dos polinomios auxiliares 
         *          y recibes un resultado que puedes decidir si guardar o no en el vector
         * @post se guardara el resultado en caso de quererlo el usuario
         * @date 2023-5-19
         * @version 2.0
         * @author DiosFer
         */
        void suma_vista();

        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para eliminar una posicion del vector de polinomios
         * @post se eliminara la posicion y se realizara el resize del vector
         * @date 2023-5-19
         * @version 2.0
         * @author DiosFer
         */
        void elimniar_posicion(int i);


        /**
         * @brief modulo para hacer el resize de un vector de polinomios en una posicion 
         * @param int new_dim   //this->get_total_polinomios
         * @post se obtendra un vector con menor dimension o mayor dimension en funcion de si se elimina o crea un nuevo polinomioi
         * @date 2023-5-18
         * @version 1.5
         * @author DiosFer
         */
        void resize_vector_polinomios (int new_dim);


};




#endif