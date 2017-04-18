#include <iostream>
#include <iomanip>
#include <string>
#include "Pack.h"
#include "MyList.h"

void printList(const MyList<Pack>& _list, const std::string& _listName = "List")
{
	std::cout << _listName << ':' << std::endl;
	std::cout << std::left << std::setw(6) << '¹' << "Name" << std::endl;
	std::cout << _list << std::endl;
}

int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");
		MyList<Pack> list;
		std::cout << "Base list created." << std::endl;
		printList(list);
		Pack a(1, "TestPack1");
		Pack b(2, "TestPack2");
		Pack c(3, "TestPack3");
		Pack d(4, "TestPack4");
		Pack e(5, "TestPack5");
		list.pushBack(a);
		list.pushBack(b);
		list.pushBack(c);
		std::cout << "3 items addeded to the end of the list." << std::endl;
		printList(list);
		list.deleteItem(1);
		std::cout << "The second item is removed from the list." << std::endl;
		printList(list);
		list.pushFront(e);
		std::cout << "New item addeded to the front of the list" << std::endl;
		printList(list);
		MyList<Pack> copyOfList(list);
		std::cout << "A copy of the list created." << std::endl;
		printList(copyOfList, "Copy of Lists");
		copyOfList.popBack();
		std::cout << "Last item is removed from the copy of list." << std::endl;
		printList(copyOfList, "Edited copy of Lists");
		std::cout << "Base Lists are not modified." << std::endl;
		printList(list);
		std::cout.setf(std::ios::boolalpha);
		std::cout << "Third element enable in Lists: " << (bool)list.enable(c) << std::endl;
		std::cout << "Third element enable in modified copy of Lists: " << (bool)copyOfList.enable(c) << std::endl << std::endl;
		list.deleteItem(2);
		std::cout << "Third item is removed from the list" << std::endl;
		copyOfList.deleteItem(2);
		std::cout << "Third item is removed from the edited copy of list" << std::endl;
	}
	catch (const MyList<Pack>::bad_List& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}