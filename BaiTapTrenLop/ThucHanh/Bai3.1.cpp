#include<iostream>
using namespace std;

class Shape {
    public:
        virtual double dientich() const {
            return 0;    
        }
        virtual void input(){}
        virtual void output() const{
            cout << "Dien tich: " << dientich() << endl;
        }
        virtual ~Shape(){}
};

class Circle: public Shape {
    private:
        double bankinh;
    public:
        Circle(double bankinh = 0){
            this->bankinh = bankinh;
        }
        void input() override{
            cout << "Nhap ban kinh: ";
            cin >> bankinh;
        }
        double dientich() const override{
            return 3.14 * bankinh * bankinh;
        }
};

class Rectangle: public Shape {
    private:
        double chieudai, chieurong;
    public:
        Rectangle(double chieudai = 0, double chieurong = 0){
            this->chieudai = chieudai;
            this->chieurong = chieurong;
        }
        void input() override{
            cout << "Nhap chieu dai: "; cin >> chieudai;
            cout << "Nhap chieu rong: "; cin >> chieurong;
        }
        double dientich() const override{
            return chieudai * chieurong;
        }
};

int main(){
    int nTron, nNhat;
    cout << "Nhap so luong hinh tron: "; cin >> nTron;
    cout << "Nhap so luong hinh chu nhat: "; cin >> nNhat;
    
    Shape** circle = new Shape*[nTron];
    for(int i=0; i<nTron; i++){
        cout << "Nhap du lieu hinh tron thu " << i+1 << "\n";
        circle[i] = new Circle();
        circle[i]->input();
    }
    
    Shape** rectangle = new Shape*[nNhat];
    for(int i=0; i<nNhat; i++){
        cout << "Nhap du lieu hinh chu nhat thu " << i+1 << "\n";
        rectangle[i] = new Rectangle();
        rectangle[i]->input();
    }
    
    cout << "\nDien tich cac hinh tron:" << endl;
    for(int i=0; i<nTron; i++){
        cout << "Hinh tron " << i+1 << " - ";
        circle[i]->output();
    }
    
    cout << "\nDien tich cac hinh chu nhat:" << endl;
    for(int i=0; i<nNhat; i++){
        cout << "Hinh chu nhat " << i+1 << " - ";
        rectangle[i]->output();
    }
    
    // Giải phóng bộ nhớ
    for(int i = 0; i < nTron; i++) {
        delete circle[i];
    }
    delete[] circle;
    for(int i = 0; i < nNhat; i++) {
        delete rectangle[i];
    }
    delete[] rectangle;
    return 0;
}