#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Printer {
	protected:
	   string Name;
	public:
	   virtual void nhap() {
	       cout << "Nhap ten may in: ";
	       cin.ignore();
	       getline(cin, Name);
	   }
	   
	   virtual void hienthi() const {
	       cout << "Ten may in: " << Name << endl;
	   }
	   
	   bool operator>(const Printer& other) const {
	       return this->Name > other.Name;
	   }
	   
	   string getName() const { return Name; }
	   
	   virtual ~Printer() {}
};

class Laser : public Printer {
	protected:
	   int Dpi;
	public:
	   void nhap() override {
	       Printer::nhap();
	       cout << "Nhap do phan giai (Dpi): ";
	       cin >> Dpi;
	   }
	   
	   void hienthi() const override {
	       Printer::hienthi();
	       cout << "Do phan giai: " << Dpi << endl;
	   }
};

class ColorLaser : public Laser {
	private:
	   int Color; 
	public:
	   void nhap() override {
	       Laser::nhap();
	       cout << "Nhap so mau ho tro: ";
	       cin >> Color;
	   }
	   
	   void hienthi() const override {
	       Laser::hienthi();
	       cout << "So mau ho tro: " << Color << endl;
	   }
};
bool compare(Printer* a, Printer* b) {
   return a->getName() < b->getName();
}

int main() {
   int n_laser, n_colorlaser;
   
   cout << "Nhap so luong may in Laser: ";
   cin >> n_laser;
   
   cout << "Nhap so luong may in ColorLaser: ";
   cin >> n_colorlaser;
   
   Printer** ds_laser = new Printer*[n_laser];
   Printer** ds_colorlaser = new Printer*[n_colorlaser];
   
   cout << "\nNHAP THONG TIN MAY IN LASER:\n";
   for(int i = 0; i < n_laser; i++) {
       cout << "\nNhap thong tin may in Laser thu " << i + 1 << ":\n";
       ds_laser[i] = new Laser();
       ds_laser[i]->nhap();
   }
   
   cout << "\nNHAP THONG TIN MAY IN COLOR LASER:\n";
   for(int i = 0; i < n_colorlaser; i++) {
       cout << "\nNhap thong tin may in ColorLaser thu " << i + 1 << ":\n";
       ds_colorlaser[i] = new ColorLaser();
       ds_colorlaser[i]->nhap();
   }
   
   sort(ds_laser, ds_laser + n_laser, compare);
   
   sort(ds_colorlaser, ds_colorlaser + n_colorlaser, compare);
   
   cout << "\nTHONG TIN MAY IN LASER (da sap xep):\n";
   for(int i = 0; i < n_laser; i++) {
       cout << "\nMay in Laser thu " << i + 1 << ":\n";
       ds_laser[i]->hienthi();
   }
   
   cout << "\nTHONG TIN MAY IN COLOR LASER (da sap xep):\n";
   for(int i = 0; i < n_colorlaser; i++) {
       cout << "\nMay in ColorLaser thu " << i + 1 << ":\n";
       ds_colorlaser[i]->hienthi();
   }
   
   for(int i = 0; i < n_laser; i++) {
       delete ds_laser[i];
   }
   delete[] ds_laser;
   
   for(int i = 0; i < n_colorlaser; i++) {
       delete ds_colorlaser[i];
   }
   delete[] ds_colorlaser;
   
   return 0;
}