#include "Coord.h"



Coord::Coord()
{
	x_ = 0.0;
	y_ = 0.0;
	delta_ = 1.0;
}

Coord::Coord(const double & _x, const double & _y)
{
	x_ = _x;
	y_ = _y;
	delta_ = 1.0;
}

Coord::Coord(const double & _x, const double & _y, const double & _delta)
{

	x_ = _x;
	y_ = _y;
	delta_ = _delta;
}

void Coord::setX(const double & _x)
{
	x_ = _x;
}

void Coord::setY(const double & _y)
{
	y_ = _y;
}

void Coord::setDelta(const double & _delta)
{
	delta_ = _delta;
}

double Coord::getX() const
{
	return x_;
}

double Coord::getY() const
{
	return y_;
}

double Coord::getDelta() const
{
	return delta_;
}

void Coord::operator++()
{
	x_ += delta_;
	y_ += delta_;
}

void Coord::operator--()
{
	x_ -= delta_;
	y_ -= delta_;
}

bool Coord::operator!() const
{
	return x_ && y_;
}

Coord Coord::operator+(const Coord & _right) const
{
	Coord temp(x_ + _right.x_, y_ + _right.y_);
	return temp;
}

Coord Coord::operator-(const Coord & _right) const
{
	Coord temp(x_ - _right.x_, y_ - _right.y_);
	return temp;
}

bool operator>=(const Coord& _left, const Coord& _right)
{
	return (std::pow(_left.x_, 2.0) + std::pow(_left.y_, 2.0)) / 2.0 >= 
		(std::pow(_right.x_, 2.0) + std::pow(_right.y_, 2.0)) / 2.0;
}

std::ostream& operator<<(std::ostream& os, const Coord& _coord)
{
	os << "X = " << _coord.x_ << " Y = " << _coord.y_;
	return os;
}

std::istream& operator>>(std::istream& is, Coord& _coord)
{
	is >> _coord.x_ >> _coord.y_;
	return is;
}

Coord::~Coord()
{
}
