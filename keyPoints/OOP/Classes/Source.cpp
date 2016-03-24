// classes in cpp

#include <iostream>
#include <conio.h>
#include "Account.h"

using namespace App;

int main()
{

	Account a("Vlad", 7, 7777);
	Account b("Bob", 8, 999);

	std::cout << a.getName() << ", yours ID is " << a.getID() << " and you have " << a.getBalance() << " $ on account\n";
	std::cout << b.getName() << ", yours ID is " << b.getID() << " and you have " << b.getBalance() << " $ on account\n";

	std::cout << "\nUser with ID " << a.compareWith(b).getID() << " has more money on his account!\n";

	secondStack st;
	
	for (int i = 0; i < 20; i++)
	{
		st.Push(i);
	}

	for (int i = 0; !st.isEmpty() ; i++)
	{
		std::cout << st.Pop() << " -> ";
	}
	std::cout << "NULL" << std::endl;
	system("pause");
	return 0;
}