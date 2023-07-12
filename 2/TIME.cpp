#include "TIME.h"
Time::Time() {
	/*
	Конструктор класса Time по умолчанию
	@param NULL
	*/
	hour = new int(0);
	minute = new int(0);
	second = new int(0);
}
Time::Time(int h, int m, int s) {
	/*
	Конструктор класса Time с параметрами
	@param int h - часы
	@param int m - минуты
	@param int s - секунды
	*/
	hour = new int(h);
	minute = new int(m);
	second = new int(s);
}
Time::~Time() {
	/*Деструктор класса Time*/
	delete hour, minute, second;
}
Time::Time(const Time& copy) {
	/*
	Конструктор копирования класса Time, для передачи в ф-ию
	@param const Time & copy - адрес передаваемого экземпляра класса Time(копия экземпляра)
	*/
	hour = new int(*copy.hour);
	minute = new int(*copy.minute);
	second = new int(*copy.second);
}
void Time::setH(int h) {
	/*
	Изменение значения часов
	@param int h - часы 
	@return NULL
	*/
	*hour = h;
}
void Time::setM(int m) {
	/*
	Изменение значения минут
	@param int m - минуты
	@return NULL
	*/
	*minute = m;
}
void Time::setS(int s) {
	/*
	Изменение значения секунд
	@param int s - секунды
	@return NULL
	*/
	*second = s;
}
int Time::getH() {
	/*
	Получение значения поля часов класса Time
	@param NULL
	@return - значение поля часов класса Time
	*/
	return *hour;
}
int Time::getM() {
	/*
	Получение значения поля минут класса Time
	@param NULL
	@return - значение поля минут класса Time
	*/
	return *minute;
}
int Time::getS() {
	/*
	Получение значения поля секунд класса Time
	@param NULL
	@return - значение поля секунд класса Time
	*/
	return *second;
}

string Time::toString() {
	/*
	Возвращение строки данных
	@param NULL
	@return - строка для вывода
	*/
	string h = "", m = "", s = "";
	h = *hour < 10 ? "0" + to_string(*hour) : to_string(*hour);
	m = *minute < 10 ? "0" + to_string(*minute) : to_string(*minute);
	s = *second < 10 ? "0" + to_string(*second) : to_string(*second);
	return h + ":" + m + ":" + s + "\n";
}

Time  Time::operator +(Time obj) {
	/*
	Оператор сложения
	@param obj - объект класса Time
	@return - объект класса Time
	*/
	int sec = *second, objS = obj.getS(),
		min = *minute, objM = obj.getM(),
		h = *hour, objH = obj.getH();
	sec += objS;
	if (sec >= 60) {
		min += 1;
		sec -= 60;
	}
	if (min >= 60) {
		h += 1;
		min-= 60;
	}
	min += objM;
	if (min >= 60) {
		h += 1;
		min-= 60;
	}
	if (h >= 24)
		h-=24;
	h += objH;
	if (h >= 24)
		h -= 24;
	Time c(h, min, sec);
	return c;
}
Time  Time::operator  + (int sec)
{
	/*
	Оператор сложения
	@param sec - целое число , кол-во секунд
	@return - объект класса Time
	*/
	int h = *hour, m = *minute, s = *second;
	s += sec;
	while (s >= 60) {
		m += 1;
		s -= 60;
	}
	while (m >= 60) {
		h += 1;
		m -= 60;
	}
	while (h >= 24)
		h -= 24;
	Time c(h, m, s);
	return c;
}
Time  Time::operator -(Time obj) {
	/*
	Оператор вычетания
	@param obj - объект класса Time
	@return - объект класса Time
	*/
	int sec = *second, objS = obj.getS(),
		min = *minute, objM = obj.getM(),
		h = *hour, objH = obj.getH();
	sec -= objS;
	if (sec < 0) {
		min -= 1;
		sec += 60;
	}
	if (min < 0) {
		h -= 1;
		min += 60;
	}
	min -= objM;
	if (min < 0) {
		h -= 1;
		min += 60;
	}
	if (h < 0)
		h += 24;
	h -= objH;
	if (h < 0)
		h += 24;
	Time c(h, min, sec);
	return c;
}
Time  Time::operator  - (int sec)
{
	/*
	Оператор вычетания
	@param sec - целое число , кол-во секунд
	@return - объект класса Time
	*/
	int h = *hour, m = *minute, s = *second;
	s -= sec;
	while (s < 0) {
		m -= 1;
		s += 60;
	}
	while (m < 0) {
		h -= 1;
		m += 60;
	}
	while (h < 0)
		h += 24;
	Time c(h, m, s);
	return c;
}

bool Time::operator ==(Time obj) {
	/*
	Оператор сравнения ==
	@param obj - объект класса Time
	@return - булевое значение ,результат операции сравнения 
	*/
	return (*hour == obj.getH()&&*minute==obj.getM()&&*second==obj.getS());
}
bool Time::operator !=(Time obj) {
	/*
	Оператор сравнения !=
	@param obj - объект класса Time
	@return - булевое значение ,результат операции сравнения
	*/
	return !(*hour == obj.getH() && *minute == obj.getM() && *second == obj.getS());
}
bool Time::operator <(Time obj) {
	/*
	Оператор сравнения <
	@param obj - объект класса Time
	@return - булевое значение ,результат операции сравнения
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour < h)
		return 1;
	else if (*hour > h)
		return 0;
	else{
		if (*minute < m)
			return 1;
		else if (*minute > m)
			return 0;
		else {
			if (*second < s)
				return 1;
			else
				return 0;
		}
	}
}
bool Time::operator >(Time obj) {
	/*
	Оператор сравнения >
	@param obj - объект класса Time
	@return - булевое значение ,результат операции сравнения
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour > h)
		return 1;
	else if (*hour < h)
		return 0;
	else {
		if (*minute > m)
			return 1;
		else if (*minute < m)
			return 0;
		else {
			if (*second > s)
				return 1;
			else
				return 0;
		}
	}
}
bool Time::operator <=(Time obj) {
	/*
	Оператор сравнения <=
	@param obj - объект класса Time
	@return - булевое значение ,результат операции сравнения
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour < h)
		return 1;
	else if (*hour > h)
		return 0;
	else {
		if (*minute < m)
			return 1;
		else if (*minute > m)
			return 0;
		else {
			if (*second < s)
				return 1;
			else if (*second > s)
				return 0;
			else
				return 1;
		}
	}
}
bool Time::operator >=(Time obj) {
	/*
	Оператор сравнения >=
	@param obj - объект класса Time
	@return - булевое значение ,результат операции сравнения
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour > h)
		return 1;
	else if (*hour < h)
		return 0;
	else {
		if (*minute > m)
			return 1;
		else if (*minute < m)
			return 0;
		else {
			if (*second > s)
				return 1;
			else if (*second < s)
				return 0;
			else
				return 1;
		}
	}
}

Time& Time::operator +=(Time obj) {
	/*
	Оператор присваивания +=
	@param obj - объект класса Time
	@return - объект класса Time,после использования оператора присваивания
	*/
	int objS = obj.getS(),
		objM = obj.getM(),
		objH = obj.getH();
	*second += objS;
	if (*second >= 60) {
		*minute += 1;
		*second -= 60;
	}
	if (*minute >= 60) {
		*hour += 1;
		*minute -= 60;
	}
	*minute += objM;
	if (*minute >= 60) {
		*hour += 1;
		*minute -= 60;
	}
	if (*hour >= 24)
		*hour-= 24;
	*hour += objH;
	if (*hour >= 24)
		*hour -= 24;
	return *this;
}
Time& Time::operator +=(int sec) {
	/*
	Оператор присваивания +=
	@param sec - целое число (кол-во секунд)
	@return - объект класса Time,после использования оператора присваивания
	*/
	*second += sec;
	while (*second >= 60) {
		*minute += 1;
		*second -= 60;
	}
	while (*minute >= 60) {
		*hour += 1;
		*minute -= 60;
	}
	while (*hour >= 24)
		*hour -= 24;
	return *this;
}
Time& Time::operator -=(Time obj) {
	/*
	Оператор присваивания -=
	@param obj - объект класса Time
	@return - объект класса Time,после использования оператора присваивания
	*/
	int objS = obj.getS(),
		objM = obj.getM(),
		objH = obj.getH();
	*second -= objS;
	if (*second < 0) {
		*minute -= 1;
		*second += 60;
	}
	if (*minute < 0) {
		*hour -= 1;
		*minute += 60;
	}
	*minute -= objM;
	if (*minute < 0) {
		*hour -= 1;
		*minute += 60;
	}
	if (*hour < 0)
		*hour += 24;
	*hour -= objH;
	if (*hour < 0)
		*hour += 24;
	return *this;
}
Time& Time::operator -=(int sec) {
	/*
	Оператор присваивания +=
	@param sec - целое число (кол-во секунд)
	@return - объект класса Time,после использования оператора присваивания
	*/
	*second -= sec;
	while (*second < 0) {
		*minute -= 1;
		*second += 60;
	}
	while (*minute < 0) {
		*hour -= 1;
		*minute += 60;
	}
	while (*hour < 0)
		*hour += 24;
	return *this;
}

