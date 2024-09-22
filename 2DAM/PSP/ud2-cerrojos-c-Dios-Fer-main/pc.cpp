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
sem_t semaforo1 ; 
sem_t semaforo_vacios;
sem_t semaforo_elementos;

// 
int posicion_a_consumir;
int posicion_a_producir;

// Condiciones d efin de hebra
bool termina_prod; 
bool terminan_cons; 


/**
* @brief    Funcion encargada de producir 
*           entra en el semaforo para ver si hay hueco
*           si hay hueco produce y sale del semaforo 
*           (repetira en caso de ser falso la condicion de fin introducida por parametro)
*           si no hay hueco saldra del semaforo y tras esto ya se podran producir cambios de contexto, el vovera al inicio del semaforo a volver a comprobar el hueco
* 
* @param void* p --> id de la hebra 
* @post se generara una hebra encargada de producir una o infinitas veces
*/
void* prod( void* p ){
    do{

        
        int *id;
        id = (int *) p;

        //Esperamos que halla hueco
        sem_wait( &semaforo_vacios );

        //Esperamos que no se este modificando el buffer
        sem_wait( &semaforo1 );

        // produces

        buffer[posicion_a_producir] = 1;
        

        // Mensaje
        cout << "HebraProductora(" << *id << ") produce en posición " << posicion_a_producir << endl;
        for (int j=0; j < buffer.size(); j++){
            
            if (j==posicion_a_producir){
                cout << VERDE << buffer[j] << " " << RESET;
            }
            else{
                cout << buffer[j] << " ";
            }

        }
        cout << endl;

        // Posicionamos la siguiente posicion
        posicion_a_producir=(posicion_a_producir+1)%buffer.size();

        // Indicamos que ha salido de modificar el buffer
        sem_post( &semaforo1 ); 

        // Indicamos que ahora hay un elemento mas que consumir
        sem_post( &semaforo_elementos ); 
    
    }while (!termina_prod);
	return NULL ;
}


/**
* @brief    Funcion encargada de consumir 
*           entra en el semaforo para ver si hay hueco
*           si hay hueco consume y sale del semaforo 
*           (repetira en caso de ser falso la condicion de fin introducida por parametro)
*           si no hay hueco saldra del semaforo y tras esto ya se podran producir cambios de contexto, el vovera al inicio del semaforo a volver a comprobar el hueco
* 
* @param void* p --> id de la hebra 
* @post se generara una hebra encargada de consumir una o infinitas veces
*/
void* cons( void* p ){
    do{
            
        
        
        int *id;
        id = (int *) p;

        //Esperamos que halla elemento
        sem_wait( &semaforo_elementos );

        //Esperamos que no se este modificando el buffer
        sem_wait( &semaforo1 );


        

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

        // Indicamos que ha salido de modificar el buffer
        sem_post( &semaforo1 ); 

        // Indicamos que ahora hay un elemento mas que consumir
        sem_post( &semaforo_vacios ); 
        
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

        
        // Inicializamos el vector

        for (int i = 0; i < tamanioBuffer; i++){
            buffer.push_back(0);
        }
        
        // Declaramos los vectores de hebras

        pthread_t vectorHebraProductora[num_hebras_prod];

        pthread_t vectorHebraConsumidora[num_hebras_cons];


        // Lanzamos las hebras
        
        //Crear el semaforos
        
        sem_init(&semaforo1, 0, 1);
        sem_init(&semaforo_vacios, 0, tamanioBuffer);
        sem_init(&semaforo_elementos, 0, 0); 
        

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


