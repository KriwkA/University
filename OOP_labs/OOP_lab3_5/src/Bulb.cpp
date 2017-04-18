#include "Bulb.h"

Bulb::Bulb(std::string _title):liquor_("None",Water(0.0),Substance("None","None"))
{
	title_ = _title;
	liquorTitle_ = "None";
}

void Bulb::addLiquor(Liquor& liquor)
{
	liquorTitle_ = liquor.title_;
	liquor_ = liquor;
}

Liquor Bulb::getLiquor()
{
	if (liquorTitle_ == "None")
		abort();
	Liquor temp = liquor_;
	liquor_ = Liquor("None", Water(0.0), Substance("None", "None"));
	liquorTitle_ = "None";
	return temp;
}

void Bulb::printInfo() const
{
	if (liquor_.getLiquorTitle() == "None")
	{
		std::cout << title_ << " is empty." << std::endl;
		return;
	}
	std::cout.setf(std::ios::left);
	std::cout << std::setw(20) << "Luquor title: " << liquorTitle_ << std::endl;
	std::cout << std::setw(20) << "Water capacity: " << liquor_.Water::capacity_ << std::endl;
	std::cout << std::setw(20) << "Substance title: " << liquor_.Substance::title_ << std::endl;
	std::cout << std::setw(20) << "Substance type: " << liquor_.Substance::type_ << std::endl;
	std::cout << std::setw(20) << "Substance mass: " << liquor_.Substance::mass_ << std::endl;
}
