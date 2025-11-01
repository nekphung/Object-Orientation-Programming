#include "Student.h"

Student::Student(): Person(), Gpa(0.0) {
	Lop = new char[1];
	Lop[0] = '\0';
	soluong++; 
	ma = soluong; 
}

int Student::soluong = 0; 

Student::Student(const char* ten, const char* ns, const char* diaChi, const char* lop, const double& gpa): 
	Person(ten, ns, diaChi), Gpa(gpa)
{
	// Neu truyen doi tuong do vao than thi chi la tao doi tuong tam thoi 
	// Neu truyen vao Person::Person(ten, ns, diaChi) thi sai phu phap  
	Lop = new char[strlen(lop) + 1];
	strcpy_s(Lop, strlen(lop) + 1, lop);
	soluong++;
	ma = soluong;
}

char* Student::toString() {
	char* parentStr = Person::toString(); 
	int size = strlen(parentStr) + strlen(Lop) + 50; 
	char* res = new char[size];
	sprintf(res, "%04d %s %s %.2f", ma, parentStr, Lop, Gpa);
	delete[] parentStr; 
	return res; 
}

Student& Student::operator=(const Student& other) {
	if (this != &other) { // tranh gan trung 
		Person::operator=(other); 
		delete[] Lop;
		Lop = new char[strlen(other.Lop) + 1]; 
		strcpy(Lop, other.Lop); 
		Gpa = other.Gpa; 
		ma = other.ma;
	}
	return *this; 
}

Student::~Student() {
	delete[] Lop;
	Lop = nullptr; 
} 