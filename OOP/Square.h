#pragma once
#include <iostream>
#include "Rectangle.h"

using namespace std;

class Square : public Rectangle {
public:
	Square();
	Square(float a); // canh mac dinh cua no bang 0
	void Input(istream& inDevice);
	float Area();
};