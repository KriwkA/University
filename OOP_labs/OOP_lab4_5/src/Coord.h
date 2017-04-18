#pragma once
#ifndef _COORD_H_
#define _COORD_H_
#include <iostream>

class Coord
{
private:
	double x_;
	double y_;
	double delta_;
public:
	Coord();
	Coord(const double& _x, const double& _y);
	Coord(const double& _x, const double& _y, const double& _delta);
	void setX(const double& _x);
	void setY(const double& _y);
	void setDelta(const double& _delta);
	double getX() const;
	double getY() const;
	double getDelta() const;
	void operator++();
	void operator--();
	bool operator!() const;
	Coord operator+(const Coord& _right) const;
	Coord operator-(const Coord& _right) const;
	friend bool operator>=(const Coord& _left, const Coord& _right);
	friend std::ostream& operator<<(std::ostream& os, const Coord& _coord);
	friend std::istream& operator>>(std::istream& os, Coord& _coord);
	~Coord();
};

#endif