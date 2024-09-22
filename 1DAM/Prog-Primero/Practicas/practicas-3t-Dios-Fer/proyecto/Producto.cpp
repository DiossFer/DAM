#include "Producto.h"

/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/


/*-------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  Producto  / ------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/




/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/


Producto::Producto(){
    if (DEBUG_producto){
        cout <<GREEN<< "INICIO creador producto"<<DEFAULT<<endl;
    }

    this->set_id_producto("");

    this->set_nombre("");

    this->set_precio_producto_sin_iva(0.0);


    this->set_tamano("");

    this->set_activo(true);

    this->set_precio_producto_con_iva(0.0);

    this->set_porcentaje_iva_producto(0);

    this->set_valoracion_total(0.0);//Resultante de la formula

    this->set_num_veces_incluido_en_pedidos(0);

    this->set_valoracion_media(0.0);
    this->set_num_valoracion(0.0);

    if (DEBUG_producto){
        cout <<GREEN<< "FIN creador producto"<<DEFAULT<<endl;
    }

}


//No hace falta todo es estatico
//Producto::Producto(const Producto &p){}



Producto::Producto(const string id_producto, const string nombre, const float precio_producto_sin_iva, const string tamano, const int porcentaje_iva_producto, const bool a){

    if (DEBUG_producto){
        cout <<GREEN<< "INICIO creador por parametros producto"<<DEFAULT<<endl;
    }

    this->set_id_producto(id_producto);

    this->set_nombre(nombre);

    this->set_precio_producto_sin_iva(precio_producto_sin_iva);


    this->set_tamano(tamano);

    this->set_activo(a);

    this->set_porcentaje_iva_producto(porcentaje_iva_producto);

    this->set_valoracion_total(0);

    this->set_num_veces_incluido_en_pedidos(0);

    this->calcular_precio_con_iva(this->get_precio_producto_sin_iva(), this->get_porcentaje_iva_producto());
    this->set_valoracion_media(0.0);
    this->set_num_valoracion(0.0);

    if (DEBUG_producto){
        cout <<GREEN<< "FIN creador por parametros producto"<<DEFAULT<<endl;
    }
    
}




Producto::~Producto(){
    if (DEBUG_producto){
        cout <<GREEN<< "INICIO destructor producto"<<DEFAULT<<endl;
    }

    //No se necesita, todo es estatico

    if (DEBUG_producto){
        cout <<GREEN<< "FIN destructor producto"<<DEFAULT<<endl;
    }
}




/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/

string Producto::get_id_producto() const{
    return this->id_producto;
}

string Producto::get_nombre() const{
    return this->nombre;
}


float Producto::get_precio_producto_sin_iva () const{
    return this->precio_producto_sin_iva;
}


string Producto::get_tamano() const{
    return this->tamano;
}


        
bool Producto::get_activo () const{
    return this->activo;
}


        
float Producto::get_precio_producto_con_iva () const{
    return this->precio_producto_con_iva;
}


        
int Producto::get_porcentaje_iva_producto () const{
    return this->porcentaje_iva_producto;
}

float Producto::get_valoracion_total () const{
    return this->valoracion_total;
}
        

int Producto::get_num_veces_incluido_en_pedidos () const{
    return this->num_veces_incluido_en_pedidos;
}

float Producto::get_valoracion_media(){
    return this->valoracion_media;
}
float Producto::get_num_valoracion(){
    return this->num_valoracion;
}


/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/

void Producto::set_id_producto(const string id){
    this->id_producto=id;
}

void Producto::set_nombre(const string n){
    this->nombre=n;
}

void Producto::set_precio_producto_sin_iva (const float p_n_i){
    this->precio_producto_sin_iva=p_n_i;
}



void Producto::set_tamano(const string t){
    this->tamano=t;
}

        
void Producto::set_activo(const bool b){
    this->activo=b;
}


        
void Producto::set_precio_producto_con_iva(const float f){
    this->precio_producto_con_iva=f;
}


        
void Producto::set_porcentaje_iva_producto(const int i){
    this->porcentaje_iva_producto=i;
}


        
void Producto::set_valoracion_total(const float f){
    this->valoracion_total=f;
}
        


        
void Producto::set_num_veces_incluido_en_pedidos(const int i){
    this->num_veces_incluido_en_pedidos=i;
}

void Producto::set_valoracion_media(float aux){
    this->valoracion_media=aux;
}
void Producto::set_num_valoracion(float aux){
    this->num_valoracion=aux;
}


/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/

void Producto::print(){
    
    cout << "id_producto: " << this->get_id_producto() <<endl;

    cout << "nombre: " << this->get_nombre() <<endl;

    cout << "precio_sin_iva: " << this->get_precio_producto_sin_iva() <<endl;

    cout << "tamano: " << this->get_tamano() <<endl;

    cout <<"Activo: "<<this->get_activo()<<endl;

    cout <<"precio_producto_con_iva: "<<this->get_precio_producto_con_iva()<<endl;

    cout <<"get_porcentaje_iva_producto: "<<this->get_porcentaje_iva_producto()<<endl;

    cout <<"get_valoracion_total: "<<this->get_valoracion_total()<<endl;

    cout <<"num_veces_incluido_en_pedidos: "<<this->get_num_veces_incluido_en_pedidos()<<endl;


}

void Producto::imprimir_estadisticas_producto(){
    cout << "num_valoracion"<<'\t';
    cout << "num_veces_incluido_en_pedidos"<<'\t';
    cout << "valoracion_media" <<'\t';
    cout << "valoracion_total"<<'\t'<<endl;

    cout << this->get_num_valoracion()<<'\t';
    cout << this->get_num_veces_incluido_en_pedidos()<<'\t';
    cout << this->get_valoracion_media()<<'\t';
    cout << this->get_valoracion_total()<<'\t'<<endl;
    
}
void Producto::imprimir_solo_producto(){
    cout << "id_producto"<<'\t';
    cout << "nombre"<<'\t';
    cout << "tamano"<<'\t';
    cout <<"precio_producto_con_iva"<<'\t';
    cout <<"get_valoracion_total"<<'\t'<<endl;

    cout << this->get_id_producto() <<'\t';
    cout << this->get_nombre() <<'\t';
    cout << this->get_tamano() <<'\t';
    cout<<this->get_precio_producto_con_iva()<<'\t';
    cout<<this->get_valoracion_total()<<'\t'<<endl;

}


ostream& operator<<(ostream&flujo, const Producto &p){
    
    flujo << "id_producto: " << p.get_id_producto() <<endl;

    flujo << "nombre: " << p.get_nombre() <<endl;

    flujo << "precio_sin_iva: " << p.get_precio_producto_sin_iva() <<endl;

    flujo << "tamano: " << p.get_tamano() <<endl;


    flujo <<"Activo: "<<p.get_activo()<<endl;

    flujo <<"precio_producto_con_iva: "<<p.get_precio_producto_con_iva()<<endl;

    flujo <<"get_porcentaje_iva_producto: "<<p.get_porcentaje_iva_producto()<<endl;

    flujo <<"get_valoracion_total: "<<p.get_valoracion_total()<<endl;

    flujo <<"num_veces_incluido_en_pedidos: "<<p.get_num_veces_incluido_en_pedidos()<<endl;


    return flujo;

}



void Producto::introducir(){ 
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


    cout << "precio_producto_con_iva: ";
    cin >> aux_f;
    this->set_precio_producto_con_iva(aux_f);


    cout << "porcentaje_iva_producto: ";
    cin >> aux_int;
    this->set_porcentaje_iva_producto(aux_int);


    //valoracion_total se ira actualizando en otros modulos
    //activo no se introduce, se cambiara en otros modulos
    //num_pedidos_insertado no se introduce, se cambiara en otros modulos

}




istream& operator>>(istream&flujo, Producto &p){
    
    string aux_s="";
    float aux_f=0.0;
    int aux_int=0;

    cout << "id_producto: ";
    flujo >> aux_s;
    p.set_id_producto(aux_s);

    cout << "nombre: "; 
    flujo >> aux_s;
    p.set_nombre(aux_s);

    cout << "precio_sin_iva: ";
    flujo >> aux_f;
    p.set_precio_producto_sin_iva(aux_f);


    cout << "tamano: ";
    flujo >> aux_s;
    p.set_tamano(aux_s);


    cout << "precio_producto_con_iva: ";
    flujo >> aux_f;
    p.set_precio_producto_con_iva(aux_f);


    cout << "porcentaje_iva_producto: ";
    flujo >> aux_int;
    p.set_porcentaje_iva_producto(aux_int);


    //valoracion_total se ira actualizando en otros modulos
    //activo no se introduce, se cambiara en otros modulos
    //num_pedidos_insertado no se introduce, se cambiara en otros modulos


    return flujo;

}



/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/

//No se realiza, todo es estatico
//Producto& Producto::operator=(const Producto &p){}

void Producto::calcular_precio_con_iva(float precio_sin_iva, int porcentaje_iva){
    this->set_precio_producto_con_iva(precio_sin_iva+(precio_sin_iva*porcentaje_iva/100));
}
