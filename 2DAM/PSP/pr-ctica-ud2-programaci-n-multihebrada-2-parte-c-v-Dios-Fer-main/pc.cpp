#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <semaphore.h>
#include <vector>

#define ROJO "\033[1;31m"
#define VERDE "\033[1;32m"
#define RESET "\033[0m"

using namespace std;



/**
* He decidido usar estas glovales, no me acaba de gustar se podria plantear por ejemplo para algunas de ellas pasarlas en un struct
*/

vector<int> buffer; // buffer compartido

// semaforo en memoria compartida
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t lleno = PTHREAD_COND_INITIALIZER;
pthread_cond_t vacio = PTHREAD_COND_INITIALIZER;

// variables para la insercion
int posicion_a_consumir;
int posicion_a_producir;

// Condiciones de fin de hebra
bool termina_prod; 
bool terminan_cons; 

int contador;


/**
* @brief    Funcion encargada de producir 
*           entra en el cerrojo para ver si hay hueco
*           si hay hueco produce y sale del cerrojo 
*           si no hay hueco esperara a la variable condicion
*
* @param void* p --> id de la hebra 
* @post se generara una hebra encargada de producir una o infinitas veces
*/
void* prod( void* p ){
    do{

        // Entramos en el cerrojo
        pthread_mutex_lock(&mutex);

        // Si no hay hueco para nuestra accion esperamos
        while (contador==buffer.size()){

            pthread_cond_wait(&lleno, &mutex); // Esperamos a la variable de condicion

        }
        
        int *id;
        id = (int *) p;


        // consumes
        
        buffer[posicion_a_producir] = 1;

        // Mensaje
        cout << "HebraProductora(" << *id << ") consume en posición " << posicion_a_producir << endl;
        for (int j=0; j < buffer.size(); j++){
            
            if (j==posicion_a_producir){
                cout << VERDE << buffer[j] << " " << RESET;
            }
            else{
                cout << buffer[j] << " ";
            }

        }
        cout << endl;

        posicion_a_producir=(posicion_a_producir+1)%buffer.size();
        contador++;


        pthread_cond_broadcast(&vacio); // Informamos a la variable condicion


        pthread_mutex_unlock(&mutex); // Salimos del cerrojo


        
    }while (!termina_prod);
	return NULL ;
}


/**
* @brief    Funcion encargada de consumir 
*           entra en el cerrojo para ver si hay hueco
*           si hay hueco produce y sale del cerrojo 
*           si no hay hueco esperara a la variable condicion
*
* @param void* p --> id de la hebra 
* @post se generara una hebra encargada de consumir una o infinitas veces
*/
void* cons( void* p ){
    do{

        // Entramos en el cerrojo
        pthread_mutex_lock(&mutex);

        // Si no hay hueco para nuestra accion esperamos
        while (contador==0){

            pthread_cond_wait(&vacio, &mutex); // Esperamos a la variable de condicion

        }
        
        int *id;
        id = (int *) p;


        // consumes
        
        buffer[posicion_a_consumir] = 0;

        // Mensaje
        cout << "HebraConsumidora(" << *id << ") consume en posición " << posicion_a_consumir << endl;
        for (int j=0; j < buffer.size(); j++){
            
            if (j==posicion_a_consumir){
                cout << ROJO << buffer[j] << " " << RESET;
            }
            else{
                cout << buffer[j] << " ";
            }

        }
        cout << endl;

        posicion_a_consumir=(posicion_a_consumir+1)%buffer.size();
        contador--;


        pthread_cond_broadcast(&lleno); // Informamos a la variable condicion


        pthread_mutex_unlock(&mutex); // Salimos del cerrojo


        
    }while (!terminan_cons);
	return NULL ;
}


/**
* @brief Main encargado de recibir los datos y de lanzar las hebras encargadas del problema p/c
* @param int tamanioBuffer 
* @param int num_hebras_prod 
* @param bool termina_prod 
* @param int num_hebras_cons 
* @param bool terminan_cons 
* @post se vera en la terminal el debug en el caso actual de productor / consumidor
*/
int main(int argc, char* argv[]) {

    // Verificar la validez de la entrada

    if (argc < 6 || argc > 6) {
        cout << "Error numero de parametros no valido"<<endl;
    }
    else{

        // Obtener parametros

        int tamanioBuffer = stoi(argv[1]);
        int num_hebras_prod = stoi(argv[2]);
        termina_prod = std::string(argv[3]) == "true";
        int num_hebras_cons = stoi(argv[4]);
        terminan_cons = std::string(argv[5]) == "true";

        // Inicializamos variables
        contador=0;
        posicion_a_consumir=0;
        posicion_a_producir=0;

        //
        
        pthread_attr_t atrib;
        pthread_attr_init(&atrib);


        
        // Inicializamos el vector

        for (int i = 0; i < tamanioBuffer; i++){
            buffer.push_back(0);
        }
        
        // Declaramos los vectores de hebras

        pthread_t vectorHebraProductora[num_hebras_prod];

        pthread_t vectorHebraConsumidora[num_hebras_cons];


        // Lanzamos las hebras
        

        int* num;


        for( unsigned i = 0 ; i < num_hebras_prod ; i++ ){ 
            num = new int(i);
		    pthread_create( &(vectorHebraProductora[i]), NULL, prod, (void *)num );
        }

        for( unsigned i = 0 ; i < num_hebras_cons ; i++ ){ 
            num = new int(i);
		    pthread_create( &(vectorHebraConsumidora[i]), NULL, cons, (void *)num );
        }


        // Esperamos las hebras
        for( unsigned i = 0 ; i < num_hebras_prod ; i++ ){
            pthread_join( vectorHebraProductora[i], NULL );
        }

        for( unsigned i = 0 ; i < num_hebras_cons ; i++ ){
            pthread_join( vectorHebraConsumidora[i], NULL );
        }

    }
    
}


