#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/


#include "color.h"


/************************/


using namespace std;


/************************/


const bool DEBUG_producto=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------ /  Producto  / ------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Producto{
    protected:

        ///Atributos
        
        string id_producto;

        string nombre;

        float precio_producto_sin_iva;

        string tamano;

        bool activo;

        float precio_producto_con_iva;

        int porcentaje_iva_producto;

        

        int num_veces_incluido_en_pedidos;

        float valoracion_total;
        float valoracion_media;
        float num_valoracion;


    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo constructor para un obbjeto de la clase Producto
         * @post se construira el objeto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        Producto();

        ///Se reaiza solo, todo es estatico
        ///Producto(const Producto &p);


        /**
         * @brief modulo constructor por parametros para un obbjeto de la clase Producto
         * @post se construira el objeto
         * @date 2023-5-26
         * @version 0.8
         * @author DiosFer
         */
        Producto(const string id_producto, const string nombre, const float precio_producto_sin_iva, const string tamano, const int porcentaje_iva_producto, const bool a);
        

        /**
         * @brief modulo destructor para un obbjeto de la clase Producto
         * @post se destruira el objeto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        ~Producto();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo get para el atributo id_producto de un objeto de tipo producto
         * @return string id_producto
         * @post se obtendra el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        string get_id_producto() const;


        /**
         * @brief modulo get para el atributo nombre de un objeto de tipo producto
         * @return nombre
         * @post string se obtendra el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        string get_nombre() const;


        /**
         * @brief modulo get para el atributo precio_producto_sin_iva de un objeto de tipo producto
         * @return float precio_producto_sin_iva
         * @post se obtendra el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        float get_precio_producto_sin_iva () const;


        /**
         * @brief modulo get para el atributo tamaño de un objeto de tipo producto
         * @return string tamaño
         * @post se obtendra el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        string get_tamano() const;


        /**
         * @brief modulo get para el atributo activo de un objeto de tipo producto
         * @return bool activo
         * @post se obtendra el atrivuto
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        bool get_activo() const;


        /**
         * @brief modulo get para el atributo precio_producto_con_iva de un objeto de tipo producto
         * @return float precio_producto_con_iva
         * @post se obtendra el atrivuto
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        float get_precio_producto_con_iva() const;


        /**
         * @brief modulo get para el atributo porcentaje_iva_producto de un objeto de tipo producto
         * @return int porcentaje_iva_producto
         * @post se obtendra el atrivuto
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        int get_porcentaje_iva_producto() const;


        /**
         * @brief modulo get para el atributo valoracion_total de un objeto de tipo producto
         * @return float valoracion_total
         * @post se obtendra el atrivuto
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        float get_valoracion_total() const;
        


        /**
         * @brief modulo get para el atributo num_veces_incluido_en_pedidos de un objeto de tipo producto
         * @return int num_veces_incluido_en_pedidos
         * @post se obtendra el atrivuto
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        int get_num_veces_incluido_en_pedidos() const;

        /**
         * @brief modulo para obtener la valoracion media de un producto
         * @return val
         * @author DiosFer
         */
        float get_valoracion_media();

        /**
         * @brief modulo para obtener num de valoraciones que tiene un producto
         * @return nnum_val
         * @author DiosFer
         */
        float get_num_valoracion();

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief modulo set para el atributo id_producto de un objeto de tipo producto
         * @param string id
         * @post se actualizara el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        void set_id_producto(const string id);

        /**
         * @brief modulo set para el atributo nombre de un objeto de tipo producto
         * @param string n
         * @post se actualizara el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        void set_nombre(const string n);

        /**
         * @brief modulo set para el atributo precio_producto_sin_iva de un objeto de tipo producto
         * @param float p_n_I
         * @post se actualizara el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        void set_precio_producto_sin_iva (const float p_n_i);


        /**
         * @brief modulo set para el atributo tamaño de un objeto de tipo producto
         * @param string t
         * @post se actualizara el atrivuto
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        void set_tamano(const string t);



        /**
         * @brief modulo set para el atributo activo de un objeto de tipo producto
         * @param bool b
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_activo(const bool b);


        /**
         * @brief modulo set para el atributo precio_producto_con_iva de un objeto de tipo producto
         * @param float f
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_precio_producto_con_iva(const float f);


        /**
         * @brief modulo set para el atributo porcentaje_iva_producto de un objeto de tipo producto
         * @param int i
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_porcentaje_iva_producto(const int i);


        /**
         * @brief modulo set para el atributo valoracion_total de un objeto de tipo producto
         * @param float f
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_valoracion_total(const float f);
        


        /**
         * @brief modulo set para el atributo num_veces_incluido_en_pedidos de un objeto de tipo producto
         * @param int i
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_num_veces_incluido_en_pedidos(const int i);

        /**
         * @brief modulo para introducir una valoracion media
         * @param float aux
         * @author DiosFer
         */
        void set_valoracion_media(float aux);

        /**
         * @brief modulo para introducir el numero de valoraciones de un producto
         * @param float aux
         * @author DiosFer
         */
        void set_num_valoracion(float aux);

        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo amigo para realizar la entrada de un objeto de tipo Producto
         * @post introducira por pantalla los datos
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, const Producto &p);
        virtual void print(); 

        /**
         * @brief modulo amigo para realizar la entrada de un objeto de tipo Producto
         * @post se introduciran por pantalla los datos
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Producto &p); 
        virtual void introducir();


        /**
         * @brief modulo para imprimir las estadisticas de un producto
         * @post 
         * @date 
         * @version 
         * @author DiosFer
         */
        void imprimir_estadisticas_producto();


        /**
         * @brief modulo para imprimir solo lo basico de producto
         * @post 
         * @date 
         * @version 
         * @author DiosFer
         */
        void imprimir_solo_producto();

        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        
        //virtual Producto& operator=(const Producto &p);

        /**
         * @brief modulo para actualizar el precio con iva de un producto
         * @param float precio_sin_iva
         * @param int porcentaje_iva
         * @post se actualizara el precio con iva
         * @date 2023-5-26
         * @version 0.8
         * @author DiosFer
         */
        void calcular_precio_con_iva(float precio_sin_iva, int porcentaje_iva);

};
#endif
