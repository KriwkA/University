#pragma once
#ifndef _WATER_
#define _WATER_
#include <cstdlib>

class Water
{
private:
	double capacity_;
public:
	friend class Bulb;
	Water();
	Water(Water& water);
	Water(const double& _capacity);
	void addWater(Water& _water);
	void addWater(Water& _water, const double& _capacity);
	Water getWater(double capacity = -1.0);
	double getCapacity() const;
};

#endif