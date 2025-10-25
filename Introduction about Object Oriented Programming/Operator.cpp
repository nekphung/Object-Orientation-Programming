#include <iostream>
#include <vector>

using namespace std;

/*
- Prefix (++a) → trả về Date& (tham chiếu).
- Postfix (a++) → trả về Date (copy).
- Trong postfix, mình hay gọi lại prefix để tránh lặp code (++(*this);).
*/

class Date
{
private:
    int Day;   // Range: 1 - 30 (assume all months have 30 days)
    int Month; // Range: 1 - 12
    int Year;

public:
    // Constructor
    Date(int InputDay, int InputMonth, int InputYear)
        : Day(InputDay), Month(InputMonth), Year(InputYear) {}

    // Prefix increment operator
    Date& operator++()
    {
        ++Day;
        if (Day > 30) {
            Day = 1;
            ++Month;
            if (Month > 12) {
                Month = 1;
                ++Year;
            }
        }
        return *this;
    }

    // Prefix decrement operator
    Date& operator--()
    {
        --Day;
        if (Day < 1) {
            Day = 30;
            --Month;
            if (Month < 1) {
                Month = 12;
                --Year;
            }
        }
        return *this;
    }

    // postfix differs from prefix operator in return-type and parameters 
    Date operator ++ (int)
    {
        // Store a copy of the current state of the object, before incrementing day
        //Date Copy(Day, Month, Year);
        //++Day;
        
        Date Copy(*this);
        ++(*this);
        // Return the state before increment was performed
        return Copy;
    }

    // postfix decrement operator
    Date operator -- (int)
    {
        Date Copy(Day, Month, Year);
        --Day;
        return Copy;
    }

    void DisplayDate()
    {
        cout << Day << " / " << Month << " / " << Year << endl;
    }
};

int main()
{
    // Instantiate and initialize a date object to 25 Dec 2011
    Date Holiday(25, 12, 2011);

    cout << "The date object is initialized to: ";
    Holiday.DisplayDate();

    // Applying the prefix increment operator
    Holiday++;
    cout << "Date after prefix-increment is: ";
    Holiday.DisplayDate();

    // Applying the prefix decrement operator twice
    Holiday--;
    Holiday--;
    cout << "Date after two prefix-decrements is: ";
    Holiday.DisplayDate();

    return 0;
}
