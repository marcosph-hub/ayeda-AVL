#pragma once

#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

#include "./ArbolBB.hpp"

template<class Clave>
class AVL: public ArbolBB<Clave> {
    
    public:
    
        AVL();
        
        ~AVL();
        
        void Insertar(Clave x);
        
        void inserta_bal(nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool &crece);
        
        void insert_re_balancea_izdo(nodoAVL<Clave>* &nodo, bool &crece);
        
        void insert_re_balancea_dcho(nodoAVL<Clave>* &nodo, bool &crece);
        
        void Eliminar(Clave x);
        
        void eliminarRama(nodoAVL<Clave>* &nodo, Clave, bool &decrece);
        
        void eliminar_re_balancea_dcho(nodoAVL<Clave>* &nodo, bool& decrece);
        
        void eliminar_re_balancea_izdo(nodoAVL<Clave>* &nodo, bool& decrece);
        
        
    private:
        
        void sustituye(nodoAVL<Clave>* &eliminado, nodoAVL<Clave>* &sust, bool &decrece);
        
        void rotacion_II (nodoAVL<Clave>* &nodo);
        
        void rotacion_ID (nodoAVL<Clave>* &nodo);
        
        void rotacion_DD (nodoAVL<Clave>* &nodo);
        
        void rotacion_DI (nodoAVL<Clave>* &nodo);

};