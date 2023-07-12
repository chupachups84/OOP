#include <iostream>
#include "List.h"
using namespace std;
int main() {
	List<double> list(2.5);
	List<double >::Iterator it=list.begin();
	for (int i = 0; i < 5; i++,++it) {
		list.insert(it, 2.5);
	}
	cout << list;
	cin >> list;
	cout << list;
	List<double> list2(7.0,5);
	cout << list2;
	List<double >::Iterator p(list2.begin());
	List<double >::Iterator t(list2.end());
	list.replacement(--(--list.end()),--list.end(), p, t);
	cout << list;
	List<double >::Iterator fElem =  list.find(1.5);
	List<double >::Iterator fGroup =  list.find(p,t);
	cout << "*fElem = " << *fElem << endl;
	cout << "*fGroup = " << *fGroup << endl;
	list2.erase(p, t);
	return 0;
}