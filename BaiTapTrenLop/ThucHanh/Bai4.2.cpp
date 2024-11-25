#include <iostream>
using namespace std;

class Frac {
	private:
	    double a; 
	    double b; 
	
	public:
	    Frac(double num = 0, double den = 1) {
	        if (den == 0) {
	            cout << "Loi: mau so bang 0!" << endl;
	            a = 0;
	            b = 1;
	        } else {
	            a = num;
	            b = den;
	        }
	    }
	
	    void input() {
	        cout << "Nhap tu so: ";
	        cin >> a;
	        do {
	            cout << "Nhap mau so: ";
	            cin >> b;
	            if (b == 0) {
	                cout << "Mau so khong duoc bang 0! Vui long nhap lai.\n";
	            }
	        } while (b == 0);
	    }
	    void display() const {
	        cout << a << "/" << b;
	    }
	    bool operator>(const Frac& other) const {
	        return (a * other.b) > (other.a * b);
	    }
	    Frac& operator=(const Frac& other) {
	        if (this != &other) {
	            a = other.a;
	            b = other.b;
	        }
	        return *this;
	    }
};

template <typename T>
T findMax(T arr[], int n) {
    T max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    
    cout << "Nhap so luong phan so: ";
    cin >> n;
    
    Frac* fractions = new Frac[n];
    
    cout << "\nNhap cac phan so:\n";
    for(int i = 0; i < n; i++) {
        cout << "\nPhan so thu " << i + 1 << ":\n";
        fractions[i].input();
    }
    
    cout << "\nCac phan so da nhap:\n";
    for(int i = 0; i < n; i++) {
        fractions[i].display();
        cout << "  ";
    }
    cout << endl;
    
    Frac maxFrac = findMax(fractions, n);
    cout << "Phan so lon nhat la: ";
    maxFrac.display();
    cout << endl;
    
    cout << "\nNhap so luong so thuc: ";
    cin >> n;
    
    double* realNumbers = new double[n];
    
    cout << "Nhap cac so thuc:\n";
    for(int i = 0; i < n; i++) {
        cout << "So thu " << i + 1 << ": ";
        cin >> realNumbers[i];
    }
    
    cout << "\nCac so thuc da nhap: ";
    for(int i = 0; i < n; i++) {
        cout << realNumbers[i] << " ";
    }
    cout << endl;
    
    double maxReal = findMax(realNumbers, n);
    cout << "So thuc lon nhat la: " << maxReal << endl;
    
    delete[] fractions;
    delete[] realNumbers;
    
    return 0;
}