#include<iostream>
using namespace std;

template<class T>
T Min(T a, T b){
	return a<b ? a : b;
}
template<class T>
T Cong(T a, T b){
	return a+b;
}
template<class T>
T Abs(T a){
	return (a<0) ? -a : a;
}
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
		PhanSo operator + (PhanSo a){
			PhanSo p;
			p.tu = this->tu * a.mau + this->mau*a.tu;
			p.mau = this->mau * a.mau;
			return p;
		}
		PhanSo operator - (){
			return PhanSo(-tu,mau);
		}
		bool operator < (int a){
			return this->tu*this->mau < a;
		}
		void output(){
			cout<<tu<<"/"<<mau;
		}
};
int main(){
	PhanSo p1(-1,2), p2(1,3);
	PhanSo m=Abs(p1);
	m.output();
}