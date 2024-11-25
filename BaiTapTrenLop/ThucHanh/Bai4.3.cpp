#include<iostream>
using namespace std;

class PhanSo{
	private:
		double a,b;
	public:
		PhanSo(double a = 0, double b = 1){
			if(b == 0){
				cout << "Mau so khac khong !!\n";
				this->a = 0;
				this->b = 1;
			}else{
				this->a = a;
				this->b = b;
			}
		}
		void input(){
			cout << "Nhap tu so: "; cin >> a;
	        do {
	            cout << "Nhap mau so: ";
	            cin >> b;
	            if (b == 0) {
	                cout << "Mau so khong duoc bang 0! Vui long nhap lai.\n";
	            }
	        } while (b == 0);
		}
		void output() const{
			cout << a << "/" << b;
		}
		PhanSo operator + (const PhanSo& q) {
		    PhanSo kq;
		    kq.a = this->a * q.b + this->b * q.a;
		    kq.b = this->b * q.b;
		    return kq;
		}
		PhanSo& operator=(const PhanSo& other) {
	        if (this != &other) {
	            a = other.a;
	            b = other.b;
	        }
	        return *this;
	    }
};
template <typename T>
T Tong(T a[], int n){
	T sum = 0;
	for(int i=0; i<n; i++){
		sum = sum + a[i];
	}
	return sum;
}
int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    
    PhanSo* p = new PhanSo[n];
    for(int i = 0; i < n; i++) {
        cout << "\nPhan so thu " << i + 1 << ": \n";
        p[i].input();
    }
    
    cout << "\nCac phan so da nhap: ";
    for(int i = 0; i < n; i++) {
        p[i].output();
        cout << "  ";
    }
    cout << endl;
    PhanSo tongPS = Tong(p, n);
    cout << "Tong phan so la: ";
    tongPS.output();
    cout << endl << endl;
    
    cout << "Nhap so luong so nguyen: ";
    cin >> n;
    
    int* a = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "\nSo nguyen thu " << i + 1 << ":";
        cin >> a[i];
    }
    
    cout << "\nCac so nguyen da nhap: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
    
    int tongSO = Tong(a, n);
    cout << "Tong cac so nguyen la: ";
    cout << tongSO;
    cout << endl;
}