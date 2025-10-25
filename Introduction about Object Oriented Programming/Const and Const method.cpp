#include <iostream> 
using namespace std;


class Box {
	int width;
public: 
	Box(int w): width(w) {}

	// ham co tham so const nhung truyen tham tri 
	void setWidth(const int& w) {
		// w = 100;  // nó sẽ không cho phép thay đổi vì nó là const  
		width = w; // thay doi du lieu noi bo 
	}

	// Ham const method (khong thay doi noi dung cua doi tuong goi ham) 
	int getWidth() const {
	   // width = 200;  // Bi loi khong the nao thuc hien duoc nhu vay duoc 
		return width; // chi doc du lieu 
	}

	int getWidth1() {
		width = 100; 
		return width;
	}
	// Lý do dùng const trong tham chiếu chứ không dùng tham trị là đối với dữ liệu lớn thì chỉ cần tham chiếu tới thôi không cần phải copy dữ liệu nên nó sẽ nhanh hơn 
};


int main() {
	Box b(10);

	int x = 20; 
	b.setWidth(x);
	cout << b.getWidth() << endl; 

	const Box c(50);
	cout << c.getWidth() << endl; // goi duoc vi no la const method 
	return 0;
}