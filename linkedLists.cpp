// linked list (Односвязный список).

//#include "stdafx.h"
#include <iostream>

using namespace std;

struct A
{
	int key;
};

struct List
{
	A a;
	List* next;
};

void printMyList(List *b)
{
	List *print = b; // first element;

	while (print)
	{
		cout << print->a.key << " -> ";
		print = print->next;
	}
	cout << "NULL\n";
}
void initMyList(List **begin) // begin will change;
{
	*begin = new List;
	A a[5] = { 43,56,78,100,511 };


	(*begin)->a.key = 20;
	(*begin)->next = NULL; // [ 20 | -]--> Null

	List* end = *begin;

	// adding elements in a List;
	for (int i = 0; i < 5; i++)
	{
		end->next = new List; // [ 20 | -]--> [|]
		end = end->next;
		end->a = a[i];
		end->next = NULL;
	}
}
void addToBegin(List **begin,const A &a)
{
	List *t = new List;
	t->a = a;
	t->next = *begin;
	*begin = t;
}
void addToEnd(List **begin, const A &a)
{
	List *temp = new List;
	temp->a = a;
	temp->next = NULL;

	List *s = *begin;
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = temp;
}
// inserting to List by sort
void insertToList(List **begin, const A &a) {
	List *ins = new List;
	ins->a = a;

	if (!*begin) // *begin == NULL
	{
		ins->next = NULL;
		*begin = ins;
		return;
	}

	List *temp = *begin;
	if (ins->a.key <= temp->a.key) {
		ins->next = temp;
		*begin = ins;
		return;
	}

	while (temp->next && ins->a.key > temp->next->a.key)
	{
		temp = temp->next;
	};

	ins->next = temp->next;
	temp->next = ins;
}
void deleteFromList(List **begin, const A &a)
{
	if (*begin == NULL)
		return;

	List *temp = *begin;
	if (temp->a.key == a.key) {
		*begin = temp->next;
		delete temp;
		return;
	}

	List *prev = temp->next;
	while (temp->a.key != a.key)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	delete temp;
}
void clearMemory(List **begin)
{
	if (!*begin) return;

	List *temp = *begin, *prev;

	while (temp)
	{
		prev = temp;
		temp = temp->next;
		delete prev;
	}
	*begin = NULL;
}

int main()
{

	List* begin = NULL;
	initMyList(&begin); // will change begin
	printMyList(begin); // begin will not change

	A a = { -12 },
		b = { 700 },
		forInsert = { 800 },
		forDelete = { 100 };

	addToBegin(&begin, a);
	printMyList(begin);

	addToEnd(&begin, b);
	printMyList(begin);

	cout << endl;

	insertToList(&begin, forInsert);
	printMyList(begin);

	deleteFromList(&begin, forDelete);
	printMyList(begin);

	clearMemory(&begin);
	printMyList(begin);

	//system("pause");
	return 0;
}
