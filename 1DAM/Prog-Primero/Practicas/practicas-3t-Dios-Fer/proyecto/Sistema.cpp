#include "Sistema.h"


/* Standard C++ includes */
#include <stdlib.h>
#include<sstream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>





/**********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************
***********************************************************************************************************************************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  Sistema  / ----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/



/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/

Sistema::Sistema(){

    this->total_ingredientes_sistema=0;//Sera tal que las utiles y la dim sera uno mas

    this->ingredientes_sistema=create_vector_ingredientes(get_total_ingredientes_sistema()+1);

    this->total_productos_sistema=0;//Sera tal que las utiles y la dim sera uno mas

    this->clientes_sistema=new Cliente* [1];

    this->total_clientes_sistema=0;

    this->valoraciones_sistema=new Valoracion [1];

    this->total_valoraciones_sistema=0;

    this->productos_sistema=new Producto* [1];
    this->set_cliente_activo(NULL);

    this->set_total_clientes_encontrados(0);
    this->resultado_busqueda_clientes=new Cliente* [1];

    this->set_total_pedidos_encontrados(0);
    this->resultado_busqueda_pedidos=new Pedido* [1];

    this->set_total_productos_encontrados(0);
    this->resultado_busqueda_productos=new Producto* [1];

    //////////////////////////////////////////
    //Carga

    this->set_id_tienda("DK1");




    //Cargamos la instancia actual del xml
    this->cargar_del_xml();


    //Carga pre-xml
/*
    ///INGREDIENTES

    Ingrediente* I;

    I=new Ingrediente("QMOZZ", "Mozarella", 0.5, "Queso");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("QAZUL", "Azul", 0.7, "Queso");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("QCHEDD", "Cheddar", 0.7, "Queso");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("QPARM", "Parmesano", 0.7, "Queso");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("CPEPP", "Pepperoni", 1.2, "Carne");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("CYORK", "JamonYork", 1.0, "Carne");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("VACEIT", "Aceituna", 0.5, "Vegetal");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("STOMAT", "Tomate", 0.2, "Salsa");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("SNATA", "Nata", 0.5, "Salsa");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("CBACO", "bacon", 1, "Carne");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("SBARBA", "Barbacoa", 0.5, "Salsa");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("VPIÑA", "Piña", 1, "Vegetal");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;

    I=new Ingrediente ("VCHAMP", "Champiñones", 0.7, "Vegetal");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;
    
    I=new Ingrediente ("VCEBO", "Cebolla", 0.3, "Vegetal");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;
    
    I=new Ingrediente ("CATUN", "Atun", 0.9, "Carne");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;
    
    I=new Ingrediente ("VMAIZ", "Maiz", 0.3, "Vegetal");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;
    
    I=new Ingrediente ("CJAM", "Jamon", 1.2, "Carne");
    this->set_ingrediente_vector_ingrediente(*I);
    delete I;
    
    

    ///PRODUCTOS
    Pizza* pi;


    pi = new Pizza ("PNAPO", "Napoli", "Mediana", 21, 5, true, "Carta");
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("STOMAT"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("CPEPP"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("QPARM"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("SNATA"));
    this->setProducto_vectorPolimorfico_productosSistema(*pi);
    delete pi;

    pi = new Pizza ("PMEDI", "Mediterranea", "Mediana", 21, 5, true, "Carta");
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("STOMAT"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("VACEIT"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("VCEBO"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("VCHAMP"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("CATUN"));
    this->setProducto_vectorPolimorfico_productosSistema(*pi);
    delete pi;

    pi = new Pizza ("PJAJQ", "YorkyQueso", "Pequeña", 21, 3, true, "Carta");
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("QMOZZ"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("CYORK"));
    pi->set_Ingrediente_pizza(this->get_posicionIngredienteConiID("STOMAT"));
    this->setProducto_vectorPolimorfico_productosSistema(*pi);
    delete pi;


    Refresco* r;

    r=new Refresco ("RPEP", "Pepsi", 1, "Pequeña", 21, true, true, true, true);
    this->setProducto_vectorPolimorfico_productosSistema(*r);
    delete r;


    r=new Refresco ("RFANZ", "FantaZero", 1.5, "Mediana", 21, false, false, true, true);
    this->setProducto_vectorPolimorfico_productosSistema(*r);
    delete r;


    r=new Refresco ("RAQUA", "Aquarius", 1.7, "Grande", 21, true, false, false, true);
    this->setProducto_vectorPolimorfico_productosSistema(*r);
    delete r;

    ///Clientes
    Cliente* c;
    Pedido* p;

    c=new Cliente("admin", "admin", "admin", "admin", "admin", "admin", true);
    set_cliente_vector_cliente_sistema(*c);
    delete c;

    c=new Cliente("HJ64C", "hulio99", "toby123", "Julio", "645123490", "Candil14", true);

    p=new Pedido("PED1", 20, 5, 2023, 22, 4, 0);
    p->set_producto_pedido(get_posicionProductoConiID("PNAPO"));
    p->set_producto_pedido(get_posicionProductoConiID("PMEDI"));
    p->set_producto_pedido(get_posicionProductoConiID("RPEP"));
    c->set_pedido_vector_pedidos_cliente(*p);
    delete p;

    p=new Pedido("PED2", 20, 5, 2023, 21, 20, 0);
    p->set_producto_pedido(get_posicionProductoConiID("PJAJQ"));
    p->set_producto_pedido(get_posicionProductoConiID("RFANZ"));
    p->set_producto_pedido(get_posicionProductoConiID("RAQUA"));
    c->set_pedido_vector_pedidos_cliente(*p);
    delete p;

    p=new Pedido("PED3", 20, 5, 2023, 23, 32, 0);
    p->set_producto_pedido(get_posicionProductoConiID("PNAPO"));
    p->set_producto_pedido(get_posicionProductoConiID("PMEDI"));
    p->set_producto_pedido(get_posicionProductoConiID("PJAJQ"));
    p->set_producto_pedido(get_posicionProductoConiID("RAQUA"));
    c->set_pedido_vector_pedidos_cliente(*p);
    delete p;




    set_cliente_vector_cliente_sistema(*c);
    delete c;


    c=new Cliente("SA68R", "suangus1", "22111978", "Angustias", "689774329", "Romero1", true);

    p=new Pedido("PED4", 20, 5, 2023, 21, 54, 0);
    p->set_producto_pedido(get_posicionProductoConiID("PNAPO"));
    p->set_producto_pedido(get_posicionProductoConiID("PNAPO"));
    p->set_producto_pedido(get_posicionProductoConiID("PMEDI"));
    p->set_producto_pedido(get_posicionProductoConiID("RAQUA"));
    c->set_pedido_vector_pedidos_cliente(*p);
    delete p;

    set_cliente_vector_cliente_sistema(*c);
    delete c;

    

    Valoracion* v;

    v=new Valoracion("1VAL2", 2, this->get_posicionProductoConiID("PNAPO"), this->get_posicionClienteConiID("HJ64C"));
    set_Valoracion_vector_Valoraciones_sistema(*v);
    delete v;

    
    v=new Valoracion("2VAL5", 5, this->get_posicionProductoConiID("PMEDI"), this->get_posicionClienteConiID("SA68R"));
    set_Valoracion_vector_Valoraciones_sistema(*v);
    delete v;

    
    v=new Valoracion("3VAL3", 3, this->get_posicionProductoConiID("PMEDI"), this->get_posicionClienteConiID("HJ64C"));
    set_Valoracion_vector_Valoraciones_sistema(*v);
    delete v;
*/

}

Sistema::~Sistema(){

    delete [] this->resultado_busqueda_clientes;

    delete [] this->resultado_busqueda_pedidos;

    delete [] this->resultado_busqueda_productos;

    for (int i=0; i<get_total_productos_sistema(); i++){

        if(Refresco *r = dynamic_cast<Refresco*>(this->productos_sistema[i])){
            delete r;
        }
        else{//este else raro es por que me daba violacion de core, supongo que alomejor entrararia a ambos pues con esta condicion lo arreglo
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                delete pi;
            }        
        } 

    }
    for (int j=0; j<get_total_clientes_sistema(); j++){
        delete this->clientes_sistema[j];
    }


    delete [] this->valoraciones_sistema;

    delete [] this->ingredientes_sistema;

    delete [] this->clientes_sistema;
    delete [] this->productos_sistema;




}


/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/

string Sistema::get_id_tienda(){
    return this->id_tienda;
}

int Sistema::get_total_ingredientes_sistema(){
    return this->total_ingredientes_sistema;
}


int Sistema::get_total_productos_sistema(){
    return this->total_productos_sistema;
}




Ingrediente Sistema::get_ingrediente_sistema(int posicion){
    return this->ingredientes_sistema[posicion];
}

Ingrediente* Sistema::get_posicion_ingrediente(int posicion){
    return &(this->ingredientes_sistema[posicion]);
}


int Sistema::get_total_clientes_sistema(){
    return this->total_clientes_sistema;
}

int Sistema::get_total_valoraciones_sistema(){
    return this->total_valoraciones_sistema;
}
Cliente* Sistema::get_cliente_activo(){
    return this->cliente_activo;
}




Pedido* Sistema::get_resultado_busqueda_pedidos(int posicion){
    return this->resultado_busqueda_pedidos[posicion];
}


int Sistema::get_total_pedidos_encontrados(){
    return this->total_pedidos_encontrados;
}


Cliente* Sistema::get_resultado_busqueda_clientes(int posicion){
    return this->resultado_busqueda_clientes[posicion];
}


int Sistema::get_total_clientes_encontrados(){
    return this->total_clientes_encontrados;
}

Producto* Sistema::get_resultado_busqueda_productos(int posicion){
    return this->resultado_busqueda_productos[posicion];
}


int Sistema::get_total_productos_encontrados(){
    return this->total_productos_encontrados;
}




/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/


void Sistema::set_id_tienda(string id){
    this->id_tienda=id;
}

void Sistema::set_total_ingredientes_sistema(int i){
    this->total_ingredientes_sistema=i;
}


void Sistema::set_total_productos_sistema(int i){
    this->total_productos_sistema=i;
}

void Sistema::set_ingrediente_vector_ingrediente(const Ingrediente &ig){

    resize_vector_ingrediente(this->get_total_ingredientes_sistema()+2);//get_total_ingredientes_sistema() <---->  util anteriores, recordamos que estamos dejando una libre asi tras la proxima introduccion del ingrediente --> +2

    this->ingredientes_sistema[this->get_total_ingredientes_sistema()]=ig;

    this->set_total_ingredientes_sistema(this->get_total_ingredientes_sistema()+1);

}

void Sistema::setProducto_vectorPolimorfico_productosSistema(Refresco r){

    Producto* p=new Refresco (r);

    this->resize_vector_polimorfico((this->get_total_productos_sistema())+2);


    this->productos_sistema[this->get_total_productos_sistema()]=p;

    this->set_total_productos_sistema(1 + (this->get_total_productos_sistema()));

}

void Sistema::setProducto_vectorPolimorfico_productosSistema(Pizza pi){

    Producto* p=new Pizza (pi);

    this->resize_vector_polimorfico((this->get_total_productos_sistema())+2);


    this->productos_sistema[this->get_total_productos_sistema()]=p;

    this->set_total_productos_sistema(this->get_total_productos_sistema()+1);
    
}
void Sistema::set_total_clientes_sistema(int aux){
    this->total_clientes_sistema=aux;
}


void Sistema::set_cliente_vector_cliente_sistema(const Cliente &c){
    Cliente* client = new Cliente;
    *client=c;

    resize_vector_clientes(this->get_total_clientes_sistema()+2);

    this->clientes_sistema[this->get_total_clientes_sistema()]=client;

    this->set_total_clientes_sistema(this->get_total_clientes_sistema()+1);
}


void Sistema::set_total_valoraciones_sistema(int aux){
    this->total_valoraciones_sistema=aux;
}

void Sistema::set_Valoracion_vector_Valoraciones_sistema(const Valoracion &v){
    this->resize_vector_valoraciones(this->get_total_valoraciones_sistema()+2);

    this->valoraciones_sistema[this->get_total_valoraciones_sistema()]=v;

    this->set_total_valoraciones_sistema(this->get_total_valoraciones_sistema()+1);
}

void Sistema::set_cliente_activo(Cliente* c){
    this->cliente_activo=c;
}





void Sistema::set_resultado_busqueda_pedidos(Pedido* p){

    resize_vector_resultado_busqueda_pedidos(this->get_total_pedidos_encontrados()+2);

    this->resultado_busqueda_pedidos[this->get_total_pedidos_encontrados()]=p;

    this->set_total_pedidos_encontrados(this->get_total_pedidos_encontrados()+1);

}




void Sistema::set_total_pedidos_encontrados(int total){
    this->total_pedidos_encontrados=total;
}




void Sistema::set_resultado_busqueda_clientes(Cliente* c){

    resize_vector_resultado_busqueda_clientes(this->get_total_clientes_encontrados()+2);

    this->resultado_busqueda_clientes[this->get_total_clientes_encontrados()]=c;

    this->set_total_clientes_encontrados(this->get_total_clientes_encontrados()+1);
}



void Sistema::set_total_clientes_encontrados(int total){
    this->total_clientes_encontrados=total;
}



void Sistema::set_resultado_busqueda_productos(Producto* p){

    resize_vector_resultado_busqueda_productos(this->get_total_productos_encontrados()+2);

    this->resultado_busqueda_productos[this->get_total_productos_encontrados()]=p;

    this->set_total_productos_encontrados(this->get_total_productos_encontrados()+1);
}



void Sistema::set_total_productos_encontrados(int total){
    this->total_productos_encontrados=total;
}



/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/

void Sistema::modificar_producto(){

    int aux=0;
    int aux2=0;
    int aux3=0;
    bool existente=false;

    this->imprimir_productos_del_sistema();
    
    for (int i=0; i<this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            aux2++;
        }
    }
    aux2--;

    if (aux2>=0){
        do{
            cout << "Que producto quiere modificar: ";
            cin >> aux;
            aux--;
        }while(aux<0 || aux > aux2); // aux2 -> Ultimo producto activo


        aux2=0;

        //Ubicar la posicion verdaddera del producto (ahora hay que tener en cuenta los desactivados)
        for (int i=0; i<this->get_total_productos_sistema(); i++){

            if (aux2==aux){
                aux3=i;
            }

            if (this->productos_sistema[i]->get_activo()){
                aux2++;
            }

        }

        /////////    Creamos una copia para que nuestor modificar sea un eliminar-crear 
        /////////    (desactivremos el producto manteniendo asi el hsitoria pues un cliente pidio esa pizza antigua no la nueva "editada", deberemos de diferenciar)
        /////////    Editaremos la copia de la antigua, desactivaremos la antigua y insertaremos la editada
        ///////////////////////////
        if(Refresco *re = dynamic_cast<Refresco*>(this->productos_sistema[aux3])){
            Refresco Rprod (*re);
            this->edit(&Rprod);
            this->productos_sistema[aux3]->set_activo(false); //Desactivamos antiguo producto

            for (int i=0; i<this->get_total_productos_sistema(); i++){

                if(Refresco *re = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                    if (Rprod==*re){
                        existente=true;
                    }
                }

            }
            if (existente){
                cout << "Ya existe un producto similar, se cancela la edicion"<<endl;
            }
            else{
                this->productos_sistema[aux3]->set_activo(false); //Desactivamos antiguo producto
                this->setProducto_vectorPolimorfico_productosSistema(Rprod);
                
            }

        }
        else{
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[aux3])){
                Pizza Pprod;
                Pprod = *pi;
                this->edit(&Pprod);



            for (int i=0; i<this->get_total_productos_sistema(); i++){

                if(Pizza *re = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                    if (Pprod==*re){
                        existente=true;
                    }
                }

            }
            if (existente){
                cout << "Ya existe un producto similar, se cancela la edicion"<<endl;
            }
            else{
                this->productos_sistema[aux3]->set_activo(false); //Desactivamos antiguo producto
                this->setProducto_vectorPolimorfico_productosSistema(Pprod);
            }

            }
        }

    }
    else{
        cout << "No hay productos que modificar"<<endl;
    }
}


void Sistema::CrearCliente(){
    if (DEBUG_Sistema){
        cout << "CREANDO Cliente"<<endl<<DEFAULT;
    }
        bool usado=false;
        cout << "---Creando cuenta en el sistema---"<<endl;
        Cliente* c=new Cliente;

        do {
            usado=false;

            c->introducir();

            //filtro para que no coincidan logins
            for (int i=0; i<this->get_total_clientes_sistema() && usado==false; i++){
                if (this->clientes_sistema[i]->get_login_cliente()==c->get_login_cliente()){
                    usado=true;
                    cout << BOLDRED <<"---Ya existe este usuario en el sistema---"<<endl<<DEFAULT;
                }
            }

        }while (usado==true);
        


        this->set_cliente_vector_cliente_sistema(*c);

        delete c;
    if (DEBUG_Sistema){
        cout << "CREADO Cliente"<<endl<<DEFAULT;
    }
}




void Sistema::nuevoIngrediente(){
    Ingrediente ig;

    cin>>ig;

    this->set_ingrediente_vector_ingrediente(ig);

    if (DEBUG_Sistema){
        cout << "Añadido nuevo ingrediente en el vector de ingredientes del sistema"<<endl<<DEFAULT;
    }

}

void Sistema::nuevoProducto(){

    bool pr;//1 -> pizza, 0->bebida
    bool existente=false;

    cout << "Elija que crear     ";
    cout << "Bebida (0) o Pizza (1): ";
    cin>>pr;


    if (pr==false){
        Refresco r;
        r.introducir();

        for (int i=0; i<this->get_total_productos_sistema(); i++){

            if(Refresco *re = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                if (r==*re){
                    existente=true;
                }
            }

        }
        if (existente){
            cout << "Ya existe el producto"<<endl;
        }
        else{
            this->setProducto_vectorPolimorfico_productosSistema(r);
        }

    }
    else{
        int aux=0;
        Pizza p;
        p.introducir();
        p.set_tipo_pizza("Carta");
        do{
            this->imprimir_ingredientes_del_sistema();
            cout << endl << "Introduce el ingrediente a añadir (numero negativo o 0 para dejar de añadir): ";
            cin >> aux;
            aux--;
            if (aux>=0 && aux<this->get_total_ingredientes_sistema()){
                p.set_Ingrediente_pizza(&this->ingredientes_sistema[aux]);
            }
            
        }while(aux>=0);


            
        for (int i=0; i<this->get_total_productos_sistema(); i++){

            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                if (p==*pi){
                    existente=true;
                }
            }

        }


        if (existente){
            cout << "Ya existe el producto"<<endl;
        }
        else{
            this->setProducto_vectorPolimorfico_productosSistema(p);
        }
            
        

        
        
    }

    if (DEBUG_Sistema){
        cout << "Añadido (o no) nuevo producto en el vector de productos del sistema"<<endl<<DEFAULT;
    }

}


void Sistema::imprimir_productos_del_sistema(){
    int k=1;
    cout << BOLDMAGENTA;
    for (int i=0; i<this->get_total_productos_sistema();i++){
        if (this->productos_sistema[i]->get_activo()){
            cout << "Producto "<<k<<": "<<endl;
            (this->productos_sistema[i])->print();
            cout << endl;
            k++;
        }
        
    }
    cout << DEFAULT;

}
void Sistema::imprimir_ingredientes_del_sistema(){
    cout << BOLDMAGENTA;
    for (int i=0; i<this->get_total_ingredientes_sistema();i++){
        cout << "Ingrediente "<<i+1<<": "<<endl;
        cout << (this->get_ingrediente_sistema(i));
        cout << endl;
    }
    cout << DEFAULT;

}

void Sistema::imprimir_clientes_del_sistema(){
    cout << BOLDBLUE;
    int j=1;
    for (int i=1; i<this->get_total_clientes_sistema(); i++){

        if(this->clientes_sistema[i]->get_activo()) {
            cout << "Cliente "<<j<<": "<<endl;
            (this->clientes_sistema[i])->print();
            cout << endl;
            j++;
        }

    }
    cout << DEFAULT;
}


void Sistema::imprimir_valoraciones_del_sistema(){
    cout << BOLDCYAN;
    for (int i=0; i<this->get_total_valoraciones_sistema();i++){
        cout << "Valoracion "<<i+1<<": "<<endl;
        (this->valoraciones_sistema[i]).print();
        cout << endl;
    }
    cout << DEFAULT;
}

void Sistema::imprimir_gloval(){

    cout <<endl<< "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
    cout << "==================================== Metricas del sistema ===================================="<<endl;
    cout << "Total Clientes"<<'\t'<<'\t'<< "Total Productos"<<'\t'<<'\t'<< "Total Ingredientes"<<'\t'<<'\t'<< "Total Valoraciones"<<endl;
    cout << this->get_total_clientes_sistema()<<'\t'<<'\t'<<'\t'<< this->get_total_productos_sistema()<<'\t'<<'\t'<<'\t'<< this->get_total_ingredientes_sistema()<<'\t'<<'\t'<<'\t'<<'\t'<< this->get_total_valoraciones_sistema()<<endl;
    
    

    cout <<endl<< "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl<<endl;

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "____________________________________ Ingredientes Sistema ____________________________________"<<endl;

    this->imprimir_ingredientes_del_sistema();

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

    cout << endl<<endl;

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "____________________________________ Productos Sistema ____________________________________"<<endl;

    this->imprimir_productos_del_sistema();

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

    cout << endl<<endl;

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "____________________________________ Clientes Sistema ____________________________________"<<endl;

    this->imprimir_clientes_del_sistema();

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

    cout << endl<<endl;

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "____________________________________ Valoraciones Sistema ____________________________________"<<endl;

    this->imprimir_valoraciones_del_sistema();

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

    cout << endl<<endl;

}



void Sistema::ranking_commun(){
    
    float valor_pos_1=0.0;
    float valor_pos_2=0.0;
    float valor_pos_3=0.0;

    float aux=0.0;
    float aux2=0.0;


    float ped_sistema=0;
    
    for (int j=0; j<this->get_total_clientes_sistema(); j++){
        ped_sistema+=(this->clientes_sistema[j]->get_total_pedidos_cliente());
    } 

    cout << "||||||||||||"<<"   Ranking 1 Gloval   "<<"||||||||||||"<<"   /Formula General"<<endl;

    //val =  (val_med_prod) + [ (num_pedidos / (____total_ped_sistema____)))*5]

    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){

            aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));
            if (aux>=valor_pos_3){
                valor_pos_3=aux;

                if (aux>=valor_pos_2){
                    aux2=valor_pos_2;


                    valor_pos_2=aux;


                    valor_pos_3=aux2;

                    if (aux>=valor_pos_1){
                        aux2=valor_pos_1;

                        valor_pos_1=aux;

                        valor_pos_2=aux2;
                        
                    }
                    
                }
            }
        }
    }

    //Imprimimos R1.1 (Raning 1 parte 1)

    
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

            

            if (aux==valor_pos_1){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Primero en la calificacion de gloval"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_1<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

            if (aux==valor_pos_2){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Segundo en la calificacion de gloval"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_2<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
        
            aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

            if (aux==valor_pos_3){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Tercero en la calificacion de gloval"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_3<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    valor_pos_1=0.0;
    valor_pos_2=0.0;
    valor_pos_3=0.0;



    cout << "||||||||||||"<<"   Ranking 2 Gloval   "<<"||||||||||||"<<"   /Mas Pedidos"<<endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());
        if (aux>=valor_pos_3){
            valor_pos_3=aux;

            if (aux>=valor_pos_2){
                aux2=valor_pos_2;

                valor_pos_2=aux;

                valor_pos_3=aux2;

                if (aux>=valor_pos_1){
                    aux2=valor_pos_1;

                    valor_pos_1=aux;

                    valor_pos_2=aux2;
                    
                }
                
            }
        }
    }
    //Imprimimos R1.2 (Raning 1 parte 2)
    
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

            if (aux==valor_pos_1){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Primero en la calificacion de mas pedidos"<<endl<<"Su numero de pedidos es: "<<valor_pos_1<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){

            
            aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

            if (aux==valor_pos_2){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Segundo en la calificacion de mas pedidos"<<endl<<"Su numero de pedidos es: "<<valor_pos_2<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

            if (aux==valor_pos_3){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Tercer en la calificacion de mas pedidos"<<endl<<"Su numero de pedidos es: "<<valor_pos_2<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    valor_pos_1=1000000.0;
    valor_pos_2=1000000.0;
    valor_pos_3=1000000.0;


    cout << "||||||||||||"<<"   Ranking 3 Gloval   "<<"||||||||||||"<<"   /Menos Pedidos"<<endl;

    for (int i=0; i < this->get_total_productos_sistema(); i++){

        if (this->productos_sistema[i]->get_activo()){


            aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());
            if (aux<=valor_pos_3){

                valor_pos_3=aux;

                if (aux<=valor_pos_2){
                    aux2=valor_pos_2;


                    valor_pos_2=aux;


                    valor_pos_3=aux2;

                    if (aux<=valor_pos_1){
                        aux2=valor_pos_1;


                        valor_pos_1=aux;

                        valor_pos_2=aux2;
                        
                    }
                    
                }
            }
        }
    }

    //Imprimimos R1.3 (Raning 1 parte 3)
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

            if (aux==valor_pos_1){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Primero en la calificacion de menos pedidos"<<endl<<"Su numero de pedidos son: "<<valor_pos_1<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

            if (aux==valor_pos_2){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Segundo en la calificacion de menos pedidos"<<endl<<"Su numero de pedidos son: "<<valor_pos_2<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

            if (aux==valor_pos_3){
                cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                cout << "     Tercero en la calificacion de menos pedidos"<<endl<<"Su numero de pedidos son: "<<valor_pos_3<<DEFAULT<<endl;

                this->productos_sistema[i]->print();
            }
        }
        
    }
    cout << endl;
}



void Sistema::ranking_separado(){
    float valor_pos_1=0.0;
    float valor_pos_2=0.0;
    float valor_pos_3=0.0;



    float aux=0.0;
    float aux2=0.0;


    float ped_sistema=0;
    
    for (int j=0; j<this->get_total_clientes_sistema(); j++){
        ped_sistema+=(this->clientes_sistema[j]->get_total_pedidos_cliente());
    } 

    cout << "||||||||||||"<<"   Ranking 1 Separado Refrescos   "<<"||||||||||||"<<"   /Formula General"<<endl;

    //val =  (val_med_prod) + [ (num_pedidos / (____total_ped_sistema____)))*5]

    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));
                if (aux>=valor_pos_3){
                    valor_pos_3=aux;

                    if (aux>=valor_pos_2){
                        aux2=valor_pos_2;

                        valor_pos_2=aux;

                        valor_pos_3=aux2;

                        if (aux>=valor_pos_1){
                            aux2=valor_pos_1;

                            valor_pos_1=aux;

                            valor_pos_2=aux2;
                            
                        }
                        
                    }
                }
            }
        }
        

    }

    //Imprimimos R2.1 (Raning 2 parte 1)
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

                

                if (aux==valor_pos_1){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Primero en la calificacion de general"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_1<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){

                
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

                if (aux==valor_pos_2){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Segundo en la calificacion de general"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_2<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){

            
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

                if (aux==valor_pos_3){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Tercero en la calificacion de general"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_3<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    valor_pos_1=0.0;
    valor_pos_2=0.0;
    valor_pos_3=0.0;





    aux=0.0;
    aux2=0.0;


    ped_sistema=0;
    
    for (int j=0; j<this->get_total_clientes_sistema(); j++){
        ped_sistema+=(this->clientes_sistema[j]->get_total_pedidos_cliente());
    }

    cout << "||||||||||||"<<"   Ranking 1 Separado Pizzas   "<<"||||||||||||"<<"   /Formula General"<<endl;

    //val =  (val_med_prod) + [ (num_pedidos / (____total_ped_sistema____)))*5]

    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
        
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));
                if (aux>=valor_pos_3){
                    valor_pos_3=aux;

                    if (aux>=valor_pos_2){
                        aux2=valor_pos_2;

                        valor_pos_2=aux;

                        valor_pos_3=aux2;

                        if (aux>=valor_pos_1){
                            aux2=valor_pos_1;

                            valor_pos_1=aux;

                            valor_pos_2=aux2;
                            
                        }
                        
                    }
                }
            }
        }
        

    }

    //Imprimimos R2.1 (Raning 2 parte 1)
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

                

                if (aux==valor_pos_1){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Primero en la calificacion de general"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_1<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){

                
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

                if (aux==valor_pos_2){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Segundo en la calificacion de general"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_2<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){

                
                aux=(this->productos_sistema[i]->get_valoracion_media() + ((this->productos_sistema[i]->get_num_veces_incluido_en_pedidos() / ped_sistema)*5));

                if (aux==valor_pos_3){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Tercero en la calificacion de general"<<endl<<"Su puntuacion con respecto a la formula es: "<<valor_pos_3<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    valor_pos_1=0.0;
    valor_pos_2=0.0;
    valor_pos_3=0.0;


    cout << "||||||||||||"<<"   Ranking 2 Separado Refrescos   "<<"||||||||||||"<<"   /Mas Pedidos"<<endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){

            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());
                if (aux>=valor_pos_3){
                    valor_pos_3=aux;

                    if (aux>=valor_pos_2){
                        aux2=valor_pos_2;

                        valor_pos_2=aux;

                        valor_pos_3=aux2;

                        if (aux>=valor_pos_1){
                            aux2=valor_pos_1;

                            valor_pos_1=aux;

                            valor_pos_2=aux2;
                            
                        }
                        
                    }
                }
            }
        }
    }
    //Imprimimos R2.2 (Raning 2 parte 2)
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                

                if (aux==valor_pos_1){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Primero en la calificacion de mas pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_1<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){

                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_2){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Segundo en la calificacion de mas pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_2<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_3){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Tercero en la calificacion de mas pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_3<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    valor_pos_1=0.0;
    valor_pos_2=0.0;
    valor_pos_3=0.0;


    cout << "||||||||||||"<<"   Ranking 2 Separado Pizzas   "<<"||||||||||||"<<"   /Mas Pedidos"<<endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){

            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());
                if (aux>=valor_pos_3){
                    valor_pos_3=aux;

                    if (aux>=valor_pos_2){
                        aux2=valor_pos_2;

                        valor_pos_2=aux;

                        valor_pos_3=aux2;

                        if (aux>=valor_pos_1){
                            aux2=valor_pos_1;

                            valor_pos_1=aux;

                            valor_pos_2=aux2;
                            
                        }
                        
                    }
                }
            }
        }
    }
    //Imprimimos R2.2 (Raning 2 parte 2)
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                

                if (aux==valor_pos_1){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Primero en la calificacion de mas pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_1<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){

                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_2){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Segundo en la calificacion de mas pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_2<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_3){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Tercero en la calificacion de mas pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_3<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    valor_pos_1=1000000.0;
    valor_pos_2=1000000.0;
    valor_pos_3=1000000.0;



    cout << "||||||||||||"<<"   Ranking 3 Separado Refrescos   "<<"||||||||||||"<<"   /Menos Pedidos"<<endl;

    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){

            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){

                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());
                if (aux<=valor_pos_3){
                    valor_pos_3=aux;

                    if (aux<=valor_pos_2){
                        aux2=valor_pos_2;

                        valor_pos_2=aux;

                        valor_pos_3=aux2;

                        if (aux<=valor_pos_1){
                            aux2=valor_pos_1;

                            valor_pos_1=aux;

                            valor_pos_2=aux2;
                            
                        }
                        
                    }
                }
            }
        }
    }
    //Imprimimos R2.3 (Raning 2 parte 3)
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                

                if (aux==valor_pos_1){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Primero en la calificacion de menos pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_1<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_2){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Segundo en la calificacion de menos pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_2<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Refresco *pi = dynamic_cast<Refresco*>(this->productos_sistema[i])){

                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_3){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Tercero en la calificacion de menos pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_3<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    valor_pos_1=1000000.0;
    valor_pos_2=1000000.0;
    valor_pos_3=1000000.0;



    cout << "||||||||||||"<<"   Ranking 3 Separado Pizzas   "<<"||||||||||||"<<"   /Menos Pedidos"<<endl;

    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){

            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){

                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());
                if (aux<=valor_pos_3){
                    valor_pos_3=aux;

                    if (aux<=valor_pos_2){
                        aux2=valor_pos_2;

                        valor_pos_2=aux;

                        valor_pos_3=aux2;

                        if (aux<=valor_pos_1){
                            aux2=valor_pos_1;

                            valor_pos_1=aux;

                            valor_pos_2=aux2;
                            
                        }
                        
                    }
                }
            }
        }
    }
    //Imprimimos R2.3 (Raning 2 parte 3)
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                

                if (aux==valor_pos_1){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Primero en la calificacion de menos pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_1<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_2){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Segundo en la calificacion de menos pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_2<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    cout << endl;
    for (int i=0; i < this->get_total_productos_sistema(); i++){
        if (this->productos_sistema[i]->get_activo()){
            if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
            
                aux=(this->productos_sistema[i]->get_num_veces_incluido_en_pedidos());

                if (aux==valor_pos_3){
                    cout<<BOLDGREEN << "     ////////////////////////////////////"<<endl;
                    cout << "     Tercero en la calificacion de menos pedidos"<<endl<<"Su total de pedidos es: "<<valor_pos_3<<DEFAULT<<endl;

                    this->productos_sistema[i]->print();
                }
            }
        }
        
    }
    
}

void Sistema::ranking_clientes(){

    float mayor=0.0;
    float aux=0.0;
    
    cout << "[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]"<<endl;
    cout << "Cliente con mayor numero de pedidos: "<<endl;

    for (int i=0; i<this->get_total_clientes_sistema(); i++){

        if (this->clientes_sistema[i]->get_activo()){
            aux=this->clientes_sistema[i]->get_total_pedidos_cliente();
            
            if (aux>=mayor){
                mayor=aux;
            }
        }
    

    }

    //Imprimir
    for (int i=0; i<this->get_total_clientes_sistema(); i++){

        if (this->clientes_sistema[i]->get_activo()){
            aux=this->clientes_sistema[i]->get_total_pedidos_cliente();
            
            if (aux==mayor){
                this->clientes_sistema[i]->print_solo_cliente();
            }
        }

    }

    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    cout << "[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]"<<endl;
    cout << "Cliente con mayor valoracion media: "<<endl;
    mayor=0.0;
    aux=0.0;

    for (int i=0; i<this->get_total_clientes_sistema(); i++){
        aux=this->clientes_sistema[i]->get_valoracion_media_productos();
        if (aux>=mayor){
            mayor=aux;
        }
    }

    //Imprimir
    for (int i=0; i<this->get_total_clientes_sistema(); i++){

        if (this->clientes_sistema[i]->get_activo()){
            aux=this->clientes_sistema[i]->get_valoracion_media_productos();
            
            if (aux==mayor){
                this->clientes_sistema[i]->print_solo_cliente();
            }
        }

    }

    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////

 
    cout << "[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]"<<endl;
    cout << "Cliente que mas ha pedido la pizza peor valorada: "<<endl;
    float menor=0.0;
    aux=0.0;
    int aux_i=0;
    int aux_mas_pedido=0;
    int i=0;


    //Producto (pedido) con menor valoracion media
    for (i=0; i<this->get_total_clientes_sistema(); i++){                                                                            //Pasamos por todos los clientes


        if (clientes_sistema[i]->get_activo()){                                                                                     //Que esten activos

        
            for (int j=0; j<clientes_sistema[i]->get_total_pedidos_cliente(); j++){                                                 //pasamos por todos sus pedidos

                for (int k=0; k<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_productos_pedido(); k++){                       //Pasamos por todos los productos

                    if(Pizza *pi = dynamic_cast<Pizza*>(this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k))){         //Por las pizzas

                        if (this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k)->get_activo()){                        //Que esten activas
                            aux=this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k)->get_valoracion_media();              //guardamos su valoracion media
                            if (aux<menor){                                                                                                             //Nos quedamos con la peor valoracion media que halla sido pedida
                                    menor=aux;                                                                                                          //la guardamos en la variable 
                            }
                        }

                    }

                }

            }

        }

    }



    //Buscar cliente/clientes que cuenten con el peor producto valorado (producto pedido con menor vloarcion media)
    for (i=0; i<this->get_total_clientes_sistema(); i++){
        aux_i=0;                                                                                                                                          //Iteracion similar a la anterior pero contamos cuantas veces se ha pedido el producto encontrado antes

        if (clientes_sistema[i]->get_activo()){

        
            for (int j=0; j<clientes_sistema[i]->get_total_pedidos_cliente(); j++){
                for (int k=0; k<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_productos_pedido(); k++){
                    if(Pizza *pi = dynamic_cast<Pizza*>(this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k))){
                        if (this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k)->get_activo()){
                            aux=this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k)->get_valoracion_media();
                            if (aux==menor){                                                                                                              //Contamos cuantas veces ha pedido cada cliente la pizza peor valorada
                                    aux_i++;                                                                                                               //Vamos guardandolo en la variable                                
                            }
                        }
                    }
                }
            }
        }
        if (aux_i > aux_mas_pedido){                                                                                                                       //nos quedamos con el mayor numero de veces pedido por un cliente para la peor pizza
            aux_mas_pedido=aux_i;                                                                                                                           //Lo guardamos en la variable
        }
    }


    //Imprimir cliente/clientes que cuenten con el peor producto valorado (producto pedido con menor vloarcion media)
    for (i=0; i<this->get_total_clientes_sistema(); i++){
        aux_i=0;

        if (clientes_sistema[i]->get_activo()){
            for (int j=0; j<clientes_sistema[i]->get_total_pedidos_cliente(); j++){
                for (int k=0; k<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_productos_pedido(); k++){
                    if(Pizza *pi = dynamic_cast<Pizza*>(this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k))){
                        if (this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k)->get_activo()){
                            aux=this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k)->get_valoracion_media();
                            if (aux==menor){
                                    aux_i++;
                            }
                        }
                    }
                }
            }

            if (aux_i == aux_mas_pedido){
                

                clientes_sistema[i]->print_solo_cliente();                                                                                          //Mismo recorrido pero imprimiendo por fin el/los clientes que hallan pedido mas veces la peor/perores pizzas
            }
        }
    }
}


void Sistema::login(){
    
    bool aux_b=0;
    string aux_s_l="";
    string aux_s_p="";
    bool valido=0;
    bool valido2=0;

    do {
    
    cout <<BOLDCYAN<< "Bienvenido al sistema Dominus King"<<endl;
    cout << "Introduce 1 para loguearte o 0 para cerrar el sistema: "<<endl;
    cout << "   #"<<BOLDGREEN;
    cin >> aux_b;
    if (aux_b==true){
        
        cout << "Usuario existente (1)     ";
        cout << "      Usuario nuevo (0)"<<endl<<"   #";
        cin >>valido2;
        if (valido2){




        

            do {
                valido=0;
                cout << BOLDCYAN<<"   Introduce tu login: "<<endl;
                cout << "      #";
                cin>>aux_s_l;

                cout << BOLDCYAN<<"   Introduce tu pass: "<<endl;
                cout << "      #";
                cin>>aux_s_p;
                
                for (int i=0; i<this->get_total_clientes_sistema() && valido==false; i++){
                    if (this->clientes_sistema[i]->get_activo()){

                        if (aux_s_l==(this->clientes_sistema[i]->get_login_cliente())){
                                if (aux_s_p==(this->clientes_sistema[i]->get_pass_cliente())){
                                    this->set_cliente_activo(clientes_sistema[i]);
                                    valido=true;
                                }
                                
                            }
                        }
                    
                }
                if (valido==false){
                    cout <<BOLDRED<< "Pass o Loggin no validos"<<DEFAULT<<endl;
                }
            }while (valido==false);


            if (this->get_cliente_activo()->get_login_cliente()=="admin"){

                this->menu_admin();

            }
            else{

                this->menu_cliente();

            }

        }
        else{ //usuario nuevo
            this->CrearCliente();
        }
    }
    
    }while (aux_b!=0);

    
}
void Sistema::menu_admin(){
    int decision=1;
    int modo=0;

    while (decision!=0){
        cout <<BOLDGREEN<< "Bienvenido ADMIN"<<endl;
        cout << "Seleccione la accion que quiere realizar:"<<endl;


        cout << " # 0 -> Cerrar Sesion"<<endl;
        cout << " # 1 -> Imprimir datos generales sistema "<<endl;
        cout << " # 2 -> Ranking Top3 General Productos "<<endl;
        cout << " # 3 -> Ranking Top3 por Tipo de Pizza o Refresco "<<endl;
        cout << " # 4 -> Ranking Clientes "<<endl;
        cout << " # 5 -> Agregar producto al catalogo del sistema "<<endl;
        cout << " # 6 -> Eliminar producto del catalogo del sistema "<<endl;
        cout << " # 7 -> Buscar producto en el catalogo del sistema  "<<endl;
        cout << " # 8 -> Modificar datos de producto "<<endl;
        cout << " # 9 -> Consultar Valoración de Producto en el Catálogo del Sistema"<<endl;
        cout << " # 10 -> Agregar cliente al sistema"<<endl;
        cout << " # 11 -> Eliminar cliente del sistema"<<endl;
        cout << " # 12 -> Buscar Cliente del sistema"<<endl;
        cout << " # 13 -> Modificar datos del cliente"<<endl;
        cout << " # 14 -> Buscar y Consultar Pedidos "<<endl;
        cout << " # 15 -> Eliminar pedido "<<endl;
        cout << " # 16 -> Guardar ingredientes en la Base Datos "<<endl;
        cout << " # 17 -> Guardar ingredientes en la Base Datos "<<endl;
        cout << " # 18 -> Guardar Sistema en xml "<<endl;

        



        cout << "   # ";
        cin>>decision;
        cout << DEFAULT<<endl;

        if(decision==0){
    
        }
        else if(decision==1){
            this->imprimir_gloval();
        }
        else if(decision==2){
            this->ranking_commun();
        }
        else if(decision==3){
            this->ranking_separado();
        }
        else if(decision==4){
            this->ranking_clientes();
        }
        else if(decision==5){
            this->nuevoProducto();
        }
        else if(decision==6){
            this->EliminarProducto();
        }
        else if(decision==7){
            modo=0;

            do{

                cout << "Seleccione la manera en la que desea buscar producto: "<<endl<<endl;
                cout << "   #1 Nombre"<<endl;
                cout << "   #2 Uno de sus ingredientes"<<endl;

                cout << endl<<"   #";
                cin >> modo;
            
            }while(modo<1 || modo>2);

            this->buscar_producto(modo);

            if (this->get_total_productos_encontrados()!=0){

                //Imprimimos los resultados
                int k=1;
                for (int i=0; i<this->get_total_productos_encontrados(); i++){
                    cout << "producto Encontrado "<<k<<": "<<endl;
                    this->get_resultado_busqueda_productos(i)->print();
                    k++;
                
                }
            }
            else {
                cout << "No se ha encontrado ningun producto"<<endl;
            }
        }
        else if(decision==8){
            this->modificar_producto();
        }
        else if(decision==9){
            this->consultar_valoracion_Producto();
        }
        else if(decision==10){
            this->CrearCliente();
        }
        else if(decision==11){

            this->EliminarCliente();

        }
        else if(decision==12){ 

            modo=0;

            do{

                cout << "Seleccione la manera en la que desea buscar clientes: "<<endl<<endl;
                cout << "   #1 Login"<<endl;
                cout << "   #2 Nombre"<<endl;

                cout << endl<<"   #";
                cin >> modo;
            
            }while(modo<1 || modo>2);

            this->buscar_cliente(modo);

            if (this->get_total_clientes_encontrados()!=0){

                //Imprimimos los resultados
                int k=1;
                for (int i=0; i<this->get_total_clientes_encontrados(); i++){
                    cout << "Cliente Encontrado "<<k<<": "<<endl;
                    this->get_resultado_busqueda_clientes(i)->print_solo_cliente();
                    k++;
                
                }
            }
            else {
                cout << "No se ha encontrado ningun cliente"<<endl;
            }

        }
        else if(decision==13){
            

    int aux=0;
    int aux2=0;
    int aux3=0;

    for (int i=1; i<this->get_total_clientes_sistema(); i++){

        if (this->clientes_sistema[i]->get_activo()){
            cout << "Cliente " <<aux2+1<<": "<<endl;
            this->clientes_sistema[i]->print_solo_cliente();
            aux2++;
        }

    }
    aux2--;

    if (aux2>=0){
        do{
            cout << "Que cliente quiere modificar: ";
            cin >> aux;
            aux--;
        }while(aux<0 || aux > aux2); // aux2 -> Ultimo producto activo


        aux2=0;

        //Ubicar la posicion verdaddera del cliente (ahora hay que tener en cuenta los desactivados)
        for (int i=1; i<this->get_total_clientes_sistema(); i++){

            if (aux2==aux){
                aux3=i;
            }

            if (this->clientes_sistema[i]->get_activo()){
                aux2++;
            }

        }

        this->modificar_datos_cliente(this->clientes_sistema[aux3]);
    
    }
    else{
        cout << "No quedan clientes que modificar"<<endl;
    }

        }

        else if(decision==14){
            modo=0;
            int revisar=0;
            bool fin=false;

            do{

                cout << "Seleccione la manera en la que desea buscar pedidos: "<<endl<<endl;
                cout << "   #1 Rango de precio con iva"<<endl;

                cout << endl<<"   #";
                cin >> modo;
            
            }while(modo<1 || modo>1);

            this->buscar_pedidos(modo);

            cout << endl<<endl;

            if (this->get_total_pedidos_encontrados()!=0){

                //Imprimimos los resultados
                
                for (int i=0; i<this->get_total_pedidos_encontrados(); i++){
                    cout << "Pedido Encontrado "<<i+1<<": "<<endl;
                    this->get_resultado_busqueda_pedidos(i)->print_basic();
                }

                //Acceder a detalles
                while(fin==false){
                    
                    do{
                        cout << "Que pedido quiere revisar mas a fondo, seleccione 0 para dejar de revisar: "<<endl;
                        cout << "#";
                        cin>>revisar;
                    }while (revisar<0 || revisar>this->get_total_pedidos_encontrados());

                    if (revisar==0){
                        fin=true;
                    }
                    else{
                        this->resultado_busqueda_pedidos[revisar-1]->print();
                    }
                    
                    
                    
                }

            }
            else {
                cout << "No se ha encontrado ningun pedido"<<endl;
            }

        }



        else if(decision==15){

            int aux=0;
            int aux2=0;
            int aux3=0;

            for (int i=1; i<this->get_total_clientes_sistema(); i++){

                if (this->clientes_sistema[i]->get_activo()){
                    cout << "Cliente " <<aux2+1<<": "<<endl;
                    this->clientes_sistema[i]->print_solo_cliente();
                    aux2++;
                }

            }
            aux2--;

            if (aux2>=0){
                    do{
                        cout << "De que cliente quieres eliminar el pedido: ";
                        cin >> aux;
                        aux--;
                    }while(aux<0 || aux > aux2); // aux2 -> Ultimo producto activo


                    aux2=0;

                    //Ubicar la posicion verdaddera del cliente (ahora hay que tener en cuenta los desactivados)
                    for (int i=1; i<this->get_total_clientes_sistema(); i++){

                        if (aux2==aux){
                            aux3=i;
                        }

                        if (this->clientes_sistema[i]->get_activo()){
                            aux2++;
                        }

                    }

                    int aux4=0;
                    bool a=true;

                    do{
                        aux4=0;
                        a=true;
                        this->clientes_sistema[aux3]->print();
                            cout <<"DEBUGGGG"<< (this->clientes_sistema[aux3]->get_total_pedidos_cliente()==0)<<endl;
                            cout <<"DEBUGGGG"<< (this->clientes_sistema[aux3]->get_total_pedidos_cliente())<<endl;

                        if(this->clientes_sistema[aux3]->get_total_pedidos_cliente()==0){
                            a=false;
                            cout << "--No quedan pedidos--" <<endl;
                        }
                        else{

                            cout << "Que pedido quieres eliminar: ";
                            cin >> aux4;


                        }
                        
                        
                    }while((aux4<=0 || aux4>this->clientes_sistema[aux3]->get_total_pedidos_cliente()) && a==true);
                    
                    if(a==true){
                        this->clientes_sistema[aux3]->eliminar_cancelar_pedido(aux4);
                    }

            }
            else{
                cout << "No ha mas pedidos"<<endl;
            }
        
                
        }
        else if(decision==16){
            this->set_ingredientes_bd();
        }
        else if(decision==17){
            this->print_ingredientes_bd();
        }
        else if(decision==18){
            this->cargar_en_xml();
        }
        

    else{
        cout << BOLDRED<<"Opcion no valida"<<DEFAULT<<endl;
    }
    }
}


void Sistema::menu_cliente(){
int decision=1;
int aux=0;

    while (decision!=0){
        cout <<BOLDGREEN<< "Bienvenido Cliente"<<endl;
        cout << "Seleccione la accion que quiere realizar:"<<endl;


        cout << " # 0 -> Cerrar Sesion"<<endl;
        cout << " # 1 ->  Consultar Pedidos del Cliente y Ver Detalle de uno Seleccionado "<<endl;
        cout << " # 2 ->  Realizar Nuevo Pedido"<<endl;
        cout << " # 3 ->  Cancelar Pedido "<<endl;
        cout << " # 4 ->  Valorar Pedido"<<endl;
        cout << "   # ";
        cin>>decision;
        cout << DEFAULT<<endl;

        if(decision==0){
    
        }
        else if(decision==1){
            this->consultar_pedido_Cliente();
        }
        else if(decision==2){
            this->realizar_pedido_cliente();
        }
        else if(decision==3){
            this->get_cliente_activo()->print();

                do{
                    cout << "Que Pedido quieres cancelar: "<<endl;
                    cin >> aux;
                    
                    //Filtro para cancelar solo pedidos cancelables
                    if (aux>0 || aux<=this->get_cliente_activo()->get_total_pedidos_cliente()){
                        if (this->get_cliente_activo()->get_vector_pedidos_cliente(aux)->get_cancelable()){
                            

                        }
                        else{ //cancelable==false
                            cout <<BOLDRED<< "No puedes cancelar el pedido, ya esta en reparto"<<endl<<DEFAULT;

                            //Forzamos a que elija otro pedido
                            aux=-1;
                        }
                    }
                
                }while(aux<=0 || aux>this->get_cliente_activo()->get_total_pedidos_cliente());
            
            
            





            this->get_cliente_activo()->eliminar_cancelar_pedido(aux);
        }
        else if(decision==4){
            Valoracion v;
            v.introducir();
            v.set_cliente_val(this->get_cliente_activo());
            v.set_producto_val(this->get_cliente_activo()->realizar_valoracion());
            this->set_Valoracion_vector_Valoraciones_sistema(v);

        }
        else{
            cout << BOLDRED<<"Opcion no valida"<<DEFAULT<<endl;
        }
    }
}

void Sistema::consultar_valoracion_Producto(){

            int aux=0;
            int aux2=0;
            int aux3=0;


            this->imprimir_productos_del_sistema();


            
            //Calculamos total de activos
            for (int i=0; i<this->get_total_productos_sistema(); i++){
                if (this->productos_sistema[i]->get_activo()){
                    aux2++;
                }
            }
            aux2--;



            if (aux2>=0){

                do{
                    cout << "De que producto quieres ver mas a fondo las estadisticas de valoracion: "<<endl;
                    cin>>aux;
                    aux--;
                }while(aux<0 || aux > aux2); // aux2 -> Ultimo producto activo


                aux2=0;
                //Ubicar la posicion verdaddera del producto (ahora hay que tener en cuenta los desactivados)
                for (int i=0; i<this->get_total_productos_sistema(); i++){

                    if (aux2==aux){
                        aux3=i;
                    }

                    if (this->productos_sistema[i]->get_activo()){
                        aux2++;
                    }

                }


                this->productos_sistema[aux3]->imprimir_estadisticas_producto();

            }
            else{
                cout << "No hay productos que ver"<<endl;
            }

}

void Sistema::consultar_pedido_Cliente(){
    int aux_int=0;

    this->get_cliente_activo()->print_solo_cliente();

    for (int i=0; i<this->get_cliente_activo()->get_total_pedidos_cliente(); i++){
        this->get_cliente_activo()->get_vector_pedidos_cliente(i)->print_basic();
        cout << endl;
    }
    
    do{
    cout << "De que pedido quieres ver los detalles: "<<endl;
    cin>>aux_int;
    }while(aux_int>this->get_cliente_activo()->get_total_pedidos_cliente() && aux_int<=0);


    this->get_cliente_activo()->get_vector_pedidos_cliente(aux_int-1)->print();

}


void Sistema::realizar_pedido_cliente(){
    int aux_int=0;
    Pedido ped;
    Pizza* pi;
    bool pasada=false;
    bool fin=false;
    bool fin2=false;
    int aux_int2=0;
    bool nueva=true;
    int i=0;

    ped.introducir();
    
    while (fin==false){
        fin2=false;
        cout << "Que desea una pizza al gusto (1) o un refresco-pizza de la carta (2) o presione 0 para salir del pedido: "<<endl;
        cin>>aux_int;
        if (aux_int==1){
            pasada=true;


            pi=new Pizza;
            pi->introducir();
            pi->set_tipo_pizza("Cliente");

            while(fin2==false){
                cout << "Introduce 0 para dejar de añadir ingredientes o 1 para añadir otro ingrediente"<<endl;
                cin>>aux_int2;

                if (aux_int2==0){
                    fin2=true;
                }

                else if (aux_int2==1){

                    do{

                        this->imprimir_ingredientes_del_sistema();
                        cout << "Introduzca que ingrediente quiere introducir: ";
                        cin>>aux_int2;

                    }while(aux_int2<=0 || aux_int2>this->get_total_ingredientes_sistema());
                    pi->set_Ingrediente_pizza(&this->ingredientes_sistema[aux_int2-1]);

                }
                

            }
            

            //filtro para que no introduzcan pizzas iguales a las ya instanciadas 
            nueva=true;
            for (i=0; i<= this->get_total_productos_sistema() && nueva==true; i++){

                if(Pizza *piz = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                    
                    if ( *pi == *piz ){
                        nueva=false;
                    }

                    if (DEBUG_Sistema){
                        cout << "Actualmente la pizza nueva vs vieja esta --> "<< (*pi == *piz) <<" en la iteracion nº "<<i<<endl;
                        cout << "/////////////////////////////////////////"<<endl<<endl;
                        pi->print();
                        cout << "------------------------------------------"<<endl;
                        piz->print();
                        cout << "/////////////////////////////////////////"<<endl<<endl;
                    }

                } 

                
            }

            if (nueva==false){ //Si no es nueva apuntamos a la encontrada en el sistema igual
                if (DEBUG_Sistema){
                    cout << "---------------------------------->>> Insertando pizza del sistema"<<endl;
                }


                i--;//posicion de la pizza igual encontrada en el sistema

                if (productos_sistema[i]->get_activo()){

                    cout << "Ups, parece que tu pizza al guto esta en la carta, no te preocupes por tu despiste, ya hemos seleccionado la de la carta por ti"<<endl;
                }
                else{
                    cout << "Tu pizza es similar a una pizza antigua del sistema"<<endl;
                    productos_sistema[i]->set_activo(true);
                }

                ped.set_producto_pedido(productos_sistema[i]);

            }
            else{ //Si es completamente nueva lo añadimos a los productos del sistema y apuntamos desde el pedido
                if (DEBUG_Sistema){
                    cout << "---------------------------------->>> Insertando nueva pizza al sistema"<<endl;
                }
                this->setProducto_vectorPolimorfico_productosSistema(*pi);
                ped.set_producto_pedido(this->productos_sistema[this->get_total_productos_sistema()-1]);
            }
            delete pi;
        }
        if (aux_int==2){
            int aux=0;
            int aux2=0;
            int aux3=0;
            pasada=true;


            this->imprimir_productos_del_sistema();


            
            //Calculamos total de activos
            for (int i=0; i<this->get_total_productos_sistema(); i++){
                if (this->productos_sistema[i]->get_activo()){
                    aux2++;
                }
            }
            aux2--;



            if (aux2>=0){

                do{
                    cout << "Introduzca el producto: ";
                    cin >> aux;
                    aux--;
                }while(aux<0 || aux > aux2); // aux2 -> Ultimo producto activo


                aux2=0;
                //Ubicar la posicion verdaddera del producto (ahora hay que tener en cuenta los desactivados)
                for (int i=0; i<this->get_total_productos_sistema(); i++){

                    if (aux2==aux){
                        aux3=i;
                    }

                    if (this->productos_sistema[i]->get_activo()){
                        aux2++;
                    }

                }

                ped.set_producto_pedido(productos_sistema[aux3]);

            }

            else{
                cout << "No quedan productos en el sistema que se puedan añadir"<<endl;
            }


        }
        else if (aux_int==0 && pasada==true){
            fin=true;
        }
        else {
            cout << "Opcion no valida"<<endl;
        }
    }
    this->get_cliente_activo()->set_pedido_vector_pedidos_cliente(ped);
    
}



void Sistema::EliminarCliente(){

    int aux=0;
    int aux2=1;

    for (int i=1; i<this->get_total_clientes_sistema(); i++){
        if (this->clientes_sistema[i]->get_activo()){
            cout << "Ciente " <<aux2<<": "<<endl;
            this->clientes_sistema[i]->print_solo_cliente();
            aux2++;
        }
    }

    if (aux2!=1){
        do{
            cout << "Que cliente quiere eliminar: ";
            cin >> aux;
        }while(aux<=0 || aux >= aux2); // aux2 -> Ultimo cliente activo
        
        aux2=1;
        //Ubicar la posicion verdaddera del cliente (ahora hay que tener en cuenta los desactivados)
        for (int i=1; i<this->get_total_clientes_sistema(); i++){
            if (aux2==aux){
                aux=i;
            }

            if (this->clientes_sistema[i]->get_activo()){
                aux2++;
            }

        }

        this->clientes_sistema[aux]->set_activo(false);

        
        cout << "--Cliente Eliminado--"<<endl;
    }
    else{
        cout <<BOLDRED<< "--No quedan usuarios para eliminar--"<<DEFAULT<<endl;
    }
    

    
}


void Sistema::EliminarProducto(){

    int aux=0;
    int aux2=0;
    int aux3=0;

    for (int i=0; i<this->get_total_productos_sistema(); i++){

        if (this->productos_sistema[i]->get_activo()){
            cout << "Producto " <<aux2+1<<": "<<endl;
            this->productos_sistema[i]->print();
            aux2++;
        }

    }
    aux2--;

    if (aux2>=0){
        do{
            cout << "Que producto quiere eliminar: ";
            cin >> aux;
            aux--;
        }while(aux<0 || aux > aux2); // aux2 -> Ultimo producto activo


        aux2=0;

        //Ubicar la posicion verdaddera del producto (ahora hay que tener en cuenta los desactivados)
        for (int i=0; i<this->get_total_productos_sistema(); i++){

            if (aux2==aux){
                aux3=i;
            }

            if (this->productos_sistema[i]->get_activo()){
                aux2++;
            }

        }

        this->productos_sistema[aux3]->set_activo(false);

        
        cout << "--Producto Eliminado--"<<endl;
    }
    else{
        cout <<BOLDRED<< "--No quedan productos para eliminar--"<<DEFAULT<<endl;
    }
    

    
}




void Sistema::edit (Pizza* p){
    int aux=1;
    int aux_i=1;
    string aux_s="";
    

    while (aux!=0){
        cout << "Que quieres editar de la pizza: "<<endl;
        cout << "   -0 -> nada"<<endl;
        cout << "   -1 -> cambiar tamano"<<endl;
        cout << "   -2 -> cambiar nombre"<<endl;
        cout << "   -3 -> añadir ingrediente"<<endl;
        cout << "   -4 -> quitar ingrediente"<<endl;
        cout << "# ";
        cin >> aux;

        if(aux==0){

        }
        else if (aux==1){
            cout << "Introduce el nuevo tamaño: ";
            cin >> aux_s;
            p->set_tamano(aux_s);
        }
        else if (aux==2){
            cout << "Introduce el nuevo nombre: ";
            cin >> aux_s;
            p->set_nombre(aux_s);
        }
        else if (aux==3){
            do{
                this->imprimir_ingredientes_del_sistema();
                cout << endl << "Introduce el ingrediente a añadir (numero negativo o 0 para dejar de añadir): ";
                cin >> aux;
                aux--;
                if (aux>=0 && aux<this->get_total_ingredientes_sistema()){
                    p->set_Ingrediente_pizza(&this->ingredientes_sistema[aux]);
                }
            
            }while(aux>=0);
        }
        else if (aux==4){
            
            do{

                do{
                    p->print();
                    cout << endl << "Introduce el ingrediente a eliminar (0 para dejar de eliminar): ";
                    cin >> aux;
                
                }while(aux<0 || aux>p->get_total_ingredientes_pizza());
                if (aux!=0){
                    p->quitar_ingrediente(aux-1);
                }
                cout << "DEBUG   Ingrediente quitado"<<endl;
            }while (aux!=0);
            
        }

    }



}


void Sistema::edit (Refresco* r){
    int aux=1;
    int aux_i=0;
    string aux_s="";
    

    while (aux!=0){
        cout << "Que quieres editar del refresco: "<<endl;
        cout << "   -0 -> nada"<<endl;
        cout << "   -1 -> cambiar tamano"<<endl;
        cout << "   -2 -> cambiar nombre"<<endl;
        cout << "   -3 -> cambiar gas"<<endl;
        cout << "   -4 -> cambiar cafeina"<<endl;
        cout << "   -5 -> cambiar azucar"<<endl;
        cout << "# ";
        cin >> aux;

        if(aux==0){

        }
        else if (aux==1){
            cout << "Introduce el nuevo tamaño: ";
            cin >> aux_s;
            r->set_tamano(aux_s);
        }
        else if (aux==2){
            cout << "Introduce el nuevo nombre: ";
            cin >> aux_s;
            r->set_nombre(aux_s);
        }
        else if (aux==3){
            cout << "Introduce el nuevo gas: ";
            cin >> aux_i;
            r->set_gas(aux_i);  
        }
        else if (aux==4){
            cout << "Introduce el nuevo cafeina: ";
            cin >> aux_i;
            r->set_cafeina(aux_i);
        }
        else if (aux==5){
            cout << "Introduce el nuevo azucar: ";
            cin >> aux_i;
            r->set_azucar(aux_i);
        }

    }


}





void Sistema::modificar_datos_cliente (Cliente* c){
    int aux=1;
    int aux_i=0;
    string aux_s="";
    bool usado=false;
    

    while (aux!=0){
        cout << "Que quieres editar del cliente: "<<endl;
        cout << "   -0 -> nada"<<endl;
        cout << "   -1 -> login"<<endl;
        cout << "   -2 -> pass"<<endl;
        cout << "   -3 -> nombre"<<endl;
        cout << "   -4 -> num_telefono"<<endl;
        cout << "   -5 -> direccion"<<endl;
        cout << "# ";
        cin >> aux;

        if(aux==0){

        }
        else if (aux==1){

            do {
                usado=false;

                cout << "Introduce el nuevo login: ";
                cin >> aux_s;
                

                //filtro para que no coincidan logins
                for (int i=0; i<this->get_total_clientes_sistema() && usado==false; i++){
                    if (this->clientes_sistema[i]->get_login_cliente()==aux_s){
                        usado=true;
                        cout << BOLDRED <<"---Ya esta usado este login---"<<endl<<DEFAULT;
                    }
                }

            }while (usado==true);
            c->set_login_cliente(aux_s);
        }
        else if (aux==2){
            cout << "Introduce la nueva pass: ";
            cin >> aux_s;
            c->set_pass_cliente(aux_s);
        }
        else if (aux==3){
            cout << "Introduce el nuevo nombre: ";
            cin >> aux_s;
            c->set_nombre(aux_s);
        }
        else if (aux==4){
            cout << "Introduce el nuevo numero_telefono: ";
            cin >> aux_s;
            c->set_num_telefono(aux_s);
        }
        else if (aux==5){
            cout << "Introduce la nueva direccion: ";
            cin >> aux_s;
            c->set_direccion(aux_s);
        }
        else{
            cout<<"--Opcion no valida--"<<endl;
        }

    }


}

/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/

Ingrediente* Sistema::create_vector_ingredientes(int dim){

    Ingrediente* I_aux = new Ingrediente [dim];

    if (I_aux == NULL){
        cout << "No hay memoria disponible" << endl;
        exit(1);
    }


    return I_aux;

}




void Sistema::resize_vector_ingrediente(int new_dim){
    if (DEBUG_Sistema){
        cout <<BOLDRED<< "ENTRANDO en resize vector ingredientes"<<endl<< DEFAULT;
    }

    Ingrediente* aux_I=create_vector_ingredientes(new_dim);

    for (int i=0; i<new_dim-1; i++){
        aux_I[i]=this->get_ingrediente_sistema(i);
    }
    delete [] this->ingredientes_sistema;

    this->ingredientes_sistema=aux_I;
    if (DEBUG_Sistema){
        cout <<BOLDRED<< "SALIENDO en resize vector ingredientes"<<endl<< DEFAULT;
    }
}




void Sistema::resize_vector_clientes(int new_dim){
    if (DEBUG_Sistema){
        cout <<BOLDRED<< "ENTRANDO en resize vector clientes"<<endl<< DEFAULT;
    }
    Cliente** aux_C=new Cliente* [new_dim];

    for (int i=0; i<new_dim-1; i++){
        aux_C[i]=this->clientes_sistema[i];
    }
    delete [] this->clientes_sistema;

    this->clientes_sistema=aux_C;
    if (DEBUG_Sistema){
        cout <<BOLDRED<< "SALIENDO en resize vector clientes"<<endl<< DEFAULT;
    }
}


void Sistema::resize_vector_valoraciones(int new_dim){
    Valoracion* aux_v=new Valoracion [new_dim];

    for (int i=0; i<new_dim-1; i++){
        aux_v[i]=this->valoraciones_sistema[i];
    }
    delete [] this->valoraciones_sistema;

    this->valoraciones_sistema=aux_v;
}


void Sistema::resize_vector_polimorfico(int new_dim){
    Producto** aux_p=new Producto* [new_dim];

    for (int i=0; i<new_dim-1; i++){
        aux_p[i]=this->productos_sistema[i];
    }
    delete [] this->productos_sistema;

    this->productos_sistema=aux_p;
}


void Sistema::resize_vector_resultado_busqueda_pedidos (int new_dim){
    Pedido** aux_p=new Pedido* [new_dim];

    for (int i=0; i<new_dim-1; i++){
        aux_p[i]=this->resultado_busqueda_pedidos[i];
    }
    delete [] this->resultado_busqueda_pedidos;

    this->resultado_busqueda_pedidos=aux_p;
}


void Sistema::resize_vector_resultado_busqueda_clientes (int new_dim){
    Cliente** aux_c=new Cliente* [new_dim];

    for (int i=0; i<new_dim-1; i++){
        aux_c[i]=this->resultado_busqueda_clientes[i];
    }
    delete [] this->resultado_busqueda_clientes;

    this->resultado_busqueda_clientes=aux_c;
}

void Sistema::resize_vector_resultado_busqueda_productos (int new_dim){
    Producto** aux_p=new Producto* [new_dim];

    for (int i=0; i<new_dim-1; i++){
        aux_p[i]=this->resultado_busqueda_productos[i];
    }
    delete [] this->resultado_busqueda_productos;

    this->resultado_busqueda_productos=aux_p;
}


void Sistema::buscar_cliente (int modo){
    //Inicializamos las busquedas a 0
    delete [] this->resultado_busqueda_clientes;
    this->resultado_busqueda_clientes=new Cliente* [1];
    this->set_total_clientes_encontrados(0);

    if (modo==1){ //buscar por login
        string l="";
        cout << "Introduce el login: ";
        cin >>l;


        for (int i=0; i<this->get_total_clientes_sistema(); i++){
            if (this->clientes_sistema[i]->get_activo()){

                if (this->clientes_sistema[i]->get_login_cliente()==l){
                    this->set_resultado_busqueda_clientes(this->clientes_sistema[i]);
                }
            }

        }


    }
    
    else if (modo==2){ //buscar por nombre
        string n="";
        cout << "Introduce el login: ";
        cin >>n;


        for (int i=0; i<this->get_total_clientes_sistema(); i++){
            if (this->clientes_sistema[i]->get_activo()){

                if (this->clientes_sistema[i]->get_nombre()==n){
                    this->set_resultado_busqueda_clientes(this->clientes_sistema[i]);
                }
            }
        }


    }
}

void Sistema::buscar_pedidos (int modo){
    //Inicializamos las busquedas a 0
    delete [] this->resultado_busqueda_pedidos;
    this->resultado_busqueda_pedidos=new Pedido* [1];
    this->set_total_pedidos_encontrados(0);

    if (modo==1){ //buscar por rango de precios (con iva)
        float aux1=0;
        float aux2=0;
        
        do{
            cout << "Introduce el inicio del rango: ";
            cin >>aux1;
        }while (aux1<0.0);
        
        
        do{
            cout << "Introduce el final del rango: ";
            cin >>aux2;
        }while (aux2<aux1);

        for (int i=1; i<this->get_total_clientes_sistema(); i++){
            for (int j=0; j<this->clientes_sistema[i]->get_total_pedidos_cliente(); j++){

                if (this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_precio_pedido_con_iva()>=aux1 && this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_precio_pedido_con_iva()<=aux2){
                    this->set_resultado_busqueda_pedidos(this->clientes_sistema[i]->get_vector_pedidos_cliente(j));
                }

            }

        }


    }
    
}


void Sistema::buscar_producto (int modo){
    //Inicializamos las busquedas a 0
    delete [] this->resultado_busqueda_productos;
    this->resultado_busqueda_productos=new Producto* [1];
    this->set_total_productos_encontrados(0);

    if (modo==1){ //buscar por nombre
        string n="";
        cout << "Introduce el nombre: ";
        cin >>n;


        for (int i=0; i<this->get_total_productos_sistema(); i++){
            if (this->productos_sistema[i]->get_activo()){

                if (this->productos_sistema[i]->get_nombre()==n){
                    this->set_resultado_busqueda_productos(this->productos_sistema[i]);
                }
            }

        }


    }
    
    else if (modo==2){ //buscar por ingrediente
        int aux=0;
        bool encontrado=false;
        do{
            this->imprimir_ingredientes_del_sistema();
            cout <<endl<<"Introduce de que ingrediente quieres ver productos que lo contengan: ";
            cin>>aux;
        }while(aux<=0 || aux>this->get_total_ingredientes_sistema());


        for (int i=0; i<this->get_total_productos_sistema(); i++){
            if (this->productos_sistema[i]->get_activo()){
                
                if(Pizza *pi = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                    encontrado=false;
                    for (int j=0; j<pi->get_total_ingredientes_pizza(); j++){
                        if (pi->get_Ingrediente_pizza(j) == &this->ingredientes_sistema[aux-1]){
                            encontrado=true;
                        }
                    }
                    if (encontrado){
                        this->set_resultado_busqueda_productos(this->productos_sistema[i]);
                    }
                } 
            }
        }


    }
}


void Sistema::set_ingredientes_bd (){






    try { //Manejamos las posibles excepciones devueltas por el SGBD
    sql::Driver *driver; //declaramos el Objeto Driver
    sql::Connection *con; //declaramos el Objeto Connection
    sql::Statement *stmt; //declaramos el Objeto Statement

    /* Create a connection */
    driver = get_driver_instance(); //creamos la instancia del Objeto Driver
    //Creación de la Instancia del Objeto Connection a través del método conncect
    //del objeto driver. Parámetros: <protocolo://servidor:puerto> <usuario> <clave>
    con = driver->connect("tcp://127.0.0.1:3306", "root", "nueva-contraseña");
    /* Connect to the MySQL test database */
    con->setSchema("DominusKing"); //conectamos a una BD utilizando su espacio de nombre
    //Creamos la Instancia del Objeto Statement utilizando el método createStatement()
    //del objeto Connection
    stmt = con->createStatement();
    
    //A partir de aquí operamos con el SGBD
    //Eliminamos la tabla si estuviera creada antes para evitar excepciones
    stmt->execute("DROP TABLE IF EXISTS ingredientes ;");

    //Creamos la tabla
    stmt->execute("CREATE TABLE IF NOT EXISTS `ingredientes` ("
    "`id_ingrediente` VARCHAR(50),"
    "`nombre` VARCHAR(50),"
    "`activo` INT,"
    "`precio_ingrediente` Double,"
    "`tipo` VARCHAR(30), "
    "`num_veces_incluido_en_pizzas` INT, "
    "PRIMARY KEY (`id_ingrediente`)"
    ");");

    for (int j=0; j<this->get_total_ingredientes_sistema(); j++){
    
        string i=ingredientes_sistema[j].get_id_ingrediente();
        string no=ingredientes_sistema[j].get_nombre();
        bool a=ingredientes_sistema[j].get_activo();
        float p=ingredientes_sistema[j].get_precio_ingrediente();
        string t=ingredientes_sistema[j].get_tipo();
        int nu=ingredientes_sistema[j].get_num_veces_incluido_en_pizzas();

        string a_s="";
        string p_s="";
        string nu_s="";

        stringstream ss1;
        ss1<<a;
        a_s=ss1.str();
        stringstream ss2;
        ss2<<p;
        p_s=ss2.str();
        stringstream ss3;
        ss3<<nu;
        nu_s=ss3.str();

        //Insertamos datos en la tabla
        stmt->execute("INSERT INTO ingredientes VALUES ('"+ i +"', '"+no+"', "+a_s+", '"+p_s+"', '"+t+"', '"+nu_s+"');");
    }


    //Eliminamos la tabla
    // stmt->execute("DROP TABLE asignaturas ;");
    // cout << "\t... Elimnamos las tabla asignatura ... " << endl;

    //Eliminamos los objetos que hemos utilizado para gestionar
    delete stmt;
    delete con;

    } catch (sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout <<endl<< "--Se han cargado de manera correcta los ingredientes en la Base de Datos--" << endl << endl;
}
void Sistema::print_ingredientes_bd (){






    try { //Manejamos las posibles excepciones devueltas por el SGBD
    sql::Driver *driver; //declaramos el Objeto Driver
    sql::Connection *con; //declaramos el Objeto Connection
    sql::Statement *stmt; //declaramos el Objeto Statement
    sql::ResultSet *res; //declaramos el Objeto ResulSet

    /* Create a connection */
    driver = get_driver_instance(); //creamos la instancia del Objeto Driver
    //Creación de la Instancia del Objeto Connection a través del método conncect
    //del objeto driver. Parámetros: <protocolo://servidor:puerto> <usuario> <clave>
    con = driver->connect("tcp://127.0.0.1:3306", "root", "nueva-contraseña");
    /* Connect to the MySQL test database */
    con->setSchema("DominusKing"); //conectamos a una BD utilizando su espacio de nombre
    //Creamos la Instancia del Objeto Statement utilizando el método createStatement()
    //del objeto Connection
    stmt = con->createStatement();
    


    //Consultar y manejar los datos devueltos por la BD
    res = stmt->executeQuery("SELECT id_ingrediente, nombre, activo, precio_ingrediente, tipo, num_veces_incluido_en_pizzas FROM ingredientes;");
    cout << "... Consultamos la BD ..." << endl<<endl;

    cout << endl<< "\t\t"<<"id_ingrediente" <<'\t'<< "nombre" <<'\t'<<'\t'<< "activo" <<'\t'<<'\t'<< "precio_ingrediente" <<'\t'<< "tipo" <<'\t'<< "num_veces_incluido_en_pizzas"<<endl;

    while (res->next()) {
        /* Access column data by alias or column name */
        cout << "\t\t" << res->getString("id_ingrediente");
        cout << "\t\t" << res->getString("nombre");
        cout << "\t\t" << res->getInt("activo");
        cout << "\t\t" << res->getDouble("precio_ingrediente");
        cout << "\t\t" << res->getString("tipo");
        cout << " " << res->getInt("num_veces_incluido_en_pizzas") << endl;

    }

    //Eliminamos la tabla
    // stmt->execute("DROP TABLE asignaturas ;");
    // cout << "\t... Elimnamos las tabla asignatura ... " << endl;

    //Eliminamos los objetos que hemos utilizado para gestionar
    delete res;
    delete stmt;
    delete con;

    } catch (sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout <<endl<<endl<< "--Se han impreso los datos de manera correcta desde la Base de Datos--" << endl << endl;
}


void Sistema::cargar_en_xml(){

    
    
    ofstream fichero;

    fichero.open ("datos.xml");

    fichero << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
    fichero << "<sistemaTiendaDominosKing>"<<endl;


    fichero<<"\t"<<"<total_ingredientes> "<<this->get_total_ingredientes_sistema()<<" </total_ingredientes>"<<endl;
    fichero<<"\t"<<endl<<"<ingredientes>"<<endl;

    for (int i=0; i<this->get_total_ingredientes_sistema(); i++){
        fichero<<"\t\t"<<"<ingrediente>"<<endl;
            fichero<<"\t\t\t"<<"<id_ingrediente> "<<this->ingredientes_sistema[i].get_id_ingrediente()<<" </id_ingrediente>"<<endl;
            fichero<<"\t\t\t"<<"<nombre> "<<this->ingredientes_sistema[i].get_nombre()<<" </nombre>"<<endl;
            fichero<<"\t\t\t"<<"<activo> "<<this->ingredientes_sistema[i].get_activo()<<" </activo>"<<endl;
            fichero<<"\t\t\t"<<"<precio> "<<this->ingredientes_sistema[i].get_precio_ingrediente()<<" </precio>"<<endl;
            fichero<<"\t\t\t"<<"<tipo> "<<this->ingredientes_sistema[i].get_tipo()<<" </tipo>"<<endl;
            fichero<<"\t\t\t"<<"<numero_veces_incluido_en_pizzas> "<<this->ingredientes_sistema[i].get_num_veces_incluido_en_pizzas()<<" </numero_veces_incluido_en_pizzas>"<<endl;
        fichero<<"\t\t"<<"</ingrediente>"<<endl<<endl;
    }
    fichero<<"\t"<<"</ingredientes>"<<endl<<endl;

    fichero<<"\t"<<"<total_productos> "<<this->get_total_productos_sistema()<<" </total_productos>"<<endl;

    fichero<<"\t"<<"<productos>"<<endl<<endl;

        int aux=0;
        for(int i=0; i<this->get_total_productos_sistema(); i++){
            if(Pizza *p = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                aux++;
            }
        }


        fichero<<"\t\t"<<"<total_pizzas> "<<aux<<" </total_pizzas>"<<endl;


        fichero<<"\t\t"<<"<pizzas>"<<endl<<endl;

        for(int i=0; i<this->get_total_productos_sistema(); i++){
            if(Pizza *p = dynamic_cast<Pizza*>(this->productos_sistema[i])){
                fichero<<"\t\t\t"<<"<pizza>"<<endl;
                    fichero <<"\t\t\t\t"<<"<id_producto> "<<p->get_id_producto()<<" </id_producto>"<<endl;
                    fichero <<"\t\t\t\t"<<"<nombre> "<<p->get_nombre()<<" </nombre>"<<endl;
                    fichero <<"\t\t\t\t"<<"<activo> "<<p->get_activo()<<" </activo>"<<endl;
                    fichero <<"\t\t\t\t"<<"<precio_con_iva> "<<p->get_precio_producto_con_iva()<<" </precio_con_iva>"<<endl;
                    fichero <<"\t\t\t\t"<<"<precio_sin_iva> "<<p->get_precio_producto_sin_iva()<<" </precio_sin_iva>"<<endl;
                    fichero <<"\t\t\t\t"<<"<iva> "<<p->get_porcentaje_iva_producto()<<" </iva>"<<endl;
                    fichero <<"\t\t\t\t"<<"<num_valoraciones> "<<p->get_num_valoracion()<<" </num_valoraciones>"<<endl;
                    fichero <<"\t\t\t\t"<<"<media_valoraciones> "<<p->get_valoracion_media()<<" </media_valoraciones>"<<endl;
                    fichero <<"\t\t\t\t"<<"<tamanio> "<<p->get_tamano()<<" </tamanio>"<<endl;
                    fichero <<"\t\t\t\t"<<"<valoracion_total> "<<p->get_valoracion_total()<<" </valoracion_total>"<<endl;
                    fichero <<"\t\t\t\t"<<"<num_veces_incluido_en_pedidos> "<<p->get_num_veces_incluido_en_pedidos()<<" </num_veces_incluido_en_pedidos>"<<endl;
                    fichero <<"\t\t\t\t"<<"<tipo_pizza> "<<p->get_tipo_pizza()<<" </tipo_pizza>"<<endl;
                    fichero <<"\t\t\t\t"<<"<precio_base> "<<p->get_preciobase_sin_iva()<<" </precio_base>"<<endl;
                    fichero <<"\t\t\t\t"<<"<total_ingredientes_pizza> "<<p->get_total_ingredientes_pizza()<<" </total_ingredientes_pizza>"<<endl;
                    fichero <<"\t\t\t\t\t"<<"<ingredientes> "<<endl;
                        for (int j=0; j<p->get_total_ingredientes_pizza(); j++){
                            fichero <<"\t\t\t\t\t\t"<<"<ingrediente> "<<p->get_Ingrediente_pizza(j)->get_id_ingrediente()<<" </ingrediente>"<<endl;
                        }

                    fichero <<"\t\t\t\t\t"<<"</ingredientes>"<<endl;
                fichero<<"\t\t\t"<<"</pizza>"<<endl<<endl;
            }
        }
        fichero<<"\t\t"<<"</pizzas>"<<endl<<endl;



        aux=0;
        for(int i=0; i<this->get_total_productos_sistema(); i++){
            if(Refresco *rand_r = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                aux++;
            }
        }

        fichero<<"\t\t"<<"<total_refrescos> "<<aux<<" </total_refrescos>"<<endl;

        fichero<<"\t\t"<<"<refrescos>"<<endl<<endl;

        for(int i=0; i<this->get_total_productos_sistema(); i++){
            if(Refresco *r = dynamic_cast<Refresco*>(this->productos_sistema[i])){
                fichero<<"\t\t\t"<<"</refresco>"<<endl;
                    fichero <<"\t\t\t\t"<<"<id_producto> "<<r->get_id_producto()<<" </id_producto>"<<endl;
                    fichero <<"\t\t\t\t"<<"<nombre> "<<r->get_nombre()<<" </nombre>"<<endl;
                    fichero <<"\t\t\t\t"<<"<activo> "<<r->get_activo()<<" </activo>"<<endl;
                    fichero <<"\t\t\t\t"<<"<precio_con_iva> "<<r->get_precio_producto_con_iva()<<" </precio_con_iva>"<<endl;
                    fichero <<"\t\t\t\t"<<"<precio_sin_iva> "<<r->get_precio_producto_sin_iva()<<" </precio_sin_iva>"<<endl;
                    fichero <<"\t\t\t\t"<<"<iva> "<<r->get_porcentaje_iva_producto()<<" </iva>"<<endl;
                    fichero <<"\t\t\t\t"<<"<num_valoraciones> "<<r->get_num_valoracion()<<" </num_valoraciones>"<<endl;
                    fichero <<"\t\t\t\t"<<"<media_valoraciones> "<<r->get_valoracion_media()<<" </media_valoraciones>"<<endl;
                    fichero <<"\t\t\t\t"<<"<tamanio> "<<r->get_tamano()<<" </tamanio>"<<endl;
                    fichero <<"\t\t\t\t"<<"<valoracion_total> "<<r->get_valoracion_total()<<" </valoracion_total>"<<endl;
                    fichero <<"\t\t\t\t"<<"<num_veces_incluido_en_pedidos> "<<r->get_num_veces_incluido_en_pedidos()<<" </num_veces_incluido_en_pedidos>"<<endl;
                    fichero <<"\t\t\t\t"<<"<azucar> "<<r->get_azucar()<<" </azucar>"<<endl;
                    fichero <<"\t\t\t\t"<<"<gas> "<<r->get_gas()<<" </gas>"<<endl;
                    fichero <<"\t\t\t\t"<<"<cafeina> "<<r->get_cafeina()<<" </cafeina>"<<endl;
                fichero<<"\t\t\t"<<"</refresco>"<<endl<<endl;
            }
        }
        fichero<<"\t\t"<<"</refrescos>"<<endl<<endl;
    fichero<<"\t"<<"</productos>"<<endl<<endl;

    fichero<<"\t"<<"<total_clientes_sistema> "<<this->get_total_clientes_sistema()<<" <total_clientes_sistema>"<<endl<<endl;
    fichero<<"\t"<<"<clientes>"<<endl<<endl;
    
        for(int i=0; i<this->get_total_clientes_sistema(); i++){
            fichero<<"\t\t"<<"<cliente>"<<endl<<endl;
                fichero<<"\t\t\t"<<"<id_cliente> "<<this->clientes_sistema[i]->get_id_cliente()<<" </id_cliente> "<<endl<<endl;
                fichero<<"\t\t\t"<<"<login> "<<this->clientes_sistema[i]->get_login_cliente()<<" </login> "<<endl<<endl;
                fichero<<"\t\t\t"<<"<password> "<<this->clientes_sistema[i]->get_pass_cliente()<<" </password> "<<endl<<endl;
                fichero<<"\t\t\t"<<"<nombre> "<<this->clientes_sistema[i]->get_nombre()<<" </nombre> "<<endl<<endl;
                fichero<<"\t\t\t"<<"<activo> "<<this->clientes_sistema[i]->get_activo()<<" </activo> "<<endl<<endl;
                fichero<<"\t\t\t"<<"<numero_telefono> "<<this->clientes_sistema[i]->get_num_telefono()<<" </numero_telefono> "<<endl<<endl;
                fichero<<"\t\t\t"<<"<direccion> "<<this->clientes_sistema[i]->get_direccion()<<" </direccion> "<<endl<<endl;
                fichero<<"\t\t\t"<<"<valoracion_media_productos> "<<this->clientes_sistema[i]->get_valoracion_media_productos()<<" </valoracion_media_productos>"<<endl<<endl;
                fichero<<"\t\t\t"<<"<precio_medio_pedidos> "<<this->clientes_sistema[i]->get_precio_medio_pedidos_cliente()<<" </precio_medio_pedidos>"<<endl<<endl;
                fichero<<"\t\t\t"<<"<total_valoraciones> "<<this->clientes_sistema[i]->get_total_valoraciones_cliente()<<" </total_valoraciones>"<<endl<<endl;
                fichero<<"\t\t\t"<<"<total_pedidos> "<<this->clientes_sistema[i]->get_total_pedidos_cliente()<<" </total_pedidos>"<<endl<<endl;
                fichero<<"\t\t\t"<<"<pedidos>"<<endl;

                for (int j=0; j<this->clientes_sistema[i]->get_total_pedidos_cliente(); j++) {
                    fichero<<"\t\t\t\t"<<"<pedido>"<<endl;

                        fichero<<"\t\t\t\t\t"<<"<id_pedido> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_id_pedido()<<" <id_pedido>"<<endl;
                        fichero<<"\t\t\t\t\t"<<"<fecha>"<<endl;
                        fichero<<"\t\t\t\t\t\t"<<"<anio> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_fecha_pedido().get_anio()<<" <anio>"<<endl;
                        fichero<<"\t\t\t\t\t\t"<<"<mes> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_fecha_pedido().get_mes()<<" <mes>"<<endl;
                        fichero<<"\t\t\t\t\t\t"<<"<dia> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_fecha_pedido().get_dia()<<" <dia>"<<endl;
                        fichero<<"\t\t\t\t\t"<<"</fecha>"<<endl;

                        fichero<<"\t\t\t\t\t"<<"<hora>"<<endl;
                        fichero<<"\t\t\t\t\t\t"<<"<hora> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_hora_pedido().get_horas()<<" <hora>"<<endl;
                        fichero<<"\t\t\t\t\t\t"<<"<minutos> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_hora_pedido().get_minutos()<<" <minutos>"<<endl;
                        fichero<<"\t\t\t\t\t\t"<<"<segundos> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_hora_pedido().get_segundos()<<" <segundos>"<<endl;
                        fichero<<"\t\t\t\t\t"<<"</hora>"<<endl;

                        fichero<<"\t\t\t\t\t"<<"<estado> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_estado()<<" <estado>"<<endl;
                        fichero<<"\t\t\t\t\t"<<"<total_precio_pedido_sin_iva> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_precio_pedido_con_iva()<<" <total_precio_pedido_sin_iva>"<<endl;
                        fichero<<"\t\t\t\t\t"<<"<total_precio_pedido_con_iva> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_precio_pedido_sin_iva()<<" <total_precio_pedido_con_iva>"<<endl;
                        fichero<<"\t\t\t\t\t"<<"<cancelable> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_cancelable()<<" <cancelable>"<<endl;
                        fichero<<"\t\t\t\t\t"<<"<total_productos> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_productos_pedido()<<" <total_productos>"<<endl;
                        
                        fichero<<"\t\t\t\t\t"<<"<productos>"<<endl;

                        for (int k=0;k<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_total_productos_pedido(); k++){

                            fichero<<"\t\t\t\t\t\t"<<"<producto> "<<this->clientes_sistema[i]->get_vector_pedidos_cliente(j)->get_producto_pedido(k)->get_id_producto()<<" <producto>"<<endl;
                        
                        }

                        fichero<<"\t\t\t\t\t"<<"</productos>"<<endl;



                    fichero<<"\t\t\t\t"<<"</pedido>"<<endl;
                }
                fichero<<"\t\t\t"<<"</pedidos>"<<endl;



            fichero<<"\t\t"<<"</cliente>"<<endl<<endl;
        }



    fichero<<"\t"<<"</clientes>"<<endl<<endl;

    fichero<<"\t"<<"<total_valoraciones> "<<this->get_total_valoraciones_sistema()<<" </total_valoraciones>"<<endl<<endl;
    fichero<<"\t"<<"<valoraciones>"<<endl<<endl;
    for (int i=0; i<this->get_total_valoraciones_sistema(); i++){
    fichero<<"\t\t"<<"<valoracion>"<<endl<<endl;
        fichero<<"\t\t\t"<<"<id_valoracion> "<<this->valoraciones_sistema[i].get_id_val()<<" <id_valoracion>"<<endl;
        fichero<<"\t\t\t"<<"<id_cliente> "<<this->valoraciones_sistema[i].get_cliente_val()->get_id_cliente()<<" <id_cliente>"<<endl;
        fichero<<"\t\t\t"<<"<id_producto> "<<this->valoraciones_sistema[i].get_producto_val()->get_id_producto()<<" <id_producto>"<<endl;
        fichero<<"\t\t\t"<<"<estrellas> "<<this->valoraciones_sistema[i].get_estrellas_val()<<" <estrellas>"<<endl;
    fichero<<"\t\t"<<"</valoracion>"<<endl<<endl;

    }

    fichero<<"\t"<<"</valoraciones>"<<endl<<endl;



    fichero << "</sistemaTiendaDominosKing>"<<endl;
    fichero.close ();

    cout <<BOLDBLUE<< "--- Se han cargado los datos de manera correcta en el xml ---"<<endl<<endl<<DEFAULT;
}

void Sistema::cargar_del_xml(){


    Ingrediente *ing;
    Pizza *pi;
    Refresco *re;
    Cliente *cl;
    Pedido *ped;
    Valoracion *val;

    ifstream flujo_entrada_fichero;

    string cadena = "";


    flujo_entrada_fichero.open("datos.xml");

    int total=0;
    int total2=0;
    int total3=0;
    string cadena_inicio, cadena_cierre;
    string carga_no_necesaria_s;
    float carga_no_necesaria_f;
    int carga_no_necesaria_i;


    string id2;

    bool bool1, bool2, bool3;
    
    string carga_id, carga_nombre, carga_tipo;
    bool carga_activo=false;

    float carga_iva=0.0;

    string login, pass, numtel, d;

    float carga_precio=0.0;
    string carga_tamanio;

    int aux1, aux2, aux3, aux4, aux5, aux6;
    string id_c, id_p;

    

flujo_entrada_fichero >> cadena;
    if (cadena != "<?xml"){
        cout << "Error en la cabecera-1 <?xml" << endl;
    }else{
        flujo_entrada_fichero >> cadena;
        if (cadena != "version=\"1.0\""){
            cout << "Error en la cabecera-2 version=\"1.0\"" << endl;
        }else{
            flujo_entrada_fichero >> cadena;
            if (cadena != "encoding=\"UTF-8\"?>"){
                cout << "Error en la cabecera-3 encoding=\"UTF-8\"?>" << endl;
            }else{
                flujo_entrada_fichero >> cadena;
                if (cadena != "<sistemaTiendaDominosKing>"){
                cout << "Error en la etiqueta <sistemaTiendaDominosKing>" << endl;
                }else{
                    flujo_entrada_fichero >> cadena_inicio >> total >> cadena_cierre;

                    flujo_entrada_fichero >> cadena_inicio;//<ingredientes>

                        for (int i=0; i<total; i++){

                            flujo_entrada_fichero >> cadena_inicio;//<ingrediente>
                                flujo_entrada_fichero >> cadena_inicio >> carga_id >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_nombre >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_precio >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_tipo >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;

                            flujo_entrada_fichero >> cadena_cierre;//<ingrediente>
                            //Carga
                            ing = new Ingrediente(carga_id, carga_nombre, carga_precio, carga_tipo);
                            this->set_ingrediente_vector_ingrediente(*ing);
                            delete ing;

                        }
                    flujo_entrada_fichero >> cadena_cierre;//</ingredientes>
                    
                    if (DEBUG_Sistema){
                        cout <<endl<<endl<< "cadena_cierre -> "<<cadena_cierre<<endl;
                        cout << YELLOW <<"-----FIN DE CARGA DE INGREDIENTES CON XML-----"<<DEFAULT<<endl<<endl<<endl;
                    }


                    flujo_entrada_fichero >> cadena_inicio >> total >> cadena_cierre;
                    flujo_entrada_fichero >> cadena_inicio;//<productos>

                    flujo_entrada_fichero >> cadena_inicio >> total >> cadena_cierre;
                    flujo_entrada_fichero >> cadena_inicio;//<pizzas>
                        for (int i=0; i<total; i++){
                            
                            flujo_entrada_fichero >> cadena_inicio;//<pizza>
                            
                                flujo_entrada_fichero >> cadena_inicio >> carga_id >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_nombre >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_activo >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_iva >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_tamanio >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_tipo >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_precio >> cadena_cierre;

                                pi = new Pizza (carga_id, carga_nombre, carga_tamanio, carga_iva, carga_precio, carga_iva, carga_tipo);

                                flujo_entrada_fichero >> cadena_inicio >> total2 >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio;
                                for (int j=0; j<total2; j++){

                                    flujo_entrada_fichero >> cadena_inicio >> id2 >> cadena_cierre;

                                    pi->set_Ingrediente_pizza(get_posicionIngredienteConiID(id2));
                                    
                                }
                                flujo_entrada_fichero>>cadena_cierre;//</ingrediente>

                                this->setProducto_vectorPolimorfico_productosSistema(*pi);
                                delete pi;

                            flujo_entrada_fichero >> cadena_cierre;//<pizza>
                

                        }

                    flujo_entrada_fichero >> cadena_cierre;//</pizzas>

                    flujo_entrada_fichero >> cadena_inicio >> total >> cadena_cierre;

                    flujo_entrada_fichero >> cadena_inicio;//<refrescos>

                        for (int i=0; i<total; i++){
                            
                            flujo_entrada_fichero >> cadena_inicio;//<refresco>
                                flujo_entrada_fichero >> cadena_inicio >> carga_id >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_nombre >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_activo >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f>> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_precio >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_iva >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_tamanio >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> bool1 >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> bool2 >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> bool3 >> cadena_cierre;

                                re = new Refresco (carga_id, carga_nombre, carga_precio, carga_tamanio, carga_iva, bool1, bool2, bool3,carga_activo);
                                this->setProducto_vectorPolimorfico_productosSistema(*re);
                                delete re;

                            flujo_entrada_fichero >> cadena_cierre;//<refresco>
                

                        }

                        flujo_entrada_fichero >> cadena_cierre;//</refrescos>

                    flujo_entrada_fichero >> cadena_cierre;//</productos>

                    if (DEBUG_Sistema){
                        cout <<endl<<endl<< "cadena_cierre -> "<<cadena_cierre<<endl;
                        cout << YELLOW <<"-----FIN DE CARGA DE PRODUCTOS CON XML-----"<<DEFAULT<<endl<<endl<<endl;
                    }

                    flujo_entrada_fichero >> cadena_inicio >> total >> cadena_cierre;

                    flujo_entrada_fichero >> cadena_inicio;//<clientes>

                    for (int i=0; i<total; i++){
                        flujo_entrada_fichero >> cadena_inicio;//<cliente>
                        flujo_entrada_fichero >> cadena_inicio >> carga_id >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> login >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> pass >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> carga_nombre >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> carga_activo >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> numtel >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> d >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                        flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;



                        cl = new Cliente (carga_id, login, pass, carga_nombre, numtel, d, carga_activo);

                        



                        flujo_entrada_fichero >> cadena_inicio >> total2 >> cadena_cierre;

                        flujo_entrada_fichero >> cadena_inicio;//<pedidos>

                        for (int j=0; j<total2; j++){
                            flujo_entrada_fichero >> cadena_inicio;//<pedido>
                                flujo_entrada_fichero >> cadena_inicio >> carga_id >> cadena_cierre;

                                flujo_entrada_fichero >> cadena_inicio;//<fecha>
                                    flujo_entrada_fichero >> cadena_inicio >> aux3 >> cadena_cierre;
                                    flujo_entrada_fichero >> cadena_inicio >> aux2 >> cadena_cierre;
                                    flujo_entrada_fichero >> cadena_inicio >> aux1 >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_cierre;//</fecha>
                                
                                flujo_entrada_fichero >> cadena_inicio;//<hora>
                                    flujo_entrada_fichero >> cadena_inicio >> aux4 >> cadena_cierre;
                                    flujo_entrada_fichero >> cadena_inicio >> aux5 >> cadena_cierre;
                                    flujo_entrada_fichero >> cadena_inicio >> aux6 >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio;//</hora>

                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_s >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_f >> cadena_cierre;
                                flujo_entrada_fichero >> cadena_inicio >> carga_no_necesaria_i >> cadena_cierre;




                                ped=new Pedido(carga_id, aux1, aux2, aux3, aux4, aux5, aux6);


                                flujo_entrada_fichero >> cadena_inicio >> total3 >> cadena_cierre;

                                flujo_entrada_fichero >> cadena_inicio; //<productos>

                                for (int k=0; k<total3; k++){

                                    flujo_entrada_fichero >> cadena_inicio>>id2>>cadena_cierre; 

                                    ped->set_producto_pedido(get_posicionProductoConiID(id2));
                                    
                                    get_posicionProductoConiID(id2)->print();
                                    
                                }

                                flujo_entrada_fichero >> cadena_cierre; //</productos>






                            cl->set_pedido_vector_pedidos_cliente(*ped);
                            delete ped;
                            flujo_entrada_fichero >> cadena_cierre;//</pedido>

                        }

                        flujo_entrada_fichero >> cadena_cierre;//</pedidos>



                        this->set_cliente_vector_cliente_sistema(*cl);
                        delete cl;
                        flujo_entrada_fichero >> cadena_cierre;//</cliente>

                    }
                    flujo_entrada_fichero >> cadena_cierre;//</clientes>

                    if (DEBUG_Sistema){
                        cout <<endl<<endl<< "cadena_cierre -> "<<cadena_cierre<<endl;
                        cout << YELLOW <<"-----FIN DE CARGA DE CLIENTES CON XML-----"<<DEFAULT<<endl<<endl<<endl;
                    }

                    flujo_entrada_fichero >> cadena_inicio>>total>>cadena_cierre;
                    flujo_entrada_fichero >> cadena_inicio;//</valoraciones>

                    for (int i=0; i<total; i++){
                        flujo_entrada_fichero >> cadena_inicio;//<valoracion>
                            flujo_entrada_fichero >> cadena_inicio>>carga_id>>cadena_cierre;
                            flujo_entrada_fichero >> cadena_inicio>>id_c>>cadena_cierre;
                            flujo_entrada_fichero >> cadena_inicio>>id_p>>cadena_cierre;
                            flujo_entrada_fichero >> cadena_inicio>>aux1>>cadena_cierre;
                        flujo_entrada_fichero >> cadena_cierre;//</valoracion>

                        val=new Valoracion(carga_id, aux1, get_posicionProductoConiID(id_p), get_posicionClienteConiID(id_c));
                        this->set_Valoracion_vector_Valoraciones_sistema(*val);
                        delete val;

                    }
                flujo_entrada_fichero >> cadena_cierre;//</valoraciones>

                flujo_entrada_fichero >> cadena_cierre;//</sistemaTiendaDominosKing>

                if (DEBUG_Sistema){
                    cout <<endl<<endl<< "cadena_cierre -> "<<cadena_cierre<<endl;
                    cout << YELLOW <<"-----FIN DE CARGA DE VALORACIONES CON XML-----"<<DEFAULT<<endl<<endl<<endl;
                }

                }  
            }    
        }    
    }






        if (DEBUG_Sistema){
            cout <<endl<<endl<< "cadena_cierre -> "<<cadena_cierre<<endl;
            cout << YELLOW <<"----- FIN -----"<<DEFAULT<<endl<<endl<<endl;
        }



    flujo_entrada_fichero.close();



    cout <<BOLDBLUE<< "--- Se han obtenido los datos de manera correcta del xml ---"<<endl<<endl<<DEFAULT;
    
}


Ingrediente* Sistema::get_posicionIngredienteConiID(const string id){
    bool encontrado=0;
    int i=0;
    for (i=0 ; i < this->get_total_ingredientes_sistema() && encontrado==false; i++){
        if(ingredientes_sistema[i].get_id_ingrediente()==id){
            encontrado=true;
        }
        
    }
    i--;
    return &ingredientes_sistema[i];
}

Producto* Sistema::get_posicionProductoConiID(const string id){
    bool encontrado=0;
    int i=0;
    for (i=0 ; i < this->get_total_productos_sistema() && encontrado==false; i++){
        if(productos_sistema[i]->get_id_producto()==id){
            encontrado=true;
        }
        
    }
    i--;
    return productos_sistema[i];
}

Cliente* Sistema::get_posicionClienteConiID(const string id){
    bool encontrado=0;
    int i=0;
    for (i=0 ; i < this->get_total_clientes_sistema() && encontrado==false; i++){
        if(clientes_sistema[i]->get_id_cliente()==id){
            encontrado=true;
        }
        
    }
    i--;
    return clientes_sistema[i];
}