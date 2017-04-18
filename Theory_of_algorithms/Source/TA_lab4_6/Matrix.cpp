#include "Matrix.h"
#include <iostream>

template class Matrix < int >;

template <typename T> 
void Matrix<T>::RandMatrix(const int n, const int m, const int max)
{
	matrix.clear();
	N = n;
	M = m;
	for (int i(0); i < n; i++)
	{
		Array<T> temp;
		temp.RandArray(m, max);
		matrix.push_back(temp);
	}
}

template <typename T>
void Matrix<T>::ScanMatrix(const int n, const int m)
{
	matrix.clear();
	N = n;
	M = m;
	for (int i(0); i < n; i++)
	{
		Array<T> temp;
		temp.ScanArray(m);
		matrix.push_back(temp);
	}
}

template <typename T>
void Matrix<T>::PrintMatrix()
{
	for (int i(0); i < N; i++)
	{
		matrix[i].PrintArray();
		std::cout << std::endl;
	}
}

template <typename T>
bool Matrix<T>::Empty()
{
	if (matrix.empty()) return true;
	else return false;
}

template <typename T>
int Matrix<T>::EvenPositiveCount()
{
	int count = 0;
	for (int i(0); i < N; i++)
		count += matrix[i].EvenPositiveCount();
	return count;
}
