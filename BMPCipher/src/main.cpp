#include <iostream>
#include <conio.h>
#include <string>
#include "BmpCipher.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char key = ' ';
	std::string fileName;
	BmpCipher image;
	do
	{
		system("cls");
		cout << "1. ������� �����������" << endl;
		if (image.isLoad())
		{
			cout << "2. ����������� ����� � �����������" << endl;
			cout << "3. ������� ����� �� ������������" << endl;
			cout << "4. ��������� �����������" << endl;
			cout << "5. ��������� ����������� �..." << endl;
		}
		cout << "Esc. �����" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			cout << "������� ���� � �����������:" << endl;
			getline(cin, fileName);
			image.loadFile(fileName);
			break;

		if (image.isLoad())
		{
		case '2':
			system("cls");
			cout << "������� ���� � ���������� ���������:" << endl;
			getline(cin, fileName);
			image.encrypt(fileName);
			break;
		case '3':
			system("cls");
			cout << "������� ���� ��� ���������� �����:" << endl;
			getline(cin, fileName);
			image.decrypt(fileName);
			break;

		case '4':
			image.saveFile();
			break;
		case'5':
			system("cls");
			cout << "������� ���� ��� ���������� �����:" << endl;
			getline(cin, fileName);
			image.saveFile(fileName);
			break;
		}

		case 27:
			return 0;
			break;
		}
	} 
	while (true);
}