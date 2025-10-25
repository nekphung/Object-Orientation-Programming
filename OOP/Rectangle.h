#pragma once
#include <iostream>
using namespace std;

class Rectangle {
protected:
	float width, height;
public:
	Rectangle() : width(0), height(0) {}; // default constructor 
	Rectangle(float w, float h);
	float Area();
	virtual void Input(istream& inDevice); // khai bao phuong thuc da hinh 
};

