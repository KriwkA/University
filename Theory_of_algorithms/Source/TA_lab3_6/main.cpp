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
		cout << "1.��������� ������ ���������� �������." << endl;
		cout << "2.������� ������." << endl;
		cout << "3.���������� ������." << endl;
		cout << "4.������� ����������." << endl;
		cout << "5.���-�� ������������ ��������." << endl;
		cout << "Esc. Exit." << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case '1':
			cout << "������� ������ �������:" << endl;
			cin >> n;
			cout << "������� ������������ �������� ��-��:" << endl;
			cin >> max;
			combo.RandArray(n, max);
			break;
		case '2':
			cout << "������� ������ �������:" << endl;
			cin >> n;
			combo.ScanArray(n);
			break;
		case '3':
			combo.PrintArray();
			system("pause");
			break;
		case '4':
			cout << "������� ����� ��-���:" << endl;
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