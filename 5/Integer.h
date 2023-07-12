#pragma once
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
class Integer {
protected:
	int* num;
	int size;
	/*����� ����������� ����� toLL
	@return s1 - ���������� �����*/
	virtual long long toLL() = 0;
	/*����� ����������� ����� toArray
	@param n - ����� �����*/
	virtual void toArray(int n)=0;
public:
	/*���������� ���� num
	@return *num*/
	int* getNum();
	/*���������� ���� size
	@return size*/
	int getSize();
	/*����������� �� ���������*/
	Integer();
	/*����������� �����������
	@param obj - ������ ������ Integer*/
	Integer(const Integer& obj);
	/*����� �����
	@param - ������ ������ Integer*/
	void sum(Integer& obj) ;
	/*����� ��������
	@param - ������ ������ Integer*/
	void dif(Integer& obj) ;
	/*����� ���������
	@param - ������ ������ Integer*/
	void mul(Integer& obj) ;
	/*����� �������
	@param - ������ ������ Integer*/
	void div(Integer& obj) ;
	/*����� ������ �� �����
	@param sout - ����� ostream
	@param integer - ������ ������ integer
	@return ����� ostream*/
	friend ostream& operator<<(ostream& sout, const Integer& integer);
	/*���������� */
	~Integer();
};
//toLL i toMas