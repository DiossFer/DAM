#ifndef VALORACION_H
#define VALORACION_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/

#include "Ingrediente.h"
#include "Producto.h"
#include "Cliente.h"
#include "Pedido.h"
#include "color.h"


/************************/


using namespace std;


/************************/


const bool DEBUG_Valoracion=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------- /  Valoracion  / ------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Valoracion{

    private:
        string id_val;
        int estrellas;
        Producto *p_val;
        Cliente *c_val;

    public:

        ///Métodos
        

        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo constructor para un objeto de tipo Valoracion
         * @post se construira el objeto
         * @author DiosFer
         */
        Valoracion();


        /**
         * @brief modulo constructor por copia para un objeto de tipo Valoracion
         * @param const Valoracion &v
         * @post se construira el objeto
         * @author DiosFer
         */
        Valoracion(const Valoracion &v);

        /**
         * @brief modulo constructor por parametros para un objeto de tipo Valoracion
         * @post se construira el objeto
         * @author DiosFer
         */
        Valoracion(string id_val, int estrellas, Producto*un_p, Cliente *un_c);
        
        /**
         * @brief modulo destructor para un objeto de tipo Valoracion
         * @post se destruira el objeto
         * @author DiosFer
         */
        ~Valoracion();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo get para el atributo id_val
         * @return string id_val
         * @author DiosFer
         */
        string get_id_val() const;


        /**
         * @brief modulo get para el atributo estrellas_val
         * @return int estrellas_val
         * @author DiosFer
         */
        int get_estrellas_val() const;

        /**
         * @brief modulo get para el atributo cliente_val
         * @return Cliente* cliente_val
         * @author DiosFer
         */
        Cliente* get_cliente_val() const;


        /**
         * @brief modulo get para el atributo cliente_val
         * @return Producto* producto_val
         * @author DiosFer
         */
        Producto* get_producto_val() const;


        
        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo set para el atributo id_val
         * @param string id
         * @author DiosFer
         */
        void set_id_val(string id);


        /**
         * @brief modulo set para el atributo estrellas_val
         * @param int e
         * @author DiosFer
         */
        void set_estrellas_val(int e);

        /**
         * @brief modulo set para el atributo cliente_val
         * @param Cliente* un_c
         * @author DiosFer
         */
        void set_cliente_val(Cliente *un_c);


        /**
         * @brief modulo set para el atributo cliente_val
         * @param Producto* un_p
         * @author DiosFer
         */
        void set_producto_val(Producto *un_p);


        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para imprimir una valoracion por pantalla
         * @post se imprimira la valoracion
         * @author DiosFer
         */
        void print ();

        /**
         * @brief modulo para introducir una valoracion por pantalla
         * @post se introducira los valores a la valoracion
         * @author DiosFer
         */
        void introducir ();

        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para igualar una valoracion
         * @post se igualara una valoracion a otra
         * @author DiosFer
         */
       Valoracion operator=(const Valoracion &v);




};

#endif