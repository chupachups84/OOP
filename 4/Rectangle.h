#include "Pair.h"
#include <string>
class Rectangle :public Pair {

public:
	/*���������� �� ��������� */
	Rectangle();
	/*����������� � �����������
	@param _x - 1 �������
	@param _y - 2 �������*/
	Rectangle(double _x, double _y);
	/*����� ������������ ������� ��������������
	@return ������� ��������������*/
	double S();
	/*����� ������������ �������� ��������������
	@return �������� ��������������*/
	double P();
};