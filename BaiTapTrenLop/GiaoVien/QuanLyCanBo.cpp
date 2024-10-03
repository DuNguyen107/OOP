#include<iostream>
#include<string>
using namespace std;

class CanBo{
	protected:
		string hoTen;
		int tuoi, gioiTinh;
		string diaChi;	
	public:
		CanBo(){};
		CanBo(string hoTen, int tuoi, int gioiTinh, string diaChi);
		void themCanBo();
		void hienThiThongTin();	
};
CanBo::CanBo(string hoTen, int tuoi, int gioiTinh, string diaChi){
	this->hoTen = hoTen;
	this->tuoi = tuoi;
	this->gioiTinh = gioiTinh;
	this->diaChi = diaChi;
}
void CanBo::themCanBo(){
	cin.ignore();
	cout << "Nhap ho ten: "; getline(cin, hoTen);
	cout << "Nhap tuoi: ";  cin >> this->tuoi;
	do{
		cout << "Nhap gioi tinh: 1.Nam\t2.Nu\t3.Khac"; cin >> this->gioiTinh;
		if(this->gioiTinh < 1 || this->gioiTinh > 3)
			cout << "Nhap lai\n";
	}while(this->gioiTinh < 1 || this->gioiTinh > 3);
	cin.ignore();
	cout << "Nhap dia chi: "; cin >> this->diaChi;
}
void CanBo::hienThiThongTin(){
	cout << "Ho ten: " << hoTen << endl;
	cout << "Tuoi: " << tuoi << endl;
	cout << "Gioi tinh: "; 
	if (gioiTinh == 1)
		cout << "Nam" << endl;
	else if (gioiTinh == 2)
		cout << "Nu" << endl;
	else
		cout << "Khac" << endl;
	cout << "Dia chi: " << diaChi << endl;
}

class QLCB{
	private:
		CanBo ds[100];
		int n = 0;
	public:
		void themCanBo(CanBo cb);
		void xoaCanBo(string hoTen);
		void timKiemTheoHoTen(string hoTen);
		void hienThiDanhSach();
};
void QLCB::themCanBo(CanBo cb){
	ds[n].themCanBo();
	n++;
}
void QLCB::xoaCanBo(string hoTen){
	for(int i=0; i<n; i++){
		if(ds[i].hoTen == hoten){
			for(int j=i; j<n; j++){
				ds[j] = ds[j+1];
			}
			n--;
		}
		return;
	}
	cout << "Khong co can bo " << hoTen << "trong danh sach\n" << endl;
}
void QLCB::timKiemTheoHoTen(string hoTen){
	for(int i=0; i<n; i++){
		if(ds[i]->hoTen == hoten){
			ds[i].hienThiThongTin()
			return;
		}
	}
	cout << "Khong co can bo " << hoTen << "trong danh sach\n" << endl;	cout << "Khong co can bo " << hoTen << "trong danh sach\n" << endl;
}
void QLCB::hienThiDanhSach(){
	for(int i=0; i<n; i++){
		ds[i].hienThiThongTin();
	}
}
class CongNhan: public CanBo{
	private:
		int bac;
	public:
		CongNhan(){}
		void themCongNhan();
		void hienThiCongNhan();
};
class KySu: public CanBo{
	private:
		string nganhDaoTao;
	public:
		KySu(){}
		void themKySu();
		void hienThiKySu();
};
class NhanVien{
	private:
		string congViec;
	public:
		void themNhanVien();
		void hienThiNhanVien();
};
void CongNhan::themCongNhan(){
	CanBo::themCanBo();
	cout << "Nhap bac (1-10): "; cin >> bac;
}
void CongNhan::hienThiCongNhan(){
	CanBo::hienThiThongTin();
	cout << "Bac cong nhan: " << bac << endl;
}
void KySu::themKySu(){
	CanBo::themCanBo();
	cout << "Nhap nganh dao tao: "; getline(cin, nganhDaoTao)
}
void KySu::hienThiKySu(){
	CanBo::hienThiThongTin();
	cout << "Nganh dao tao: " << nganhDaoTao << endl;
}
void NhanVien::themNhanVien(){
	CanBo::themCanBo();
	cout << "Nhap cong viec: "; getline(cin, congViec);
}
void NhanVien::hienThiNhanVien(){
	CanBo::hienThiThongTin();
	cout << "Cong viec: " << congViec << endl;
}
int main(){
	QLCB cb;
}