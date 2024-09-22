#include <iostream>
#include <iomanip>
#include <cmath>

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

const bool DEBUG_C=true;

using namespace std;



const int DIM_CADENA_NORMAL_U=50; //Dimension para cadenas que no tienen un limite establecido (para nombres, correos, ...)
const int DIM_DNI=11;
const int DIM_TIPO_CARNET=5;
const int DIM_MOVIL=11;
const int DIM_ID_USUARIO=10;

const int DIM_CADENA_NORMAL_C=50;
const int DIM_ID_COCHE=9;



/***************************************************************************************************************************************
**************************************************************   STRUCT   **************************************************************
***************************************************************************************************************************************/


/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Usuario *
 ***************************************************************************************************************************************/


struct Usuario{

    char id_usuario[DIM_ID_USUARIO];
    char DNI[DIM_DNI];
    char carnet[DIM_TIPO_CARNET]; 
    char nombre_usuario [DIM_CADENA_NORMAL_U]; 

    char nombre [DIM_CADENA_NORMAL_U];
    char apellido1 [DIM_CADENA_NORMAL_U];
    char apellido2 [DIM_CADENA_NORMAL_U];

    int edad; 
    char movil[DIM_MOVIL]; 

    char contrasena[DIM_CADENA_NORMAL_U];
    char mail[DIM_CADENA_NORMAL_U];

};

/***************************************************************************************************************************************
                                                   * Definición del TIPO DE DATO Coche *
 ***************************************************************************************************************************************/

struct Coche{

    char id_coche[DIM_ID_COCHE];
    char marca[DIM_CADENA_NORMAL_C];
    char matricula[DIM_CADENA_NORMAL_C];
    char modelo[DIM_CADENA_NORMAL_C];
    int numero_asientos;

};

/***************************************************************************************************************************************
************************************************************   PROTOTIPOS   ************************************************************
***************************************************************************************************************************************/


/***************************************************************************************************************************************
                                                           * Modulos Tipo char *
 ***************************************************************************************************************************************/

/**
 * @brief Módulo que agrega un nuevo caracter al final de las componentes utilizadas
 * @param vector Es una referencia al vector 
 * @param i es la posicion en la que vamos a introducir el nuevo caracter
 * @param letra Es el nuevo caracter que quiero insertar en el vector.
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-02-13
 */
void agregarLetraACadena(char vector[], int i, char letra);


/**
 * @brief Módulo que calcula cual es la longuitud actual de una cadena de caracteres
 * @param cadena [] cadena de caracteres
 * @return longuitud (J(0)a(1)i(2)m(3)e(4)\0(5) --> longitud=5)
 * @version 0.3
 * @date 2023-02-13
 * @author Dios-Fer
 */
int get_Longitud (const char cadena []);

/**
 * @brief Módulo para copiar por completo un vector char en otro 
 * @pre longitud_vector < DIM_COPIA 
 * @param char vector[] (vector que se "copia")
 * @param char copia[] (vector en el que se "pega")
 * @post el vector copia en el otro vector
 * @version 0.1
 * @author Dios-Fer
 * @date 2023-03-13
 */
void copiarVector_char(const char vector[], char copia[]);

/**
 * @brief Módulo para introducir un vector char filtrando o no en funcion de dos booleanos el numero de caracteres tanto maximos como minimos o a eleccion
 * @param const char mensaje[] mensaje que se mostrara por pantalla antes de la introduccion de la cadena
 * @param char cadena[] cadena que se introduce (S)
 * @param const int DIM_AUX dimension de la cadena que introduciremos, en este caso al ser global se introducira desde el modulo que lo llame para su aislamiento 
 * @param bool minimo_establecido (true:se filtrara el minimo de carcteres)(false: no se filtrara el minimo de carcteres)
 * @param int minimo numero minimo de caracteres (no importara si minimo_establecido==false)
 * @param bool maximo_establecido (true:se filtrara el maximo de carcteres)(false: no se filtrara el maximo de carcteres)
 * @param int maximo numero maximo de caracteres (no importara si maximo_establecido==false)
 * @param const char mensaje_error[] mensaje que se mostrara por pantalla en caso de fallar con el numero de caracteres (no importara si ambos filtros estan desactivados)
 * @pre el minimo o maximo no puede superar la dimension
 * @pre min<=max
 * @version 0.3
 * @author Dios-Fer
 * @date 2023-03-14
 */
void introducir_cadena_numero_caracteres_filtrado (const char mensaje[], char cadena[], const int DIM_AUX, bool minimo_establecido, int minimo, bool maximo_establecido, int maximo, const char mensaje_error[]);


/***************************************************************************************************************************************
                                                           * Modulos Tipo int *
 ***************************************************************************************************************************************/


/**
 * @brief Modulo para la insercion de un numero filtrado
 * @param const char mensaje_entrada
 * @param int NoMenorA limite por abajo del numero que se quiere introducir
 * @param int NoMayorA limite por arriba del numero que se quiere introducir
 * @param const char mensaje_entrada
 * @return int numero 
 * @date 2023-03-13
 * @version 2.1
 * @author DiosFer
 */
int introducir_int_filtrado (const char mensaje_entrada[], int NoMenorA, int NoMayorA, const char mensaje_error[]);



/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Usuario *
 ***************************************************************************************************************************************/


/**
 * @brief Modulo que establece un valor concreto para el miembro id_usuario de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char id_usuario [] vector que se quiere introducir en el miembro id_usuario de la variable de tipo Usuario usuario
 * @date 2023-3-16
 * @version 0.4
 * @author DiosFer
 */
void set_id_usuario(Usuario &usuario, char id_usuario[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro DNI de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI [] vector que se quiere introducir en el miembro DNI de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_DNI(Usuario &usuario, char DNI[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro carnet de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char carnet [] vector que se quiere introducir en el miembro carnet de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_carnet (Usuario &usuario, char carnet[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro nombre_usuario de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre_usuario [] vector que se quiere introducir en el miembro nombre_usuario de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_nombre_usuario (Usuario &usuario, char nombre_usuario[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro nombre de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre [] vector que se quiere introducir en el miembro nombre de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_nombre (Usuario &usuario, char nombre[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro apellido1 de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido1 [] vector que se quiere introducir en el miembro apellido1 de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_apellido1 (Usuario &usuario, char apellido1[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro apellido2 de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido2 [] vector que se quiere introducir en el miembro apellido2 de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_apellido2 (Usuario &usuario, char apellido2[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro edad de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param int edad variable que se quiere introducir en el miembro edad de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_edad (Usuario &usuario, int edad);

/**
 * @brief Modulo que establece un valor concreto para el miembro movil de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char movil [] vector que se quiere introducir en el miembro movil de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_movil (Usuario &usuario, char movil[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro contrasena de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char contrasena [] vector que se quiere introducir en el miembro contrasena de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_contrasena (Usuario &usuario, char contrasena[]);

/**
 * @brief Modulo que establece un valor concreto para el miembro mail de una variable de tipo Usuario.
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char mail [] vector que se quiere introducir en el miembro mail de la variable de tipo Usuario usuario
 * @date 2023-3-13
 * @version 0.1
 * @author DiosFer
 */
void set_mail (Usuario &usuario, char mail[]);


/**
 * @brief Modulo para obtener el valor del miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char id_usuario_del_usuario [] vector en el que se guardara el resultado (en este caso el id_usuario del usuario introducido)
 * @date 2023-3-16
 * @version 0.4
 * @author DiosFer
 */
void get_id_usuario (const Usuario &usuario, char id_usuario_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_DNI (const Usuario &usuario, char DNI_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro carnet de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char carnet_del_usuario [] vector en el que se guardara el resultado (en este caso el carnet del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_carnet (const Usuario &usuario, char carnet_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro nombre_usuario de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre_usuario_del_usuario [] vector en el que se guardara el resultado (en este caso el nombre_usuario del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_nombre_usuario (const Usuario &usuario, char nombre_usuario_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro nombre de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char nombre_del_usuario [] vector en el que se guardara el resultado (en este caso el nombre del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_nombre (const Usuario &usuario, char nombre_del_usuario[]);


/**
 * @brief Modulo para obtener el valor del miembro apellido1 de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido1_del_usuario [] vector en el que se guardara el resultado (en este caso el apellido1 del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_apellido1 (const Usuario &usuario, char apellido1_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro apellido2 de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char apellido2_del_usuario [] vector en el que se guardara el resultado (en este caso el apellido2 del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_apellido2 (const Usuario &usuario, char apellido2_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro edad de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @return int usuario.edad
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
int get_edad (const Usuario &usuario);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_movil (const Usuario &usuario, char movil_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_contrasena (const Usuario &usuario, char contrasena_del_usuario[]);

/**
 * @brief Modulo para obtener el valor del miembro DNI de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario 
 * @param char DNI_del_usuario [] vector en el que se guardara el resultado (en este caso el DNI del usuario introducido)
 * @date 2023-3-15
 * @version 0.2
 * @author DiosFer
 */
void get_mail (const Usuario &usuario, char mail_del_usuario[]);

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Front*
 ***************************************************************************************************************************************/
    


/**
 * @brief Modulo para mostrar el valor de todos lo miembros de una variable de tipo Usuario
 * @param Usuario &usuario variable de tipo Usuario que se quiere mostrar
 * @date 2023-3-16
 * @version 0.4
 * @author DiosFer
 */
void mostrar_usuario (const Usuario &usuario);

/**
 * @brief Modulo para introducir todos los miembros de la variable de tipo Usuario introducida
 * @param Usuario &usuario variable de tipo Usuario que se quiere rellenar
 * @date 2023-3-16
 * @version 0.4
 * @author DiosFer
 */
void introducir_Usuario (Usuario &usuario);



/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Back*
 ***************************************************************************************************************************************/






  /***************************************************************************************************************************************
  ****************************************************************   MAIN   **************************************************************
  ***************************************************************************************************************************************/
  //=====================================================================================================================================\\
 //_______________________________________________________________________________________________________________________________________\\
//_________________________________________________________________________________________________________________________________________\\

int main(){
    
    Usuario usuario1;
    
    introducir_Usuario(usuario1);
    mostrar_usuario(usuario1);
    
}



/***************************************************************************************************************************************
**************************************************************   Codigo   **************************************************************
***************************************************************************************************************************************/


void agregarLetraACadena(char vector[], int i, char letra){

    vector[i] = letra;

}


int get_Longitud (const char cadena []){

    int longitud=0;

    while (cadena[longitud] != '\0'){
        longitud++;
    }

    return longitud;

}


void copiarVector_char(const char vector[], char copia[]){

    int longitud_vector=get_Longitud (vector);
    int j=0;

    for (int i=0; i<=longitud_vector; i++){
        agregarLetraACadena(copia, i, vector[i]);
    }
}


void introducir_cadena_numero_caracteres_filtrado (const char mensaje[], char cadena[], const int DIM_AUX, bool minimo_establecido, int minimo, bool maximo_establecido, int maximo, const char mensaje_error[]){
    int longitud=0;
    bool estabien=false;

    do{

        estabien=false;

        cout << mensaje<<endl;

        cin.getline(cadena, DIM_AUX, '\n');

        if (cin.fail()){//si se intenta leer una cantidad superior a la DIM_AUX se detendra y fallara
            cin.clear();
            cin.ignore(10000, '\n');
            estabien=false;
        }


        longitud=get_Longitud(cadena);


        if (minimo_establecido==true){
            if(longitud>=minimo){
                estabien=true;
            }
        }
        else{
            estabien=true;
        }
        if (estabien==true){
            if (maximo_establecido==true){
                if(longitud<=maximo){
                    estabien=true;
                }
                else{
                    estabien=false;
                }
            }
            else{
                estabien=true;
            }
        }

        if(!estabien){
            cout <<BOLDRED<< mensaje_error << endl<<RESTORE;
        }
        

    }while(!estabien);
    
}


/***************************************************************************************************************************************
                                                           * Modulos Tipo int *
 ***************************************************************************************************************************************/



int introducir_int_filtrado (const char mensaje_entrada[], int NoMenorA, int NoMayorA, const char mensaje_error[]){
    int numero=0;
    bool EstaBien=true;

    

    do{

        EstaBien=true;
        cout << mensaje_entrada;
        cin>>numero;

        if (numero<=NoMenorA || numero>=NoMayorA){
            EstaBien=false;
            cout << mensaje_error<<endl<<endl;
        }

        if(cin.fail()==1){

            cin.clear();
            cin.ignore(10000, '\n');

            cout << BOLDRED << "Por favor introduzca un numero"<<RESET<<endl<<endl;
            EstaBien=false;

        }


    }while(EstaBien==false);

    return numero;
}

/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Usuario *
 ***************************************************************************************************************************************/

void set_id_usuario(Usuario &usuario, char id_usuario[]){
    copiarVector_char(id_usuario, usuario.id_usuario);
}

void set_DNI(Usuario &usuario, char DNI[]){
    copiarVector_char(DNI, usuario.DNI);
}


void set_carnet (Usuario &usuario, char carnet[]){
    copiarVector_char(carnet, usuario.carnet);
}


void set_nombre_usuario (Usuario &usuario, char nombre_usuario[]){
    copiarVector_char(nombre_usuario, usuario.nombre_usuario);
}


void set_nombre (Usuario &usuario, char nombre[]){
    copiarVector_char(nombre, usuario.nombre);
}


void set_apellido1 (Usuario &usuario, char apellido1[]){
    copiarVector_char(apellido1, usuario.apellido1);
}


void set_apellido2 (Usuario &usuario, char apellido2[]){
    copiarVector_char(apellido2, usuario.apellido2);
}


void set_edad (Usuario &usuario, int edad){
    usuario.edad=edad;
}


void set_movil (Usuario &usuario, char movil[]){
    copiarVector_char(movil, usuario.movil);
}


void set_contrasena (Usuario &usuario, char contrasena[]){
    copiarVector_char(contrasena, usuario.contrasena);
}


void set_mail (Usuario &usuario, char mail[]){
    copiarVector_char(mail, usuario.mail);
}

void get_id_usuario (const Usuario &usuario, char id_usuario_del_usuario[]){
    copiarVector_char(usuario.id_usuario, id_usuario_del_usuario);
}


void get_DNI (const Usuario &usuario, char DNI_del_usuario[]){
    copiarVector_char(usuario.DNI, DNI_del_usuario);
}


void get_carnet (const Usuario &usuario, char carnet_del_usuario[]){
    copiarVector_char(usuario.carnet, carnet_del_usuario);
}


void get_nombre_usuario (const Usuario &usuario, char nombre_usuario_del_usuario[]){
    copiarVector_char(usuario.nombre_usuario, nombre_usuario_del_usuario);
}


void get_nombre (const Usuario &usuario, char nombre_del_usuario[]){
    copiarVector_char(usuario.nombre, nombre_del_usuario);
}



void get_apellido1 (const Usuario &usuario, char apellido1_del_usuario[]){
    copiarVector_char(usuario.apellido1, apellido1_del_usuario);
}


void get_apellido2 (const Usuario &usuario, char apellido2_del_usuario[]){
    copiarVector_char(usuario.apellido2, apellido2_del_usuario);
}


int get_edad (const Usuario &usuario){
    return usuario.edad;
}


void get_movil (const Usuario &usuario, char movil_del_usuario[]){
    copiarVector_char(usuario.movil, movil_del_usuario);
}


void get_contrasena (const Usuario &usuario, char contrasena_del_usuario[]){
    copiarVector_char(usuario.contrasena, contrasena_del_usuario);
}


void get_mail (const Usuario &usuario, char mail_del_usuario[]){
    copiarVector_char(usuario.mail, mail_del_usuario);
}

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Front*
 ***************************************************************************************************************************************/
    




void mostrar_usuario (const Usuario &usuario){
    char cadena_aux_dim_id_usuario[DIM_ID_USUARIO]={'\0'};
    char cadena_aux_dim_dni[DIM_DNI]={'\0'};
    char cadena_aux_dim_cadena_normal_u[DIM_CADENA_NORMAL_U]={'\0'};
    char cadena_aux_dim_tipo_carnet[DIM_TIPO_CARNET]={'\0'};
    char cadena_aux_dim_movil[DIM_MOVIL]={'\0'};
    int aux=0;

    get_id_usuario (usuario, cadena_aux_dim_id_usuario);
    cout <<"id_usuario--> "<< cadena_aux_dim_id_usuario << endl;

    get_DNI (usuario, cadena_aux_dim_dni);
    cout <<"DNI--> "<< cadena_aux_dim_dni << endl;

    get_carnet (usuario, cadena_aux_dim_tipo_carnet);
    cout <<"carnet--> "<< cadena_aux_dim_tipo_carnet << endl;

    get_nombre_usuario (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"nombre_usuario--> "<< cadena_aux_dim_cadena_normal_u << endl;

    get_nombre (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"nombre--> "<< cadena_aux_dim_cadena_normal_u << endl;

    get_apellido1 (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"apellido1--> "<< cadena_aux_dim_cadena_normal_u << endl;

    get_apellido2 (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"apellido2--> "<< cadena_aux_dim_cadena_normal_u << endl;

    aux=get_edad (usuario);
    cout <<"edad--> "<< aux<<endl;

    get_movil (usuario, cadena_aux_dim_movil);
    cout <<"movil--> "<< cadena_aux_dim_movil << endl;

    get_contrasena (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"contrasena--> "<< cadena_aux_dim_cadena_normal_u << endl;
    
    get_mail (usuario, cadena_aux_dim_cadena_normal_u);
    cout <<"mail--> "<< cadena_aux_dim_cadena_normal_u << endl;
}


void introducir_Usuario (Usuario &usuario){
    char cadena_aux_dim_id_usuario[DIM_ID_USUARIO]={'\0'};
    char cadena_aux_dim_dni[DIM_DNI]={'\0'};
    char cadena_aux_dim_cadena_normal_u[DIM_CADENA_NORMAL_U]={'\0'};
    char cadena_aux_dim_tipo_carnet[DIM_TIPO_CARNET]={'\0'};
    char cadena_aux_dim_movil[DIM_MOVIL]={'\0'};
    int aux=0;
    

    introducir_cadena_numero_caracteres_filtrado("Introduzca el id_usuario: ", cadena_aux_dim_id_usuario, DIM_ID_USUARIO, true, 8, true, 8, "No cumple con el tamaño establecido");
    set_id_usuario (usuario, cadena_aux_dim_id_usuario);
    
    introducir_cadena_numero_caracteres_filtrado("Introduzca el DNI: ", cadena_aux_dim_dni, DIM_DNI, true, 9, true, 9, "No cumple con el tamaño establecido");
    set_DNI (usuario, cadena_aux_dim_dni);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el carnet: ", cadena_aux_dim_tipo_carnet, DIM_TIPO_CARNET, false, 0, true, 3, "No cumple con el tamaño establecido");
    set_carnet (usuario, cadena_aux_dim_tipo_carnet);
    

    introducir_cadena_numero_caracteres_filtrado("Introduzca el nombre_usuario: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_nombre_usuario (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el nombre: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_nombre (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el apellido1: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_apellido1 (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el apellido2: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, " ");
    set_apellido2 (usuario, cadena_aux_dim_cadena_normal_u);


    aux=introducir_int_filtrado ("Introduce la edad: \n", 16, 120, "Edad no valida");
    set_edad (usuario, aux);
    cin.ignore(10000, '\n');

    introducir_cadena_numero_caracteres_filtrado("Introduzca el movil: ", cadena_aux_dim_movil, DIM_MOVIL, true, 9, true, 9, "No cumple con el tamaño establecido");
    set_movil (usuario, cadena_aux_dim_movil);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el contrasena: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, true, 8, false, 0, "No cumple con el tamaño establecido");
    set_contrasena (usuario, cadena_aux_dim_cadena_normal_u);


    introducir_cadena_numero_caracteres_filtrado("Introduzca el mail: ", cadena_aux_dim_cadena_normal_u, DIM_CADENA_NORMAL_U, false, 0, false, 0, "No cumple con el tamaño establecido");
    set_mail (usuario, cadena_aux_dim_cadena_normal_u);


    if (DEBUG_C==true){
        cout << DEBUG << "DEBUG"<<endl;
        mostrar_usuario(usuario);
        cout << "DEBUG"<<RESTORE<<endl;
    }

}


/***************************************************************************************************************************************
                                                        * Modulos de la estructura Usuario Back*
 ***************************************************************************************************************************************/





/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/