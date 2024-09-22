#include "Ingrediente.h"

/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------- /  Ingrediente  / -----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/




/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/
Ingrediente::Ingrediente(){

    if (DEBUG_ingrediente){
        cout << BOLDCYAN<<"INICIO constructor ingrediente"<<endl<<DEFAULT;
    }

    this->set_id_ingrediente("");
    this->set_nombre("");
    this->set_activo(true);
    this->set_precio_ingrediente(0.0);
    this->set_tipo("");
    this->set_num_veces_incluido_en_pizzas(0);

    if (DEBUG_ingrediente){
        cout << BOLDCYAN<<"FIN constructor ingrediente"<<endl<<DEFAULT;
    }
}

//Todo estatico
//Ingrediente::Ingrediente(const Ingrediente &i){}

Ingrediente::Ingrediente(const string id, const string nombre, const float precio, const string tipo){
    this->set_id_ingrediente(id);
    this->set_nombre(nombre);
    this->set_precio_ingrediente(precio);
    this->set_tipo(tipo);

    this->set_activo(true);
    this->set_num_veces_incluido_en_pizzas(0);
}

Ingrediente::~Ingrediente(){
    if (DEBUG_ingrediente){
        cout << BOLDCYAN<<"INICIO destructor ingrediente"<<endl<<DEFAULT;
    }

    //No hace falta, todo es estatico

    if (DEBUG_ingrediente){
        cout << BOLDCYAN<<"FIN destructor ingrediente"<<endl<<DEFAULT;
    }
}



/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/


string Ingrediente::get_id_ingrediente() const{
    return this-> id_ingrediente;
}

string Ingrediente::get_nombre() const{
    return this-> nombre;
}

bool Ingrediente::get_activo() const{
    return this-> activo;
}

float Ingrediente::get_precio_ingrediente() const{
    return this-> precio_ingrediente;
}

string Ingrediente::get_tipo() const{
    return this-> tipo;
}
int Ingrediente::get_num_veces_incluido_en_pizzas() const{
    return this-> num_veces_incluido_en_pizzas;
}

/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/

void Ingrediente::set_id_ingrediente(string aux_s){
    this-> id_ingrediente=aux_s;
}

void Ingrediente::set_nombre(string aux_s){
    this-> nombre=aux_s;
}

void Ingrediente::set_activo(bool a){
    this-> activo=a;
}

void Ingrediente::set_precio_ingrediente(float aux_f){
    this-> precio_ingrediente=aux_f;
}

void Ingrediente::set_tipo(string aux_s){
    this-> tipo=aux_s;
}

void Ingrediente::set_num_veces_incluido_en_pizzas(int new_num){
    this-> num_veces_incluido_en_pizzas=new_num;
}

/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/

//se realizara a futuro cout y cin



ostream& operator<<(ostream&flujo, const Ingrediente &i){
    flujo <<BOLDYELLOW<< "Id_ingrediente"<<'\t';
    flujo << "Nombre"<<'\t';
    flujo << "actividad"<<'\t';
    flujo << "Precio_ingrediente"<<'\t';
    flujo << "Tipo"<<'\t';
    flujo << "num_veces_incluido_en_pizzas"<<'\t'<<endl;

    flujo<<i.get_id_ingrediente()<<'\t';
    flujo<<i.get_nombre()<<'\t';
    flujo<<i.get_activo()<<'\t';
    flujo<<i.get_precio_ingrediente()<<'\t';
    flujo<<i.get_tipo()<<'\t';
    flujo<<i.get_num_veces_incluido_en_pizzas()<<'\t'<<endl<<DEFAULT;

    return flujo;
}

/*
void Ingrediente::print(){
    cout << "Id_ingrediente: "<<this->get_id_ingrediente()<<endl;
    cout << "Nombre: "<<this->get_nombre()<<endl;
    cout << "precio_ingrediente_sin_iva: "<<this->get_precio_ingrediente_sin_iva()<<endl;
    cout << "IVA ingrediente: "<<this->get_iva_ingrediente()<<endl;
    cout << "Tipo: "<<this->get_tipo()<<endl;
}
*/

istream& operator>>(istream&flujo, Ingrediente &i){
    string aux_s="";
    float aux_f=0.0;

    cout << "Introduce el Id_ingrediente: ";
    flujo>>aux_s;
    i.set_id_ingrediente(aux_s);
    
    cout << "Introduce el Nombre: ";
    flujo>>aux_s;
    i.set_nombre(aux_s);

    cout << "Introduce el precio_ingrediente: ";
    flujo>>aux_f;
    i.set_precio_ingrediente(aux_f);

    //activo sera es aprate cuando se tenga que desactivar

    cout << "Introduce el Tipo: ";
    flujo>>aux_s;
    i.set_tipo(aux_s);

    //num de pizzas que lo usan ira aparte cuando se añada en una pizza


    return flujo;
}


/*
void Ingrediente::introducir(){
    string aux_s="";
    float aux_f=0.0;

    cout << "Introduce el Id_ingrediente: ";
    cin>>aux_s;
    this->set_id_ingrediente(aux_s);
    
    cout << "Introduce el Nombre: ";
    cin>>aux_s;
    this->set_nombre(aux_s);

    cout << "Introduce el precio_ingrediente_sin_iva: ";
    cin>>aux_f;
    this->set_precio_ingrediente_sin_iva(aux_f);

    cout << "Introduce el IVA ingrediente: ";
    cin>>aux_f;
    this->set_iva_ingrediente(aux_f);

    cout << "Introduce el Tipo: ";
    cin>>aux_s;
    this->set_tipo(aux_s);

}
*/
/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/

//Todo estatico
//Ingrediente operator=(const Ingrediente &i){}