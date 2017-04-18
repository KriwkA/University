#include <iostream>
#include <iomanip>

using namespace std;
//������ �������
void ScanArray(double *a, const int n)
{
	cout << "������� ������:" << endl;
	for (int i(0); i < n; i++)
		cin >> a[i];
}
//����� �������
void PrintArray(double *a, const int n)
{
	cout << "������:" << endl;
	for (int i(0); i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
//����� 3-� ������ ������ ������������� ���������
bool ThreeNegative(double *a, const int n)
{
	for (int i(0); i < n - 2; i++)
		if (a[i] < 0 && a[i + 1 < 0 && a[i + 2] < 0]) return true;
	return false;
}
//���������� ���������� � ������ ����� � �������
double Int_near(double *a, const int p, const int n)
{
	double nearest = a[p-1];
	for (int i(p); i < n; i++)
		if (abs(round(a[i]) - a[i]) < abs(round(nearest) - nearest))
			nearest = a[i];
	return nearest;
}
//��������� ���������
void Sort_Bubble(double *a, const int p, const int n)
{
	double temp;
	for (int j(n-1); j > p - 1; j--)
		for (int i(p - 1); i < j; i++)
			if (a[i] > a[i + 1]) //�����
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int p, q, n; 
	cout << "������� p, q, n:" << endl;
	cin >> p >> q >> n;
	double *a = new double[n];
	ScanArray(a, n); 
	cout.setf(ios::boolalpha);
	cout << "������� 3� ������������� ��������� �� ���������� 1-q: " << ThreeNegative(a, q) << endl;
	cout << "��������� � ������ �� ���������� p-q: " << Int_near(a, p, q) << endl;
	Sort_Bubble(a, p, n);
	PrintArray(a, n);
	system("pause");
	return 0;
}