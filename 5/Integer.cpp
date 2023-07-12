#include "Integer.h"
int* Integer::getNum() {
	return num;
}

int Integer::getSize()
{
		return size;
}

Integer::Integer() {
	num = new int[0];
	size = 0;
}
Integer::Integer(const Integer& obj) {
	num = new int[obj.size];
	size = obj.size;
	for (int i = 0; i < size; i++) {
		num[i] = obj.num[i];
	}
}

void Integer::sum(Integer& obj)
{
	long long s1 = toLL(), s2 = obj.toLL();
	int n = s1 + s2;
	toArray(n);
}

void Integer::dif(Integer& obj)
{
	long long s1 = toLL(), s2 = obj.toLL();
	int n = s1 - s2;
	toArray(n);
}

void Integer::mul(Integer& obj)
{
	long long s1 = toLL(), s2 = obj.toLL();
	int n = s1 * s2;
	toArray(n);
}

void Integer::div(Integer& obj)
{
	long long s1 = toLL(), s2 = obj.toLL();
	if (s2 != 0) {
		int n = s1 / s2;
		toArray(n);
	}
}

Integer::~Integer() {
	delete num;
	size = 0;
}

ostream& operator<<(ostream& sout, const Integer& integer)
{
	for (int i = 0; i < integer.size; ++i) {
		sout << integer.num[i];
	}
	return sout ;
}
