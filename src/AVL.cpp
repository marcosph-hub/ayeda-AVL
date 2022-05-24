#include "../include/AVL.hpp"

template<class Clave>
AVL<Clave>::AVL(){
    
      ArbolBB<Clave>::raiz = NULL;
      ArbolBB<Clave>::nivel = 0;
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
AVL<Clave>::~AVL(){
    podar(ArbolBB<Clave>::raiz);
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::Insertar(Clave x){
    
    nodoAVL<Clave>* n_node = new nodoAVL<Clave>(x);
    bool crece = false;
    inserta_bal(ArbolBB<Clave>::raiz, n_node, crece);
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::inserta_bal( nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool &crece) {
    
    if (nodo == NULL){
     
        nodo = nuevo;
        crece = true;
        
    }else if (nuevo->dato < nodo->dato) {
        
        inserta_bal(nodo->izdo, nuevo, crece);
        
        if(crece) {insert_re_balancea_izdo(nodo, crece);}
        
    }else{
        
        inserta_bal(nodo-> dcho, nuevo, crece);
        
        if(crece) {insert_re_balancea_dcho(nodo, crece);}
    }
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::insert_re_balancea_izdo(nodoAVL<Clave>* &nodo, bool &crece) {
    
    switch (nodo->bal) {
        
        case -1:
            nodo->bal = 0;
            crece = false;
            break;
            
        case 0:
            nodo->bal = 1 ;
            break;
            
        case 1:
            nodoAVL<Clave>* nodo1 = nodo-> izdo;
            
            if (nodo1->bal == 1){
                rotacion_II(nodo);
            }else{
                rotacion_ID(nodo);
            }
            crece = false;
    }
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::insert_re_balancea_dcho(nodoAVL<Clave>* &nodo, bool &crece) {
    
    switch (nodo->bal){
        
        case 1:
            nodo->bal = 0;
            crece = false;
            break;
            
        case 0:
            nodo->bal = -1;
            break;
            
        case -1:
            nodoAVL<Clave>* nodo1 = nodo-> dcho;
            
            if (nodo1->bal == -1){
                rotacion_DD(nodo);
            } else{
                rotacion_DI(nodo);
            }
            crece = false;
    }
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::rotacion_II (nodoAVL<Clave>* &nodo) {
    
    nodoAVL<Clave>* nodo1 = nodo-> izdo;
    
    nodo-> izdo = nodo1-> dcho;
    nodo1-> dcho = nodo;
    
    if (nodo1->bal == 1) {
        nodo->bal = 0;
        nodo1->bal = 0;
    }
    else { // nodo1->bal == 0
        nodo->bal = 1;
        nodo1->bal = -1;
    }
    nodo = nodo1;
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::rotacion_ID (nodoAVL<Clave>* &nodo) {
    
    nodoAVL<Clave>* nodo1 = nodo-> izdo;
    nodoAVL<Clave>* nodo2 = nodo1-> dcho;
    
    nodo-> izdo = nodo2-> dcho;
    nodo2-> dcho = nodo;
    nodo1-> dcho = nodo2-> izdo;
    nodo2-> izdo = nodo1;
    
    if (nodo2->bal == -1){
        nodo1->bal = 1;
    } else{
        nodo1->bal = 0;
    }
    
    if (nodo2->bal == 1){
        nodo->bal = -1;
    } else{
        nodo->bal = 0;
    }
    
    nodo2->bal = 0;
    nodo = nodo2;
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::rotacion_DD(nodoAVL<Clave>* &nodo) {
    
    nodoAVL<Clave>* nodo1 = nodo-> dcho;
    
    nodo-> dcho = nodo1-> izdo;
    nodo1-> izdo = nodo ;
    
    if (nodo1->bal == -1) {
        nodo->bal = 0;
        nodo1->bal = 0;
    } else { // nodo1->bal == 0
        nodo->bal = -1;
        nodo1->bal = 1;
    }
    nodo = nodo1;
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::rotacion_DI (nodoAVL<Clave>* &nodo) {
    
    nodoAVL<Clave>* nodo1 = nodo->dcho;
    nodoAVL<Clave>* nodo2 = nodo1->izdo;
    
    nodo-> dcho = nodo2-> izdo;
    nodo2-> izdo = nodo;
    nodo1-> izdo = nodo2-> dcho;
    nodo2-> dcho = nodo1;
    
    if (nodo2->bal == 1){
        nodo1->bal = -1;
    }else{
        nodo1->bal = 0;
    }
    
    if (nodo2->bal == -1){
        nodo->bal = 1;
    }else{
        nodo->bal = 0;
    }
    nodo2->bal = 0;
    nodo = nodo2;
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::Eliminar(Clave x){
    
    bool decrece = false;
    eliminarRama(ArbolBB<Clave>::raiz, x, decrece);
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::eliminarRama(nodoAVL<Clave>* &nodo, Clave d, bool &decrece) {
    
    if (nodo == NULL){ cout << "Exeption" << endl; }
    
    if (d < nodo->dato){
        
        eliminarRama(nodo->izdo, d, decrece);
        
        if (decrece){
            eliminar_re_balancea_izdo(nodo,decrece);
        }
        
    } else if (d > nodo->dato){
        
        eliminarRama(nodo->dcho, d, decrece);
        
        if (decrece){
            eliminar_re_balancea_dcho(nodo,decrece);
        }
        
    } else { //d == nodo->dato
        
        nodoAVL<Clave>* Eliminado = nodo;
        
        if (nodo-> izdo == NULL){
            
            nodo = nodo-> dcho;
            decrece = true;
            
        } else if (nodo-> dcho == NULL){
        
            nodo = nodo-> izdo;
            decrece = true;
            
        } else{
            
            sustituye(Eliminado, nodo->izdo, decrece);
            
            if (decrece){
                eliminar_re_balancea_izdo(nodo,decrece);
            }
        }
        delete (Eliminado);
    }
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::sustituye(nodoAVL<Clave>* &eliminado, nodoAVL<Clave>* &sust, bool &decrece) {

    if (sust->dcho != NULL){
        
        sustituye(eliminado, sust->dcho, decrece);
        
        if (decrece){
            eliminar_re_balancea_dcho(sust, decrece);
        }
        
    }else{
        eliminado->dato = sust->dato;
        eliminado = sust;
        sust = sust->izdo;
        
        decrece = true;
    }
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::eliminar_re_balancea_izdo(nodoAVL<Clave>* &nodo, bool& decrece) {
    
    switch (nodo->bal){
        
        case -1:
            {
                nodoAVL<Clave>* nodo1 = nodo->dcho;
                
                if (nodo1->bal > 0){
                    rotacion_DI(nodo);
                } else {
                    if (nodo1->bal == 0){
                        decrece = false;
                    }
                    rotacion_DD(nodo);
                }
            }
            break;
            
        case 0:
            nodo->bal = -1;
            decrece = false;
            break;
            
        case 1:
            nodo->bal = 0;
    }
}
//---------------------------------------------------------------------------------------------------
template<class Clave>
void AVL<Clave>::eliminar_re_balancea_dcho(nodoAVL<Clave>* &nodo, bool& decrece) {
    
    switch (nodo->bal){
        
        case 1:
            {
                nodoAVL<Clave>* nodo1 = nodo->izdo;
                
                if (nodo1->bal < 0){
                    rotacion_ID(nodo);
                }else {
                    if (nodo1->bal == 0){
                        decrece = false;
                    }
                    rotacion_II(nodo);
                }
            }
            break ;
            
        case 0:
            nodo->bal = 1;
            decrece = false;
            break;
            
        case -1:
            nodo->bal = 0;
    }
}
