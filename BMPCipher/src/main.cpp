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
		cout << "1. Открыть изображение" << endl;
		if (image.isLoad())
		{
			cout << "2. Зашифровать текст в изображение" << endl;
			cout << "3. Извлечь текст из изобрашжения" << endl;
			cout << "4. Сохранить изображение" << endl;
			cout << "5. Сохранить изображение в..." << endl;
		}
		cout << "Esc. Выход" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			cout << "Введите путь к изображению:" << endl;
			getline(cin, fileName);
			image.loadFile(fileName);
			break;

		if (image.isLoad())
		{
		case '2':
			system("cls");
			cout << "Введите путь к текстовому документу:" << endl;
			getline(cin, fileName);
			image.encrypt(fileName);
			break;
		case '3':
			system("cls");
			cout << "Введите путь для сохранения теста:" << endl;
			getline(cin, fileName);
			image.decrypt(fileName);
			break;

		case '4':
			image.saveFile();
			break;
		case'5':
			system("cls");
			cout << "Введите путь для сохранения файла:" << endl;
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