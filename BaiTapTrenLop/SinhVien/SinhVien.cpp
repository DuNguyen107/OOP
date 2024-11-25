//SVCN ke thua SVTC
//SVCN ke thua SVTC
#include<iostream>
#include<string>
using namespace std;

class SinhVien{
	protected:
		string lop;
		string hoten;
	public:
		SinhVien();
		SinhVien(string lop, string hoten);
		string getLop(); 
    	string getHoTen(); 
    	void setLop(string lop); 
    	void setHoTen(string hoten);
		~SinhVien();
		
		virtual void Nhap();
		virtual void Show();
};
class SVTC: public SinhVien{
	protected:
		double hocphi;
	public:
		SVTC();
		SVTC(double hocphi);
		double getHocPhi(); 
    	void setHocPhi(double hocphi);
    	void Nhap();
		void Show();
};
class SVCN: public SVTC{
	private:
		double dtb;
		string hocbong;
	public:
		SVCN();
		double getDTB(); 
    	string getHocBong(); 
    	void setDTB(double dtb); 
    	void setHocBong(); 
    	bool trangThaiHocBong();
    	void Nhap();
		void Show();
		friend bool operator > (SVCN a, SVCN b);
		friend bool operator < (SVCN a, SVCN b);
		friend bool operator == (SVCN a, SVCN b);
};
/*----------------------------------SinhVien----------------------------------*/
SinhVien::SinhVien(){
	lop = "";
	hoten = "";
}
SinhVien::SinhVien(string lop, string hoten){
	this->lop = lop;
	this->hoten = hoten;
}
string SinhVien::getLop(){
	return lop;
}
string SinhVien::getHoTen(){
	return hoten;
}
void SinhVien::setLop(string lop){
	this->lop = lop;
}
void SinhVien::setHoTen(string hoten){
	this->hoten = hoten;
}
SinhVien::~SinhVien(){
	
}
void SinhVien::Nhap() {
    cout << "Nhap lop: ";
    cin.ignore();
    getline(cin, lop);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
}
void SinhVien::Show(){
	cout << "Lop: " << lop << endl;
	cout << "Ho ten: " << hoten << endl;
}
/*----------------------------------SVTC----------------------------------*/
SVTC::SVTC(){
	hocphi = 0.0;
}
SVTC::SVTC(double hocphi){
	this->hocphi = hocphi;
}
double SVTC::getHocPhi(){
	return hocphi;
}
void SVTC::setHocPhi(double hocphi){
	this->hocphi = hocphi;
}
void SVTC::Nhap() {
    SinhVien::Nhap(); 
    cout << "Nhap hoc phi: ";
    cin >> hocphi;
}
void SVTC::Show(){
	SinhVien::Show();
	cout << "Hoc phi: " << hocphi << endl;
	cout << "---------------------------\n";
}
/*----------------------------------SVCN----------------------------------*/
SVCN::SVCN(){
	dtb = 0;
	hocbong = "Khong";
}
double SVCN::getDTB(){
	return dtb;
}
string SVCN::getHocBong(){
	return hocbong;
}
void SVCN::setDTB(double dtb){
	this->dtb = dtb;
}
void SVCN::setHocBong(){
	if (dtb >= 8) {
        this->hocbong = "Co";
    } else {
        this->hocbong = "Khong";
    }
}
bool SVCN::trangThaiHocBong() {
    return dtb >= 8.0;
}
void SVCN::Nhap() {
    SVTC::Nhap();
    cout << "Nhap DTB: ";
    cin >> dtb;
}
void SVCN::Show() {
    SVTC::Show();
    cout << "DTB: " << dtb << endl;
    setHocBong();
    cout << "Hoc bong: " << hocbong << endl;
    cout << "---------------------------\n";
}
/*----------------------------------Menu----------------------------------*/
void Menu(){
	cout << "----------------MENU------------------\n";
	cout << " 0. Thoat chuong trinh" << endl;
	cout << " 1. Nhap SVTC"<< endl;
	cout << " 2. Nhap SVCN"<< endl;
	cout << " 3. Xuat Danh Sach Sinh Vien"<< endl;
	cout << " 4. Xuat Danh Sach SVTC"<< endl;
	cout << " 5. Xuat Danh Sach SVCN"<< endl;
	cout << " 6. Xuat Danh Sach Sinh Vien co hoc bong\n";
	cout << " 7. Sap xep danh sach sinh vien\n";
	cout << " 8. Tim kiem sinh vien\n"; 
	cout << "----------------------------------\n";
}
/*----------------------------------main----------------------------------*/
int main(){
	SinhVien* a[100];
	int i = 0;
	bool check = true;
	while(check){
		Menu();
		cout << "Nhap lua chon: ";
		int choose; cin >> choose;
		switch(choose){
			case 0:
				cout << "Ban co muon thoat chuong trinh ? (Y/N): ";
				char c; cin >> c;
				if(c == 'Y' || c == 'y') 
				break;
			case 1: 
				a[i] = new SVTC;
				a[i]->Nhap();
				i++;
				break;
			case 2: 
				a[i] = new SVCN;
				a[i]->Nhap();
				i++;
				break;
			case 3:
				system("cls");
				cout << "Thong tin danh sach sinh vien\n";
				for(int j=0;j<i;j++)
					a[j]->Show();
				break;		
			case 4:
				cout << "Thong tin danh sach SVTC\n";
				for(int j=0;j<i;j++){
					SVTC *b = dynamic_cast<SVTC*>(a[j]);
					if(b!=NULL)
						a[j]->Show();
				}					
				break;	
			case 5:
				cout << "Thong tin danh sach SVCN\n";
				for(int j=0;j<i;j++){
					SVCN *b = dynamic_cast<SVCN*>(a[j]);
					if(b!=NULL)
						a[j]->Show();
				}					
				break;	
			case 6:
                cout << "Thong tin sinh vien\n";
                for (int j = 0; j < i; j++) {
                    
                }
                break;
            case 7:
            	for(int j=0; j<i; j++){
            		SinhVien* tmp ;
            		for(int k=j+1; k<i; k++){
            			if(a[k]->getHoTen() < a[j]->getHoTen())
            				tmp = a[k];
					}
					SinhVien* res = a[j];
					a[j] = tmp;
					tmp = a[j];
				}
				cout << "Da sap xep, nhap chuc nang de xem ket qua !!\n";
                break;
            case 8:
            {	
            	cout << "Nhap ho ten de tim kiem: ";
            	string s; cin >> s;
            	bool ok = false;
            	for(int j=0; j<i; j++){
            		if(a[j]->getHoTen() == s){
            			ok = true;
            			a[j]->Show();
					}
				}
				if(ok == false) {
					cout << "Khong co ten trong danh sach\n";
				}
				break;
			}
			default:{
				cout << "Lua chon khong hop le !!\n";	
				break;
			}
		}
	}
    for (int j = 0; j < i; j++) {
        delete a[i];
    }
    return 0;
}