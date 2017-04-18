#include <iostream>
#include <iomanip>
#include <map>
#include <Windows.h>

template<typename T>
T f(const T* a, const size_t& _n)
{
	std::map<T, size_t> count;
	for (size_t i = 0; i < _n; ++i)
		count[a[i]]++;
	size_t maxCount = count.begin()->second;
	T ans = count.begin()->first;
	for(auto i : count)
		if (i.second > maxCount)
		{
			maxCount = i.second;
			ans = i.first;
		}
	return ans;
}


template<typename T>
void printArr(const T* arr, const size_t& _n)
{
	for (size_t i = 0; i < _n; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));
	size_t n;
	std::cout << "Input array size:" << std::endl;
	std::cin >> n;
	int* a = new int[n];
	for (size_t i = 0; i < n; ++i)
		a[i] = rand() % 5 + 1;
	printArr(a, n);
	std::cout << f(a, n) << std::endl;
	delete[] a;
	system("pause");
	return 0;
}