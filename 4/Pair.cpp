#include "Pair.h"
Pair::Pair() { 
	x = 0;
	y = 0; 
}
Pair::Pair(double _x, double _y) { 
	x = _x; 
	y = _y;
}
void Pair::setX(double _x) {
	x = _x; 
}
void Pair::setY(double _y) {
	y = _y;
}
double Pair::getX() {
	return x;
}
double Pair::getY() {
	return y; 
}
double Pair::compozition() { 
	return x * y;
}

std::string Pair::toString()
{
	std::string str = std::to_string(x) + " " + std::to_string(y);
	return str;
}
