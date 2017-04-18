#pragma once
#ifndef _BULB_
#define _BULB_
#include <iostream>
#include <iomanip>
#include "Liquor.h"
class Bulb
{
private:
	std::string title_;
	std::string liquorTitle_;
	Liquor liquor_;
public:
	Bulb(std::string _title);
	void addLiquor(Liquor& liquor);
	Liquor getLiquor();
	void printInfo() const;
};

#endif
