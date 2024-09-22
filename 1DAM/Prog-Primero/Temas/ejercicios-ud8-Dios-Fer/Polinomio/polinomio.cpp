#include "polinomio.h"

/*-------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  Polinomio  / -----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/




/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/

Polinomio::Polinomio (){//automatico cuando se declara el polimio
    //Aquí dentro se asigna el puntero this

    int dim_ini_coef=10;

    if (DEBUG_C_Polinomio){
        cout << DEBUG <<  "Se invoca al Constructor Polinomio." << " La dirección de this es: " << this << DEFAULT << endl;
    }

    this->coef=crear_vector_float (dim_ini_coef);


    setMaxGrado(dim_ini_coef-1);
    setGrado(0);


    if (DEBUG_C_Polinomio){
        cout << DEBUG <<  "Fin invocacion del Constructor Polinomio." << " La dirección de this es: " << this << DEFAULT << endl;
    }

}

Polinomio::Polinomio (const Polinomio &p){

    int dim_ini_coef=10;

    if (DEBUG_C_Polinomio){
        cout << DEBUG <<  "Se invoca al Constructor Polinomio por copia." << " La dirección de this es: " << this << DEFAULT << endl;
    }


    setMaxGrado(p.getGrado());
    setGrado(0);

    this->coef= new float[p.getGrado()];

    for (int i=p.getGrado(); i>=0; i--) {
        this->setCoeficiente_V3(i, p.getCoef(i));
    }



    if (DEBUG_C_Polinomio){
        cout << DEBUG <<  "Fin invocacion del Constructor Polinomio por copia." << " La dirección de this es: " << this << DEFAULT << endl;
    }

}

Polinomio::~Polinomio(){
    if (DEBUG_C_Polinomio){
        cout << DEBUG <<  "Se invoca al Destructor del Polinomio." << " La dirección de this es: " << this << DEFAULT << endl;
    }

    this->coef=dropVectorFloat(this->coef);

    if (DEBUG_C_Polinomio){
        cout << DEBUG <<  "Fin invocacion del Destructor del Polinomio." << " La dirección de this es: " << this << DEFAULT << endl;
    }

}

/**************************************************************************************************************************************
************************************************************* -  GET'S  - *************************************************************
**************************************************************************************************************************************/
int Polinomio::getGrado() const{
    return this->grado_actual;
}


int Polinomio::getMaxGrado() const{
    return this->grado_max;
}


float Polinomio::getCoef(int grado) const{
    return this->coef[grado];
}



/**************************************************************************************************************************************
************************************************************* -  SET'S  - *************************************************************
**************************************************************************************************************************************/

void Polinomio::setGrado(int nuevo_grado){

    if (DEBUG_C_Polinomio){
        cout << DEBUG <<  "Estableciendo el grado del polinomio..." << this << DEFAULT << endl;
    }


    if (nuevo_grado <= getMaxGrado()){
        this -> grado_actual = nuevo_grado;
    }
    
    else {
        this->resize_Coef(nuevo_grado+1); // nuevo_grado+1 sera la nueva dimension (ejemplo: quiero grado 7 debere tener dim 8)

        this -> grado_actual = nuevo_grado; // una vez redimensionado introducimos el grado

    }

}

void Polinomio::setMaxGrado(int nuevo_grado_max){
    this -> grado_max = nuevo_grado_max;
}


void Polinomio::setCoeficiente_V2(int grado, float coeficiente){
    if (grado<0){
        cout << "Error el grado debe de ser positivo"<<endl;
    }
    else{


        if (this->getGrado()<grado && coeficiente!=0.0){ //caso nuevo coeficiente

            this->setGrado (grado);//setGrado se encargaria de expandir e inicializar en caso de ser necesario

            this->coef[grado]=coeficiente;



        }

        else if (this->getGrado()==grado && coeficiente==0.0){ //Caso mi grado ahora no tiene coef (debemos de actualizar el grado para abajo)

            this->coef[grado]=coeficiente; //ponemos a 0 el coef

            bool fin=false;


            ///Posible modularizacion planteada en clase
            for (int i=this->getGrado()-1; i>=0 && fin==false; i--){//buscamos el 2º mayor grado para sustituir al original (que ahora no tiene coef y no se tendra en cuenta)
                if (getCoef(i)!=0){
                    grado=i; //cambiamos el grado
                    fin=true;
                }

                else if (i==0){
                    grado=i; //cambiamos el grado
                }

            }
            this->setGrado (grado); //establecemos el grado actual
        }

        else { //Caso normal (NI cambiar ultimo a 0 NI añadir mas arriba) (editar cualquiera menos el del grado actual)

            this->coef[grado]=coeficiente;

            //grado se mantiene

        }


    }

    
}


void Polinomio::setCoeficiente_V3(int grado, float coeficiente){ //Exactamente igual que la v2 pero al fina comprueba si hay espacio no usado en caso de que si se redimensionara para que grado=maxGrado
    if (grado<0){
        cout << "Error el grado debe de ser positivo"<<endl;
    }
    else{


        if (this->getGrado()<grado && coeficiente!=0.0){ //caso nuevo coeficiente

            this->setGrado (grado);//setGrado se encargaria de expandir e inicializar en caso de ser necesario

            this->coef[grado]=coeficiente;



        }

        else if (this->getGrado()==grado && coeficiente==0.0){ //Caso mi grado ahora no tiene coef (debemos de actualizar el grado para abajo)

            this->coef[grado]=coeficiente; //ponemos a 0 el coef

            


            
            this->setGrado (this->calcularGrado()); //establecemos el grado actual
        }
        else if (this->getGrado()<grado && coeficiente==0.0){ 
            //no haces nada si intenta meter un 0 redimensionando
        }

        else { //Caso normal (NI cambiar ultimo a 0 NI añadir mas arriba) (editar cualquiera menos el del grado actual)

            this->coef[grado]=coeficiente;

            //grado se mantiene

        }

        if (this->getMaxGrado() != this->getGrado()){

            if (DEBUG_C_Polinomio){
                cout <<DEBUG<< "Actualizando la dim para que se ajuste al grado" << DEFAULT<<endl;
            }

            this->resize_Coef(this->getGrado()+1);//Este resize se mueve con las utiles asi que es totalmente valido para este caso en el que queremos grado=maxGrado, en caso de tener que recortar el vector y que maxGrado < grado_antiguo(ahoraElimiNado) se tendria que reprogramar
            this->setMaxGrado(this->getGrado());

            if (DEBUG_C_Polinomio){
                cout <<DEBUG<<DEBUG<< "Resize para ajustar al grado COMPLETADO" <<DEFAULT<<endl;
            }

        }

    }

    
}



/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/



/**************************************************************************************************************************************
************************************************************* -  BACK  - **************************************************************
**************************************************************************************************************************************/




void Polinomio::resize_Coef(int new_dim){

    float *new_coef=crear_vector_float(new_dim);
    
    
    //Copiamos el antiguo en el nuevo
    copiarVectorFloatConEspacio(this->coef, getGrado()+1, new_coef, new_dim);

    //Eliminamos el antiguo
    this->coef = dropVectorFloat(this->coef);


    //Actualizamos la dimension 
    this->setMaxGrado(new_dim-1);


    //Actualizamos el coef del objeto
    this->coef=new_coef;
    this->setMaxGrado(new_dim-1);

}
void Polinomio::CopiarPolinomio(Polinomio *p){

    for (int i=p->getGrado(); i>=0; i--){
        this->setCoeficiente_V3(i, p->getCoef(i));//Se encarga de actualizar grado y max grado ademas de refactorizar en caso de ser necesario
    }

}



void Polinomio::sumar(const Polinomio &p2){///V1



    int Mayor_Grado=0;
    if (p2.getGrado() > this->getGrado()){
        Mayor_Grado = p2.getGrado();
    }
    
    else{
        Mayor_Grado = this->getGrado();
    }

    for (int i=Mayor_Grado; i>=0; i--){

        if (this->getGrado() < i){
            this->setCoeficiente_V3 (i, p2.getCoef(i));
        }
        else{
            this->setCoeficiente_V3 (i, ( p2.getCoef(i) + this->getCoef(i) ));
        }


    }

}
void Polinomio::sumar(const Polinomio &p2,const Polinomio &p3){///V2

    int Mayor_Grado=0;
    int Menor_Grado=0;

    if (p2.getGrado() > p3.getGrado()){
        Mayor_Grado = p2.getGrado();
        Menor_Grado = p3.getGrado();
    }
    else{
        Mayor_Grado = p3.getGrado();
        Menor_Grado = p3.getGrado();
    }


    for (int i=Mayor_Grado; i>=0; i--) {
        if (i<=Menor_Grado){
            this->setCoeficiente_V3(i, (p2.getCoef(i) + p3.getCoef(i)));
        }
        else{
            if (Mayor_Grado==p2.getGrado()){
                this->setCoeficiente_V3(i, p2.getCoef(i));
            }
            else{
                this->setCoeficiente_V3(i, p3.getCoef(i));
            }
        }
    }
    
    
    
    

}
Polinomio Polinomio::operator+(const Polinomio &p2){///V3
    if (DEBUG_C_Polinomio){
        cout <<ERROR<< "opertor+ ---> sumar V3"<<endl<<DEFAULT;
    }
    Polinomio p1;
    int Mayor_Grado=0;
    int Menor_Grado=0;

    if (p2.getGrado() > this->getGrado()){
        Mayor_Grado = p2.getGrado();
        Menor_Grado = this->getGrado();
    }
    else{
        Mayor_Grado = this->getGrado();
        Menor_Grado = this->getGrado();
    }


    for (int i=Mayor_Grado; i>=0; i--) {
        if (i<=Menor_Grado){
            p1.setCoeficiente_V3(i, (p2.getCoef(i) + this->getCoef(i)));
        }
        else{
            if (Mayor_Grado==p2.getGrado()){
                p1.setCoeficiente_V3(i, p2.getCoef(i));
            }
            else{
                p1.setCoeficiente_V3(i, this->getCoef(i));
            }
        }
    }
    
    
    return p1;
    
}

Polinomio* Polinomio::operator+(const Polinomio *p2){///V4
    if (DEBUG_C_Polinomio){
        cout <<ERROR<< "opertor+ ---> sumar V4"<<endl<<DEFAULT;
    }
    Polinomio *p1;
    p1 = new Polinomio;

    int Mayor_Grado=0;
    int Menor_Grado=0;

    if (p2->getGrado() > this->getGrado()){
        Mayor_Grado = p2->getGrado();
        Menor_Grado = this->getGrado();
    }
    else{
        Mayor_Grado = this->getGrado();
        Menor_Grado = this->getGrado();
    }


    for (int i=Mayor_Grado; i>=0; i--) {
        if (i<=Menor_Grado){
            p1->setCoeficiente_V3(i, (p2->getCoef(i) + this->getCoef(i)));
        }
        else{
            if (Mayor_Grado==p2->getGrado()){
                p1->setCoeficiente_V3(i, p2->getCoef(i));
            }
            else{
                p1->setCoeficiente_V3(i, this->getCoef(i));
            }
        }
    }
    
    
    return p1;
}

Polinomio& Polinomio::operator=(const Polinomio &p){

    if (this != &p){// por si pone p=p;

        this->inicializarPolinomio(); //ponemos el actual a 0

        for (int i=p.getGrado(); i>=0; i--){ //en principio podria usar el copiar que hice hace tiempo pero lo hare aparte
            this->setCoeficiente_V3(i, p.getCoef(i));
        }


    }

    return *this;


}

Polinomio* Polinomio::operator=(const Polinomio *p){

    if (this != p){// por si pone p=p;

        this->inicializarPolinomio(); //ponemos el actual a 0

        for (int i=p->getGrado(); i>=0; i--){ //en principio podria usar el copiar que hice hace tiempo pero lo hare aparte
            this->setCoeficiente_V3(i, p->getCoef(i));
        }

    }

    return this;

}


void Polinomio::inicializarPolinomio(){
    for (int i=0; i<=this->getGrado(); i++){
        this->setCoeficiente_V3(i, 0.0);
    }
}

int Polinomio::calcularGrado(){
    int grado=0;
    bool fin=false;
    for (int i=this->getGrado()-1; i>=0 && fin==false; i--){//buscamos el 2º mayor grado para sustituir al original (que ahora no tiene coef y no se tendra en cuenta)
        if (this->getCoef(i)!=0){
            grado=i; //cambiamos el grado
            fin=true;
        }

        else if (i==0){
            grado=i; //cambiamos el grado
        }

    }
    return grado;
}

/***************************************************************************************************************************************
*************************************************** -  VectorFloat - Definiciones  - ***************************************************
***************************************************************************************************************************************/


float* Polinomio::crear_vector_float (int dim){

    if (DEBUG_C_Polinomio){
        cout << DEBUG << "Inicio crear_vector_float"<<endl<<DEFAULT;
    }

    float*v = new float [dim];

    if (v==NULL){
        cout << "No hay memoria disponible" << endl;
        exit(1);
    }

    for (int i=0; i<dim; i++){
        v[i]=0.0;
    }

    if (DEBUG_C_Polinomio){
        cout << DEBUG << "Fin crear_vector_float"<<endl<<DEFAULT;
    }

    return v;
}

float* Polinomio::dropVectorFloat(float *v){

    if (DEBUG_C_Polinomio){
        cout << DEBUG << "Inicio dropVectorFloat"<<endl<<DEFAULT;
    }

    delete [] v;
    v=NULL;

    if (DEBUG_C_Polinomio){
        cout << DEBUG << "Fin dropVectorFloat"<<endl<<DEFAULT;
    }

    return v;
}


void Polinomio::copiarVectorFloatConEspacio (float v[], int util_v, float new_v[], int new_dim_v){
    
    
    int i=0;

    for (i=0; ((i<util_v) && (i<new_dim_v)); i++){
        new_v[i]=v[i];
    }

}



ostream& operator<<(ostream&flujo, const Polinomio &p){
    
    bool impresion=false;
    flujo << "p(x) = ";

    for (int i=p.getGrado(); i>=0; i--){

        if (p.getCoef(i)!=0){

            impresion=true;

            if (p.getCoef(i)>0){
                flujo <<"+ ";
            }

            if (p.getCoef(i)<0){
                flujo <<"- ";
            }

            flujo << abs(p.getCoef(i));

            if (i!=0){
                flujo<<"x^"<<i;
            }
            
            
            flujo<<" ";

        }
    }
    if (impresion==false){
        flujo << "No hay polinomio que mostrar";
    }  

    flujo << endl;

    if (DEBUG_C_Polinomio){
        flujo << DEBUG << "Grado de p(x): " << p.getGrado()<<endl;
        flujo << "Maximo grado de p(x): " << p.getMaxGrado()<<endl<<DEFAULT;
    }

    return flujo;
}

istream& operator>>(istream&flujo, Polinomio &p){

    int aux_i=0;
    float aux_f=0.0;

    cout << "Introduce el maximo grado del polinomio: ";
    flujo >> aux_i;

    for (; aux_i>=0; aux_i--){
        cout << "Introduce el coeficiente para el grado "<<aux_i<<": ";
        flujo >> aux_f;

        ///Posible filtro

        p.setCoeficiente_V3(aux_i, aux_f);

    }
    return flujo;
}

