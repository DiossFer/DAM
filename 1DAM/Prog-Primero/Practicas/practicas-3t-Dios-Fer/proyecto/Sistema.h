#ifndef SISTEMA
#define SISTEMA

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>


/************************/


#include "Producto.h"
#include "Refresco.h"
#include "Pizza.h"
#include "Ingrediente.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Time.h"
#include "Valoracion.h"
#include "color.h"


/************************/


using namespace std;


/************************/


const bool DEBUG_Sistema=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*--------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  DominusKing  / ----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/


class Sistema{
    private:

        ///Atributos
        string id_tienda;

        Cliente** clientes_sistema;
        int total_clientes_sistema;


        Producto** productos_sistema;
        int total_productos_sistema;



        Ingrediente* ingredientes_sistema;
        int total_ingredientes_sistema;

        Valoracion* valoraciones_sistema;
        int total_valoraciones_sistema;

        Cliente* cliente_activo;

        Pedido** resultado_busqueda_pedidos;
        int total_pedidos_encontrados;

        Cliente** resultado_busqueda_clientes;
        int total_clientes_encontrados;

        Producto** resultado_busqueda_productos;
        int total_productos_encontrados;




    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/
        
        /**
         * @brief modulo constructor para un objeto de tipo DominusKing
         * @post se construira el objeto
         * @date 2023-5-25
         * @version 0.9
         * @author DiosFer
         */
        Sistema();

        /**
         * @brief modulo destructor para un objeto de tipo DominusKing
         * @post se destruira el objeto
         * @date 2023-5-25
         * @version 0.9
         * @author DiosFer
         */
        ~Sistema();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo get para obtener el id_tienda
         * @return id_tienda
         * @post se obtendra el dato
         * @author DiosFer
         */
        string get_id_tienda ();

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
         * @brief modulo get para obtener el total de productos del sistema
         * @return int total
         * @post se obtendra el dato
         * @author DiosFer
         */
        int get_total_productos_sistema();


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


        /**
         * @brief modulo get para obtener una posicion de un ingrediente de una posicion concreta del vcetor de ingredientes del sistema
         * @param int posicion
         * @return Ingrediene*
         * @post se obtendra el dato
         * @author DiosFer
         */
        Ingrediente* get_posicion_ingrediente(int posicion);


        /**
         * @brief modulo get para obtener el total de clientes del sistema
         * @return int total
         * @post se obtendra el dato
         * @author DiosFer
         */
        int get_total_clientes_sistema();


        /**
         * @brief modulo get para obtener el total de valoraciones del sistema
         * @return int total
         * @post se obtendra el dato
         * @author DiosFer
         */
        int get_total_valoraciones_sistema();

        /**
         * @brief modulo get para obtener el cliente activo del sistema
         * @return Cliente* c
         * @post se obtendra el dato
         * @author DiosFer
         */
        Cliente* get_cliente_activo();

        /**
         * @brief modulo get para obtener un pedido del resultado de busquedas de pedido
         * @pre haber realizado una busqueda de pedidos
         * @pre la posicin debe de estar contenida en el vector
         * @param int posicion
         * @return Pedido* p
         * @author DiosFer
         */
        Pedido* get_resultado_busqueda_pedidos(int posicion);


        /**
         * @brief modulo get para obtener el total de pedidos encontrados en una busqueda
         * @return int total
         * @post se obtendra el dato
         * @author DiosFer
         */
        int get_total_pedidos_encontrados();


        /**
         * @brief modulo get para obtener un cliente del resultado de busquedas de cliente
         * @pre haber realizado una busqueda de clientes
         * @pre la posicin debe de estar contenida en el vector
         * @param int posicion
         * @return Cliente* c
         * @author DiosFer
         */
        Cliente* get_resultado_busqueda_clientes(int posicion);

        /**
         * @brief modulo get para obtener el total de clientes encontrados en una busqueda
         * @return int total
         * @post se obtendra el dato
         * @author DiosFer
         */
        int get_total_clientes_encontrados();



        /**
         * @brief modulo get para obtener un producto del resultado de busquedas de producto
         * @pre haber realizado una busqueda de productos
         * @pre la posicin debe de estar contenida en el vector
         * @param int posicion
         * @return Producto* c
         * @author DiosFer
         */
        Producto* get_resultado_busqueda_productos(int posicion);

        /**
         * @brief modulo get para obtener el total de productos encontrados en una busqueda
         * @return int total
         * @post se obtendra el dato
         * @author DiosFer
         */
        int get_total_productos_encontrados();

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief modulo set para el total de id_tienda
         * @param string id
         * @post se actualizara el atributo
         * @author DiosFer
         */
        void set_id_tienda (string id);

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
         * @brief modulo set para el total de productos del sistema
         * @param int i
         * @post se actualizara el atributo
         * @author DiosFer
         */
        void set_total_productos_sistema(int i);



        /**
         * @brief modulo set para introducir un ingrediente en el vector de ingredientes del sistema
         * @param Ingrediente ig
         * @post se añadira el ingrediente en el vcetor
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        void set_ingrediente_vector_ingrediente(const Ingrediente &ig);

        /**
         * @brief modulo set para introducir un producto en el vector polimorfico del sistema (Sobrecarga1 Refrescos)
         * @param Refresco r 
         * @post se introducira el producto polimorfico de productos del sistema
         * @date 2023-5-28
         * @version 0.9.3
         * @author DiosFer
         */
        void setProducto_vectorPolimorfico_productosSistema(Refresco r);

        /**
         * @brief modulo set para introducir un producto en el vector polimorfico del sistema (Sobrecarga2 Pizzas)
         * @param Pizza p 
         * @post se introducira el producto polimorfico de productos del sistema
         * @date 2023-5-28
         * @version 0.9.3
         * @author DiosFer
         */
        void setProducto_vectorPolimorfico_productosSistema(Pizza p);

        /**
         * @brief modulo set para el total de clientes del sistema
         * @param int aux
         * @post se actualizara el atributo
         * @author DiosFer
         */
        void set_total_clientes_sistema(int aux);

        /**
         * @brief modulo set para introducir un cliente en el vector de clientes del sistema
         * @param const Cliente &c
         * @post se actualizara el vector y su dim-total
         * @author DiosFer
         */
        void set_cliente_vector_cliente_sistema(const Cliente &c);


        /**
         * @brief modulo set para el total de valoraciones del sistema
         * @param int aux
         * @post se actualizara el atributo
         * @author DiosFer
         */
        void set_total_valoraciones_sistema(int aux);


        /**
         * @brief modulo set para introducir una vloracion en el vector de valoraciones del sistema
         * @param const Valoracion &v
         * @post se actualizara el vector y su dim-total
         * @author DiosFer
         */
        void set_Valoracion_vector_Valoraciones_sistema(const Valoracion &v);


        /**
         * @brief modulo set para introducir un cliente en el vector de clientes del sistema
         * @param Cliente* c
         * @post se actualizara el vector y su dim-total
         * @author DiosFer
         */
        void set_cliente_activo(Cliente* c);


        /**
         * @brief modulo set para actualizar un pedido del resultado de busquedas de pedido
         * @param Pedido* p
         * @post se actualizara el vector de resultados
         * @author DiosFer
         */
        void set_resultado_busqueda_pedidos(Pedido* p);


        /**
         * @brief modulo set para actualizar el total de pedidos encontrados en una busqueda
         * @param int total         
         * @post se actualizara el atributo
         * @author DiosFer
         */
        void set_total_pedidos_encontrados(int total);


        /**
         * @brief modulo set para actualizar un cliente del resultado de busquedas de cliente
         * @param Cliente* c
         * @post se actualizara el vector de resultados
         * @author DiosFer
         */
        void set_resultado_busqueda_clientes(Cliente* c);

        /**
         * @brief modulo set para actualizar el total de clientes encontrados en una busqueda
         * @param int total         
         * @post se actualizara el atributo
         * @author DiosFer
         */
        void set_total_clientes_encontrados(int total);



        /**
         * @brief modulo set para actualizar un cliente del resultado de busquedas de cliente
         * @param Cliente* c
         * @post se actualizara el vector de resultados
         * @author DiosFer
         */
        void set_resultado_busqueda_productos(Producto* p);

        /**
         * @brief modulo set para actualizar el total de clientes encontrados en una busqueda
         * @param int total         
         * @post se actualizara el atributo
         * @author DiosFer
         */
        void set_total_productos_encontrados(int total);



        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/
        






        /**
         * @brief modulo para modificar un producto
         *          Proceso:
         *          Creamos una copia para que nuestor modificar sea un eliminar-crear 
         *          (desactivremos el producto manteniendo asi el hsitoria pues un cliente pidio esa pizza antigua no la nueva "editada", deberemos de diferenciar)
         *          Editaremos la copia de la antigua, desactivaremos la antigua y insertaremos la editada
         * @post se habra creado la nueva version del producto (y "eliminado" la anterior)
         * @author DiosFer
         */
        void modificar_producto();


        /**
         * @brief modulo para buscar un cliente por cierto argumento 
         * @pre solicitar la manera en que se quiere buscar al cliente
         * @param int modo -->
         *                      1 -> buscar por login         
         *                      2 -> buscar por nombre         
         * @post se cambiara el vector de resultados de busqueda junto a su total
         * @author DiosFer
         */
        void buscar_cliente (int modo);


        /**
         * @brief modulo para buscar un pedido por cierto argumento 
         * @pre solicitar la manera en que se quiere buscar el pedido
         * @param int modo -->
         *                      1 -> buscar por intervalo de precio con iva         
         * @post se cambiara el vector de resultados de busqueda junto a su total
         * @author DiosFer
         */
        void buscar_pedidos (int modo);


        /**
         * @brief modulo para buscar un producto por cierto argumento 
         * @pre solicitar la manera en que se quiere buscar el producto
         * @param int modo -->
         *                      1 -> buscar por nombre 
         *                      2 -> buscar por un ingrediente que contenga
         * @post se cambiara el vector de resultados de busqueda junto a su total
         * @author DiosFer
         */
        void buscar_producto (int modo);

        /**
         * @brief modulo para crear un cliente desde el acceso del usuario
         * @post se creara el usuario con sus credenciales
         * @author DiosFer
         */
        void CrearCliente();


        /**
         * @brief modulo para crear e introducir un ingrediente en el vector de ingredientes del sistema
         * @post se introducira en el vector el ingrediente
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        void nuevoIngrediente();


        /**
         * @brief modulo para crear e introducir un producto en el vector de productos del sistema (si se introduce uno ya existente dara error)
         * @post se introducira al vector polimorfico el producto creado
         * @date 2023-5-28
         * @version 0.9.3
         * @author DiosFer
         */
        void nuevoProducto();
        

        /**
         * @brief modulo para imprimir los productos del sistema
         * @post se imprimira por pantalla todos los productos del sistema
         * @date 2023-5-28
         * @version 0.9.3
         * @author DiosFer
         */
        void imprimir_productos_del_sistema();


        /**
         * @brief modulo para imprimir los ingredientes del sistema
         * @post se imprimira por pantalla todos los ingredientes del sistema
         * @author DiosFer
         */
        void imprimir_ingredientes_del_sistema();


        /**
         * @brief modulo para imprimir los clientes del sistema
         * @post se imprimira por pantalla todos los clientes del sistema
         * @author DiosFer
         */
        void imprimir_clientes_del_sistema();


        /**
         * @brief modulo para imprimir las valorcaiones del sistema
         * @post se imprimira por pantalla todos las valorcaiones del sistema
         * @author DiosFer
         */
        void imprimir_valoraciones_del_sistema();


        /**
         * @brief modulo para imprimir todo el sistema por pantalla
         * @post se imprimira todo el sistema por pantalla
         * @author DiosFer
         */
        void imprimir_gloval();

        /**
         * @brief modulo para calcular e imprimir los 3 top 3 pertenecientes al Ranking 1
         * @post se imprimira por pantalla todos los tops
         * @date 2023-5-30
         * @version 1.2
         * @author DiosFer
         */
        void ranking_commun();

        /**
         * @brief modulo para calcular e imprimir los 3 top 3 pertenecientes al Ranking 2
         * @post se imprimira por pantalla todos los tops
         * @date 2023-5-30
         * @version 1.2.1
         * @author DiosFer
         */
        void ranking_separado();

        /**
         * @brief modulo para calcular e imprimir los tops pertenecientes al Ranking 3 
         * @post se imprimira por pantalla todos los tops
         * @date 2023-5-30
         * @version 1.2.2
         * @author DiosFer
         */
        void ranking_clientes();

        /**
         * @brief modulo para realizar un login y dar paso a un menu en funcion del usuario que acceda
         * @post se accedera al menu
         * @author DiosFer
         */
        void login();

        /**
         * @brief modulo para mostrar y acceder en funcion de una eleccion a acciones que puede realizar un administrador
         * @post se realizaran las acciones deseadas y se cerrara sesion
         * @author DiosFer
         */
        void menu_admin();


        /**
         * @brief modulo para realizar un login y dar paso a un menu en funcion del usuario que acceda
         * @post se accedera al menu
         * @author DiosFer
         */
        void menu_cliente();

        /**
         * @brief modulo para que un cliente activo consulte sus pedidos
         * @post se accederan a los pedidos del cliente
         * @author DiosFer
         */
        void consultar_pedido_Cliente();


        /**
         * @brief modulo para que un cliente realize un pedido, con productos del sistema o pizzas al gusto
         *          Que implica la pizza al gusto:
         *              1. Se creara una pizza, como no hay precios por defecto ni generadores de Ids todo se metera por pantalla
         *              2. Si se introduce una pizza del sistema no se duplicara, se apuntara a la del sistema
         *                  2.1. Si esta activa no habra problema y se apuntara como si se pidiera normalemente
         *                  2.2. Si no esta activa, se activara, nos interesa sus antiguas estadisticas, su historia sera importante 
         *                      (Ejemplo: antes se pedia una pizza pero se acabo "eliminando" por ciertos motivos ahora un cliente se pide una al gusto igual que esa, sus antiguas estadisticas en mi contexto nos interesa para su historial)
         *                      por tantro ademas de apuntar a esta se volvera a activar igual que se añaden la pizzas al gusto
         *                      (habria otras opciones como duplicarlas para generar un nuevo historial pero en mi contexto he decidido hacerlo de esta manera)
         * @post se añadira el pedido a los pedidos del usuario 
         * @author DiosFer
         */
        void realizar_pedido_cliente();



        /**
         * @brief modulo rpara que el administrador elija una valoracion para ver mas a fondo
         * @post mostrara la valoracion elejia por el cliente
         * @author DiosFer
         */
        void consultar_valoracion_Producto();



        /**
         * @brief modulo para eliminar-desactivar un cliente
            //Que implica:
            //considero que eliminar un cliente sera cuestion de desactivarlo 
            //ya lo que afecte a este como los pedidos y valoraciones hay que decidir
            //en cuanto a los pedidos nos interesara mantenerlo para las estadisticas del sistema (al eliminarse tu cuenta dominus sigue teniendo registrado lo que pediste pues ya fue pedido)
            //Las valoraciones tambien las mantendremos intactas pues nos interesa las opiniones de antiguos usuarios a pesar de que en la actualidad su cuenta no exista
         * @post se desactivara el cliente y ya no se tendra en cuenta para las metricas
         * @author DiosFer
         */
        void EliminarCliente();


        /**
         * @brief modulo para eliminar-desactivar un producto
            //Que implica:
            //Se desactivara el producto 
            //se dejara de tener en cuenta para rankings y salidas del sistema, no se podra pedir ni ver
         * @post se desactivara el producto y ya no se tendra en cuenta para las metricas
         * @author DiosFer
         */
        void EliminarProducto();


        /**
         * @brief modulo para editar los datos de un producto (pizza)
         * @param Pizza* p
         * @post se actualizaran los datos
         * @author DiosFer
         */
        void edit (Pizza* p);

        /**
         * @brief modulo para editar los datos de un producto (refresco)
         * @param Refresco* r
         * @post se actualizaran los datos
         * @author DiosFer
         */
        void edit (Refresco* r);

        /**
         * @brief modulo para editar los datos de un cliente 
         * @param Cliente* c
         * @post se actualizaran los datos del cliente
         * @author DiosFer
         */
        void modificar_datos_cliente(Cliente* c);

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

    private:
         /**
         * @brief modulo resizear un vector de ingredientes del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @date 2023-5-25
         * @version 0.3
         * @author DiosFer
         */
        void resize_vector_ingrediente(int new_dim);


        /**
         * @brief modulo resizear un vector de clientes del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @author DiosFer
         */
        void resize_vector_clientes(int new_dim);


        /**
         * @brief modulo resizear un vector de valoraciones del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @author DiosFer
         */
        void resize_vector_valoraciones(int new_dim);

        /**
         * @brief modulo resizear un vector de productos del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @author DiosFer
         */
        void resize_vector_polimorfico(int new_dim);



        /**
         * @brief modulo resizear un vector de resultados de busqueda de pedidos del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @author DiosFer
         */
        void resize_vector_resultado_busqueda_pedidos (int new_dim);



        /**
         * @brief modulo resizear un vector de resultados de busqueda de clientes del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @author DiosFer
         */
        void resize_vector_resultado_busqueda_clientes (int new_dim);

        
        /**
         * @brief modulo resizear un vector de resultados de busqueda de productos del sistema
         * @param int new_dim
         * @post se obtendran los datos del vcetor actual en uno con mas dim
         * @author DiosFer
         */
        void resize_vector_resultado_busqueda_productos (int new_dim);

    public:

        /**
         * @brief modulo para guardar la instancia actual de los ingredientes en la base de datos 
         *        (Actualmente no hay nada relacionado a la edicion-creacion de ingredeintes pero en caso de futuras mejoras funcionaria correctamente)
         * @post se actualizara la base de datos
         * @author DiosFer
         */
        void set_ingredientes_bd ();


        /**
         * @brief modulo para imprimir la instancia actual de la base de datos
         * @post se imprimira la instancia actual de la bd
         * @author DiosFer 
         */
        void print_ingredientes_bd ();

        /**
         * @brief modulo para cargar la instanciacion actual del programa en un xml
         * @post se guardara en el archivo
         * @author DiosFer 
         */
        void cargar_en_xml();


        /**
         * @brief modulo para cargar la instancia de un xml para los datos del sistema 
         * @post se guardaran en los vectores del sistema la instancia del xml
         * @pre se llamara en el constuctor 
         * @author DiosFer 
         */
        void cargar_del_xml();

        /**
         * @brief modulo para obtener la posicion de un ingrediente en el sistema con el id
         * @return *ingrediente
         * @author DiosFer 
         */
        Ingrediente* get_posicionIngredienteConiID(const string id);

        /**
         * @brief modulo para obtener la posicion de un producto en el sistema con el id
         * @return *producto
         * @author DiosFer 
         */
        Producto* get_posicionProductoConiID(const string id);

        /**
         * @brief modulo para obtener la posicion de un cliente en el sistema con el id
         * @return *cliente
         * @author DiosFer 
         */
        Cliente* get_posicionClienteConiID(const string id);

};

#endif
