#include <iostream>
#include <string>
#define DEFAULT "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define YELLOW "\033[1;33m"      /* Yellow */
#define ERROR "\033[1;31m"
#define GREEN "\033[1;32m"      /* Green */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define BLUE "\033[1;34m"      /* Blue */
using namespace std;

/***************************************
** Definición del TIPO DE DATO Usuario **
****************************************/
struct Usuario{
    string id_usuario;
    string dni;
    string nombre; 
    int edad;
    //Fecha fecha_nacimiento;
};

//================================ PROTOTIPOS Y DOCUMENTACION SETS Y GETS DEL TDA USUARIO =============================



/**
 * @brief Modulo (set) (Por referencia) para el miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string id
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setIdUsuarioPorReferencia(Usuario &u, string id);

/**
 * @brief Modulo (set) (Por copia) para el miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string id
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setIdUsuarioPorCopia(Usuario u, string id);

/**
 * @brief Modulo (set) (Por puntero) para el miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string id
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setIdUsuarioPorCopiadePuntero(Usuario *u, string id);


/**
 * @brief Modulo (get) (Por referencia) para el miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getIdUsuarioPorReferencia(Usuario &u);

/**
 * @brief Modulo (get) (Por copia) para el miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getIdUsuarioPorCopia(Usuario u);

/**
 * @brief Modulo (get) (Por puntero) para el miembro id_usuario de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getIdUsuarioPorCopiadePuntero(Usuario *u);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Modulo (set) (Por referencia) para el miembro nombre de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string un_nombre
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setnombrePorReferencia(Usuario &u, string un_nombre);



/**
 * @brief Modulo (set) (Por copia) para el miembro nombre de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string un_nombre
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setnombrePorCopia(Usuario u, string un_nombre);



/**
 * @brief Modulo (set) (Por puntero) para el miembro nombre de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string un_nombre
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setnombrePorCopiadePuntero(Usuario *u, string un_nombre);


/**
 * @brief Modulo (get) (Por referencia) para el miembro nombre de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getnombrePorReferencia(Usuario &u);


/**
 * @brief Modulo (get) (Por copia) para el miembro nombre de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getnombrePorCopia(Usuario u);


/**
 * @brief Modulo (get) (Por puntero) para el miembro nombre de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getnombrePorCopiadePuntero(Usuario *u);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Modulo (set) (Por referencia) para el miembro dni de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string un_dni
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setdniPorReferencia(Usuario &u, string un_dni);


/**
 * @brief Modulo (set) (Por copia) para el miembro dni de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string un_dni
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setdniPorCopia(Usuario u, string un_dni);


/**
 * @brief Modulo (set) (Por puntero) para el miembro dni de una variable de tipo Usuario
 * @param Usuario &u 
 * @param string un_dni
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setdniPorCopiadePuntero(Usuario *u, string un_dni);



/**
 * @brief Modulo (get) (Por referencia) para el miembro dni de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getdniPorReferencia(Usuario &u);

/**
 * @brief Modulo (get) (Por copia) para el miembro dni de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getdniPorCopia(Usuario u);

/**
 * @brief Modulo (get) (Por puntero) para el miembro dni de una variable de tipo Usuario
 * @param Usuario &u 
 * @return string
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
string getdniPorCopiadePuntero(Usuario *u);




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Modulo (set) (Por referencia) para el miembro edad de una variable de tipo Usuario
 * @param Usuario &u 
 * @param int una_edad
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setEdadPorReferencia(Usuario &u, int una_edad);


/**
 * @brief Modulo (set) (Por copia) para el miembro edad de una variable de tipo Usuario
 * @param Usuario &u 
 * @param int una_edad
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setEdadPorCopia(Usuario u, int una_edad);


/**
 * @brief Modulo (set) (Por puntero) para el miembro edad de una variable de tipo Usuario
 * @param Usuario &u 
 * @param int una_edad
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void setEdadPorCopiadePuntero(Usuario *u, int una_edad);


/**
 * @brief Modulo (get) (Por referencia) para el miembro edad de una variable de tipo Usuario
 * @param Usuario &u 
 * @return int
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
int getEdadPorReferencia(Usuario &u);



/**
 * @brief Modulo (get) (Por copia) para el miembro edad de una variable de tipo Usuario
 * @param Usuario &u 
 * @return int
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
int getEdadPorCopia(Usuario u);



/**
 * @brief Modulo (get) (Por puntero) para el miembro edad de una variable de tipo Usuario
 * @param Usuario &u 
 * @return int
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
int getEdadPorCopiadePuntero(Usuario *u);



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






/**
 * @brief Modulo de impresion (Por copia) de un usuario
 * @param Usuario &u 
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void imprimirUsuarioPorCopiaEstática(Usuario u);


/**
 * @brief Modulo de impresion (Por referencia) de un usuario
 * @param Usuario &u 
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void imprimirUsuarioPorReferencia (Usuario &u);


/**
 * @brief Modulo de impresion (Por puntero) de un usuario
 * @param Usuario &u 
 * @date 2023-4-17
 * @version 0.1
 * @author DiosFer
 */
void imprimirUsuarioPorCopiaDelPuntero (Usuario *u);





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
int main(){

    Usuario u = {"1234U", "12345678K", "Fernando", 18 };//Inicializacion de purueba, futuro modulo para la introduccion

    Usuario otro_usuario, *ptr_u; //variable de tipo usuario y un puntero a usuario

    

    //Imprimimos con el identificador
    imprimirUsuarioPorCopiaEstática(u);
    imprimirUsuarioPorReferencia(u);



    ptr_u = &u; //asigno dirección de memoria de u a ptr_u

    //Imprimimos atraves del puntero
    imprimirUsuarioPorCopiaEstática(*ptr_u);
    imprimirUsuarioPorReferencia(*ptr_u);
    imprimirUsuarioPorCopiaDelPuntero(ptr_u);

}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setIdUsuarioPorReferencia(Usuario &u, string id){
    u.id_usuario = id;
}


void setIdUsuarioPorCopia(Usuario u, string id){
    u.id_usuario = id;
}


void setIdUsuarioPorCopiadePuntero(Usuario *u, string id){
    u->id_usuario = id;
}


string getIdUsuarioPorReferencia(Usuario &u){
    return u.id_usuario; 
}


string getIdUsuarioPorCopia(Usuario u){
    return u.id_usuario;
}


string getIdUsuarioPorCopiadePuntero(Usuario *u){
    return u->id_usuario;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setnombrePorReferencia(Usuario &u, string un_nombre){
    u.dni = un_nombre;
}


void setnombrePorCopia(Usuario u, string un_nombre){
    u.dni = un_nombre;
}


void setnombrePorCopiadePuntero(Usuario *u, string un_nombre){
    u->dni = un_nombre;
}


string getnombrePorReferencia(Usuario &u){
    return u.nombre; 
}


string getnombrePorCopia(Usuario u){
    return u.nombre;
}


string getnombrePorCopiadePuntero(Usuario *u){
    return u->nombre;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setdniPorReferencia(Usuario &u, string un_dni){
    u.dni = un_dni;
}


void setdniPorCopia(Usuario u, string un_dni){
    u.dni = un_dni;
}


void setdniPorCopiadePuntero(Usuario *u, string un_dni){
    u->dni = un_dni;
}


string getdniPorReferencia(Usuario &u){
    return u.dni; 
}


string getdniPorCopia(Usuario u){
    return u.dni;
}


string getdniPorCopiadePuntero(Usuario *u){
    return u->dni;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setEdadPorReferencia(Usuario &u, int una_edad){
    u.edad = una_edad;
}


void setEdadPorCopia(Usuario u, int una_edad){
    u.edad = una_edad;
}


void setEdadPorCopiadePuntero(Usuario *u, int una_edad){
    u->edad = una_edad;
}


int getEdadPorReferencia(Usuario &u){
    return u.edad; 
}


int getEdadPorCopia(Usuario u){
    return u.edad;
}


int getEdadPorCopiadePuntero(Usuario *u){
    return u->edad;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimirUsuarioPorCopiaEstática(Usuario u){
    cout << "imprimirUsuarioPorCopiaEstática --> " <<endl;
    cout << "ID: "<<getIdUsuarioPorCopia(u) << endl;
    cout << "DNI: "<<getdniPorCopia(u) << endl;
    cout << "Nombre: "<<getnombrePorCopia(u) << endl;
    cout << "Edad: "<<getEdadPorCopia(u) << endl;
    cout << endl << endl;
}


void imprimirUsuarioPorReferencia (Usuario &u){
    cout << "imprimirUsuarioPorReferencia --> " <<endl;
    cout << "ID: "<<getIdUsuarioPorReferencia(u) << endl;
    cout << "DNI: "<<getdniPorReferencia(u) << endl;
    cout << "Nombre: "<<getnombrePorReferencia(u) << endl;
    cout << "Edad: "<<getEdadPorReferencia(u) << endl;
    cout << endl << endl;
}


void imprimirUsuarioPorCopiaDelPuntero (Usuario *u){
    cout << "imprimirUsuarioPorPuntero --> " <<endl;
    cout << "ID: "<<getIdUsuarioPorCopiadePuntero(u) << endl;
    cout << "DNI: "<<getdniPorCopiadePuntero(u) << endl;
    cout << "Nombre: "<<getnombrePorCopiadePuntero(u) << endl;
    cout << "Edad: "<<getEdadPorCopiadePuntero(u) << endl;
    cout << endl << endl;
}