#include <iostream>
#include "Bulb.h"

void printInfo(const Bulb& _first, const Bulb& _second)
{
	std::cout << std::endl << "First bottle:" << std::endl;
	_first.printInfo();
	std::cout << std::endl << "Second bottle:" << std::endl;
	_second.printInfo();
}

int main()
{
	Bulb bottle1("Bottle");
	Bulb bottle2("Bottle");
	printInfo(bottle1, bottle2);
	bottle1.addLiquor(Liquor("Salt water", Water(0.3), Substance(0.01, "Salt", "Salt")));
	std::cout << std::endl << "Salt water added in the first bottle." << std::endl;
	printInfo(bottle1, bottle2);
	std::cout << std::endl << "Salt water trancefused into the second bottle of the first." << std::endl;
	bottle2.addLiquor(bottle1.getLiquor());
	printInfo(bottle1, bottle2);
	system("pause");
	return 0;
}