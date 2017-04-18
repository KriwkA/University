#pragma once

class Time
{
private:
	unsigned short int hour_;
	unsigned short int minute_;
	unsigned short int second_;
public:
	Time();
	Time(const int);
	Time(const unsigned short int, const unsigned short int,
		 const unsigned short int);
	unsigned short int getHour() const;
	unsigned short int getMinute() const;
	unsigned short int getSecond() const;
	unsigned int getTimeInSec() const;
	void setHour(const unsigned short int);
	void setMinute(const unsigned short int);
	void setSecond(const unsigned short int);
	void random();
	friend bool operator<(const Time, const Time);
	friend bool operator>(const Time, const Time);
	friend bool operator==(const Time, const Time);
};


