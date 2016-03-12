// stack with Linked lists

//#include "stdafx.h"
#include <iostream>

using namespace std;

struct Stack
{
	int key;
	Stack *next;
};

void printMyStack(Stack *begin)
{
	Stack *temp = begin;

	while (temp)
	{
		cout << "| " << temp->key << " |\n";
		temp = temp->next;
	}
}

void push(Stack **begin, int el)
{
	Stack *temp = new Stack;
	temp->key = el;
	temp->next = *begin; // saving current last element of stack
	*begin = temp;
}

int pop(Stack **begin)
{
	int deletedInteger = (*begin)->key;
	Stack *temp = *begin;
	*begin = (*begin)->next;
	delete temp;
	return deletedInteger;
}

int main()
{

	Stack *begin = NULL;
	printMyStack(begin);

	for (int i = 1; i < 10; i++)
	{
		push(&begin, i * 10);
	}
	cout << "Default stack:\n";
	printMyStack(begin);

	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "deleted " << pop(&begin) << " from stack" << endl;
	}

	cout << "\nResult stack:\n";
	printMyStack(begin);
  //system("pause");

	return 0;
}
