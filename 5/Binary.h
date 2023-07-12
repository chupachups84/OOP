#pragma once
#include "Integer.h"
class Binary :public Integer {
protected:
	/*Реализация метода toLL для класса Binary
	@return  s1 - long long число в десятичной системе счисления*/
	long long toLL();
	/*Реализация метода toArray для класса Binary
	@param n - целое число */
	void toArray(int n);
public:
	/*Конструктор по умолчанию*/
	Binary();
	/*Конструктор с параметрами
	@param n - десятичное целое число*/
	Binary(int n);
};