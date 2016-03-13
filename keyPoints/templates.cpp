// Templates.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>

using namespace std;

template<typename t>
void Print(const t arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
}

template<typename T1>
void Swap(T1 &a, T1 &b)
{
	T1 temp = a;
	a = b;
	b = temp;
}


// sort for array of some type t;
template<typename t>
void Sort(t arr[], int size)
{
	//int min;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				Swap( arr[i], arr[j] );
			}
		}
	}
}

// arr - указатель
template<typename t>
auto findInArray(t arr[], int size, t search) -> decltype(arr)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == search)
			return (arr + i);
	}
	return NULL;
}


int main()
{

	int a = 1, b = 2;

	Swap(a, b);
	cout << "Swaped:\na: " << a << " b:" << b << endl;

	const int SIZE = 5;
	int arr[SIZE] = {3,2,5,7,1};

	Sort(arr, SIZE);
	cout << endl << "Your sorted set: ";
	Print(arr, SIZE);

	cout << endl;
	int *foundedInArray = findInArray(arr, SIZE, 7);

	if (foundedInArray != NULL)
		cout << "foundedInArray: " << foundedInArray;
	else
		cout << "No such element in your set!";

	cout << endl;
	//system("pause");
  return 0;
}
