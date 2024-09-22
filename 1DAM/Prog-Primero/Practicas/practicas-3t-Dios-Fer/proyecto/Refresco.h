#ifndef REFRESCO_H
#define REFRESCO_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/


#include "Producto.h"
#include "color.h"


/************************/


using namespace std;


/************************/


const bool DEBUG_refresco=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------ /  Refresco  / ------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Refresco : public Producto{
    private:

        ///Atributos

        bool azucar;

        bool gas;

        bool cafeina;



    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief modulo constructor de un refresco que llama al constructor de un producto
         * @post se creara y inicializara un refresco
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        Refresco();

        ///Constructor por copia no hace falta por ser entero estatico
        ///Refresco(const Refresco &r);



        /**
         * @brief modulo constructor por parametros
         * @post se construira el objeto
         * @date 2023-5-26
         * @version 0.8
         * @author DiosFer
         */
        Refresco(const string id_producto, const string nombre, const float precio_producto_sin_iva, const string tamano, const int porcentaje_iva_producto, const bool azucar, const bool cafeina, const bool gas, const bool a);

        /**
         * @brief modulo destructor de un refresco
         * @post se destruira el refresco
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        ~Refresco();

        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/
        /**
         * @brief modulo get para el atributo azucar de un refresco
         * @return bool azucar
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        bool get_azucar() const;

        /**
         * @brief modulo get para el atributo gas de un refresco
         * @return bool gas
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        bool get_gas() const;

        /**
         * @brief modulo get para el atributo cafeina de un refresco
         * @return bool cafeina
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        bool get_cafeina() const;

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo set para el atributo azucar de un refresco
         * @param bool a
         * @post se actualizara el atributo azucar de un refresco
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        void set_azucar(const bool a);

        /**
         * @brief modulo set para el atributo gas de un refresco
         * @param bool g
         * @post se actualizara el atributo gas de un refresco
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        void set_gas(const bool g);


        /**
         * @brief modulo set para el atributo cafeina de un refresco
         * @param bool c
         * @post se actualizara el atributo cafeina de un refresco
         * @date 2023-5-22
         * @version 0.1
         * @author DiosFer
         */
        void set_cafeina(const bool c);

        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo friend para realizar el cout
         * @post se imprimira en un cout
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, const Refresco &r);
        void print ();

        /**
         * @brief modulo friend para realizar el cin
         * @post se imprimira en un cin
         * @date 2023-5-26
         * @version 0.8
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Refresco &r);
        void introducir();
        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/
       /**
         * @brief modulo para igualar refrescos
         * @param const Refresco &r
         * @author DiosFer
         */
        Refresco& operator=(const Refresco &r);


        /**
         * @brief modulo para comparar refrescos (Solo tendra en cuenta las cosa que se introducen reales que diferencian, precio, id, no lo tiene en cuenta)
         * @param const Refresco &r
         * @return bool igual
         * @author DiosFer
         */
        bool operator==(const Refresco &r);


};


#endif