#include<iostream>
#include<string>

using namespace std;

template <typename  T>
T findMax(T a[], int n){
	T max = a[0];
	for(int i=0; i<n; i++){
		if(a[i] > max) max = a[i];
	}
	return max;
}
int main() {
    int intA[] = {1, 5, 3, 9, 2};
    cout << "Gia tri lon nhat (so nguyen): " 
         << findMax(intA, 5) << endl;
    
    double doubleA[] = {1.5, 3.7, 2.8, 9.2, 5.1};
    cout << "Gia tri lon nhat (so thuc): " 
         << findMax(doubleA, 5) << endl;
    
    string strA[3];
    cout << "\nNhap 3 xau ky tu:\n";
    for(int i = 0; i < 3; i++) {
        cout << "Xau " << i + 1 << ": ";
        getline(cin, strA[i]);
    }
    
    cout << "\nCac xau da nhap:\n";
    for(int i = 0; i < 3; i++) {
        cout << strA[i] << endl;
    }
    
    cout << "\nXau lon nhat: " << findMax(strA, 3) << endl;
}