#ifndef maybay_h
#define maybay_h
#include <iostream>
#include <string>
using namespace std;
class maybay
{
    private:
        string sohieumb;
		string loaimaybay;
		int socho;
		int soluot_bay;
		
    public:
		maybay *next;
        ~maybay();
		void setmb(string, string, int, int);
		void setSohieu(string);
		void setLoai(string);
		void setSoCho(string);
		void setSl_mb(string);
		string getSohieu();
		string getLoai();
		int getSoCho();
		int getsl_mb();

};
typedef class maybay MB;
#endif /* maybay_h */