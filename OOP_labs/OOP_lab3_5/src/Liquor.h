#pragma once
#ifndef _LIQUOR_
#define _LIQUOR_
#include <string>
#include "Water.h"
#include "Substance.h"

class Liquor : public Water, public Substance
{
private:
	std::string title_;
public:
	friend class Bulb;
	Liquor();
	Liquor(const std::string& _liquorTitle, Water& _water, Substance& _substance);
	void addLiquor(Liquor& _liquor);
	Liquor getLiquor();
	std::string getLiquorTitle() const;
};

#endif