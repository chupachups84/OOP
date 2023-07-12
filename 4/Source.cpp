#include "Rectangle.h"
#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите 2 стороны прямоугольника: " << endl;
	double a, b;
	cin >> a>> b;
	Rectangle r(a, b);
	cout << "Площадь равна " << r.S() << endl;
	cout << "Периметр равен " << r.P() << endl;
}