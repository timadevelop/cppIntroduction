#pragma once
#include <iostream>

namespace App
{
	typedef unsigned int ui;

	class Account
	{
		private:
			char *name;
			int ID;
			const int maxBalance = 100000;
			ui balance;
		public:
			Account(); // constructor
			~Account(); // destructor
			Account(char *newName, int newID = 0, ui newBalance = 0);
			void setName(char*);
			char* getName() const;
			void setID(int);
			int getID() const;
			void setBalance(ui);
			int getBalance() const;
			void addMoney(ui);
			void takeMoney(ui);
			Account compareWith(const Account&) const;

	};

	class firstStack
	{
	private:
		int* arr;
		int MAX;
		int index;
	public:
		firstStack(int n)
		{
			MAX = 1000;
			index = 0;
			if (n <= MAX)
			{
				arr = new int[n];
				MAX = n;
			}
			else std::cout << "Stack overflow!";
		}
		~firstStack()
		{
			delete[] arr;
		}

		bool push(int n)
		{
			if (index == MAX)
				return false;
			else
				arr[index++] = n;
		}

		int pop()
		{
			if (index < 0)
				return -1;
			else
				return arr[--index];
		}

		bool isEmpty()
		{
			if (index <= 0)
				return true;
			return false;
		}

		bool isFull()
		{
			if (index == MAX)
				return true;
			return false;
		}

	};

	class stackElement
	{
	private:
		int key;
		stackElement *deeper;
	public:
		stackElement()
		{
			key = NULL;
			deeper = NULL;
		}
		
		void setDeeper(stackElement *d)
		{
			deeper = d;
		}

		stackElement* getDeeper() const
		{
			return deeper;
		}

		void setValue(int value)
		{
			key = value;
		}
		int getValue() const
		{
			return key;
		}
	};


	class secondStack
	{
	private:
		stackElement *top = NULL;
	public:
		void Push(int n)
		{
			stackElement *temp = new stackElement;
			temp->setValue(n);
			temp->setDeeper(top);
			top = temp;
		}

		int Pop()
		{
			int deletedInteger = top->getValue();
			stackElement *temp = top;
			top = top->getDeeper();
			delete temp;
			return deletedInteger;
		}

		bool isEmpty()
		{
			return !top;
		}
	};

}