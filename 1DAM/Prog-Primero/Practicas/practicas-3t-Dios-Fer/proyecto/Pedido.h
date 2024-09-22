#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/


#include "Producto.h"
#include "Time.h"
#include "color.h"

/************************/


using namespace std;


/************************/


const bool DEBUG_Pedido=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------ /  Pedido  / --------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Pedido{
    private:

        string id_pedido;

        Fecha fecha_pedido;

        Hora hora_pedido;

        Producto** vector_productos_pedido;

        int total_productos_pedido;

        float total_precio_pedido_sin_iva;

        float total_precio_pedido_con_iva;

        string estado;

        bool cancelable;


    public:

        ///Métodos

        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/
            
        /**
         * @brief modulo constructor del objeto Pedido 
         * @post se construira el objeto Pedido
         * @date 2023-5-27
         * @version 0.9.2
         * @author DiosFer
         */
        Pedido();

        /**
         * @brief modulo 
         * @post 
         * @date 2023-5-27
         * @version 0.9.2
         * @author DiosFer
         */
        Pedido(const Pedido &p);


        /**
         * @brief modulo constructor de un objeto Pedido por parametros
         * @post se construira el objeto de clase Pedido
         * @date 2023-5-27
         * @version 0.9.2
         * @author DiosFer
         */
        Pedido(string id, int dia, int mes, int anio, int hora, int minutos, int segundos);


        /**
         * @brief modulo destructo de un objeto de clase pedido
         * @post se destruira el objeto
         * @date 2023-5-27
         * @version 0.9.2
         * @author DiosFer
         */
        ~Pedido();



        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

       /**
         * @brief modulo get del atributo id_pedido 
         * @return id_pedido
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        string get_id_pedido() const;
        
       /**
         * @brief modulo get del atributo fecha_pedido 
         * @return fecha_pedido
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        Fecha get_fecha_pedido() const;

       /**
         * @brief modulo get del atributo hora_pedido 
         * @return hora_pedido
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        Hora get_hora_pedido() const;

       /**
         * @brief modulo get del atributo total_productos_pedidos 
         * @return total_productos_pedidos
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        int get_total_productos_pedido() const;

       /**
         * @brief modulo get del atributo total_precio_pedido_sin_iva 
         * @return total_precio_pedido_sin_iva
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        float get_total_precio_pedido_sin_iva() const;

       /**
         * @brief modulo get del atributo total_precio_pedido_con_iva 
         * @return total_precio_pedido_con_iva
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        float get_total_precio_pedido_con_iva() const;

       /**
         * @brief modulo get del atributo producto_pedido 
         * @param int posicion
         * @return producto_pedido
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        Producto* get_producto_pedido(int posicion) const;
        

        /**
         * @brief modulo get del atributo estado 
         * @return estado
         * @author DiosFer
         */
        string get_estado() const;

        /**
         * @brief modulo get del atributo cancelable 
         * @return cancelable
         * @author DiosFer
         */
        bool get_cancelable() const;


        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo set del atributo total_precio_pedido_con_iva 
         * @param aux
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        void set_id_pedido(const string aux);

        /**
         * @brief modulo set del atributo fecha_pedido 
         * @param aux
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        void set_fecha_pedido(const Fecha aux);

        /**
         * @brief modulo set del atributo hora_pedido 
         * @param aux
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        void set_hora_pedido(const Hora aux);

        /**
         * @brief modulo set del atributo total_productos_pedido 
         * @param aux
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        void set_total_productos_pedido(const int aux);

        /**
         * @brief modulo set del atributo total_precio_pedido_sin_iva 
         * @param aux
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        void set_total_precio_pedido_sin_iva(const float aux);

        /**
         * @brief modulo set del atributo total_precio_pedido_con_iva 
         * @param aux
         * @date 2023-5-28
         * @version 0.9.2
         * @author DiosFer
         */
        void set_total_precio_pedido_con_iva(const float aux);


        /**
         * @brief modulo set para introducir una puntero a producto en el vector (puntero a puntero) de productos en pedidos
         * @param Producto* p
         * @date 2023-5-29
         * @version 0.9.5
         * @author DiosFer
         */
        void set_producto_pedido(Producto *p);


        /**
         * @brief modulo set del atributo estado 
         * @param estado
         * @author DiosFer
         */
        void set_estado(string e);

        /**
         * @brief modulo set del atributo cancelable 
         * @param cancelable
         * @author DiosFer
         */
        void set_cancelable(bool c);


        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/
        /**
         * @brief modulo para imprimir por pantalla un pedido
         * @post se imprimira por pantalla
         * @date 2023-5-29
         * @version 0.9.5
         * @author DiosFer
         */
        void print() const;

        /**
         * @brief modulo para introducir un pedido
         * @post se introducira el pedido
         * @date 2023-5-29
         * @version 0.9.5
         * @author DiosFer
         */
        void introducir();

        /**
         * @brief modulo para imprimir lo basico de un pedido
         * @post se imprimira por pantalla los datos propios del pedido
         * @author DiosFer
         */
        void print_basic();

        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para igualar un pedido
         * @param const Pedido &p
         * @author DiosFer
         */
        Pedido operator=(const Pedido &p);
        
    private:
        /**
         * @brief modulo para hacer un resize de un vector a punteros de pedidos
         * @post se actualizara el tamaño
         * @date 2023-5-29
         * @version 0.9.5
         * @author DiosFer
         */
        void resize_vector_productos_pedido(int new_dim);

};

#endif