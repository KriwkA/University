#include <iostream>
#include "Progression.h"


class A
{
public:
	A(){ std::cout << "a" << std::endl; };
	virtual int func() { return 0; }
	virtual ~A() {std::cout << "~a" << std::endl; };
};

class B : public A
{
public:
	B(){ std::cout << "b" << std::endl; };
	virtual int func() { return 10; };
	virtual ~B() { std::cout << "~b" << std::endl; };
};


int main()
{
	double a, q, count;
	std::cout << "Input a1 and q:" << std::endl;
	std::cin >> a >> q;
	Progression& arifmetical = ArithmeticalProgression(a, q);
	Progression& geometrocal = GeometricalProgression(a, q);
	std::cout << "Input count of elements:" << std::endl;
	std::cin >> count;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(5);
	std::cout << "Arifmetical Progression: S(n) = " << arifmetical.sum(count) << std::endl;
	std::cout << "Geometrical Progression: S(n) = " << geometrocal.sum(count) << std::endl;
	system("pause");
	return 0;
}