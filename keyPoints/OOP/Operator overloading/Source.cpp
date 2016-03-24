// Operator overLoading

#include <iostream>
#include "time.h"
#include "fraction.h"

using namespace std;


int main()
{

	cout << "/* TIME */\n";
	time t1(4500);
	time t2(2, 35, 21);
	time t3;

	t3 = t1 + t2; //t3 = t1.operator+(t2);
	cout << "Time is: || " << t3 << " || \n";


	cout << "/* Vectors */\n";
	Vector v1(30, 50, Decart);
	Vector v2(6.56, 1.34, Polar);


	cout << "v1 + v2 = " <<  v1 + v2 << endl;
	cout << endl;

	cout << "/* Fractions */\n";
	fraction a(1, 0);
	fraction b(1, 6);
	cout << "=====================\na = " << a << ", b = " << b << endl;
	cout << "a+b = " << a + b << endl;
	cout << "a-b = " << a - b << endl;
	cout << "a*b = " << a * b << endl;
	cout << "a/b = " << a / b << endl;
	cout << "=====================\n";



	cout << endl;
	system("pause");
	return 0;
}