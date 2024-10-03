#include"kysu.h"
#include<iostream>
int main(){
	int n;
	kysu a[100];
	cout << "Nhap n: "; cin >> n;
	for(int i=0; i<n; i++){
		cout << "Ky su thu " << i+1 << ":\n";
		a[i].nhap();
	}
	cout << "Thong tin vua nhap: \n";
	for(int i=0; i<n; i++){
		a[i].xuat();
	}
	int max = a[0].getNam();
	for(int i=0; i<n; i++){
		if(a[i].getNam() > max)
			max = a[i].getNam();
	}
	cout << "Ky su co nam tot nghiep gan day la: \n";
	for(int i=0; i<n; i++)
		if(a[i].getNam() == max)
			a[i].xuat();
}