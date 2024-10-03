#include<iostream>
using namespace std;

class Mytime{
	private:
		int hour, minute, second;
	public:
		Mytime();
		void setMyTime(int hour,int minute,int second);
		void nhap();
		void xuat();
};
Mytime::Mytime(){
	hour = minute = second = 0;
}
void Mytime::setMyTime(int H, int M, int S){
	hour = (H>=0 && H<24) ? H : 0;
	minute = (M>=0 && M<60) ? M : 0;
	second = (S>=0 && S<60) ? S : 0;
}
void Mytime::nhap(){
	do {
		cout << "Nhap gio: "; cin >> hour;
		if (hour < 0 || hour >= 24){
			cout << "Nhap khong dung !! Nhap lai\n";
		}
	} while (hour < 0 || hour >= 24);
	do {
		cout << "Nhap phut: "; cin >> minute;
		if (minute < 0 || minute >= 60){
			cout << "Nhap khong dung !! Nhap lai\n";
		}
	} while (minute < 0 || minute >= 60);
	do {
		cout << "Nhap giay: "; cin >> second;
		if (second < 0 || second >= 60){
			cout << "Nhap khong dung !! Nhap lai\n";
		}
	} while (second < 0 || second >= 60);
}
void Mytime::xuat(){
	cout << (hour < 10 ? "0" : "") << hour;
	cout << ":" << (minute < 10 ? "0" : "") << minute;
	cout << ":" << (second < 10 ? "0" : "") << second;
	cout << (hour < 12 ? " AM" : " PM") << endl; 
};
class Mydate{
	private:
		int day,month,year;
	public:
		Mydate();
		void setMyDate(int day, int month, int year);
		void nhap();
		void xuat();	
};
Mydate::Mydate(){
	day = 1;
	month = 1;
	year = 2024;
}
void Mydate::setMyDate(int D, int M, int Y){
	this->day = D;
	this->month = M;
	this->year = Y;
}
void Mydate::nhap(){
	do{
		cout << "Nhap ngay (1 - 31): "; cin >> day;
		if (day < 1 || day > 31){
			cout << "Nhap khong dung !! Nhap lai\n";
		}
	} while (day < 1 || day > 31);
	do {
		cout << "Nhap thang (1 - 12): "; cin >> month;
		if (month < 1 || month > 12){
			cout << "Nhap khong dung !! Nhap lai\n";
		}
	} while (month < 1 || month > 12);
	cout << "Nhap nam: "; cin >> year;
}
void Mydate::xuat(){
	cout << (day < 10 ? "0" : "") << day;
	cout << "-" << (month < 10 ? "0" : "") << month;
	cout << "-" << (year < 10 ? "0" : "") << year;
};
class Datetime: public Mytime, public Mydate{
	public:
		void setDateTime(int H, int M, int S, int D, int Mo, int Y);
		void nhap();
		void xuat();
};
void Datetime::setDateTime(int H, int M, int S, int D, int Mo, int Y){
	Mytime::setMyTime(H,M,S);
	Mydate::setMyDate(D,Mo,Y);
}
void Datetime::nhap(){
	Mytime::nhap();
	Mydate::nhap();
}
void Datetime::xuat(){
	Mytime::xuat();
	Mydate::xuat();
}
int main(){
	Datetime dt;
	dt.setDateTime(12, 30, 45, 29, 2, 2024);  
	cout << "Thong tin vua thiet lap la: \n";
	dt.xuat();
	cout << endl;
	
	dt.nhap();  
	cout << "Thong tin vua nhap la: \n";
	dt.xuat();
	cout << endl;
}