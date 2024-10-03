#include<string>
using namespace std;
class person{
	public:
		string hoten;
		string namsinh;
		string que;
};
class kysu: public person{
	private:
		string nganh;
		int nam;
	public:
		void nhap();
		void xuat();
		int getNam();
};