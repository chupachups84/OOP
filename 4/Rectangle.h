#include "Pair.h"
#include <string>
class Rectangle :public Pair {

public:
	/*Контруктор по умолчанию */
	Rectangle();
	/*Конструктор с параметрами
	@param _x - 1 сторона
	@param _y - 2 сторона*/
	Rectangle(double _x, double _y);
	/*Метод возвращающий площадь прямоугольника
	@return площадь прямоугольника*/
	double S();
	/*Метод возвращающий периметр прямоугольника
	@return периметр прямоугольника*/
	double P();
};