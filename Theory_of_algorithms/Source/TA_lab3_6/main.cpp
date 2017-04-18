#include <iostream>
#include <time.h>
#include <conio.h>
#include "Array.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));	
	Combo combo;
	char key;
	int n, sum , max;
	do
	{
		system("cls");
		cout << "1.Заполнить массив случайными числами." << endl;
		cout << "2.Считать массив." << endl;
		cout << "3.Отобразить массив." << endl;
		cout << "4.Вывести комбинации." << endl;
		cout << "5.Кол-во элементарных операций." << endl;
		cout << "Esc. Exit." << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case '1':
			cout << "Введите размер массива:" << endl;
			cin >> n;
			cout << "Введите максимальное значение эл-та:" << endl;
			cin >> max;
			combo.RandArray(n, max);
			break;
		case '2':
			cout << "Введите размер массива:" << endl;
			cin >> n;
			combo.ScanArray(n);
			break;
		case '3':
			combo.PrintArray();
			system("pause");
			break;
		case '4':
			cout << "Введите сумму эл-тов:" << endl;
			cin >> sum;
			combo.Print_Combo(sum);
			system("pause");
			break;
		case '5':
			system("cls");
			combo.PrintP();
			system("pause");
			break;
		}

	} while (key != 27);
	system("pause");
}