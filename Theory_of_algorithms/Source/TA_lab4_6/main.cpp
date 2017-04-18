#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Array.h"
#include "Matrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(GetTickCount64());
	Array<int> arr;
	Matrix<int> matrix;
	char key;
	int n, m, max;
	ULONGLONG StTime,EndTime;
	do
	{
		system("cls");
		cout << "1. Заполнение массива случайными числами." << endl;
		cout << "2. Заполнение матрицы случайными числами." << endl;
		cout << "3. Ввод массива." << endl;
		cout << "4. Ввод матрицы." << endl;
		if (!arr.Empty())
		{
			cout << "5. Отобразить массив." << endl;
			cout << "6. Сортировать массив по возрастанию." << endl;
			cout << "7. Сортировать массив по убыванию." << endl;
		}
		if (!matrix.Empty())
		{
			cout << "8. Отобразить матрицу." << endl;
			cout << "9. Вывести количество четных положительных эл-тов матрицы." << endl;
		}
		cout << "Esc. Выход." << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case '1':
			cout << "Введите длинну массива и макс значение эл-та:" << endl;
			cin >> n >> max;
			cout << "Выполняется заполнение массива." << endl;
			StTime = GetTickCount64();
			arr.RandArray(n, max);
			EndTime = GetTickCount64();
			cout << "Время выполнения: " << EndTime - StTime << "ms." << endl;
			cout << "Готово." << endl;
			break;
		case '2':
			cout << "Введите N, M и макс значение эл-та:" << endl;
			cin >> n  >> m >> max;
			cout << "Выполняется заполнение матрицы." << endl;
			StTime = GetTickCount64();
			matrix.RandMatrix(n , m, max);
			EndTime = GetTickCount64();
			cout << "Время выполнения: " << EndTime - StTime << "ms." << endl;
			cout << "Готово." << endl;
			break;
		case '3':
			cout << "Введите длинну массива:" << endl;
			cin >> n;
			arr.ScanArray(n);
			break;
		case '4':
			cout << "Введите N, M:" << endl;
			cin >> n >> m;
			matrix.ScanMatrix(n, m);
			break;
		case '5':
			if (!arr.Empty())
			{
				cout << "Массив:" << endl;
				arr.PrintArray();
				cout << endl;
			}
			break;
		case '6':
			if (!arr.Empty())
			{
				cout << "Выполняется сортировка..." << endl;
				StTime = GetTickCount64();
				arr.SortBubbleLH();
				EndTime = GetTickCount64();
				system("cls");
				cout << "Время выполнения: " << EndTime - StTime << "ms." << endl;
				cout << "Готово." << endl;
			}
			break;
		case '7':
			if (!arr.Empty())
			{
				cout << "Выполняется сортировка..." << endl;
				StTime = GetTickCount64();
				arr.SortBubbleHL();
				EndTime = GetTickCount64();
				system("cls");
				cout << "Время выполнения: " << EndTime - StTime << "ms." << endl;
				cout << "Готово." << endl;
			}
			break;
		case '8':
			if (!matrix.Empty())
			{
				cout << "Матрица:" << endl;
				matrix.PrintMatrix();
			}
			break;
		case '9':
			if (!matrix.Empty())
			{
				cout << "Выполняется подсчет четных положительных элементов..." << endl;
				StTime = GetTickCount64();
				int count = matrix.EvenPositiveCount();
				EndTime = GetTickCount64();
				system("cls");
				cout << "В матрице " << count
					<< " четных положительных эл-тов." << endl;
				cout << "Время выполнения: " << EndTime - StTime << "ms." << endl;
			}
			break;
		}
		system("pause");
	} while (key != 27);
	return 0;
}