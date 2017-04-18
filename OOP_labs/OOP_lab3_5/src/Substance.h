#pragma once
#ifndef _SUBSTANCE_
#define _SUBSTANCE_
#include <string>

class Substance
{
private:
	double mass_;
	std::string title_;
	std::string type_;
public:
	friend class Bulb;
	Substance();
	Substance(const std::string& _title,
		const std::string _type);
	Substance(const double& _mass, const std::string& _title,
						const std::string _type);
	Substance(Substance& sub);
	void addSubstance(Substance& sub);
	void addSubstance(Substance& sub, const double& _mass);
	Substance getSubstance(double mass = -1.0);
	std::string getSubstanceTitle() const;
	std::string getSubstanceType() const;
	double getSubstanceMass() const;
};

#endif