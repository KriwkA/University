#pragma once
#include <vector>
#include "Array.h"

template <typename T>
class Matrix
{
private:
	std::vector<Array<T>> matrix;
	int N;
	int M;
public:
	void RandMatrix(const int,const int,const int);
	void ScanMatrix(const int, const int);
	void PrintMatrix();
	bool Empty();
	int EvenPositiveCount();
};

