#include <iostream>
#include <conio.h>

using namespace std;

struct BookList
{
	char Title[20];
	BookList* NextBook;
};

struct Child
{
	char Name[20];
	BookList* FirstBook;
};

struct ChildList
{
	Child child;
	ChildList* NextChild;
};

void addBook(BookList **fBook)
{
	system("cls");
	if (*fBook == NULL)
	{
		*fBook = new BookList;
		(*fBook)->NextBook = NULL;
	}
	else
	{
		BookList* newBook = new BookList;
		newBook->NextBook = (*fBook);
		(*fBook) = newBook;
	}
	cout << "¬ведите название книги." << endl;
	cin >> (*fBook)->Title;
	system("cls");
	cout << " нига добавлена успешно." << endl;
	system("pause");
}

Child NewChild()
{
	Child child;
	int N;
	system("cls");
	cout << "¬ведите им€ ученика." << endl;
	cin >> child.Name;
	cout << "¬ведите кол-во прочитанных книг." << endl;
	cin >> N;
	child.FirstBook = NULL;
	for (int i(0); i < N; i++)
		addBook(&child.FirstBook);
	system("cls");
	cout << "”ченик добавлен." << endl;
	system("pause");
	return child;
}

void addChild(ChildList **fChild)
{
	if (*fChild == NULL)
	{
		*fChild = new ChildList;
		(*fChild)->NextChild = NULL;
	}
	else
	{
		ChildList* newChild = new ChildList;
		newChild->NextChild = (*fChild);
		(*fChild) = newChild;
	}
	(*fChild)->child = NewChild();
}

void PrintBookList(BookList *fBook, ChildList *fChild)
{
	ChildList *Child= fChild;
	while (fBook != NULL)
	{
		fChild = Child;
		float percent=0.0;
		int n = 0, np = 0;
		while (fChild != NULL)
		{
			n++;
			BookList *Book = fChild->child.FirstBook;
			while (Book != NULL)
			{
				if (strcmp(Book->Title,fBook->Title)==0)
				{
					np++;
					break;
				}				
				else 
					Book = Book->NextBook;
			}
			fChild = fChild->NextChild;
		}
		if (n != 0) percent = float(np) / float(n) * 100.0;
		cout << fBook->Title << ": " << percent << '%' << endl;
		fBook = fBook->NextBook;
	}
}

void PrintChildBookList(BookList *fBook)
{
	while (fBook != NULL)
	{
		cout << fBook->Title << ' ';
		fBook = fBook->NextBook;
	}
}

void PrintChildList(ChildList *fChild)
{
	while (fChild != NULL)
	{
		cout << fChild->child.Name << ": ";
		PrintChildBookList(fChild->child.FirstBook);
		cout << endl;
		fChild = fChild->NextChild;
	}
}

void DeleteBookList(BookList **fBook)
{
	BookList *NextBook;
	while (*fBook != NULL)
	{
		NextBook = *fBook;
		*fBook = (*fBook)->NextBook;
		delete NextBook;
	}
}

void DeleteChildList(ChildList **fChild)
{
	ChildList *NextChild;
	while (*fChild != NULL)
	{
		NextChild = *fChild;
		*fChild = (*fChild)->NextChild;
		DeleteBookList(&NextChild->child.FirstBook);
		delete NextChild;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	ChildList *FirstChild = NULL;
	BookList *FirstBook = NULL;

	char key;
	while (true)
	{
		system("cls");
		cout << "1.Add child" << endl;
		cout << "2.Show child list" << endl;
		cout << "3.Add book" << endl;
		cout << "4.Show book list" << endl;
		cout << "Esc.Exit" << endl;
		key = _getch();
		switch (key)
		{
		case '1': addChild(&FirstChild); break;
		case '2':
			system("cls");
			PrintChildList(FirstChild);
			cout << endl;
			system("pause");
		break;
		case '3': addBook(&FirstBook);  break;
		case '4':
			system("cls");
			PrintBookList(FirstBook,FirstChild); 
			system("pause"); 
		break;
		case 27:
			DeleteChildList(&FirstChild); 
			DeleteBookList(&FirstBook);
			return 0;
		break;
		}
	}
}