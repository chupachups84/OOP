#pragma once
#include "Money.h"
#include <iostream>
#include <string>;
using namespace std;
class Account {
private:
	string fam; //Фамилия
	string accountNum; //Номер счета
	float procent; //Процент
	Money money; //Объект класса Money
public:
	/*Конструктор класса Account по умолчанию
	@return объект класса Account
	*/
	Account();
	/*Конструктор класса Account
	@param _fam - фамилия, которую мы присваиваем
	@param _chet - номер счета, который мы будем присваивать
	@param _procent - процент, который мы будем присваивать
	@param _sum - сумма, с помощью которой мы будем вызывать конструктор Money
	@return объект класса Account
	*/
	Account(string _fam, string _accountNum, float _procent, float _sum);
	/*Функция получения значения поля money
	@return поле money*/
	Money GetMoney();
	/*Функция получения поля procent
	@return поле procent*/
	float GetProcent();
	/*Функция получения поля accountNum
	@return поле accountNum*/
	string GetAccountNum();
	/*Функция получения поля fam
	@return поле fam*/
	string GetFam();

	/*Функция изменения поля money
	@param k - новая сумма*/
	void SetMoney(Money k);
	/*Функция изменения поля procent
	@param p - новый процент*/
	void SetProcent(float p);
	/*Функция изменения поля accountNum
	@param acNum - новый номер счета*/
	void SetAccountNum(string acNum);
	/*Функция для изменения фамилии владельца
	@param _fam - новая фамилия владельца*/
	void changeOwner(string _fam);
	/*Функция снятия суммы с баланса
	@param sum1 - сумма для снятия */
	void TakeFromAccount(float sum1);
	/*Функция пополнения баланса 
	@param sum1 - сумма пополнения*/
	void PutInAccount(float sum1);
	/*Функция начисления процента*/
	void PlusProcent();
	/*Функция перевода суммы в доллары*/
	void ExchangeToDollars();
	/*Функция перевода суммы в евро*/
	void ExchangeToEuros();
	/*Функция получения данных из аккаунта 
	@return строка данных */
	string toString();
};