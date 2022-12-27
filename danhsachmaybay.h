#ifndef __danhsachmaybay_h__
#define __danhsachmaybay_h__
#include"maybay.h"
#include<string>
using namespace std;

class danhsachmaybay
{
    private:
        MB *dau;
        static int sl_mb;
    public:
        danhsachmaybay();
        //~danhsachmaybay();
        void Tang_SlMB();
        void InpByFile(string name);

        maybay *Search(string id);
};
#endif
