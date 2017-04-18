#pragma once
#ifndef _PROGRESSION_H_
#define _PROGRESSION_H_

class Progression
{
protected:
	double firstElement_;
	double coefficient_;
public:
	Progression();
	Progression(const double& _firstElement, const double& _coefficient);
	virtual double sum(const size_t& _elementCount) = 0;
	void setFirstElement(const double& _firstElement);
	void setCoefficient(const double& _coefficient);
	double getFirstElement();
	double getCoefficient();
	virtual ~Progression() {};
};

class ArithmeticalProgression : public Progression
{
public:
	ArithmeticalProgression();
	ArithmeticalProgression(const double& _firstElement, const double& _coefficient);
	virtual double sum(const size_t& _elementCount);
	virtual ~ArithmeticalProgression() {};
};

class GeometricalProgression : public Progression
{
public:
	GeometricalProgression();
	GeometricalProgression(const double& _firstElement, const double& _coefficient);
	virtual double sum(const size_t& _elementCount);
	virtual ~GeometricalProgression() {};
};

#endif