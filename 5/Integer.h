#pragma once
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
class Integer {
protected:
	int* num;
	int size;
	/*Чисто виртуальный метод toLL
	@return s1 - десятичное число*/
	virtual long long toLL() = 0;
	/*Чисто виртуальный метод toArray
	@param n - целое число*/
	virtual void toArray(int n)=0;
public:
	/*Возвращает поле num
	@return *num*/
	int* getNum();
	/*Возвращает поле size
	@return size*/
	int getSize();
	/*Конструктор по умолчанию*/
	Integer();
	/*Конструктор копирования
	@param obj - объект класса Integer*/
	Integer(const Integer& obj);
	/*Метод суммы
	@param - объект класса Integer*/
	void sum(Integer& obj) ;
	/*Метод разности
	@param - объект класса Integer*/
	void dif(Integer& obj) ;
	/*Метод умножения
	@param - объект класса Integer*/
	void mul(Integer& obj) ;
	/*Метод деления
	@param - объект класса Integer*/
	void div(Integer& obj) ;
	/*Метод вывода на экран
	@param sout - поток ostream
	@param integer - объект класса integer
	@return поток ostream*/
	friend ostream& operator<<(ostream& sout, const Integer& integer);
	/*Деструктор */
	~Integer();
};
//toLL i toMas