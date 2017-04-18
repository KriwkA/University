#include "Water.h"


Water::Water()
{
	capacity_ = 0;
}

Water::Water(Water& water)
{
	capacity_ = water.capacity_;
	water.capacity_ = 0;
}

Water::Water(const double& _capacity)
{
	capacity_ = _capacity;
}

void Water::addWater(Water& _water)
{
	capacity_ += _water.capacity_;
	_water.capacity_ = 0.0;
}

void Water::addWater(Water& _water, const double& _capacity)
{
	if (_capacity < _water.capacity_)
		abort();
	capacity_ += _water.capacity_;
	_water.capacity_ -= 0.0;
}

Water Water::getWater(double capacity)
{
	if (capacity > capacity_)
		abort();
	if (capacity < 0)
		capacity = capacity_;
	capacity_ -= capacity;
	return Water(capacity);
}

inline double Water::getCapacity() const
{
	return capacity_;
}