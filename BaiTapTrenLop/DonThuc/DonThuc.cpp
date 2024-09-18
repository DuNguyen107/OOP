#include <iostream>
#include <cmath>
using namespace std;

class DonThuc{
	private:
		float heSo, soMu;
	public:
//		void nhap();
//		void xuat();
		friend istream& operator >> (istream &is, DonThuc &p);
		friend ostream& operator << (ostream &os, DonThuc p);
		float getHeSo();
		float getSoMu();
		void setHeSo(float heSo);
		void setSoMu(float soMu);
		float getGiaTri(float x);
		DonThuc getDaoHam();
		DonThuc getNguyenHam();
//		DonThuc cong(const DonThuc& a);
//		DonThuc nhan(const DonThuc& a);
		friend DonThuc operator + (const DonThuc &a, const DonThuc &b);
		friend DonThuc operator - (const DonThuc &a, const DonThuc &b);
		DonThuc operator * (const DonThuc &a);
		DonThuc operator / (const DonThuc &b);
		bool operator == (const DonThuc &a);
		friend DonThuc operator > (const DonThuc &a, const DonThuc &b);
		friend DonThuc operator < (const DonThuc &a, const DonThuc &b);
//		int soSanh(const DonThuc& a);
};
istream& operator >>(istream &is, DonThuc &p){
	cout << "Nhap He So Da Thuc: "; cin >> p.heSo;
	cout << "Nhap So Mu Da Thuc: "; cin >> p.soMu;
	return is;
}
ostream& operator<<(ostream &os, DonThuc p){
	cout << "Ket qua: ";
	if(p.soMu == 0) cout << p.heSo << endl;
	else if(p.soMu == 1) cout << p.heSo << "X" << endl;
	else if(p.heSo == 0) cout << "0" << endl;
	else{
		cout << p.heSo << "X^" << p.soMu << endl;
	}
	return os;
}
//void DonThuc::nhap(){
//	cout << "Nhap He So Da Thuc: "; cin >> this->heSo;
//	cout << "Nhap So Mu Da Thuc: "; cin >> this->soMu;
//}
//void DonThuc::xuat(){
//	if(this->soMu == 0) cout << this->heSo << endl;
//	else if(this->soMu == 1) cout << this->heSo << "X" << endl;
//	else{
//		cout << this->heSo << "X^" << this->soMu << endl;
//	}
//}
float DonThuc::getHeSo(){
	return this->heSo;
}
float DonThuc::getSoMu(){
	return this->soMu;
}
void DonThuc::setHeSo(float heSo){
	this->heSo = heSo;
}
void DonThuc::setSoMu(float soMu){
	this->soMu = soMu;
}
float DonThuc::getGiaTri(float x){
	return this->heSo*pow(x, this->soMu);
}
DonThuc DonThuc::getDaoHam(){
	DonThuc x;
	if(this->soMu == 0) {
		x.heSo = 0;
		x.soMu = 0;
	}
	else{
		x.heSo = this->heSo*this->soMu;
		x.soMu = this->soMu - 1;
	}
	return x;
}
DonThuc DonThuc::getNguyenHam(){
	DonThuc x;
	x.heSo = this->heSo/(this->soMu + 1);
	x.soMu = this->soMu + 1;
	return x;
}
//DonThuc DonThuc::cong(const DonThuc& a){
//	DonThuc x;
//	x.heSo = this->heSo + a.heSo;
//	x.soMu = this->soMu;
//	return x;
//}
//DonThuc DonThuc::nhan(const DonThuc& a){
//	DonThuc x;
//	x.heSo = this->heSo * a.heSo;
//	x.soMu = this->soMu*2;
//	return x;
//}
//int DonThuc::soSanh(const DonThuc &a){
//	if(this->heSo > a.heSo) return 1;
//	else if(this->heSo < a.heSo) return -1;
//	return 0;
//}
DonThuc operator + (const DonThuc &a, const DonThuc &b){
	DonThuc p;
	p.heSo = a.heSo + b.heSo;
	p.soMu = p.soMu;
	return p;
}
DonThuc operator - (const DonThuc &a, const DonThuc &b){
	DonThuc p;
	p.heSo = a.heSo - b.heSo;
	p.soMu = p.soMu;
	return p;
}
DonThuc DonThuc::operator * (const DonThuc &a){
	DonThuc p;
	p.heSo = a.heSo * heSo;
	p.soMu = soMu*2;
	return p;
}
DonThuc DonThuc::operator / (const DonThuc &a){
	DonThuc p;
	p.heSo = (float)a.heSo / heSo;
	p.soMu = abs(a.soMu - soMu); 
	return p;
} 
void Menu(){
	cout << "\n-------------------------------\n";
	cout << "        MENU\n";
	cout << "1.Nhap, xuat don thuc\n";
	cout << "2.Tinh dao ham\n";
	cout << "3.Tinh nguyen ham\n";
	cout << "4.Cong hai don thuc\n";
	cout << "5.Tru hai don thuc\n";
	cout << "6.Nhan hai don thuc\n";
	cout << "7.Chia hai don thuc\n";
	cout << "\n-------------------------------\n";
}
void test(int choose){
	switch(choose){
		DonThuc a,b,kq;
		case 1:
			cin >> a; cout << a;
			cout << "\n-------------------------------\n";
			break;
		case 2:
			cin >> kq;
			a = kq.getDaoHam();
			cout << a;
			cout << "\n-------------------------------\n";
			break;
		case 3:
			cin >> kq;
			a = kq.getNguyenHam();
			cout << a;
			cout << "\n-------------------------------\n";
			break;
		case 4:
			cin >> a; cin >> b;
			kq = a+b;
			cout << kq;
			cout << "\n-------------------------------\n";
			break;
		case 5:
			cin >> a; cin >> b;
			kq = a-b;
			cout << kq;
			cout << "\n-------------------------------\n";
			break;
		case 6:
			cin >> a; cin >> b;
			kq = a*b;
			cout << kq;
			cout << "\n-------------------------------\n";
			break;
		case 7:
			cin >> a; cin >> b;
			kq = a/b;
			cout << kq;
			cout << "\n-------------------------------\n";
			break;
		case 8:
			cin >> a; cin >> b;
			kq = a+b;
			cout << kq;
			cout << "\n-------------------------------\n";
			break;		
	}
}
int main(){
	Menu();
	cout << "Moi ban nhap lua chon: ";
	int choose; cin >> choose;
	while(1){
		test(choose);	
		char check;
		cout << "Ban muon tiep tuc(Y) hay thoat (N): ";
		cin >> check;
		if(check == 'N' || check == 'n'){
			cout << "Chuong trinh da thoat !!\n";
			break;
		}		
	}	
}