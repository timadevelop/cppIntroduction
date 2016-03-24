#include "time.h"



time::time()
{
	hours = minutes = seconds = 0;
}

time::time(ui sec)
{
	hours = sec / (60 * 60);
	minutes = sec % (60 * 60) / 60;
	seconds = sec % (60 * 60) % 60;
}

time::time(ui h, ui m, ui s)
{
	if (h > 24 || m > 60 || s > 60)
	{
		time::time();
		return;
	}

	hours = h;
	minutes = m;
	seconds = s;
}


time time::operator+(const time& t) const
{
	time result;
	result.hours = (hours + t.hours + (minutes + t.minutes) / 60);
	result.minutes = (minutes + t.minutes + (seconds + t.seconds)/60)%60;
	result.seconds = (seconds + t.seconds)%60;

	return result;
}


std::ostream& operator<<(std::ostream &os, const time& t1)
{
	os << t1.hours << " : " << t1.minutes << " : " << t1.seconds;
	return os;
}

time::~time()
{
}
