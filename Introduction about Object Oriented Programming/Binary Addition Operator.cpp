#include <iostream>
using namespace std;

class Date
{
private:
    int Day, Month, Year;

public:
    // Constructor
    Date(int InputDay, int InputMonth, int InputYear)
        : Day(InputDay), Month(InputMonth), Year(InputYear) {};

    // Binary addition operator (+)
    Date operator+(int DaysToAdd)
    {
        Date newDate(Day + DaysToAdd, Month, Year);
        return newDate;
    }

    // Binary subtraction operator (-)
    Date operator-(int DaysToSub)
    {
        return Date(Day - DaysToSub, Month, Year);
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

    cout << "Holiday on: ";
    Holiday.DisplayDate();

    Date PreviousHoliday(Holiday - 19);
    cout << "Previous holiday on: ";
    PreviousHoliday.DisplayDate();

    Date NextHoliday(Holiday + 6);
    cout << "Next holiday on: ";
    NextHoliday.DisplayDate();

    return 0;
}
