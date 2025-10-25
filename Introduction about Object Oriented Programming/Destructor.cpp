#include <iostream>
#include <cstring>
using namespace std;


//Class MyClass
//{
//private:
//     Type * PtrResource;
//public:
//     MyClass(); // default constructor
//     MyClass(const MyClass& CopySource); // copy constructor
//     MyClass& operator= (const MyClass& CopySource); // copy assignment operator
//     MyClass(MyClass&& MoveSource) // Move constructor, note &&
//     {
//         PtrResource = MoveSource.PtrResource; // take ownership, start move
//         MoveSource.PtrResource = NULL;
//     }
//     MyClass& operator= (MyClass&& MoveSource)//move assignment operator, note &&
//     {
//         if (this != &MoveSource)
//     {
//         delete[] PtrResource; // free own resource
//         PtrResource = MoveSource.PtrResource; // take ownership, start move
//         MoveSource.PtrResource = NULL; // free move source of ownership
//     }
//   }
//};

class MyString
{
private:
    char* Buffer;

    // private default constructor
    MyString() : Buffer(NULL)
    {
        cout << "Default constructor called" << endl;
    }

public:
    // Destructor
    ~MyString()
    {
        if (Buffer != NULL)
            delete[] Buffer;
    }

    int GetLength()
    {
        return strlen(Buffer);
    }

    operator const char* ()
    {
        return Buffer;
    }

    MyString operator+ (const MyString& AddThis)
    {
        cout << "operator+ called: " << endl;
        MyString NewString;

        if (AddThis.Buffer != NULL)
        {
            NewString.Buffer = new char[GetLength() + strlen(AddThis.Buffer) + 1];
            strcpy(NewString.Buffer, Buffer);
            strcat(NewString.Buffer, AddThis.Buffer);
        }

        return NewString;
    }

    // constructor
    MyString(const char* InitialInput)
    {
        cout << "Constructor called for: " << InitialInput << endl;
        if (InitialInput != NULL)
        {
            Buffer = new char[strlen(InitialInput) + 1];
            strcpy(Buffer, InitialInput);
        }
        else
            Buffer = NULL;
    }

    // Copy constructor
    MyString(const MyString& CopySource)
    {
        cout << "Copy constructor to copy from: " << CopySource.Buffer << endl;
        if (CopySource.Buffer != NULL)
        {
            // ensure deep copy by first allocating own buffer
            Buffer = new char[strlen(CopySource.Buffer) + 1];

            // copy from the source into local buffer
            strcpy(Buffer, CopySource.Buffer);
        }
        else
            Buffer = NULL;
    }

    // Copy assignment operator
    MyString& operator= (const MyString& CopySource)
    {
        cout << "Copy assignment operator to copy from: " << CopySource.Buffer << endl;
        if ((this != &CopySource) && (CopySource.Buffer != NULL))
        {
            if (Buffer != NULL)
                delete[] Buffer;

            // ensure deep copy by first allocating own buffer
            Buffer = new char[strlen(CopySource.Buffer) + 1];

            // copy from the source into local buffer
            strcpy(Buffer, CopySource.Buffer);
        }

        return *this;
    }

    // move constructor
    MyString(MyString&& MoveSource)
    {
        cout << "Move constructor to move from: " << MoveSource.Buffer << endl;
        if (MoveSource.Buffer != NULL)
        {
            Buffer = MoveSource.Buffer; // take ownership i.e. �move�
            MoveSource.Buffer = NULL;   // free move source
        }
    }

    // move assignment operator
    MyString& operator= (MyString&& MoveSource)
    {
        cout << "Move assignment operator to move from: " << MoveSource.Buffer << endl;
        if ((MoveSource.Buffer != NULL) && (this != &MoveSource))
        {
            delete[] Buffer; // release own buffer

            Buffer = MoveSource.Buffer; // take ownership i.e. �move�
            MoveSource.Buffer = NULL;   // free move source
        }

        return *this;
    }
};

int main()
{
    MyString Hello("Hello ");
    MyString World("World");
    MyString CPP(" of C++");

    MyString sayHelloAgain("overwrite this");
    sayHelloAgain = Hello + World + CPP;

    return 0;
}
