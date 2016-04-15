// inheritance and constructors
#include <iostream>

#include "SomeBox.h"
#include "ShippingOrder.h"

using namespace std;

int main()
{
	system("pause");


	SomeBox b(20, 30, 50);

	std::cout << b.Volume() << std::endl;

	SomeBox c = 2; // equals  to c(2) but this can give some errors
	std::cout << c.Volume();

	ShippingOrder so(20, 10.7);
	std::cout << so.getProduct().Volume();
	
	std::cout << std::endl;

	SomeBox boxes[3]{ {1,3,5} , {1,7,9}, {9,1,4} };
	for (int i = 0; i < 3; i++)
	{
		std::cout << boxes[i].Volume() << std::endl;
	}

	StorageBox sb(30, 777);

	std::cout << sb.Volume();

	system("pause");
	return 0;
}