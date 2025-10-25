#include <iostream>
#include <string>
using namespace std;

/*
- Con trỏ có 2 vùng nhớ liên quan: 
  + bản thân con trỏ: chứa địa chỉ mà nó đang quản lý 
  + vùng nhớ mà nó đang quản lý 
- Khi truyền con trỏ vào trong hàm thì vùng nhớ "bản thân con trỏ" sẽ theo nguyên tắc của truyền tham trị và truyền tham chiếu được đề cập ở bên trên.
- Tuy nhiên, vùng nhớ mà nó đang quản lý thì hoàn toàn độc lập. Do đó, mặc dù truyền tham trị cho con trỏ vào bên trong một hàm nào đó thì khi thay đổi nội dung của vùng nhớ mà con trỏ đó 
 trỏ đó đang quản lý cũng sẽ làm thay đổi nội dung này ở bên ngoài. Chỉ có nội dung của "bản thân con trỏ" là không bị thay đổi nếu truyền vào tham trị.
- Khi truyền vào tham trị, thì con trỏ được quyền thay đổi địa chỉ của con trỏ mà nó nhận được ở bên ngoài. 
*/

void TruyenThamTri(int* temp) {
	*temp = 5; // thay doi du lieu ben trong vung nho dang tro toi luc nay bien ben ngoai cung bi thay doi nhung dia chi van khong thay doi 
	temp = new int; // thay doi noi dung vung nho moi cho temp, dong nay khong co y nghia, chi gay ra memory leak 
}

void TruyenThamChieu(int*& q) {
	q = new int[3];
	q[0] = 1;
	q[1] = 2;
	q[2] = 3;
}

int main() {
	int x = 10; // 00000092AE9BF584
	int* p = &x;  
	cout << &x << endl; // dia chi cua x 
	cout << p << endl; // noi dung cua con tro 
	cout << &p << endl; // dia chi cua con tro 
	cout << *p << endl; // du lieu trong vung nho ma no dang tro toi 
	*p = 3; // luc nay gia tri cua x cung thay doi thanh 3 
	cout << x << endl;
	cout << "Bat dau cua hanh trinh tim ra nhung thu moi: " << endl;
	cout << "x = " << x << endl;
	cout << "Con tro p = " << p << "Gia tri cua *p = " << *p << endl;
	TruyenThamTri(p);
	cout << "x = " << x << endl;
	cout << "Con tro p = " << p << "Gia tri cua *p = " << *p << endl;
	TruyenThamChieu(p);
	cout << "con tro p = " << p << "Gia tri cua *p = " << *(p) << " " << *(p + 1) << " " << *(p + 2) << endl;
	delete[] p; // thu hoi bo nho cho p 
	return 0;
}


//int main() {
//	int x = 10;
//	int* p = &x; // p giu dia chi cua x 
//	cout << "Noi dung cua p =  " << p << " Dia chi cua con tro p = " << &p << endl;
//	p = new int; // xin mot cai moi 
//	cout << "Noi dung cua p = " << p << " Dia chi cua con tro p = " << &p << endl;
//	return 0;
//}