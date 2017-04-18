#include "Array.h"
#include <iostream>

void Array::RandArray(const int n, const int rand_max)
{
	arr.clear();
	for (int i(0); i < n; i++)
	{
		arr.push_back(rand() % (rand_max+1));
	}
}

void Array::ScanArray(const int n)
{
	arr.clear();
	int temp;
	std::cout << "Введите массив:" << std::endl;
	for (int i(0); i < n; i++)
	{
		std::cin >> temp;
		arr.push_back(temp);
	}
}

void Array::PrintArray()
{
	if (arr.empty())
	{
		std::cout << "Массив пуст." << std::endl;
		return;
	}
	std::cout << "Массив:" << std::endl;
	for (auto a : arr)
		std::cout << a << ' ';
	std::cout << std::endl;
}


void Combo::Print_Combo(int sum)
{
	int s, k = 0;
	combo.clear();
	int counter1 = 0;
	int P_in = 0;
	for (int i(0); i < (1 << arr.size()); i++)
	{
		s = 0;
		counter1++;
		int counter_in1 = 0;
		int P_in2 = 0;
		combo.resize(combo.size() + 1);
		for (int j(0); j < arr.size(); j++)
		{
			counter_in1++;
			if (i + 1 & (1 << j))
			{
				combo.back().push_back(arr[j]);
				s = s + arr[j];
				P_in2+=3;
			}
		}
		P_in += 1 + P_in2 + 3*counter_in1;

		if (s != sum)
		{
			combo.pop_back();
			P_in++;
		}
	}	
	P = 1 + 3 * counter1 + P_in;
	if (combo.empty())
	{
		std::cout << "Комбинаций не существует." << std::endl;
		return;
	}
	std::cout << "Список комбинаций:" << std::endl;
	for (int i(0); i < combo.size(); i++)
	{
		for (auto a : combo.at(i))
			std::cout << a << ' ';
		std::cout << std::endl;
	}
}

void Combo::PrintP()
{
	std::cout << "Кол-во элементарных операций = ";
	std::cout << P << std::endl;
}