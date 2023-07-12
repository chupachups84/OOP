#include "Account.h"
Account::Account() {
	fam = "";
	accountNum = "";
	procent = 0;
	money=Money();
}
Account::Account(string _fam, string _accountNum, float _procent, float _sum) {
	fam = _fam;
	accountNum=_accountNum;
	procent = _procent;
	money = Money(_sum);
}
Money Account::GetMoney() {
	return money;
}
void Account::SetMoney(Money k) {
	money = k;
}
void Account::changeOwner(string _fam) {
	fam = _fam;
}
void Account::TakeFromAccount(float sum1) {
	money = money - Money(sum1);
}
void Account::PutInAccount(float sum1) {
	money = money + Money(sum1);
}
void Account::PlusProcent() {
	money = money + (money * procent)/100;
	procent = 0;
}
void Account::ExchangeToDollars() {
	money = money / 61.65;
}
void Account::ExchangeToEuros() {
	money = money / 60.45;
}
string Account::toString() {
	string result = "";
	result = "\nName : " + fam + ";\nAccount Number: " + accountNum + ";\nProcent: " + to_string(procent) + ";\nBalance: " + money.toString()+'\n';
	return result;
}
float Account::GetProcent() {
	return procent;
}
string Account::GetAccountNum() {
	return accountNum;
}
string Account::GetFam() {
	return fam;
}
void Account::SetProcent(float p) {
	procent = p;
}
void Account::SetAccountNum(string acNum) {
	accountNum = acNum;
}
