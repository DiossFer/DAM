#include "Cliente.h"

/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*--------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------ /  Cliente  / -------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/




/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/
Cliente::Cliente(){
    if(DEBUG_Cliente){
        cout << DEBUG << "ENTRANDO en crear cliente"<<DEFAULT<<endl;
    }
    this->set_id_cliente("");

    this->set_login_cliente("");

    this->set_pass_cliente("");

    this->set_nombre("");

    this->set_num_telefono("");

    this->set_direccion("");

    this->set_activo(true);

    this->set_valoracion_media_productos(0.0);

    this->set_precio_medio_pedidos_cliente(0.0);
    this->set_total_valoraciones_cliente(0.0);

    this->vector_pedidos_cliente=new Pedido [1];

    this->total_pedidos_cliente=0;
    if(DEBUG_Cliente){
        cout << DEBUG << "SALIENDO en crear cliente"<<DEFAULT<<endl;
    }
   
}

Cliente::Cliente(const Cliente &c){
    
    this->set_id_cliente(c.get_id_cliente());

    this->set_login_cliente(c.get_login_cliente());

    this->set_pass_cliente(c.get_pass_cliente());

    this->set_nombre(c.get_nombre());

    this->set_num_telefono(c.get_num_telefono());

    this->set_direccion(c.get_direccion());

    this->set_activo(c.get_activo());

    this->set_valoracion_media_productos(c.get_valoracion_media_productos());

    this->set_precio_medio_pedidos_cliente(c.get_precio_medio_pedidos_cliente());

    this->vector_pedidos_cliente = new Pedido[c.get_total_pedidos_cliente()+1];
    for (int i=0; i<c.get_total_pedidos_cliente(); i++){
        this->vector_pedidos_cliente[i]=c.vector_pedidos_cliente[i];
    }
    this->set_total_pedidos_cliente(c.get_total_pedidos_cliente());
}

Cliente::Cliente(string un_id_cliente, string un_login_cliente, string un_pass_cliente, string un_nombre, string un_num_telefono, string un_direccion, bool a){
    if(DEBUG_Cliente){
        cout << DEBUG << "ENTRANDO en crear cliente por parametros"<<DEFAULT<<endl;
    }
    this->set_id_cliente(un_id_cliente);

    this->set_login_cliente(un_login_cliente);

    this->set_pass_cliente(un_pass_cliente);

    this->set_nombre(un_nombre);

    this->set_num_telefono(un_num_telefono);

    this->set_direccion(un_direccion);

    this->set_activo(true);

    this->set_valoracion_media_productos(0.0);

    this->set_precio_medio_pedidos_cliente(0.0);



    this->vector_pedidos_cliente=new Pedido [1];

    this->total_pedidos_cliente=0;

    this->set_total_valoraciones_cliente(0.0);
    if(DEBUG_Cliente){
        cout << DEBUG << "SALIENDO en crear cliente por parametros"<<DEFAULT<<endl;
    }
}

Cliente::~Cliente(){
if(DEBUG_Cliente){
        cout << DEBUG << "ENTRANDO en dstructor cliente"<<DEFAULT<<endl;
    }
    if(DEBUG_Cliente){
        cout << DEBUG << "SALIENDO en dstructor cliente"<<DEFAULT<<endl;
    }
}


/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/

string Cliente::get_id_cliente() const{
    return this->id_cliente;
}


string Cliente::get_login_cliente() const{
    return this->login_cliente;
}

string Cliente::get_pass_cliente() const{
    return this->pass_cliente;
}

string Cliente::get_nombre() const{
    return this->nombre;
}

string Cliente::get_num_telefono() const{
    return this->num_telefono;
}

string Cliente::get_direccion() const{
    return this->direccion;
}

bool Cliente::get_activo() const{
    return this->activo;
}

Pedido* Cliente::get_vector_pedidos_cliente(int posicion){
    return &this->vector_pedidos_cliente[posicion];
}

int Cliente::get_total_pedidos_cliente() const{
    return this->total_pedidos_cliente;
}


float Cliente::get_valoracion_media_productos() const{
    return this->valoracion_media_productos;
}

float Cliente::get_precio_medio_pedidos_cliente() const{
    return this->precio_medio_pedidos_cliente;
}

float Cliente::get_total_valoraciones_cliente() const{
    return this->total_valoraciones;
}

/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/


void Cliente::set_id_cliente(string aux){
    this->id_cliente=aux;
}

void Cliente::set_login_cliente(string aux){
    this->login_cliente=aux;
}

void Cliente::set_pass_cliente(string aux){
    this->pass_cliente=aux;
}

void Cliente::set_nombre(string aux){
    this->nombre=aux;
}

void Cliente::set_num_telefono(string aux){
    this->num_telefono=aux;
}

void Cliente::set_direccion(string aux){
    this->direccion=aux;
}
void Cliente::set_activo(bool aux){
    this->activo=aux;
}


void Cliente::set_total_pedidos_cliente(int aux){
    this->total_pedidos_cliente=aux;
}

void Cliente::set_pedido_vector_pedidos_cliente(const Pedido &p){

    this->set_precio_medio_pedidos_cliente(((this->get_precio_medio_pedidos_cliente()*this->get_total_pedidos_cliente()) + p.get_total_precio_pedido_con_iva())/(this->get_total_pedidos_cliente()+1));


    this->resize_vector_pedidos_cliente(this->get_total_pedidos_cliente()+2);

    this->vector_pedidos_cliente[this->get_total_pedidos_cliente()]=p;

    this->set_total_pedidos_cliente(this->get_total_pedidos_cliente()+1);


}

void Cliente::set_valoracion_media_productos(float aux){
    this->valoracion_media_productos=aux;
}

void Cliente::set_precio_medio_pedidos_cliente(float aux){
    this->precio_medio_pedidos_cliente=aux;
}

void Cliente::set_total_valoraciones_cliente(float aux){
    this->total_valoraciones=aux;
}


/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/


void Cliente::print(){
    
    cout << BLUE << endl;

    cout << "id_cliente";
    cout << '\t';

    cout << "login";
    cout << '\t';

    cout << "pass";
    cout << '\t';

    cout << "nombre";
    cout << '\t';

    cout << "num_tel";
    cout << '\t';

    cout << "Direccion";
    cout << '\t';

    cout << "Activo";
    cout << '\t';

    cout << "Valoracion_media_productos";
    cout << '\t';

    cout << "precio_medio_productos";
    cout << '\t';
    cout << '\n';

    cout << this->get_id_cliente();
    cout << '\t'<<'\t';

    cout << this->get_login_cliente();
    cout << '\t'<<'\t';

    cout << this->get_pass_cliente();
    cout << '\t'<<'\t';

    cout << this->get_nombre();
    cout << '\t'<<'\t';

    cout << this->get_num_telefono();
    cout << '\t'<<'\t';

    cout << this->get_direccion();
    cout << '\t'<<'\t';

    cout << this->get_activo();
    cout << '\t'<<'\t';

    cout << this->get_valoracion_media_productos();
    cout << '\t'<<'\t';

    cout << this->get_precio_medio_pedidos_cliente();
    cout << '\t'<<'\t';

    cout << DEFAULT << endl;

    for (int i=0; i<this->get_total_pedidos_cliente(); i++){
        cout << "Pedido " <<i+1<<": "<<endl;
        this->vector_pedidos_cliente[i].print();
        
    }

    cout << endl<<DEFAULT;
}
void Cliente::print_solo_cliente(){

    cout << BLUE << endl;

    cout << "id_cliente";
    cout << '\t';

    cout << "login";
    cout << '\t';

    cout << "pass";
    cout << '\t';

    cout << "nombre";
    cout << '\t';

    cout << "num_tel";
    cout << '\t';

    cout << "Direccion";
    cout << '\t';

    cout << "Activo";
    cout << '\t';

    cout << "Valoracion_media_productos";
    cout << '\t';

    cout << "precio_medio_productos";
    cout << '\t';
    cout << '\n';

    cout << this->get_id_cliente();
    cout << '\t'<<'\t';

    cout << this->get_login_cliente();
    cout << '\t'<<'\t';

    cout << this->get_pass_cliente();
    cout << '\t'<<'\t';

    cout << this->get_nombre();
    cout << '\t'<<'\t';

    cout << this->get_num_telefono();
    cout << '\t'<<'\t';

    cout << this->get_direccion();
    cout << '\t'<<'\t';

    cout << this->get_activo();
    cout << '\t'<<'\t';

    cout << this->get_valoracion_media_productos();
    cout << '\t'<<'\t';

    cout << this->get_precio_medio_pedidos_cliente();
    cout << '\t'<<'\t';

    cout << DEFAULT << endl;
}
void Cliente::introducir(){
    string aux_s="";


    cout << "Introduce el id_cliente: ";
    cin>>aux_s;
    this->set_id_cliente(aux_s);

    cout << "Introduce el login: ";
    cin>>aux_s;
    this->set_login_cliente(aux_s);

    cout << "Introduce la contraseña: ";
    cin>>aux_s;
    this->set_pass_cliente(aux_s);

    cout << "Introduce el nombre: ";
    cin>>aux_s;
    this->set_nombre(aux_s);

    cout << "Introduce el numero de telefono: ";
    cin>>aux_s;
    this->set_num_telefono(aux_s);

    cout << "Introduce la direccion: ";
    cin>>aux_s;
    this->set_direccion(aux_s);


    this->set_activo(true);

    this->set_valoracion_media_productos(0);

    this->set_precio_medio_pedidos_cliente(0);
}

Producto* Cliente::realizar_valoracion(){
    int aux_int=0;
    int aux_int2=0;

    for (int i=0; i<this->get_total_pedidos_cliente(); i++){
        cout << "Pedido " <<i+1<<": "<<endl;
        this->vector_pedidos_cliente[i].print(); 
    }
    do{
        cout << "Sobre que pedido quieres realizar una valoracion: ";
        cin>>aux_int;
        cout << this->get_total_pedidos_cliente()<<endl;
    }while(aux_int<=0 || aux_int>this->get_total_pedidos_cliente());

    this->vector_pedidos_cliente[aux_int-1].print();

    do{
        cout << "Sobre que producto quieres realizar una valoracion: ";
        cin>>aux_int2;
    }while(aux_int2<=0 || aux_int2>this->vector_pedidos_cliente[aux_int-1].get_total_productos_pedido());

    return this->vector_pedidos_cliente[aux_int-1].get_producto_pedido(aux_int2-1);

}

/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/

Cliente Cliente::operator=(const Cliente &c){
    this->set_id_cliente(c.get_id_cliente());

    this->set_login_cliente(c.get_login_cliente());

    this->set_pass_cliente(c.get_pass_cliente());

    this->set_nombre(c.get_nombre());

    this->set_num_telefono(c.get_num_telefono());

    this->set_direccion(c.get_direccion());

    this->set_activo(c.get_activo());

    this->set_valoracion_media_productos(c.get_valoracion_media_productos());

    this->set_precio_medio_pedidos_cliente(c.get_precio_medio_pedidos_cliente());
    
    this->set_total_pedidos_cliente(0);

    this->vector_pedidos_cliente=new Pedido [c.get_total_pedidos_cliente()+1];
    for (int i=0; i<c.get_total_pedidos_cliente(); i++){
        this->vector_pedidos_cliente[i]=c.vector_pedidos_cliente[i];
    }

    this->set_total_pedidos_cliente(c.get_total_pedidos_cliente());
    this->set_total_valoraciones_cliente(c.get_total_valoraciones_cliente());
    

    return *this;
}


void Cliente::resize_vector_pedidos_cliente(int new_dim){

    Pedido* aux_p=new Pedido[new_dim];

    for (int i=0; i<new_dim-1; i++){

        aux_p[i]=this->vector_pedidos_cliente[i];

    }
    this->vector_pedidos_cliente=aux_p;

}

void Cliente::eliminar_cancelar_pedido(int posicion){

    //Si cancela el pedido los productos estaran incluidos en un pedido menos
    for (int j=0; j<this->vector_pedidos_cliente[posicion].get_total_productos_pedido(); j++){
        this->vector_pedidos_cliente[posicion].get_producto_pedido(j)->set_num_veces_incluido_en_pedidos ((this->vector_pedidos_cliente[posicion].get_producto_pedido(j)->get_num_veces_incluido_en_pedidos()) - 1);
    }

    for (int i=posicion; (i<this->get_total_pedidos_cliente()); i++){

        this->vector_pedidos_cliente[posicion]=vector_pedidos_cliente[posicion+1];
    }
    this->set_total_pedidos_cliente(this->get_total_pedidos_cliente()-1);


}