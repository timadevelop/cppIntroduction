//#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>

using namespace std;

void Recurs(int level)
{
	if (level == 0)
		return;

	cout << "Recurse function with argument " << level << endl;
	Recurs(level-1);
	cout << "UpWard! argument: " << level << endl;
}

void MiddleMyString(char *str, int left, int right, int level)
{
	if (level == 0) return;

	int middle = ( left + right ) / 2;
	str[middle] = '|';
	MiddleMyString(str, left, middle, level-1); // left
	MiddleMyString(str, middle, right, level - 1); // right
}

void ExampleWithString()
{
	char str[65];
	str[64] = '\0';

	int min = 0, max = 63;
	str[min] = str[max] = '|';

	for (int i = min + 1; i < max; i++)
	{
		str[i] = ' ';
	}

	cout << str << endl;

	for (int i = 1; i < 7; i++)
	{
		MiddleMyString(str, min, max, i);
		cout << str << endl;
	}
}

template<typename t>
void quickSort(t arr[], int left, int right)
{
	int i = left, j = right;
	int middle = arr[(i + j) / 2];

	do {
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++; j--;
		}

	} while (i < j);

	if (i < right) quickSort(arr, i, right);
	if (j > left) quickSort(arr, left, j);
}

int main()
{
	//Recurs(5);
	//ExampleWithString();

	srand(time(NULL));

	int n = 1000000;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	double t1 = clock();
	quickSort(arr, 0, n - 1);
	double t2 = clock() - t1;

	cout << t2 / CLOCKS_PER_SEC;

	delete[] arr;

	cout << endl;

	//system("pause");
    return 0;
}
