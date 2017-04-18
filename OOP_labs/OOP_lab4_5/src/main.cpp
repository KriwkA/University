#include <iostream>
#include <iomanip>
#include "Coord.h"

int main()
{
	Coord a,b;
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::boolalpha);
	std::cout.precision(3);
	std::cout << "First point coord (0, 0): " << (!a) << std::endl;
	std::cout << "Input first point coord:" << std::endl;
	std::cin >> a;
	std::cout << "Input second point coord:" << std::endl;
	std::cin >> b;

	std::cout << "First point coord >= then the second: " << (a >= b) << std::endl;
	a++;
	b--;
	std::cout << "First point coord are inc." << std::endl;
	std::cout << "Second point coord are dec." << std::endl;
	std::cout << "First point: " << a << std::endl;
	std::cout << "Second point: " << b << std::endl;
	std::cout << "First point coord >= then the second: " << (a >= b) << std::endl;
	std::cout << "First point coord + second: " << (a + b) << std::endl;
	system("pause");
	return 0;
}