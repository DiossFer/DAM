#include "Valoracion.h"

/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------- /  Valoracion  / ------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/




/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/

Valoracion::Valoracion(){
    if (DEBUG_Valoracion){
        cout << DEBUG << "ENTRANDO en constructor valoracion"<<DEFAULT<<endl;
    }
    this->set_id_val("");

    this->set_estrellas_val(0);

    this->c_val=NULL;

    this->p_val=NULL;
    if (DEBUG_Pedido){
        cout << DEBUG << "SALIENDO en constructor valoracion"<<DEFAULT<<endl;
    }
}


Valoracion::Valoracion(const Valoracion &v){
    if (DEBUG_Valoracion){
        cout << DEBUG << "ENTRANDO en constructor por copia valoracion"<<DEFAULT<<endl;
    }
    this->set_id_val(v.get_id_val());

    this->set_estrellas_val(v.get_estrellas_val());

    this->c_val=v.get_cliente_val();

    this->p_val=v.get_producto_val();

    if (DEBUG_Pedido){
        cout << DEBUG << "SALIENDO en constructor por copia valoracion"<<DEFAULT<<endl;
    }
}


Valoracion::Valoracion(string id_val, int estrellas, Producto*un_p, Cliente *un_c){
    if (DEBUG_Pedido){
        cout << DEBUG << "ENTRANDO en constructor valoracion por parametros"<<DEFAULT<<endl;
    }
    this->set_id_val(id_val);

    this->set_estrellas_val(estrellas);

    this->set_cliente_val(un_c);

    this->set_producto_val(un_p);
    if (DEBUG_Pedido){
        cout << DEBUG << "SALIENDO en constructor valoracion por parametros"<<DEFAULT<<endl;
    }
}

Valoracion::~Valoracion(){
    if (DEBUG_Pedido){
        cout << DEBUG << "ENTRANDO en destructor valoracion"<<DEFAULT<<endl;
    }
    if (DEBUG_Pedido){
        cout << DEBUG << "SALIENDO en destructor valoracion"<<DEFAULT<<endl;
    }
}


/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/

string Valoracion::get_id_val() const{
    return this->id_val;
}


int Valoracion::get_estrellas_val() const{
    return this->estrellas;
}

Cliente* Valoracion::get_cliente_val() const{
    return this->c_val;
}

Producto* Valoracion::get_producto_val() const{
    return this->p_val;
}



/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/

void Valoracion::set_id_val(string id){
    this->id_val=id;
}


void Valoracion::set_estrellas_val(int e){
    this->estrellas=e;
}

void Valoracion::set_cliente_val(Cliente *un_c){
    this->c_val=un_c;
    un_c->set_valoracion_media_productos(((un_c->get_valoracion_media_productos() * un_c->get_total_valoraciones_cliente())+this->get_estrellas_val())/(un_c->get_total_valoraciones_cliente()+1));
    un_c->set_total_valoraciones_cliente(un_c->get_total_valoraciones_cliente()+1.0);
}

void Valoracion::set_producto_val(Producto *un_p){
    this->p_val=un_p;

    un_p->set_valoracion_total(un_p->get_valoracion_total()+this->get_estrellas_val());

    un_p->set_num_valoracion(un_p->get_num_valoracion()+1);

    un_p->set_valoracion_media((un_p->get_valoracion_total())/(un_p->get_num_valoracion()));
    

}


/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/

void Valoracion::print (){
    cout << "--------------------------------------------"<<endl;

    cout << "ID_Val"<<'\t'<<'\t';
    cout << "Estresllas"<<'\t'<<endl;

    cout << this->get_id_val()<<'\t'<<'\t';
    cout << this->get_estrellas_val()<<'\t'<<endl;
    

    cout <<endl<< "Cliente Val:"<<endl;
    (this->get_cliente_val())->print();

    cout <<endl<< "Producto Val:"<<endl;
    (this->get_producto_val())->print();


    cout << "--------------------------------------------"<<endl;

}

void Valoracion::introducir (){
    string aux_s="";
    float aux_f=0.0;

    cout << "Introduce la id_val: ";
    cin>>aux_s;
    this->set_id_val(aux_s);


    cout << "Introduce las estrellas: ";
    cin>>aux_f;
    this->set_estrellas_val(aux_f);

}

/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/
Valoracion Valoracion::operator=(const Valoracion &v){
    this->set_id_val(v.get_id_val());

    this->set_estrellas_val(v.get_estrellas_val());

    this->c_val=(v.get_cliente_val());

    this->p_val=(v.get_producto_val());

    return *this;
}




