#include <iostream>
#include <cmath>
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
 * @brief Modulo para cargar de manera manual en el codigo coches en el vector de coches del sistema 
 * @param Coche coches_del_sistema [] 
 * @param int util_coches_sistema 
 * @date 2023-3-26
 * @version 0.9.5
 * @author DiosFer
 */
void cargar_coches_del_sistema (Coche coches_del_sistema[], int &util_coches_sistema);


/**         
 * @brief Modulo para cargar de manera manual en el codigo usuarios en el vector de usuarios del sistema 
 * @param Usuario usuarios_del_sistema [] 
 * @param int util_usuarios_sistema 
 * @param const Coche &coches_del_sistema (para la introduccion del coche correspondiente al usuario)
 * @pre debe de haberse cargado los coches del sistema
 * @date 2023-3-26
 * @version 0.9.6
 * @author DiosFer
 */
void cargar_usuarios_del_sistema (Usuario usuarios_del_sistema[], int &util_usuarios_sistema, const Coche coches_del_sistema []);


/**         
 * @brief Modulo para cargar de manera manual en el codigo trayectos en el vector de trayectos del sistema 
 * @param Trayecto trayectos_del_sistema [] 
 * @param int util_trayectos_sistema 
 * @date 2023-3-27
 * @version 0.9.7
 * @author DiosFer
 */
void cargar_trayectos_del_sistema(Trayecto trayectos_del_sistema[], int &util_trayectos_sistema);



/**         
 * @brief Modulo para cargar de manera manual en el codigo viajes en el vector de viajes del sistema 
 * @param Viaje viajes_del_sistema[]
 * @param int &util_viajes_sistema
 * @param const Trayecto trayectos_del_sistema[]
 * @param const Coche coches_del_sistema []
 * @pre haber cargado ya los coches del sistema
 * @pre haber cargado ya los trayectos del sistema
 * @date 2023-3-28
 * @version 0.9.8
 * @author DiosFer
 */
void cargar_viajes_del_sistema(Viaje viajes_del_sistema[], int &util_viajes_sistema, const Trayecto trayectos_del_sistema[], const Coche coches_del_sistema []);


/**         
 * @brief Modulo para mostrar por pantalla todos los vectores (usuario, trayecto, viaje, coche) del sistema en su estado actual
 * @param const Usuario usuarios_del_sistema[]
 * @param const int util_usuarios_sistema
 * @param const Coche coches_del_sistema[]
 * @param const int util_coches_sistema
 * @param const Trayecto trayectos_del_sistema[]
 * @param const int util_trayectos_sistema
 * @param const Viaje viajes_del_sistema[]
 * @param const int util_viajes_sistema
 * @date 2023-3-28
 * @version 0.9.8.1
 * @author DiosFer
 */
void mostrar_sistema_actual(const Usuario usuarios_del_sistema[], const int util_usuarios_sistema, const Coche coches_del_sistema[], const int util_coches_sistema, const Trayecto trayectos_del_sistema[], const int util_trayectos_sistema, const Viaje viajes_del_sistema[], const int util_viajes_sistema);






/**         
 * @brief Modulo para logearse, introduciendo nombre de usuario y contraseña, debe de tener los Ids de admins para devolver el tipo de usuario (0 admin; 1 normal)
 * @param const Usuario usuarios_del_sistema[]
 * @param const int util_usuarios_sistema
 * @param Usuario &usuario_actual
 * @param const int DIM_USUARIOS_SISTEMA
 * @date 2023-3-28
 * @version 0.9.9
 * @author DiosFer
 */
int login(const Usuario usuarios_del_sistema[], const int util_usuarios_sistema, Usuario &usuario_actual, const int DIM_USUARIOS_SISTEMA);




/**         
 * @brief Modulo para la ejecucion de procesos que puede realizar un usuario que sea administrador
 * @param const Usuario usuarios_del_sistema[]
 * @param const int util_usuarios_sistema
 * @param const Coche coches_del_sistema[]
 * @param const int util_coches_sistema
 * @param const Trayecto trayectos_del_sistema[]
 * @param const int util_trayectos_sistema
 * @param const Viaje viajes_del_sistema[]
 * @param const int util_viajes_sistema
 * @date 2023-3-28
 * @version 1.2
 * @author DiosFer
 */
void menu_admin (Usuario usuarios_del_sistema[], int util_usuarios_sistema, Coche coches_del_sistema[], int util_coches_sistema, Trayecto trayectos_del_sistema[], int util_trayectos_sistema, Viaje viajes_del_sistema[], int util_viajes_sistema);

/**         
 * @brief Modulo para crear un nuevo viaje en el vector de viajes del sistema (con coches y trayactos ya creados (por el momento))
 * @param Coche coches_del_sistema[]
 * @param int util_coches_sistema
 * @param Trayecto trayectos_del_sistema[]
 * @param int util_trayectos_sistema
 * @param Viaje viajes_del_sistema[]
 * @param int util_viajes_sistema
 * @date 2023-3-28
 * @version 1.1
 * @author DiosFer
 */
void CrearNuevoViaje (Coche coches_del_sistema[], int &util_coches_sistema, Trayecto trayectos_del_sistema[], int &util_trayectos_sistema, Viaje viajes_del_sistema[], int &util_viajes_sistema);


/**         
 * @brief Modulo para eliminar un viaje introduciendo su id_coche_que_viaje y su id_trayecto_que_se_realiza
 * @param Viaje viajes_del_sistema[]
 * @param int &util_viajes_sistema
 * @date 2023-3-28
 * @version 1.2
 * @author DiosFer
 */
void eliminar_viaje(Viaje viajes_del_sistema[], int &util_viajes_sistema);


/**         
 * @brief Modulo para eliminar un trayecto introduciendo su ida (Tambien se eliminaran los viajes asociados a ese trayecto)
 * @param Viaje viajes_del_sistema[]
 * @param int &util_viajes_sistema
 * @date 2023-3-28
 * @version 1.3
 * @author DiosFer
 */
void eliminar_trayecto(Viaje viajes_del_sistema[], int &util_viajes_sistema, Trayecto trayectos_del_sistema[], int &util_trayectos_sistema);


/**         
 * @brief Modulo para modificar un viaje concreto (FS-FL-HS-HL-NAO)
 * @param Viaje viajes_del_sistema[]
 * @param int &util_viajes_sistema
 * @date 2023-3-28
 * @version 1.4
 * @author DiosFer
 */
void modificar_viaje(Viaje viajes_del_sistema[], int &util_viajes_sistema);




/**         
 * @brief Modulo para crear un trayecto (introducir y añadir al vector del sistema) ademas de obtenerlo como referencia 
 * @param Trayecto &t_aux
 * @param Trayecto trayectos_del_sistema[]
 * @param int &util_trayectos_sistema
 * @date 2023-3-29
 * @version 1.5
 * @author DiosFer
 */
void crear_trayecto(Trayecto &t_aux, Trayecto trayectos_del_sistema[], int &util_trayectos_sistema);



/**         
 * @brief Modulo para crear un coche (introducir y añadir al vector del sistema) (y asociarle un usuario (existente o nuevo)) ademas de obtenerlo como referencia 
 * @param Coche coches_del_sistema[]
 * @param int &util_coches_sistema
 * @param Usuario usuarios_del_sistema[]
 * @param int &util_usuarios_sistema
 * @param Coche &coche_aux
 * @date 2023-3-29
 * @version 1.5
 * @author DiosFer
 */
void crear_coche (Coche coches_del_sistema[], int &util_coches_sistema, Usuario usuarios_del_sistema[], int &util_usuarios_sistema, Coche &coche_aux);










/**         
 * @brief Modulo calcular la media de edad de usuarios
 * @param Usuario const Usuario u[], 
 * @param const int util_u
 * @return media_edad
 * @date 2023-3-30
 * @version 1.7
 * @author DiosFer
 */
double calcular_media_edad (const Usuario u[], const int util_u);


/**         
 * @brief Modulo calcular el total de asientos de los coches
 * @param const Coche c[]
 * @param const int util_c
 * @return total_asientos
 * @date 2023-3-30
 * @version 1.7
 * @author DiosFer
 */
int total_asientos (const Coche c[], const int util_c);



/**         
 * @brief Modulo calcular el total de asientos ofertados
 * @param const Viaje v[]
 * @param const int util_v
 * @return media_AO
 * @date 2023-3-30
 * @version 1.7
 * @author DiosFer
 */
double media_asientos_ofertados (const Viaje v[], const int util_v);




/**         
 * @brief Modulo calcular el total de asientos ofertados
 * @param const Viaje v[]
 * @param const int util_v
 * @return total_AO
 * @date 2023-3-30
 * @version 1.7
 * @author DiosFer
 */
int asientosOfertados_totales_viaje(const Viaje v[], const int util_v);



/**         
 * @brief Modulo calcular la desviacion de los asientos ofertados
 * @param const Viaje v[]
 * @param const int util_v
 * @return desviacion_AO
 * @date 2023-3-30
 * @version 1.7
 * @author DiosFer
 */
double desviacion_asientos_ofertados(const Viaje v[], const int util_v);



  /***************************************************************************************************************************************
  ****************************************************************   MAIN   **************************************************************
  ***************************************************************************************************************************************/
  //=====================================================================================================================================\\
 //_______________________________________________________________________________________________________________________________________\\
//_________________________________________________________________________________________________________________________________________\\

int main(){
  /**********************************************************************/
  ///     SISTEMA
  const int DIM_USUARIOS_SISTEMA=10;
  Usuario usuarios_del_sistema[DIM_USUARIOS_SISTEMA];
  int util_usuarios_sistema=0;

  const int DIM_COCHES_SISTEMA=10;
  Coche coches_del_sistema[DIM_COCHES_SISTEMA];
  int util_coches_sistema=0;

  const int DIM_TRAYECTOS_SISTEMA=10;
  Trayecto trayectos_del_sistema[DIM_TRAYECTOS_SISTEMA];
  int util_trayectos_sistema=0;

  const int DIM_VIAJES_SISTEMA=10;
  Viaje viajes_del_sistema[DIM_TRAYECTOS_SISTEMA];
  int util_viajes_sistema=0;

  ///     CARGA
  cargar_trayectos_del_sistema(trayectos_del_sistema, util_trayectos_sistema);
  cargar_coches_del_sistema (coches_del_sistema, util_coches_sistema);
  cargar_usuarios_del_sistema (usuarios_del_sistema, util_usuarios_sistema, coches_del_sistema);
  cargar_viajes_del_sistema (viajes_del_sistema, util_viajes_sistema, trayectos_del_sistema, coches_del_sistema);
  /**********************************************************************/


  int tipo_usuario=0;//0 admin 
  bool no_cierre_sesion=false;
  bool cierre_programa=false;
  Usuario usuario_actual;

  do{
    no_cierre_sesion=introducir_int_filtrado("Introduzca 1 para iniciar sesion o 0 para cerrar el programa: \n", -1, 2, "Error, no se admite la insercion\n");
    cin.clear();
    cin.ignore(10000, '\n');
    if (no_cierre_sesion){
      tipo_usuario=login(usuarios_del_sistema, util_usuarios_sistema, usuario_actual, DIM_USUARIOS_SISTEMA);
      if (tipo_usuario==0){
        menu_admin(usuarios_del_sistema, util_usuarios_sistema, coches_del_sistema, util_coches_sistema, trayectos_del_sistema, util_trayectos_sistema, viajes_del_sistema, util_viajes_sistema);
      }
      else{
        cout << BOLDRED<<"El sistema actualmente solo trabaja con ADMINISTRADORES"<<RESTORE<<endl;
      }
    }
    else {
      cierre_programa=true;
    }
    

  }while(cierre_programa==false);



}





/***************************************************************************************************************************************
****************************************************************************************************************************************
****************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/



double desviacion_asientos_ofertados(const Viaje v[], const int util_v){
  double desviacion_muestral=0.0;
  double aux=0.0;
  double aux2=0.0;
  double media= media_asientos_ofertados(v, util_v);

 for (int i=0; i<util_v; i++){

    aux2=get_numero_asiento_ofertados(v[i]);
    aux = aux + ((aux2-media) * (aux2-media));
 }
 aux = aux / (util_v-1);

   
  desviacion_muestral=sqrt (aux);





  return desviacion_muestral;


}


double media_asientos_ofertados (const Viaje v[], const int util_v){
  int aux=0;
  double aux2=0.0;

  aux=asientosOfertados_totales_viaje(v, util_v);
  aux2=aux;
  aux2=(aux2/(util_v));
  return aux2;
}


int asientosOfertados_totales_viaje(const Viaje v[], const int util_v){
  int aux=0;

  for (int i=0; i< util_v; i++){

    aux+=get_numero_asiento_ofertados(v[i]);

  }
  return aux;
}


double calcular_media_edad (const Usuario u[], const int util_u){
  int aux=0;
  double aux2=0.0;
  for (int i=0; i< util_u; i++){

    aux+=get_edad (u[i]);
  }

  aux2=aux;
  aux2=(aux2/(util_u-1));//-1 por el admin
  return aux2;
}




int total_asientos (const Coche c[], const int util_c){
  int aux=0;
  for (int i=0; i< util_c; i++){

    aux+=get_numero_asientos(c[i]);

  }
  return aux;
}



void crear_coche (Coche coches_del_sistema[], int &util_coches_sistema, Usuario usuarios_del_sistema[], int &util_usuarios_sistema, Coche &coche_aux){
  
  Usuario u_aux;

  introducir_coche(coche_aux);

  int P_actualUser=0;

  char aux_NU[DIM_CADENA_NORMAL_U];
  bool encontrado=false;

  bool nuevo=false;

  //Asignar usuario
  nuevo=introducir_int_filtrado("Desea asignar el coche a un usuario existente (0) o crear un nuevo usuario (1): ", -1, 2, "No permitido");
  cin.clear();
  cin.ignore(10000, '\n');

  if (nuevo==1){//creamos el usuario, le añadimos el coche y lo introducimos en el vector
    introducir_usuario_sin_coches(u_aux);
    set_nuevo_coche_usuario(u_aux, coche_aux);
    
    anadir_usuaro_a_vector_usuarios (u_aux, usuarios_del_sistema, util_usuarios_sistema);
  }
  else{

    do{//Insertar el coche en un usuario existente 

      introducir_cadena_numero_caracteres_filtrado ("Introduzca el nombre usuario para asignar el coche: \n", aux_NU, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
      P_actualUser=buscar_Posicion_usuario_por_nombre_usuario(aux_NU, usuarios_del_sistema, util_usuarios_sistema, encontrado);

      if (encontrado==false){
        cout << BOLDRED << "No se encontro un usuario con ese nombre usuario"<<endl<<RESTORE;
      }

    }while(encontrado==false);

    set_nuevo_coche_usuario (usuarios_del_sistema[P_actualUser], coche_aux);
  }

  set_anadir_coche_en_vector_coches (coches_del_sistema, coche_aux, util_coches_sistema);

}


void crear_trayecto(Trayecto &t_aux, Trayecto trayectos_del_sistema[], int &util_trayectos_sistema){
  introducir_trayecto(t_aux);
  anadir_trayecto_a_vector_trayectos(t_aux, trayectos_del_sistema, util_trayectos_sistema);
}



void modificar_viaje(Viaje viajes_del_sistema[], int &util_viajes_sistema){
  char aux_id_t[DIM_ID_TRAYECTO];
  char aux_id_c[DIM_ID_COCHE];


  char aux_id_t2[DIM_ID_TRAYECTO];
  char aux_id_c2[DIM_ID_COCHE];

  bool igual=false;

  Coche coche_aux;
  Trayecto trayecto_aux;

  int i=0;




  int eleccion=0;
  Time t_aux;
  Fecha f_aux;
  int aux=0;



  do{

    introducir_cadena_numero_caracteres_filtrado("Introduzca el id del coche del viaje que desea modificar: \n", aux_id_c, DIM_ID_COCHE, false, 0, false, 0, " ");
    introducir_cadena_numero_caracteres_filtrado("Introduzca el id del trayecto del viaje que desea modificar: \n", aux_id_t, DIM_ID_TRAYECTO, false, 0, false, 0, " ");

    i=0;
    for (; i<util_viajes_sistema && igual==false; i++){
      

      get_coche_que_viaja(viajes_del_sistema[i], coche_aux);
      get_trayecto_que_se_realiza(viajes_del_sistema [i], trayecto_aux);

      get_id_coche(coche_aux, aux_id_c2);
      get_id_trayecto(trayecto_aux, aux_id_t2);

      igual=comparar_cadenas(aux_id_c2, aux_id_c);
      if (igual){
        igual=comparar_cadenas(aux_id_t2, aux_id_t);
      }
      
    }
  }while (igual==false);

  i--;

  eleccion=introducir_int_filtrado("Que quieres modificar (1:fecha-salida 2:hora-salida 3:fecha-llegada 4:hora-llegada 5:Numero_asientos_ofertados): \n", 0, 6, "Eleccion no valida");
  if (eleccion==1){
    introducir_Fecha(f_aux);
    set_fecha_salida(viajes_del_sistema[i], f_aux);
  }
  else if (eleccion==2){
    Introducir_Time(t_aux);
    set_hora_salida(viajes_del_sistema[i], t_aux);
  }
  else if (eleccion==3){
    introducir_Fecha(f_aux);
    set_fecha_llegada(viajes_del_sistema[i], f_aux);
  }
  else if (eleccion==4){
    Introducir_Time(t_aux);
    set_hora_llegada(viajes_del_sistema[i], t_aux);
  }
  else if (eleccion==5){
    aux=introducir_int_filtrado("Introduzca el nuevo numero de asientos ofertados: \n", -1, 10, "Asientos no validos");
    set_numero_asiento_ofertados (viajes_del_sistema[i], aux);
  }
}




void eliminar_viaje(Viaje viajes_del_sistema[], int &util_viajes_sistema){//Posible modularizacion a futuro


  char aux_id_t[DIM_ID_TRAYECTO];
  char aux_id_c[DIM_ID_COCHE];


  char aux_id_t2[DIM_ID_TRAYECTO];
  char aux_id_c2[DIM_ID_COCHE];

  bool igual=false;

  Coche coche_aux;
  Trayecto trayecto_aux;

  int i=0;


  do{

    introducir_cadena_numero_caracteres_filtrado("Introduzca el id del coche del viaje que desea eliminar: \n", aux_id_c, DIM_ID_COCHE, false, 0, false, 0, " ");
    introducir_cadena_numero_caracteres_filtrado("Introduzca el id del trayecto del viaje que desea eliminar: \n", aux_id_t, DIM_ID_TRAYECTO, false, 0, false, 0, " ");

    i=0;
    for (; i<util_viajes_sistema && igual==false; i++){
      

      get_coche_que_viaja(viajes_del_sistema[i], coche_aux);
      get_trayecto_que_se_realiza(viajes_del_sistema [i], trayecto_aux);

      get_id_coche(coche_aux, aux_id_c2);
      get_id_trayecto(trayecto_aux, aux_id_t2);

      igual=comparar_cadenas(aux_id_c2, aux_id_c);
      if (igual){
        igual=comparar_cadenas(aux_id_t2, aux_id_t);
      }
      
    }
  }while (igual==false);

  i--;

  for(; i<util_viajes_sistema; i++){

    viajes_del_sistema[i]=viajes_del_sistema[i+1];

  }
  util_viajes_sistema--;

}




void CrearNuevoViaje (Usuario usuarios_del_sistema[], int &util_usuarios_sistema, Coche coches_del_sistema[], int &util_coches_sistema, Trayecto trayectos_del_sistema[], int &util_trayectos_sistema, Viaje viajes_del_sistema[], int &util_viajes_sistema){
  
  Fecha aux_f;
  Time aux_ti;

  int num_asi=0;

  char aux[DIM_ID_COCHE];

  char aux2[DIM_ID_TRAYECTO];

  bool nuevo=false;

  const int DIM_COCHE_BUSQUEDA=10;
  Coche coche_busqueda[DIM_COCHE_BUSQUEDA];
  int util_coche_busqueda=0;


  const int DIM_TRAYECTO_BUSQUEDA=10;
  Trayecto trayecto_busqueda[DIM_TRAYECTO_BUSQUEDA];
  int util_trayecto_busqueda=0;


  Coche coche_aux;
  Trayecto trayecto_aux;


  Viaje v;


  cout <<endl<< "     Introduzca la hora de salida del viaje: "<<endl<<endl;
  Introducir_Time (aux_ti);
  set_hora_salida (v, aux_ti);


  cout <<endl<< "     Introduzca la hora de llegada del viaje: "<<endl<<endl;
  Introducir_Time (aux_ti);
  set_hora_llegada (v, aux_ti);

  cout <<endl<< "     Introduzca la fecha de salida del viaje: "<<endl<<endl;
  introducir_Fecha (aux_f);
  set_fecha_salida (v, aux_f);

  cout <<endl<< "     Introduzca la fecha de llegada del viaje: "<<endl<<endl;
  introducir_Fecha (aux_f);
  set_fecha_llegada (v, aux_f);

  num_asi=introducir_int_filtrado("Introduzca el numero de asientos: \n", -1, 10, "Numero de asientos no valido");
  set_numero_asiento_ofertados(v, num_asi);
  cin.clear();
  cin.ignore(10000, '\n');



  nuevo=introducir_int_filtrado("Desea utilizar un coche ya creado o crear uno nuevo, seleccione 1 pera crear uno nuevo o 0 para usar una id existente: ", -1, 2, "No permitido");
  cin.clear();
  cin.ignore(10000, '\n');

  if (nuevo==1){
    crear_coche(coches_del_sistema, util_coches_sistema, usuarios_del_sistema, util_usuarios_sistema, coche_aux);//Con la misma cuestion de si quiere crear usuario nuevo o existente
    set_coche_que_viaja (v, coche_aux);
  }

  else{

    do{//Insertar coche existente en el nuevo viaje

      introducir_cadena_numero_caracteres_filtrado ("Introduzca el id del coche a introducir en el viaje: \n", aux, DIM_ID_COCHE, false, 0, false, 0, " ");
      buscar_coche_por_id_coche(aux, coches_del_sistema, util_coches_sistema, coche_busqueda, util_coche_busqueda);

      if (util_coche_busqueda==0){
        cout << BOLDRED << "No se encontro un coche con esa ID"<<endl<<RESTORE;
      }

    }while(util_coche_busqueda==0);
    set_coche_que_viaja (v, coche_busqueda[0]);
  }


  nuevo=introducir_int_filtrado("Desea utilizar un trayecto ya creado o crear uno nuevo, seleccione 1 para crear uno nuevo o 0 para usar una id existente: ", -1, 2, "No permitido");
  cin.clear();
  cin.ignore(10000, '\n');

  if (nuevo==1){
    crear_trayecto(trayecto_aux, trayectos_del_sistema, util_trayectos_sistema);
    set_trayecto_que_se_realiza (v, trayecto_aux);
  }
  else{

    do{//Insertar trayecto existente en el nuevo viaje

      introducir_cadena_numero_caracteres_filtrado ("Introduzca el id del trayecto a introducir en el viaje: \n", aux2, DIM_ID_TRAYECTO, false, 0, false, 0, " ");
      buscar_trayecto_por_id_trayecto(aux2, trayectos_del_sistema, util_trayectos_sistema, trayecto_busqueda, util_trayecto_busqueda);

      if (util_trayecto_busqueda==0){
        cout << BOLDRED << "No se encontro un trayecto con esa ID"<<endl<<RESTORE;
      }

    }while(util_trayecto_busqueda==0);
    set_trayecto_que_se_realiza (v, trayecto_busqueda[0]);
  }
  anadir_viaje_a_vector_viajes (v, viajes_del_sistema, util_viajes_sistema);
}


void menu_admin (Usuario usuarios_del_sistema[], int util_usuarios_sistema, Coche coches_del_sistema[], int util_coches_sistema, Trayecto trayectos_del_sistema[], int util_trayectos_sistema, Viaje viajes_del_sistema[], int util_viajes_sistema){
  int eleccion=0;

  do{
    cout <<BOLDGREEN<< endl<<endl<<"BLA BLA KING      by 1oDAM"<<endl;
    cout <<"FUNCIONALIDADES DEL ADMINISTRADOR: Tito Ferni"<<endl;
    cout <<"Pulse la tecla que desee para realizar una de las siguientes acciones:"<<endl;
    cout <<"—— OPCIONES GENERALES DEL SISTEMA ——"<<endl;
    cout << endl<<endl<<endl<<"# Presione 0 para cerrar sesion"<<endl;
    cout << "# Presione 1 para imprimir la situacion actual del sistema"<<endl;
    cout << "# Presione 2 para crear un nuevo viaje"<<endl;
    cout << "# Presione 3 para modificar un viaje existente"<<endl;
    cout << "# Presione 4 para eliminar un viaje"<<endl;
    cout << "# Presione 5 para eliminar un trayecto (se eliminaran los viajes asociados al mismo)"<<endl<<RESTORE;


    eleccion=introducir_int_filtrado("   # ", -1, 6, "Error, no se admite la eleccion\n");
    cin.clear();
    cin.ignore(10000, '\n');

    if(eleccion==0){
      //cierre
    }

    else if(eleccion==1){
      mostrar_sistema_actual(usuarios_del_sistema, util_usuarios_sistema, coches_del_sistema, util_coches_sistema, trayectos_del_sistema, util_trayectos_sistema, viajes_del_sistema, util_viajes_sistema);
    }

    else if (eleccion==2){
      CrearNuevoViaje(usuarios_del_sistema, util_usuarios_sistema, coches_del_sistema, util_coches_sistema, trayectos_del_sistema, util_trayectos_sistema, viajes_del_sistema, util_viajes_sistema);
    }

    else if (eleccion==3){
      modificar_viaje(viajes_del_sistema, util_viajes_sistema);
    }

    else if (eleccion==4){
      eliminar_viaje(viajes_del_sistema, util_viajes_sistema);
    }

    else if (eleccion==5){
      eliminar_trayecto(viajes_del_sistema, util_viajes_sistema, trayectos_del_sistema, util_trayectos_sistema);
    }

  }while(eleccion!=0);
}







int login(const Usuario usuarios_del_sistema[], const int util_usuarios_sistema, Usuario &usuario_actual, const int DIM_USUARIOS_SISTEMA){
  char usuario_a_buscar[DIM_CADENA_NORMAL_U];
  char contrasena_in[DIM_CADENA_NORMAL_U];
  char contrasena[DIM_CADENA_NORMAL_U];
  bool P_valida=false;
  char id_usuario [DIM_ID_USUARIO];//para comprobar si es admin

  bool es_admin=false;
  int type=0;

  bool fin=false;

  Usuario Usuario_encontrado [DIM_USUARIOS_SISTEMA];//No me gusta que en la busqueda de un vector pero lo realice asi por que lo ponia explicitamente en la tabla del excel
  int util_usuario_encontrado=0;

  do{
    introducir_cadena_numero_caracteres_filtrado("Introduzca el nombre_usuario: ", usuario_a_buscar, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    
    buscar_usuario_por_nombre_usuario (usuario_a_buscar, usuarios_del_sistema, util_usuarios_sistema, Usuario_encontrado, util_usuario_encontrado);

    

    if (util_usuario_encontrado==0){
      cout << "Usuario no encontrado" << endl;
    }

    else{
      usuario_actual=Usuario_encontrado[0];


      introducir_cadena_numero_caracteres_filtrado("Introduzca la contraseña: ", contrasena_in, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
      get_contrasena(usuario_actual, contrasena);// contraseña admin --> aD432789NkM


      P_valida=comparar_cadenas(contrasena_in, contrasena);

      if (P_valida){



        get_id_usuario(usuario_actual, id_usuario);
        es_admin=comparar_cadenas(id_usuario, "AD001");

        if (es_admin){
          type=0;
        }
        else{
          type=1;
        }
          
        fin=true;
      }

      else {

        cout << "Contraseña no valida"<<endl;

      }
    }
  }while(fin==false);
  return type;
}



void eliminar_trayecto(Viaje viajes_del_sistema[], int &util_viajes_sistema, Trayecto trayectos_del_sistema[], int &util_trayectos_sistema){
  Trayecto t_aux;
  char cadena_aux[DIM_ID_TRAYECTO]={'\0'};

  char id_trayecto_a_buscar[DIM_ID_TRAYECTO]={'\0'};

  bool igual=false;

  int i=0, i2=0, i2_aux=0;

  //Actualizamos los trayectos
  do{
    introducir_cadena_numero_caracteres_filtrado("Introduzca el id del trayecto para eliminar: \n", id_trayecto_a_buscar, DIM_ID_TRAYECTO, false, 0, false, 0, " ");

    i=0;
    for (; i<util_trayectos_sistema&& igual==false; i++){
      igual=false;

      get_id_trayecto(trayectos_del_sistema[i], cadena_aux);
      igual=comparar_cadenas(cadena_aux, id_trayecto_a_buscar);

    }
         
  }while (igual==false);
  i--;

  for(; i<util_trayectos_sistema; i++){

    copiar_trayecto (trayectos_del_sistema[i+1], trayectos_del_sistema[i]);

  }
  util_trayectos_sistema--;
  
  //Actualizamos los viajes asociados

  for (i2=0; i2<util_viajes_sistema; i2++){
    igual=false;

    get_trayecto_que_se_realiza(viajes_del_sistema[i2], t_aux);
    get_id_trayecto(t_aux, cadena_aux);

    igual=comparar_cadenas(cadena_aux, id_trayecto_a_buscar);


    if (igual){
      for(i2_aux=i2; i2_aux<util_viajes_sistema; i2_aux++){

        viajes_del_sistema[i2_aux]=viajes_del_sistema[i2_aux+1];

      }
      i2--;
      util_viajes_sistema--;
    }

  }

}




void mostrar_sistema_actual(const Usuario usuarios_del_sistema[], const int util_usuarios_sistema, const Coche coches_del_sistema[], const int util_coches_sistema, const Trayecto trayectos_del_sistema[], const int util_trayectos_sistema, const Viaje viajes_del_sistema[], const int util_viajes_sistema){
  
  int aux=0;
  double aux2=0;


  cout << endl <<endl<< endl<<BOLDRED; 
  cout <<"--------------------------------------"<<endl;
  cout <<"---------USUARIOS DEL SISTEMA---------"<<endl;
  cout <<"--------------------------------------"<<endl<<RESTORE;

  mostrar_vector_usuarios(usuarios_del_sistema, util_usuarios_sistema);

  cout <<BOLDMAGENTA<<"______________ESTADISTICAS____________"<<endl<<endl;
  cout << "Total_Usuarios = "<<util_usuarios_sistema-1<<endl;




  
  aux2=calcular_media_edad(usuarios_del_sistema, util_usuarios_sistema);

  cout << "Edad media usuarios = " << aux2 << endl;




  cout <<"______________________________________"<<endl<<endl<<RESTORE;

  cout << endl <<endl<< endl<<BOLDRED; 
  cout <<"--------------------------------------"<<endl;
  cout <<"---------TRAYECTOS DEL SISTEMA--------"<<endl;
  cout <<"--------------------------------------"<<endl<<RESTORE;

  mostrar_vector_trayectos(trayectos_del_sistema, util_trayectos_sistema);

  cout <<BOLDMAGENTA<<"______________ESTADISTICAS____________"<<endl<<endl;
  cout << "Total_Trayectos = "<<util_trayectos_sistema<<endl;
  cout <<"______________________________________"<<endl<<endl<<RESTORE;

  cout << endl <<endl<< endl<<BOLDRED; 
  cout <<"--------------------------------------"<<endl;
  cout <<"----------Coches DEL SISTEMA----------"<<endl;
  cout <<"--------------------------------------"<<endl<<RESTORE;

  mostrar_vector_coches(coches_del_sistema, util_coches_sistema);

  cout <<BOLDMAGENTA<<"______________ESTADISTICAS____________"<<endl<<endl;
  cout << "Total_Coches = "<<util_coches_sistema<<endl;


  aux=total_asientos(coches_del_sistema, util_coches_sistema);

  cout << "Total asientos maximos disponibles = " << aux << endl;


  cout <<"______________________________________"<<endl<<endl<<RESTORE;

  cout << endl <<endl<< endl<<BOLDRED; 
  cout <<"--------------------------------------"<<endl;
  cout <<"----------VIAJES DEL SISTEMA----------"<<endl;
  cout <<"--------------------------------------"<<endl<<RESTORE;

  mostrar_vector_viajes(viajes_del_sistema, util_viajes_sistema);

  cout <<BOLDMAGENTA<<"______________ESTADISTICAS____________"<<endl<<endl;

  aux=asientosOfertados_totales_viaje(viajes_del_sistema, util_viajes_sistema);

  cout << "Total_Asientos_ofertados = "<<aux<<endl;

  aux2=media_asientos_ofertados(viajes_del_sistema, util_viajes_sistema);

  cout << "Media asientos_ofertados por viaje = "<<aux2<<endl;

  aux2=desviacion_asientos_ofertados(viajes_del_sistema, util_viajes_sistema);

  cout << "Desviacion de asientos ofertadoes en un viaje = "<<aux2<<endl;

  cout << "Moda de los asientos ofertados en un viaje = "<<0<<endl;

  cout <<"______________________________________"<<endl<<endl<<RESTORE;

  cout << endl <<endl<< endl<<RESTORE; 
}


void cargar_viajes_del_sistema(Viaje viajes_del_sistema[], int &util_viajes_sistema, const Trayecto trayectos_del_sistema[], const Coche coches_del_sistema []){
  Viaje v_aux;
  Time t_aux;
  Fecha f_aux;


  //Viaje 1
  
  set_coche_que_viaja (v_aux, coches_del_sistema[0]);


  set_trayecto_que_se_realiza (v_aux, trayectos_del_sistema[0]);


  sethoraF12(t_aux, 5);
  setAm(t_aux, true);
  setminuto(t_aux, 30);
  setsegundo(t_aux, 0);

  set_hora_salida (v_aux, t_aux);



  sethoraF12(t_aux, 10);
  setAm(t_aux, true);
  setminuto(t_aux, 30);
  setsegundo(t_aux, 0);

  set_hora_llegada (v_aux, t_aux);




  set_dia(f_aux, 15);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_salida (v_aux, f_aux);



  set_dia(f_aux, 15);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_llegada (v_aux, f_aux);



  set_numero_asiento_ofertados(v_aux, 2);

  anadir_viaje_a_vector_viajes(v_aux, viajes_del_sistema, util_viajes_sistema);

  //Viaje 2
  
  set_coche_que_viaja (v_aux, coches_del_sistema[3]);


  set_trayecto_que_se_realiza (v_aux, trayectos_del_sistema[2]);


  sethoraF12(t_aux, 6);
  setAm(t_aux, true);
  setminuto(t_aux, 0);
  setsegundo(t_aux, 0);

  set_hora_salida (v_aux, t_aux);



  sethoraF12(t_aux, 3);
  setAm(t_aux, false);
  setminuto(t_aux, 0);
  setsegundo(t_aux, 0);

  set_hora_llegada (v_aux, t_aux);




  set_dia(f_aux, 4);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_salida (v_aux, f_aux);



  set_dia(f_aux, 4);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_llegada (v_aux, f_aux);



  set_numero_asiento_ofertados(v_aux, 1);

  anadir_viaje_a_vector_viajes(v_aux, viajes_del_sistema, util_viajes_sistema);

  //Viaje 3
  
  set_coche_que_viaja (v_aux, coches_del_sistema[4]);


  set_trayecto_que_se_realiza (v_aux, trayectos_del_sistema[1]);


  sethoraF12(t_aux, 10);
  setAm(t_aux, true);
  setminuto(t_aux, 0);
  setsegundo(t_aux, 0);

  set_hora_salida (v_aux, t_aux);



  sethoraF12(t_aux, 11);
  setAm(t_aux, true);
  setminuto(t_aux, 30);
  setsegundo(t_aux, 0);

  set_hora_llegada (v_aux, t_aux);




  set_dia(f_aux, 6);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_salida (v_aux, f_aux);



  set_dia(f_aux, 6);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_llegada (v_aux, f_aux);



  set_numero_asiento_ofertados(v_aux, 4);

  anadir_viaje_a_vector_viajes(v_aux, viajes_del_sistema, util_viajes_sistema);


  //Viaje 4
  
  set_coche_que_viaja (v_aux, coches_del_sistema[5]);


  set_trayecto_que_se_realiza (v_aux, trayectos_del_sistema[0]);


  sethoraF12(t_aux, 11);
  setAm(t_aux, false);
  setminuto(t_aux, 0);
  setsegundo(t_aux, 0);

  set_hora_salida (v_aux, t_aux);



  sethoraF12(t_aux, 3);
  setAm(t_aux, true);
  setminuto(t_aux, 0);
  setsegundo(t_aux, 0);

  set_hora_llegada (v_aux, t_aux);




  set_dia(f_aux, 7);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_salida (v_aux, f_aux);



  set_dia(f_aux, 8);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_llegada (v_aux, f_aux);



  set_numero_asiento_ofertados(v_aux, 4);

  anadir_viaje_a_vector_viajes(v_aux, viajes_del_sistema, util_viajes_sistema);


  //Viaje 5
  
  set_coche_que_viaja (v_aux, coches_del_sistema[1]);


  set_trayecto_que_se_realiza (v_aux, trayectos_del_sistema[0]);


  sethoraF12(t_aux, 9);
  setAm(t_aux, true);
  setminuto(t_aux, 0);
  setsegundo(t_aux, 0);

  set_hora_salida (v_aux, t_aux);



  sethoraF12(t_aux, 11);
  setAm(t_aux, true);
  setminuto(t_aux, 0);
  setsegundo(t_aux, 0);

  set_hora_llegada (v_aux, t_aux);




  set_dia(f_aux, 1);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_salida (v_aux, f_aux);



  set_dia(f_aux, 1);
  set_mes(f_aux, 4);
  set_ano(f_aux, 2023);
  set_fecha_llegada (v_aux, f_aux);



  set_numero_asiento_ofertados(v_aux, 5);

  anadir_viaje_a_vector_viajes(v_aux, viajes_del_sistema, util_viajes_sistema);




}







void cargar_trayectos_del_sistema(Trayecto trayectos_del_sistema[], int &util_trayectos_sistema){
  Trayecto t_aux;

  //Trayecto 1

  set_id_trayecto (t_aux, "GM01");
  

  set_destino (t_aux, "Madrid");


  set_origen (t_aux, "Granada");



  anadir_trayecto_a_vector_trayectos(t_aux, trayectos_del_sistema, util_trayectos_sistema);

    //Trayecto 2

  set_id_trayecto (t_aux, "SM02");
  

  set_destino (t_aux, "Málaga");


  set_origen (t_aux, "Sevilla");



  anadir_trayecto_a_vector_trayectos(t_aux, trayectos_del_sistema, util_trayectos_sistema);
   
  //Trayecto 3

  set_id_trayecto (t_aux, "GB03");
  

  set_destino (t_aux, "Barcelona");


  set_origen (t_aux, "Granada");



  anadir_trayecto_a_vector_trayectos(t_aux, trayectos_del_sistema, util_trayectos_sistema);


  //Trayecto 4

  set_id_trayecto (t_aux, "GC04");
  

  set_destino (t_aux, "Cádiz");


  set_origen (t_aux, "Granada");



  anadir_trayecto_a_vector_trayectos(t_aux, trayectos_del_sistema, util_trayectos_sistema);

   

    
  //Trayecto 5

  set_id_trayecto (t_aux, "TC05");
  

  set_destino (t_aux, "Coruña");


  set_origen (t_aux, "Toledo");



  anadir_trayecto_a_vector_trayectos(t_aux, trayectos_del_sistema, util_trayectos_sistema);

}



void cargar_usuarios_del_sistema (Usuario usuarios_del_sistema[], int &util_usuarios_sistema, const Coche coches_del_sistema[]){
  
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

  set_coche_usuario (user, coches_del_sistema [0], 0);
  set_coche_usuario (user, coches_del_sistema [1], 1);


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



  anadir_usuaro_a_vector_usuarios(user, usuarios_del_sistema, util_usuarios_sistema);

  //Usuario3  
  
  set_id_usuario (user, "MA962");

  set_DNI (user, "96458122L");

  set_carnet (user, 0);

  set_nombre_usuario (user, "marta1989");

  set_nombre (user, "Marta");

  set_apellido1 (user, "");

  set_apellido2 (user, "");

  set_edad (user, 19);

  set_movil (user, "248612357");

  set_contrasena (user, "martitagranada23");

  set_mail (user, "marta@mail.es ");

  set_util_coche_usuario (user, 0);

  

  anadir_usuaro_a_vector_usuarios(user, usuarios_del_sistema, util_usuarios_sistema);


  //Usuario4 
  
  set_id_usuario (user, "AN659");

  set_DNI (user, "65712362A");

  set_carnet (user, 1);

  set_nombre_usuario (user, "andreita99");

  set_nombre (user, "Andrea");

  set_apellido1 (user, "");

  set_apellido2 (user, "");

  set_edad (user, 45);

  set_movil (user, "951478963");

  set_contrasena (user, "gft1256Lo");

  set_mail (user, "andrea@mail.com  ");

  set_util_coche_usuario (user, 1);

    set_coche_usuario (user, coches_del_sistema [2], 0);


  anadir_usuaro_a_vector_usuarios(user, usuarios_del_sistema, util_usuarios_sistema);

  //Usuario5
  
  set_id_usuario (user, "GU573");

  set_DNI (user, "57641235J");

  set_carnet (user, 1);

  set_nombre_usuario (user, "guerreranomada15");

  set_nombre (user, "Laira");

  set_apellido1 (user, "");

  set_apellido2 (user, "");

  set_edad (user, 37);

  set_movil (user, "326458999");

  set_contrasena (user, "aj39821MuN");

  set_mail (user, "laira@hotmail.com");

  set_util_coche_usuario (user, 3);

  set_coche_usuario (user, coches_del_sistema [3], 0);
  set_coche_usuario (user, coches_del_sistema [4], 1);
  set_coche_usuario (user, coches_del_sistema [5], 2);

  anadir_usuaro_a_vector_usuarios(user, usuarios_del_sistema, util_usuarios_sistema);


  //Usuario6  
  
  set_id_usuario (user, "AD001");

  set_DNI (user, " ");

  set_carnet (user, 0);

  set_nombre_usuario (user, "admin");

  set_nombre (user, "TITO FERNI");

  set_apellido1 (user, " ");

  set_apellido2 (user, " ");

  set_edad (user, 0);

  set_movil (user, " ");

  set_contrasena (user, "aD432789NkM");

  set_mail (user, " ");

  set_util_coche_usuario (user, 0);

  //Tiene util null pero un id coche asociado, no lo acabo de pillar

  anadir_usuaro_a_vector_usuarios(user, usuarios_del_sistema, util_usuarios_sistema);

}


void cargar_coches_del_sistema (Coche coches_del_sistema[], int &util_coches_sistema){

  Coche c_aux;

  //Coche1

  set_id_coche (c_aux, "K144");
  
  set_marca (c_aux, "Kia");

  set_matricula (c_aux, "4567HJK");

  set_modelo (c_aux, "14F");

  set_numero_asientos (c_aux, 4);


  set_anadir_coche_en_vector_coches(coches_del_sistema, c_aux, util_coches_sistema);
  
  //Coche2
  set_id_coche (c_aux, "HI97");
  
  set_marca (c_aux, "Hyundai");

  set_matricula (c_aux, "9516MNJ");

  set_modelo (c_aux, "i30");

  set_numero_asientos (c_aux, 7);


  set_anadir_coche_en_vector_coches(coches_del_sistema, c_aux, util_coches_sistema);


  //Coche3
  set_id_coche (c_aux, "NG72i");
  
  set_marca (c_aux, "Nissan");

  set_matricula (c_aux, "7642ASD");

  set_modelo (c_aux, "GTR");

  set_numero_asientos (c_aux, 2);


  set_anadir_coche_en_vector_coches(coches_del_sistema, c_aux, util_coches_sistema);

  
  //Coche4
  set_id_coche (c_aux, "FS22");
  
  set_marca (c_aux, "Ferrari");

  set_matricula (c_aux, "2468NHY");

  set_modelo (c_aux, "Spider");

  set_numero_asientos (c_aux, 2);


  set_anadir_coche_en_vector_coches(coches_del_sistema, c_aux, util_coches_sistema);

  
  //Coche5
  set_id_coche (c_aux, "FF45");
  
  set_marca (c_aux, "Ford");

  set_matricula (c_aux, "4157JUY");

  set_modelo (c_aux, "Focus");

  set_numero_asientos (c_aux, 5);


  set_anadir_coche_en_vector_coches(coches_del_sistema, c_aux, util_coches_sistema);

  //Coche6
  set_id_coche (c_aux, "RC75");
  
  set_marca (c_aux, "Renault");

  set_matricula (c_aux, "7564IOP");

  set_modelo (c_aux, "Clio");

  set_numero_asientos (c_aux, 5);


  set_anadir_coche_en_vector_coches(coches_del_sistema, c_aux, util_coches_sistema);

  
  //Coche7
  set_id_coche (c_aux, "OC63");
  
  set_marca (c_aux, "Opel");

  set_matricula (c_aux, "6845AER");

  set_modelo (c_aux, "Corsa");

  set_numero_asientos (c_aux, 3);


  set_anadir_coche_en_vector_coches(coches_del_sistema, c_aux, util_coches_sistema);
  
}