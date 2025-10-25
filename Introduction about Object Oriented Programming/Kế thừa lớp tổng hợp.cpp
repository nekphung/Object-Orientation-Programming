#include <iostream>
#include <string>

using namespace std;

// 1. Ví dụ cơ bản: Kế thừa nhiều lớp cùng lúc 

/* 
class A {
private: 
	int x; 
public: 
	void showA() { cout << "Class A" << endl; }
}; 

class B {
public: 
	void showB() { cout << "Class B" << endl;  }
};

// C ke thua ca A va B 
class C : public A, public B {
public:
	void showC() {
		cout << "Class C" << endl;
	}
};


int main() {
	C obj; 
	obj.showA();
	obj.showB(); 
	obj.showC();
	return 0; 
}*/

// 2. Van de trung ten ham 

/*
class A {
public : 
	void show() { cout << "A" << endl; }
};

class B {
public : 
	void show() {
		cout << "B" << endl; 
	}
};

class C : public A, public B
{
};


int main() {
	C obj; 
	//obj.show(); // khong biet chon ham show() cua A hay B 
	obj.A::show(); // chi ro ra pham vi cua ham 
	obj.B::show(); // chi ro ra B 
	return 0;
}*/


// 3. Diamond Problem (van de kim cuong) 

/*
class A {
public:
	int value;
	A() : value(10) {}
};

class B : public A { };
class C : public A { };

// D kế thừa cả B và C
class D : public B, public C { };

int main() {
	D obj;
	// cout << obj.value; // ❌ Lỗi: D có 2 bản copy của A
	cout << obj.B::value << endl; // ✅ truy cập rõ ràng
	cout << obj.C::value << endl; // ✅
}
*/

// 4. Giai quyet diamond bang virtual inheritance 

/*
class A {
public:
	int value;
	A() : value(10) {}
};

class B : virtual public A { };
class C : virtual public A { };

class D : public B, public C { };

int main() {
	D obj;
	cout << obj.value << endl; // ✅ chỉ còn 1 bản A
}

*/

// 5. Truong hop cuc phuc tap 

/*
class Drawable {
public:
	virtual void draw() = 0;
};

// lop truu tuong 
class Updatable {
public:
	virtual void update() = 0;
};

class PhysicsObject : public Updatable {
public:
	void update() override { // vật lý  }
};

class Sprite : public Drawable, public PhysicsObject {
public:
	void draw() override { // vẽ hình ảnh  }
	void update() override {
		PhysicsObject::update();
		// thêm animation 
	}
};
// Nếu hàm đó là ảo thì tất cả các lớp kế thừa từ lớp đó cũng là ảo 
*/
