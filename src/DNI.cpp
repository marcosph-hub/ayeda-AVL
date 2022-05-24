#include "../include/DNI.hpp"

DNI::DNI(void){
    
    size = 8;
    for (int i = 0; i < size; i++) {
        if(i == 0){
            int aux = 1 + rand() % 9;
            v_.push_back(aux);
        }
        else{
            int aux = rand() % 10;
            v_.push_back(aux);
        }
    }
}
//-------------------------------------------------------------------------
DNI::DNI(int dni){
    vector<int> v_aux;
    while(dni>0){
   
        int aux = dni%10;
        dni = dni/10;
        v_aux.insert(v_aux.begin(), aux);
    }
    v_ = v_aux;
}
//-------------------------------------------------------------------------
DNI::~DNI(void){}
//-------------------------------------------------------------------------
void DNI::operator=(const DNI &dni_){
    this->v_ = dni_.v_;
    this->cont = dni_.cont;

}
//-------------------------------------------------------------------------
DNI::operator unsigned long() const{
    
    unsigned long aux = 0;
    
    for (long unsigned int i = 0; i < v_.size(); i++) {
        if(this->v_[i] != 0){
            aux += pow(10, v_.size()-i-1) * this->v_[i];
        }
    }
    return aux;
}
//-------------------------------------------------------------------------
bool DNI::operator==(const DNI &dni_){
    
    this->cont.incrementar();
        
    if(this->v_ == dni_.v_){
        return true;
    }
    return false;
}
//-------------------------------------------------------------------------
bool DNI::operator<(const DNI &dni_){
    
    this->cont.incrementar();
    
    unsigned long aux = 0;
    
    for (long unsigned int i = 0; i < this->v_.size(); i++) {
            aux += pow(10, this->v_.size()-i-1) * this->v_[i];
    }
    
    unsigned long aux_ = 0;
    
    for (long unsigned int i = 0; i < dni_.v_.size(); i++) {
            aux_ += pow(10, dni_.v_.size()-i-1) * dni_.v_[i];
    }
    
    
    if(aux < aux_){
        return true;
    }
    return false;
}
//-------------------------------------------------------------------------
bool DNI::operator>(const DNI &dni_){
    
    this->cont.incrementar();
    
    unsigned long aux = 0;
    
    for (long unsigned int i = 0; i < this->v_.size(); i++) {
            aux += pow(10, this->v_.size()-i-1) * this->v_[i];
    }
    
    unsigned long aux_ = 0;
    
    for (long unsigned int i = 0; i < dni_.v_.size(); i++) {
            aux_ += pow(10, dni_.v_.size()-i-1) * dni_.v_[i];
    }
    
    
    if(aux > aux_){
        return true;
    }
    return false;
}
//-------------------------------------------------------------------------
int DNI::get_cont(void){
    return this->cont.get_cont();
}