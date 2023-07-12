#include<iostream>
#include<math.h>
#include<string>

using namespace std;
class Money
{
    long rub;
    unsigned char kop;

public:
    /*����������� �� ��������� ������ Money*/
    Money();
    //����������� ������ Money 
    //@param sum - ������������ ����� ,�����
    Money(float sum);
    /*����������� ������ Money
    @param r - �����
    @param k - �������*/
    Money(long r, unsigned char k);
    /*����� toString 
    @return �����a �� ������ ����� ������ Money*/
    string toString();
    /*����� ���������� �������� ���� rub
    @param Rubles - �����*/
    void amountOfRubles(long Rubles);
    /*����� ���������� �������� ���� kop
    @param Kopeyka - ������� */
    void amountOfKopeyka(unsigned char Kopeyka);
    /*����� ������������ �������� ���� rub
    @return ���� rub*/
    long getRub();
    /*����� ������������ �������� ���� kop
    @return ���� kop*/
    char getKop();

    /*�������� �������� 
    @param r - ������ ������ Money
    @return ������ ������ Money , ����� ���������� ���������*/
    Money operator +(Money r);
    /*�������� ���������
    @param r - ������ ������ Money
    @return ������ ������ Money , ����� ���������� ���������*/
    Money operator -(Money r);
    /*�������� ������� �� ����� �����
    @param n - ����� ����� , �������� 
    @return ������ ������ Money , ����� ���������� ���������*/
    Money operator /(int n);
    /*�������� ������� �� ������������ �����
    @param n - ������������ �����,��������
    @return ������ ������ Money , ����� ���������� ���������*/
    Money operator /(double n);
    /*�������� ���������
    @param n - ������������ �����, ���������
    @return ������ ������ Money , ����� ���������� ���������*/
    Money operator*(double n);

    /*�������� ��������� ==
    @param r - ������ ������ Money 
    @return ��������� ��������� ==*/
    bool operator==(Money r);
    /*�������� ��������� !=
    @param r - ������ ������ Money
    @return ��������� ��������� !=*/
    bool operator!=(Money r);
    /*�������� ��������� >
    @param r - ������ ������ Money
    @return ��������� ��������� >*/
    bool operator>(Money r);
    /*�������� ��������� <
    @param r - ������ ������ Money
    @return ��������� ��������� <*/
    bool operator<(Money r);
    /*�������� ��������� >=
    @param r - ������ ������ Money
    @return ��������� ��������� >=*/
    bool operator>=(Money r);
    /*�������� ��������� <=
    @param r - ������ ������ Money
    @return ��������� ��������� <=*/
    bool operator<= (Money r);
};