#include "Account.h"

namespace App
{
	typedef unsigned int ui;
	Account::Account()
	{
		name = "";
		balance = 0;
		ID = 0;
	}

	Account::Account(char *newName, int newID, ui newBalance) {
		name = newName;
		ID = newID;
		if(newBalance < maxBalance)
			balance = newBalance;
	}

	void Account::setName(char* newName)
	{
		name = newName;
	}

	char* Account::getName() const
	{
		return name;
	}
	
	void Account::setID(int newID)
	{
		ID = newID;
	}

	int Account::getID() const
	{
		return ID;
	}
	
	void Account::setBalance(ui newBalance)
	{
		if(newBalance < maxBalance)
			balance = newBalance;
	}

	int Account::getBalance() const
	{
		return balance;
	}

	void Account::addMoney(ui amount)
	{
		if (amount + balance <= maxBalance)
			balance += amount;
	}

	void Account::takeMoney(ui amount)
	{
		if (amount <= balance)
			balance -= amount;
	}

	Account Account::compareWith(const Account &another) const
	{
		if (another.getBalance() > balance)
			return another;
		else return *this;
	}

	Account::~Account()
	{

	}
}