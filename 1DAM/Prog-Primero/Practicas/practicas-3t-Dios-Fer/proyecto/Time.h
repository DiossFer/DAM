#ifndef TIME_H
#define TIME_H

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


const bool DEBUG_Time=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------- /  Hora  / ---------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Hora{
    private:

        int segundos;
        int minutos;
        int horas;
        

    public:

        
        ///Métodos

        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo constructor del objeto hora
         * @post se construira el objeto
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        Hora();
        

        /**
         * @brief modulo constructor por parametros del objeto hora
         * @post se construira el objeto
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        Hora(const int seg, const int min, const int h);

        //no hace falta, todo es estatico
        //Hora(const Hora &h);

        
        /**
         * @brief modulo destructor del objeto cliente 
         * @post se destruira el objeto
         * @date 2023-5-27
         * @version 0.9.1
         * @author DiosFer
         */
        ~Hora();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo get del atributo segundo
         * @return segundo
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        int get_segundos();

        /**
         * @brief modulo get del atributo minuto
         * @return minuto
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        int get_minutos();


        /**
         * @brief modulo get del atributo hora
         * @return hora
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        int get_horas();
        
        
        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo set del atributo segundos
         * @param segundos
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        void set_segundos(int aux);


        /**
         * @brief modulo set del atributo minutos
         * @param minutos
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        void set_minutos(int aux);


        /**
         * @brief modulo set del atributo horas
         * @param horas
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        void set_horas(int aux);


        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo amigo para la salida de un objeto de tipo hora
         * @post se mostrara por pantalla
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, Hora &h);
        void print ();

        /**
         * @brief modulo amigo para la entrada de un objeto de tipo hora
         * @post se mostrara por pantalla
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Hora &h);
        void introducir();


        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        //no hace falta = todo es estatico

};


/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------- /  Fecha  / --------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/
class Fecha{
    private:

        int dia;
        int mes;
        int anio;
        

    public:

        
        ///Métodos

        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo constructor del objeto fecha
         * @post se construira el objeto
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        Fecha();
        
        /**
         * @brief modulo constructor por parametros del objeto fecha
         * @post se construira el objeto
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        Fecha(const int d, const int m, const int a);

        //no hace falta, todo es estatico
        //Fecha(const Fecha &h);

        /**
         * @brief modulo destructor del objeto fecha
         * @post se destrura el objeto
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        ~Fecha();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo get del atributo dia
         * @return dia
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        int get_dia();


        /**
         * @brief modulo get del atributo mes
         * @return mes
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        int get_mes();


        /**
         * @brief modulo get del atributo anio
         * @return anio
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        int get_anio();
        
        
        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo set del atributo dia
         * @param dia
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        void set_dia(int aux);

        /**
         * @brief modulo set del atributo mes
         * @param mes
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        void set_mes(int aux);

        /**
         * @brief modulo set del atributo anio
         * @param anio
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        void set_anio(int aux);


        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo amigo para la salida de un objeto de tipo fecha
         * @post se mostrara por pantalla
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, Fecha &f);
        void print();


        /**
         * @brief modulo amigo para la entrada de un objeto de tipo fecha
         * @post se mostrara por pantalla
         * @date 2023-5-28
         * @version 0.9.1
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Fecha &f);
        void introducir();


        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/

        //no hace falta = todo es estatico

};

#endif