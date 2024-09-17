#include<iostream>
#include<cmath>
using namespace std;

class SoPhuc{
	private:
		double phanThuc, phanAo;
	public:
		SoPhuc(){
			this->phanThuc = 0;
			this->phanAo = 0;
		}
		SoPhuc(double a, double b){
			this->phanThuc = a;
			this->phanAo = b;
		}
		SoPhuc(double a){
			this->phanThuc = a;
			this->phanAo = 0;
		}
		SoPhuc(const SoPhuc &p){
			this->phanThuc = p.phanThuc;
			this->phanAo = p.phanAo;
		}
//		void nhap();
//		void xuat();
		friend istream& operator >> (istream &is, SoPhuc &p);
		friend ostream& operator << (ostream &os, SoPhuc p);
		double getPhanThuc();
		void setPhanThuc(double phanThuc);
		double getPhanAo();
		void setPhanAo(double phanAo);
		friend double Modun(const SoPhuc &p1);
//		friend SoPhuc Cong(const SoPhuc &p1, const SoPhuc &p2);
//		friend SoPhuc Tru(const SoPhuc &p1, const SoPhuc &p2);
//		friend SoPhuc Nhan(const SoPhuc &p1, const SoPhuc &p2);
//		friend SoPhuc Chia(const SoPhuc &p1, const SoPhuc &p2);
		
		friend SoPhuc operator + (const SoPhuc &p1, const SoPhuc &p2);
		SoPhuc operator - (const SoPhuc &p);
		friend SoPhuc operator * (const SoPhuc &p1, const SoPhuc &p2);
		friend SoPhuc operator / (const SoPhuc &p1, const SoPhuc &p2);
//		void SoSanh(const SoPhuc &p1);
		friend bool operator ==(const SoPhuc &p1, const SoPhuc &p2);
		bool operator > (const SoPhuc &p);
		bool operator < (const SoPhuc &p);
};

double Modun(const SoPhuc &p1){
	double p;
	p = sqrt(pow(p1.phanThuc,2)+pow(p1.phanAo,2));
	return p;
}
//SoPhuc Cong(const SoPhuc &p1, const SoPhuc &p2){
//	SoPhuc p;
//	p.phanThuc = p1.phanThuc + p2.phanThuc;
//	p.phanAo = p1.phanAo + p2.phanAo;
//	return p;
//}
//SoPhuc Tru(const SoPhuc &p1, const SoPhuc &p2){
//	SoPhuc p;
//	p.phanThuc = p1.phanThuc - p2.phanThuc;
//	p.phanAo = p1.phanAo - p2.phanAo;
//	return p;
//}
//SoPhuc Nhan(const SoPhuc &p1, const SoPhuc &p2){
//	SoPhuc p;
//	p.phanThuc = p1.phanThuc*p2.phanThuc - p1.phanAo*p2.phanAo;
//	p.phanAo = p1.phanThuc*p2.phanAo + p2.phanThuc*p1.phanAo;
//	return p;
//}
//SoPhuc Chia(const SoPhuc &p1, const SoPhuc &p2){
//	SoPhuc p;
//	double mau = pow(p2.phanThuc, 2) + pow(p2.phanAo, 2);
//	p.phanThuc = (p1.phanThuc*p2.phanThuc + p1.phanAo*p2.phanAo)/mau;
//	p.phanAo = (p1.phanAo*p2.phanThuc - p1.phanThuc*p2.phanAo)/mau;
//	return p;
//}

SoPhuc operator + (const SoPhuc &p1, const SoPhuc &p2){
	SoPhuc p;
	p.phanThuc = p1.phanThuc + p2.phanThuc;
	p.phanAo = p1.phanAo + p2.phanAo;
	return p;
}
SoPhuc SoPhuc::operator -(const SoPhuc &p){
	SoPhuc a;
	a.phanThuc = p.phanThuc - phanThuc;
	a.phanAo = p.phanAo - phanAo;
	return a;
}
SoPhuc operator * (const SoPhuc &p1, const SoPhuc &p2){
	SoPhuc p;
	p.phanThuc = p1.phanThuc*p2.phanThuc - p1.phanAo*p2.phanAo;
	p.phanAo = p1.phanThuc*p2.phanAo + p2.phanThuc*p1.phanAo;
	return p;
}
SoPhuc operator / (const SoPhuc &p1, const SoPhuc &p2){
	SoPhuc p;
	double mau = pow(p2.phanThuc, 2) + pow(p2.phanAo, 2);
	p.phanThuc = (p1.phanThuc*p2.phanThuc + p1.phanAo*p2.phanAo)/mau;
	p.phanAo = (p1.phanAo*p2.phanThuc - p1.phanThuc*p2.phanAo)/mau;
	return p;
}
//void SoPhuc::SoSanh(const SoPhuc &p2){
//	double mod1 = Modun(*this);
//    double mod2 = Modun(p2);
//    if (mod1 > mod2)
//        cout << "=> p1 > p2\n";
//    else if (mod1 < mod2)
//        cout << "=> p1 < p2\n";
//    else
//        cout << "=> p1 = p2\n";
//}
bool operator ==(const SoPhuc &p1, const SoPhuc &p2){
	double mod1 = Modun(p1);
    double mod2 = Modun(p2);
	return mod1 == mod2;
}
bool SoPhuc::operator > (const SoPhuc &p){
	double mod1 = Modun(*this);
    double mod2 = Modun(p);
    return mod1 > mod2;
}
bool SoPhuc::operator < (const SoPhuc &p){
	double mod1 = Modun(*this);
    double mod2 = Modun(p);
    return mod1 < mod2;
}
//void SoPhuc::nhap(){
//	cout << "Nhap phan thuc: "; cin >> phanThuc;
//	cout << "Nhap phan ao: "; cin >> phanAo;
//}
//void SoPhuc::xuat(){
//	if (phanAo == 0) cout << phanThuc;
//    else if (phanAo < 0) cout << phanThuc << phanAo << "i";  
//    else cout << phanThuc << "+" << phanAo << "i"; 
//}

istream& operator >> (istream &is, SoPhuc &p){
	cout << "Nhap phan thuc: "; cin >> p.phanThuc;
	cout << "Nhap phan ao: "; cin >> p.phanAo;
	return is;
}
ostream& operator << (ostream &os, SoPhuc p){
	if(p.phanAo == 0) cout << p.phanThuc;
	else if(p.phanAo < 0) cout << p.phanThuc << p.phanAo << "i";
	else cout << p.phanThuc << "+" << p.phanAo << "i";
}
double SoPhuc::getPhanThuc(){
	return this->phanThuc;
}
double SoPhuc::getPhanAo(){
	return this->phanAo;
}
void SoPhuc::setPhanThuc(double phanThuc){
	this->phanThuc = phanThuc;
}
void SoPhuc::setPhanAo(double phanAo){
	this->phanAo = phanAo;
}

void test(SoPhuc p1, SoPhuc p2, SoPhuc ketqua, char choose){
	switch(choose){
		case '+':
			ketqua = p1+p2;
		    cout << "Tong hai so phuc: ";
		    cout << ketqua;
		    cout << endl;
		    break;
		case '-':
			ketqua = p1-p2;
		    cout << "Tru hai so phuc: ";
		    cout << ketqua;
		    cout << endl;
		    break;
		case '*':
			ketqua = p1*p2;
		    cout << "Nhan hai so phuc: ";
		    cout << ketqua;
		    cout << endl;
		    break;
		case '/':
			ketqua = p1/p2;
		    cout << "Chia hai so phuc: ";
		    cout << ketqua;
		    cout << endl;
		    break;
		default:
			cout << "Lua chon khong dung !! Vui long chon lai (+,-,*,/)\n";
			break;
	}
}

int main(){
	SoPhuc p1,p2,kq;
	cout << "--Nhap so phuc thu nhat\n"; cin >> p1;
    cout << "--Nhap so phuc thu hai\n"; cin >> p2;
    
    cout << "++Modun cua p1: " << Modun(p1) << endl;
    cout << "++Modun cua p2: " << Modun(p2) << endl;
    if (p1 > p2)
        cout << "=> SP1 > SP2\n";
    else if (p1 < p2)
        cout << "=> SP1 < SP2\n";
    else
        cout << "=> SP1 = SP2\n";
    
    char choose;
    while(1){
    	cout << "Lua chon phep tinh bang ki tu: Cong(+), Tru(-), Nhan(*), Chia(/)\n";
		cin >> choose;
		test(p1,p2,kq,choose);
		int exit_vl = 0;
		cout << "Nhap 0 de thoat, nhap 1 de tiep tuc chuong trinh: ";
		cin >> exit_vl;
		if(!exit_vl){
			cout << "Chuong trinh da thoat !!";
			break;
		}
		
	}
}