#include "QuanLiKhachHang.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
// Cac ham trong class khachhang
void KhachHang::setCMND(string cmnd)
{
    this->CMND = cmnd;
}
void KhachHang::setHovTen(string hoten)
{
    this->HovaTen = hoten;
}
void KhachHang::SetSex(string sex)
{
    this->Sex = sex;
}
void KhachHang::setPhoneNumber(string number)
{
    this->PhoneNumber = number;
}

string KhachHang::getCMND()
{
    return CMND;
}
string KhachHang::getHovTen()
{
    return HovaTen;
}
string KhachHang::getSex()
{
    return Sex;
}
string KhachHang::getPhoneNumber()
{
    return PhoneNumber;
}

int DanhSachKH::sl_KH = 0;
void DanhSachKH::TangSl_KH()
{
    ++sl_KH;
}
void DanhSachKH::InpByFile(string name)
{
    KhachHang *hientai;
    std::ifstream input(name);
    string line;
    int rows, cols, i;
    cols = 5;
    for (rows = 0; getline(input, line); ++rows)
    {
        if (dau == NULL)
        {
            dau = new KhachHang;
            hientai = dau;
        }
        else
        {
            hientai->next = new KhachHang;
            hientai = hientai->next;
        }
        i = 1;
        string element = "";
        for (int t = 0; t < line.length(); ++t)
        {
            if (line[t] != ' ')
            {
                element += line[t];
            }
            else if (line[t] == ' ')
            {
                if (i == 1)
                    hientai->setCMND(element);
                else if (i == 2)
                    hientai->setHovTen(element);
                else if (i == 3)
                    hientai->SetSex(element);
                else if (i == 4)
                    hientai->setPhoneNumber(element);
                else
                    break;
                element = "";
                while (line[t] == ' ')
                {
                    t++;
                }

                t--;
                i++;
            }
        }

        TangSl_KH();
    }
}

void DanhSachKH::InKH(string id, int i,int x, int y)
{
    // int x = 10,y=3;
    if (dau == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    KhachHang *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getCMND() == id)
        {
            setColor(8);
            gotoXY(x,y+2+i); cout << char(179);
            gotoXY(x+3,y+2+i); cout << char(179);
            gotoXY(x+14,y+2+i); cout << char(179);
            gotoXY(x+34,y+2+i); cout << char(179);
            gotoXY(x+38,y+2+i); cout << char(179);
            gotoXY(x+50,y+2+i); cout << char(179);
            setColor(7);
            gotoXY(x+1,y+2+i); cout << i;
            gotoXY(x+4,y+2+i); cout << hientai->getCMND();
            gotoXY(x+15,y+2+i); cout << hientai->getHovTen();
            gotoXY(x+35,y+2+i); cout << hientai->getSex();
            gotoXY(x+39,y+2+i); cout << hientai->getPhoneNumber();
            //cout << setw(10)<<hientai->getCMND() <<setw(20)<< hientai->getHovTen() <<setw(20)<< hientai->getSex() <<setw(15)<< hientai->getPhoneNumber() <<setw(5)<<endl;
            return;
        }
        hientai = hientai->next;
    }
    if (i == 0)
        cout << "Khach hang co CMND " << id << " khong ton tai!" << endl;
}
void DanhSachKH::InDS()
{
    if (dau == NULL)
    {
        cout << "Danh sach bi trong!" << endl;
        return;
    }
    cout << setw(9) << "CustomerID" << setw(30) << "Full Name" << setw(30) << "Gender" << setw(30)<<"Phone Number"<<endl;
    KhachHang *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        cout << hientai->getCMND() << setw(30) << hientai->getHovTen() << setw(30) << hientai->getSex() << setw(30)<<hientai->getPhoneNumber()<<endl;
        hientai = hientai->next;
    }
    cout << "Customer Amount:"<<sl_KH << endl;
}
string DanhSachKH::GetHoVaTenbyCMND(string CMND)
{
    if (dau == NULL)
    {
        cout << "Empty List" << endl;
        return "";
    }
    KhachHang *hientai;
    hientai = dau;
    int i = 0;
    while (hientai != NULL)
    {
        if (hientai->getCMND() == CMND)
        {
            i = 1;
            return hientai->getHovTen();
        }
        hientai = hientai->next;
    }
}