#pragma once
#include <iostream>

using namespace std;


template<class Clave>
class nodoAVL{

    public:
        // Miembros:
        Clave dato;
        nodoAVL<Clave> *izdo;
        nodoAVL<Clave> *dcho;
        int bal;
        
        // Constructor:
        nodoAVL(Clave dat, nodoAVL<Clave>* iz=NULL, nodoAVL<Clave>* de=NULL): 
        dato(dat), 
        izdo(iz), 
        dcho(de),
        bal(0){}
};