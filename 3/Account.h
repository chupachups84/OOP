#pragma once
#include "Money.h"
#include <iostream>
#include <string>;
using namespace std;
class Account {
private:
	string fam; //�������
	string accountNum; //����� �����
	float procent; //�������
	Money money; //������ ������ Money
public:
	/*����������� ������ Account �� ���������
	@return ������ ������ Account
	*/
	Account();
	/*����������� ������ Account
	@param _fam - �������, ������� �� �����������
	@param _chet - ����� �����, ������� �� ����� �����������
	@param _procent - �������, ������� �� ����� �����������
	@param _sum - �����, � ������� ������� �� ����� �������� ����������� Money
	@return ������ ������ Account
	*/
	Account(string _fam, string _accountNum, float _procent, float _sum);
	/*������� ��������� �������� ���� money
	@return ���� money*/
	Money GetMoney();
	/*������� ��������� ���� procent
	@return ���� procent*/
	float GetProcent();
	/*������� ��������� ���� accountNum
	@return ���� accountNum*/
	string GetAccountNum();
	/*������� ��������� ���� fam
	@return ���� fam*/
	string GetFam();

	/*������� ��������� ���� money
	@param k - ����� �����*/
	void SetMoney(Money k);
	/*������� ��������� ���� procent
	@param p - ����� �������*/
	void SetProcent(float p);
	/*������� ��������� ���� accountNum
	@param acNum - ����� ����� �����*/
	void SetAccountNum(string acNum);
	/*������� ��� ��������� ������� ���������
	@param _fam - ����� ������� ���������*/
	void changeOwner(string _fam);
	/*������� ������ ����� � �������
	@param sum1 - ����� ��� ������ */
	void TakeFromAccount(float sum1);
	/*������� ���������� ������� 
	@param sum1 - ����� ����������*/
	void PutInAccount(float sum1);
	/*������� ���������� ��������*/
	void PlusProcent();
	/*������� �������� ����� � �������*/
	void ExchangeToDollars();
	/*������� �������� ����� � ����*/
	void ExchangeToEuros();
	/*������� ��������� ������ �� �������� 
	@return ������ ������ */
	string toString();
};