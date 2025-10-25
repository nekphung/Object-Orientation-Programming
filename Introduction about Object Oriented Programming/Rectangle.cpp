#include <iostream>
#include <vector>
using namespace std;


class Rectangle {
protected:
	float width, height;
public:
	Rectangle(float w, float h);
	float Area();
	void Input(istream& inDevice);
};

class Square : public Rectangle {
public:
	Square(float a);
	void Input(istream& inDevice);
};

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

Square::Square(float a) {
	width = height = a;
}

void Square::Input(istream& inDevice) {
	inDevice >> width;
	height = width;
}


int main() {


	return 0;
}