#include "Time.h"
#include <cstdlib>

Time::Time()
{

}

Time::Time(const int second)
{
	second_ = second % 60;
	minute_ = second / 60 % 24;
	hour_ = second / 3600;
}

Time::Time(const unsigned short int hour,
	const unsigned short int minute,
	const unsigned short int second)
{
	second_ = second;
	minute_ = minute;
	hour_ = hour;
}

unsigned short int Time::getHour() const
{
	return hour_;
}

unsigned short int Time::getMinute() const
{
	return minute_;
}

unsigned short int Time::getSecond() const
{
	return second_;
}

unsigned int Time::getTimeInSec() const
{
	return hour_ * 3600 + minute_ * 60 + second_;
}

void Time::setHour(unsigned short int hour)
{
	hour_ = hour;
}

void Time::setMinute(unsigned short int minute)
{
	minute_ = minute;
}

void Time::setSecond(unsigned short int second)
{
	second_ = second;
}

void Time::random()
{
	hour_ = rand() % 24;
	minute_ = rand() % 60;
	second_ = rand() % 60;
}

bool operator<(const Time t1, const Time t2)
{
	return t1.getTimeInSec() < t2.getTimeInSec();
}

bool operator>(const Time t1, const Time t2)
{
	return t1.getTimeInSec() > t2.getTimeInSec();
}

bool operator==(const Time t1, const Time t2)
{
	return t1.getTimeInSec() == t2.getTimeInSec();
}