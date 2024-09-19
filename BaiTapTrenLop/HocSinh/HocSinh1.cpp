#include<iostream>
#include<string>
#include<vector>
using namespace std;

class HocSinh{
	private:
		static int idCount;
		int id; 
		string hoTen;
		double diemVan, diemToan;
	public:
		HocSinh();
		HocSinh(string hoTen, double diemVan, double diemToan);
		HocSinh(string hoTen);
		HocSinh(const HocSinh &hs);
		~HocSinh(){};
		friend istream& operator >>(istream &is, HocSinh &hs);
		friend ostream& operator <<(ostream &os, const HocSinh &hs);
		double diemTrungBinh() const;
		HocSinh operator = (const HocSinh &hs);
		bool operator == (const HocSinh &hs) const;
		bool operator >= (const HocSinh &hs) const;
		bool operator <= (const HocSinh &hs) const;
		friend bool operator != (const HocSinh &hs1, const HocSinh &hs2);
		friend bool operator > (const HocSinh &hs1, const HocSinh &hs2);
		friend bool operator < (const HocSinh &hs1, const HocSinh &hs2);
};
int HocSinh::idCount = 1;
istream& operator >> (istream& is, HocSinh &hs){
	is.ignore();
	cout << "Nhap ho ten: "; getline(is, hs.hoTen);
	cout << "Nhap diem van: "; is >> hs.diemVan;
	cout << "Nhap diem toan: "; is >> hs.diemToan;
	hs.id = HocSinh::idCount++;
	return is;
}
ostream& operator << (ostream& os, const HocSinh &hs){
	os << hs.id << "\t\t\t" << hs.hoTen << "\t\t" << hs.diemVan << "\t\t\t";
	os << hs.diemToan << "\t\t\t" << hs.diemTrungBinh() << "\t\t" << endl;
	return os;
}
HocSinh::HocSinh(){
	this->hoTen = "";
	this->diemVan = 0;
	this->diemToan = 0;
}
HocSinh::HocSinh(string hoTen, double diemVan, double diemToan){
	this->hoTen = hoTen;
	this->diemVan = diemVan;
	this->diemToan = diemToan;
}
HocSinh::HocSinh(string hoTen){
	this->hoTen = hoTen;
	this->diemVan = 0;
	this->diemToan = 0;
}
HocSinh::HocSinh(const HocSinh &hs) {
    this->hoTen = hs.hoTen;
    this->diemVan = hs.diemVan;
    this->diemToan = hs.diemToan;
}
double HocSinh::diemTrungBinh() const{
	return (diemVan+diemToan)/2;
}
HocSinh HocSinh::operator =(const HocSinh &hs){
	if(this != &hs){
		hoTen = hs.hoTen;
		diemVan = hs.diemVan;
		diemToan = hs.diemToan;
	}
	return *this;
}
bool HocSinh::operator ==(const HocSinh &hs) const{
	return diemTrungBinh() == hs.diemTrungBinh();
}
bool HocSinh::operator >=(const HocSinh &hs) const{
	return diemTrungBinh() >= hs.diemTrungBinh();
}
bool HocSinh::operator <=(const HocSinh &hs) const{
	return diemTrungBinh() <= hs.diemTrungBinh();
}
bool operator != (HocSinh &hs1, HocSinh &hs2){
	return hs1.diemTrungBinh() != hs2.diemTrungBinh();
}
bool operator > (HocSinh &hs1, HocSinh &hs2){
	return hs1.diemTrungBinh() > hs2.diemTrungBinh();
}
bool operator < (HocSinh &hs1, HocSinh &hs2){
	return hs1.diemTrungBinh() < hs2.diemTrungBinh();
}
void SapXep(vector<HocSinh> &ds, int n){
	for(int i=1; i<n; i++){
		HocSinh idx = ds[i];
		int temp = i-1;
		double val = ds[i].diemTrungBinh();
		while(temp >= 0 && ds[temp].diemTrungBinh() > val){
			ds[temp + 1] = ds[temp];
			--temp;
		}
		ds[temp+1] = idx;
	}
}
void NhapDanhSach(vector<HocSinh> &ds, int n){
	ds.resize(n); 
    for (int i=0; i<n; i++) {
        cout << "Nhap thong tin hoc sinh thu " << i+1 << "\n";
        cin >> ds[i];
    }
}
void XuatDanhSach(const vector<HocSinh>& ds, int n){
	cout << "Ma hoc sinh\t\tHo ten\t\tDiem Van\t\tDiem Toan\t\tDiem trung binh\t\t\n";
	for (int i = 0; i < n; i++) {
        cout << ds[i];
    }
}
void Menu(){
	cout << "\n----------------------------MENU----------------------------\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Sap xep danh sach tang dan theo diem trung binh\n";
	cout << "\n------------------------------------------------------------\n";
}
void test(int choose, vector<HocSinh> &ds, char &n){
	switch(choose){
		case 1:
			do{
				cout << "Nhap so danh sach hoc sinh muon nhap: ";
		    	cin >> n;
		    	if(!isdigit(n)){
		    		cout << "Phai nhap ki tu so !! Vui long nhap lai\n";
				}
			}while(!isdigit(n));
		    n = n - '0';
			NhapDanhSach(ds,n);
			cout << "\n---------------------------------------\n";
			break;
		case 2:
			cout << "\n-------------------DANH SACH HOC SINH-------------------\n";
			XuatDanhSach(ds,n);
			cout << "\n---------------------------------------\n";
			break;
		case 3:
			SapXep(ds,n);
			cout << "\n-------------------DANH SACH HOC SINH-------------------\n";
			XuatDanhSach(ds,n);
			cout << "\n---------------------------------------\n";
			break;
	}
}

int main(){
	Menu();
	int choose;
	vector<HocSinh> ds;
	char n = '0';
	while(1){
		do{
			cout << "Moi nhap lua chon: ";
			cin >> choose;
			if(choose < 1 || choose > 3)
				cout << "Nhap khong dung !! Nhap lai \n";
		}while(choose < 1 || choose > 3);
		test(choose, ds, n);
		char ok; 
		cout << "Ban muon tiep tuc(Y) hay thoat chuong trinh(N): "; cin >> ok;
		if(ok == 'N' || ok == 'n')
			break;
	}
    return 0;
}