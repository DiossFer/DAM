#include <iostream>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <sys/wait.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"

using namespace std;


/*******************************************************************************************************************************************************************************************************
***********************************************************************                        PROTOTIPOS                        ***********************************************************************
*******************************************************************************************************************************************************************************************************/


/**
 * @brief Esta funcion se encarga de escuchar indefinidamente los paquetes y por cada -1 separar el paquete mandando el anterior a un hijo para su posterior evaluacion
 * @version 0.4
 * @author Dios-Fer
*/
void EscuchaPaquetes ();


/**
 * @brief Esta funcion se encarga de evaluar un paquete
 * @param vector<int> paquete -> paquete ne un vector de int -> el fork se encargara de duplicarlo para su evaluacion independiente a la escucha
 * @param int id -> id del paquete  
 * @post se mostrara de color verde los paquetes validos ademas de su sumatoria en caso de no ser valodos se mostrara de color rojo el paquete
 * @version 0.4
 * @author Dios-Fer
*/
void ComprobarPaqute (vector<int> paquete, int id);


/*******************************************************************************************************************************************************************************************************
**************************************************************************                        MAIN                        **************************************************************************
*******************************************************************************************************************************************************************************************************/


int main (){

    EscuchaPaquetes();

}


/*******************************************************************************************************************************************************************************************************
*************************************************************************                        CUERPO                        *************************************************************************
*******************************************************************************************************************************************************************************************************/


void EscuchaPaquetes (){

    vector<int> paquete;
    int num=0;
    int id=0;

    //Siempre escuchando paquetes
    while (true){

        // Entrada de paquetes 
        do{

            cin >> num;
            paquete.push_back(num);

        }while(num != -1);

        //Actualizamos las id's
        id++;

        //Crea un hijo encargado de validar y devolver el paquete
        ComprobarPaqute(paquete, id);

        //Limpiamos nuestro paquete local
        paquete.clear();

    }
}



void ComprobarPaqute (vector<int> paquete, int id){

    //Tuberia para pasar el resultado de la suma del nieto al padre
    int  tuberia[2];
    pipe(tuberia);

    //buffer con un maximo de 50 caracteres
    char buffer[50];

    pid_t pID = fork();
    if (pID == 0) // child
    {

        //Creamos el proceso nieto para el calculo de la suma
        pid_t pID2 = fork();
        if (pID2 == 0) // child
        {
            //Cerramos tuberia de lectura
            close(tuberia[0]);
            
            int suma=0;

            //Realizamos la suma        
            for (int i=0; i<paquete.size()-1; i++){
                suma+=paquete[i];
            }

            //Introduciomos la suma como string en la tuberia
            write(tuberia[1], to_string(suma).c_str(), to_string(suma).size());  

            //Cerramos el nieto
            exit(EXIT_SUCCESS);

        }
        else if (pID2 < 0)// failed to fork
        {

            cerr << "Failed to fork" << endl;
            exit(1);
            // Throw exception

        }
        else// parent
        {

        }
        
        // parent
        bool valido=true;

        //Comprobamos la validez del paquete
        for (int i=0; i<paquete.size()-1; i++){

            if (paquete[i]<0){
                valido=false;
            }

        }
        
            //Inicializamos la salida del paquete con la id del paquete
            string res="";
            res+= "Proceso[";
            res+=to_string(id);
            res+="]-->";

        if (valido){ //Si el paquete es valido

            // Esperamos a que termine la suma (proceso nieto)
            wait (NULL);

            close(tuberia[1]);

            //Guardamos el ssize_t tamanio para evitar que el buffer traiga cosas de mas
            ssize_t tamanio = read(tuberia[0], buffer, sizeof(buffer));



            //Obtenemos el resultado de la suma sin char's sobrantes
            string sum (buffer, tamanio);            

            //Guardamos la salida del paquete en res
            for (int i=0; i<paquete.size()-1; i++){
                res +=" ";
                res+=to_string(paquete[i]);
                res+=" ";

                
            }

            res+=" = ";

            res+=sum;


            //Esperamos el numeo de segundos que dicte el resultado
            sleep(stoi(sum));

            //Mostramos la salida en la terminal
            cout << GREEN << res << RESET<<endl;
        }
        else{
            //Ignoramos la suma por que el paquete no es valido


            //Guardamos la salida del paquete en res
            for (int i=0; i<paquete.size(); i++){
                res+=" ";
                res+=to_string(paquete[i]);
                res+=" ";
            }

            //Mostramos la salida en la terminal
            cout << RED << res << RESET << endl;
        }

        //Teminamos el hijo (comprobacion-salida)
        _exit(0);

    }
    else if (pID < 0)// failed to fork
    {

        cerr << "Failed to fork" << endl;
        exit(1);
        // Throw exception

    }
    else// parent
    {

        // Code only executed by parent process
        
        //Su cometido habitual esta en el main

    }
    

    //El padre tras la llamada al hijo seguira con su ejecucion habitual en su escucha continua de paquetes
    

}

