#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "ticket.h"
#include "Console.h"
using namespace std;

int take_num_seat(string seat){ // hàm lấy chỗ ngồi
    int collum1 = seat[1] - '0';
    int collum2 = seat[2] - '0';
    return (collum1 * 10 + collum2);
}

// vẽ may bay, chỗ ngồi, khung note và bảng điều khiển
void plane_side(int x, int y, int h, int w, int plane_color, int key)
{
    // váº½ khung mÃ¡y bay
    setColor(8);
    gotoXY(x, y);
    cout << char(40);
    for (int i = 1; i < 5; i++)
    {
        gotoXY(x + i, y - i);
        cout << char(47);
        gotoXY(x + i, y + i);
        cout << char(92);
    }
    // vÃ¡ÂºÂ½ Ã„â€˜Ã†Â°Ã¡Â»Âng viÃ¡Â»Ân dÃ†Â°Ã¡Â»Â¡i
    gotoXY(x + 5, y + 4);
    for (int i = 0; i < 81; i++)
    {
        cout << char(95);
    }
    // vÃ¡ÂºÂ½ Ã„â€˜Ã†Â°Ã¡Â»Âng viÃ¡Â»Ân trÃƒÂªn
    gotoXY(x + 5, y - 5);
    for (int i = 0; i < 81; i++)
    {
        cout << char(95);
    }
    // vÃ¡ÂºÂ½ Ã„â€˜uÃƒÂ´i mÃƒÂ¡y bay:
    for (int i = -4; i < 5; i++)
    {
        gotoXY(x + 86, y + i);
        cout << char(124);
    }
    for (int i = 1; i < 6; i++)
    {
        gotoXY(x + 86 + i, y - 4 - i);
        cout << char(47);
        gotoXY(x + +86 + i, y + 4 + i);
        cout << char(92);
    }
    for (int i = 0; i < 10; i++)
    {
        gotoXY(x + 92 + i, y - 10);
        cout << char(95);
        gotoXY(x + 92 + i, y + 9);
        cout << char(95);
    }
    gotoXY(x + 101, y - 10);
    cout << char(32);
    for (int i = -9; i < 10; i++)
    {
        if (i == -1)
        {
            gotoXY(x + 100, y - 1);
            cout << char(47);
            gotoXY(x + 100, y + 1);
            cout << char(92);
            gotoXY(x + 99, y);
            cout << char(40);
            i += 3;
        }
        gotoXY(x + 101, y + i);
        cout << char(124);
    }

    // vÃ¡ÂºÂ½ cÃƒÂ¡nh mÃƒÂ¡y bay
    for (int i = 1; i < 6; i++)
    {
        gotoXY(x + 32 + i, y - 4 - i);
        cout << char(47);
        gotoXY(x + 32 + i, y + 4 + i);
        cout << char(92);
        gotoXY(x + 55, y - 4 - i);
        cout << char(124);
        gotoXY(x + 55, y + 4 + i);
        cout << char(124);
    }
    for (int i = 1; i < 18; i++)
    {
        gotoXY(x + 37 + i, y - 10);
        cout << char(95);
        gotoXY(x + 37 + i, y + 9);
        cout << char(95);
    }

    // váº½ hÃ ng chá»¯
    int word = 65;
    for (int i = -3; i < 4; i++)
    {
        if (i == 0)
            i++;
        gotoXY(x + 5, y + i);
        cout << char(word++);
    }

    // váº½ hÃ ng sá»‘
    gotoXY(x + 7, y - 4);
    for (int i = 1; i < 26; i++)
    {
        if (i == 5 || i == 9 || i == 17)
            cout << " ";
        if (i < 10)
            cout << "0" << i << " ";
        else
            cout << i << " ";
    }

    // váº½ hÃ ng gháº¿ thÆ°Æ¡ng gia
    if(key == 1) setColor(6);
    else if(key == 2) setColor(8);
    for (int i = -3; i < 4; i++)
    {
        if (i == 0)
            i++;
        for (int j = 7; j < 19; j += 3)
        {
            gotoXY(x + j, y + i);
            cout << char(254);
            gotoXY(x + j + 1, y + i);
            cout << char(254);
        }
    }

    // váº½ hÃ ng gháº¿ phá»• thÃ´ng
    
    
    for (int i = -3; i < 4; i++)
    {
        if (i == 0)
            i++;
        for (int j = 20; j < 83; j += 3)
        {
            if(key == 1) setColor(1);
            else if(key == 2) setColor(8);
            if (j == 32 || j == 57)
                j++;
            if (j > 57 && key == 1)
                setColor(2);
            else if(j>57 && key == 2) setColor(8);
            gotoXY(x + j, y + i);
            cout << char(254);
            gotoXY(x + j + 1, y + i);
            cout << char(254);
        }
    }
    
    if(key == 1 ){
        // hÃ m váº½ cÃ¡i khung note
        x = 120, y = 1;
        P_box(x, y, 20, 6, 5, 1);
        setColor(7);
        gotoXY(x + 1, y + 1);
        cout << "NOTE";
        gotoXY(x + 2, y + 2);
        cout << ": Hang thuong gia";
        gotoXY(x + 2, y + 3);
        cout << ": Hang pho thong";
        gotoXY(x + 2, y + 4);
        cout << ": Hang tiet kiem";
        gotoXY(x + 2, y + 5);
        cout << ": Da co nguoi dat";
        setColor(6);
        gotoXY(x + 1, y + 2);
        cout << char(254);
        setColor(1);
        gotoXY(x + 1, y + 3);
        cout << char(254);
        setColor(2);
        gotoXY(x + 1, y + 4);
        cout << char(254);
        setColor(4);
        gotoXY(x + 1, y + 5);
        cout << char(254);
        // váº½ báº£ng Ä‘iá»u khiá»ƒn
        x = 10, y = 21, w = 31, h = 8;
        P_box(x, y, w, h, 7, 1);
        gotoXY(x + 7, y + 1);
        cout << "Dat cho ngoi";
        gotoXY(x + 1, y + 2);
        cout << "Nhap CMND: _________";
        gotoXY(x + 1, y + 3);
        cout << "Nhap vi tri (VD: A01): ___";
        P_box(x + 1, y + 5, 9, 2, 8, 1);
        P_box(x + 24, y + 5, 6, 2, 8, 1);
        setColor(7);
        gotoXY(x + 2, y + 6);
        cout << "Tiep tuc";
        gotoXY(x + 25, y + 6);
        cout << "Thoat";
    }

    else if(key == 2 ){
        // hÃ m váº½ khung note
        x = 120, y = 1;
        P_box(x, y, 20, 5, 5, 1);
        setColor(7);
        gotoXY(x + 1, y + 1);
        cout << "NOTE";
        gotoXY(x + 2, y + 2);
        cout << ": Chua checkin";
        gotoXY(x + 2, y + 3);
        cout << ": Chua len may bay";
        gotoXY(x + 2, y + 4);
        cout << ": San sang!";
        setColor(8);
        gotoXY(x + 1, y + 2);
        cout << char(254);
        setColor(4);
        gotoXY(x + 1, y + 3);
        cout << char(254);
        setColor(2);
        gotoXY(x + 1, y + 4);
        cout << char(254);
        setColor(4);
        // váº½ báº£ng Ä‘iá»u khiá»ƒn
        x = 10, y = 19, w = 31, h = 8;
        P_box(x, y, w, h, 7, 1);
        gotoXY(x + 7, y + 1);
        cout << "Check len may bay";
        gotoXY(x + 1, y + 2);
        cout << "Nhap CMND: _________";
        P_box(x + 1, y + 5, 9, 2, 8, 1);
        P_box(x + 24, y + 5, 6, 2, 8, 1);
        setColor(7);
        gotoXY(x + 2, y + 6);
        cout << "Tiep tuc";
        gotoXY(x + 25, y + 6);
        cout << "Thoat";
    }
}


int ChuyenDoiSo(string a)
{
    stringstream str2num(a);
    int x = 0;
    str2num >> x;
    return x;
}
// Cac ham trong Ticket:
void ticket::setVitri(int vt)
{
    this->vitri = vt;
}
void ticket::setCheck_in(int s)
{
    this->Check_in_status = s;
}
void ticket::setCheck_vitri(int c)
{
    this->Check_vitri = c;
}

int ticket::getVitri()
{
    return vitri;
}
bool ticket::getCheck_in()
{
    return Check_in_status;
}
bool ticket::getCheck_vitri()
{
    return Check_vitri;
}

ticket::~ticket() {}

// Cac ham trong TicketList:
int TicketList::sl_ve = 0;
void TicketList::TangSl_ve()
{
    ++sl_ve;
}
int TicketList::sl_ve_cb = 0;
void TicketList::TangSl_ve_cb()
{
    ++sl_ve_cb;
}
void TicketList::setSl_ve_cb()
{
    sl_ve_cb = 0;
}

void TicketList::InpByFile(string name)
{
    ticket *hientai;
    std::ifstream input(name);
    string line;
    int rows, cols, i;
    cols = 4;
    for (rows = 0; getline(input, line); ++rows)
    {
        if (dau == NULL)
        {
            dau = new ticket;
            hientai = dau;
        }
        else
        {
            hientai->next = new ticket;
            hientai = hientai->next;
        }
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
                    hientai->setCMND(element);
                else if (i == 2)
                {
                    tmp = ChuyenDoiSo(element);
                    hientai->setCheck_in(tmp);
                }
                else if (i == 3)
                {
                    tmp = ChuyenDoiSo(element);
                    hientai->setCheck_vitri(tmp);
                }
                else if (i == 4)
                    hientai->setMaCB(element);
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
        TangSl_ve();
    }
}

bool TicketList::Search_kh_checkin(string makh, string macb, DanhSachChuyenBay cb)
{
    if (dau == NULL)
        return 0;
    ticket *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == macb && hientai->getCMND() == makh && hientai->getCheck_in() == 1)
            return 0;
        hientai = hientai->next;
    }
    return 1;
}

int TicketList::Search_checkin(string macb, DanhSachKH kh)
{
    system("cls");
    int x= 10, y =3, w = 50, h = 2;
    setColor(7);
    gotoXY(x+8, y-1); cout << "Danh sach khach hang chua checkin";
    P_box(x,y,w,h,8,1);
    setColor(7);
    gotoXY(x+1,y+1); cout << "Stt";
    gotoXY(x+3,y+1); cout << char(179) << "CMND";
    gotoXY(x+14,y+1); cout << char(179) << "Ho ten";
    gotoXY(x+34,y+1); cout << char(179) << "Sex";
    gotoXY(x+38,y+1); cout << char(179) << "Phone";
    setColor(8);
    gotoXY(x+3,y); cout << char(194);
    gotoXY(x+3,y+2); cout << char(193);
    gotoXY(x+14,y); cout << char(194);
    gotoXY(x+14,y+2); cout << char(193);
    gotoXY(x+34,y); cout << char(194);
    gotoXY(x+34,y+2); cout << char(193);
    gotoXY(x+38,y); cout << char(194);
    gotoXY(x+38,y+2); cout << char(193);
    int cnt = 0;
    if (dau == NULL)
        return 0;
    ticket *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == macb)
        {
            if (hientai->getCheck_in() == 0)
            {
                cnt++;
                kh.InKH(hientai->getCMND(),cnt,x,y);
            }
        }
        hientai = hientai->next;
    }
    P_box(x,y+5+cnt,9,h,5,1); // hộp quay lại
    P_box(x+43,y+5+cnt,7,h,8,1); // hộp thoát
    setColor(7);
    gotoXY(x+1,y+6+cnt); cout << "Quay lai";
    gotoXY(x+44,y+6+cnt); cout << "Thoat";
    int press = 1;
    int key = 1;
    while (key == 1)
    {
        int t = getch();
        if (t == 13)
        {
            if (press == 1)
                return 1;
            else if (press == 2)
                return 0;
        }
        else if (t == 80)
        {
            press++;
        }
        else if (t == 72)
        {
            press--;
        }
        if (press > 2)
            press = 1;

        else if (press < 1)
            press = 2;

        if (press == 1)
        {
            P_box(x,y+5+cnt,9,h,5,1); // hộp quay lại
            P_box(x+43,y+5+cnt,7,h,8,1); // hộp thoát
        }
        else if (press == 2)
        {
            P_box(x,y+5+cnt,9,h,8,1); // hộp quay lại
            P_box(x+43,y+5+cnt,7,h,5,1); // hộp thoát
        }
    }
}


bool TicketList::Search_kh(string makh, string macb, DanhSachChuyenBay cb)
{
    if (dau == NULL)
        return 0;
    ticket *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == macb && hientai->getCMND() == makh)
            return 1;
        hientai = hientai->next;
    }
    return 0;
}

// hàm kiểm tra ghế nhập vào có đúng cú pháp kh
bool Check_name_seat(string seat)
{
    if (seat.length() != 3)
        return 0;
    seat[0] = toupper(seat[0]);
    if (char(seat[0]) < 65 || char(seat[0]) > 70)
        return 0;
    if (char(seat[1]) < 48 || char(seat[1]) > 50)
        return 0;
    if (char(seat[1]) == 50)
    {
        if (char(seat[2]) < 48 || char(seat[2]) > 53)
            return 0;
    }
    else
    {
        if (char(seat[1]) == 48 && char(seat[2]) == 48)
            return 0;
        if (char(seat[2]) < 48 || char(seat[2]) > 57)
            return 0;
    }
    return 1;
}
// hàm kiểm tra cmnd có đúng định dạng kh
long Check_name_cmnd(string cmnd)
{
    if (cmnd.length() != 9)
        return 0;
    for (int i = 0; i < 9; i++)
    {
        if (cmnd[i] < 48 && cmnd[i] > 57)
            return 0;
    }
    int cnt = 8;
    long c = 0, d;
    for (int i = 0; i < 9; i++)
    {
        d = 1;
        for (int i = 0; i < cnt; i++)
        {
            d *= 10;
        }
        cnt--;
        c += (cmnd[i] - '0') * d;
    }
    return c;
}

void Box_ticket_checkin()
{
    int x = 50, y = 21, w = 80, h = 13;
    P_box(x, y, w, h, 3, 1);
    gotoXY(x + 1, y + 1);
    cout << char(2);
    gotoXY(x + 79, y + 1);
    cout << char(2);
    for (int i = 1; i < 14; i++)
    {
        gotoXY(x + 60, y + i);
        cout << char(124);
    }
    for (int i = 0; i < 80; i++)
    {
        gotoXY(x + i, y + 3);
        cout << char(196);
    }
    gotoXY(x + 60, y + 3);
    cout << char(197);
    gotoXY(x + 80, y + 3);
    cout << char(180);
    gotoXY(x + 60, y);
    cout << char(194);
    gotoXY(x + 60, y + 13);
    cout << char(193);
    gotoXY(x, y + 3);
    cout << char(195);
    setColor(5);
    gotoXY(x + 1, y + 2);
    cout << "Vietnam Airline";
    gotoXY(x + 63, y + 2);
    cout << "Vietnam Airline";
    setColor(7);
    gotoXY(x + 1, y + 4);
    cout << "Hang chuyen cho/CARRER:";
    gotoXY(x + 1, y + 6);
    cout << "Ho va ten/NAME:";
    gotoXY(x + 1, y + 8);
    cout << "Noi di/FROM:";
    gotoXY(x + 1, y + 10);
    cout << "Noi den/TO:";
    gotoXY(x + 28, y + 4);
    for (int i = 0; i < 15; i++)
    {
        cout << char(177);
    }
    gotoXY(x + 28, y + 5);
    cout << "Chuyen bay/FLIGHT:";
    gotoXY(x + 28, y + 7);
    cout << "Cong/GATE:";
    gotoXY(x + 28, y + 9);
    cout << "Ghe/SEAT:";
    gotoXY(x + 49, y + 5);
    cout << "Ngay/DATE:";
    gotoXY(x + 43, y + 7);
    cout << "Gio len may bay/";
    gotoXY(x + 43, y + 8);
    cout << " BOARDING TIME:";
    gotoXY(x + 61, y + 4);
    cout << "Fr: ";
    gotoXY(x + 61, y + 5);
    cout << "To: ";
    gotoXY(x + 61, y + 6);
    cout << "Ho va ten/NAME: ";
    gotoXY(x + 61, y + 8);
    cout << "Chuyen bay/FLIGHT:";
    gotoXY(x + 61, y + 10);
    cout << "Ghe/SEAT: ";
    gotoXY(x + 61, y + 11);
    cout << "Ngay/DATE: ";
    gotoXY(x + 61, y + 12);
    cout << "Time:";
    setColor(1);
    gotoXY(x + 20, y + 12);
    cout << "Chuc quy khach co mot chuyen bay vui ve!";
}

void seated_reser_color(string seat, long cmnd, int x, int y, Chuyenbay *cb)
{
    int row = cb->get_row(seat);
    int i = cb->set_seat(seat, cmnd);
    setColor(4);
    gotoXY(x + 7 + i, y + row - 15);
    cout << char(254) << char(254); // trá»« 15 vÃ¬ truyá»n vÃ´ lÃ  21
    setColor(7);
}


void TicketList::Check_in(string id, DanhSachChuyenBay dscb, DanhSachKH kh,Chuyenbay *cb)
{
    system("cls");
    ofstream file;
    file.open("text_checkin.txt", ios::app);
    int cnt = 0;
    int key = 1;
    ticket *hientai;
    plane_side(10, 10, 8, 50, 6,1);
    long cmnd;
    string seat, cmnd1; // cmnd1 là chuỗi để check
    int x = 10, y = 21; // set tọa độ nhập vào cmnd và ghế
    int x1 = 50, w = 80, h = 13;
    do
    {
        cb->set_color_seat_checkin(x,y);
        setColor(7);
        gotoXY(x + 12, y + 2);
        cout << "_________";
        gotoXY(x + 24, y + 3);
        cout << "___    ";
        gotoXY(x + 12, y + 2);
        cin >> cmnd1;
        while (!Check_name_cmnd(cmnd1) || !Search_kh(cmnd1, id, dscb)) // cmnd != cmnd2
        {
            gotoXY(x + 12, y + 2);
            cout << "_________       ";
            gotoXY(x + 5, y + 4);
            cout << "  Khong tim thay CMND!   ";
            gotoXY(x + 12, y + 2);
            cin >> cmnd1;
        }
        if (!Search_kh_checkin(cmnd1, id, dscb))
        {
            gotoXY(x + 12, y + 2);
            cout << "_________       ";
            gotoXY(x + 5, y + 4);
            cout << "Khach hang nay da Checkin";
            continue;
        }
        cmnd = Check_name_cmnd(cmnd1);
        gotoXY(x + 5, y + 4);
        cout << "  Dang nhap thanh cong!   ";
        gotoXY(x + 24, y + 3);
        cin >> seat;
        seat[0] = toupper(seat[0]);
        while (!Check_name_seat(seat) || !cb->check_seat_already(seat)) //
        {
            gotoXY(x + 24, y + 3);
            cout << "___    ";
            gotoXY(x + 5, y + 4);
            cout << "  Ghe ngoi khong kha dung!";
            gotoXY(x + 24, y + 3);
            cin >> seat;
            seat[0] = toupper(seat[0]);
        }
        seat[0] = toupper(seat[0]);
        seated_reser_color(seat, cmnd, x, y, cb);
        gotoXY(x + 5, y + 4);
        cout << "  Da dat cho thanh cong!  ";
        Box_ticket_checkin();
        P_box(x + 1, y + 5, 9, 2, 5, 1);

        // màu ghế
        int seat_word_collor; 
        if(take_num_seat(seat) < 5) seat_word_collor = 6;
        else if(take_num_seat(seat) < 17) seat_word_collor = 1;
        else seat_word_collor = 2;

        ticket *hientai;
        hientai = dau;
        while (hientai != NULL)
        {
            if (hientai->getCMND() == cmnd1 && hientai->getMaCB() == id){
                hientai->setCheck_in(1);
                file << hientai->getCMND() << setw(30)  << hientai->getCheck_in() << setw(30) << hientai->getCheck_vitri()<<setw(20)<<id << "   " << endl;
                setColor(seat_word_collor);
                gotoXY(x + 78, y + 1);
                string str= seat.substr(1,2);
                int num=ChuyenDoiSo(str);
                if(num<=4) 
                { setColor(6);
                 cout<<"HANG THUONG GIA";
                }
                else if(num<=16)
                { setColor(1);
                 cout<<"HANG PHO THONG";
                }
                else if(num<=25)
                {
                    setColor(2);
                    cout<<"HANG TIET KIEM";
                }
                gotoXY(x1+ 1, y + 5);
                cout << "Vietnam Airline";
                gotoXY(x1+ 1, y + 7);
                cout << kh.GetHoVaTenbyCMND(hientai->getCMND());
                gotoXY(x1+ 1, y + 9);
                cout << "DaNang";
                gotoXY(x1+ 1, y + 11);
                cout << dscb.getnoiden(id);
                gotoXY(x1+ 28, y + 6);
                cout << id;
                gotoXY(x1+ 28, y + 8);
                cout << hientai->getCongVao(id);
                gotoXY(x1+ 28, y + 10);
                cout << seat;
                gotoXY(x1+ 49, y + 6);
                cout << dscb.getdate(id);
                gotoXY(x1+ 49, y + 9);
                cout << dscb.gettime(id);
                gotoXY(x1+ 65, y + 4);
                cout << "DaNang";
                gotoXY(x1+ 65, y + 5);
                cout << dscb.getnoiden(id);
                gotoXY(x1+ 61, y + 7);
                cout << kh.GetHoVaTenbyCMND(hientai->getCMND());
                gotoXY(x1+ 61, y + 9);
                cout << id;
                gotoXY(x1+ 70, y + 10);
                cout << seat;
                gotoXY(x1+ 71, y + 11);
                cout << dscb.getdate(id);
                gotoXY(x1+ 67, y + 12);
                cout << dscb.gettime(id);
                break;
            }
            hientai = hientai->next;
        }
        int press = 1;
        key = 1;
        gotoXY(x + 7, y + 4);
        cout << "                       ";
        while (key == 1)
        {
            int t = getch();
            if (t == 13)
            {
                if (press == 1)
                {   xoathongtin();
                    break;
                }
                else if (press == 2)
                    key = 0;
            }
            else if (t == 80)
            {
                press++;
            }
            else if (t == 72)
            {
                press--;
            }
            if (press > 2)
                press = 1;

            else if (press < 1)
                press = 2;

            if (press == 1)
            {
                P_box(x + 1, y + 5, 9, 2, 5, 1);
                P_box(x + 24, y + 5, 6, 2, 8, 1);
            }
            else if (press == 2)
            {
                P_box(x + 1, y + 5, 9, 2, 8, 1);
                P_box(x + 24, y + 5, 6, 2, 5, 1);
            }
        }
        P_box(x + 1, y + 5, 9, 2, 8, 1);
        P_box(x + 24, y + 5, 6, 2, 8, 1);
        gotoXY(x + 7, y + 4);
        cout << "                        ";
        if(key == 0){
            key = Search_checkin(id,kh);// ,dscb
            if(key!=0){
                system("cls");
                plane_side(10, 10, 8, 50, 6,1);
                cb->set_color_seat_checkin(x,y);
            }
        } 
    } while (key);
}

int TicketList::find_checkin(string id, DanhSachChuyenBay dscb, DanhSachKH kh) // hÃ m in ra danh sÃ¡ch khÃ¡ch hÃ ng Ä‘Ã£ checkin
{  
    int x= 111, y =9, w = 50, h = 2;
    setColor(4);
    gotoXY(x+8, y-1); cout << "Danh sach khach hang chua len may bay";
    setColor(8);
    P_box(x,y,w,h,8,1);
    setColor(7);
    gotoXY(x+1,y+1); cout << "Stt";
    gotoXY(x+3,y+1); cout << char(179) << "CMND";
    gotoXY(x+14,y+1); cout << char(179) << "Ho ten";
    gotoXY(x+34,y+1); cout << char(179) << "Sex";
    gotoXY(x+38,y+1); cout << char(179) << "Phone";
    setColor(8);
    gotoXY(x+3,y); cout << char(194);
    gotoXY(x+3,y+2); cout << char(193);
    gotoXY(x+14,y); cout << char(194);
    gotoXY(x+14,y+2); cout << char(193);
    gotoXY(x+34,y); cout << char(194);
    gotoXY(x+34,y+2); cout << char(193);
    gotoXY(x+38,y); cout << char(194);
    gotoXY(x+38,y+2); cout << char(193);
    int cnt = 0;
    if (dau == NULL)
        return 0;
    ticket *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        if (hientai->getMaCB() == id)
        {
            if (hientai->getCheck_in()==1 && hientai->getMaCB()==id && hientai->getCheck_vitri()==0)
            {
                cnt++;
                kh.InKH(hientai->getCMND(),cnt,x,y);
            }
        }
        hientai = hientai->next;
    }
    return cnt;
}

void TicketList::Get_in_plane(string id, DanhSachChuyenBay dscb, DanhSachKH kh,Chuyenbay *cb)
{   

    system("cls");
    ofstream file;
    file.open("text_get_in_plane.txt", ios::app);

    int x = 10,y = 20; // tá»a Ä‘á»™ khi nháº­p cmnd 
    setColor(3);
    int cnt = 0;
    string cmnd1;
    ticket *hientai;
    int cmnd, key = 1; // key = 2 :continue
    int i;
    do
    {
        system("cls");
        i = find_checkin(id,dscb,kh); 
        plane_side(8, 10, 8, 50, 6,2);
        cb->set_color_seat_checkin(8,21);
        cb->set_color_seat_on_board(8,21,cmnd);


        setColor(7);
        gotoXY(x + 12, y + 1);
        cout << "_________";
        gotoXY(x + 12, y + 1);
        cin >> cmnd1;
        while (!Check_name_cmnd(cmnd1) || !Search_kh(cmnd1, id, dscb)) 
        {
            gotoXY(x + 12, y + 1);
            cout << "_________       ";
            gotoXY(x + 4, y + 2);
            cout << "   Khong tim thay CMND!   ";
            gotoXY(x + 12, y + 1);
            cin >> cmnd1;
        }
        hientai = dau;
        while (hientai != NULL)
        {
            if (hientai->getCMND() == cmnd1 && hientai->getMaCB()==id)
            {
                if (hientai->getCheck_in() == 0)
                {
                    gotoXY(x+4,y+2); cout << " Khach hang chua Check_in ";
                    key = 2;
                    break;
                }
                else if(hientai ->getCheck_vitri()==1)
                {
                    gotoXY(x+4,y+2); cout << " Khach hang da len may bay";
                    key = 2;
                    break;
                }
                else if (hientai->getCheck_in() == 1)
                {
                    cmnd = Check_name_cmnd(cmnd1);
                    hientai->setCheck_vitri(1);
                    file << hientai->getCMND() << setw(30)  << hientai->getCheck_in() << setw(30) << hientai->getCheck_vitri()<<setw(20)<<id << "   " << endl;
                    cnt++;
                    cb->set_seated_onboard(cmnd);
                }
                break;
            }
            hientai = hientai->next;
        }
        if(key == 2 ) continue;
        int press = 1;
        key = 1;
        P_box(x + 1, y + 4, 9, 2, 5, 1);
        P_box(x + 24, y + 4, 6, 2, 8, 1);
        while (key == 1)
        {
            int t = getch();
            if (t == 13)
            {
                if (press == 1)
                    {   xoathongtin();
                    break;
                    }
                else if (press == 2)
                    key = 0;
            }
            else if (t == 80)
            {
                press++;
            }
            else if (t == 72)
            {
                press--;
            }
            if (press > 2)
                press = 1;

            else if (press < 1)
                press = 2;

            if (press == 1)
            {
                P_box(x + 1, y + 4, 9, 2, 5, 1);
                P_box(x + 24, y + 4, 6, 2, 8, 1);
            }
            else if (press == 2)
            {
                P_box(x + 1, y + 4, 9, 2, 8, 1);
                P_box(x + 24, y + 4, 6, 2, 5, 1);
            }
        }
        P_box(x + 1, y + 4, 9, 2, 8, 1);
        P_box(x + 24, y + 4, 6, 2, 8, 1);
        gotoXY(x + 12, y + 2);
        cout << "                       ";
        gotoXY(1,1);
        
        if(key == 0) break;
        if(i == 1) {
            system("cls");
            setColor(6);
            gotoXY(x+40,y + 20); cout << " TAT CA KHACH HANG DA LEN MAY BAY!";
            gotoXY(x+40,y + 21); cout << "CHUC QUY KHACH CO CHUYEN BAY VUI VE!";
            Sleep(5000);
            break;
        }
    } while (key);
}

string ticket::getCongVao(string maCB)
{
    if (maCB == "1111" || maCB == "VIDU" || maCB == "VNCT")
        return "A1";
    else if (maCB == "VNDANANG" || maCB == "HANOI01" || maCB == "VNVNV")
        return "A2";
    else if (maCB == "CH113" || maCB == "VNNNV" || maCB == "VNV")
        return "B1";
    else if (maCB == "NH370" || maCB == "SCGC" || maCB == "VNHCM01")
        return "B2";
    else if (maCB == "VNHCM")
        return "C1";
    else
        return "Flight not found";
}
void TicketList::updatetofile(string filename)
{
    ofstream ofs(filename, ios::trunc);
    ticket *hientai;
    hientai = dau;
    while (hientai != NULL)
    {
        ofs << hientai->getCMND() <<"    " << hientai->getCheck_in() <<"    " << hientai->getVitri() << "                " << hientai->getMaCB() << "  " << endl;
        hientai = hientai->next;
    }
    ofs.close();
}