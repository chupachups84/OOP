#include "Rectangle.h"
Rectangle::Rectangle(){}
Rectangle::Rectangle(double _x, double _y) { 
	x = _x; 
	y = _y; 
}
double Rectangle::S() {
	return compozition();
}
double Rectangle::P() {
	return Pair(2, x + y).compozition();
}