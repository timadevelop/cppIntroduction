#include "Figure.h"
#include <iostream>


Figure::Figure()
{
	points = NULL;
	lengths = NULL;
}

Figure::Figure(int p[], int l[])
{

}


Figure::~Figure()
{
	delete[] points;
	delete[] lengths;
}
