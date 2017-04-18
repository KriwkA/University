#include "Liquor.h"

Liquor::Liquor()
{
	title_ = "None";
}

Liquor::Liquor(const std::string& _liquorTitle, Water& _water,
	Substance& _substance):Water(_water), 
	Substance(_substance)
{
	title_ = _liquorTitle;
}

void Liquor::addLiquor(Liquor& _liquor)
{
	if (_liquor.title_ != title_)
		abort();
	this->addWater(_liquor.getWater());
	this->addSubstance(_liquor.getSubstance());
}

Liquor Liquor::getLiquor()
{
	if (title_ == "None")
		abort();
	Liquor temp = (*this);
	this->getWater();
	this->getSubstance();
	return temp;
}

std::string Liquor::getLiquorTitle() const
{
	return title_;
}
