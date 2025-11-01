#include "Shape.h"

Shape::Shape() {
	color = "red";
	filled = true; 
}

Shape::Shape(string color, bool filled) {
	this->color = color; 
	this->filled = filled; 
}

string Shape::getColor() {
	return color; 
}
void Shape::setColor(string color) {
	this->color = color; 
}
bool Shape::isFilled() {
	return (filled == 1);
}

void Shape::setFilled(bool filled) {
	this->filled = filled; 
}
string Shape::toString() {
	ostringstream oss; 
	oss <<  "Color : " + color + +"\n" +
		"Filled : " + (filled ? "true" : "false") + "\n"; 
	return oss.str(); 
}