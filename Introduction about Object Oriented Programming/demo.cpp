#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    // Private member data:
    string Name;
    int Age;

public:
    // constructor
    //Human()
    //{
    //    Age = 0; // initialized to ensure no junk value
    //    cout << "Default constructor creates an instance of Human" << endl;
    //}

    // overloaded constructor that takes Name
    Human(string HumansName)
    {
        Name = HumansName;
        Age = 0; // initialized to ensure no junk value
        cout << "Overloaded constructor creates " << Name << endl;
    }

    ~Human(); // destructor declaration
    // overloaded constructor that takes Name and Age
    /*Human(string HumansName , int HumansAge = 25)
    {
        Name = HumansName;
        Age = HumansAge;
        cout << "Overloaded constructor creates ";
        cout << Name << " of " << Age << " years" << endl;
    }*/

    // constructor takes two parameters to initialize members Age and Name
    Human(string InputName = "Alam", int InputAge = 25)
        :Name(InputName), Age(InputAge)
    {
        cout << "Overloaded constructor creates ";
        cout << Name << " of " << Age << " years" << endl;
    }

    void SetName(string HumansName)
    {
        Name = HumansName;
    }

    void SetAge(int HumansAge)
    {
        Age = HumansAge;
    }

    void IntroduceSelf()
    {
        cout << "I am " + Name << " and am ";
        cout << Age << " years old" << endl;
    }
};

// destructor definition (implementation)
Human::~Human()
{
    // destructor code here
}

int main()
{
    //Human FirstMan; // use default constructor
    //FirstMan.SetName("Adam");
    //FirstMan.SetAge(30);

    //Human FirstWoman("Eve"); // use overloaded constructor
    //FirstWoman.SetAge(28);

    //Human ChildRen; // Tu tao mac dinh 
    Human FirstChild("Rose", 1);
    Human Children;
   // FirstMan.IntroduceSelf();
   // FirstWoman.IntroduceSelf();
   // ChildRen.IntroduceSelf();
    Children.IntroduceSelf();
    FirstChild.IntroduceSelf();
}
