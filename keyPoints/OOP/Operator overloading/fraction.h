#pragma once
#include <iostream>
class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction(int, int);

	void reduce(); //


	int getNumerator() const;
	int getDenominator() const;

	fraction operator*(const fraction &b) const;
	fraction operator/(const fraction &b) const;
	fraction operator+(const fraction &b) const;
	fraction operator-(const fraction &b) const;

	friend std::ostream& operator<<(std::ostream&, const fraction&);
	
	~fraction();
};

