#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
//private: 
protected: // lop con co the try xuat duoc nhung lop ngoai khong the 
	char* name; 
	char* birthDay;
	char* address; 
public: 
	Person(); 
	Person(const char* ten, const char* ns, const char* diaChi);
    char* toString();
	void chuanHoaTen();
	void chuanHoaNgaySinh(); 
	Person& operator=(const Person& other); 
	~Person(); // thu hoi doi tuong 
};