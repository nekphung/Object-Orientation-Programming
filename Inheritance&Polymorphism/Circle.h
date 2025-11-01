#pragma once
#include "Shape.h"
class Circle : public Shape
{
private: 
	double radius; 
public: 
	Circle();
	Circle(double radius);
	Circle(double radius, string color, bool filled);
	double getRadius();
	void setRadius(double radius);
	double getArea() override; 
	double getPerimeter() override; 
	string toString(); 
};

