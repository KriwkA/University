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
struct Train
{
	int number;
	char StPoint[8];
	char EndPoint[8];
	Time StTime;
	Time EndTime;
	int Price;
};
//��������� ������
struct TrainTree
{
	Train key;
	TrainTree* left;
	TrainTree* right;
};
//���������� ������ � ������
Train ScanTrain()
{
	Train Train;
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
void PrintTrain(const Train Train)
{
	cout.setf(ios::left);
	cout << setw(3) << Train.number;
	cout << setw(9) << Train.StPoint;
	cout << setw(9) << Train.EndPoint;
	cout << setw(2) << Train.StTime.hour << ':' << setw(4) << Train.StTime.minute;
	cout << setw(2) << Train.EndTime.hour << ':' << setw(5) << Train.EndTime.minute;
	cout << Train.Price << endl;
}

//������� ������� ������
void DeleteTree(TrainTree* node)
{
	if (!node) return;
	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
}

//���������� ������ ���� � ������
TrainTree* AddNode(TrainTree* node, const Train NewTrain)
{
	if (!node)
	{
		node = new TrainTree;
		node->key = NewTrain;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if (node->key.number > NewTrain.number)
		node->left = AddNode(node->left, NewTrain);
	else
		node->right = AddNode(node->right, NewTrain);
	return node;
}
//����� ������
void PrintTree(TrainTree* node)
{
	if (!node) return;
	PrintTree(node->left);
	PrintTrain(node->key);
	PrintTree(node->right);
}
//����������� ��������� ������
void PrintTreeStruct(TrainTree* node, int level)
{
	if (!node) return;
	PrintTreeStruct(node->right, level + 1);
	cout << setw((level+1) * 4) << node->key.number << endl;
	PrintTreeStruct(node->left, level + 1);
}
//���������� ����� n ������
int NodeCount(TrainTree* node, int level)
{
	if (!node || level < 1) return 0;
	if (level == 1) return 1;
	if (level > 1)
		return NodeCount(node->left, level - 1) + NodeCount(node->right, level - 1);
	
}
//�������� ����
void DeleteNode(TrainTree** node, int number)
{
	if (!(*node)) return;
	if ((*node)->key.number > number)
	{
		DeleteNode(&(*node)->left, number);
		return;
	}
	else  if ((*node)->key.number < number)
	{
		DeleteNode(&(*node)->right, number);
		return;
	}
	TrainTree* left = (*node)->left;
	TrainTree* right = (*node)->right;
	delete *node;
	if (!left) *node = right;
	else if (!right) *node = left;
	else
	{
		*node = left;
		while (left->right) left = left->right;
		left->right = right;
	}
}
//�������� �����
void LoadFile(fstream& f, TrainTree** root)
{
	f.open("train.dat", ios::in | ios::binary);
	if (!f) return;
	Train temp;
	while (!f.eof())
	{
		if (f.read(reinterpret_cast<char*>(&temp), sizeof(Train)))
			*root = AddNode(*root, temp);
	}
	f.close();
}
//������ � ����
void PrintToFile(fstream& f, TrainTree* node)
{
	if (!node) return;
	f.write(reinterpret_cast<char*>(&node->key), sizeof(Train));
	PrintToFile(f, node->left);
	PrintToFile(f, node->right);
}
//���������� �����
void SaveFile(fstream& f, TrainTree* root)
{
	f.open("train.dat", ios::out | ios::binary);
	PrintToFile(f, root);
	f.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	fstream f;
	TrainTree* root = NULL;
	LoadFile(f, &root);
	char key;
	int n=0;
	do
	{
		system("cls");
		cout << "1.AddNode" << endl;
		cout << "2.PrintTree" << endl;
		cout << "3.PrintTreeStruct" << endl;
		cout << "4.NodeCount" << endl;
		cout << "5.DeleteNode" << endl;
		cout << "Esc.Exit" << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case '1':
			root = AddNode(root, ScanTrain());
			break;
		case '2':
			cout << "�  StPoint  EndPoint StTime EndTime Price" << endl;
			PrintTree(root);
			break;
		case '3':
			PrintTreeStruct(root, 0);
			break;
		case '4':
			cout << "������� � ������:" << endl;
			cin >> n;
			cout << NodeCount(root, n) << endl;
			break;
		case '5':
			cout << "������� � ������:" << endl;
			cin >> n;
			DeleteNode(&root, n);
			break;
		}
		system("pause");
	} while (key != 27);
	SaveFile(f, root);
	DeleteTree(root);
	return 0;
}