#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

struct Time
{
	int hour;
	int minute;
};
//запись о поезде
struct train
{
	int number; //номер поезда
	char StPoint[8]; //место отправления
	char EndPoint[8]; //место прибытия
	Time StTime;	//время отправления
	Time EndTime;	//время прибытия
	unsigned int Price; //стоимость билета
};
//элемент списка поезда
struct trainlist
{
	train key;
	trainlist* next;
};
//считывание данных поезда
train ScanTrain()
{
	train Train;
	cout << "Введите номер поезда:" << endl;
	cin >> Train.number;
	cout << "Введите место отправки:" << endl;
	cin >> Train.StPoint;
	cout << "Введите место прибытия:" << endl;
	cin >> Train.EndPoint;
	cout << "Введите время отправки:" << endl;
	cin >> Train.StTime.hour >> Train.StTime.minute;
	cout << "Введите время прибытия:" << endl;
	cin >> Train.EndTime.hour >> Train.EndTime.minute;
	cout << "Введите стоимость билета:" << endl;
	cin >> Train.Price;
	return Train;
}
//вывод данных о поезде
void PrintTrain(const train& Train)
{
	cout.setf(ios::left);
	cout << setw(3) << Train.number;
	cout << setw(9) << Train.StPoint;
	cout << setw(9) << Train.EndPoint;
	cout << setw(2) << Train.StTime.hour << ':' << setw(4) << Train.StTime.minute;
	cout << setw(2) << Train.EndTime.hour << ':' << setw(5) << Train.EndTime.minute;
	cout << Train.Price << endl;
}
//добавление нового поезда в конец списка
void AddTrain(trainlist** First, trainlist** Last, train NewTrain)
{
	if (!*First)
	{
		*First = new trainlist;
		(*First)->key = NewTrain;
		(*First)->next = NULL;
		*Last = *First;
		return;
	}
	(*Last)->next = new trainlist;
	*Last = (*Last)->next;
	(*Last)->key = NewTrain;
	(*Last)->next = NULL;
}
//вывод списка поездов
void PrintTrainList(trainlist* Train)
{
	if (!Train)
	{
		cout << "Список пуст" << endl;
		return;
	}
	while (Train)
	{
		PrintTrain(Train->key);
		Train = Train->next;
	}
}
//удаление первого эл-та списка
void PopTrain(trainlist** FirstTrain)
{
	if (!*FirstTrain)
	{
		cout << "Поездов нет." << endl;
		return;
	}
	trainlist* temp;
	temp = *FirstTrain;
	*FirstTrain = (*FirstTrain)->next;
	cout << "Поезд " << temp->key.StPoint << '-'
		<< temp->key.EndPoint << " отправлен." << endl;
	delete temp;
}
//очистка памяти
void FreeMem(trainlist** FirstTrain)
{
	trainlist* temp;
	while (*FirstTrain)
	{
		temp = *FirstTrain;
		*FirstTrain = (*FirstTrain)->next;
		delete temp;
	}
}
//загрузка файла и его данных
void LoadFile(fstream& f,trainlist** First, trainlist** Last)
{
	f.open("train.dat", ios::in | ios::binary);
	if (!f) return;
	train temp;
	while (!f.eof())
	{
		if(f.read(reinterpret_cast<char*>(&temp), sizeof(train)))
		AddTrain(&(*First), &(*Last), temp);
	}
	f.close();
}
//сохранение списка в файл
void SaveFile(fstream& f, trainlist* Train)
{
	f.open("train.dat", ios::out | ios::binary);
		while (Train)
		{
			f.write(reinterpret_cast<char*>(&Train->key), sizeof(train));
			Train = Train->next;
		}
	f.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	fstream f;
	trainlist *FirstTrain = NULL, *LastTrain = NULL;
	LoadFile(f, &FirstTrain, &LastTrain);
	char key;
	do
	{
		system("cls");
		cout << "1.Add 2.PrintAll 3.Pop1st Esc.Exit" << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case '1':
			AddTrain(&FirstTrain, &LastTrain, ScanTrain());
			break;
		case '2':
			cout << "№  StPoint  EndPoint StTime EndTime Price" << endl;
			PrintTrainList(FirstTrain);
			break;
		case '3':
			PopTrain(&FirstTrain);
			break;
		}
		system("pause");
	} while (key != 27);
	SaveFile(f, FirstTrain);
	FreeMem(&FirstTrain);
	return 0;
}