#include "Circle.h"

Circle::Circle(): Shape(), radius(0.0) {}

Circle::Circle(double radius): Shape() {
	this->radius = radius; 
}

Circle::Circle(double radius, string color, bool filled): 
	Shape(color, filled), radius(radius)
{}

double Circle::getRadius() {
	return radius; 
}

void Circle::setRadius(double radius) {
	this->radius = radius; 
}

double Circle::getArea() 
{ 
	// dien tich hinh tron
	return 3.14 * radius * radius; 
}

double Circle::getPerimeter()  {
	// chu vi hinh tron 
	return 2 * 3.14 * radius; 
}

string Circle::toString() {
	ostringstream oss;
	oss << "Radius : " << fixed << setprecision(2) << radius << "\n";
	oss << Shape::toString(); 
	oss << "Perimeter : " << fixed << setprecision(2) << getPerimeter() << "\n";
	oss << "Area : " << fixed << setprecision(2) << getArea() << "\n";
	return oss.str(); 
}