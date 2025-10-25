#include <iostream>
//#include <memory> // để dùng std::unique_ptr
using namespace std;


/*
- Khi dùng new, bộ nhớ được cấp phát trên heap. Bình thường, phải delete để giải phóng, nếu không sẽ gây memory leak.
- Nhưng unique_ptr là một smart pointer. Nó tuân theo RAII(Resource Acquisition Is Initialization):
  + Khi biến unique_ptr ra khỏi scope, destructor của nó sẽ tự động gọi delete cho con trỏ mà nó quản lý.
- RAII = Resource Acquisition Is Initialization (tạm dịch: Lấy tài nguyên thông qua khởi tạo).
  + Ý nghĩa:
    Tài nguyên (resource) như bộ nhớ động, file, socket, mutex, ... được quản lý bởi đối tượng.
    Khi đối tượng được khởi tạo (constructor gọi) → nó sẽ nhận (acquire) tài nguyên.
    Khi đối tượng hết phạm vi (ra khỏi scope, destructor gọi) → nó sẽ giải phóng (release) tài nguyên.
*/

template <typename T>
class smart_pointer
{
private:
    T* m_pRawPointer;

public:
    smart_pointer(T* pData) : m_pRawPointer(pData) {} // constructor

    ~smart_pointer() { delete m_pRawPointer; }        // destructor

    T& operator*() const   // overload toán tử * (dereference)
    {
        return *(m_pRawPointer);
    }

    T* operator->() const  // overload toán tử -> (truy cập thành viên)
    {
        return m_pRawPointer;
    }
};

class Date
{
private:
    int Day;
    int Month;
    int Year;
    string DateInString;

public:
    Date(int InputDay, int InputMonth, int InputYear)
        : Day(InputDay), Month(InputMonth), Year(InputYear) {}

    void DisplayDate()
    {
        cout << Day << " / " << Month << " / " << Year << endl;
    }
};

int main()
{
    unique_ptr<int> pDynamicAllocInteger(new int);
    *pDynamicAllocInteger = 42;

    cout << "Integer value is: " << *pDynamicAllocInteger << endl;

    unique_ptr<Date> pHoliday(new Date(25, 11, 2011));
    cout << "The new instance of date contains: ";
    pHoliday->DisplayDate();

    // Không cần delete vì unique_ptr sẽ tự động giải phóng
    //delete pDynamicAllocInteger;
    //delete pHoliday;
    return 0;
}
