#include "BitString.h"
#include <iostream>
using namespace std;
BitString::BitString(unsigned long long b1, unsigned long long b2)
{
	bytes1 = b1;
	bytes2 = b2;
}
void BitString::toString()
{
	cout << "bytes1 = " << this->bytes1 << "\nbytes2 = " << this->bytes2 << '\n';
}
void BitString::setB1(unsigned long long b)
{
	bytes1 = b;
}
void BitString::setB2(unsigned long long b)
{
	bytes2 = b;
}
unsigned long long BitString::getB1()
{
	return this->bytes1;
}
unsigned long long BitString::getB2()
{
	return this->bytes2;
}
void BitString::AND(BitString bytes)
{
	this->bytes1 &= bytes.bytes1;
	this->bytes2 &= bytes.bytes2;
}
void BitString::OR(BitString bytes)
{
	this->bytes1 |= bytes.bytes1;
	this->bytes2 |= bytes.bytes2;
}
void BitString::XOR(BitString bytes)
{
	this->bytes1 ^= bytes.bytes1;
	this->bytes2 ^= bytes.bytes2;
}
void BitString::NOT()
{
	this->bytes1 = ~(this->bytes1);
	this->bytes2 = ~(this->bytes2);
}
void BitString::shiftLeft(int n)
{
	this->bytes1 = this->bytes1 << n;
	this->bytes2 = this->bytes2 << n;
}
void BitString::shiftRight(int n)
{
	this->bytes1 = this->bytes1 >> n;
	this->bytes2 = this->bytes2 >> n;
}

