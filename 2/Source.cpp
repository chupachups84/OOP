#include "TIME.h"
#include <iostream>
int main() {
	setlocale(LC_ALL, "rus");
	int h1, m1, s1,h2,m2,s2;
	cout<<"¬ведите врем€(ч. ,мин. , сек.):\n";
	cout<<"t1: ";
	cin >> h1 >> m1>>s1 ;
	cout<<"t2: ";
	cin>>h2>>m2>>s2;
	if (h1>=24 ||m1>=60  ||s1>=60 ||h2>=24  ||m2>=60  ||s2>=60||
		h1 < 0 || m1 < 0 || s1 < 0|| h2 < 0 || m2 < 0 || s2 < 0 )
		cout<<"ќшибка ввода: выход за пределы(0 <= ч. < 24, 0 <= сек.< 60, 0 <= мин. < 60 )\n";
	else {
		Time t1(h1, m1, s1);
		Time t2(h2, m2, s2);
		/*Time t1(12, 53, 2);
		Time t2(15, 20, 59);*/
		cout << "t1: " << t1.toString();
		cout << "t2: " << t2.toString();
		Time c = t1 + t2;
		cout << "t1+t2: " << c.toString();
		Time d = t2 - t1;
		cout <<"t2-t1: " << d.toString();
		Time a = t1 + 3600;
		cout <<"t1+3600 сек.: " << a.toString();
		Time b = t1 - 3600;
		cout <<"t1-3600 сек.: " << b.toString();
		t1 += t2;
		cout<<"t1+=t2: " << t1.toString();
		t1 -= t2;
		cout << "t1-=t2: " << t1.toString();
		t1 -= 3600;
		cout << "t1-=3600: " << t1.toString();
		t1 += 3600;
		cout << "t1+=3600: " << t1.toString();
	}


}