#include "Money.h"
Money::Money()
{
    rub = 0;
    kop = 0;
}
Money::Money(long r, unsigned char k) {
    rub = r;
    kop = k;
}
Money::Money(float sum) {
    int s = sum * 100;
    rub = s / 100;
    kop = s - rub * 100;
}
string Money::toString()
{
    string str;
    str += to_string(rub) + ',';
    str += to_string(kop) + "\n";
    return str;
}
void Money::amountOfRubles(long Rubles)
{
    rub = Rubles;
};
void Money::amountOfKopeyka(unsigned char Kopeyka)
{
    kop = Kopeyka;
}
long Money::getRub() {
    return rub;
}
char Money::getKop() {
    return kop;
}
Money Money::operator+(Money r)
{
    Money temp;
    temp.rub = rub + r.rub;
    temp.kop = kop + r.kop;
    if (temp.kop >= 100)
    {
        temp.rub += 1;
        temp.kop -= 100;
    }
    return temp;
}
Money Money::operator-(Money r)
{
    Money temp1;
    int n;
    temp1.rub = rub - r.rub;
    n = kop - r.kop;
    if (n < 0)
    {
        n*= -1;
        temp1.rub -= 1;
        temp1.kop = n;
    }
    return temp1;
}
Money Money::operator / (int n)
{
    Money temp;
    int r100 ,m,div,k;
    r100 = rub * 100;
    m = r100 + kop ;
    div =  m / n;
    temp.rub = div / 100;
    temp.kop = div - temp.rub * 100;
    return temp;
}
Money Money::operator/(double n)
{
    Money temp;
    int r100, m,div,k;
    r100 = rub * 100;
    m = kop + r100;
    div = m / n;
    temp.rub = div / 100;
    temp.kop = div - temp.rub * 100;
    return temp;
}
Money Money::operator *(double n)
{
    Money temp;
    int r100, m, mult,k;
    r100 = rub * 100;
    m = kop + r100;
    mult = m * n;
    temp.rub = mult / 100;
    temp.kop = mult - temp.rub * 100;
    return temp;
}

bool Money::operator==(Money r) {
    return (rub == r.rub && kop == r.kop);
}
bool Money::operator!=(Money r) {
    int tmp1 = rub * 100 + kop-'0';
    int tmp2 = r.rub * 100 + kop - '0';
    return (tmp1 != tmp2);
}
bool Money::operator>(Money r) {
    int tmp1 = rub * 100 + kop - '0';
    int tmp2 = r.rub * 100 + kop - '0';
    return (tmp1 > tmp2);
}
bool Money::operator<(Money r) {
    int tmp1 = rub * 100 + kop - '0';
    int tmp2 = r.rub * 100 + kop - '0';
    return tmp1 < tmp2;
}
bool Money::operator>=(Money r) {
    int tmp1 = rub * 100 + kop - '0';
    int tmp2 = r.rub * 100 + kop - '0';
    return tmp1 >= tmp2;
}
bool Money::operator<= (Money r) {
    int tmp1 = rub * 100 + kop - '0';
    int tmp2 = r.rub * 100 + kop - '0';
    return tmp1 <= tmp2;
}