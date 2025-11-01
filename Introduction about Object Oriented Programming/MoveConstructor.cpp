#include <iostream>
#include <algorithm> // std::copy
#include <utility>   // std::move

using namespace std; 

class Buffer {
    int size;
    char* data;

public:
    // Default constructor
    Buffer(int n = 0) : size(n), data(n ? new char[n] : nullptr) {
        cout << "Default constructor - Constructed Buffer of size " << size << endl; 
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        cout << "Destroyed Buffer\n";
    }

    // Copy constructor (deep copy)
    Buffer(const Buffer& other) : size(other.size), data(other.size ? new char[other.size] : nullptr) {
        if (data)
            copy(other.data, other.data + size, data);
        cout << "Copy constructor - Copied Buffer\n";
    }

    // Copy assignment operator 
    Buffer& operator=(const Buffer& other) {
        if (this != &other)  // so sanh dia chi neu no khac nhau thi moi duoc, tranh truong hop copy chinh no 
        {
            delete[] data; // xoa de tranh truong hop no ton tai gia tri rac 
            size = other.size; 
            data = other.size ? new char[other.size] : nullptr; 
            if (data) // Neu no khac nullptr thi no moi copy qua duoc 
               copy(other.data, other.data + size, data);
        }
        cout << "Copy assignment - Copy assigned Buffer\n";
        return *this;
    }
    
    // Move constructor
    Buffer(Buffer&& other) 
        : size(other.size), data(other.data)
    {
        other.size = 0; // gan lai cai cu = 0 
        other.data = nullptr;  // gan lai bang nullptr 
        cout << "Move constructor - Moved Buffer (constructor)\n";
    }

    // Move assignment
    Buffer& operator=(Buffer&& other) {
        if (this != &other) {
            delete[] data;          // Giải phóng bộ nhớ hiện tại
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
        }
        cout << "Move assignment - Move assigned Buffer\n";
        return *this;
    }

    // Helper: set value
    void setValue(int index, char val) {
        if (index < size) data[index] = val;
    }

    // Helper: print value
    void print() const {
        for (size_t i = 0; i < size; ++i)
            cout << data[i] << " ";
       cout << "\n";
    }
};


int main() {

    int* p; 
    int x = 10; 
    p = &x; 
    cout << p << endl;  // dia chi x trong bo nho 
    cout << &p << endl; // dia chi cua p trong bo nho 
    cout << *p << endl; // 10 
    *p = 25; 
    cout << x << endl; // 25 

    Buffer buf1(5);
    for (int i = 0; i < 5; ++i)
        buf1.setValue(i, 'A' + i); // A B C D E

    Buffer buf2 = move(buf1); // Gọi **move constructor**
    buf2.print();                   // In ra: A B C D E

    Buffer buf3; // default constructor 
    buf3 = move(buf2);         // Gọi **move assignment**
    buf3.print();                   // In ra: A B C D E

    Buffer buf4; // default constructor 
    buf4.print();  

    Buffer buf5 = buf3;  // copy constructor 
    buf5.print(); 


    Buffer buf6; // default contructor 
    buf6 = buf5;  // copy assignment constructor 
    buf6.print(); 

    return 0;
}

