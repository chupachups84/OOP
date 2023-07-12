#pragma once
#include "Integer.h"
class Decimal :public Integer {
protected:
	/*���������� ������ toLL ��� ������ Decimal
	@return  s1 - long long ����� � ���������� ������� ���������*/
	long long toLL();
	/*���������� ������ toArray ��� ������ Decimal
	@param n - ����� ����� */
	void toArray(int n);
public:
	/*����������� �� ���������*/
	Decimal();
	/*����������� � �����������
	@param n - ���������� ����� �����*/
	Decimal(int n);
};