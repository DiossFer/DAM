#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/


#include "Producto.h"
#include "Ingrediente.h"
#include "color.h"


/************************/


using namespace std;


/************************/


const bool DEBUG_pizza=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*--------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------- /  Pizza  / -------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Pizza : public Producto{
    private:

        ///Atributos

            
        string tipo_pizza;

        Ingrediente** vetorIngredientes;

        int total_ingredientes_pizza;

        float preciobase_sin_iva;

    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/
       /**
         * @brief modulo constructor para un objeto de tipo pizza
         * @post se construira el objeto
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        Pizza();

        /**
         * @brief modulo constructor por copia 
         * @post se construira el objeto a partir del otro
         * @date 2023-5-26
         * @version 0.7
         * @author DiosFer
         */
        Pizza(const Pizza &p);


        /**
         * @brief modulo constructor por parametros 
         * @post se construira el objeto a partir de los parametros
         * @pre los parametros que no se ponen pues se actualizan solos o no son necesarios ahora se pondran a 0 o ""
         * @date 2023-5-26
         * @version 0.8
         * @author DiosFer
         */
        Pizza(const string id_producto, const string nombre, const string tamano, const int porcentaje_iva_producto, const float precio_base, const bool a, const string tipo);


        /**
         * @brief modulo destructor para un objeto de tipo pizza
         * @post se destruira el objeto
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        ~Pizza();

        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

       /**
         * @brief modulo get para el tipo de una pizza
         * @return string tipo
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        string get_tipo_pizza () const;


        /**
         * @brief modulo get para el ttotal de ingredientes de una pizza
         * @return int total
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        int get_total_ingredientes_pizza () const;

        /**
         * @brief modulo get para el puntero de una posicion del puntero a punteros de ingredientes
         * @param posicion
         * @return Ingrediente* i
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        Ingrediente* get_Ingrediente_pizza (int posicion) const;


        /**
         * @brief modulo get para el atributo preciobase_sin_iva del objeto pizza
         * @post se obtendra el atributo
         * @return float preciobase
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        float get_preciobase_sin_iva() const;

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

       /**
         * @brief modulo set para el atributo tipo de una pizza
         * @param string tipo
         * @post se actualizara el atributo
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        void set_tipo_pizza (string tipo);


        /**
         * @brief modulo set para el atributo total ingredientes pizza
         * @param int total
         * @post se actualizara el atributo
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        void set_total_ingredientes_pizza (int total);
        

        /**
         * @brief modulo set para una de las posiciones del vector de ingredientes de pizza
         * @param Ingrediente* i
         * @post se actualizara el atributo, actualizara tambien los precios y el numero de usos del ingrediente
         * @date 2023-5-26
         * @version 0.8
         * @author DiosFer
         */
        void set_Ingrediente_pizza (Ingrediente* i);

        /**
         * @brief modulo set para el atributo preciobase_sin_iva del objeto pizza
         * @post se actualizara el atributo
         * @param float precio
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_preciobase_sin_iva(const float precio);

        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo amigo para realizar la salida de un objeto de tipo Pizza
         * @post se mostraran los datos por pantalla 
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, const Pizza &p);
        void print ();


        /**
         * @brief modulo amigo para realizar la entrada de un objeto de tipo Pizza
         * @post se introduciran por pantalla los datos
         * NOTA: no se introduciran los ingredientes
         * @date 2023-5-26
         * @version 0.8
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Pizza &p);
        void introducir();


        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/
   
        /**
         * @brief modulo para copiar una pizza en otra
         * @param const Pizza &p
         * @post se actualizara el objeto
         * @pre el objeto que llama debe de estar vacio
         * @date 2023-5-26
         * @version 0.7
         * @author DiosFer
         */
        Pizza operator=(const Pizza &p);
        
    private:
        /**
         * @brief modulo para hacer resize de un vector de punteros a ingredientes 
         * @param int new_dim
         * @post se realizara el resize
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        void resize_vector_ptr_Ingredientes(int new_dim);

    public:
        /**
         * @brief modulo para crear un vector de punteros a punteros de ingredientes
         * @param int dim
         * @return Ingrediente** 
         * @post se realizara el resize
         * @date 2023-5-25
         * @version 0.4
         * @author DiosFer
         */
        Ingrediente** create_vector_ptr_ingredientes(int dim);


        /**
         * @brief modulo para comparar dos pizzas 
         *        (se tomara de todo lo que se puede introducir unicamente lo que elijiria un cliente 
         *        (tamaño (en un sistema real con un filtro en condiciones se daria a elegir pequeño mediano o grande) e 
         *        ingredientes (tanteo en numero como en si son los mismos independiente del orden)), 
         *        el resto de cosas no se tienen en cuenta pues en un sistema de verdad se generaria automatico)
         * @param const Pizza &p
         * @return bool igual
         * @date 2023-6-3
         * @version 2.2
         * @author DiosFer
         */
        bool operator==(const Pizza &p) const;

          /**
         * @brief modulo para quitar un ingrediente de una pizza resizeando ademas hacia abajo el vector
         * @param int posicion
         * @post se obtendra el vector sin el ingrediente seleccionado
         * @author DiosFer
         */
        void quitar_ingrediente(int posicion);

};

#endif