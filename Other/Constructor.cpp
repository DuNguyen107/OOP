#include<iostream>
using namespace std;

class Time
{
	private:
	int Hour;
	int Minute;
	int Second;
	public:
		Time(int = 0, int = 0, int = 0); //Constructor mac dinh
		void SetTime(int, int, int);
		void PrintMilitary();
		void PrintStandard();
}; 
//Ham constructor de khoi dong du lieu private
//Cac gia tri mac dinh la 0
Time::Time(int Hr, int Min, int Sec)
{
	SetTime(Hr, Min, Sec);
}
//Thiet lap cac gia tri cua Hour, Minute va Second
//Gia tri khong hop le duoc thiet lap la 0
void Time::SetTime(int H, int M, int S)
{
	Hour = (H >= 0 && H < 24) ? H : 0;
	Minute = (M >= 0 && M < 60) ? M : 0;
	Second = (S >= 0 && S < 60) ? S : 0;
}
//Hien thi thoi gian theo dang gio quan doi: HH:MM:SS
void Time::PrintMilitary()
{
	cout << (Hour < 10 ? "0" : "") << Hour << ":"
	<< (Minute < 10 ? "0" : "") << Minute << ":"
	<< (Second < 10 ? "0" : "") << Second;
}
//Hien thi thoi gian theo dang chuan: HH:MM:SS AM (hoac PM)
void Time::PrintStandard()
{
	cout << ((Hour == 0 || Hour == 12) ? 12 : Hour % 12)
	<< ":" << (Minute < 10 ? "0" : "") << Minute
	<< ":" << (Second < 10 ? "0" : "") << Second
	<< (Hour < 12 ? " AM" : " PM");
} 
int main()
{
	Time T1,T2(2),T3(21,34),T4(12,25,42),T5(27,74,99);
	cout << "Duoc khoi tao:" << endl << "tat ca doi so mac dinh" << endl << " ";
	T1.PrintMilitary(); cout << endl << " ";
	T1.PrintStandard();
	cout << endl << "Gio quy dinh; phut and giay mac dinh:" << endl << " ";
	T2.PrintMilitary(); cout << endl << " ";
	T2.PrintStandard();
	cout << endl << "Gio va phu duoc chi dinh; giay mac dinh:" << endl << " ";
	T3.PrintMilitary(); cout << endl << " ";
	T3.PrintStandard(); cout << endl << "gio, phut, and giay chi dinh:"<<endl<<" ";
	T4.PrintMilitary(); cout << endl << " ";
	T4.PrintStandard(); cout << endl << "tat ca gia tri khong hop le duoc chi dinh:" << endl << " ";
	T5.PrintMilitary(); cout << endl << " ";
	T5.PrintStandard(); cout << endl;
	return 0;
} 