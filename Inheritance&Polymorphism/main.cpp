#include "Student.h"
#include "Person.h"
#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

#define MAX 1000

int main() {
	int n; cin >> n; 
	//cin.ignore(); 
	Shape** shapes = new Shape * [n]; 
	for (int i = 0; i < n; i++) {
		char x; cin >> x; 
		if (x == 'S') {
			double side; cin >> side; 
			//cin.ignore();
			string color; cin >> color; 
			bool filled; 
			string fill; cin >> fill; 
			filled = (fill == "true") ? 1 : 0; 
			shapes[i] = new Square(side, color, filled); 
		}
		else if (x == 'C') {
			double radius; cin >> radius; 
			//cin.ignore();
			string color; cin >> color; 
			bool filled; 
			string fill; cin >> fill; 
			filled = (fill == "true") ? 1 : 0; 
			shapes[i] = new Circle(radius, color, filled); 
		}
		else {
			double width; cin >> width;
			double length; cin >> length; 
			//cin.ignore();
			string color; cin >> color; 
			bool filled; 
			string fill; cin >> fill; 
			filled = (fill == "true") ? 1 : 0;
			shapes[i] = new Rectangle(width, length, color, filled); 
		}
	}
	cout << "Circle : " << endl; 
	cout << "-----------------------" << endl; 
	for (int i = 0; i < n; i++) {
		Circle* c = dynamic_cast<Circle*>(shapes[i]);
		if (c != nullptr) {
			cout << c->toString();
			cout << "-----------------------" << endl;
		}
	}

	cout << "Rectangle : " << endl; 
	cout << "-----------------------" << endl; 
	for (int i = 0; i < n; i++) {
		// Kiem tra xem no co phai la Square khong 
		Square* s = dynamic_cast<Square*>(shapes[i]);
		if (s != nullptr) {
			continue; // bo qua cac square
		}
		Rectangle* r = dynamic_cast<Rectangle*>(shapes[i]);
		if (r != nullptr) {
			cout << r->toString();
			cout << "-----------------------" << endl;
		}
	}
	cout << "Square : " << endl; 
	cout << "-----------------------" << endl;
	for (int i = 0; i < n; i++) {
		Square* s = dynamic_cast<Square*>(shapes[i]);
		if (s != nullptr) {
			cout << s->toString();
			cout << "-----------------------" << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		delete shapes[i];
	}
	delete[] shapes; 
	return 0; 
}



//int main() {
//    NVSanXuat sx1;
//    cout << "Nhap nvsx1" << endl;
//    sx1.Nhap();
//
//    NVCongNhat cn1;
//    cout << "Nhap nvcn1" << endl;
//    cn1.Nhap();
//    return 0;
//}

//int main() {
//	int n; cin >> n;
//	cin.ignore();
//	Student* list[MAX] = { NULL };
//	for (int i = 0; i < n; i++) {
//		char ten[256];
//		cin.getline(ten, 256);
//		char ns[256];
//		cin.getline(ns, 256);
//		char diaChi[256];
//		cin.getline(diaChi, 256);
//		char lop[256];
//		cin.getline(lop, 256);
//		double gpa; 
//		cin >> gpa; 
//		cin.ignore(); 
//		list[i] = new Student(ten, ns, diaChi, lop, gpa);  // gan doi tuong trong c++
//	}
//	for (int i = 0; i < n; i++) {
//		cout << list[i]->toString() << endl;
//	}
//	for (int i = 0; i < MAX; i++) {
//		if (list[i]) delete list[i]; 
//	}
//	return 0; 
//}