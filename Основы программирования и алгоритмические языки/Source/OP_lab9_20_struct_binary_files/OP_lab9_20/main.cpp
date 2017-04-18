#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <conio.h>

using namespace std;

struct order
{
	char id_1[8]; //��������� ���� �����������
	char id_2[8]; //��������� ���� ����������
	unsigned int summ; //����� ��������
};

size_t size_order = sizeof(order);

//�������� ����� ������ � ��������
order NewOrder()
{
	system("cls");
	order new_order;
	cout << "������� ��������� ���� �����������:" << endl;
	cin >> new_order.id_1;
	cout << "������� ��������� ���� ����������:" << endl;
	cin >> new_order.id_2;
	cout << "������� ����� ��������:" << endl;
	cin >> new_order.summ;
	return new_order;
}

//���������� ������ �������� � ���� � ���. �������
void Add(FILE* f,const order& O)
{
	order temp;
	int pos = 0;
	bool flag = false; //������� � �������� ��� �����
	fseek(f, 0, 2);
	unsigned long int file_length = ftell(f) / size_order;
	for (pos = file_length-1; pos >= 0; pos--)
	{
		fseek(f, pos*size_order, SEEK_SET);
		fread(&temp, size_order, 1, f);
		fseek(f, pos*size_order, SEEK_SET);
		if (strcmp(temp.id_1, O.id_1) > 0)
		{
			fwrite(&O, size_order, 1, f);
			fwrite(&temp, size_order, 1, f);
		}
		else
		{
			fwrite(&temp, size_order, 1, f);
			fwrite(&O, size_order, 1, f);
			flag = true;
			break;
		}
	}
	if (!flag) //���� �� ����� ����� � ��. ��� �����
	{
		fseek(f, 0, SEEK_SET);
		fwrite(&O, size_order, 1, f);
	}
	system("pause");
}

//����� ������ ����� �� �����
void PrintAll(FILE* f)
{
	system("cls");
	fseek(f, 0, 0);
	order temp;
	cout.setf(ios::left);
	cout << "���������� ���������� �����" << endl;
	while (fread(&temp, size_order, 1, f))
		cout << setw(11) << temp.id_1 << setw(11) << temp.id_2 << temp.summ << endl;
	system("pause");
}

//�������� �����
void Loadfile(FILE** f)
{
	*f = fopen("input", "r+b");
	if (!(*f)) 
		*f = fopen("input", "w+b");
}
//����� ��������� ������ � ����� �� �����������.
void Search(FILE *f)
{
	system("cls");
	order temp;
	char str[8];
	cout << "������� ��������� ���� �����������:" << endl;
	cin >> str;
	system("cls");
	bool empty = true;
	cout.setf(ios::left);
	cout << "���������� ���������� �����" << endl;
	fseek(f, 0, 0);
	while (fread(&temp, size_order, 1, f))
	{
		if (!strcmp(temp.id_1, str))
		{
			cout << setw(11) << temp.id_1 << setw(11) << temp.id_2 << temp.summ << endl;
			empty = false;
		}
	}
	if (empty)
		cout << "��������� ���� �� ������." << endl;
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* f;
	Loadfile(&f);
	char key; //�������
	do
	{
		system("cls");
		cout << "1.Add 2.PrintAll 3.Search Esc.Exit" << endl;
		key = _getch();
		switch (key)
		{
		case '1': Add(f, NewOrder()); break;
		case '2': PrintAll(f); break;
		case '3': Search(f); break;
		}
	} while (key != 27);
	fclose(f); //�������� � ���������� �����
	system("cls");
	system("pause");
	return 0;
}