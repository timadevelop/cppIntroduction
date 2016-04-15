#pragma once
#include <iostream>
class fraction
{
private:
	int numerator;
	int denominator;
	int gcd(int a, int b) const
	{
		if (a == b) return a;
		while (a != 0 && b != 0)
		{
			if (a > b) a = a%b;
			else if (b > a) b = b%a;
		}
		return a + b;
	}
	int lcm(int a, int b) const
	{
		return a / gcd(a, b) *b;
	}
	void reduce();
public:
	fraction(int, int);


	int getNumerator() const;
	int getDenominator() const;

	fraction operator*(const fraction &b) const;
	fraction operator/(const fraction &b) const;
	fraction operator+(const fraction &b) const;
	fraction operator-(const fraction &b) const;

	friend std::ostream& operator<<(std::ostream&, const fraction&);
	
	~fraction();
};

