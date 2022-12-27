#include "login.h"
#include "Option.h"
#include "Account.h"
#include "windows.h"
#include"Console.h"
#include <iostream>
using namespace std;
void P_box_word(int x, int y, int h, int w)
{
    setColor(150);
    gotoXY(x + 35, y + 1);
    cout << "PBL2: DO AN CO SO LAP TRINH";

    setColor(196);
    gotoXY(x + 19, y + 3);
    cout << "De tai: Xay dung ung dung quan li check-in ve va len may bay";

    setColor(226);
    gotoXY(x + 10, y + 5);
    cout << "Nhom 1:";

    setColor(221);
    gotoXY(x + 8, y + 6);
    cout << "Sinh vien 1: Le Duc Thanh";
    gotoXY(x + 8, y + 7);
    cout << "Sinh vien 2: Phan Nguyen Tuong Vy";
    gotoXY(x + 8, y + 8);
    cout << "Sinh vien 3: Do Cao Cuong";
    gotoXY(x + 60, y + 6);
    cout << "Lop: 21TCLC_KHDL2";
    gotoXY(x + 60, y + 7);
    cout << "Lop: 21TCLC_KHDL2";
    gotoXY(x + 60, y + 8);
    cout << "Lop: 21TCLC_KHDL2";
    gotoXY(x + 8, y + 9); cout << char(2);
}

void P_box_rim(int x, int y, int w, int h, int rim_color, int num)
{
    setColor(rim_color);
    for (int i = 0; i < num; i++)
    {
        for (int ix = x; ix < x + w; ix++)
        {
            gotoXY(ix, y);
            cout << char(220);
            gotoXY(ix, y + h);
            cout << char(223);
        }
        for (int iy = y; iy < y + h; iy++)
        {
            gotoXY(x, iy);
            cout << char(219);
            gotoXY(x + w, iy);
            cout << char(219);
        }
        y += h;
    }
    y = y - h * num;
    // váº½ cÃ¡c gÃ³c á»Ÿ trÃªn vÃ  dÆ°á»›i
    gotoXY(x, y);
    cout << char(220);
    gotoXY(x + w, y);
    cout << char(220);
    gotoXY(x + w, y + h);
    cout << char(223);
}

void Run(int x, int y, int col){
    
    for(int i = 0; i < 50;  i++){
        setColor(col);
        gotoXY(x + 1 + i,y+1);
        cout << char(177);
        setColor(7);
        gotoXY(97,y+3); cout << i*2 <<"%";
        Sleep(50);
        setColor(7);
    }
    gotoXY(97,y+3); cout <<"100%";
}

login::login()
{
    P_box(30, 5, 90, 15, 33, 1);
    P_box_word(30, 5, 90, 15);
    Sleep(4000);
    setColor(7);
    system("cls");
    DanhSachAccount ds;
    ds.InpByFile("text_account.txt");
    P_box(55, 5, 40, 10, 7, 1); // váº½ há»™p lá»›n
    P_box_rim(55, 5, 40, 10, 8, 1); // váº½ cÃ¡i viá»n
    P_box(60, 7, 30, 2, 8, 1); // váº½ cÃ¡i há»™p cho tÃ i khoáº£n
    P_box(60, 10, 30, 2, 8, 1); 
    int x = 68, y = 6;
    string tk, mk;
    setColor(2);
    gotoXY(x + 5, y);
    cout << "LOGIN";
    setColor(7);
    gotoXY(x - 7, y + 2);
    cout << "Username: ";
    gotoXY(x - 7, y + 5);
    cout << "Password: ";
    gotoXY(x + 6, y + 7);
    cout << "Quen mat khau?";
    gotoXY(x + 3, y + 2);
    cin >> tk;
    gotoXY(x + 3, y + 5);
    cin >> mk;
    while (ds.Search_account(tk) == false || ds.login(tk,mk) == false)
    {
        gotoXY(x + 3, y + 2);
        for (int i = 0; i < 19; i++)
            cout << char(32); // cout dấu cách
        gotoXY(x + 3, y + 5);
        for (int i = 0; i < 19; i++)
            cout << char(32);
        setColor(4);
        gotoXY(x + 3, y + 7);
        cout << "Tai khoan khong ton tai!";
        setColor(7);
        gotoXY(x + 3, y + 2);
        cin >> tk;
        gotoXY(x + 3, y + 5);
        cin >> mk;
    }
    setColor(6); gotoXY(x + 2, y + 7);
    cout << "  DANG NHAP THANH CONG!  ";
    setColor(7);
    P_box(49, 17, 52, 2, 8, 1);
    Run(49,17,8);
    Option op;
}
login::~login() {}