#ifndef __QuanLiKhachHang_h__
#define __QuanLiKhachHang_h__
#include<string>
#include"Console.h"
using namespace std;
class KhachHang
{
    private:
        string CMND;
		string HovaTen;
		string Sex;//True:name-False:nu
        string PhoneNumber;
    public:
        KhachHang *next;
        void setCMND(string );
        void setHovTen(string );
        void SetSex(string );
        void setPhoneNumber(string );
        string getCMND();
        string getHovTen();
        string getSex();
        string getPhoneNumber();
};

class DanhSachKH
{
    private:
        KhachHang *dau;
        static int sl_KH;
    public:
        DanhSachKH(){dau = NULL;}
        void TangSl_KH();
        void InpByFile(string name);
        void InKH(string id, int i, int x, int y); // với id là CMND
        void InDS();
        string GetHoVaTenbyCMND(string CMND);
};
#endif
