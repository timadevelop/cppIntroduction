#include "fraction.h"


fraction::fraction(int n = 1, int d = 1)
{
	if (d == 0) d = 1;
	numerator = n;
	denominator = d;
	reduce();
}



void fraction::reduce()
{
	int tmp = gcd(numerator, denominator);
	numerator /= tmp;
	denominator /= tmp;
}

int fraction::getNumerator() const
{
	return numerator;
}
int fraction::getDenominator() const
{
	return denominator;
}


// basic arithmetic

fraction fraction::operator*(const fraction &b) const
{
	return fraction(numerator*b.getNumerator(), denominator*b.getDenominator());
}

fraction fraction::operator/(const fraction &b) const
{
	fraction result(numerator*b.getDenominator(), denominator*b.getNumerator());
	result.reduce();
	return result;
}

fraction fraction::operator+(const fraction &b) const
{
	int commonDen = lcm(denominator, b.denominator);
	int num = numerator*(commonDen/denominator) + b.numerator*(commonDen/b.denominator);
	return fraction(num, commonDen);
}

fraction fraction::operator-(const fraction &b) const
{
	int commonDen = lcm(denominator, b.denominator);
	int num = numerator*(commonDen / denominator) - b.numerator*(commonDen / b.denominator);
	return fraction(num, commonDen);
}


std::ostream& operator<<(std::ostream &os, const fraction &a)
{
	if (a.getDenominator() == 1)
	{
		os << a.getNumerator();
	}
	else
	{
		os << a.getNumerator() << "/" << a.getDenominator();
	}
	return os;
}


fraction::~fraction()
{
}
