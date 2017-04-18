#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Time.h"

using namespace std;

void printTime(const Time time)
{
	cout << time.getHour() << "h. "
		<< time.getMinute() << "m. "
		<< time.getSecond() << "s." << endl;
}

void randTimeArr(Time** arr, const unsigned int n)
{
	delete[] *arr;
	*arr = new Time[n];
	for (int i(0); i < n; i++)
		(*arr)[i].random();
}

void sortTimeArr(Time** arr, const unsigned int n)
{
	for (int step(n / 2); step > 0; step /= 2)
		for (int i(0); i < (n - step); i++)
			for (int j(i); (j >= 0) && ((*arr)[j] < (*arr)[j + step]); j--)
				swap((*arr)[j], (*arr)[j + step]);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Time* arr = nullptr;
	unsigned int n=0;
	char key;
	do
	{
		system("cls");
		cout << "1. RandTimeArray" << endl;
		cout << "2. PrintTimeArray" << endl;
		cout << "3. SortTimeArray" << endl;
		cout << "Esc. Exit" << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case '1':
			cout << "Input n:" << endl;
			cin >> n;
			randTimeArr(&arr, n);
			break;
		case '2':
			for (int i(0); i < n; i++)
				printTime(arr[i]);
			system("pause");
			break;
		case '3':
			cout << "Array is sorted..." << endl;
			ULONGLONG stTime = GetTickCount64();
			sortTimeArr(&arr, n);
			ULONGLONG endTime = GetTickCount64();
			cout << "Done. " << endTime-stTime <<"ms." << endl;
			system("pause");
			break;
		}
	} while (key != 27);

	delete[] arr;
	return 0;
}