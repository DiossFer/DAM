#ifndef DK
#define DK

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/


#include "Producto.h"


#include "Refresco.h"

#include "Pizza.h"


#include "Ingrediente.h"


/************************/


#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define OK "\033[1;32m"
#define DEBUG "\033[1;34m"


//////////////////////////


#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define gray "\033[0;37m"                  /* gray */


//////////////////////////


#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"


//////////////////////////


#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"


/************************/


using namespace std;


/************************/


const bool DEBUG_DK=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*--------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  DominusKing  / ----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/


class DominusKing{
    private:

        ///Atributos

        /// Pendiente ///
        string id_tienda;

        string login_admin;
        string pass_admin;

/*

        Cliente* clientes_sistema;
        int total_clientes_sistema;

        Producto* productos_sistema;
        int total_productos_sistema;

*/

        Ingrediente* ingredientes_sistema;
        int total_ingredientes_sistema;



    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/
        
        /**
         * @brief modulo constructor para un objeto de tipo DominusKing
         * @post se construira el objeto
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        DominusKing();

        /**
         * @brief modulo destructor para un objeto de tipo DominusKing
         * @post se destruira el objeto
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        ~DominusKing();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo get para obtener el total de ingredientes del sistema
         * @return Int total
         * @post se obtendra el dato
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        int get_total_ingredientes_sistema();


        /**
         * @brief modulo get para obtener un ingrediente de una posicion concreta del vcetor de ingredientes del sistema
         * @param int posicion
         * @return Ingrediene
         * @post se obtendra el dato
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        Ingrediente get_ingrediente_sistema(int posicion);

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief modulo set para el total de ingredientes del sistema
         * @param int i
         * @post se actualizara el atributo
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        void set_total_ingredientes_sistema(int i);

        /**
         * @brief modulo set para introducir un ingrediente en el vector de ingredientes del sistema
         * @param Ingrediente ig
         * @post se añadira el ingrediente en el vcetor
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        void set_ingrediente_vector_ingrediente(const Ingrediente &ig);


        
        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/
/*
        menu_admin();
        menu_usuario();
*/

/*
        nuevoPedido();
        nuevoCliente();
*/
        /**
         * @brief modulo para crear e introducir un ingrediente en el vector de ingredientes del sistema
         * @post se introducira en el vector el ingrediente
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        void nuevoIngrediente();

        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo Para crear un vector de ingredientes
         * @return Ingrediente* 
         * @param int dim
         * @post se declarara en el heap el vetor
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        Ingrediente* create_vector_ingredientes(int dim);


         /**
         * @brief modulo resizear un vector de ingredientes del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        void resize_vector_ingrediente(int new_dim);

};

#endif