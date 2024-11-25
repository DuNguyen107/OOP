#include <iostream>
#include <string>
using namespace std;

class SV {
	protected:
	   string lophoc;
	   string hoten;
	public:
	   virtual void nhap() {
	       cout << "Nhap lop hoc: ";
	       cin.ignore();
	       getline(cin, lophoc);
	       cout << "Nhap ho ten: ";
	       getline(cin, hoten);
	   }
	   
	   virtual void hienthi() const {
	       cout << "Lop hoc: " << lophoc << endl;
	       cout << "Ho ten: " << hoten << endl;
	   }
	   
	   virtual ~SV() {}
};

class SVSP : public SV {
	private:
	   double hocbong;
	public:
	   void nhap() override {
	       SV::nhap();
	       cout << "Nhap hoc bong: ";
	       cin >> hocbong;
	   }
	   
	   void hienthi() const override {
	       SV::hienthi(); 
	       cout << "Hoc bong: " << hocbong << endl;
	   }
};


class SVTC : public SV {
	private:
	   double hocphi;
	public:
	   void nhap() override {
	       SV::nhap(); 
	       cout << "Nhap hoc phi: ";
	       cin >> hocphi;
	   }
	   
	   void hienthi() const override {
	       SV::hienthi(); 
	       cout << "Hoc phi: " << hocphi << endl;
	   }
};

int main() {
   int n_sp, n_tc;
  
   cout << "Nhap so luong sinh vien su pham: ";
   cin >> n_sp;
   
   cout << "Nhap so luong sinh vien tai chuc: ";
   cin >> n_tc;
   
   SV** ds_svsp = new SV*[n_sp];
   SV** ds_svtc = new SV*[n_tc];
   
   cout << "\nNHAP THONG TIN SINH VIEN SU PHAM:\n";
   for(int i = 0; i < n_sp; i++) {
       cout << "\nNhap thong tin sinh vien su pham thu " << i + 1 << ":\n";
       ds_svsp[i] = new SVSP();
       ds_svsp[i]->nhap();
   }
  
   cout << "\nNHAP THONG TIN SINH VIEN TAI CHUC:\n";
   for(int i = 0; i < n_tc; i++) {
       cout << "\nNhap thong tin sinh vien tai chuc thu " << i + 1 << ":\n";
       ds_svtc[i] = new SVTC();
       ds_svtc[i]->nhap();
   }
   
   cout << "\nTHONG TIN SINH VIEN SU PHAM\n";
   for(int i = 0; i < n_sp; i++) {
       cout << "\nSinh vien thu " << i + 1 << "\n";
       ds_svsp[i]->hienthi();
   }
   
   cout << "\nTHONG TIN SINH VIEN TAI CHUC\n";
   for(int i = 0; i < n_tc; i++) {
       cout << "\nSinh vien thu " << i + 1 << "\n";
       ds_svtc[i]->hienthi();
   }
   
   for(int i = 0; i < n_sp; i++)
       delete ds_svsp[i];
   delete[] ds_svsp;
   
   for(int i = 0; i < n_tc; i++)
       delete ds_svtc[i];
   delete[] ds_svtc;
   return 0;
}