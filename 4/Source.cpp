#include "Rectangle.h"
#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	cout << "������� 2 ������� ��������������: " << endl;
	double a, b;
	cin >> a>> b;
	Rectangle r(a, b);
	cout << "������� ����� " << r.S() << endl;
	cout << "�������� ����� " << r.P() << endl;
}