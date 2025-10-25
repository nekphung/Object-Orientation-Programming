#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Date
{
private:
    int Day;   // Range: 1 - 30 (lets assume all months have 30 days)
    int Month;
    int Year;

    string DateInString;

public:
    // Constructor
    Date(int InputDay, int InputMonth, int InputYear)
        : Day(InputDay), Month(InputMonth), Year(InputYear) {}

    // Overloaded type-cast operator: convert Date → const char*
    operator const char* ()
    {
        ostringstream formattedDate;  // tạo một stream để format dữ liệu
        formattedDate << Day << " / " << Month << " / " << Year;

        DateInString = formattedDate.str();  // lấy chuỗi từ stream
        return DateInString.c_str();         // trả về con trỏ C-string
    }
};

int main()
{
    Date Holiday(25, 12, 2011);
    cout << "Holiday is on: " << Holiday << endl;

    return 0;
}
