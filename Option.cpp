#include"Option.h"
#include<iostream>
#include "Console.h"
using namespace std;

int Create_menu(){
    P_box(55, 5, 18, 11, 7, 1);
    P_box(56,7,16,2,8,1); // há»™p checkin
    P_box(56,10,16,2,8,1); // há»™p bay
    P_box(56,13,16,2,8,1); // há»™p exit
    setColor(7);
    gotoXY(63,6); cout << "MENU";
    gotoXY(60,8); cout << "Check_in";
    gotoXY(60,11); cout << "Bay";
    gotoXY(60,14); cout << "Exit";
    P_box(56,7,16,2,5,1);
    int key = 1;
    int cn = 1;
    while(key){
        int t = getch();
        if(t == 13){
            // nhan enter
            switch(cn){
                case 1:
                    return 1;
                    break;
                case 2:
                    return 2;
                    break;
                case 3:
                    return 3;
                    break;
            }
        }
        else if (t==80){// nhan phim mui ten xuong thi tang chuc nang len 1 don vi
            cn++; //
        }
        else if (t==72){
            cn--; // mui ten di len
        }


        if (cn > 3) // neu dang o chuc nang so 3, nhan di xuong thanh chuc nang so 4, ma minh chi co 3
        // chuc nang ne se quay ve chuc nang so 1
        {
            cn=1;
        }
        else if (cn<1)// neu dang o chuc nang so 1, nhan di len thanh chuc nang so 0, ma minh chi co 3
        // chuc nang ne se quay ve chuc nang so 3
        {
            cn = 3;
        }

        if(cn == 1){
            P_box(56,7,16,2,5,1); // box 1
            P_box(56,10,16,2,8,1); // box 2
            P_box(56,13,16,2,8,1); // box 3
        }
        else if(cn == 2){
            P_box(56,7,16,2,8,1); // box 1
            P_box(56,10,16,2,5,1); // box 2
            P_box(56,13,16,2,8,1); // box 3
        }
        else if(cn == 3){
            P_box(56,7,16,2,8,1); // box 1
            P_box(56,10,16,2,8,1); // box 2
            P_box(56,13,16,2,5,1); // box 3
        }

    }
}

int Create_menu_CB(){
    P_box(55, 5, 18, 14, 7, 1);
    P_box(56,7,16,2,8,1); // box 1
    P_box(56,10,16,2,8,1); // box 2
    P_box(56,13,16,2,8,1); // box 3
    P_box(56,16,16,2,8,1); // box exit
    setColor(7);
    gotoXY(57,6); cout << "Chon chuyen bay";
    gotoXY(60,8); cout << "VNHCM";
    gotoXY(60,11); cout << "VNV";
    gotoXY(60,14); cout << "VNVNV";
    gotoXY(60,17); cout << "Exit";
    P_box(56,7,16,2,5,1);
    int key = 1;
    int cn = 1;
    while(key){
        int t = getch();
        if(t == 13){
            // nhan enter
            switch(cn){
                case 1:
                    return 1;
                    break;
                case 2:
                    return 2;
                    break;
                case 3:
                    return 3;
                    break;
                case 4:
                    return 4;
                    key = 0;;
                    break;
            }
        }
        else if (t==80){
            // nhan phim mui ten xuong
            cn++; // thi tang chuc nang len 1 don vi
        }
        else if (t==72){
            cn--; // mui ten di len
        }
        if (cn > 4) // neu dang o chuc nang so 3, nhan di xuong thanh chuc nang so 4, ma minh chi co 3
        // chuc nang ne se quay ve chuc nang so 1
        {
            cn=1;
        }
        else if (cn<1)// neu dang o chuc nang so 1, nhan di len thanh chuc nang so 0, ma minh chi co 3
        // chuc nang ne se quay ve chuc nang so 3
        {
            cn = 4;
            P_box(56,13,16,2,5,1);
            P_box(56,7,16,2,8,1);
        }


        if(cn == 1){
            P_box(56,7,16,2,5,1); // box 1
            P_box(56,10,16,2,8,1); // box 2
            P_box(56,13,16,2,8,1); // box 3
            P_box(56,16,16,2,8,1); // box exit
        }
        else if(cn == 2){
            P_box(56,7,16,2,8,1); // box 1
            P_box(56,10,16,2,5,1); // box 2
            P_box(56,13,16,2,8,1); // box 3
            P_box(56,16,16,2,8,1); // box exit
        }
        else if(cn == 3){
            P_box(56,7,16,2,8,1); // box 1
            P_box(56,10,16,2,8,1); // box 2
            P_box(56,13,16,2,5,1); // box 3
            P_box(56,16,16,2,8,1); // box exit
        }
        else if(cn == 4){
            P_box(56,7,16,2,8,1); // box 1
            P_box(56,10,16,2,8,1); // box 2
            P_box(56,13,16,2,8,1); // box 3
            P_box(56,16,16,2,5,1); // box exit
        }
    }
}

Option::Option(){
    int key = 1;
    danhsachmaybay mb;      mb.InpByFile("text_ds_mb.txt");
    DanhSachChuyenBay dscb; dscb.InpByFile("text_ds_cb.txt");
    DanhSachKH kh;          kh.InpByFile("text_ds_KH.txt");
    TicketList tl;          tl.InpByFile("text_ds_ve.txt");
    Chuyenbay *cb;
    int cb1 = 0,cb2 = 0,cb3 = 0; // Ä‘Ã¡nh dáº¥u Ä‘Ã£ gá»i hay chÆ°a

    do
    {
        system("cls");
        int key = Create_menu();
        
        if(key == 1){
            system("cls");
            string id; // mÃ£ cá»§a chuyáº¿n bay
            int select = Create_menu_CB(); // chá»n chuyáº¿n bay
            setColor(7);
            switch (select)
            {
                case 1:
                    id = "VNHCM";
                    
                    break;
                case 2:
                    id = "VNV";
                    break;
                case 3:
                    id = "VNVNV";
                    break;
                case 4:
                    key = 4;
                    break;
            }
            if(key == 4) continue;
            cb = dscb.Search_maCB(id);
            if(id == "VNHCM" && cb1 == 0) {
                cb->set_map_seat();
                cb1 = 1;
            }
            else if(id == "VNV" && cb2 == 0) {
                cb->set_map_seat();
                cb2 = 1;
            }
            else if(id == "VNVNV" && cb3 ==0) 
            {
                cb->set_map_seat();
                cb3 = 1;
            }
            tl.Check_in(id,dscb,kh,cb);
            system("cls");
        }
        else if(key==2)
        {
            system("cls");
            string id;
            int select = Create_menu_CB();
            setColor(7);
            switch (select)
            {
                case 1:
                    id = "VNHCM";
                    break;
                case 2:
                    id = "VNV";
                    break;
                case 3:
                    id = "VNVNV";
                    break;
                case 4:
                    key = 4;
                    break;
            }
            //Check_in.
            if(key == 4) continue; // neu chon exit thi continue
            system("cls");
            gotoXY(1,1);
            if(id == "VNHCM" && cb1 == 0) {
                cout << "Chuyen bay nay chua duoc checkin";
                Sleep(2000);
                continue;
            }
            else if(id == "VNV" && cb2 == 0) {
                cout << "Chuyen bay nay chua duoc checkin";
                Sleep(2000);
                continue;
            }
            else if(id == "VNVNV" && cb3 ==0) 
            {
                cout << "Chuyen bay nay chua duoc checkin";
                Sleep(2000);
                continue;
            }
            cb = dscb.Search_maCB(id);
            tl.Get_in_plane(id,dscb,kh,cb); 
        }
        else if(key == 3) break;
        tl.updatetofile("text_ds_ve.txt");
    } while (key);
}
Option::~Option(){ 

}