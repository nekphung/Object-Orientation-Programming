#include "Rectangle.h"

Rectangle::Rectangle(float w, float h) {
	this->width = w;
	this->height = h;
}

float Rectangle::Area() {
	return width * height;
}

void Rectangle::Input(istream& inDevice) {
	inDevice >> width >> height;
}