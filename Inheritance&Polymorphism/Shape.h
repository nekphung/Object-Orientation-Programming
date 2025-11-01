#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std; 

class Shape
{
protected: 
	string color; 
	bool filled; 
public: 
	Shape(); 
	Shape(string color, bool filled); 
	string getColor();
	void setColor(string color); 
	bool isFilled();
	void setFilled(bool filled);
	virtual double getArea() = 0; // pure virtual methods 
	virtual double getPerimeter() = 0; 
	string toString(); 
};

