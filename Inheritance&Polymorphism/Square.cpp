#include "Square.h"


Square::Square(): Rectangle() {}
Square::Square(double side) : Rectangle(side, side) {
}

Square::Square(double side, string color, bool filled)
	: Rectangle(side, side, color, filled)
{
}
double Square::getSide() {
	return Rectangle::getWidth(); 
}
void Square::setSide(double side) {
	Rectangle::setWidth(side);
	Rectangle::setLength(side); 
}
void Square::setWidth(double side) {
	Rectangle::setWidth(side);
}
void Square::setLength(double side) {
	Rectangle::setLength(side);
}
string Square::toString() {
	ostringstream oss;
	oss << "Side : " << fixed << setprecision(2) << getSide() << "\n"; 
	oss << Shape::toString();
	oss << "Perimeter : " << fixed << setprecision(2) << getPerimeter() << "\n";
	oss << "Area : " << fixed << setprecision(2) << getArea() << "\n";
	return oss.str();
}