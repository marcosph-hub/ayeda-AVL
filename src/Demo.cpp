#include "../include/DNI.hpp"
#include "../include/ArbolBB.hpp"
#include "./ArbolBB.cpp"
#include "../include/AVL.hpp"
#include "./AVL.cpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <climits>

using namespace std;

int main (void){

    int option = 0;
    ArbolBB<DNI>* arbol = new AVL<DNI>;
    
    do{
        cout << "1.Insertar Clave" << endl;
        cout << "2.Eliminar Clave" << endl;
        cout << "0.Salir" << endl;
        cout << "\t>>> Introduzca una opcion: ";
        cin >> option;
        
        switch (option){
            
            case 1:
                {   
                    cout << "1. Insertar:" << endl;
                    int n1 = 0;
                    cout << "Clave: ";
                    cin >> n1;
                    cout << endl << endl;
                    cout << "Árbol: " << endl;
                    DNI dni(n1);
                    arbol->Insertar(dni);
                    arbol->write(cout);
                    cout << endl << endl;
                }
                break;
                
            case 2:

                {   
                    cout << "2. Eliminar:" << endl;
                    int n1 = 0;
                    cout << "Clave: ";
                    cin >> n1;
                    cout << endl << endl;
                    cout << "Árbol: " << endl;
                    DNI dni(n1);
                    arbol->Eliminar(dni);
                    arbol->write(cout);
                    cout << endl << endl;
                }
                break;
        }
            
    } while(option != 0);
    
}
