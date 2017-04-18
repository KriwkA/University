#include <iostream>
#include <conio.h>
#include <set>
#include "Bookmark.h"

int main()
{
	try
	{
		Bookmark bookmark;
		std::string name;
		long long phone;
		std::set<char> keyset;
		keyset.insert(27);
		keyset.insert('1');
		keyset.insert('2');
		keyset.insert('3');
		char c;
		bool flag = false;
		while (true)
		{
			system("cls");
			c = 111;
			printf("1.Add\n2.Del\n3.Print\nEsc.Quit\n");
			while (!keyset.count(c))
				c = _getch();
			switch (c)
			{
			case '1':
			{
				system("cls");
				std::cout << "Input FIO:" << std::endl;
				if (flag) std::cin.get();
				std::getline(std::cin, name);
				std::cout << "Input phone number:" << std::endl;
				std::cin >> phone;
				bookmark.add(std::make_pair(name, phone));
				flag = true;
				system("pause");
			} break;
			case '2':
			{
				system("cls");
				size_t pos;
				std::cout << "Input position on bookmark:" << std::endl;
				std::cin >> pos;
				bookmark.del(pos - 1);
				system("pause");
			} break;
			case '3':
			{
				system("cls");
				std::cout << bookmark;
				std::cout.flush();
				system("pause");
			}break;
			case 27:
			{
				return 0;
			}break;
			}
		}
	}
	catch (const std::exception& _e)
	{
		std::cerr << _e.what() << std::endl;
	}
	system("pause");
	return 0;
}