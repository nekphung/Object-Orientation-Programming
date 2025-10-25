#include <iostream> 
using namespace std; 


// Trường hợp dùng virtual và không có tham số 
//class A {
//public: 
//	A() {
//		cout << "Constructor A" << endl;
//	}
//	~A() {
//		cout << "Destructor A" << endl; 
//	}
//};
//
//class B: virtual public A {
//public: 
//	B() {
//		cout << "Constructor B" << endl;
//	}
//	~B() {
//		cout << "Destructor B" << endl;
//	}
//};
//
//class C : virtual public A {
//public: 
//	C() {
//		cout << "Constructor C" << endl;
//	}
//	~C() {
//		cout << "Destructor C" << endl;
//	}
//};
//
//class D : public B, public C {
//public : 
//	D() {
//		cout << "Constructor D" << endl;
//	}
//	~D() {
//		cout << "Destructor D" << endl;
//	}
//};
//
//
//
//int main() {
//	B b;
//	cout << " ----------------------------------- " << endl;
//	C c;
//	cout << " ----------------------------------- " << endl;
//	D d;
//	cout << " ----------------------------------- " << endl;
//	return 0;
//}


// Trường hợp A có truyền tham số vào hàm và không dùng virtual 
//class A {
//public:
//    int value;
//    A(int v) : value(v) {
//        cout << "Constructor A, value = " << value << endl;
//    }
//    ~A() {
//        cout << "Destructor A" << endl;
//    }
//};
//
//class B : public A {
//public:
//    B(int v) : A(v) {
//        cout << "Constructor B" << endl;
//    }
//    ~B() {
//        cout << "Destructor B" << endl;
//    }
//};
//
//class C : public A {
//public:
//    C(int v) : A(v) {
//        cout << "Constructor C" << endl;
//    }
//    ~C() {
//        cout << "Destructor C" << endl;
//    }
//};
//
//// D không virtual → sẽ chứa 2 bản A
//class D : public B, public C {
//public:
//    D(int vb, int vc) : B(vb), C(vc) {
//        cout << "Constructor D" << endl;
//    }
//    ~D() {
//        cout << "Destructor D" << endl;
//    }
//};
//
//int main() {
//    D d(11, 22);
//    return 0;
//}


// Trường hợp có tham số và dùng virtual 

//class A {
//public:
//    int value;
//    A(int v) : value(v) {
//        cout << "Constructor A, value = " << value << endl;
//    }
//    ~A() {
//        cout << "Destructor A" << endl;
//    }
//};
//
//class B : virtual public A {
//public:
//    // B KHÔNG được phép tự ý gọi A(v)
//    // vì A là virtual base → chỉ most-derived (D) được khởi tạo A
//    B() : A(0) {  // ⚠️ BẮT BUỘC phải gọi A(0) tạm nếu A không có default ctor
//        cout << "Constructor B" << endl;
//    }
//    ~B() {
//        cout << "Destructor B" << endl;
//    }
//};
//
//class C : virtual public A {
//public:
//    C() : A(0) {  // ⚠️ giống như B
//        cout << "Constructor C" << endl;
//    }
//    ~C() {
//        cout << "Destructor C" << endl;
//    }
//};
//
//class D : public B, public C {
//public:
//    // D là most-derived → chỉ D mới được phép khởi tạo A thực sự
//    D(int v) : A(v), B(), C() {
//        cout << "Constructor D" << endl;
//    }
//    ~D() {
//        cout << "Destructor D" << endl;
//    }
//};
//
//int main() {
//    D d(42);
//    return 0;
//}


// Trường hợp copy dữ liệu 

//class A {
//public:
//    int value;
//    A(int v = 0) : value(v) { cout << "A ctor, value=" << value << endl; }
//    A(const A& other) : value(other.value) { cout << "A copy ctor\n"; }
//    ~A() { cout << "A dtor\n"; }
//};
//
//class B : virtual public A {
//public:
//    B() { cout << "B ctor\n"; }
//    B(const B& other) { cout << "B copy ctor\n"; }
//    ~B() { cout << "B dtor\n"; }
//};
//
//class C : virtual public A {
//public:
//    C() { cout << "C ctor\n"; }
//    C(const C& other) { cout << "C copy ctor\n"; }
//    ~C() { cout << "C dtor\n"; }
//};
//
//class D : public B, public C {
//public:
//    D(int v) : A(v), B(), C() { cout << "D ctor\n"; }
//
//    // copy constructor cho D
//    D(const D& other)
//        : A(other), B(other), C(other)   // ⚠️ chỉ D mới gọi A(other)
//    {
//        cout << "D copy ctor\n";
//    }
//
//    ~D() { cout << "D dtor\n"; }
//};
//
//int main() {
//    D d1(42);
//    cout << "----- copy -----\n";
//    D d2(d1);
//}

class A {
public: 
	A() {
		cout << "Constructor A" << endl; 
	}
	~A() {
		cout << "Destructor A" << endl; 
	}

};

void ham(A a) {
	// write code here 
}

int main() {
	A a;
    ham(a);
	return 0;
}
