#include "Rectangle.h"

Rectangle::Rectangle(): Shape(), width(0.0), length(0.0) {}

Rectangle::Rectangle(double width, double length): 
Shape(), width(width), length(length) {}

Rectangle::Rectangle(double width, double length, string color, bool filled) 
 : Shape(color, filled), width(width), length(length) {}

double Rectangle::getWidth() {
	return width; 
}

void Rectangle::setWidth(double width) {
	this->width = width; 
}

double Rectangle::getLength() {
	return length; 
}

void Rectangle::setLength(double length) {
	this->length = length; 
}

double Rectangle::getArea()  {
	return width * length; 
}
double Rectangle::getPerimeter()  {
	return 2 * (width + length); 
}
string Rectangle::toString() {
	ostringstream oss;
	oss << "Width : " << fixed << setprecision(2) << width << "\n";
	oss << "Length : " << fixed << setprecision(2) << length << "\n"; 
	oss << Shape::toString();
	oss << "Perimeter : " << fixed << setprecision(2) << getPerimeter() << "\n";
	oss << "Area : " << fixed << setprecision(2) << getArea() << "\n";
	return oss.str();
}