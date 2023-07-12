#include <iostream>
#include "Binary.h"
#include "Decimal.h"
using namespace std;
void main() {
	Integer* j = new Binary(58);
	Integer* p = new Binary(60);
	cout<< *j << endl;
	cout << *p << endl;
	j->dif(*p);
	cout << *j << endl;
	Integer* d = new Decimal(58);
	Integer* o = new Decimal(59);
	cout << *d << endl;
	cout << *o << endl;
	d->sum(*o);
	cout << *d << endl;
	d->sum(*j);
	cout << *d << endl;

	delete p;
	delete j;
	delete o;
	delete d;
}
