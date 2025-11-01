#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
protected: 
	double width, length; 
public: 
	Rectangle();
	Rectangle(double width, double length);
	Rectangle(double width, double length, string color, bool filled);
	double getWidth();
	void setWidth(double width);
	double getLength();
	void setLength(double length);
	double getArea() override;
	double getPerimeter() override;
	string toString();
};

