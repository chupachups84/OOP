#include "Account.h"
void main() {
	
	string fam, accountNum;
	float procent,sum;
	cout << "1st account data: ";
	cin >> fam >> accountNum >> procent >> sum;
	Account a1(fam, accountNum, procent, sum);
	cout << a1.toString();
	cout << "new Name:";
	cin >> fam;
	a1.changeOwner(fam);
	cout << a1.toString()<<'\n';
	cout << "withdraw money from the account: ";
	cin >> sum;
	Money summa(sum);
	if (a1.GetMoney() - summa < 0)
		cout << "insufficient funds in the account\n";
	else
		a1.TakeFromAccount(sum);
	cout << a1.toString() << '\n';
	cout << "put money in account: ";
	cin >> sum;
	a1.PutInAccount(sum);
	cout<<a1.toString()<<'\n';
	cout << "plus " <<a1.GetProcent()<<" % "<<" :\n";
	a1.PlusProcent();
	cout << a1.toString() << '\n';
	Money Sum1 = a1.GetMoney();
	cout << "exchange balance in dollars: \n";
	a1.ExchangeToDollars();
	cout << a1.toString() << '\n';
	a1.SetMoney(Sum1);
	cout << "exchange balance in euros: \n";
	a1.ExchangeToEuros();
	cout << a1.toString() << '\n';
	a1.SetMoney(Sum1);

	


	
}