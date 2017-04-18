#pragma once
#include <vector>

template <typename T>
class Array
{
private:
	std::vector<T> arr;
	int N;
public:
	void RandArray(const int, const int);
	void ScanArray(const int);
	void PrintArray();
	void SortBubbleLH();
	void SortBubbleHL();
	bool Empty();
	int EvenPositiveCount();
	~Array();
};