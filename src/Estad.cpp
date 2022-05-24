#include "DNI.hpp"
#include "ArbolBB.hpp"
#include "ArbolBB.cpp"
#include "AVL.hpp"
#include "AVL.cpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <climits>

using namespace std;

int main (void){

    int option = 0;
    ArbolBB<DNI>* arbol = new AVL<DNI>;
    
    int N, nPruebas, Min_1, Max_1, Min_2, Max_2;
    double Acu_1, Acu_F1, Acu_2, Acu_F2;
    
    //ESTADISTICO 
    cout << "Tamaño del árbol: " << endl;
    cin >> N;
    
    cout << "Número de pruebas: " << endl;
    cin >> nPruebas;
    cout << endl;
    
    vector<DNI> banco;
    
    srand(time(NULL));
    for (int i = 0; i < 2*N; i++){
        DNI dni;
        banco.push_back(dni);
    }
    
    for (int i = 0; i < N; i++) {
         arbol->Insertar(banco[i]);
    }
    
    Min_1 = INT_MAX;
    Acu_1 = 0;
    Max_1 = 0;
    //PRIMER EXPERIMENTO
    for (int i = 0; i < nPruebas; i++) {
        int j = rand()%N;
         arbol->Buscar(banco[j]);
        if(banco[j].get_cont() < Min_1){   Min_1 = banco[j].get_cont();}
        if(banco[j].get_cont() > Max_1){   Max_1 = banco[j].get_cont();}
        Acu_1 = Acu_1 + banco[j].get_cont();
    }
    Acu_F1 = static_cast<double>(Acu_1)/nPruebas;
    
    Min_2 = INT_MAX;
    Acu_2 = 0;
    Max_2 = 0;
    //SEGUNDO EXPERIMENTO
    for (int i = 0; i < nPruebas; i++) {
        int j = N + rand()%N;
         arbol->Buscar(banco[j]);
        if(banco[j].get_cont() < Min_2){   Min_2 = banco[j].get_cont();}
        if(banco[j].get_cont() > Max_2){   Max_2 = banco[j].get_cont();}
        Acu_2 = Acu_2 + banco[j].get_cont();
    }
    Acu_F2 = static_cast<double>(Acu_2)/nPruebas;
    
    cout << " \t\tMín " << "  |  " << " Acumulado " << "  |  " << " Máximo  " << endl;
    cout << "Búsqueda " << "\t" << Min_1 << "\t" << Acu_F1 << "\t\t" << Max_1 << endl;
    cout << "Inserción " << "\t" << Min_2 << "\t" << Acu_F2 << "\t\t" << Max_2 << endl;
    
    
    //MODIFICACION
/*    float Acu_P = 0;
    float Acu_PF = 0;
    int Min_P = INT_MAX;
    int Max_P = 0;
    for (int i = 0; i < nPruebas; i++) {
        ArbolBB<DNI> arbol_;
        vector<DNI> banco;
    
        for (int i = 0; i < 2*N; i++){
            DNI dni;
            banco.push_back(dni);
        }
        for (int i = 0; i < N; i++) {
            arbol_.Insertar(banco[i]);
        }
        if(arbol_.Alt() < Min_P){   Min_P = arbol_.Alt();}
        if(arbol_.Alt() > Max_P){   Max_P = arbol_.Alt();}
        Acu_P = Acu_P + arbol_.Alt();
    }
     Acu_PF = static_cast<double>(Acu_P)/nPruebas;
    
     cout << "Profundidad " << "\t" << Min_P << "\t" << Acu_PF << "\t\t" << Max_P << endl;*/
}
