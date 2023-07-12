#pragma once
#include "Integer.h"
class Decimal :public Integer {
protected:
	/*Реализация метода toLL для класса Decimal
	@return  s1 - long long число в десятичной системе счисления*/
	long long toLL();
	/*Реализация метода toArray для класса Decimal
	@param n - целое число */
	void toArray(int n);
public:
	/*Конструктор по умолчанию*/
	Decimal();
	/*Конструктор с параметрами
	@param n - десятичное целое число*/
	Decimal(int n);
};