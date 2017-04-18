#include "Array.h"
#include <iostream>

template class Array < int > ;

template <typename T> 
void Array<T>::RandArray(const int n, const int rand_max)
{
	N = n;
	arr.clear();
	for (int i(0); i < n; i++)
	{
		arr.push_back(rand() % (rand_max+1));
	}
}

template <typename T> 
void Array<T>::ScanArray(const int n)
{
	N = n;
	arr.clear();
	int temp;
	for (int i(0); i < n; i++)
	{
		std::cin >> temp;
		arr.push_back(temp);
	}
}

template <typename T> 
bool Array<T>::Empty()
{
	if (arr.empty()) return true;
	else return false;
}

template <typename T> 
void Array<T>::PrintArray()
{
	for (auto a : arr)
		std::cout << a << ' ';
}

template <typename T> 
void Array<T>::SortBubbleLH()
{
	for (int j(N - 1); j > 0; j--)
		for (int i(0); i < j; i++)
			if (arr[i] > arr[i + 1])
			{
				int x = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = x;
			}
}

template <typename T> 
void Array<T>::SortBubbleHL()
{
	for (int j(N - 1); j > 0; j--)
		for (int i(0); i < j; i++)
			if (arr[i] < arr[i + 1])
			{
				int x = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = x;
			}
}

template <typename T> 
int Array<T>::EvenPositiveCount()
{
	int count = 0;
	for (T a : arr)
		if (a>0 && a % 2 == 0) count++;
	return count;
}

template <typename T>
Array<T>::~Array()
{
	arr.clear();
}