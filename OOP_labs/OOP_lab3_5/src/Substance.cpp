#include "Substance.h"

Substance::Substance()
{
	mass_ = 0.0;
	title_ = "None";
	type_ = "None";
}

Substance::Substance(const std::string & _title, const std::string _type)
{
	mass_ = 0.0;
	title_ = _title;
	type_ = _type;
}

Substance::Substance(const double & _mass, const std::string & _title, const std::string _type)
{
	mass_ = _mass;
	title_ = _title;
	type_ = _type;
}

Substance::Substance(Substance & sub)
{
	title_ = sub.title_;
	type_ = sub.type_;
	mass_ = sub.mass_;
	sub = Substance();
}

void Substance::addSubstance(Substance& sub)
{
	if (title_ != "None" && type_ != "None")
	{
		if (title_ != sub.title_ || type_ != sub.type_)
			abort();
	}
	else 
	{
		title_ = sub.title_;
		type_ = sub.type_;
	}
	mass_ += sub.mass_;
	sub.mass_ = 0.0;
}

void Substance::addSubstance(Substance & sub, const double & _mass)
{
	if (title_ != "None" && type_ != "None")
	{
		if (title_ != sub.title_ || type_ != sub.type_ || _mass > sub.mass_)
			abort();
	}
	else
	{
		title_ = sub.title_;
		type_ = sub.type_;
	}
	mass_ += _mass;
	sub.mass_ -= _mass;
}

Substance Substance::getSubstance(double mass)
{
	if (mass_ < mass || type_ == "None" || title_ == "None")
		abort();
	if (mass < 0)
		mass = mass_;
	Substance temp = *this;
	temp.mass_ = mass;
	mass_ -= mass;
	return temp;
}

inline std::string Substance::getSubstanceTitle() const
{
	return title_;
}

inline std::string Substance::getSubstanceType() const
{
	return type_;
}

inline double Substance::getSubstanceMass() const
{
	return mass_;
}
