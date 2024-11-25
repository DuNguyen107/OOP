#include <iostream>
#include <string>
using namespace std;

class Media {
	protected:
	    string name;
	    double price;
	public:
	    Media(string n = "", double p = 0) {
	        name = n;
	        price = p;
	    }
	    
	    virtual void input() {
	        cout << "Nhap ten: ";
	        cin.ignore();
	        getline(cin, name);
	        cout << "Nhap gia ban: ";
	        cin >> price;
	    }
	    
	    virtual void display() {
	        cout << "Ten: " << name << endl;
	        cout << "Gia ban: " << price << endl;
	    }
	    
    virtual ~Media() {}
};

class Book : public Media {
	private:
	    int pages;
	    string author;
	public:
	    Book(string n = "", double p = 0, int pg = 0, string a = "") : Media(n, p) {
	        pages = pg;
	        author = a;
	    }
	    
	    void input() override {
	        Media::input();
	        cout << "Nhap so trang: ";
	        cin >> pages;
	        cout << "Nhap tac gia: ";
	        cin.ignore();
	        getline(cin, author);
	    }
	    
	    void display() override {
	        Media::display();
	        cout << "So trang: " << pages << endl;
	        cout << "Tac gia: " << author << endl;
	    }
};

class Video : public Media {
	private:
	    int duration; 
	public:
	    Video(string n = "", double p = 0, int d = 0) : Media(n, p) {
	        duration = d;
	    }
	    
	    void input() override {
	        Media::input();
	        cout << "Nhap thoi gian (phut): ";
	        cin >> duration;
	    }
	    
	    void display() override {
	        Media::display();
	        cout << "Thoi gian: " << duration << " phut" << endl;
	    }
};

int main() {
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    
    Media** books = new Media*[n];
    cout << "\nNhap thong tin sach:\n";
    for(int i = 0; i < n; i++) {
        cout << "\nSach thu " << i + 1 << ":\n";
        books[i] = new Book();
        books[i]->input();
    }
    
    int m;
    cout << "\nNhap so luong video: ";
    cin >> m;
    
    Media** videos = new Media*[m];
    cout << "\nNhap thong tin video:\n";
    for(int i = 0; i < m; i++) {
        cout << "\nVideo thu " << i + 1 << ":\n";
        videos[i] = new Video();
        videos[i]->input();
    }
    
    cout << "\n=== THONG TIN SACH ===\n";
    for(int i = 0; i < n; i++) {
        cout << "\nSach thu " << i + 1 << ":\n";
        books[i]->display();
    }
    
    cout << "\n=== THONG TIN VIDEO ===\n";
    for(int i = 0; i < m; i++) {
        cout << "\nVideo thu " << i + 1 << ":\n";
        videos[i]->display();
    }
    
    for(int i = 0; i < n; i++) {
        delete books[i];
    }
    delete[] books;
    
    for(int i = 0; i < m; i++) {
        delete videos[i];
    }
    delete[] videos;
    
    return 0;
}