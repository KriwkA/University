#include <iostream>
#include <fstream>
#include <iomanip>
#include <exception>
#include "Vector.h"

void printArr(const Vector& _arr)
{
	for (size_t i = 0; i < _arr.size(); ++i)
		std::cout << _arr[i] << ' ';
	std::cout << std::endl;
}

int main()
{
	try
	{
		double a, x, b;
		std::ofstream fout("output.txt");
		fout.setf(std::ios::fixed);
		fout.width(12);
		fout.precision(4);
		fout.fill('%');
		std::cout << "Input a, b, x:" << std::endl;
		std::cin >> a >> b >> x;
		fout << a*x + b << std::endl;
		fout.close();
		Vector arr(10);
		for (size_t i = 0; i < arr.size(); ++i)
			arr[i] = rand() % 10;
		std::cout << "Random array:" << std::endl;
		printArr(arr);
		arr.resize(1);
		std::cout << "Array size set 1:" << std::endl << "Array: ";
		printArr(arr);
		arr.pop_back();
		std::cout << "Pop last element from array" << std::endl << "Array: ";
		printArr(arr);
		arr.pop_back();
		std::cout << "Pop last element from array" << std::endl << "Array: ";
		printArr(arr);
	}
	catch (const Vector::bad_Vector& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error: " << "unknown error" << std::endl;
	}
	system("pause");
	return 0;
}