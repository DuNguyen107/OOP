#include <iostream>
#include <string>
using namespace std;

class MatHang {
	protected:
	   string Ten;
	public:
	   virtual void nhap() {
	       cout << "Nhap ten mat hang: ";
	       cin.ignore();
	       getline(cin, Ten);
	   }
	   
	   virtual void hienthi() const {
	       cout << "Ten mat hang: " << Ten << endl;
	   }
	   
	   virtual ~MatHang() {}
};

class MayTinh : public MatHang {
	private:
	   int Speed;
	public:
	   void nhap() override {
	       MatHang::nhap(); // Gọi hàm nhập của lớp cơ sở
	       cout << "Nhap toc do (Speed): ";
	       cin >> Speed;
	   }
	   
	   void hienthi() const override {
	       MatHang::hienthi(); // Gọi hàm hiển thị của lớp cơ sở
	       cout << "Toc do: " << Speed << endl;
	   }
};

class MayIn : public MatHang {
	private:
	   int Dpi;
	public:
	   void nhap() override {
	       MatHang::nhap(); 
	       cout << "Nhap do phan giai (Dpi): ";
	       cin >> Dpi;
	   }
	   
	   void hienthi() const override {
	       MatHang::hienthi(); 
	       cout << "Do phan giai: " << Dpi << endl;
	   }
};

int main() {
   int n_mt, n_mi;
   
   cout << "Nhap so luong may tinh: ";
   cin >> n_mt;
   
   cout << "Nhap so luong may in: ";
   cin >> n_mi;
   
   MatHang** ds_maytinh = new MatHang*[n_mt];
   MatHang** ds_mayin = new MatHang*[n_mi];
   
   cout << "\nNHAP THONG TIN MAY TINH:\n";
   for(int i = 0; i < n_mt; i++) {
       cout << "\nNhap thong tin may tinh thu " << i + 1 << ":\n";
       ds_maytinh[i] = new MayTinh();
       ds_maytinh[i]->nhap();
   }
   
   cout << "\nNHAP THONG TIN MAY IN:\n";
   for(int i = 0; i < n_mi; i++) {
       cout << "\nNhap thong tin may in thu " << i + 1 << ":\n";
       ds_mayin[i] = new MayIn();
       ds_mayin[i]->nhap();
   }
   
   cout << "\nTHONG TIN CAC MAY TINH:\n";
   for(int i = 0; i < n_mt; i++) {
       cout << "\nMay tinh thu " << i + 1 << ":\n";
       ds_maytinh[i]->hienthi();
   }
   
   cout << "\nTHONG TIN CAC MAY IN:\n";
   for(int i = 0; i < n_mi; i++) {
       cout << "\nMay in thu " << i + 1 << ":\n";
       ds_mayin[i]->hienthi();
   }
   
   for(int i = 0; i < n_mt; i++) {
       delete ds_maytinh[i];
   }
   delete[] ds_maytinh;
   
   for(int i = 0; i < n_mi; i++) {
       delete ds_mayin[i];
   }
   delete[] ds_mayin;
   
   return 0;
}