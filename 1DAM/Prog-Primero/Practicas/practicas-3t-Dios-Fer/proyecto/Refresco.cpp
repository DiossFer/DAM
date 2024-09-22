#include "Refresco.h"

/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------ /  Refresco  / ------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/


/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/

Refresco::Refresco() : Producto(){
    if (DEBUG_refresco){
        cout << ORANGE<<"INICIO constructor refresco"<<endl<<DEFAULT;
    }
    this->set_azucar(false);
    this->set_gas(false);
    this->set_cafeina(false);
    if (DEBUG_refresco){
        cout << ORANGE<<"FIN constructor refresco"<<endl<<DEFAULT;
    }
}




//No se realiza, todo es estatico
//Refresco::Refresco(const Refresco &r) : Producto(){}
Refresco::Refresco(const string id_producto, const string nombre, const float precio_producto_sin_iva, const string tamano, const int porcentaje_iva_producto, const bool azucar, const bool cafeina, const bool gas, const bool a) : Producto(id_producto, nombre, precio_producto_sin_iva, tamano, porcentaje_iva_producto, a){
    this->set_azucar(azucar);
    this->set_gas(gas);
    this->set_cafeina(cafeina);
}


Refresco::~Refresco(){
    if (DEBUG_refresco){
        cout << ORANGE<<"INICIO destructor refresco"<<endl<<DEFAULT;
    }
    //No hace falta destructor todo es estatico
    if (DEBUG_refresco){
        cout << ORANGE<<"FIN destructor refresco"<<endl<<DEFAULT;
    }
}

/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/

bool Refresco::get_azucar() const{
    return this->azucar;
}

bool Refresco::get_gas() const{
    return this->gas;
}

bool Refresco::get_cafeina() const{
    return this->cafeina;
}

/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/

void Refresco::set_azucar(const bool a){
    this->azucar=a;
}

void Refresco::set_gas(const bool g){
    this->gas=g;
}

void Refresco::set_cafeina(const bool c){
    this->cafeina=c;
}

/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/


void Refresco::print(){
    cout << BOLDCYAN;
    cout << "id_producto"<<'\t';
    cout << "nombre"<<'\t';
    cout << "precio_sin_iva"<<'\t';
    cout << "tamano"<<'\t';
    cout <<"Activo"<<'\t';
    cout <<"precio_producto_con_iva"<<'\t';
    cout <<"get_porcentaje_iva_producto"<<'\t';
    cout <<"get_valoracion_total"<<'\t';
    cout <<"num_veces_incluido_en_pedidos"<<'\t';
    cout <<"Azucar"<<'\t';
    cout <<"Gas"<<'\t';
    cout <<"Cafeina"<<'\t'<<endl;

    cout<< this->get_id_producto() <<'\t';
    cout<< this->get_nombre() <<'\t';
    cout<< this->get_precio_producto_sin_iva() <<'\t';
    cout<< this->get_tamano() <<'\t';
    cout<<this->get_activo()<<'\t';
    cout<<this->get_precio_producto_con_iva()<<'\t';
    cout<<this->get_porcentaje_iva_producto()<<'\t';
    cout<<this->get_valoracion_total()<<'\t';
    cout<<this->get_num_veces_incluido_en_pedidos()<<'\t';
    cout<< this->get_azucar()<<'\t';
    cout<< this->get_gas()<<'\t';
    cout<< this->get_cafeina()<<'\t'<<endl<<endl;
    cout << DEFAULT;


}


ostream& operator<<(ostream&flujo, const Refresco &r){

    flujo << "id_producto: " << r.get_id_producto() <<endl;

    flujo << "nombre: " << r.get_nombre() <<endl;

    flujo << "precio_sin_iva: " << r.get_precio_producto_sin_iva() <<endl;

    flujo << "tamano: " << r.get_tamano() <<endl;


    flujo <<"Activo: "<<r.get_activo()<<endl;

    flujo <<"precio_producto_con_iva: "<<r.get_precio_producto_con_iva()<<endl;

    flujo <<"get_porcentaje_iva_producto: "<<r.get_porcentaje_iva_producto()<<endl;

    flujo <<"get_valoracion_total: "<<r.get_valoracion_total()<<endl;

    flujo <<"num_veces_incluido_en_pedidos: "<<r.get_num_veces_incluido_en_pedidos()<<endl;

    flujo <<"Azucar: "<< r.get_azucar()<<endl;
    flujo <<"Gas: "<< r.get_gas()<<endl;
    flujo <<"Cafeina: "<< r.get_cafeina()<<endl;
    return flujo;
}



void Refresco::introducir(){
    string aux_s="";
    float aux_f=0.0;
    int aux_int=0;

    cout << "id_producto: ";
    cin >> aux_s;
    this->set_id_producto(aux_s);

    cout << "nombre: "; 
    cin >> aux_s;
    this->set_nombre(aux_s);

    cout << "precio_sin_iva: ";
    cin >> aux_f;
    this->set_precio_producto_sin_iva(aux_f);


    cout << "tamano: ";
    cin >> aux_s;
    this->set_tamano(aux_s);



    cout << "porcentaje_iva_producto: ";
    cin >> aux_int;
    this->set_porcentaje_iva_producto(aux_int);


    this->calcular_precio_con_iva(this->get_precio_producto_sin_iva(), this->get_porcentaje_iva_producto());
    //precio_producto_con_iva:  --> se calcula, se suma el precio ingrediente a lo que ya esta y se calcula el precio con iva, al ser la entrada solo tenemos la base pues los ingredientes van a parte por tanto lo calcularemos con la base



    //valoracion_total se ira actualizando en otros modulos
    //activo no se introduce, se cambiara en otros modulos
    //num_pedidos_insertado no se introduce, se cambiara en otros modulos

    cout <<"Introduce el azucar (1-> con) (0->sin): ";
    cin>>aux_int;
    this->set_azucar(aux_int);

    cout <<"Introduce el gas (1-> con) (0->sin): ";
    cin>>aux_int;
    this->set_gas(aux_int);

    cout <<"Introduce la cafeina (1-> con) (0->sin): ";
    cin>>aux_int;
    this->set_cafeina(aux_int);
}


istream& operator>>(istream&flujo, Refresco &r){
    string aux_s="";
    float aux_f=0.0;
    int aux_int=0;

    cout << "id_producto: ";
    flujo >> aux_s;
    r.set_id_producto(aux_s);

    cout << "nombre: "; 
    flujo >> aux_s;
    r.set_nombre(aux_s);

    cout << "precio_sin_iva: ";
    flujo >> aux_f;
    r.set_precio_producto_sin_iva(aux_f);


    cout << "tamano: ";
    flujo >> aux_s;
    r.set_tamano(aux_s);



    cout << "porcentaje_iva_producto: ";
    flujo >> aux_int;
    r.set_porcentaje_iva_producto(aux_int);


    r.calcular_precio_con_iva(r.get_precio_producto_sin_iva(), r.get_porcentaje_iva_producto());
    //precio_producto_con_iva:  --> se calcula, se suma el precio ingrediente a lo que ya esta y se calcula el precio con iva, al ser la entrada solo tenemos la base pues los ingredientes van a parte por tanto lo calcularemos con la base



    //valoracion_total se ira actualizando en otros modulos
    //activo no se introduce, se cambiara en otros modulos
    //num_pedidos_insertado no se introduce, se cambiara en otros modulos

    cout <<"Introduce el azucar (1-> con) (0->sin): ";
    flujo>>aux_int;
    r.set_azucar(aux_int);

    cout <<"Introduce el gas (1-> con) (0->sin): ";
    flujo>>aux_int;
    r.set_gas(aux_int);

    cout <<"Introduce la cafeina (1-> con) (0->sin): ";
    flujo>>aux_int;
    r.set_cafeina(aux_int);

    return flujo;
}



/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/



// Se realiza solo, todo es estatico
//Refresco& Refresco::operator=(const Refresco &r){}

bool Refresco::operator==(const Refresco &r){
    bool igual=true;
    if (this->get_azucar()!=r.get_azucar()){
        igual=false;
    }
    else if (this->get_cafeina()!=r.get_cafeina()){
        igual=false;
    }
    else if (this->get_gas()!=r.get_gas()){
        igual=false;
    }
    else if (this->get_tamano()!=r.get_tamano()){
        igual=false;
    }
    else if (this->get_nombre()!=r.get_nombre()){
        igual=false;
    }
    return igual;

}
