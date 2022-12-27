#ifndef __ticket_h__
#define __ticket_h__
#include"Chuyenbay.h"
#include"QuanLiKhachHang.h"
class ticket : public Chuyenbay, public KhachHang
{
    private:
        Time Order; // thoi gian dat ve
        int vitri;
        bool Check_in_status; // kiem tra da lam thu tuc check in hay chua
        bool Check_vitri; // kiem tra da vao cho ngoi hay chua
    public:
        ticket *next;
        ~ticket();
        void setVitri(int vt);
        void setCheck_in(int s);
        void setCheck_vitri(int c);
        string getCongVao(string MaCB);
        int getVitri();
        bool getCheck_in();
        bool getCheck_vitri();
};

class TicketList{
    private:
        ticket *dau;
        static int sl_ve;
        static int sl_ve_cb;
    public:
        TicketList(){
            dau = NULL;
        }
        void TangSl_ve();
        void TangSl_ve_cb();
        void setSl_ve_cb();
        void InpByFile(string name);
        
        void Check_in(string id, DanhSachChuyenBay dscb, DanhSachKH kh,Chuyenbay *cb);
        void Get_in_plane(string id, DanhSachChuyenBay dscb, DanhSachKH kh,Chuyenbay *cb);
        int Search_checkin(string macb,DanhSachKH kh); // xuất ra danh sách khách hàng chưa checkin
        bool Search_kh(string makh,string macb, DanhSachChuyenBay cb); // kiểm tra có khách hàng trên chuyến bay đó không
        bool Search_kh_checkin(string makh, string macb, DanhSachChuyenBay dscb); // kiểm tra khách hàng này đã check in hay chưa
        void updatetofile(string filename);
        int find_checkin(string id, DanhSachChuyenBay cb, DanhSachKH kh);
};
#endif