#include <iostream>
#include <string>
using namespace std; 

class Point {
	int x, y; 
public: 
	Point(): x(0), y(0){}
	
	Point& operator++() { // prefix ++ 
		++x; 
		++y; 
		return *this; // trả về tham chiếu đến đối tượng
	}

	Point operator++(int) { // postfix ++ 
		Point temp = *this;  // lưu trạng thái cũ
		++(*this);   // cộng sau 
		return temp; // trả về bản cũ 
	}

};