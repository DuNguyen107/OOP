#include <iostream>
using namespace std;

class TaoVaHuy
{
 public:
    TaoVaHuy(int); // Constructor (Hàm tạo)
    ~TaoVaHuy();   // Destructor (Hàm hủy)
 private:
    int DuLieu;
};

TaoVaHuy::TaoVaHuy(int GiaTri)
{
    DuLieu = GiaTri;
    cout << "Doi tuong " << DuLieu << " ham tao";
}

TaoVaHuy::~TaoVaHuy()
{
    cout << "Doi tuong " << DuLieu << " ham huy " << endl;
}

void Tao(); // Prototype (nguyên mẫu)
TaoVaHuy ThuNhat(1); // Doi tuong toan cuc

int main()
{
    cout << " (doi tuong toan cuc tao truoc main)" << endl;
    TaoVaHuy ThuHai(2); // Doi tuong cuc bo
    cout << " (doi tuong cuc bo trong main)" << endl;
    static TaoVaHuy ThuBa(3); // Doi tuong cuc bo static
    cout << " (doi tuong static cuc bo trong main)" << endl;
    Tao(); // Goi ham de tao cac doi tuong
    TaoVaHuy ThuTu(4); // Doi tuong cuc bo
    cout << " (doi tuong cuc bo trong main)" << endl;
    return 0;
}

// Ham tao cac doi tuong
void Tao(void)
{
    TaoVaHuy ThuNam(5);
    cout << " (doi tuong cuc bo trong ham tao)" << endl;
    static TaoVaHuy ThuSau(6);
    cout << " (doi tuong static cuc bo trong ham tao)" << endl; 
    TaoVaHuy ThuBay(7);
    cout << " (doi tuong cuc bo trong ham tao)" << endl;
}
