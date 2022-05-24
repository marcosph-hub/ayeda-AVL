#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <cstring>

using namespace std;

class Contador{
    
    private:
        
        int cont;
        
    public:
    
        Contador(void){
            cont = 0;
        }
        
        ~Contador(void){}
        
        void incrementar(void){
            cont = cont + 1;
        }
        
        int get_cont(void){
            return cont;
        }
        
};