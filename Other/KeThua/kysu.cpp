#include"kysu.h"
#include<iostream>

int kysu::getNam(){
	return nam;
}
void kysu::nhap(){
	cin.ignore();
	cout << "Ho ten: "; getline(cin, hoten);
	cout << "Ngay sinh: "; getline(cin, namsinh);
	cout << "Que quan: "; getline(cin, que);
	cout << "Nganh hoc: "; getline(cin, nganh);
	cout << "Nam tot nghiep: "; cin >> nam;
}
void kysu::xuat(){
	cout << "Ho ten: " << hoten << endl;
	cout << "Ngay sinh: " << namsinh << endl;
	cout << "Que quan: " << que << endl;
	cout << "Nganh hoc: " << nganh << endl;
	cout << "Nam tot nghiep: " << nam << endl;
}