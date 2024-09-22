#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/

#include "Pedido.h"
#include "color.h"

/************************/


using namespace std;


/************************/


const bool DEBUG_Cliente=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------ /  Cliente  / -------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Cliente{
    private:

        string id_cliente;

        string login_cliente;

        string pass_cliente;

        string nombre;

        string num_telefono;

        string direccion;

        bool activo;

        Pedido* vector_pedidos_cliente;

        int total_pedidos_cliente;

        float valoracion_media_productos;

        float precio_medio_pedidos_cliente;

        float total_valoraciones;

    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/
       /**
         * @brief modulo constructor del objeto cliente 
         * @post se construira el objeto
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        Cliente();

        /**
         * @brief modulo constructor por copia del objeto cliente 
         * @post se construira el objeto
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        Cliente(const Cliente &c);


        /**
         * @brief modulo constructor por parametros del objeto cliente 
         * @post se construira el objeto
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        Cliente(string un_id_cliente, string un_login_cliente, string un_pass_cliente, string un_nombre, string un_num_telefono, string un_direccion, bool a);
    
        /**
         * @brief modulo destructor del objeto cliente 
         * @post se destruira el objeto
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        ~Cliente();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

       /**
         * @brief modulo get del atributo id_cliente
         * @return id_cliente
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        string get_id_cliente() const;

        /**
         * @brief modulo get del atributo login
         * @return login
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        string get_login_cliente() const;


        /**
         * @brief modulo get del atributo pass
         * @return pass
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        string get_pass_cliente() const;

        /**
         * @brief modulo get del atributo nombre
         * @return nombre
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        string get_nombre() const;


        /**
         * @brief modulo get del atributo num_telefono
         * @return num_telefono
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        string get_num_telefono() const;

        /**
         * @brief modulo get del atributo direccion
         * @return direccion
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        string get_direccion() const;

        /**
         * @brief modulo get del atributo activo
         * @return activo
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        bool get_activo() const;

        /**
         * @brief modulo get para obtener un pedido de un cliente
         * @date 
         * @version 
         * @author DiosFer
         */
        Pedido* get_vector_pedidos_cliente(int posicion);


        /**
         * @brief modulo para obtener el total de pedidos 
         * @post 
         * @date 
         * @version 
         * @author DiosFer
         */
        int get_total_pedidos_cliente() const;

        /**
         * @brief modulo get del atributo valoracion_media
         * @return valoracion_media
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        float get_valoracion_media_productos() const;

        /**
         * @brief modulo get del atributo precio_medio
         * @return precio_medio
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        float get_precio_medio_pedidos_cliente() const;

        /**
         * @brief modulo get del atributo total_valoracion_cliente
         * @return total_valoracion_cliente
         * @author DiosFer
         */
        float get_total_valoraciones_cliente() const;

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

       
        /**
         * @brief modulo set del atributo id_cliente
         * @param id_cliente
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_id_cliente(string aux);

        /**
         * @brief modulo set del atributo login
         * @param login
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_login_cliente(string aux);

        /**
         * @brief modulo set del atributo pass
         * @param pass
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_pass_cliente(string aux);

        /**
         * @brief modulo set del atributo nombre
         * @param nombre
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_nombre(string aux);

        /**
         * @brief modulo set del atributo num_telefono
         * @param num_telefono
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_num_telefono(string aux);

        /**
         * @brief modulo set del atributo direccion
         * @param direccion
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_direccion(string aux);

        /**
         * @brief modulo set del atributo activo
         * @param activo
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_activo(bool aux);

        /**
         * @brief modulo para insertar un pedido en el cliente
         * @param cosnt Pedido &p
         * @date 
         * @version 
         * @author DiosFer
         */
        void set_pedido_vector_pedidos_cliente(const Pedido &p);


        /**
         * @brief modulo para introducir el total de pedidos de un cliente
         * @param int aux
         * @date 
         * @version 
         * @author DiosFer
         */
        void set_total_pedidos_cliente(int aux);

        /**
         * @brief modulo set del atributo valoracion_media
         * @return valoracion_media
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_valoracion_media_productos(float aux);

        /**
         * @brief modulo set del atributo precio_medio
         * @return precio_medio
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void set_precio_medio_pedidos_cliente(float aux);

        /**
         * @brief modulo para introducir el total de valoraciones de un vcliente
         * @param float aux
         * @date 
         * @version 
         * @author DiosFer
         */
        void set_total_valoraciones_cliente(float aux);


        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        
        /**
         * @brief modulo para mostrar un cliente
         * @post se mostrara por pantalla el cliente
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void print();

        /**
         * @brief modulo para imprimir solo el cliente
         * @post se imprimira el cliente
         * @author DiosFer
         */
        void print_solo_cliente();

        /**
         * @brief modulo para introducir un cliente
         * @post se introduciran los datos de un cliente
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        void introducir();

        /**
         * @brief modulo para que un cliente realize una valoracion a un producto
         * @return Producto* p
         * @author DiosFer
         */
        Producto* realizar_valoracion();


        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para igualar un cliente
         * @param const Cliente c
         * @date 2023-5-27
         * @version 0.9
         * @author DiosFer
         */
        Cliente operator=(const Cliente &c);

    private:

        /**
         * @brief modulo para
         * @post se habra actualizado la dimension del vector de pedidos del cliente
         * @author DiosFer
         */
        void resize_vector_pedidos_cliente(int new_dim);
        
    public:
        /**
         * @brief modulo para cancelar un pedido (parto de que en principio pedidos cancelados no serviran para las estadisticas futuras por tanto una cancelacion equivale a eliminacion)
         * @post se eliminaran sus datos y se reducira el numero de pedidos en los que esta cada producto
         * @author DiosFer
         */
        void eliminar_cancelar_pedido(int posicion);
};

#endif
