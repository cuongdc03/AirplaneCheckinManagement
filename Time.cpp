#include"time.h"
using namespace std;
void Time::setIt(int m , int h, int d, int M, int y){
    this->phut = m;
    this->gio = h;
    this->ngay = d;
    this->thang = M;
    this->nam = y;
}
void Time::setGio(int h){
    this->gio = h;
}
void Time::setPhut(int m){
    this->phut = m;
}
void Time::setNgay(int d){
    this->ngay = d;
}
void Time::setThang(int m){
    this->thang = m;
}
void Time::setNam(int y){
    this->nam = y;
}

int Time::getPhut(){
    return phut;
}
int Time::getGio(){
    return gio;
}
int Time::getNgay(){
    return ngay;
}
int Time::getThang(){
    return thang;
}
int Time::getNam(){
    return nam;
}