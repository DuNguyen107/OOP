#include<iostream>
using namespace std;

class PhanSo{
	private:
		int tu, mau;
	public:
		PhanSo(){
			tu=0;
			mau=1;
		}
		PhanSo(int tu, int mau){
			this->tu=tu;
			this->mau=mau;
		}
		bool operator < (PhanSo a){
			return ((float)this->tu/this->mau)<((float)a.tu/a.mau);
		}
		bool operator > (int a){
			return this->tu*this->mau > a;
		}
		void output(){
			cout<<tu<<"/"<<mau;
		}
};

template<class T>
class Array{
	private:
		T* data;
		int size;
	public:
		Array(){
			data = NULL;
			size = 0;
		}
		void addTail(T value){
			T* newData = new T[size+1];
			for(int i=0; i<size; i++){
				newData[i] = data[i];
			} 
			newData[size] = value;
			delete []data;
			data = newData;
			size++;
		}		
		void output(){
			for(int i=0; i<size; i++){
				cout << data[i] << ' ';
			}
			cout << endl;
		}
		void sapxep(){
			for(int i=0; i<size-1; i++){
				for(int j=i+1; j<size; j++){
					if(data[j] < data[i]){	
						T temp = data[j];
						data[j] = data[i];
						data[i] = temp;
					}
				}
			}
		}
		T findMax() {
        T max = data[0];
        for(int i = 1; i < size; i++) {
            if(data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }
};
int main(){
	Array<int> arr;
    arr.addTail(5);
    arr.addTail(2);
    arr.addTail(8);
    arr.addTail(1);
    arr.addTail(9);
    
    cout << "Mang sau khi them: ";
    arr.output();
    
    arr.sapxep();
    cout << "Mang sau khi sap xep: ";
    arr.output();
    
    cout << "Phan tu lon nhat: " << arr.findMax() << endl;
}