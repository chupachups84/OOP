#include<iostream>
#include<math.h>
#include<string>

using namespace std;
class Money
{
    long rub;
    unsigned char kop;

public:
    /*Конструктор по умолчанию класса Money*/
    Money();
    //Конструктор класса Money 
    //@param sum - вещественное число ,сумма
    Money(float sum);
    /*Конструктов класса Money
    @param r - рубли
    @param k - копейки*/
    Money(long r, unsigned char k);
    /*Метод toString 
    @return строкa из данных полей класса Money*/
    string toString();
    /*Метод изменяющий значение поля rub
    @param Rubles - рубли*/
    void amountOfRubles(long Rubles);
    /*Метод изменяющий значение поля kop
    @param Kopeyka - копейки */
    void amountOfKopeyka(unsigned char Kopeyka);
    /*Метов возвращающий значение поля rub
    @return поле rub*/
    long getRub();
    /*Метов возвращающий значение поля kop
    @return поле kop*/
    char getKop();

    /*Оператор сложения 
    @param r - объект класса Money
    @return объект класса Money , после выполнения оператора*/
    Money operator +(Money r);
    /*Оператор вычетания
    @param r - объект класса Money
    @return объект класса Money , после выполнения оператора*/
    Money operator -(Money r);
    /*Оператор деления на целое число
    @param n - целое число , делитель 
    @return объект класса Money , после выполнения оператора*/
    Money operator /(int n);
    /*Оператор деления на вещественное число
    @param n - вещественное чилос,делитель
    @return объект класса Money , после выполнения оператора*/
    Money operator /(double n);
    /*Оператор умножения
    @param n - вещественное число, множитель
    @return объект класса Money , после выполнения оператора*/
    Money operator*(double n);

    /*Оператор сравнения ==
    @param r - объект класса Money 
    @return результат сравнения ==*/
    bool operator==(Money r);
    /*Оператор сравнения !=
    @param r - объект класса Money
    @return результат сравнения !=*/
    bool operator!=(Money r);
    /*Оператор сравнения >
    @param r - объект класса Money
    @return результат сравнения >*/
    bool operator>(Money r);
    /*Оператор сравнения <
    @param r - объект класса Money
    @return результат сравнения <*/
    bool operator<(Money r);
    /*Оператор сравнения >=
    @param r - объект класса Money
    @return результат сравнения >=*/
    bool operator>=(Money r);
    /*Оператор сравнения <=
    @param r - объект класса Money
    @return результат сравнения <=*/
    bool operator<= (Money r);
};