#include<iostream>
#include<cmath>
using namespace std;

class TaiKhoan
{
	private:
		float m_fSoDu = 0;
	public:
		float baoSoDu() { return m_fSoDu; }
		void napTien(float fSoTien) { m_fSoDu += fSoTien; }
		void rutTien(float fSoTien){
			if (fSoTien <= m_fSoDu)
				m_fSoDu -= fSoTien;
		}
};

class TaiKhoanTietKiem: public TaiKhoan{
	private:
		int kyHanGui;
		double laiSuat;
		int soThangDaGui;
	public:
		TaiKhoanTietKiem(){};
		TaiKhoanTietKiem(int kyHanGui, double laiSuat) : kyHanGui(kyHanGui), laiSuat(laiSuat), soThangDaGui(0) {}
		void napTien(float fSoTien){
			soThangDaGui = 0;
			return TaiKhoan::napTien(fSoTien);
		}
		void rutTien(float fSoTien){
			if(soThangDaGui >= kyHanGui)
				TaiKhoan::rutTien(fSoTien);
			else
				cout << "Khong the rut tien vi chua toi ki han !!\n";
		}
		void tangSoThang(int thang){
			soThangDaGui += thang;
			if(soThangDaGui > kyHanGui){
				soThangDaGui = kyHanGui;
			}
		}
		float tinhSoDu(){
			double lai = (double)(baoSoDu() * laiSuat / 100) * (double)(soThangDaGui / 12.0);
			return baoSoDu() + lai;
		}
		void thongTinTaiKhoan() {
	        cout << "So thang da gui: " << soThangDaGui << endl;
	        cout << "Ky han: " << kyHanGui << " tháng" << endl;
	        cout << "Lai suat: " << laiSuat << "%" << endl;
	        cout << "So du hien tai: " << tinhSoDu() << endl;
    	}
};
void Menu(){
	cout << "1.Nap tien\n";
	cout << "2.Rut tien\n";
	cout << "3.Tang so thang da gui\n";
	cout << "4.Xem so du tai khoan\n";
	cout << "5.Xem thong tin tai khoan\n";
}
void test(){
	int choose;
	Menu();
	cout << "Nhap lua chon: \n"; cin >> choose;
	TaiKhoanTietKiem p(12,0.7);
	switch(choose){
		case 1:
			cout << "Nhap so tien muon nap: ";
			int n; cin >> n;
			p.napTien(n);
			cout << "Nap thanh cong !!\n";
			break;
		case 2:
			cout << "Nhap so tien muon rut: ";
			cin >> n;
			p.rutTien(n);
			cout << "Rut thanh cong !!\n";
			break;
		case 3:
			cout << "Nhap so thang muon tang: ";
			cin >> n;
			p.tangSoThang(n);
			break;
		case 4:
			cout << "So du tai khoan hien tai la: ";
			cout << p.baoSoDu();
			break;
		case 5:
			p.thongTinTaiKhoan();
			break;
	}
}
int main(){
	char c;
	while(1){
		test();
		cout << "Ban muon thoat(n) hay tiep tuc(y) chuong trinh(y/n)\n"; cin >> c;
		if(c == 'n' || c == 'N') break;
	}
}
