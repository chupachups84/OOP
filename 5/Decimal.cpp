#include "Decimal.h"

long long Decimal::toLL()
{
	long long s1=0;
	int power = 0;
	for (int i = size - 1; i > 0; i--) {
		s1 += static_cast<long long>(pow(10, power)) * num[i];
		power++;
	}
	if (num[0] < 0) {
		s1 += (-1)*static_cast<long long>(pow(10, power)) * num[0] ;
		s1 *= (-1);
	}
	else {
		s1 += static_cast<long long>(pow(10, power)) * num[0];
	}
	return s1;
}

void Decimal::toArray(int n){
	size = 0;
	if (n < 0) {
		n *= (-1);
		int n1 = n;
		while (n != 0) {
				size += 1;
				n /= 10;
			}
			if (num != nullptr) {
				delete []num;
			}
			num = new int[size];
			for (int i = size - 1; i >= 0; i--) {
				num[i] = n1 % 10;
				n1 /= 10;
			}
			num[0] *= (-1);
	}
	else if (n > 0) {
		int n1 = n;
		while (n != 0) {
			size += 1;
			n /= 10;
		}
		if (num != nullptr) {
			delete []num;
		}
		num = new int[size];
		for (int i = size - 1; i >= 0; i--) {
			num[i] = n1 % 10;
			n1 /= 10;
		}
	}
	else {
		size = 1;
		if (num != nullptr) {
			delete []num;
		}
		num = new int[size];
		num[0] = 0;
	}
}

Decimal::Decimal() {
	toArray(0);
}

Decimal::Decimal(int n) {
	toArray(n);
}






