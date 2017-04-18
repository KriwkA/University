#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian"); //����������� ���������
	ifstream fin("input.txt", ios::in); //���� �����
	if (!fin) //������� �����
	{
		cout << "���� �� ����������." << endl;
		system("pause");
		return 0;
	}
	ofstream fout("output.txt", ios::out); //���� ������
	string str;
	while (!fin.eof()) //������ � ������ � ����
	{
		unsigned int count = 0;
		getline(fin, str); 
		for (auto a : str) //������ �� ��-��� ������
			if (a == '(' || a == ')') count++;
		fout << str << ' ' << count << endl;
	}
	fin.close(); //�������� � ���������� ������
	fout.close();
	system("pause");
	return 0;
}