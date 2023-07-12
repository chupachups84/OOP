#pragma once
#include <iostream>
#include <string>
using namespace std;
class Time {
	int* hour;
	int* minute;
	int* second;
public:
	Time();
	
	Time(int h, int m, int s);
	~Time();
	Time(const Time& copy);
	void setH(int h);
	void setM(int h);
	void setS(int h);
	int getH();
	int getM();
	int getS();
	string toString();
	Time operator  + (int sec);
	Time operator  - (int sec);
	Time operator  + (Time obj);
	Time operator -(Time obj);

	bool operator ==(Time obj);
	bool operator !=(Time obj);
	bool operator <(Time obj);
	bool operator >(Time obj);
	bool operator <=(Time obj);
	bool operator >=(Time obj);

	Time& operator +=(Time obj);
	Time& operator +=(int sec);
	Time& operator -=(Time obj);
	Time& operator -=(int sec);

};