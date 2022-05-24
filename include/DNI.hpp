#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <cstring>

#include "./Contador.hpp"

using namespace std;

class DNI{
    
    private:
        
        vector<int> v_;
        
        int size;
        
        Contador cont;
        
    public:
    
        DNI(void);
        
        DNI(int dni);
        
        ~DNI(void);
        
         void operator=(const DNI &dni_);
         
         bool operator<(const DNI &dni_);
         
         bool operator>(const DNI &dni_);
         
         bool operator==(const DNI &dni_);
         
         operator unsigned long() const;
         
         int get_cont(void);
};