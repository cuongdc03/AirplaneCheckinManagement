#ifndef __Time_h__
#define __Time_h__
class Time
{
    private:
		int phut;
		int gio;
		int ngay;
		int thang;
		int nam;
	public:
		void setIt(int , int, int , int , int);
		void setPhut(int m);
		void setGio(int h);
		void setNgay(int d);
		void setThang(int m);
		void setNam(int y);

		int getPhut();
		int getGio();
		int getNgay();
		int getThang();
		int getNam();
};
#endif
