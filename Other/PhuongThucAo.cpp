#include<iostream>
using namespace std;

class Cay{
	protected:
		float Chieucao;
		float Dotuoi;
		float CVTan;
	public:
		virtual void nhap();
		virtual void xuat();
};

void Cay::nhap(){
	cout<<"Nhap thong tin cho Cay "<<endl;
	cout<<"Chieu cao "; cin>>Chieucao;
	cout<<"Do tuoi "; cin>>Dotuoi;
	cout<<"Chu vi tan "; cin>>CVTan; 
}
void Cay::xuat(){
	cout<<"Thong tin cua lop Cay "<<endl;
	cout<<"Chieu cao: "<<Chieucao<<endl;
	cout<<"Do tuoi: "<<Dotuoi<<endl;
	cout<<"Chu vi tan: "<<CVTan<<endl; 
}
class Caycanh: public Cay{
	private:
		float Giathanh;
		char Chungloai[30];
	public:
		void nhap();
		void xuat();
};
void Caycanh::nhap(){
	cout<<"Nhap thong tin cho Cay canh"<<endl;
	cout<<"Chieu cao "; cin>>Chieucao;
	cout<<"Do tuoi "; cin>>Dotuoi;
	cout<<"Chu vi tan "; cin>>CVTan;
	cout<<"Gia thanh "; cin>>Giathanh;
	cin.ignore();
	cout<<"Chung loai "; gets(Chungloai); 
}
void Caycanh::xuat(){
	cout<<"Thong tin cua lop Cay Canh "<<endl;
	cout<<"Chieu cao: "<<Chieucao<<endl;
	cout<<"Do tuoi: "<<Dotuoi<<endl;
	cout<<"Chu vi tan: "<<CVTan<<endl;
	cout<<"Gia thanh: "<<Giathanh<<endl;
	cout<<"Chung loai: "<<Chungloai<<endl; 
}
int main(){
	Cay a, *p;
	Caycanh b;
	p = &a;
	p->nhap();//Nhap cua lop Cay
	p=&b;
	p->nhap();//Nhap cua lop Caycanh
	p=&a;
	p->xuat();//Xuat cua lop Cay
	p=&b;
	p->xuat();//Xuat cua lop Caycanh 
}