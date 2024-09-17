#include<iostream>
#include<cmath>
using namespace std;

struct DT{
	double HeSo;
	int SoMu;	
};

struct Node{
	DT info;
	Node *next;
};

struct List{
	Node* pHead = NULL;
	Node* pTail = NULL;
};
void Init(List &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
Node* getNode(double heso, int somu){
	Node *p = new Node;
	if(p == NULL){
		cout << "Khong du bo nho !!\n";
		return NULL;
	}
	p->info.HeSo = heso;
	p->info.SoMu = somu;
	p->next = NULL;
	return p;	
}

void printList(List L){
	Node *p = L.pHead;
	if(p == NULL)
		return;
	while(p != NULL ){
		if(p->info.SoMu == 1){
			cout << p->info.HeSo << "x + ";
			p = p->next;
		}
		if(p->info.SoMu == 0){
			cout << p->info.HeSo;
			return;
		}	
		cout << p->info.HeSo << "x^" << p->info.SoMu;
		if(p->info.SoMu > 0)
			cout << " + ";
		p = p->next;
	}
	cout << endl;
}

void addTail(List &L, double heso, int somu)
{
    Node* p = getNode(heso, somu);
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}
class DaThuc{
	private:
		int n;
		List L;
	public:
		void KhoiTao();
		void Nhap();
		void Xuat();
		double GiaTri(double x);
		void SoSanh(DaThuc p, DaThuc q, double x);
};

void DaThuc::KhoiTao() {
	Init(L); 
}
void DaThuc::Nhap(){
	cout << "Nhap bac cua da thuc: "; cin >> n;
	cout << "--Nhap he so cho da thuc bac " << n << endl;
	for(int i=n; i>=0; i--){
		cout << "He so bac " << i << ": ";
		double value; cin >> value;
		addTail(L,value, i);
	}
}
void DaThuc::Xuat(){
	printList(L);
}
double DaThuc::GiaTri(double x){
	double kq = 0.0;
	Node* p = L.pHead;
	while(p != NULL){
		kq += p->info.HeSo * pow(x, p->info.SoMu);
		p = p->next;
	}
	return kq;
}

void DaThuc::SoSanh(DaThuc p, DaThuc q, double x){
	double KQ_DaThuc_1 = p.GiaTri(x);
	double KQ_DaThuc_2 = q.GiaTri(x);
	if(KQ_DaThuc_1 > KQ_DaThuc_1) 
		cout << "Da thuc so 1 > Da thuc so 2\n";
	else if(KQ_DaThuc_1 < KQ_DaThuc_1) 
		cout << "Da thuc so 1 < Da thuc so 2\n";
	else
		cout << "Da thuc so 1 = Da thuc so 2\n";
}

void Menu(){
	while(1){
		cout << "----------------------------------\n";
		cout << "            MENU\n";
		cout << "1. Nhap va xuat da thuc\n";
		cout << "2. Tinh gia tri cua da thuc tai x\n";
		cout << "3. So sanh 2 da thuc\n" << endl;
		cout << "----------------------------------\n";
		int choose;
		cout << "Nhap lua chon: ";
		cin >> choose;
		DaThuc p,q, temp;
		switch(choose){
			
			case 1:
				p.Nhap();
				cout << "Da thuc vua nhap: ";
				p.Xuat();
				cout << endl;
				cout << "\n-------------------------------\n";
				break;
			case 2:
				p.Nhap();
				cout << "\nNhap x de tinh gia tri cua da thuc ";
				p.Xuat(); cout << ": ";
				double x; cin >> x;
				cout << "Ket qua cua bieu thuc khi x = " << x << ": ";
				cout << p.GiaTri(x) << endl;
				cout << "\n-------------------------------\n";
				break;
			case 3:
				cout << "Nhap da thuc so 1 \n"; p.Nhap();
				cout << "Nhap da thuc so 2 \n"; q.Nhap();
				double t;
				cout << "Nhap gia tri de so sanh 2 da thuc: ";
				cin >> t;
				temp.SoSanh(p,q,t);
				cout << "\n-------------------------------\n";
				break;
			default:
				cout << "Lua chon khong dung !! Vui long chon lai \n";
				cout << "\n-------------------------------\n";
				break;
		}
		cout << "Ban muon tiep tuc(1) hay thoat chuong trinh(0):\n";
		int check; cin >> check;
		if(!check){
			cout << "Chuong trinh da thoat!! \n";
			break;
		}		
	}
}
int main(){
	Menu();
}