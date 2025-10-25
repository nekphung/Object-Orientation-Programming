#include <iostream>
using namespace std;

/*
- Một số lưu ý về hàm thuần ảo 
 + Một hàm thuần ảo không có phần triển khai trong class cha.
 + Nó bắt buộc các class dẫn xuất(con) phải override lại hàm này, có nghĩa là ghi đè lên hàm đó.
 + Class nào có ít nhất một hàm thuần ảo thì trở thành abstract class (lớp trừu tượng).
 + Bạn không thể tạo object trực tiếp từ abstract class. 

- Đúng là không thể tạo trực tiếp object từ abstract class (ví dụ Fish f; sẽ bị lỗi nếu Fish có hàm thuần ảo = 0).Nhưng
có thể khai báo con trỏ hoặc reference kiểu abstract class.Lí do:
 + Abstract class chỉ không thể instantiate(tạo object cụ thể) vì nó chưa "hoàn thành", nó có hàm chưa được định nghĩa.
 + Nhưng con trỏ hoặc reference chỉ cần biết giao diện(interface), không cần tạo object thực.
 + Sau đó, bạn gán cho nó một object của class con(class con đã được implement đầy đủ các hàm thuần ảo).
*/


class Fish
{
public:
    Fish() {
        cout << "Constructor Fish" << endl; 
    }

    virtual ~Fish() // virtual destructor
    {
        cout << "Destructor Fish" << endl;
    } 
    virtual Fish* Clone() = 0; // pure virtual function
    virtual void Swim() = 0; // pure virtual function, neu khong dung ham thuan ao thi no chi goi thang cha thoi va khong the nao xoa duoc thang con, thang ke thua cua lop do
};

class Tuna : public Fish
{
public:
    Tuna() {
        cout << "Constructor Tuna" << endl; 
    }

    Fish* Clone() override // override Fish::Clone();
    {
        cout << "Copy constructor Tuna" << endl; 
        return new Tuna(*this);
    }

    void Swim() override // no phai override cai co san de su dung 
    {
        cout << "Tuna swims fast in the sea" << endl;
    }
    ~Tuna() {
        cout << "Destructor Tuna" << endl;
    }
};

class Carp : public Fish
{
public:
    Carp() {
        cout << "Constructor Carp" << endl; 
    }

    Fish* Clone() override
    {
        cout << "Copy constructor Carp" << endl; 
        return new Carp(*this); 
    }

    void Swim() override
    {
        cout << "Carp swims slow in the lake" << endl;
    }
    ~Carp()
    {
        cout << "Destructor Carp" << endl;
    }
};



int main()
{
    const int ARRAY_SIZE = 4;

    Fish* myFishes[ARRAY_SIZE] = { NULL };
    cout << "Du lieu cu: " << endl; 
    myFishes[0] = new Tuna();
    myFishes[1] = new Carp();
    myFishes[2] = new Tuna();
    myFishes[3] = new Carp();


    cout << "Du lieu moi: " << endl; 
    Fish* myNewFishes[ARRAY_SIZE]; // chi la con tro thoi 
    for (int Index = 0; Index < ARRAY_SIZE; ++Index)
         myNewFishes[Index] = myFishes[Index]->Clone(); // phep gan mac dinh cua compiler 
      //  myNewFishes[Index] = new Tuna();

    cout << "In ra Swim: " << endl; 
    // invoke a virtual method to check
    for (int Index = 0; Index < ARRAY_SIZE; ++Index)
        myNewFishes[Index]->Swim();

    // memory cleanup
    for (int Index = 0; Index < ARRAY_SIZE; ++Index)
    {
        delete myFishes[Index];
        delete myNewFishes[Index];
    }

    // xóa khi cấp phát động 
    /* delete[] myFishes;
    delete[] myNewFishes;*/
    return 0;
}
