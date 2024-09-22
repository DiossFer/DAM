#include "vista.h"


/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------- /  Vista  / --------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/


Vista::Vista(){

    if (DEBUG_C_Vista){
        cout <<DEBUG<< "Inicio costructor vista"<<endl<<DEFAULT;
    }


    this->salir = false;
    this->total_polinomios = 0;
    this->vector_polinomios = new Polinomio[this->total_polinomios+1];


    if (DEBUG_C_Vista){
        cout <<DEBUG<< "FIN costructor vista"<<endl<<DEFAULT;
    }

}

Vista::~Vista(){

    if (DEBUG_C_Vista){
        cout <<DEBUG<< "Inicio destructor vista"<<endl<<DEFAULT;
    }


    delete[] this->vector_polinomios;
    this->vector_polinomios = 0;


    if (DEBUG_C_Vista){
        cout <<DEBUG<< "FIN destructor vista"<<endl<<DEFAULT;
    }

}


/**************************************************************************************************************************************
************************************************************* -  SET's  - *************************************************************
**************************************************************************************************************************************/


void Vista::set_salida(bool new_status){
    this->salir=new_status;
}


void Vista::set_total_polinomios (int new_total){

    this->total_polinomios=new_total;
    
}


void Vista::set_Polinomio_vista (Polinomio p){


    
    //Como actualmente el programa solo debe de crear no hare un set muy avanzado y cubrire el caso de que se extienda siempre (ademas de que el resice para abajo se encargara el eliminar pues tal vez nos interese tener polinomios vacios)
    
    
    this->resize_vector_polinomios(this->get_total_polinomios()+1);//partiendo de que new_total solo sera el crear o elimniar EN LA ACTUALIDAD DEL SISTEMA


    this->vector_polinomios[this->get_total_polinomios()]=p;


    set_total_polinomios(this->get_total_polinomios()+1);//se encargara del resize


}



/**************************************************************************************************************************************
************************************************************* -  GET's  - *************************************************************
**************************************************************************************************************************************/

bool Vista::get_salida(){
    return this->salir;
}


int Vista::get_total_polinomios (){
    return this->total_polinomios;
}


Polinomio Vista::get_Polinomio_vista (int posicion){
    
    return this->vector_polinomios[posicion];
    

}



/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/


void Vista::bienvenida(){
    this->set_salida(false);
    cout << "Bienvenido al programa de polinomios." << endl;
}

void Vista::menu(){
    string opcion=" ";

    //Vista
    while(salir == false){
        cout << "1. Crear polinomio" << endl;
        cout << "2. Mostrar polinomio" << endl;
        cout << "3. Sumar" << endl;
        cout << "4. Elimniar polinomio" << endl;
        cout << "5. Salir" << endl;
        cout << "# ";
        cin >> opcion;
        
        Polinomio aux_P;
        int aux_int=0;

        //Funcional

        if(opcion=="1"){
            cin>>aux_P;
            this->set_Polinomio_vista(aux_P);

            aux_P.inicializarPolinomio();
        }
        else if (opcion=="2"){
            this->print();
        }
        else if (opcion=="3"){
            this->suma_vista();
        }
        else if (opcion=="4"){
            if(this->get_total_polinomios()==0){

            }
            else{
                do{
                    cout << "Introduzca la posicion a eliminar" << endl;
                    cin >> aux_int;
                }while(aux_int<0 || aux_int>=this->get_total_polinomios());
            
                this->elimniar_posicion(aux_int);
            }
            
        }
        else if (opcion=="5"){
            set_salida(true);
            cout << "El programa se ha cerrado correctamente"<<endl;
        }
        else{
            cout <<ERROR<< "Opcion no valida"<<DEFAULT<<endl<<endl;
        }

    }


}


void Vista::print (){
    for (int i=0; i<this->get_total_polinomios(); i++){
        cout << this->get_Polinomio_vista(i);
        cout << endl;
    }
    
        cout << endl<<endl;

    if (DEBUG_C_Vista){
        cout <<BOLDYELLOW<< "Tamaño del vector: "<<this->get_total_polinomios()<<endl<<DEFAULT;
    }

}




void Vista::suma_vista(){ 
    string guardado=" ";
    Polinomio p1;
    Polinomio p2;
    Polinomio res;

    cout << "Introduce los dos polinomios para sumarlos: "<<endl;

    cin>>p1;
    cin>>p2;

    res=p1+p2;

    cout << "El resultado es: "<<endl;
    cout << res <<endl;

    do{
        cout << "Introduzca 1 si quiere guardar el resultado en el vector de polinomios o 0 si quieres descartarlo y salir "<<endl;
        cin>>guardado;
    }while(!(guardado=="1" || guardado=="0"));

    if (guardado=="1"){
        this->set_Polinomio_vista(res);
    }

}




/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/


void Vista::elimniar_posicion(int i){
    
    for (; i<this->get_total_polinomios()-1; i++){
        this->vector_polinomios[i]=this->vector_polinomios[i+1];
    }
    this->resize_vector_polinomios(this->get_total_polinomios());
    this->set_total_polinomios(this->get_total_polinomios()-1);

}



void Vista::resize_vector_polinomios (int new_dim){
    Polinomio *v_p = new Polinomio [new_dim];

    for (int i=0; i<this->get_total_polinomios(); i++){
        v_p[i]=this->get_Polinomio_vista(i);
    }

    delete[] this->vector_polinomios;

    this->vector_polinomios=v_p;

}