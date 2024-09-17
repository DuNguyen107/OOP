#include<iostream>
using namespace std;

class PhanSo{
	private:
		int tuSo, mauSo;
	public:
		PhanSo(){
			this->tuSo = 0;
			this->mauSo = 1;
		}
		// PhanSo(int tu, int mau) : tu(tu), mau(mau) {}
		PhanSo(int tuSo, int mauSo){
			this->tuSo = tuSo;
			this->mauSo = mauSo;
		}
		PhanSo(int n){
			this->tuSo = n;
			this->mauSo = 1;
		}
		PhanSo(const PhanSo &p){
			this->tuSo = p.tuSo;
			this->mauSo = p.mauSo;
		}
//		void nhap();
//		void xuat();
		friend istream& operator >>(istream &is, PhanSo &p);
		friend ostream& operator <<(ostream &os, PhanSo p);
		int getTuSo();
		void setTuSo(int tuSo);
		int getMauSo();
		void setMauSo(int mauSo);
		void NghichDao();
		void RutGon();
//		void congPhanSo(PhanSo a, PhanSo b);
//		void truPhanSo(PhanSo a, PhanSo b);
//		void nhanPhanSo(PhanSo a, PhanSo b);
//		void chiaPhanSo(PhanSo a, PhanSo b);
		friend PhanSo operator + (PhanSo a, PhanSo b);
		PhanSo operator - (PhanSo a);
		friend PhanSo operator * (PhanSo a, PhanSo b);
		PhanSo operator / (PhanSo a);
		friend bool operator == (PhanSo a, PhanSo b);
		bool operator < (PhanSo a);
		friend bool operator > (PhanSo a, PhanSo b); 
};

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}
//void PhanSo::nhap(){
//	cout << "Nhap tu so: ";
//	cin >> tuSo;
//	cout << "Nhap mau so: ";
//	do{
//		cin >> mauSo;
//		if(mauSo == 0){
//			cout << "Mau so phai khac 0\n";
//		}
//	}
//	while(mauSo == 0);
//}
istream& operator >> (istream &is, PhanSo &p){
	cout << "Nhap tu so: "; is >> p.tuSo;
	cout << "Nhap mau so: ";
	do{
		is >> p.mauSo;
		if(p.mauSo == 0) cout << "Mau so phai khac 0\n";
	}while(p.mauSo == 0);
	return is;
}
ostream& operator <<(ostream &os, PhanSo p){
	if(p.tuSo == 0 || p.mauSo == 1)
		cout << p.tuSo;
	else if(p.tuSo == p.mauSo)
		cout << p.tuSo;
	else
		cout << p.tuSo << "/" << p.mauSo;
	return os;
}
//void PhanSo::xuat(){
//	if(tuSo == 0 || mauSo == 1)
//		cout << tuSo;
//	else if(mauSo == tuSo)
//		cout << tuSo;
//	else
//		cout << tuSo << '/' << mauSo;
//	cout << endl;
//}
void PhanSo::RutGon(){
    int p = GCD(tuSo, mauSo);
    tuSo/=p;
    mauSo/=p;
}
void PhanSo::NghichDao(){
	if(tuSo == 0){
		cout << "Khong nghich dao duoc\n";
	}	
	else
	{
		int tmp = this->tuSo;
		this->tuSo = this->mauSo;
		this->mauSo = tmp;
	}
}
int PhanSo::getTuSo(){
	return this->tuSo;
}
void PhanSo::setTuSo(int tuSo){
	this->tuSo = tuSo;
}
int PhanSo::getMauSo(){
	return this->mauSo;
}
void PhanSo::setMauSo(int mauSo){
	if(mauSo!=0)
		this->mauSo = mauSo;
	else
		cout << "Mau so phai khac 0";
}

PhanSo operator + (PhanSo a, PhanSo b){
	PhanSo p;
	p.tuSo = a.tuSo*b.mauSo + a.mauSo*b.tuSo;
	p.mauSo = a.mauSo * b.mauSo;
	return p;
}
PhanSo PhanSo::operator - (PhanSo a){
	PhanSo p;
	p.tuSo = tuSo*a.mauSo - mauSo*a.tuSo;
	p.mauSo = mauSo * a.mauSo;
	return p;
}
PhanSo operator * (PhanSo a, PhanSo b){
	PhanSo p;
	p.tuSo = a.tuSo*b.tuSo;
	p.mauSo = a.mauSo * b.mauSo;
	return p;
}
PhanSo PhanSo::operator / (PhanSo a){
	PhanSo p;
	p.tuSo = a.tuSo*mauSo;
	p.mauSo = a.mauSo *tuSo;
	return p;
}
//void PhanSo::congPhanSo(PhanSo a, PhanSo b){
//	this->tuSo = a.tuSo*b.mauSo + a.mauSo*b.tuSo;
//	this->mauSo = a.mauSo * b.mauSo;
//}
//
//void PhanSo::truPhanSo(PhanSo a, PhanSo b){
//	this->tuSo = a.tuSo*b.mauSo - a.mauSo*b.tuSo;
//	this->mauSo = a.mauSo * b.mauSo;
//}
//void PhanSo::nhanPhanSo(PhanSo a, PhanSo b){
//	this->tuSo = a.tuSo*b.tuSo;
//	this->mauSo = a.mauSo*b.mauSo;
//}
//void PhanSo::chiaPhanSo(PhanSo a, PhanSo b){
//	this->tuSo = a.tuSo*b.mauSo;
//	this->mauSo = a.mauSo*b.tuSo;
//}
bool PhanSo :: operator <(PhanSo a){
	return tuSo*a.mauSo < a.tuSo*mauSo;
}
bool operator > (PhanSo a, PhanSo b){
	return a.tuSo*b.mauSo > b.tuSo*a.mauSo;
}
bool operator == (PhanSo a, PhanSo b){
	return a.tuSo*b.mauSo == b.tuSo*a.mauSo;
}
void Menu(){
	cout << "---MENU---\n";
	cout << "Nhap lua chon tu 1 den 10\n";
	cout << "1. Nhap phan so\n";
	cout << "2. In phan so\n";
	cout << "3. Rut gon phan so\n";
	cout << "4. Nghich dao phan so\n";
	cout << "5. Cong hai phan so\n";
	cout << "6. Tru hai phan so\n";
	cout << "7. Nhan hai phan so\n";
	cout << "8. Chia hai phan so\n";
	cout << "9. So sanh hai phan so\n";
	cout << "10. Thoat chuong trinh\n";
	cout << "--------------\n";
	cout << endl;
}


int main(){
	PhanSo p, q, kq;
	int luachon;
	while(true){
		Menu();
		cin >> luachon;
		switch(luachon){
			case 10:
				cout << "Ban co chac chan muon thoat chuong trinh: Co(Nhan Y) , Khong(Nhan N)\n ";
				char c; cin >> c;
				if(c == 'Y' || c == 'y'){
					cout << "Chuong trinh da thoat!\n";
					return 0;
				}
			case 1:
				cout << "Nhap phan so \n"; cin >> p;
				cout << "\n-----------------------\n";
				break;
			case 2:
				cout << "Ket qua phan so: "; cout << p;
				cout << "\n-----------------------\n";
				break;
			case 3:
				p.RutGon();
				cout << "\n-----------------------\n";
				break;
			case 4:
				p.NghichDao();
				cout << "\n-----------------------\n";
				break;
			case 5:
				cout << "Nhap phan so thu nhat:\n"; cin >> p;
				cout << "Nhap phan so thu hai:\n"; cin >> q;
				cout << "Cong hai phan so: "; kq = p + q;
				kq.RutGon(); cout << kq;
				cout << "\n-----------------------\n";
				break;
			case 6:
				cout << "Nhap phan so thu nhat:\n"; cin >> p;
				cout << "Nhap phan so thu hai:\n"; cin >> q;
				cout << "Tru hai phan so: "; kq = p - q;
				kq.RutGon(); cout << kq;
				cout << "\n-----------------------\n";
				break;
			case 7:
				cout << "Nhap phan so thu nhat:\n"; cin >> p;
				cout << "Nhap phan so thu hai:\n"; cin >> q;
				cout << "Nhan hai phan so: "; kq = p * q;
				kq.RutGon(); cout << kq;
				cout << "\n-----------------------\n";
				break;
			case 8:
				cout << "Nhap phan so thu nhat:\n"; cin >> p;
				cout << "Nhap phan so thu hai:\n"; cin >> q;
				cout << "Chia hai phan so: "; kq = p / q;
				kq.RutGon(); cout << kq;
				cout << "\n-----------------------\n";
				break;
			case 9:
				cout << "Nhap phan so thu nhat:\n"; cin >> p;
				cout << "Nhap phan so thu hai:\n"; cin >> q;
				cout << "So sanh hai phan so: " << p << " va " << q << endl;
				cout << "Ket qua: ";
				if(p<q) cout << p << " < " << q;
				else if (p>q) cout << p << " > " << q;
				else cout << p << " = " << q;
				cout << "\n-----------------------\n";
				break;
			default:
				cout << "Lua chon khong hop le! Vui long chon lai.\n";
				cout << "\n-----------------------\n";
		}
	}
}