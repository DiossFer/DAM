#include <iostream>
#include "Cadenas.h"
#include "Enteros.h"
#include "Viaje.h"//incluye usuario.h(con coche.h) trayecto.h fecha.h tiempo.h


#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define gray "\033[0;37m"                  /* gray */

const bool DEBUG_C_main=false;

using namespace std;


/**
 * @brief Modulo para añadir un usaurio a un vector de usuarios en la util y actualizar la misma
 * @param Usuario user 
 * @param Usuario usuarios_del_sistema [] 
 * @param Usuario util_usuarios_sistema 
 * @date 2023-3-22
 * @version 0.9.2.1
 * @author DiosFer
 */
void anadir_usuaro_a_vector_usuarios (Usuario user, Usuario usuarios_del_sistema[], int &util_usuarios_sistema){
  usuarios_del_sistema[util_usuarios_sistema]=user; //No me gusta igualarlos directamente pero por falta de tiempo lo dejare asi por el momento
  util_usuarios_sistema++;
}


/**         
 * @brief Modulo para cargar de manera manual en el codigo usuarios en el vector de usuarios del sistema 
 * @param Usuario usuarios_del_sistema [] 
 * @param Usuario util_usuarios_sistema 
 * @date 2023-3-22
 * @version 0.9.2.1
 * @author DiosFer
 */
void cargar_usuarios_del_sistema (Usuario usuarios_del_sistema[], int &util_usuarios_sistema){
  usuarios_del_sistema[util_usuarios_sistema];
  Usuario user;


  //Usuario1      
  
  //he indicado las diferencias mas resaltables entre como he hecho la introduccion y como lo han hecho en la instanciacion compartida
  //Por el momento no realizare cambios en cuanto a mi dominio, pues Jaime dijo que no era necesario y no importaba demasiado, pero usare el de mis compañeros ya que al estar el fitro en introducir y no en el set, puedo introducir estos valores sin problemas

  set_id_usuario (user, "RO767");// instancia compartida -->[1, 6]

  set_DNI (user, "76541235P");

  set_carnet (user, 1);

  set_nombre_usuario (user, "roberto14");

  set_nombre (user, "Roberto");

  set_apellido1 (user, "");

  set_apellido2 (user, "");

  set_edad (user, 25);// instancia compartida --> (>16)

  set_movil (user, "789456123");

  set_contrasena (user, "roberto2133");// instancia compartida --> min 7 max 20

  set_mail (user, "roberto@mail.com");

  set_util_coche_usuario (user, 2);

  //introducir_coche Por el momento dejare la util a 0 cuando tenga vector de choches del sistema continuare con la carga de estos datos

  anadir_usuaro_a_vector_usuarios(user, usuarios_del_sistema, util_usuarios_sistema);




    //Usuario2    
  
  set_id_usuario (user, "CH473");

  set_DNI (user, "47562224K");

  set_carnet (user, 0);

  set_nombre_usuario (user, "chetos33");

  set_nombre (user, "Pepe");

  set_apellido1 (user, "");

  set_apellido2 (user, "");

  set_edad (user, 17);

  set_movil (user, "357687159");

  set_contrasena (user, "tuchetos445");

  set_mail (user, "pepe@mail.es");

  set_util_coche_usuario (user, 0);

  //introducir_coche Por el momento dejare la util a 0 cuando tenga vector de choches del sistema continuare con la carga de estos datos

  anadir_usuaro_a_vector_usuarios(user, usuarios_del_sistema, util_usuarios_sistema);

}




  /***************************************************************************************************************************************
  ****************************************************************   MAIN   **************************************************************
  ***************************************************************************************************************************************/
  //=====================================================================================================================================\\
 //_______________________________________________________________________________________________________________________________________\\
//_________________________________________________________________________________________________________________________________________\\

int main(){

  const int DIM_USUARIOS_SISTEMA=5;
  Usuario usuarios_del_sistema[DIM_USUARIOS_SISTEMA];
  int util_usuarios_sistema=0;



  cargar_usuarios_del_sistema(usuarios_del_sistema, util_usuarios_sistema);




  //mero testing aun no esta el mostrar vector
  mostrar_usuario(usuarios_del_sistema[util_usuarios_sistema-2]);
  mostrar_usuario(usuarios_del_sistema[util_usuarios_sistema-1]);
}
