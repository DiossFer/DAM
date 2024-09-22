#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


/************************/

#include "DominusKing.h"

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


const bool DEBUG_main=true;


/************************/


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*************************************************************************************************************************************
------------------------------------------------------------- *  Main  * -------------------------------------------------------------
**************************************************************************************************************************************/



int main(){


/*
    DominusKing cristoking;

    cristoking.nuevoIngrediente();
    cout << cristoking.get_ingrediente_sistema(0);

    cristoking.nuevoIngrediente();
    cout << cristoking.get_ingrediente_sistema(1);

    cristoking.nuevoIngrediente();
    cout << cristoking.get_ingrediente_sistema(2);

    cristoking.nuevoIngrediente();
    cout << cristoking.get_ingrediente_sistema(3);
*/

    Pizza p1;
    Ingrediente *I1=new Ingrediente;



    cin>>*I1;


    cin >> p1;
    p1.set_Ingrediente_pizza(I1);
    p1.set_Ingrediente_pizza(I1);
    p1.set_Ingrediente_pizza(I1);
    cout << p1;

}



/*************************************************************************************************************************************
------------------------------------------------------------- *  Main  * -------------------------------------------------------------
**************************************************************************************************************************************/


