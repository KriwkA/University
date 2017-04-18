#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#define PI 3.1415926

void arctg(const double x, const double e, double& f, int& n)
{
	double nTerm = -1.0 / x;
	f = PI / 2 + nTerm;
	n = 0;
	do
	{
		n++;
		nTerm *= -(2 * n - 1) / ((2 * n + 1)*x*x);
		f += nTerm;
	} while (abs(nTerm) >= e);
}

void firstEx()
{
	system("cls");
	cout << "Задание 1:" << endl << endl;
	double x = 1.4;
	double f;
	int n;
	arctg(x, 0.00005, f, n);
	cout << "е = 0.00005 N = " << n << endl;
	cout << "Arctg(1.4) = " << setprecision(6) << f << endl << endl;
	arctg(x, 0.000000001, f, n);
	cout << "е = 0.000000005 N = " << n << endl;
	cout << "Arctg(1.4) = " << setprecision(10) << f << endl << endl;
	cout << "Табл. значение: " << endl;
	cout << "Arctg(1.4) = " << setprecision(10) << atan(x) << endl;
	system("pause");
}

double exp(const double x, const double e)
{
	double f = 1;
	double nTerm = 1;
	int n = 0;
	do
	{
		n++;
		nTerm *= -x / n;
		f += nTerm;
	} while (abs(nTerm) >= e);
	return f;
}

void secondEx()
{
	system("cls");
	cout << "Задание 2:" << endl << endl;
	cout.setf(ios::left);
	cout.precision(10);
	cout << "x         e^(-x)    e^(-x)табл." << endl;
	for (int i = 0; i < 16; i++)
	{
		double x = 0.505 + 0.005*i;

		cout << setw(10) << x;
		cout << setprecision(6) << exp(x, 0.00005) << "  ";
		cout << setprecision(6) << exp(-x) << endl; 
	}
	system("pause");
}

void thirdEx()
{
	system("cls");
	cout << "Задание 3:" << endl << endl;
	unsigned long long fac;
	cout.setf(ios::fixed);
	for (int i = 10; i <= 20; i++)
	{
		fac = pow(i, i)/exp(i)*sqrt(2 * PI*i)*(1 + 1.0/(12*i)+1.0/(288*i*i)-
			139.0/(51810*i*i*i)-571.0/(2488320*i*i*i*i));
		cout << i << "! = " << fac << endl;
	}
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	firstEx();
	secondEx();
	thirdEx();
	return 0;
}