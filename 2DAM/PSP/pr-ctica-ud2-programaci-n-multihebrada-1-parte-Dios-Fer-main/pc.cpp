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

sem_t semaforo1 ; // semaforo en memoria compartida

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

        bool hueco = false;

        // Entras en seccion critica y miras si hay hueco, no hay sales, hay produces 
        // Cuando sales deberia de generarse hueco, si no saldras de nuevo 
        // En caso de que nunca halla mas hueco te quedaras indefinido aqui pero es normal (al menos como lo he planteado)

        while (!hueco){ 

            sem_wait( &semaforo1 );

            int i = 0;
            for (i=0; i < buffer.size() && hueco==false; i++){
                if (buffer[i] == 0){
                    hueco = true;
                }
            }

            

            if (hueco){ // produces

                i--; // hueco libre

                buffer[i] = 1;// produces

                // Mensaje
                cout << "HebraProductora(" << *id << ") produce en posición " << i << endl;
                for (int j=0; j < buffer.size(); j++){
                    
                    if (j==i){
                        cout << VERDE << buffer[j] << " " << RESET;
                    }
                    else{
                        cout << buffer[j] << " ";
                    }

                }
                cout << endl;

            }

            sem_post( &semaforo1 ); 
        }
        
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

        bool hueco = false;

        // Entras en seccion critica y miras si hay hueco, no hay sales, hay consumes 
        // Cuando sales deberia de generarse hueco, si no saldras de nuevo 
        // En caso de que nunca halla mas hueco te quedaras indefinido aqui pero es normal (al menos como lo he planteado)

        while (!hueco){ 

            sem_wait( &semaforo1 );

            int i = 0;
            for (i=0; i < buffer.size() && hueco==false; i++){
                if (buffer[i] == 1){
                    hueco = true;
                }
            }

            

            if (hueco){ // consumes

                i--; // hueco libre

                buffer[i] = 0;// consumes

                // Mensaje
                cout << "HebraConsumidora(" << *id << ") consume en posición " << i << endl;
                for (int j=0; j < buffer.size(); j++){
                    
                    if (j==i){
                        cout << ROJO << buffer[j] << " " << RESET;
                    }
                    else{
                        cout << buffer[j] << " ";
                    }

                }
                cout << endl;

            }

            sem_post( &semaforo1 ); 
        }
        
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
        
        int* num;
        sem_init( &semaforo1, 0, 1 );	 //Crear el semaforo

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


