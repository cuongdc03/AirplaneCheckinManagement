#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Chuyenbay.h"

#include <iomanip>
using namespace std;
// hàm chuyển đổi từ chuỗi sang số nguyên
int ChuyenDoi(string a)
{
    stringstream str2num(a);
    int x = 0;
    str2num >> x;
    return x;
}
// hàm trả ra row
int Chuyenbay::get_row(string seat){
    switch (seat[0])
    {
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'C':
            return 3;
        case 'D':
            return 5;
        case 'E':
            return 6;   
        case 'F':
            return 7;  
        default:
            break;
    }
}

void Chuyenbay::setMaCB(string ma)
{
    this->MaCB = ma;
}
void Chuyenbay::setNoiDen(string noi)
{
    this->NoiDen = noi;
}
void Chuyenbay::setSl_hk(int n)
{
    this->sl_hk = n;
}

string Chuyenbay::getMaCB()
{
    return MaCB;
}
string Chuyenbay::getNoiDen()
{
    return NoiDen;
}
int Chuyenbay::getSl_hk()
{
    return sl_hk;
}
Chuyenbay::~Chuyenbay() {}

string DanhSachChuyenBay::getnoiden(string id)
{   
    Chuyenbay *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == id)
            return hientai->getNoiDen();
        hientai = hientai->next;
    }
    return "";
}
string DanhSachChuyenBay::getdate(string id)
{
    Chuyenbay *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == id)
            return to_string(hientai->getNgay()) + "/" + to_string(hientai->getThang()) + "/" + to_string(hientai->getNam());
        hientai = hientai->next;
    }
    return "";
}
string DanhSachChuyenBay::gettime(string id)
{
    Chuyenbay *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == id)
            return to_string(hientai->getGio()) + ":" + to_string(hientai->getPhut());
        hientai = hientai->next;
    }
    return "";
}
void Chuyenbay::set_map_seat(){
    int n = 8, m = 80;
    map_seat = new long *[n];
    for (int i=0;i<n;i++)    map_seat[i]= new long [m];

    // hàm khởi tạo map_seat
    int j = 1;
    int c = 0;
    for (int i = 0; i < 77; i++)
    {
        if (i < 12 && i % 3 == 0)
            map_seat[0][i] = 0;
        else if (i < 12 && i % 3 == 1)
            map_seat[0][i] = j++;
        else if (i > 11 && i < 25 && i % 3 == 1)
            map_seat[0][i] = 0;
        else if (i > 11 && i < 25 && i % 3 == 2)
            map_seat[0][i] = j++;
        else if (i > 28 && i < 50 && i % 3 == 2)
            map_seat[0][i] = 1;
        else if (i > 26 && i < 50 && i % 3 == 0)
            map_seat[0][i] = j++;
        else if (i > 50 && i < 60 && i % 3 == 0)
            map_seat[0][i] = 1;
        else if (i > 57 && i % 3 == 0)
            map_seat[0][i] = 2;
        else if (i > 50 && i % 3 == 1)
            map_seat[0][i] = j++;
        else
            map_seat[0][i] = -1;
        if (j == 10)
            j = 0;
    }
    for(int i = 1; i < 8; i++) map_seat[i][0] = 0;
    map_seat[0][26] = 0;
}

int Chuyenbay::set_seat(string seat, long cmnd){
    int row, collum1, collum2;
    row = get_row(seat);
    collum1 = seat[1] - '0';
    collum2 = seat[2] - '0';
    int i = 0;
    for (i; i < 77; i++)
    {
        if (map_seat[0][i] == collum1 && map_seat[0][i + 1] == collum2)
            break;
    }
    map_seat[row][i] = 1;
    map_seat[row][i + 1] = cmnd;
    return i;
}

void Chuyenbay::set_seated_onboard(long cmnd){
    setColor(2);
    int row, collum;
    int x=8,y=21;
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < 80; j++){
            if(map_seat[i][j] == 1 && map_seat[i][j+1] == cmnd){
                map_seat[i][j] = 2;
                row = x+7+j;
                collum = y+i-15;
                gotoXY(row, collum ); cout << char(254) << char(254);
                return;
            }
        }
    }
}


int Chuyenbay::check_seat_already(string seat){
    int row = get_row(seat);
    int collum1 = seat[1] - '0';
    int collum2 = seat[2] - '0';
    int i = 0;
    for(i; i < 80; i++){
        if(map_seat[0][i] == collum1 && map_seat[0][i+1] == collum2) break;
    }
    if(map_seat[row][i] == 0) return 1;
    return 0;
}

void Chuyenbay::set_color_seat_checkin(int x, int y){
    setColor(4);
    int c = 1, row, collum;
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < 80; j++){
            if(map_seat[i][j] == 1){
                row = x+7+j;
                collum = y+i-15;
                gotoXY(row, collum ); cout << char(254) << char(254);
            }
        }
    }
    setColor(7);
}
void Chuyenbay::set_color_seat_on_board(int x, int y, long cmnd){
    setColor(2);
    int c = 1, row, collum;
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < 80; j++){
            if(map_seat[i][j] == 2){
                row = x+7+j;
                collum = y+i-15;
                gotoXY(row, collum ); cout << char(254) << char(254);
            }
        }
    }
    setColor(7);
}

int DanhSachChuyenBay::sl_cb = 0;
void DanhSachChuyenBay::TangSl_CB()
{
    ++sl_cb;
}
void DanhSachChuyenBay::InpByFile(string name)
{
    Chuyenbay *hientai;
    std::ifstream input(name);

    string line;
    int rows, cols, i;
    cols = 5;
    for (rows = 0; getline(input, line); ++rows)
    {
        if (dau == NULL)
        {
            dau = new Chuyenbay;
            hientai = dau;
        }
        else
        {
            hientai->next = new Chuyenbay;
            hientai = hientai->next;
        }
        int slhk; // slhk : số lượng hành khách
        i = 1;
        string element = "";
        if (line.length() == 0)
            continue;
        for (int t = 0; t < line.length(); ++t)
        {
            int tmp;
            if (line[t] != ' ')
            {
                element += line[t];
            }
            else if (line[t] == ' ')
            {
                if (i == 1)
                {
                    slhk = ChuyenDoi(element);
                    hientai->setSl_hk(slhk);
                }
                else if (i == 2)
                    hientai->setMaCB(element);
                else if (i == 3)
                    hientai->setNoiDen(element);
                else if (i == 4)
                    hientai->setLoai(element);
                else if (i == 5)
                {
                    tmp = ChuyenDoi(element);
                    hientai->setGio(tmp);
                }
                else if (i == 6)
                {
                    tmp = ChuyenDoi(element);
                    hientai->setPhut(tmp);
                }
                else if (i == 7)
                {
                    tmp = ChuyenDoi(element);
                    hientai->setNgay(tmp);
                }
                else if (i == 8)
                {
                    tmp = ChuyenDoi(element);
                    hientai->setThang(tmp);
                }
                else if (i == 9)
                {
                    tmp = ChuyenDoi(element);
                    hientai->setNam(tmp);
                    // cout << hientai->getMaCB() << "    " << hientai->getSl_hk() << "    "  << "    "  << hientai->getLoai() << "    "  << hientai->getNoiDen() << " " << hientai->getNgay() << endl;
                }
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
        TangSl_CB();
    }
}
Chuyenbay *DanhSachChuyenBay::Search_maCB(string id)
{
    if (dau == NULL)
    {
        cout << "Danh sach may bay rong!" << endl;
        return NULL;
    }
    Chuyenbay *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == id)
            return hientai;
        hientai = hientai->next;
    }
    cout << "Khong tim thay may bay!" << endl;
    return NULL;
}
