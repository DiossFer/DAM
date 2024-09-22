#include <iostream>
#include "Coche.h"
#include "Cadenas.h"
#include "Enteros.h"

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

using namespace std;

/***************************************************************************************************************************************
                                                   * Modulos sets y gets de la estructura Coche *
 ***************************************************************************************************************************************/

void set_id_coche(Coche &c, char id_c[]){
    copiarVector_char(id_c, c.id_coche);
}

void set_marca(Coche &c, char marc[]){
    copiarVector_char(marc, c.marca);
}

void set_matricula(Coche &c, char matric[]){
    copiarVector_char(matric, c.matricula);
}

void set_modelo(Coche &c, char mod[]){
    copiarVector_char(mod, c.modelo);
}

void set_numero_asientos(Coche &c, int num_asientos){
    c.numero_asientos=num_asientos;
}

void get_id_coche (const Coche &c, char id_c[]){
    copiarVector_char(c.id_coche, id_c);
}

void get_marca (const Coche &c, char marc[]){
    copiarVector_char(c.marca, marc);
}

void get_matricula (const Coche &c, char matric[]){
    copiarVector_char(c.matricula, matric);
}

void get_modelo (const Coche &c, char mod[]){
    copiarVector_char(c.modelo, mod);
}

int get_numero_asientos (const Coche &c){
    return c.numero_asientos;
}

void set_anadir_coche_en_vector_coches(Coche coches[], Coche c, int &util){
    
    copiar_coche(c, coches[util]);
    util++;

}
/***************************************************************************************************************************************
                                                        * Modulos de la estructura Coche Front*
 ***************************************************************************************************************************************/
    
void mostrar_coche (const Coche &c){
    char cadena_aux_dim_id_coche[DIM_ID_COCHE]={'\0'};
    char cadena_aux_dim_cadena_normal_c[DIM_CADENA_NORMAL_C]={'\0'};
    char cadena_aux_dim_matricula[DIM_MATRICULA]={'\0'};
    int aux=0;

    cout << endl << BOLDCYAN<<endl;

    get_id_coche (c, cadena_aux_dim_id_coche);
    cout <<"id_coche--> ";
    mostrar_cadena(cadena_aux_dim_id_coche);
    cout << endl;

    get_marca (c, cadena_aux_dim_cadena_normal_c);
    cout <<"marca--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_c);
    cout << endl;


    get_matricula (c, cadena_aux_dim_matricula);
    cout <<"matricula--> ";
    mostrar_cadena(cadena_aux_dim_matricula);
    cout << endl;

    get_modelo (c, cadena_aux_dim_cadena_normal_c);
    cout <<"modelo--> ";
    mostrar_cadena(cadena_aux_dim_cadena_normal_c);
    cout << endl;

    aux=get_numero_asientos (c);
    cout <<"numero_asientos--> "<< aux<<endl;


    cout << endl<<RESTORE;
}


void mostrar_leyenda_coche (){
    cout << endl << BOLDBLUE<<endl;
    
    cout << "id_coche"<<'\t'<< '\t';
    cout <<"marca"<< '\t'<< '\t';
    cout <<"matricula"<< '\t'<< '\t';
    cout << "modelo"<<'\t'<< '\t';
    cout << "numero_asientos";

    cout << endl<<RESTORE<<endl;
}

void mostrar_coche_fila (const Coche &c){
    char cadena_aux_dim_id_coche[DIM_ID_COCHE]={'\0'};
    char cadena_aux_dim_cadena_normal_c[DIM_CADENA_NORMAL_C]={'\0'};
    char cadena_aux_dim_matricula[DIM_MATRICULA]={'\0'};
    int aux=0;

    cout << endl << BOLDCYAN<<endl;

    get_id_coche (c, cadena_aux_dim_id_coche);
    mostrar_cadena(cadena_aux_dim_id_coche);
    cout << '\t'<< '\t';

    get_marca (c, cadena_aux_dim_cadena_normal_c);
    mostrar_cadena(cadena_aux_dim_cadena_normal_c);
    cout << '\t'<< '\t';

    get_matricula (c, cadena_aux_dim_matricula);
    mostrar_cadena(cadena_aux_dim_matricula);
    cout << '\t'<< '\t';

    get_modelo (c, cadena_aux_dim_cadena_normal_c);

    mostrar_cadena(cadena_aux_dim_cadena_normal_c);
    cout << '\t'<< '\t';

    aux=get_numero_asientos (c);
    cout << aux;


    cout << endl<<RESTORE<<endl;
}


void introducir_coche (Coche &c){
    char cadena_aux_dim_id_coche[DIM_ID_COCHE]={'\0'};
    char cadena_aux_dim_cadena_normal_c[DIM_CADENA_NORMAL_C]={'\0'};
    char cadena_aux_dim_matricula[DIM_MATRICULA]={'\0'};
    int aux=0;
    

    introducir_cadena_numero_caracteres_filtrado("Introduzca el id_coche: ", cadena_aux_dim_id_coche, DIM_ID_COCHE, true, 8, true, 8, "No cumple con el tamaño establecido");
    set_id_coche (c, cadena_aux_dim_id_coche);
    

    introducir_cadena_numero_caracteres_filtrado("Introduzca la marca: ", cadena_aux_dim_cadena_normal_c, DIM_ID_COCHE, false, 8, false, 8, " ");
    set_marca (c, cadena_aux_dim_cadena_normal_c);

    introducir_cadena_numero_caracteres_filtrado("Introduzca la matricula: ", cadena_aux_dim_matricula, DIM_ID_COCHE, true, 7, true, 7, "Ha introducido mal la matricula");
    set_matricula (c, cadena_aux_dim_matricula);

    introducir_cadena_numero_caracteres_filtrado("Introduzca el modelo: ", cadena_aux_dim_cadena_normal_c, DIM_ID_COCHE, false, 8, false, 8, " ");
    set_modelo (c, cadena_aux_dim_cadena_normal_c);

    aux=introducir_int_filtrado ("Introduce la el numero de asientos: \n", -1, 8, "Numero de asientso no valido");
    set_numero_asientos (c, aux);
    cin.ignore(10000, '\n');


    if (DEBUG_C_coche==true){
        cout << DEBUG << "DEBUG"<<endl;
        mostrar_coche(c);
        cout << "DEBUG"<<RESTORE<<endl;
    }

}


void mostrar_vector_coches (const Coche c[], const int util_c){
    for (int i=0; i<util_c; i++){
        mostrar_leyenda_coche ();
        mostrar_coche_fila (c[i]);
        cout << endl<<endl;
    }
    cout<<endl<<endl;
}

/***************************************************************************************************************************************
                                                        * Modulos de la estructura Coche Back*
 ***************************************************************************************************************************************/


void buscar_coche_por_id_coche (const char id_coche_a_buscar[], const Coche vector_para_buscar[], const int util_vector, Coche coche_sol[],int &util_vector_solucion){
    char cadena_aux[DIM_ID_COCHE]={'\0'};
    bool igual=false;

    for (int i=0; i<util_vector; i++){
        igual=false;

        get_id_coche(vector_para_buscar[i], cadena_aux);
        igual=comparar_cadenas(cadena_aux, id_coche_a_buscar);

        if (igual){
            set_anadir_coche_en_vector_coches (coche_sol, vector_para_buscar[i], util_vector_solucion);
        }
    }
}



void copiar_coche (const Coche &c1, Coche &c2){

    char cadena_aux_dim_id_coche[DIM_ID_COCHE]={'\0'};
    char cadena_aux_dim_cadena_normal_c[DIM_CADENA_NORMAL_C]={'\0'};
    char cadena_aux_dim_matricula[DIM_MATRICULA]={'\0'};
    int aux=0;

    get_id_coche (c1, cadena_aux_dim_id_coche);
    set_id_coche (c2, cadena_aux_dim_id_coche);
    

    get_marca (c1, cadena_aux_dim_cadena_normal_c);
    set_marca (c2, cadena_aux_dim_cadena_normal_c);




    get_matricula (c1, cadena_aux_dim_matricula);
    set_matricula (c2, cadena_aux_dim_matricula);





    get_modelo (c1, cadena_aux_dim_cadena_normal_c);
    set_modelo (c2, cadena_aux_dim_cadena_normal_c);


    aux=get_numero_asientos (c1);
    set_numero_asientos (c2, aux);

}



/***************************************************************************************************************************************
****************************************************************************************************************************************
***************************************************************************************************************************************/