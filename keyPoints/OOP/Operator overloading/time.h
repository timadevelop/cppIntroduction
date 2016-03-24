#pragma once
#include <iostream>
typedef unsigned int ui;

class time
{
private:
	ui seconds;
	ui minutes;
	ui hours;
public:
	time();
	time(ui);
	time(ui, ui, ui);

	// operation overload
	time operator+(const time&) const;
	friend std::ostream& operator<<(std::ostream &os, const time& t1);

	~time();
};

enum vec{Decart, Polar};

class Vector
{
private:
	double x;
	double y;
	double angle;
	double radicalDistance;
	void polar_to_decart()
	{
		x = cos(angle)*radicalDistance;
		y = sin(angle)*radicalDistance;
	}
	void decart_to_polar()
	{
		angle = atan2(x, y);
		radicalDistance = sqrt(x*x + y*y);
	}
	vec Mode;
public:
	Vector()
	{
		Mode = Decart;
		x = 0;
		y = 0;
		decart_to_polar();
	}
	Vector(double a, double b, vec mode = Decart)
	{
		if (mode == Decart)
		{
			Mode = mode;
			x = a;
			y = b;
			decart_to_polar();
		}
		else {
			Mode = mode;
			radicalDistance = a;
			angle = b;
			polar_to_decart();
		}
	}
	
	void ChangeMode(vec mode)
	{
		Mode = mode;
	}

	// Vector module
	double operator+()
	{
		return radicalDistance;
	}

	Vector operator+(const Vector& v) const
	{
		Vector result;
		result.x = x + v.x;
		result.y = y + v.y;
		result.decart_to_polar();
		return result;
	}

	Vector operator-() const
	{
		return Vector(-x, -y, Decart);
	}

	// vec * C
	Vector operator*(double a) const
	{
		return Vector(x*a, y*a);
	}

	// C * vec
	friend Vector operator*(double a, const Vector& v)
	{
		return v*a;
	}

	friend std::ostream& operator<<(std::ostream &os, const Vector& v)
	{
		if (v.Mode == Decart)
			os << "x: " << v.x << ", y: " << v.y;
		else
			os << "Angle: " << v.angle*(180/3.14) << ", Radical distance: " << v.radicalDistance;
		return os;
	}

};