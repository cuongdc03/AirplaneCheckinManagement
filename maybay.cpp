#include "maybay.h"
#include <string>
#include <fstream>
#include <sstream>
void maybay::setmb(string sohieu, string loai, int cho, int sl){
    this->sohieumb = sohieu; 
    this->loaimaybay = loai;
    this->socho = cho; // choox
    this->soluot_bay = sl;
}

void maybay::setSohieu(string sohieu){
    this->sohieumb = sohieu; 
}
void maybay::setLoai(string loai){
    this->loaimaybay = loai;
}
void maybay::setSoCho(string cho){
	stringstream str2num(cho);
    int x = 0;
    str2num >> x;
    this->socho = x;
}
void maybay::setSl_mb(string sl){
    stringstream str2num(sl);
    int x = 0;
    str2num >> x;
    this->soluot_bay = x;
}

string maybay::getSohieu(){
    return sohieumb;
}
string maybay::getLoai(){
    return loaimaybay;
}
int maybay::getSoCho(){
    return socho;
}
int maybay::getsl_mb(){
    return soluot_bay;
}
maybay::~maybay(){
    
}