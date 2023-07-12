#pragma once
class BitString
{
	unsigned long long bytes1;
	unsigned long long bytes2;
public:
	void toString();
	void setB1(unsigned long long b);
	void setB2(unsigned long long b);
	void AND(BitString bytes);
	void OR(BitString bytes);
	void XOR(BitString bytes);
	void NOT();
	void shiftLeft(int n);
	void shiftRight(int n);
	unsigned long long getB1();
	unsigned long long getB2();
	BitString(unsigned long long b1, unsigned long long b2);
};

