#include "Rectangle.h"
#include "Square.h"

int main() {
	
	Rectangle* pRec;
	Rectangle Rec; // constructor rong, default 
	Square Sq;

	cout << "Rectangle's sizes (width and height): ";
	pRec = &Rec; // con tro tro den dia chi cua mot doi tuong trong o nho, tinh
	pRec->Input(cin);
	cout << "Rectangle's area = " << Rec.Area() << endl;

	cout << "Square's sizes: ";
	pRec = &Sq;
	pRec->Input(cin); // khong biet phai tro vao dau trong 2 truong hop la Rectangle va Square
	cout << "Square's area = " << Sq.Area() << endl;


	return 0;
}