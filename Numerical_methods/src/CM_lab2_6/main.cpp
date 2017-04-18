#include <iostream>
#include <iomanip>

using namespace std;

void PrintSumm(double epsilon)
{
	cout.setf(ios::fixed);
	int n = 1;
	double S = 0;
	double Sn = 19 / 64.0;
	double a=0;
	do
	{
		a = 1.0 / (n*(4 * n + 1));
		S += a;
		n++;
	}
	while (n<=25000);
	cout << "Сумма ряда: S = " << setprecision(7) << S << endl;
	cout << "Кол-во слагаемых: n = "<< n - 1 << endl;
	n = 1;
	do
	{
		a = 21.0 / (16 * n*(n + 1)*(n + 2)*(4 * n + 1));
		Sn += a;
		n++;
	} 
	while (n <= 22);
	cout << "Сумма улучшенного ряда: S = " << setprecision(7) << Sn << endl;
	cout << "Кол-во слагаемых: n = "  << n - 1 << endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	PrintSumm(0.00001);
	system("pause");
	return 0;
}