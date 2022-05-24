#pragma once
#include "./DNI.hpp"
#include "./nodoAVL.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <queue>

template<class Clave>
class ArbolBB{
    
    protected:
    
        nodoAVL<Clave> *raiz;
        
        int nivel;
        
    public: 
    
        ArbolBB(int sz);
    
        ArbolBB();
        
        ~ArbolBB();
    
        nodoAVL<Clave>* Buscar(Clave& clave_dada);
        
        virtual void Insertar(Clave clave_dada) = 0;
        
        virtual void Eliminar(Clave clave_dada) = 0;
        
        //void sustituye(nodoBB<Clave>* &eliminado, nodoBB<Clave>* &sust);
        
        void write(ostream&);
        
        const int Alt();
        
        void n_niv();
        
        int get_niv();
        
    private:
    
        void Podar(nodoAVL<Clave>* &nodo);
        
        nodoAVL<Clave>* BuscarRama(nodoAVL<Clave>* nodo, Clave& clave_dada);
        
        void recorreN(nodoAVL<Clave>* raiz);
        
        //void InsertarRama(nodoBB<Clave>* &nodo, Clave clave_dada);
        
        //void EliminarRama(nodoBB<Clave>* &nodo, Clave clave_dada);
        
        //ostream& print(ostream&, nodoAVL<Clave>* &nodo, int& c, int& l, vector<vector<nodoAVL<Clave>* > >& p); 
        
        const int AltN(nodoAVL<Clave>* nodo);
};