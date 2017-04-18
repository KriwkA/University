#include <iostream>
#include <ctime>

using namespace std;

//������������� � ���� ��������� �������
int** Init_matrix(const int& n, const int& m)
{
	int **arr = new int*[n];			// ��������� ������ ��� ������
	for (int i(0); i < n; i++)
	{
		arr[i] = new int[m];
		for (int j(0); j < m; j++)
			cin >> arr[i][j];
	}
	return arr;
}

//�������� ������� �� ������
void Free_mem(int **arr, const int& n)
{
	for (int i(0); i < n; i++)
		delete[] arr[i];
	delete[] arr;
}

//����� ���������� ������������� ��������� � ������� �������
void Print_Negative(int** arr, const int& n, const int& m)
{
	bool Enable = false; //������� ������� �����
	for (int i(0); i < n; i++) //����� ������� �����
	{
		bool flag = false;
		unsigned int counter = 0; //������� ���. ��-���
		for (int j(0); j < m; j++)
		{
			if (arr[i][j] < 0) counter++;
			if (arr[i][j] == 0) flag = true;
		}
		if (flag)
		{
			Enable = true;
			cout << "� ������� ������ " << i+1 << ' '
			<< counter << " ������������� �����." << endl;
		}
	}
	if (!Enable)
		cout << "������� ����� ���." << endl;
}

//���������� ������������ �������� � ��������������� ������
int MinInStr(int* arr, const int& n)
{
	int min = arr[0];
	for (int i(1); i < n; i++)
		if (min>arr[i]) min = arr[i];
	return min;
}

//����� �������� ����� �������
void Print_Saddles(int** arr, const int& n, const int& m)
{
	bool Enable = false; //������� �������� �����
	int* max_in_col = new int[n]; //������ ����. ��-��� ��������
	int* min_in_str = new int[m]; //������ ���. ��-��� �����
	for (int i(0); i < n; i++)    
		min_in_str[i] = MinInStr(arr[i], m);
	for (int j(0); j < m; j++)
	{
		max_in_col[j] = arr[0][j];
		for (int i(1); i < n; i++)
			if (max_in_col[j] < arr[i][j]) max_in_col[j] = arr[i][j];
	}
	for (int i(0); i < n; i++) //����� �������� �����
		for (int j(0); j < m; j++) 
			if (min_in_str[i] == max_in_col[j])
			{
				Enable = true;
				cout << "�������� �����: " << i+1 << ' ' << j+1 << endl;
			}
	if (!Enable)
		cout << "�������� ����� ���" << endl;
	delete[] max_in_col; //�������� ��������
	delete[] min_in_str;
}

// ������� main
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian"); //����������� ���������
	int n, m; // ������� �������
	cout << "������� ������� �������:" << endl;
	cin >> m >> n;
	cout << "������� ������� NxM:" << endl;
	int** arr=Init_matrix(n,m);  // ��������� �������
	Print_Negative(arr, n, m);
	Print_Saddles(arr, n, m);
	Free_mem(arr,n);
	system("pause");
	return 0;
}