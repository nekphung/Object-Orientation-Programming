#pragma once
#include "Person.h"

class Student: Person
{
private: 
	int ma; 
	static int soluong; // ma so sinh vien duoc in ra 0001
	double Gpa; 
	char* Lop; 
public: 
	Student();
	Student(const char* ten, const char* ns, const char* diaChi, const char* lop, const double& gpa); 
	char* toString();
	Student& operator=(const Student& other); // nap chong toan tu gan 
	~Student(); 
};

