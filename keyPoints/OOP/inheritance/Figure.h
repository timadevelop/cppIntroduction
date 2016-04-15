#pragma once
class Figure
{
private:
	int *points;
	int *lengths;
public:
	Figure();
	Figure(int*, int*);
	~Figure();
};

