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
//������ � ������
struct train
{
	int number; //����� ������
	char StPoint[8]; //����� �����������
	char EndPoint[8]; //����� ��������
	Time StTime;	//����� �����������
	Time EndTime;	//����� ��������
	unsigned int Price; //��������� ������
};
//������� ������ ������
struct trainlist
{
	train key;
	trainlist* next;
};
//���������� ������ ������
train ScanTrain()
{
	train Train;
	cout << "������� ����� ������:" << endl;
	cin >> Train.number;
	cout << "������� ����� ��������:" << endl;
	cin >> Train.StPoint;
	cout << "������� ����� ��������:" << endl;
	cin >> Train.EndPoint;
	cout << "������� ����� ��������:" << endl;
	cin >> Train.StTime.hour >> Train.StTime.minute;
	cout << "������� ����� ��������:" << endl;
	cin >> Train.EndTime.hour >> Train.EndTime.minute;
	cout << "������� ��������� ������:" << endl;
	cin >> Train.Price;
	return Train;
}
//����� ������ � ������
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
//���������� ������ ������ � ����� ������
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
//����� ������ �������
void PrintTrainList(trainlist* Train)
{
	if (!Train)
	{
		cout << "������ ����" << endl;
		return;
	}
	while (Train)
	{
		PrintTrain(Train->key);
		Train = Train->next;
	}
}
//�������� ������� ��-�� ������
void PopTrain(trainlist** FirstTrain)
{
	if (!*FirstTrain)
	{
		cout << "������� ���." << endl;
		return;
	}
	trainlist* temp;
	temp = *FirstTrain;
	*FirstTrain = (*FirstTrain)->next;
	cout << "����� " << temp->key.StPoint << '-'
		<< temp->key.EndPoint << " ���������." << endl;
	delete temp;
}
//������� ������
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
//�������� ����� � ��� ������
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
//���������� ������ � ����
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
			cout << "�  StPoint  EndPoint StTime EndTime Price" << endl;
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