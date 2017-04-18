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
		cout << "1. ���������� ������� ���������� �������." << endl;
		cout << "2. ���������� ������� ���������� �������." << endl;
		cout << "3. ���� �������." << endl;
		cout << "4. ���� �������." << endl;
		if (!arr.Empty())
		{
			cout << "5. ���������� ������." << endl;
			cout << "6. ����������� ������ �� �����������." << endl;
			cout << "7. ����������� ������ �� ��������." << endl;
		}
		if (!matrix.Empty())
		{
			cout << "8. ���������� �������." << endl;
			cout << "9. ������� ���������� ������ ������������� ��-��� �������." << endl;
		}
		cout << "Esc. �����." << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case '1':
			cout << "������� ������ ������� � ���� �������� ��-��:" << endl;
			cin >> n >> max;
			cout << "����������� ���������� �������." << endl;
			StTime = GetTickCount64();
			arr.RandArray(n, max);
			EndTime = GetTickCount64();
			cout << "����� ����������: " << EndTime - StTime << "ms." << endl;
			cout << "������." << endl;
			break;
		case '2':
			cout << "������� N, M � ���� �������� ��-��:" << endl;
			cin >> n  >> m >> max;
			cout << "����������� ���������� �������." << endl;
			StTime = GetTickCount64();
			matrix.RandMatrix(n , m, max);
			EndTime = GetTickCount64();
			cout << "����� ����������: " << EndTime - StTime << "ms." << endl;
			cout << "������." << endl;
			break;
		case '3':
			cout << "������� ������ �������:" << endl;
			cin >> n;
			arr.ScanArray(n);
			break;
		case '4':
			cout << "������� N, M:" << endl;
			cin >> n >> m;
			matrix.ScanMatrix(n, m);
			break;
		case '5':
			if (!arr.Empty())
			{
				cout << "������:" << endl;
				arr.PrintArray();
				cout << endl;
			}
			break;
		case '6':
			if (!arr.Empty())
			{
				cout << "����������� ����������..." << endl;
				StTime = GetTickCount64();
				arr.SortBubbleLH();
				EndTime = GetTickCount64();
				system("cls");
				cout << "����� ����������: " << EndTime - StTime << "ms." << endl;
				cout << "������." << endl;
			}
			break;
		case '7':
			if (!arr.Empty())
			{
				cout << "����������� ����������..." << endl;
				StTime = GetTickCount64();
				arr.SortBubbleHL();
				EndTime = GetTickCount64();
				system("cls");
				cout << "����� ����������: " << EndTime - StTime << "ms." << endl;
				cout << "������." << endl;
			}
			break;
		case '8':
			if (!matrix.Empty())
			{
				cout << "�������:" << endl;
				matrix.PrintMatrix();
			}
			break;
		case '9':
			if (!matrix.Empty())
			{
				cout << "����������� ������� ������ ������������� ���������..." << endl;
				StTime = GetTickCount64();
				int count = matrix.EvenPositiveCount();
				EndTime = GetTickCount64();
				system("cls");
				cout << "� ������� " << count
					<< " ������ ������������� ��-���." << endl;
				cout << "����� ����������: " << EndTime - StTime << "ms." << endl;
			}
			break;
		}
		system("pause");
	} while (key != 27);
	return 0;
}