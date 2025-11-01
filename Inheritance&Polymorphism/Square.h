#pragma once
#include "Rectangle.h"
class Square : public Rectangle
{
public: 
	Square();
	Square(double side);
	Square(double side, string color, bool filled);
	double getSide();
	void setSide(double side);
	void setWidth(double side); 
	void setLength(double side); 
	string toString(); 
};

