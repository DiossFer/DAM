#include <cstdlib>
#include <iostream>
#include <string>

#define RESTORE "\033[1;0m"
#define DEBUG "\033[1m\033[36m"
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

using namespace std;

const bool DEBUG_C = true;


/*********************************************************************************************************************************
 ********************************************************     struct     *********************************************************
 *********************************************************************************************************************************/


struct Fecha{
    int dia;
    string mes;
    int anio;
};



struct Alumno{

    string cod_alumno;
    string dni;

    string nombre;

    string apellido1;
    string apellido2;

    Fecha *fecha_nacimiento;


    float *notas;
    int dim_notas;
    int util_notas;


    //Asignaturas (lo mismo que notas pero con tipo string)

};

/*********************************************************************************************************************************
 **************************************     Basicos (Fecha) (create, drope, sets, gets)     **************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo (set) (Por Puntero) para el miembro dia de una variable de tipo Fecha
 * @param Fecha *f
 * @param int d
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
void setDiaFecha(Fecha *f, int d);


/**
 * @brief Modulo (set) (Por Puntero) para el miembro mes de una variable de tipo Fecha
 * @param Fecha *f
 * @param string m
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
void setMesFecha(Fecha *f, string m);



/**
 * @brief Modulo (set) (Por Puntero) para el miembro anio de una variable de tipo Fecha
 * @param Fecha *f
 * @param int a
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
void setAnioFecha(Fecha *f, int a);



/**
 * @brief Modulo (get) (Por Puntero) para el miembro dia de una variable de tipo Fecha
 * @param Fecha *f
 * @return int dia
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
int getDiaFecha(Fecha *f);

/**
 * @brief Modulo (get) (Por Puntero) para el miembro mes de una variable de tipo Fecha
 * @param Fecha *f
 * @return string mes
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
string getMesFecha(Fecha *f);

/**
 * @brief Modulo (get) (Por Puntero) para el miembro anio de una variable de tipo Fecha
 * @param Fecha *f
 * @return int anio
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
int getAnioFecha(Fecha *f);





/**
 * @brief Modulo crear una fecha dinamicamente
 * @return Fecha *f
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
Fecha* createFecha();




/**
 * @brief Modulo para eliminar una fecha dinamico y anularlo
 * @param Fecha *f
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
Fecha* dropFecha(Fecha *f);






/*********************************************************************************************************************************
 *************************************     Basicos (Alumno) (create, drope, sets, gets))     *************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo (set) (Por Puntero) para el miembro cod_alumno de una variable de tipo Alumno
 * @param Alumno *a
 * @param string cod_alumno
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
void set__cod_alumno__PorPuntero (Alumno *a, string un_cod_alumno);


/**
 * @brief Modulo (set) (Por Puntero) para el miembro dni de una variable de tipo Alumno
 * @param Alumno *a
 * @param string dni
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
void set__dni__PorPuntero (Alumno *a, string un_dni);


/**
 * @brief Modulo (set) (Por Puntero) para el miembro nombre de una variable de tipo Alumno
 * @param Alumno *a
 * @param string nombre
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
void set__nombre__PorPuntero (Alumno *a, string un_nombre);


/**
 * @brief Modulo (set) (Por Puntero) para el miembro apllido1 de una variable de tipo Alumno
 * @param Alumno *a
 * @param string apllido1
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
void set__apellido1__PorPuntero (Alumno *a, string un_apellido1);


/**
 * @brief Modulo (set) (Por Puntero) para el miembro apellido2 de una variable de tipo Alumno
 * @param Alumno *a
 * @param string apellido2
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
void set__apellido2__PorPuntero (Alumno *a, string un_apellido2);



/**
 * @brief Modulo para introducir la dim de un vector de notas en un alumno
 * @param Alumno *a
 * @param int una_dim_notas
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
void set__dim_notas(Alumno *a, int una_dim_notas);


/**
 * @brief Modulo para introducir la util de un vector de notas en un alumno
 * @param Alumno *a
 * @param int una_nota
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
void set__util_notas(Alumno *a, int una_dim_notas);

/**
 * @brief Modulo para introducir una nota en la ultima posicion de un vector de notas de un alumno
 * @param Alumno *a
 * @param float elemento
 * @return Alumno *a
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
Alumno* set__notaVectorNotas (Alumno *a, float elemento);




/**
 * @brief Modulo (get) (Por Puntero) para el miembro cod_alumn de una variable de tipo Alumno
 * @param Alumno *a
 * @return string cod_alumno
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
string get__cod_alumno__PorPuntero (Alumno *a);


/**
 * @brief Modulo (get) (Por Puntero) para el miembro dni de una variable de tipo Alumno
 * @param Alumno *a
 * @return string dni
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
string get__dni__PorPuntero (Alumno *a);


/**
 * @brief Modulo (get) (Por Puntero) para el miembro nombre de una variable de tipo Alumno
 * @param Alumno *a
 * @return string nombre
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
string get__nombre__PorPuntero (Alumno *a);


/**
 * @brief Modulo (get) (Por Puntero) para el miembro apellido1 de una variable de tipo Alumno
 * @param Alumno *a
 * @return string apellido1
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
string get__apellido1__PorPuntero (Alumno *a);


/**
 * @brief Modulo (get) (Por Puntero) para el miembro apellido2 de una variable de tipo Alumno
 * @param Alumno *a
 * @return string apellido2
 * @date 2023-4-18
 * @version 0.1
 * @author DiosFer
 */
string get__apellido2__PorPuntero (Alumno *a);


/**
 * @brief Modulo (get) (Por Puntero) el puntero fecha_nacimiento de alumno
 * @param Alumno *a
 * @return Fecha *f
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
Fecha* getFechaNacimientoAlumno(Alumno *a);





/**
 * @brief Modulo para el vector de notas de un alumno
 * @param Alumno *a
 * @return float *notas
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
float* getNotasVectorNotas(Alumno *a);



/**
 * @brief Modulo para una nota de un vector de alumnos
 * @param Alumno *a
 * @param int posicion
 * @return float nota
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
float get__NotaVectorNotas(Alumno *a, int posicion);



/**
 * @brief Modulo para obtener la dimension del vector de notas de un alumno
 * @param Alumno *a
 * @return int dim_notas
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
int getDimVectorNotas(Alumno *a);



/**
 * @brief Modulo para obtener la util del vector de notas de un alumno
 * @param Alumno *a
 * @return int util_vector
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
int getUtilVectorNotas(Alumno *a);


/**
 * @brief Modulo crear un alumno dinamicamente
 * @return *a
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
Alumno* createAlumno();



/**
 * @brief Modulo para eliminar un alumno dinamico y anularlo
 * @param Alumno *a
 * @return *a
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
Alumno* dropAlumno(Alumno *a);


/*********************************************************************************************************************************
 *************************************************     Modulos - Basicos - float    *************************************************
 *********************************************************************************************************************************/



/**
 * @brief Modulo para crear dinamicamente un vector de float
 * @param int dim_v
 * @return float *v
 * @date 2023-4-23
 * @version 0.4
 * @author DiosFer
 */
float* crearVectorFloat (int dim_v);


/**
 * @brief Modulo para elimniar y anular un vector de float
 * @param float *v
 * @return float *v
 * @date 2023-4-23
 * @version 0.4
 * @author DiosFer
 */
float* dropVectorFloat (float* v);







/*********************************************************************************************************************************
 ***********************************************     Modulos - Front - Fecha     *************************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo para mostrar por pantalla una fecha (Por Puntero)
 * @param Fecha *f
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
void printFecha(Fecha *f);


/**
 * @brief Modulo para la insercion de un alumno por pantalla (Por Puntero)
 * @param Fecha *f
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
void insertar_fecha_nac (Fecha *f);




/*********************************************************************************************************************************
 ***********************************************     Modulos - Front - Alumno     ************************************************
 *********************************************************************************************************************************/


/**
 * @brief Modulo para la insercion de un alumno por pantalla (Por Puntero)
 * @param Usuario &a
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
void insertarAlumno(Alumno *a);



/**
 * @brief Modulo para la salida de un alumno por pantalla (Por Puntero)
 * @param Alumno *a
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
void imprimirAlumno(Alumno *a);

/**
 * @brief Modulo para insertar el numero de notas y las notas para un vector de notas en un alumno
 * @param Alumno *a
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
void insertar_notas_alumno (Alumno *a);

/**
 * @brief Modulo para imprimir un vector de notas de un alumno
 * @param Alumno *a
 * @date 2023-4-25
 * @version 0.5
 * @author DiosFer
 */
void imprimir_notas_alumno (Alumno *a);


/*********************************************************************************************************************************
 *************************************************     Modulos - Back - Fecha    *************************************************
 *********************************************************************************************************************************/





/**
 * @brief Modulo para copiar en una fecha b lo que se encuentra en la fecha a
 * @param Alumno *f_b
 * @param Alumno *f_a
 * @date 2023-4-20
 * @version 0.3
 * @author DiosFer
 */
void copiarFecha_nac(Fecha *f_b, Fecha *f_a);







/*********************************************************************************************************************************
 ************************************************     Modulos - Back - Alumno    *************************************************
 *********************************************************************************************************************************/


/**
 * @brief Modulo para copiar un alumno a en uno b 
 * @param Alumno *a
 * @param Alumno *b
 * @date 2023-4-26
 * @version 0.6
 * @author DiosFer
 */
void CopiarAlumno(Alumno *a, Alumno *b);






/*********************************************************************************************************************************
 *************************************************     Modulos - Back - float    *************************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo para copiar un vector de float en otro, si no cabe se elimniara el sobrante
 * @param float v[]
 * @param int &util_v
 * @param float new_v[]
 * @param int new_dim_v
 * @date 2023-4-23
 * @version 0.4
 * @author DiosFer
 */
void copiarVectorFloat (float v[], int &util_v, float new_v[], int new_dim_v);



/**
 * @brief Modulo para expandir o reducir la dimension de un vector (crear nuevo (diferente dim), copiar en el nuevo y elimniar el antiguo)
 * @param int new_dim_v
 * @param float *v
 * @param int &util_v
 * @param int &dim_v
 * @return *v
 * @date 2023-4-23
 * @version 0.4
 * @author DiosFer
 */
float* resize(int new_dim_v, float *v, int &util_v, int &dim_v);



/**
 * @brief Modulo agregar un elemento a un vector de float dinamico y en caso de no caber extender su tamaño
 * @param float *v_dinamico
 * @param int &util_v_dinamico
 * @param int &DIM_V
 * @param float elemento
 * @param int extendido
 * @return *v
 * @date 2023-4-23
 * @version 0.4
 * @author DiosFer
 */
float* agregaElementoVectorFloat (float *v_dinamico, int &util_v_dinamico, int &DIM_V, float elemento, int extendido);




/*********************************************************************************************************************************
 *********************************     Basicos (Vector-Alumnos) (create, drope, sets, gets))     *********************************
 *********************************************************************************************************************************/


/**
 * @brief Modulo crear un vector de alumnos dinamico
 * @param int dim_a
 * @return Alumno *vector_alumno
 * @date 2023-4-27
 * @version 0.7
 * @author DiosFer
 */
Alumno* create_vector_alumnos(int dim_a);


/**
 * @brief Modulo eliminar un vector de alumnos dinamico
 * @param Alumno *vector_alumno
 * @param int dim_a
 * @return Alumno *vector_alumno
 * @date 2023-4-27
 * @version 0.7
 * @author DiosFer
 */
Alumno* drop_vector_alumnos(Alumno *vector_alumnos, int dim_a);




/*********************************************************************************************************************************
 ****************************************************     back (Vector-Alumnos)    ***********************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo para copiar un alumno de la manera convencional (sin agregar) por lo tanto se reuiere de espacio disponible
 * @pre Espacio disponible en el vector copia
 * @param Alumno *v_alumno_dinamico
 * @param int &util_a
 * @param Alumno *new_v_alumno_dinamico
 * @param int new_dim
 * @date 2023-4-28
 * @version 0.8
 * @author DiosFer
 */
void copiar_Vector_Alumno_con_espacio(Alumno *v_alumno_dinamico, int &util_a, Alumno *new_v_alumno_dinamico, int new_dim);


/**
 * @brief Modulo para redimensionar un vector de alumnos a una nueva dimension
 * @param int new_dim
 * @param Alumno *v_alumno_dinamico
 * @param int &util_a
 * @param int &dim_a
 * @post se tendra el mismo vector (datos) pero con mas dim 
 * @return Alumno*
 * @date 2023-4-28
 * @version 0.8
 * @author DiosFer
 */
Alumno* resize_vector_alumno(int new_dim, Alumno* v_alumno_dinamico, int &util_a, int &dim_a);


/**
 * @brief Modulo para agregar un alumno a un vector de alumnos
 * @param Alumno *v_alumno_dinamico
 * @param int &util_a
 * @param int &dim_a
 * @param Alumno un_alumno
 * @param int extendido
 * @return Alumno*
 * @date 2023-4-28
 * @version 0.8
 * @author DiosFer
 */
Alumno* agregarAlumnoVectorAlumno (Alumno *v_alumno_dinamico, int &util_a, int &dim_a, Alumno un_alumno, int extendido);


/**
 * @brief Modulo para copiar un vector de alumnos en otro independientemente del tamaño con el que cuente
 * @param Alumno *v_alumno_dinamico
 * @param int &util_a
 * @param Alumno *new_copia_v_alumno_dinamico
 * @param int &new_copia_dim
 * @param int &new_copia_util
 * @return Alumno*
 * @date 2023-4-28
 * @version 0.8
 * @author DiosFer
 */
Alumno* copiar_vector_alumnos_redimensionando (Alumno *v_alumno_dinamico, int util_a, Alumno *new_copia_v_alumno_dinamico, int &new_copia_dim, int &new_copia_util);




/*********************************************************************************************************************************
 ****************************************************     Front (Vector-Alumnos)    ***********************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo para insertar un vector de alumnos
 * @param Alumno *V_alumnos 
 * @param int &util_a
 * @param int &dim_a
 * @return Alumno*
 * @date 2023-4-28
 * @version 0.8
 * @author DiosFer
 */
Alumno* Insertar_Vector_Alumno (Alumno *V_alumnos, int &util_a, int &dim_a);




/**
 * @brief Modulo para imprimir un vector de alumnos
 * @param Alumno *V_alumnos 
 * @param int util_a
 * @date 2023-4-28
 * @version 0.8
 * @author DiosFer
 */
void imprimir_Vector_Alumno (Alumno *V_alumnos, int util_a);






/*********************************************************************************************************************************
 *************************************************     Front (Vector-PTR-Alumnos)      ********************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo para introducir un vector de ptr alumnos
 * @param Alumno **vector_ptr_alumnos
 * @param int &util_v_ptr_alumnos
 * @param int &dim_v_ptr_alumnos
 * @return Alumno** vector_ptr_alumnos
 * @date 2023-4-28
 * @version 1.0
 * @author DiosFer
 */
Alumno** introducir_vector_ptr_alumnos (Alumno **vector_ptr_alumnos, int &util_v_ptr_alumnos, int &dim_v_ptr_alumnos);

/**
 * @brief Modulo para introducir un vector de ptr alumnos
 * @param Alumno **vector_ptr_alumnos
 * @param int &util_v_ptr_alumnos
 * @date 2023-4-28
 * @version 1.0
 * @author DiosFer
 */
void imprimir_vector_ptr_alumnos (Alumno **vector_ptr_alumnos, int util_a);

/*********************************************************************************************************************************
 *************************************************     Back (Vector-PTR-Alumnos)      ********************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo para agregar un alumno a un puntero de un vector de punteros de alumnos
 * @param Alumno **vector_alumno_dinamico
 * @param int int &util_alumnos_dinamico, 
 * @param int int &dim_alumnos_dinamico, 
 * @param int Alumno un_alumno
 * @param int int extendido
 * @return Alumno**
 * @date 2023-4-28
 * @version 1.0
 * @author DiosFer
 */
Alumno** agregar_alumno_vector_PTR (Alumno **vector_alumno_dinamico, int &util_alumnos_dinamico, int &dim_alumnos_dinamico, Alumno un_alumno, int extendido);


/**
 * @brief Modulo para redimensionar un vector de punteros de alumno
 * @param int new_dim
 * @param Alumno** v_alumno_dinamico
 * @param int &util_a, int &dim_a
 * @return Alumno**
 * @date 2023-4-28
 * @version 1.0
 * @author DiosFer
 */
Alumno** resize_vector_alumno_ptr(int new_dim, Alumno** v_alumno_dinamico, int &util_a, int &dim_a);


/*********************************************************************************************************************************
 ***********************************************     Basicos (Vector-PTR-Alumnos)     ********************************************
 *********************************************************************************************************************************/

/**
 * @brief Modulo para crear un vector de punteros de tipo alumno (y lo asociado a este) (puntero a puntero)
 * @param int dim_vector_ptr_alumno
 * @return Alumno**
 * @date 2023-4-28
 * @version 1.0
 * @author DiosFer
 */
Alumno** create_vector_ptr_alumnos (int dim_vector_ptr_alumno);


/**
 * @brief Modulo para eliminar un vector de punteros de tipo alumno (y lo asociado a este) (puntero a puntero)
 * @param int dim_vector_ptr_alumno
 * @param Alumno** vector_ptr_alumno
 * @return Alumno**
 * @date 2023-4-28
 * @version 1.0
 * @author DiosFer
 */
Alumno** drop_vector_ptr_alumnos (Alumno** vector_ptr_alumno, int dim_vector_ptr_alumno);
















  /***************************************************************************************************************************************
  ****************************************************************   MAIN   **************************************************************
  ***************************************************************************************************************************************/

int main() {

    int dim_vector_ptr_alumno=3;
    int util_vector_ptr_alumno=0;
    
    Alumno** Prueba_vector_ptr_alumnos = create_vector_ptr_alumnos (dim_vector_ptr_alumno);


    Prueba_vector_ptr_alumnos=introducir_vector_ptr_alumnos (Prueba_vector_ptr_alumnos, util_vector_ptr_alumno, dim_vector_ptr_alumno);


    imprimir_vector_ptr_alumnos(Prueba_vector_ptr_alumnos, util_vector_ptr_alumno);

    Prueba_vector_ptr_alumnos = drop_vector_ptr_alumnos (Prueba_vector_ptr_alumnos, dim_vector_ptr_alumno);
    

}




/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/





























/*********************************************************************************************************************************
 **************************************     Basicos (Fecha) (create, drope, sets, gets)     **************************************
 *********************************************************************************************************************************/


void setDiaFecha(Fecha *f, int d){
    f->dia = d;
}


void setMesFecha(Fecha *f, string m){
    f->mes = m;
}


void setAnioFecha(Fecha *f, int a){
    f->anio = a;
}


int getDiaFecha(Fecha *f){
    return f->dia;
}


string getMesFecha(Fecha *f){
    return f->mes;
}


int getAnioFecha(Fecha *f){
    return f->anio;
}




Fecha* createFecha(){

    if (DEBUG_C){//DEBUG
        cout <<DEBUG<< "DEBUG: Creando fecha dinámica..." << endl<<RESTORE;
    }

    Fecha *una_fecha = new Fecha; //fecha dinámica

    if (una_fecha == NULL){
        cout << "No hay memoria disponible" << endl;
        exit(1);
    }

    if (DEBUG_C){//DEBUG
        cout <<DEBUG<< "DEBUG: Asignación de Memoria de la fecha realizada..." <<RESTORE<< endl;
    }

    return una_fecha;

}

Fecha* dropFecha(Fecha *f){
    if (DEBUG_C){
        cout <<DEBUG<< "DEBUG: Liberando memoria de la fecha..." <<RESTORE<< endl;
    }
    
    delete f;
    f = NULL; //puntero nulo

    if (DEBUG_C){
        cout<<DEBUG << "DEBUG: Memoria de la fecha liberada y puntero anulado..." <<RESTORE<< endl;
    }
    
    return f;
}




/*********************************************************************************************************************************
 *************************************     Basicos (Alumno) (create, drope, sets, gets))     *************************************
 *********************************************************************************************************************************/






void set__cod_alumno__PorPuntero (Alumno *a, string un_cod_alumno){
    a->cod_alumno=un_cod_alumno;
}

void set__dni__PorPuntero (Alumno *a, string un_dni){
    a->dni=un_dni;
}

void set__nombre__PorPuntero (Alumno *a, string un_nombre){
    a->nombre=un_nombre;
}

void set__apellido1__PorPuntero (Alumno *a, string un_apellido1){
    a->apellido1=un_apellido1;
}

void set__apellido2__PorPuntero (Alumno *a, string un_apellido2){
    a->apellido2=un_apellido2;
}

void set__dim_notas(Alumno *a, int una_dim_notas){
    a->dim_notas=una_dim_notas;
}
void set__util_notas(Alumno *a, int una_dim_notas){
    a->util_notas=una_dim_notas;
}

Alumno* set__notaVectorNotas (Alumno *a, float elemento){
    a->notas = agregaElementoVectorFloat (a->notas, a->util_notas, a->dim_notas, elemento, 1);//la dimension se actualizara de 1 en 1
    return a;
}


string get__cod_alumno__PorPuntero (Alumno *a){
    return a->cod_alumno;
}



string get__dni__PorPuntero (Alumno *a){
    return a->dni;
}



string get__nombre__PorPuntero (Alumno *a){
    return a->nombre;
}



string get__apellido1__PorPuntero (Alumno *a){
    return a->apellido1;
}



string get__apellido2__PorPuntero (Alumno *a){
    return a->apellido2;
}


Fecha* getFechaNacimientoAlumno(Alumno *a){
    return a->fecha_nacimiento;
}

float* getNotasVectorNotas(Alumno *a){
    return a->notas;
}
float get__NotaVectorNotas(Alumno *a, int posicion){
    return a->notas[posicion];
}

int getDimVectorNotas(Alumno *a){
    return a->dim_notas;
    
}

int getUtilVectorNotas(Alumno *a){
    return a->util_notas;
}





Alumno* createAlumno(){
    if (DEBUG_C){
        cout <<DEBUG<< "DEBUG: Creando alumno dinámico..." <<RESTORE<< endl;
    }

    //Creo el alumno dinamico
    Alumno *un_alumno = new Alumno;

    if (un_alumno == NULL){
        cout << "No hay memoria disponible" << endl;
        exit(1);
    }

    //Creo la fecha de nacimiento del alumno que es dinámica
    un_alumno->fecha_nacimiento = createFecha();


    set__dim_notas(un_alumno, 5);//Dim de 5 al comenzar




    set__util_notas (un_alumno, 0);//Util a 0






    un_alumno->notas=crearVectorFloat(getDimVectorNotas(un_alumno));//Creamos el vector con nuestras utiles (en este caso las que estan por defecto justo arriba)


    if (DEBUG_C){
        cout<<DEBUG<<BOLDGREEN << "DEBUG: Asignación de Memoria del alumno realizada..." <<RESTORE<< endl;
    }


    return un_alumno;
}



Alumno* dropAlumno(Alumno *a){
    if (DEBUG_C){
        cout <<DEBUG<< "DEBUG: Liberando memoria del alumno..." <<RESTORE<< endl;
    }
    
    //Elimino la fecha de nacimiento del alumno
    a->fecha_nacimiento = dropFecha(a->fecha_nacimiento);


    a->notas=dropVectorFloat(a->notas);

    //Elimino el alumno
    delete a;

    a = NULL; //puntero nulo
    if (DEBUG_C){
        cout <<DEBUG<< "DEBUG: Memoria del alumno liberada y puntero anulado..." <<RESTORE<< endl;
    }
    
    return a;    
}



/*********************************************************************************************************************************
 *************************************************     Modulos - Basicos - float    **********************************************
 *********************************************************************************************************************************/


float* crearVectorFloat (int dim_v){
    if (DEBUG_C){
	    cout <<DEBUG<< "DEBUG reservando la memoria para el vector float"<<RESTORE<<endl;
    }
	

	float* v = NULL;
    v = new float[dim_v];

	if (v==NULL){
		cout<<DEBUG << "No hay memoria disponible"<<RESTORE<<endl;
		exit(1);
	}
	
	if (DEBUG_C){
	    cout <<DEBUG<< "DEBUG creado el vector de float"<<RESTORE<<endl;
    }
	
	return v;
}

float* dropVectorFloat (float* v){

	if (DEBUG_C){

	    cout <<DEBUG<< "DEBUG: elimninando vector float"<<RESTORE<<endl;

	}

	delete [] v;
	
	v=NULL;

	if (DEBUG_C){
	    cout <<DEBUG<< "DEBUG: elimninado y anulado el vector float"<<RESTORE<<endl;
	}
	
	return v;
}


/*********************************************************************************************************************************
 ***********************************************     Modulos - Front - Fecha     *************************************************
 *********************************************************************************************************************************/


void printFecha(Fecha *f){
    cout << f->dia << "/" << f->mes << "/" << f->anio << endl;
}

void insertar_fecha_nac (Fecha *f){
    int aux_int;
    string aux_string;

    cout << "Inserte el dia: ";
    cin >> aux_int;
    setDiaFecha (f, aux_int);

    cout << "Inserte el mes: ";
    cin >> aux_string;
    setMesFecha (f, aux_string);

    cout << "Inserte el anio: ";
    cin >> aux_int;
    setAnioFecha (f, aux_int);
}




/*********************************************************************************************************************************
 ***********************************************     Modulos - Front - Alumno     ************************************************
 *********************************************************************************************************************************/




void insertarAlumno(Alumno *a){

    string aux_string;

    cout << "cod_alumno: ";
    cin >> aux_string;
    set__cod_alumno__PorPuntero(a, aux_string);
    
    cout << "dni: ";
    cin >> aux_string;
    set__dni__PorPuntero(a, aux_string);

    
    cout << "nombre: ";
    cin >> aux_string;
    set__nombre__PorPuntero(a, aux_string);

    
    cout << "apellido1: ";
    cin >> aux_string;
    set__apellido1__PorPuntero(a, aux_string);
    
    cout << "apellido2: ";
    cin >> aux_string;
    set__apellido2__PorPuntero(a, aux_string);

    
    insertar_fecha_nac(getFechaNacimientoAlumno(a));

    insertar_notas_alumno (a);



    //Asignaturas

    
}

void imprimirAlumno(Alumno *a){

    cout << BOLDCYAN;

    cout << "cod_alumno: " << get__cod_alumno__PorPuntero(a) << endl;
    cout << "dni: " << get__dni__PorPuntero(a) << endl;

    cout << "nombre: " << get__nombre__PorPuntero(a) << endl;

    cout << "apellido1: " << get__apellido1__PorPuntero(a) << endl;
    cout << "apellido2: " << get__apellido2__PorPuntero(a) << endl;

    cout << "fecha_nac: ";
    printFecha(getFechaNacimientoAlumno(a));

    imprimir_notas_alumno(a);

    
    //Asignaturas
    
    cout << RESTORE;
}



void imprimir_notas_alumno (Alumno *a){

    int i=getUtilVectorNotas(a);

    for (int j=0; j<i; j++){
        cout << "Nota ["<<j<<"] = "<<get__NotaVectorNotas(a, j)<<endl;
    }

    cout << endl;
}





/*********************************************************************************************************************************
 *************************************************     Modulos - Front - float    *************************************************
 *********************************************************************************************************************************/

//dim esta creada antes del create
//

void insertar_notas_alumno (Alumno *a){
    
    int aux_util=0;
    float aux=0.0;
    a->util_notas=0;

    cout << "Introduzca el numero de notas que se introducira: ";
    cin >> aux_util;

    for (a->util_notas = 0; a->util_notas<aux_util; ){

        cout << "Introduzca la nota: "<<endl;
        cin >> aux;

        a=set__notaVectorNotas (a, aux);
    }

}









/*********************************************************************************************************************************
 *************************************************     Modulos - Back - Fecha    *************************************************
 *********************************************************************************************************************************/



void copiarFecha_nac(Fecha *f_b, Fecha *f_a){
    setDiaFecha(f_b,getDiaFecha(f_a)); 
    setMesFecha(f_b,getMesFecha(f_a)); 
    setAnioFecha(f_b,getAnioFecha(f_a)); 
}



/*********************************************************************************************************************************
 ************************************************     Modulos - Back - Alumno    *************************************************
 *********************************************************************************************************************************/





void CopiarAlumno(Alumno *a, Alumno *b){
    set__cod_alumno__PorPuntero(b, get__cod_alumno__PorPuntero(a));
    set__dni__PorPuntero(b, get__dni__PorPuntero(a));
    set__nombre__PorPuntero(b, get__nombre__PorPuntero(a));
    set__apellido1__PorPuntero(b, get__apellido1__PorPuntero(a));
    set__apellido2__PorPuntero(b, get__apellido2__PorPuntero(a));
    



    copiarFecha_nac (getFechaNacimientoAlumno(b), getFechaNacimientoAlumno(a));

    for (int i=0; i<getUtilVectorNotas(a); i++){
        b->notas=agregaElementoVectorFloat(b->notas, b->util_notas, b->dim_notas, get__NotaVectorNotas(a, i), 1);
    }

    //Asignaturas

}



/*********************************************************************************************************************************
 *************************************************     Modulos - Back - float    *************************************************
 *********************************************************************************************************************************/
void copiarVectorFloat (float v[], int &util_v, float new_v[], int new_dim_v){
    int i=0;
    //Copiamos siempre que no se llegue a las utiles y halla hueco en el vector
    for (i=0; ((i<util_v) && (i<new_dim_v)); i++){
        new_v[i]=v[i];
    }

    if (i==new_dim_v){
        util_v=new_dim_v;
    }

}

float* resize(int new_dim_v, float *v, int &util_v, int &dim_v){


    //Creamos el nuevo vector
    float *new_v_dinamico=NULL;
    new_v_dinamico = crearVectorFloat(new_dim_v);
	
    //Copiamos el antiguo en el nuevo
    copiarVectorFloat(v, util_v, new_v_dinamico, new_dim_v);

    //Eliminamos el antiguo
	v = dropVectorFloat(v);


    //Actualizamos la dimension 
    dim_v = new_dim_v;

    

    //Devolvemos el nuevo
    return new_v_dinamico;

}


float* agregaElementoVectorFloat (float *v_dinamico, int &util_v_dinamico, int &DIM_V, float elemento, int extendido){

	if (util_v_dinamico<DIM_V){
		v_dinamico[util_v_dinamico]=elemento;
		util_v_dinamico++;
	}

	else{
		
        //añadimos extendido a la dimension
		v_dinamico=resize(DIM_V+extendido, v_dinamico, util_v_dinamico, DIM_V);

        //continuamos con la insercion
        v_dinamico[util_v_dinamico]=elemento;
		util_v_dinamico++;
		
	}
	return v_dinamico;
}

/*********************************************************************************************************************************
 *********************************     Basicos (Vector-Alumnos) (create, drope, sets, gets))     *********************************
 *********************************************************************************************************************************/

Alumno* create_vector_alumnos(int dim_a){
   

    if (DEBUG_C){
	    cout <<DEBUG<< "DEBUG reservando la memoria para el vector de alumnos"<<RESTORE<<endl;
    }
	

	Alumno* a = NULL;
    a = new Alumno[dim_a];

	if (a==NULL){
		cout << "No hay memoria disponible"<<endl;
		exit(1);
	}


    ///For recorriendolo y asignandolo

    for (int i=0; i<dim_a; i++){

        //creamos fecha
        a[i].fecha_nacimiento = createFecha();

        //asignamos dim_nota
        set__dim_notas(&a[i], 5);//Dim de 5 al comenzar

        //asignamos util_nota
        set__util_notas (&a[i], 0);//Util a 0

        //Creamos el vector notas
        a[i].notas=crearVectorFloat(getDimVectorNotas(&a[i]));//Creamos el vector con nuestras utiles (en este caso las que estan por defecto justo arriba)

    }
    


	if (DEBUG_C){
	    cout <<DEBUG<< "DEBUG creado el vector de alumnos"<<RESTORE<<endl;
    }
	
	return a;

}

Alumno* drop_vector_alumnos(Alumno *vector_alumnos, int dim_a){
    if (DEBUG_C){
        cout <<DEBUG<< "DEBUG: Liberando memoria del vector de alumnos..." <<RESTORE<< endl;
    }
    
    //Elimino la fecha de nacimiento de los alumnos
    for (int i=0; i<dim_a; i++){
        vector_alumnos[i].fecha_nacimiento = dropFecha(vector_alumnos[i].fecha_nacimiento);
        vector_alumnos[i].notas=dropVectorFloat(vector_alumnos[i].notas);
    }
    


    
    
    //Elimino el alumno
    delete [] vector_alumnos;

    vector_alumnos = NULL; //puntero nulo

    if (DEBUG_C){
        cout <<DEBUG<< "DEBUG: Memoria del alumno liberada y puntero anulado..." <<RESTORE<< endl;
    }
    
    return vector_alumnos; 
}




/*********************************************************************************************************************************
 ****************************************************     back (Vector-Alumnos)    ***********************************************
 *********************************************************************************************************************************/

void copiar_Vector_Alumno_con_espacio(Alumno *v_alumno_dinamico, int &util_a, Alumno *new_v_alumno_dinamico, int new_dim){
    int i=0;
    for (i=0; ((i<util_a) && (i<new_dim)); i++) {
        CopiarAlumno(&v_alumno_dinamico[i], &new_v_alumno_dinamico[i]);
    }

    if (i==new_dim){
        util_a=new_dim;
    }
}


Alumno* resize_vector_alumno(int new_dim, Alumno* v_alumno_dinamico, int &util_a, int &dim_a){
    //Creamos el nuevo vector
    Alumno *new_v_alumno_dinamico=NULL;
    new_v_alumno_dinamico = create_vector_alumnos(new_dim);
	
    //Copiamos el antiguo en el nuevo
    copiar_Vector_Alumno_con_espacio(v_alumno_dinamico, util_a, new_v_alumno_dinamico, new_dim);

    //Eliminamos el antiguo
	v_alumno_dinamico = drop_vector_alumnos(v_alumno_dinamico, dim_a);


    //Actualizamos la dimension 
    dim_a = new_dim;

    

    //Devolvemos el nuevo
    return new_v_alumno_dinamico;

}

Alumno* agregarAlumnoVectorAlumno (Alumno *v_alumno_dinamico, int &util_a, int &dim_a, Alumno un_alumno, int extendido){

	if (util_a<dim_a){
        CopiarAlumno(&un_alumno, &v_alumno_dinamico[util_a]);
		util_a++;

	}

	else{
		
        //añadimos extendido a la dimension
		v_alumno_dinamico=resize_vector_alumno(dim_a+extendido, v_alumno_dinamico, util_a, dim_a);

        //continuamos con la insercion
        CopiarAlumno(&un_alumno, &v_alumno_dinamico[util_a]);
		util_a++;

	}

	return v_alumno_dinamico;
}



Alumno* copiar_vector_alumnos_redimensionando (Alumno *v_alumno_dinamico, int util_a, Alumno *new_copia_v_alumno_dinamico, int &new_copia_dim, int &new_copia_util){
    
    new_copia_util=0;

    for (int i=0; i<util_a;i++){
        new_copia_v_alumno_dinamico=agregarAlumnoVectorAlumno (new_copia_v_alumno_dinamico, new_copia_util, new_copia_dim, v_alumno_dinamico[i], 1);
    }
    return new_copia_v_alumno_dinamico;
}



/*********************************************************************************************************************************
 ****************************************************     Front (Vector-Alumnos)    ***********************************************
 *********************************************************************************************************************************/


Alumno* Insertar_Vector_Alumno (Alumno *V_alumnos, int &util_a, int &dim_a){

    int aux_util=0;
    Alumno *aux_alumn=createAlumno();


    cout << "Introduzca el numero de alumnos que se introducira: ";
    cin >> aux_util;

    for (util_a = 0; util_a<aux_util; ){

        insertarAlumno(aux_alumn);

        V_alumnos=agregarAlumnoVectorAlumno(V_alumnos, util_a, dim_a, *aux_alumn,1);

    }

    aux_alumn=dropAlumno(aux_alumn);
    return V_alumnos;
}

void imprimir_Vector_Alumno (Alumno *V_alumnos, int util_a){
    for (int i=0; i<util_a; i++){
        cout <<endl<<endl<<endl<<BOLDBLUE<< "Alumno "<<i<<": "<<endl<<endl<<RESTORE;
        imprimirAlumno(&V_alumnos[i]);
    }
    
}





/*********************************************************************************************************************************
 ***********************************************     Basicos (Vector-PTR-Alumnos)     ********************************************
 *********************************************************************************************************************************/

Alumno** create_vector_ptr_alumnos (int dim_vector_ptr_alumno){

    Alumno **vector_ptr_alumno=new Alumno* [dim_vector_ptr_alumno];


    for (int i=0; i<dim_vector_ptr_alumno; i++){
        vector_ptr_alumno[i]=createAlumno();
    }

    return vector_ptr_alumno;
}

Alumno** drop_vector_ptr_alumnos (Alumno** vector_ptr_alumno, int dim_vector_ptr_alumno){

    for (int i=0; i<dim_vector_ptr_alumno; i++){
        vector_ptr_alumno[i]=dropAlumno(vector_ptr_alumno[i]);
    }

    delete [] vector_ptr_alumno;

    vector_ptr_alumno=NULL;

    return vector_ptr_alumno;
}






/*********************************************************************************************************************************
 *************************************************     Front (Vector-PTR-Alumnos)      ********************************************
 *********************************************************************************************************************************/

Alumno** introducir_vector_ptr_alumnos (Alumno **vector_ptr_alumnos, int &util_v_ptr_alumnos, int &dim_v_ptr_alumnos){
    
    int aux_util=0;
    Alumno *aux_alumn=createAlumno();


    cout << "Introduzca el numero de alumnos que se introducira: ";
    cin >> aux_util;

    for (util_v_ptr_alumnos = 0; util_v_ptr_alumnos<aux_util; ){

        insertarAlumno(aux_alumn);

        vector_ptr_alumnos=agregar_alumno_vector_PTR (vector_ptr_alumnos, util_v_ptr_alumnos, dim_v_ptr_alumnos, *aux_alumn, 1);

    }

    aux_alumn=dropAlumno(aux_alumn);
    return vector_ptr_alumnos;

}

void imprimir_vector_ptr_alumnos (Alumno **vector_ptr_alumnos, int util_a){

    for (int i=0; i<util_a; i++){
        cout <<endl<<endl<<endl<<BOLDBLUE<< "Alumno "<<i<<": "<<endl<<endl<<RESTORE;
        imprimirAlumno(vector_ptr_alumnos[i]);
    }
    
}

/*********************************************************************************************************************************
 *************************************************     Back (Vector-PTR-Alumnos)      ********************************************
 *********************************************************************************************************************************/


Alumno** agregar_alumno_vector_PTR (Alumno **vector_ptr_alumnos, int &util_v_ptr_alumnos, int &dim_v_ptr_alumnos, Alumno un_alumno, int extendido){

	if (util_v_ptr_alumnos<dim_v_ptr_alumnos){
        CopiarAlumno(&un_alumno, vector_ptr_alumnos[util_v_ptr_alumnos]);
		util_v_ptr_alumnos++;

	}

	else{
		
        //añadimos extendido a la dimension
        vector_ptr_alumnos=resize_vector_alumno_ptr(dim_v_ptr_alumnos+extendido, vector_ptr_alumnos, util_v_ptr_alumnos, dim_v_ptr_alumnos);

        //continuamos con la insercion
        CopiarAlumno(&un_alumno, vector_ptr_alumnos[util_v_ptr_alumnos]);
		util_v_ptr_alumnos++;

	}

	return vector_ptr_alumnos;
}


Alumno** resize_vector_alumno_ptr(int new_dim, Alumno** v_alumno_dinamico, int &util_a, int &dim_a){

    //Creamos el nuevo vector
    Alumno **new_v_alumno_ptr=create_vector_ptr_alumnos(new_dim);

	
    //Copiamos el antiguo en el nuevo
    for(int i=0; i<util_a; i++){
        CopiarAlumno(v_alumno_dinamico[i], new_v_alumno_ptr[i]);
    }
    
    //Eliminamos el antiguo
	v_alumno_dinamico = drop_vector_ptr_alumnos(v_alumno_dinamico, dim_a);


    //Actualizamos la dimension 
    dim_a = new_dim;

    

    //Devolvemos el nuevo
    return new_v_alumno_ptr;

}

/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/
