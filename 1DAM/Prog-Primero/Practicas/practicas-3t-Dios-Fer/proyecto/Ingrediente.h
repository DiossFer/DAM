#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/


#include "color.h"


/************************/


using namespace std;


/************************/


const bool DEBUG_ingrediente=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------- /  Ingrediente  / -----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Ingrediente{
    private:

        ///Atributos

        string id_ingrediente;
        
        string nombre;

        bool activo;

        float precio_ingrediente;

        string tipo;

        int num_veces_incluido_en_pizzas;

    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief constructor de la clase ingrediente
         * @post se construira un objeto de la clase ingrediente
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        Ingrediente();


        /**
         * @brief constructor de la clase ingrediente por parametros
         * @post se construira un objeto de la clase ingrediente
         * @author DiosFer
         */
        Ingrediente(const string id, const string nombre, const float precio, const string tipo);


        /**
         * @brief Destructor de la clase ingrediente
         * @post se destruira un objeto de la clase ingrediente
         * @date 2023-5-23
         * @version 0.2
         * @author DiosFer
         */
        ~Ingrediente();



        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo get para el atributo id_ingrediente de la clase ingrediente
         * @return string id_ingrediente
         * @date 2023-5-23
         * @version 0.2
         * @author DiosFer
         */
        string get_id_ingrediente() const;

        /**
         * @brief modulo get para el atributo nombre de la clase ingrediente
         * @return string nombre
         * @date 2023-5-23
         * @version 0.2
         * @author DiosFer
         */
        string get_nombre() const;

        /**
         * @brief modulo get para el atributo activo de la clase ingrediente
         * @return bool precio_ingrediente_sin_iva
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        bool get_activo() const;


        /**
         * @brief modulo get para el atributo precio_ingrediente de la clase ingrediente
         * @return float iva_ingrediente
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        float get_precio_ingrediente() const;


        /**
         * @brief modulo get para el atributo tipo de la clase ingrediente
         * @return string tipo
         * @date 2023-5-23
         * @version 0.2
         * @author DiosFer
         */
        string get_tipo() const;

        /**
         * @brief modulo get para el atributo num_veces_incluido_en_pizzas de la clase ingrediente
         * @return int num_veces_incluido_en_pizzas
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        int get_num_veces_incluido_en_pizzas() const;

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo set para el atributo id_ingrediente de la clase ingrediente
         * @param string id_ingrediente
         * @post se actualizara el atributo
         * @date 2023-5-23
         * @version 0.2
         * @author DiosFer
         */
        void set_id_ingrediente(string aux_s);

        /**
         * @brief modulo set para el atributo nombre de la clase ingrediente
         * @param string nombre
         * @post se actualizara el atributo
         * @date 2023-5-23
         * @version 0.2
         * @author DiosFer
         */
        void set_nombre(string aux_s);

        /**
         * @brief modulo set para el atributo activo de la clase ingrediente
         * @param bool activo
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_activo(bool a);

        /**
         * @brief modulo set para el atributo precio_ingrediente de la clase ingrediente
         * @param float precio_ingrediente
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_precio_ingrediente(float aux_f);

        /**
         * @brief modulo set para el atributo tipo de la clase ingrediente
         * @param string tipo
         * @post se actualizara el atributo
         * @date 2023-5-23
         * @version 0.2
         * @author DiosFer
         */
        void set_tipo(string aux_s);

        /**
         * @brief modulo set para el atributo num_veces_incluido_en_pizzas de la clase ingrediente
         * @param int new_num
         * @post se actualizara el atributo
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        void set_num_veces_incluido_en_pizzas(int new_num);
        
        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo amigo para realizar la salida de un objeto de tipo Ingrediente
         * @post se mostrara por pantalla
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, const Ingrediente &i); 
        //void print();


        /**
         * @brief modulo amigo para realizar la entrada de un objeto de tipo Ingrediente
         * @post introducira por pantalla los datos
         * @date 2023-5-26
         * @version 0.5
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Ingrediente &i); 
        //void introducir();

        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        //Todo estatico
        //Ingrediente operator=(const Ingrediente &i);
        

};

#endif