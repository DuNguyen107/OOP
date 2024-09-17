#include <iostream>
#include <math.h>
using namespace std;

class DonThuc{
	private:
		float heSo, soMu;
	public:
		void nhap();
		void xuat();
		float getHeSo();
		float getSoMu();
		void setHeSo(float heSo);
		void setSoMu(float soMu);
		float getGiaTri(float x);
		DonThuc getDaoHam();
		DonThuc getNguyenHam();
		DonThuc cong(const DonThuc& a);
		DonThuc nhan(const DonThuc& a);
		int soSanh(const DonThuc& a);
};
void DonThuc::nhap(){
	cout << "Nhap He So Da Thuc: "; cin >> this->heSo;
	cout << "Nhap So Mu Da Thuc: "; cin >> this->soMu;
}
void DonThuc::xuat(){
	if(this->soMu == 0) cout << this->heSo << endl;
	else if(this->soMu == 1) cout << this->heSo << "X" << endl;
	else{
		cout << this->heSo << "X^" << this->soMu << endl;
	}
}
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
DonThuc DonThuc::cong(const DonThuc& a){
	DonThuc x;
	x.heSo = this->heSo + a.heSo;
	x.soMu = this->soMu;
	return x;
}
DonThuc DonThuc::nhan(const DonThuc& a){
	DonThuc x;
	x.heSo = this->heSo * a.heSo;
	x.soMu = this->soMu*2;
	return x;
}
int DonThuc::soSanh(const DonThuc &a){
	if(this->heSo > a.heSo) return 1;
	else if(this->heSo < a.heSo) return -1;
	return 0;
}

main(){
	DonThuc a;
	a.nhap();
	a.xuat();
	
	cout << "He So: " << a.getHeSo() << endl;
	cout << "So Mu: " << a.getSoMu() << endl;	
	
	DonThuc b;
	float heso = 2;
	float  somu = 4;
	b.setHeSo(heso);
	b.setSoMu(somu);
	
	
	float x = 2;
	cout << "Gia Tri Cua Don Thuc b(" << x <<") = " << b.getGiaTri(x) << endl;
	
	DonThuc daoHamB = b.getDaoHam();
	cout << "Dao Ham" << endl;
	daoHamB.xuat();
	DonThuc nguyenHamB = b.getNguyenHam();
	cout << "Nguyen Ham" << endl;
	nguyenHamB.xuat();
	
	DonThuc tong = b.cong(a);
	cout << "a + b = ";
	tong.xuat();
	
	DonThuc tich = b.nhan(a);
	cout << "a * b = ";
	tich.xuat();
		
}