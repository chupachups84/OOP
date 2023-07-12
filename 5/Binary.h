#pragma once
#include "Integer.h"
class Binary :public Integer {
protected:
	/*���������� ������ toLL ��� ������ Binary
	@return  s1 - long long ����� � ���������� ������� ���������*/
	long long toLL();
	/*���������� ������ toArray ��� ������ Binary
	@param n - ����� ����� */
	void toArray(int n);
public:
	/*����������� �� ���������*/
	Binary();
	/*����������� � �����������
	@param n - ���������� ����� �����*/
	Binary(int n);
};