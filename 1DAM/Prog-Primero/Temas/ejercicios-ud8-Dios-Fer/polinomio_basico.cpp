#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define OK "\033[1;32m"
#define DEBUG "\033[1;34m"

const bool DEBUG_C=true;



/*-------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  Polinomio  / -----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/

class Polinomio{
    private:

        ///Atributos

        float* coef; //vector de coeficientes del polinomio

        int grado_actual; //grado actual que tiene el polinomio

        int grado_max; //coincide con la DIM del VECTOR DE COEFICIENTES - 1



    public:

        ///Métodos


        /**************************************************************************************************************************************
        ************************************************************ -  Basicos  - ************************************************************
        **************************************************************************************************************************************/


        /**
         * @brief Constructor del objeto Polinomio: reserva por defecto un vector de coeficientes de dimensión 10, de tal manera que el máximo grado permitido será 9. Todos los coeficientes tendrán como valor 0.0. Y el grado_actual será por lo tanto 0.
         * @post El objeto Polinomio estará construido con la memoria del vector reservada y los valores por defecto.
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        Polinomio();


        /**
         * @brief Constructor del objeto Polinomio: creara un polinomio con los valores de otro
         * @param const Polinomio &p polinomio del que se quiere partir
         * @post El objeto Polinomio estará construido con con los mimos valores que el introducido
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        Polinomio(const Polinomio &p);

        /**
         * @brief Destructor del objeto Polinomio: reserva por defecto un vector de coeficientes de dimensión 10, de tal manera que el máximo grado permitido será 9. Todos los coeficientes tendrán como valor 0.0. Y el grado_actual será por lo tanto 0.
         * @post El objeto Polinomio se destruira junto a la reserva de memoria
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        ~Polinomio();


        /**************************************************************************************************************************************
        ************************************************************* -  GET'S  - *************************************************************
        **************************************************************************************************************************************/

    

        /**
         * @brief modulo (get) para el atributo grado_actual de un Polinomio
         * @return int grado_actual
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        int getGrado() const;

        /**
         * @brief modulo (get) para el atributo grado_max de un Polinomio
         * @return int grado_max
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        int getMaxGrado() const;

        /**
         * @brief modulo (get) para el atributo coef de un Polinomio en un grado especifico
         * @param int grado 
         * @return *coef
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        float getCoef(int grado) const;

        /**************************************************************************************************************************************
        ************************************************************* -  SET'S  - *************************************************************
        **************************************************************************************************************************************/
    private:
        /**
         * @brief modulo (set) para el atributo grado_actual de un Polinomio
         * @param int nuevo_grado
         * @pre el grado debe de ser positivo
         * @post se actualizara el grado_actual del polinomio
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void setGrado(int nuevo_grado);

        /**
         * @brief modulo (set) para el atributo grado_max de un Polinomio
         * @param int nuevo_grado_max
         * @post se actualizara el grado_max del polinomio
         * @date 2023-5-1
         * @version 0.1
         * @author DiosFer
         */
        void setMaxGrado(int nuevo_grado_max);


    public:

        /**
         * @brief modulo (set) para el coeficiente indicando el grado donde se introducira
         * @param int grado
         * @param float coeficiente
         * @post en la posicion grado del vector se habra introducido el coeficiente
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void setCoeficiente_V2(int grado, float coeficiente);


        /**
         * @brief modulo (set) para el coeficiente indicando el grado donde se introducira
         * @param int grado
         * @param float coeficiente
         * @post en la posicion grado del vector se habra introducido el coeficiente
         * @date 2023-5-16
         * @version 1.2
         * @author DiosFer
         */
        void setCoeficiente_V3(int grado, float coeficiente);

        
        /**************************************************************************************************************************************
        ************************************************************* -  FRONT  - *************************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para imprimir por pantalla
         * @post se imprimira por pantalla el objeto
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        //void print() const;

        /**
         * @brief modulo para introducir un polinomio
         * @post guardara lo introducido en el objeto
         * @date 2023-5-2
         * @version 0.2
         * @author DiosFer
         */
        void introducir();

        /**************************************************************************************************************************************
        ************************************************************* -  BACK  - **************************************************************
        **************************************************************************************************************************************/
    private:

        /**
         * @brief modulo para redimensionar el atributo vector coef
         * @post se mantendran los mismos datos del vector pero con una dimension (y maxgrado) aumentada
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void resize_Coef(int new_dim);


        public:

        /**
         * @brief modulo para copiar en este polinomio otro polinomio introducido
         * @post se obtendra un polinomio exactamente igual que el introducido 
         * @param Polinomio *p
         * @date 2023-5-6
         * @version 0.5
         * @author DiosFer
         */
        void CopiarPolinomio(Polinomio *p);


        
        /**
         * @brief modulo para sumar dos polinomios y guardar el resultado en el que hace la llamada                             ///V1
         * @pre grado=maxGrado (uso de la v3 en los sets) 
         * @post se modificara el polinomio a la solucion, perdiendo el polinomio original 
         * @param const Polinomio &p2
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        void sumar(const Polinomio &p2);


        /**
         * @brief modulo para sumar dos polinomios externos y guardar el resultado en el que hace la llamada                    ///V2
         * @pre el polinomio estara vacio
         * @post se modificara el polinomio a la solucion, perdiendo el polinomio original 
         * @param const Polinomio &p2
         * @param const Polinomio &p3
         * @date 2023-5-9
         * @version 0.7
         * @author DiosFer
         */
        void sumar(const Polinomio &p2,const Polinomio &p3);



        /**
         * @brief modulo para sumar un polinomio y otro externo y dar el resultado                                              ///V3
         * @post se dara el resultado 
         * @post se mantendran los polinomios intactos
         * @param const Polinomio &p2
         * @return polinomio
         * @date 2023-5-14
         * @version 0.9.1
         * @author DiosFer
         */
        Polinomio operator+(const Polinomio &p2);

        /**
         * @brief modulo para sumar un polinomio por puntero y otro polinomio por puntero y dar un puntero de polinomio         ///V4
         * @post se dara el resultado 
         * @post se mantendran los polinomios intactos
         * @param const Polinomio &p2
         * @return polinomio*
         * @date 2023-5-14
         * @version 0.9.1
         * @author DiosFer
         */
        Polinomio* operator+(const Polinomio *p2);


        /**
         * @brief modulo para igualar un polinomio a otro
         * @post el Polinomio que realice la llamada tomara los valores del que se iguale 
         * @return Polinomio&
         * @param const Polinomio &p
         * @date 2023-5-15
         * @version 1.1
         * @author DiosFer
         */
        Polinomio& operator=(const Polinomio &p);


        /**
         * @brief modulo para igualar un polinomio a otro
         * @post el Polinomio que realice la llamada tomara los valores del que se iguale 
         * @return Polinomio*
         * @param const Polinomio *p
         * @date 2023-5-15
         * @version 1.1
         * @author DiosFer
         */
        Polinomio* operator=(const Polinomio *p);

        /**
         * @brief modulo para inicializar a 0 un polinomio
         * @post se pondran los coeficientes, grado y max_grado a 0 (con el redimensionamiento adecuado)
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        void inicializarPolinomio();


    private:

        /**
         * @brief modulo para buscar el nuevo grado mas grande de un vector de coeficientes
         * @return int grado
         * @date 2023-5-8
         * @version 0.6
         * @author DiosFer
         */
        int calcularGrado();


        /**************************************************************************************************************************************
        ***************************************************** -  VectorFloat-Prototipos  - ****************************************************
        **************************************************************************************************************************************/

        /**
         * @brief modulo para crear un vector de float con una dimension concreta
         * @post se reservara la memoria del vector en el heap
         * @return float* 
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        float* crear_vector_float (int dim);


        /**
         * @brief modulo para elimniar un vector float 
         * @post se limpiara la memoria reservada y se anulara el puntero
         * @return float* 
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        float* dropVectorFloat(float *v);

        /**
         * @brief modulo para copiar un vcetor de float (solo en caso de caber en el vector (util_copiado<dim_copia))
         * @post se copiaran los paramtros de v* en new_v*
         * @date 2023-5-3
         * @version 0.3
         * @author DiosFer
         */
        void copiarVectorFloatConEspacio (float v[], int util_v, float new_v[], int new_dim_v);
                
        /**
         * @brief modulo (frien) para la salida de un polinomio por medio de un cout
         * @post se mostrara por pantalla el polinomio en su posicion de cout
         * @date 2023-5-15
         * @version 1.1
         * @author DiosFer
         */
        friend ostream& operator<<(ostream&flujo, const Polinomio &p);

        /**
         * @brief modulo (frien) para la entrada de un polinomio
         * @post guardara lo introducido en el polinomio 
         * @date 2023-5-16
         * @version 1.2
         * @author DiosFer
         */
        friend istream& operator>>(istream&flujo, Polinomio &p);

};



/*-------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------- /  Polinomio  / -----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/




/**************************************************************************************************************************************
************************************************************ -  Basicos  - ************************************************************
**************************************************************************************************************************************/

Polinomio::Polinomio (){//automatico cuando se declara el polimio
    //Aquí dentro se asigna el puntero this

    int dim_ini_coef=10;

    if (DEBUG_C){
        cout << DEBUG <<  "Se invoca al Constructor Polinomio." << " La dirección de this es: " << this << DEFAULT << endl;
    }

    this->coef=crear_vector_float (dim_ini_coef);


    setMaxGrado(dim_ini_coef-1);
    setGrado(0);


    if (DEBUG_C){
        cout << DEBUG <<  "Fin invocacion del Constructor Polinomio." << " La dirección de this es: " << this << DEFAULT << endl;
    }

}

Polinomio::Polinomio (const Polinomio &p){

    int dim_ini_coef=10;

    if (DEBUG_C){
        cout << DEBUG <<  "Se invoca al Constructor Polinomio por copia." << " La dirección de this es: " << this << DEFAULT << endl;
    }


    setMaxGrado(p.getGrado());
    setGrado(0);

    this->coef= new float[p.getGrado()];

    for (int i=p.getGrado(); i>=0; i--) {
        this->setCoeficiente_V3(i, p.getCoef(i));
    }



    if (DEBUG_C){
        cout << DEBUG <<  "Fin invocacion del Constructor Polinomio por copia." << " La dirección de this es: " << this << DEFAULT << endl;
    }

}

Polinomio::~Polinomio(){
    if (DEBUG_C){
        cout << DEBUG <<  "Se invoca al Destructor del Polinomio." << " La dirección de this es: " << this << DEFAULT << endl;
    }

    this->coef=dropVectorFloat(this->coef);

    if (DEBUG_C){
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

    if (DEBUG_C){
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

            if (DEBUG_C){
                cout <<DEBUG<< "Actualizando la dim para que se ajuste al grado" << DEFAULT<<endl;
            }

            this->resize_Coef(this->getGrado()+1);//Este resize se mueve con las utiles asi que es totalmente valido para este caso en el que queremos grado=maxGrado, en caso de tener que recortar el vector y que maxGrado < grado_antiguo(ahoraElimiNado) se tendria que reprogramar
            this->setMaxGrado(this->getGrado());

            if (DEBUG_C){
                cout <<DEBUG<<DEBUG<< "Resize para ajustar al grado COMPLETADO" <<DEFAULT<<endl;
            }

        }

    }

    
}



/**************************************************************************************************************************************
************************************************************* -  FRONT  - *************************************************************
**************************************************************************************************************************************/

/*
void Polinomio::print() const{
    bool impresion=false;
    cout << "p(x) = ";

    for (int i=getGrado(); i>=0; i--){

        if (getCoef(i)!=0){

            impresion=true;

            if (getCoef(i)>0){
                cout <<"+ ";
            }

            if (getCoef(i)<0){
                cout <<"- ";
            }

            cout << abs(getCoef(i));

            if (i!=0){
                cout<<"x^"<<i;
            }
            
            
            cout<<" ";

        }
    }
    if (impresion==false){
        cout << "No hay polinomio que mostrar";
    }  

    cout << endl;

    if (DEBUG_C){
        cout << DEBUG << "Grado de p(x): " << this->getGrado()<<endl;
        cout << "Maximo grado de p(x): " << this->getMaxGrado()<<endl<<DEFAULT;
    }

}
*/
/*
void Polinomio::introducir(){

    int aux_i=0;
    float aux_f=0.0;

    cout << "Introduce el maximo grado del polinomio: ";
    cin >> aux_i;

    for (; aux_i>=0; aux_i--){
        cout << "Introduce el coeficiente para el grado "<<aux_i<<": ";
        cin >> aux_f;

        ///Posible filtro

        setCoeficiente_V3(aux_i, aux_f);

    }

}
*/


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
    if (DEBUG_C){
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
    if (DEBUG_C){
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

    if (DEBUG_C){
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

    if (DEBUG_C){
        cout << DEBUG << "Fin crear_vector_float"<<endl<<DEFAULT;
    }

    return v;
}

float* Polinomio::dropVectorFloat(float *v){

    if (DEBUG_C){
        cout << DEBUG << "Inicio dropVectorFloat"<<endl<<DEFAULT;
    }

    delete [] v;
    v=NULL;

    if (DEBUG_C){
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

    if (DEBUG_C){
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




void Polinomio::introducir(){

    int aux_i=0;
    float aux_f=0.0;

    cout << "Introduce el maximo grado del polinomio: ";
    cin >> aux_i;

    for (; aux_i>=0; aux_i--){
        cout << "Introduce el coeficiente para el grado "<<aux_i<<": ";
        cin >> aux_f;

        ///Posible filtro

        setCoeficiente_V3(aux_i, aux_f);

    }

}


/*************************************************************************************************************************************
------------------------------------------------------------- *  Main  * -------------------------------------------------------------
**************************************************************************************************************************************/



int main(){

    Polinomio p1, p2, res;

    cout << "Inserte el polinomio 1"<<endl;
    cin >> p1;
    cout << p1;

    cout << "Inserte el polinomio 2"<<endl;
    cin >> p2;
    cout << p2;


    res = p1 + p2;
    cout<< "El resultado de la suma entre los dos polinomios es:   " << endl <<res;



    /*
    //Declaraciones
    Polinomio *p1 = new Polinomio(); //aquí invoca al constructor por defecto
    Polinomio *p2 = new Polinomio();
    Polinomio *res = new Polinomio();
    
    Polinomio p3;
    Polinomio p4;

    Polinomio resultado;

    ///////////////


    // //Caso 1
    //p1(x) = 7x^2 + 3x
    //p2(x) = 4x^4 + 3x^2 + 3
     //Esperado --> p3 = 4x^4 + 10x^2 + 3x + 3

    p3.setCoeficiente_V3(4, 4);
    p3.setCoeficiente_V3(2, 3);
    p3.setCoeficiente_V3(0, 3);

    p4.setCoeficiente_V3(2, 7);
    p4.setCoeficiente_V3(1, 3);

    ///////////////


    p1->setCoeficiente_V3(4, 4);
    p1->setCoeficiente_V3(2, 3);
    p1->setCoeficiente_V3(0, 3);

    p2->setCoeficiente_V3(2, 7);
    p2->setCoeficiente_V3(1, 3);

    ///////////////

    cout <<endl<< "Sumar V3 (operator+)"<<endl;
    cout << "Caso de prueba 1 --> p_res(x)=4x^4 + 10x^2 + 3x + 3"<<endl;
    resultado=p3+p4;
    cout << resultado;



    cout <<endl<< "Sumar V4 (operator+)"<<endl;
    cout << "Caso de prueba 1 --> p_res(x)=4x^4 + 10x^2 + 3x + 3"<<endl;

    res=*p1+p2;

    cout << *res;

    ///////////////

    //todo a 0
    p3.inicializarPolinomio();
    p4.inicializarPolinomio();
    resultado.inicializarPolinomio();
    p1->inicializarPolinomio();
    p2->inicializarPolinomio();
    res->inicializarPolinomio();

    cout << endl<<endl;

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



     //Caso 2
    //p1(x) = 4x^4 + 3x^2 + 3
    //p2(x) = 7x^2 + 3x
     //Esperado --> p3 = 4x^4 + 10x^2 + 3x + 3



    p4.setCoeficiente_V3(4, 4);
    p4.setCoeficiente_V3(2, 3);
    p4.setCoeficiente_V3(0, 3);

    p3.setCoeficiente_V3(2, 7);
    p3.setCoeficiente_V3(1, 3);

    ///////////////

    p1->setCoeficiente_V3(4, 4);
    p1->setCoeficiente_V3(2, 3);
    p1->setCoeficiente_V3(0, 3);

    p2->setCoeficiente_V3(2, 7);
    p2->setCoeficiente_V3(1, 3);


    ///////////////

    cout <<endl<< "Sumar V3 (operator+)"<<endl;
    cout << "Caso de prueba 2 --> p_res(x)=4x^4 + 10x^2 + 3x + 3"<<endl;
    resultado=p3+p4;
    cout << resultado;



    cout <<endl<< "Sumar V4 (operator+)"<<endl;
    cout << "Caso de prueba 2 --> p_res(x)=4x^4 + 10x^2 + 3x + 3"<<endl;

    res=*p1+p2;

    cout << *res;
    
    ///////////////

    //todo a 0
    p3.inicializarPolinomio();
    p4.inicializarPolinomio();
    resultado.inicializarPolinomio();
    p1->inicializarPolinomio();
    p2->inicializarPolinomio();
    res->inicializarPolinomio();

    cout << endl<<endl;

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



     //Caso 3
    //p1(x) = 4x^4 + 3x^2 + 3
    //p2(x) = 7x^4 + 3x - 3
     //Esperado --> p3 = 11x^4 + 3x^2 + 3x


    p3.setCoeficiente_V3(4, 4);
    p3.setCoeficiente_V3(2, 3);
    p3.setCoeficiente_V3(0, 3);

    p4.setCoeficiente_V3(4, 7);
    p4.setCoeficiente_V3(1, 3);
    p4.setCoeficiente_V3(0, -3);

    ///////////////

    p1->setCoeficiente_V3(4, 4);
    p1->setCoeficiente_V3(2, 3);
    p1->setCoeficiente_V3(0, 3);

    p2->setCoeficiente_V3(4, 7);
    p2->setCoeficiente_V3(1, 3);
    p2->setCoeficiente_V3(0, -3);


    ///////////////


    cout <<endl<< "Sumar V3 (operator+)"<<endl;
    cout << "Caso de prueba 3 --> p_res(x)=11x^4 + 3x^2 + 3x"<<endl;
    resultado=p3+p4;
    cout << resultado;



    cout <<endl<< "Sumar V4 (operator+)"<<endl;
    cout << "Caso de prueba 3 --> p_res(x)=11x^4 + 3x^2 + 3x"<<endl;

    res=*p1+p2;

    cout << *res;
    
    ///////////////

    //todo a 0
    p3.inicializarPolinomio();
    p4.inicializarPolinomio();
    resultado.inicializarPolinomio();
    p1->inicializarPolinomio();
    p2->inicializarPolinomio();
    res->inicializarPolinomio();

    cout << endl<<endl;



    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



     //Caso 4
    //p1(x) = 4x^4 + 3x^2 + 3
    //p2(x) = -4x^4 + 3x - 3
     //Esperado --> p3 = 3x^2 + 3x

    p3.setCoeficiente_V3(4, 4);
    p3.setCoeficiente_V3(2, 3);
    p3.setCoeficiente_V3(0, 3);

    p4.setCoeficiente_V3(4, -4);
    p4.setCoeficiente_V3(1, 3);
    p4.setCoeficiente_V3(0, -3);

    ///////////////

    p1->setCoeficiente_V3(4, 4);
    p1->setCoeficiente_V3(2, 3);
    p1->setCoeficiente_V3(0, 3);

    p2->setCoeficiente_V3(4, -4);
    p2->setCoeficiente_V3(1, 3);
    p2->setCoeficiente_V3(0, -3);



    ///////////////

    cout <<endl<< "Sumar V3 (operator+)"<<endl;
    cout << "Caso de prueba 4 --> p_res(x)=3x^2 + 3x"<<endl;
    resultado=p3+p4;
    cout << resultado;



    cout <<endl<< "Sumar V4 (operator+)"<<endl;
    cout << "Caso de prueba 4 --> p_res(x)=3x^2 + 3x"<<endl;

    res=*p1+p2;

    cout << *res;
    
    ///////////////

    //todo a 0
    p3.inicializarPolinomio();
    p4.inicializarPolinomio();
    resultado.inicializarPolinomio();
    p1->inicializarPolinomio();
    p2->inicializarPolinomio();
    res->inicializarPolinomio();

    cout << endl<<endl;


    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



     //Caso 5
    //p1(x) = 4x^4 + 3x^2 + 3
    //p2(x) = -4x^4 - 3x^2 - 3
     //Esperado --> p3 = 0 (nulo) (warning al imprimir)


    p3.setCoeficiente_V3(4, 4);
    p3.setCoeficiente_V3(2, 3);
    p3.setCoeficiente_V3(0, 3);


    p4.setCoeficiente_V3(4, -4);
    p4.setCoeficiente_V3(2, -3);
    p4.setCoeficiente_V3(0, -3);

    ///////////////

    p1->setCoeficiente_V3(4, 4);
    p1->setCoeficiente_V3(2, 3);
    p1->setCoeficiente_V3(0, 3);


    p2->setCoeficiente_V3(4, -4);
    p2->setCoeficiente_V3(2, -3);
    p2->setCoeficiente_V3(0, -3);


    ///////////////

    cout <<endl<< "Sumar V3 (operator+)"<<endl;
    cout << "Caso de prueba 5 --> p_res(x) = 0 (nulo) (warning al imprimir)"<<endl;
    resultado=p3+p4;
    cout << resultado;



    cout <<endl<< "Sumar V4 (operator+)"<<endl;
    cout << "Caso de prueba 5 --> p_res(x) = 0 (nulo) (warning al imprimir)"<<endl;

    res=*p1+p2;

    cout << *res;
    
    ///////////////

    //todo a 0
    p3.inicializarPolinomio();
    p4.inicializarPolinomio();
    resultado.inicializarPolinomio();
    p1->inicializarPolinomio();
    p2->inicializarPolinomio();
    res->inicializarPolinomio();

    cout << endl<<endl;

    
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    //Eliminamos lo dinamico
    delete p1;
    delete p2;
    delete res;

    //Se elimina automatico lo estatico
    */


}



/*************************************************************************************************************************************
------------------------------------------------------------- *  Main  * -------------------------------------------------------------
**************************************************************************************************************************************/


