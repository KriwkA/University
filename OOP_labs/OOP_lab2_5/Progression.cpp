#include <cmath>
#include "Progression.h"

Progression::Progression()
{
	firstElement_ = 0.0;
	coefficient_ = 0.0;
}

Progression::Progression(const double & _firstElement, const double & _coefficient)
{
	firstElement_ = _firstElement;
	coefficient_ = _coefficient;
}

void Progression::setFirstElement(const double& _firstElement)
{
	firstElement_ = _firstElement;
}

void Progression::setCoefficient(const double& _coefficient)
{
	coefficient_ = _coefficient;
}

double Progression::getFirstElement()
{
	return firstElement_;
}

double Progression::getCoefficient()
{
	return coefficient_;
}

ArithmeticalProgression::ArithmeticalProgression():Progression()
{
}

ArithmeticalProgression::ArithmeticalProgression(const double & _firstElement, const double & _coefficient):
	Progression(_firstElement, _coefficient)
{
}

double ArithmeticalProgression::sum(const size_t& _elementCount)
{
	return ((_elementCount)*(firstElement_+firstElement_+((_elementCount-1)*coefficient_)))/2.0;
}

GeometricalProgression::GeometricalProgression() :
	Progression()
{
}

GeometricalProgression::GeometricalProgression(const double & _firstElement, const double & _coefficient):
	Progression(_firstElement, _coefficient)
{
}

double GeometricalProgression::sum(const size_t& _elementCount)
{
	if (coefficient_ == 1)
		return _elementCount* firstElement_;
	return (firstElement_*(1 - std::pow(coefficient_, _elementCount))) / (1 - coefficient_);
}
