#ifndef __Chuyenbay_h__
#define __Chuyenbay_h__
#include<string>
#include"Time.h"
#include"Console.h"
#include"danhsachmaybay.h"
using namespace std;
class Chuyenbay : public Time, public maybay
{
    private:
        string MaCB;
        string NoiDen;
        int sl_hk; // số lượng người hiện đã đki vé
        long **map_seat; // ma trận để lưu
    public:
        Chuyenbay *next;
        void setMaCB(string ma);
        void setNoiDen(string noi);
        void setSl_hk(int n);
        string getMaCB();
        string getNoiDen();
        int getSl_hk();
        
        // void set_seat(int i, int j, long x);
        //Chuyenbay();
        ~Chuyenbay();
        
        // các hàm mapseat
        int get_row(string seat);
        void set_map_seat(); // khởi tạo ma trận với 8 hàng và 80 cột
        int set_seat(string seat, long cmnd); // ham khởi tạo cho vị trí cần inp vào ma trận
        void set_seated_onboard(long cmnd);
        int check_seat_already(string seat); // hàm kiểm tra ghế đó còn trống hay không
        void set_color_seat_checkin(int x, int y); // hàm tô màu lên vị trí đã checkin
        void set_color_seat_on_board(int x, int y, long cmnd);
};

class DanhSachChuyenBay{
    private:
        Chuyenbay *dau;
        static int sl_cb;
    public:
        DanhSachChuyenBay(){ dau = NULL;}
        void TangSl_CB();
        void InpByFile(string name);

        string getnoiden(string id);
        string getdate(string id);
        string gettime(string id);
        Chuyenbay *Search_maCB(string id); // tim kiem chuyen bay theo ma chuyen bay
};
#endif