#include <iostream>
using namespace std;

class MyTime {
protected:
    int hours;
    int minutes;
    int seconds;  
public:
    MyTime() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    friend istream& operator >> (istream &is, MyTime &t){
    	do {
            cout << "Nhap gio: ";
            is >> t.hours;
            if (t.hours > 24 || t.hours < 0) {
                cout << "Gio khong hop le! Moi nhap lai!" << endl;
            }
        } while (t.hours > 24 || t.hours < 0);

        do {
            cout << "Nhap phut: ";
            is >> t.minutes;
            if (t.minutes >= 60 || t.minutes < 0) {
                cout << "Phut khong hop le! Moi nhap lai!" << endl;
            }
        } while (t.minutes >= 60 || t.minutes < 0);  

        do {
            cout << "Nhap giay: ";
            is >> t.seconds;
            if (t.seconds >= 60 || t.seconds < 0) {
                cout << "Giay khong hop le! Moi nhap lai!" << endl;
            }
        } while (t.seconds >= 60 || t.seconds < 0);  
        return is;
	}
	friend ostream& operator << (ostream &os, MyTime t){
		if (t.hours < 10) os << "0" << t.hours;
        else if(t.hours == 24) os << "00";
        else os << t.hours;

        cout << ":";

        if (t.minutes < 10) os << "0" << t.minutes;
        else os << t.minutes;

        cout << ":";

        if (t.seconds < 10) os << "0" << t.seconds;
        else os << t.seconds;
        os << endl;
        return os;
	}
	MyTime operator+(int hour) {
        MyTime h = *this;
        h.hours += hour;
        if (h.hours >= 24) {
            h.hours %= 24;  // Nếu giờ vượt quá 24 thì reset lại
        }
        return h;
    }
};

class MyDate {
protected:
    int day;
    int month;
    int year;

public:
    MyDate() {
        day = month = year = 0;
    }
    bool isLeapYear (int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
	int daysInMonth() const {
        switch (month) {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(year) ? 29 : 28;
            default: return 31;
        }
    } 
	MyDate operator + (int days){
		MyDate d = *this;
        d.day += days;
        while (d.day > d.daysInMonth()) {
            d.day -= d.daysInMonth();
            d.month++;
            if (d.month > 12) {
                d.month = 1;
                d.year++;
            }
        }
        return d;
	}
    friend istream& operator >> (istream &is, MyDate &t){
        bool valid = false; 
        do {
            valid = true;  

            cout << "Nhap nam: ";
            is >> t.year;
            if (t.year < 0) {
                cout << "Nam khong hop le! Moi nhap lai!" << endl;
                valid = false;
            }

            if (valid) {
                cout << "Nhap thang: ";
                is >> t.month;
                if (t.month < 1 || t.month > 12) {
                    cout << "Thang khong hop le! Moi nhap lai!" << endl;
                    valid = false;
                }
            }

            if (valid) {
                cout << "Nhap ngay: ";
                is >> t.day;

                if (t.month == 1 || t.month == 3 || t.month == 5 || t.month == 7 || t.month == 8 || t.month == 10 || t.month == 12) {
                    if (t.day < 1 || t.day > 31) {
                        cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                        valid = false;
                    }
                } else if (t.month == 4 || t.month == 6 || t.month == 9 || t.month == 11) {
                    if (t.day < 1 || t.day > 30) {
                        cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                        valid = false;
                    }
                } else if (t.month == 2) {
                    if (t.isLeapYear(t.year)) {
                        if (t.day < 1 || t.day > 29) {
                            cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                            valid = false;
                        }
                    } else {
                        if (t.day < 1 || t.day > 28) {
                            cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                            valid = false;
                        }
                    }
                }
            }
        } while (!valid); 
        return is;
    }   

    friend ostream& operator << (ostream& os, const MyDate t) {
        if (t.day < 10) os << "0" << t.day;
        else os << t.day;

        os << "/";

        if (t.month < 10) os << "0" << t.month;
        else os << t.month;

        os << "/" << t.year;

        os << " ";
        return os;
    }
};

class DateTime : public MyDate, public MyTime {
	private:
	    MyDate date;
	    MyTime time;
	public:
	    DateTime() {};
		DateTime operator +(int days, int hour){
	        DateTime dt = *this;  
		    dt.date = dt.date + days;
		    dt.time = dt.time + hour;
		
		    if (dt.time.hours >= 24) {
		        int extraDays = dt.time.hours / 24;  
		        dt.time.hours %= 24;  
		        dt.date = dt.date + extraDays;  
	    	}
	    	return result;
    	}
	    friend istream& operator>>(istream &is, DateTime &dt) {
	        is >> dt.date >> dt.time;
	        return is;
	    }
	
	    friend ostream& operator<<(ostream &os, const DateTime &dt) {
	        os << dt.date << " " << dt.time;
	        return os;
	    }
};

int main() {
   DateTime dt1, dt2;

    cout << "Nhap DateTime 1:" << endl;
    cin >> dt1;

    cout << "Nhap DateTime 2:" << endl;
    cin >> dt2;

    cout << "DateTime 1: " << dt1 << endl;
    cout << "DateTime 2: " << dt2 << endl;
    DateTime dt3 = dt1 + DateTime(5, 26);
    cout << "DateTime 1 sau khi cong 5 ngay: " << dt3 << endl;
    Date
}
