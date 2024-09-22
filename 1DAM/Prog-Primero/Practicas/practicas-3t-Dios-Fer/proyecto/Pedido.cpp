#include "Pedido.h"


/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------ /  Pedido  / --------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/



/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/
    

Pedido::Pedido(){
    if (DEBUG_Pedido){
        cout << DEBUG << "ENTRANDO en constructor pedido"<<DEFAULT<<endl;
    }
    int dia=0, mes=0, anio=0, hora=0, minutos=0, segundos=0;

    this->set_id_pedido("");

    Hora aux_h(segundos, minutos, hora);
    this->set_hora_pedido(aux_h);

    Fecha aux_f(dia, mes, anio);
    this->set_fecha_pedido(aux_f);

    this->set_total_productos_pedido(0);

    this->vector_productos_pedido=new Producto* [1];

    this->set_total_precio_pedido_sin_iva(0.0);

    this->set_total_precio_pedido_con_iva(0.0);

    this->estado="preparacion"; // por defecto hasta su cambio

    this->cancelable=true; // por defecto hasta su cambio

    if (DEBUG_Pedido){
        cout << DEBUG << "SALIENDO en constructor pedido"<<DEFAULT<<endl;
    }

}

Pedido::Pedido(const Pedido &p){
    this->set_id_pedido(p.get_id_pedido());


    this->set_hora_pedido(p.get_hora_pedido());


    this->set_fecha_pedido(p.get_fecha_pedido());


    this->set_total_precio_pedido_sin_iva(p.get_total_precio_pedido_sin_iva());

    this->set_total_precio_pedido_con_iva(p.get_total_precio_pedido_con_iva());

    this->vector_productos_pedido = new Producto* [p.get_total_productos_pedido()+1];
    for (int i=0; i<=p.get_total_productos_pedido(); i++){
        this->vector_productos_pedido[i]=p.get_producto_pedido(i);
    }
    this->set_total_productos_pedido(p.get_total_productos_pedido());

    this->set_estado(p.get_estado());

    this->set_cancelable(p.get_cancelable());


}

Pedido::Pedido(string id, int dia, int mes, int anio, int hora, int minutos, int segundos){
    if (DEBUG_Pedido){
        cout << DEBUG << "ENTRANDO en constructor pedido por parametros"<<DEFAULT<<endl;
    }
    this->set_id_pedido(id);
    this->vector_productos_pedido=new Producto* [1];
    Hora aux_h(segundos, minutos, hora);
    this->set_hora_pedido(aux_h);

    Fecha aux_f(dia, mes, anio);
    this->set_fecha_pedido(aux_f);

    this->set_total_productos_pedido(0);

    //Producto** vector_productos_pedido;

    this->set_total_precio_pedido_sin_iva(0.0);

    this->set_total_precio_pedido_con_iva(0.0);


    this->estado="preparacion"; // por defecto hasta su cambio

    this->cancelable=true; // por defecto hasta su cambio


    if (DEBUG_Pedido){
        cout << DEBUG << "SALIENDO en constructor pedido por parametros"<<DEFAULT<<endl;
    }
}



Pedido::~Pedido(){
    if (DEBUG_Pedido){
        cout << DEBUG << "ENTRANDO en destructor pedidos"<<DEFAULT<<endl;
    }
    delete [] vector_productos_pedido;
    if (DEBUG_Pedido){
        cout << DEBUG << "SALIENDO en destructor pedidos"<<DEFAULT<<endl;
    }
}



/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/
string Pedido::get_id_pedido() const{
    return this->id_pedido;
}

Fecha Pedido::get_fecha_pedido() const{
    return this->fecha_pedido;
}

Hora Pedido::get_hora_pedido() const{
    return this->hora_pedido;
}

int Pedido::get_total_productos_pedido() const{
    return this->total_productos_pedido;
}

float Pedido::get_total_precio_pedido_sin_iva() const{
    return this->total_precio_pedido_sin_iva;
}

float Pedido::get_total_precio_pedido_con_iva() const{
    return this->total_precio_pedido_con_iva;
}

Producto* Pedido::get_producto_pedido(int posicion) const{
    return this->vector_productos_pedido[posicion];
}

string Pedido::get_estado() const{
    return this->estado;
}

bool Pedido::get_cancelable() const{
    return this->cancelable;
}



/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/
void Pedido::set_id_pedido(const string aux){
    this->id_pedido = aux;
}

void Pedido::set_fecha_pedido(const Fecha aux){
    this->fecha_pedido = aux;
}

void Pedido::set_hora_pedido(const Hora aux){
    this->hora_pedido = aux;
}

void Pedido::set_total_productos_pedido(const int aux){
    this->total_productos_pedido = aux;
}

void Pedido::set_total_precio_pedido_sin_iva(const float aux){
    this->total_precio_pedido_sin_iva = aux;
}

void Pedido::set_total_precio_pedido_con_iva(const float aux){
    this->total_precio_pedido_con_iva = aux;
}
void Pedido::set_producto_pedido(Producto *p){
    this->resize_vector_productos_pedido(this->get_total_productos_pedido()+2);

    this->vector_productos_pedido[this->get_total_productos_pedido()]=p;

    this->set_total_productos_pedido(this->get_total_productos_pedido()+1);

    p->set_num_veces_incluido_en_pedidos(p->get_num_veces_incluido_en_pedidos()+1);

    this->set_total_precio_pedido_sin_iva(this->get_total_precio_pedido_sin_iva() + p->get_precio_producto_sin_iva());
    this->set_total_precio_pedido_con_iva(this->get_total_precio_pedido_con_iva() + p->get_precio_producto_con_iva());

}


void Pedido::set_estado(string e){
    this->estado=e;
}



void Pedido::set_cancelable(bool c){
    this->cancelable=c;
}
/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/


void Pedido::print() const{

    cout << GREEN<<endl;
    cout<<"id_pedido"<<'\t';
    cout << "fecha_pedido"<<'\t';
    cout<<'\t';
    cout << "hora_pedido"<<'\t';
    cout<<'\t';
    cout << "precio_ped_sin_iva"<<'\t';
    cout << "precio_ped_con_iva"<<'\t';
    cout << "total_productos_pedidos"<<'\t'<<endl;


    cout<<this->get_id_pedido()<<'\t'<<'\t';
    (this->get_fecha_pedido()).print();
    cout<<'\t'<<'\t';
    (this->get_hora_pedido()).print();
    cout<<'\t'<<'\t';
    cout<<this->get_total_precio_pedido_sin_iva()<<'\t'<<'\t';
    cout<<this->get_total_precio_pedido_con_iva()<<'\t'<<'\t';
    cout<<this->get_total_productos_pedido()<<'\t'<<'\t'<<endl<<endl;
    cout << DEFAULT;

    for (int i=0; i<get_total_productos_pedido(); i++){
        cout << "Producto"<<i+1<<": "<<endl;
        this->vector_productos_pedido[i]->print();
        cout << endl;
    }
    cout << endl<<endl;
    cout << DEFAULT;


}

void Pedido::print_basic(){
    cout << GREEN<<endl;
    cout<<"id_pedido"<<'\t';
    cout << "fecha_pedido"<<'\t';
    cout<<'\t';
    cout << "hora_pedido"<<'\t';
    cout<<'\t';
    cout << "precio_ped_con_iva"<<'\t'<<endl;


    cout<<this->get_id_pedido()<<'\t'<<'\t';
    (this->get_fecha_pedido()).print();
    cout<<'\t'<<'\t';
    (this->get_hora_pedido()).print();
    cout<<'\t'<<'\t';
    cout<<this->get_total_precio_pedido_con_iva()<<'\t'<<'\t'<<endl;
    cout << DEFAULT;
}


void Pedido::introducir(){

    int aux=0;
    Hora aux_h;
    Fecha aux_f;
    string aux_s="";

    cout << "Introduce el id_pedido: ";
    cin>>aux_s;
    this->set_id_pedido(aux_s);

    aux_f.introducir();
    this->set_fecha_pedido(aux_f);
    aux_h.introducir();
    this->set_hora_pedido(aux_h);


    //se realizaran con posteriores sets
    //set_total_productos_pedido(0);
    //Producto** vector_productos_pedido;
    //set_total_precio_pedido_sin_iva(0.0);
    //set_total_precio_pedido_con_iva(0.0);

}


/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/


Pedido Pedido::operator=(const Pedido &p){

    this->set_id_pedido(p.get_id_pedido());


    this->set_hora_pedido(p.get_hora_pedido());


    this->set_fecha_pedido(p.get_fecha_pedido());

    this->set_total_productos_pedido(0);

    this->set_total_precio_pedido_sin_iva(p.get_total_precio_pedido_sin_iva());

    this->set_total_precio_pedido_con_iva(p.get_total_precio_pedido_con_iva());

    
    this->vector_productos_pedido=new Producto* [p.get_total_productos_pedido()+1];

    for (int i=0; i<p.get_total_productos_pedido(); i++){
        this->vector_productos_pedido[i]=p.vector_productos_pedido[i];
    }

    this->set_total_productos_pedido(p.get_total_productos_pedido());


    this->set_estado(p.get_estado());

    this->set_cancelable(p.get_cancelable());
    
    return *this;
}


void Pedido::resize_vector_productos_pedido(int new_dim){

    Producto ** aux_p = new Producto* [new_dim];
    for (int i=0; i<new_dim-1; i++){

        aux_p[i]=this->vector_productos_pedido[i];

    }

    delete [] this->vector_productos_pedido;

    this->vector_productos_pedido=aux_p;

}

