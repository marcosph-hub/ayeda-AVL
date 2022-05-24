#include "../include/ArbolBB.hpp"

template<class Clave>
ArbolBB<Clave>::ArbolBB(int sz):raiz(NULL),nivel(0){}
//---------------------------------------------------------------------------------------------------
template<class Clave>
ArbolBB<Clave>::ArbolBB():raiz(NULL),nivel(0){}
//---------------------------------------------------------------------------------------------------
template<class Clave>
ArbolBB<Clave>::~ArbolBB(){Podar(raiz);}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void ArbolBB<Clave>::Podar(nodoAVL<Clave>* &nodo){
    if (nodo == NULL) return ;
        Podar(nodo->izdo); // Podar subarbol izquierdo
        Podar(nodo->dcho); // Podar subarbol derecho
        delete nodo; // Eliminar nodo
        nodo = NULL;
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
nodoAVL<Clave>* ArbolBB<Clave>::Buscar(Clave& clave_dada){
    return BuscarRama(raiz, clave_dada); 
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
nodoAVL<Clave>* ArbolBB<Clave>::BuscarRama(nodoAVL<Clave>* nodo, Clave& clave_dada){
    if (nodo == NULL){
        return NULL;
    }
    if (clave_dada == nodo->dato){
        return nodo;
    }
    if (clave_dada < nodo->dato){
        return BuscarRama(nodo->izdo, clave_dada);
    }
    
    return BuscarRama(nodo->dcho, clave_dada);
} 
//---------------------------------------------------------------------------------------------------
/*template<class Clave>
void ArbolBB<Clave>::Insertar(Clave clave_dada){
    InsertarRama(raiz, clave_dada); 
}*/
//---------------------------------------------------------------------------------------------------
/*template<class Clave>
void ArbolBB<Clave>::InsertarRama(nodoAVL<Clave>* &nodo, Clave clave_dada){
    if (nodo == NULL){
        nodo = new nodoAVL<Clave>(clave_dada);
    }
        else if (clave_dada < nodo->dato){
                InsertarRama(nodo->izdo, clave_dada);
        }
            else{
                InsertarRama(nodo->dcho, clave_dada);
            }
}*/
//---------------------------------------------------------------------------------------------------
/*template<class Clave>
void ArbolBB<Clave>::Eliminar(Clave clave_dada){
    EliminarRama(raiz, clave_dada); 
}*/
//---------------------------------------------------------------------------------------------------
/*template<class Clave>
void ArbolBB<Clave>::EliminarRama(nodoAVL<Clave>* &nodo, Clave clave_dada) {
    if (nodo == NULL){
        cout << "Error. Nodo inexistente." << endl;
        exit(1);
    }
    
    if (clave_dada < nodo->dato){
        EliminarRama(nodo->izdo, clave_dada);
    }
    
        else if (clave_dada > nodo->dato){
            EliminarRama(nodo->dcho, clave_dada);
        }
            else{//clave_dada == nodo_clave
                nodoAVL<Clave>* Eliminado = nodo;
                if (nodo->dcho == NULL){
                    nodo = nodo->izdo;
                }
                    else if (nodo->izdo == NULL){
                        nodo = nodo->dcho;
                    }
                        else{
                            sustituye(Eliminado, nodo->izdo);
                        }
                delete (Eliminado);
                }
}*/
//---------------------------------------------------------------------------------------------------
/*template<class Clave>
void ArbolBB<Clave>::sustituye(nodoAVL<Clave>* &eliminado, nodoAVL<Clave>* &sust) {
    if (sust->dcho != NULL){
        sustituye(eliminado, sust->dcho);
    }
        else {
            eliminado->dato = sust->dato;
            eliminado = sust;
            sust = sust->izdo;
        }
}*/
//---------------------------------------------------------------------------------------------------
template<class Clave>
void ArbolBB<Clave>::write(ostream& os){
    
    /*int c = 0;
    int l = 1;
     vector<  vector< nodoAVL<Clave>* > > p;
    p.resize(2);*/
    
    //print(os, raiz, c, l, p);
    recorreN(raiz);
}
//---------------------------------------------------------------------------------------------------
/*template<class Clave>
vector<unsigned long>& ArbolBB<Clave>::print(vector<unsigned long>& v, nodoAVL<Clave>* &nodo){

    
    if (nodo == NULL){ 
        unsigned long aux = 0;
        v.push_back(aux);
        return v;}
        else{
            v.push_back(nodo->dato);
        }
        print(v, nodo->izdo);
        print(v, nodo->dcho);

        return v;
}*/
//---------------------------------------------------------------------------------------------------
template<class Clave>
const int ArbolBB<Clave>::Alt(){ return AltN(raiz); }
//---------------------------------------------------------------------------------------------------
template<class Clave>
const int ArbolBB<Clave>::AltN(nodoAVL<Clave>* nodo){
    if(nodo == NULL){
        return 0;
    }
    int alt_i = AltN(nodo->izdo);
    int alt_d = AltN(nodo->dcho);
    if(alt_d > alt_i){
        return alt_d + 1;
    }
        else{
            return alt_i + 1;
        }
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void ArbolBB<Clave>::recorreN( nodoAVL<Clave>* raiz ) {
    
    queue<pair<nodoAVL<Clave>*, int> > Q;
    nodoAVL<Clave> *nodo;
    
    int nivel = 0;
    int Nivel_actual = 0;
    int temp = 1;
    
    Q.push({raiz, 0});
    
    while (!Q.empty()) {
        
        pair<nodoAVL<Clave>*, int> P;
        P = Q.front();
        
        nodo = P.first;
        nivel = P.second;
        
        Q.pop();
        
        
        if(temp == pow(2, nivel)){
             cout << "\n" << nivel  << ":" ;
        }
        
        if(nivel > Nivel_actual){
            
            Nivel_actual = nivel; 
        }
        
        if(nodo != NULL) {
            
            unsigned long aux = nodo->dato;
             cout << "[" << aux << "]";
            
            temp++;
            
            Q.push( make_pair(nodo->izdo, nivel+1));
            Q.push( make_pair(nodo->dcho, nivel+1));
        }
        else {
            
             cout << "[.]";
            temp++;

        }
    }
}