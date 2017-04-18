#include <iomanip> //��� setpresition()
#include <fstream> //��� ��������� ����� �������
#include <ctime>   //time(NULL), ��� ����������� �������

using namespace std;


//������� ���������� ������� ������������ �������� � �������
void MinInArray(int& imin, const int& n,const int *a, int& count)
{
	for (int i(0); i < n; i++)	// ���� �������� ��-��� �������
		if (a[i] < a[imin])		// ��������� ��-���
		{
			imin = i;		
			count++;			//������ ��-��� ����������������
		}
}

// �������� ������� ���������
int main()
{
	setlocale(LC_ALL, "Russian");	//����. ���������
	srand(time(NULL));				//���. �������������
	ofstream fout("TA_lab2.txt", ios_base::app); //�������� �����

	int *a;
	int b[3] = { 100, 1000, 2000 }; //������ �������� ������ ��������� �������
	for (int j(0); j < 3; j++)		//���� ����� �������� � �� �����
	{
		a = new int[b[j]];			//��������� ������ ��� ������
		fout << "������ ������� �� " << b[j] << " ���������." << endl;
		for (int i(0); i < b[j]; i++) //���� ���������� �������
		{
			a[i] = rand() % 801;
			fout << a[i] << ' ';
		}
		int count = 0;	//c������ ����������������
		int imin = 0;	//������ ���. ��-�� �������
		MinInArray(imin, b[j], a, count); //����� imin
		fout << endl;
		fout << "���. ������� �������: " << a[imin] << endl;
		fout << "���-�� ���������������� ��� ������:" << count << endl;
		fout << setprecision(2) << "n-� ����������� �����: Hn=" << log(b[j]) + 0.57 << endl;
		fout << endl;
		delete [] a;	//�������� ������� �� ������
	}

	system("pause");
	return 0;
}