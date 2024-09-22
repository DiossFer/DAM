#include "Pizza.h"

/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/



/*--------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------- /  Pizza  / -------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/




/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/

Pizza::Pizza() : Producto(){
    if (DEBUG_pizza){
        cout << YELLOW << "INICIO en el constructor de pizza"<<DEFAULT<<endl;
    }
    this->set_tipo_pizza("");

    this->set_total_ingredientes_pizza(0);

    this->vetorIngredientes=create_vector_ptr_ingredientes(1);

    this->set_preciobase_sin_iva(0.0);
    if (DEBUG_pizza){
        cout << YELLOW << "FIN en el constructor de pizza"<<DEFAULT<<endl;
    }
}

Pizza::Pizza(const Pizza &p){

    if (DEBUG_pizza){
        cout << YELLOW << "INICIO en el constructor por copia de pizza"<<DEFAULT<<endl;
    }
    this->set_tipo_pizza("");

    this->set_total_ingredientes_pizza(0);

    this->vetorIngredientes=new Ingrediente* [1];
    
    this->set_preciobase_sin_iva(0.0);


    this->set_id_producto(p.get_id_producto());

    this->set_nombre(p.get_nombre());


    this->set_tamano(p.get_tamano());

    this->set_activo(p.get_activo());
    this->set_valoracion_total(p.get_valoracion_total());

    this->set_num_veces_incluido_en_pedidos (p.get_num_veces_incluido_en_pedidos());
    this->set_tipo_pizza(p.get_tipo_pizza());


    this->set_preciobase_sin_iva(p.get_preciobase_sin_iva());
    
    this->set_porcentaje_iva_producto(p.get_porcentaje_iva_producto());
    
    this->set_precio_producto_sin_iva(this->get_preciobase_sin_iva());

    this->calcular_precio_con_iva(this->get_preciobase_sin_iva(), this->get_porcentaje_iva_producto());
    

    for (int i=0; i<p.get_total_ingredientes_pizza(); i++){
        this->set_Ingrediente_pizza(p.get_Ingrediente_pizza(i));
    }
    
    if (DEBUG_pizza){
        cout << YELLOW << "FIN en el constructor por copia de pizza"<<DEFAULT<<endl;
    }
}


Pizza::Pizza(const string id_producto, const string nombre, const string tamano, const int porcentaje_iva_producto, const float precio_base, const bool a, const string tipo) : Producto(id_producto, nombre, precio_producto_sin_iva, tamano, porcentaje_iva_producto, a){
    this->set_tipo_pizza("Sistema");
    this->set_preciobase_sin_iva(precio_base);
    this->set_precio_producto_sin_iva(this->get_preciobase_sin_iva());

    this->calcular_precio_con_iva(this->get_precio_producto_sin_iva(), this->get_porcentaje_iva_producto());
    
    this->set_total_ingredientes_pizza(0);
    this->vetorIngredientes=create_vector_ptr_ingredientes(1);
}



Pizza::~Pizza(){

    if (DEBUG_pizza){
        cout << YELLOW << "INICIO en el destructor de pizza"<<DEFAULT<<endl;
    }
    for (int i=0; i<=this->get_total_ingredientes_pizza()-1; i++){
        this->vetorIngredientes[i]->set_num_veces_incluido_en_pizzas(this->vetorIngredientes[i]->get_num_veces_incluido_en_pizzas()-1);
    }
    
    delete [] this->vetorIngredientes;

    this->vetorIngredientes=NULL;
    if (DEBUG_pizza){
        cout << YELLOW << "FIN en el destructor de pizza"<<DEFAULT<<endl;
    }
}

/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/


string Pizza::get_tipo_pizza () const{
    return this-> tipo_pizza;
}

int Pizza::get_total_ingredientes_pizza () const{
    return this-> total_ingredientes_pizza;
}

Ingrediente* Pizza::get_Ingrediente_pizza (int posicion) const{
    return this-> vetorIngredientes[posicion];
}

float Pizza::get_preciobase_sin_iva() const{
    return this->preciobase_sin_iva;
}

/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/


void Pizza::set_tipo_pizza (string tipo){
    this->tipo_pizza=tipo;
}

void Pizza::set_total_ingredientes_pizza (int total){
    this->total_ingredientes_pizza=total;
}


void Pizza::set_Ingrediente_pizza (Ingrediente* i){

    if (DEBUG_pizza){
        cout << YELLOW << "INICIO set_Ingrediente_pizza (resice, insercion, actualizacion de precio con y sin iva, actualizacion de usos del ingrediente)"<<DEFAULT<<endl;
    }

    this->resize_vector_ptr_Ingredientes(this->get_total_ingredientes_pizza()+2);
    

    this->vetorIngredientes[this->get_total_ingredientes_pizza()]=i;

    this->set_total_ingredientes_pizza(this->get_total_ingredientes_pizza()+1);



    this->set_precio_producto_sin_iva(get_precio_producto_sin_iva()+i->get_precio_ingrediente());//calculamos y actualizamos el precio sin iva

    this->calcular_precio_con_iva(this->get_precio_producto_sin_iva(), this->get_porcentaje_iva_producto());//calculamos y actualizamos el precio con iva

    i->set_num_veces_incluido_en_pizzas(i->get_num_veces_incluido_en_pizzas()+1);//actualizamos el numero de usos del ingrediete

    if (DEBUG_pizza){
        cout << YELLOW << "FIN set_Ingrediente_pizza (resice, insercion, actualizacion de precio con y sin iva, actualizacion de usos del ingrediente)"<<DEFAULT<<endl;
    }
}


void Pizza::set_preciobase_sin_iva(const float precio){
    this->preciobase_sin_iva=precio;
}


/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/

ostream& operator<<(ostream&flujo, const Pizza &p){
    flujo << "id_producto: " << p.get_id_producto() <<endl;

    flujo << "nombre: " << p.get_nombre() <<endl;

    flujo << "precio_sin_iva: " << p.get_precio_producto_sin_iva() <<endl;

    flujo << "tamano: " << p.get_tamano() <<endl;


    flujo <<"Activo: "<<p.get_activo()<<endl;

    flujo <<"precio_producto_con_iva: "<<p.get_precio_producto_con_iva()<<endl;

    flujo <<"get_porcentaje_iva_producto: "<<p.get_porcentaje_iva_producto()<<endl;

    flujo <<"get_valoracion_total: "<<p.get_valoracion_total()<<endl;

    flujo <<"num_veces_incluido_en_pedidos: "<<p.get_num_veces_incluido_en_pedidos()<<endl;

    flujo << "tipo_pizza: "<<p.get_tipo_pizza()<<endl;

    flujo << "precio_base_sin_iva: "<<p.get_preciobase_sin_iva()<<endl;

    for (int i=0; i<p.get_total_ingredientes_pizza(); i++){
        flujo << "Ingrediente "<<i+1<<": " <<endl<< *p.get_Ingrediente_pizza(i) <<endl;
    }

    return flujo;
}

void Pizza::print (){
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
    cout << "tipo_pizza"<<'\t';
    cout << "precio_base_sin_iva"<<'\t'<<endl;

    cout << this->get_id_producto() <<'\t';
    cout << this->get_nombre() <<'\t';
    cout << this->get_precio_producto_sin_iva() <<'\t';
    cout << this->get_tamano() <<'\t';
    cout<<this->get_activo()<<'\t';
    cout<<this->get_precio_producto_con_iva()<<'\t';
    cout<<this->get_porcentaje_iva_producto()<<'\t';
    cout<<this->get_valoracion_total()<<'\t';
    cout<<this->get_num_veces_incluido_en_pedidos()<<'\t';
    cout<<this->get_tipo_pizza()<<'\t';
    cout<<this->get_preciobase_sin_iva()<<'\t'<<endl;


    for (int i=0; i<this->get_total_ingredientes_pizza(); i++){
        cout << "Ingrediente "<<i+1<<": " <<endl<< *this->get_Ingrediente_pizza(i) <<endl;
    }
    cout << endl;
    cout << DEFAULT;

}



istream& operator>>(istream&flujo, Pizza &p){
    string aux_s="";
    float aux_f=0.0;
    int aux_int=0;

    cout << "Introduce el tipo de la pizza: ";
    flujo>>aux_s;
    p.set_tipo_pizza(aux_s);


    //crear

    cout << "id_producto: ";
    flujo >> aux_s;
    p.set_id_producto(aux_s);

    cout << "nombre: "; 
    flujo >> aux_s;
    p.set_nombre(aux_s);
    
    cout << "Introduce el precio base de la pizza: ";
    flujo>>aux_f;
    p.set_preciobase_sin_iva(aux_f);

    cout << "porcentaje_iva_producto: ";
    flujo >> aux_int;
    p.set_porcentaje_iva_producto(aux_int);

    cout << "tamano: ";
    flujo >> aux_s;
    p.set_tamano(aux_s);



    p.set_precio_producto_sin_iva(p.get_preciobase_sin_iva());
    //Precio sin iva=base+ ingredientes //actualmente solo base
    p.calcular_precio_con_iva(p.get_preciobase_sin_iva(), p.get_porcentaje_iva_producto());
    //precio_producto_con_iva:  --> se calcula, se suma el precio ingrediente a lo que ya esta y se calcula el precio con iva, al ser la entrada solo tenemos la base pues los ingredientes van a parte por tanto lo calcularemos con la base

    cout<<endl<<endl;

    

    //Los ingredientes se meten aparte

    //valoracion_total se ira actualizando en otros modulos
    //activo no se introduce, se cambiara en otros modulos
    //num_pedidos_insertado no se introduce, se cambiara en otros modulos

    return flujo;
}
void Pizza::introducir(){
    string aux_s="";
    float aux_f=0.0;
    int aux_int=0;

    cout << "Introduce el tipo de la pizza: ";
    cin>>aux_s;
    this->set_tipo_pizza(aux_s);

    cout << "id_producto: ";
    cin >> aux_s;
    this->set_id_producto(aux_s);

    cout << "nombre: "; 
    cin >> aux_s;
    this->set_nombre(aux_s);
    
    cout << "Introduce el precio base de la pizza: ";
    cin>>aux_f;
    this->set_preciobase_sin_iva(aux_f);

    cout << "porcentaje_iva_producto: ";
    cin >> aux_int;
    this->set_porcentaje_iva_producto(aux_int);

    cout << "tamano: ";
    cin >> aux_s;
    this->set_tamano(aux_s);



    this->set_precio_producto_sin_iva(this->get_preciobase_sin_iva());
    //Precio sin iva=base+ ingredientes //actualmente solo base
    this->calcular_precio_con_iva(this->get_preciobase_sin_iva(), this->get_porcentaje_iva_producto());
    //precio_producto_con_iva:  --> se calcula, se suma el precio ingrediente a lo que ya esta y se calcula el precio con iva, al ser la entrada solo tenemos la base pues los ingredientes van a parte por tanto lo calcularemos con la base

    cout<<endl<<endl;

    

    //Los ingredientes se meten aparte

    //valoracion_total se ira actualizando en otros modulos
    //activo no se introduce, se cambiara en otros modulos
    //num_pedidos_insertado no se introduce, se cambiara en otros modulos
}

/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/


Pizza Pizza::operator=(const Pizza &p){

    if (DEBUG_pizza){
        cout << YELLOW << "Estas copiando por parametros una pizza"<<endl<<DEFAULT;
    }

    this->set_id_producto(p.get_id_producto());

    this->set_nombre(p.get_nombre());


    this->set_tamano(p.get_tamano());

    this->set_activo(p.get_activo());
    this->set_valoracion_total(p.get_valoracion_total());

    this->set_num_veces_incluido_en_pedidos (p.get_num_veces_incluido_en_pedidos());
    this->set_tipo_pizza(p.get_tipo_pizza());


    this->set_preciobase_sin_iva(p.get_preciobase_sin_iva());
    
    this->set_porcentaje_iva_producto(p.get_porcentaje_iva_producto());

    this->set_precio_producto_sin_iva(this->get_preciobase_sin_iva());

    this->calcular_precio_con_iva(this->get_preciobase_sin_iva(), this->get_porcentaje_iva_producto());
    

    for (int i=0; i<p.get_total_ingredientes_pizza(); i++){
        this->set_Ingrediente_pizza(p.get_Ingrediente_pizza(i));
    }

    //total_ingredientes se actualiza conforme los ingredientes


    if (DEBUG_pizza){
        cout << YELLOW << "Has terminado de copiar por parametros una pizza"<<endl<<DEFAULT;
    }
    return *this;
}


void Pizza::resize_vector_ptr_Ingredientes(int new_dim){

    if (DEBUG_pizza){
        cout <<BOLDRED<< "ENTRANDO en resize vector ptr ingredientes"<<endl<< DEFAULT;
    }

    Ingrediente** aux_ptr_I=create_vector_ptr_ingredientes(new_dim);


    for (int i=0; i<new_dim-1; i++){
        aux_ptr_I[i]=this->get_Ingrediente_pizza(i);
    }
    delete [] this->vetorIngredientes;

    this->vetorIngredientes=aux_ptr_I;

    if (DEBUG_pizza){
        cout <<BOLDRED<< "SALIENDO en resize vector ptr ingredientes"<<endl<< DEFAULT;
    }
    
}



Ingrediente** Pizza::create_vector_ptr_ingredientes(int dim){
    if (DEBUG_pizza){
        cout << YELLOW << "INICIO creando vector_ptr_Ingrediente"<<DEFAULT<<endl;
    }
    Ingrediente** I_aux = new Ingrediente* [dim];

    if (I_aux == NULL){
        cout << "No hay memoria disponible" << endl;
        exit(1);
    }
    if (DEBUG_pizza){
        cout << YELLOW << "FIN creando vector_ptr_Ingrediente"<<DEFAULT<<endl;
    }
    return I_aux;

}


bool Pizza::operator==(const Pizza &p) const{

    bool igual=true;
    int numero_de_iguales_1=0;
    int numero_de_iguales_2=0;

    if (this->get_tamano()!=p.get_tamano()){ //tamaño diferente son pizzas diferentes
        igual=false;
        if (DEBUG_pizza){
            cout <<BOLDRED<<endl<< "_-_-_-_-_-_-_-_-_-_-_-_-_-   Son de diferente tamaño"<<DEFAULT<<endl;
        }
    }
    else if (this->get_total_ingredientes_pizza()!=p.get_total_ingredientes_pizza()){ //distinto numero de ingredientes
        if (DEBUG_pizza){
            cout <<BOLDRED<<endl<< "_-_-_-_-_-_-_-_-_-_-_-_-_-   Diferente numero de ingredietes"<<DEFAULT<<endl;
        }
        igual=false;
    }
    else{ //mismo tamaño de ingredientes

        for (int i=0; i<this->get_total_ingredientes_pizza() && igual==true; i++){
            numero_de_iguales_1=0;
            numero_de_iguales_2=0;


            for (int j=0; j<this->get_total_ingredientes_pizza(); j++){

                //Contar las veces que el ingrediente de this esta en p
                if (this->get_Ingrediente_pizza(i)==p.get_Ingrediente_pizza(j)){
                    numero_de_iguales_1++;//vecs que encontramos el ingrediente de this en p

                    //Cuando sean iguales los ingredientes contamos cuantas veces esta el mismo ingrediente de p en this
                    numero_de_iguales_2=0;//Veces que esta el ingrediente en this
                    for (int z=0; z<=this->get_total_ingredientes_pizza(); z++){
                        if (p.get_Ingrediente_pizza(j)==this->get_Ingrediente_pizza(z)){
                            numero_de_iguales_2++;
                        }
                    }

                }

            }//Al salir tendremos cuantas veces esta el ingrediente i en this (numero_de_iguales_2) y cuantas en p (numero_de_iguales_1)


            //Comprobaciones de si el ingrediente es o no apto (sale las mismas veces en ambos productos)

            if (numero_de_iguales_1==0){ //ingrediente i no esta en p
                igual=false;
            }
            else if (numero_de_iguales_1==numero_de_iguales_2){ //sale las mismas veces en this que en p
                if (DEBUG_pizza){
                    cout <<BOLDGREEN<<endl<< "_-_-_-_-_-_-_-_-_-_-_-_-_-   Las pizzas son iguales"<<DEFAULT<<endl;
                }
                igual=true;
            }
            else{ //Sale mas veces en uno que en el otro 
                if (DEBUG_pizza){
                    cout <<BOLDGREEN<<endl<< "_-_-_-_-_-_-_-_-_-_-_-_-_-   Las pizzas VARIAN en los ingredientes"<<DEFAULT<<endl;
                }
                igual=false;
            }

        } // Si hemos pasado por todos los ingredientes de yhis y salen las mismas veces en ambos productos las pizzas son iguales 
    }

    if (DEBUG_pizza){
        cout <<endl<< "FIN == -> _-_-_-_-_-_-_-_-_-_-_-_-_- ->   -|"<< igual<<"|-"<<endl;
    }
    return igual;
}

void Pizza::quitar_ingrediente(int posicion){

    
    for (int i=posicion; i<this->get_total_ingredientes_pizza()-1; i++){
        this->vetorIngredientes[i]=this->vetorIngredientes[i+1];
    }

    this->resize_vector_ptr_Ingredientes(this->get_total_ingredientes_pizza());

    this->set_total_ingredientes_pizza(this->get_total_ingredientes_pizza()-1);

}

