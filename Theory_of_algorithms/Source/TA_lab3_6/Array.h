#pragma once
#include <vector>

class Array
{
protected:
	std::vector<int> arr;
public:
	void RandArray(const int, const int);
	void ScanArray(const int);
	void PrintArray();
};

class Combo : public Array
{
private:
	int P;
	std::vector<std::vector<int>> combo;
public:
	void Print_Combo(int);
	void PrintP();
};