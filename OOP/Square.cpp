#include "Square.h"

Square::Square() {
	width = height = 0;
}

Square::Square(float a) {
	width = height = a;
}

float Square::Area() {
	return width*height;
}
void Square::Input(istream& inDevice) {
	inDevice >> width;
	height = width;
}


