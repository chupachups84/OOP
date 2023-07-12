#include <string>
class Pair {
protected:
	double x;
	double y;
public:
	/*���������� �� ��������� */
	Pair();
	/*����������� � �����������
	@param _x - 1 �����
	@param _y - 2 �����*/
	Pair(double _x, double _y);
	/*�����  ���������� ���� x
	@param _x - ����� �������� ���� x*/
	void setX(double _x);
	/*�����  ���������� ���� �
	@param _� - ����� �������� ���� �*/
	void setY(double _y);
	/*����� ������������ ���� x
	@return �������� ���� x*/
	double getX();
	/*����� ������������ ���� y
	@return �������� ���� y*/
	double getY();
	/*����� ������������ �����
	@return ������������ x � y*/
	double compozition();
	/*����� toString
	@return ������ �������� �����*/
	std::string toString();
};