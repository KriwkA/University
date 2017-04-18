#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian"); //отображение кириллицы
	ifstream fin("input.txt", ios::in); //файл ввода
	if (!fin) //наличие файла
	{
		cout << "Файл не существует." << endl;
		system("pause");
		return 0;
	}
	ofstream fout("output.txt", ios::out); //файл вывода
	string str;
	while (!fin.eof()) //чтение и запись в файл
	{
		unsigned int count = 0;
		getline(fin, str); 
		for (auto a : str) //проход по эл-там строки
			if (a == '(' || a == ')') count++;
		fout << str << ' ' << count << endl;
	}
	fin.close(); //закрытие и сохранение файлов
	fout.close();
	system("pause");
	return 0;
}