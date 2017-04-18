#include <iostream>
#include <iomanip>
#include "CalcError.h"

using namespace std;
namespace CM
{
	void Ex1()
	{
		system("cls");
		double A = 4.26845000;
		cout.setf(ios::fixed);
		cout << "Задание 1:" << endl;
		cout << "A = " << A << endl;
		for (int i(6); i > 2; i--)
		{
			double a = CalcError::Round(A, i);
			double d = CalcError::delta(A, a);
			double da = CalcError::delta_a(A, a);
			double s = CalcError::sigma(A, d);
			cout << "a=" << a << endl;
			cout << "delta_a=" << da << endl;
			cout << "delta=" << d << endl;
			cout << "sigma=" << s << endl;
			cout << endl;
		}
		system("pause");
	}

	void Ex2()
	{
		system("cls");
		double A = 0.2589637;
		double d = 0.00006;
		double s = CalcError::sigma(A, d);
		cout.setf(ios::fixed);
		cout.precision(7);
		cout << "Задание 2:" << endl;
		cout << "A = " << A << endl;
		cout << "delta = " << d << endl;
		cout << "sigma = " << s << endl;
		cout << "true count = " << CalcError::TrueSimbolsNumber_A_delta(A, d) << endl;
		system("pause");
	}

	void Ex3()
	{
		system("cls");
		double A = 58.237545;
		double s = 0.00014;
		double d = CalcError::sigma_to_delta(A, s);
		cout.setf(ios::fixed);
		cout << "Задание 3:" << endl;
		cout << "A = " << A << endl;
		cout << "sigma = " << s << endl;
		cout << "delta = " << d << endl;
		cout << "true count = " << CalcError::TrueSimbolsNumber_A_sigma(A, s) << endl;
		system("pause");
	}

	void Ex4()
	{
		system("cls");
		double A = 85.12, a = 0.005, s_a = CalcError::sigma(A, a);
		double B = 48.4, b = 0.05, s_b = CalcError::sigma(B, b);
		double C = 0.5072, c = 0.00005, s_c = CalcError::sigma(C, c);
		double D = 0.12, d = 0.005, s_d = CalcError::sigma(D, d);
		double U = (A - B)*(C + D);
		double d_f1 = CalcError::delta_difference(a,b);
		double d_f2 = CalcError::delta_summ(c, d);
		double dU = CalcError::delta_multiplication(A - B, d_f1, C + D, d_f2);
		double s_f1 = CalcError::sigma_summ(A, s_a, B, s_b);
		double s_f2 = CalcError::sigma_difference(C, s_c, D, s_d);
		double sU = CalcError::sigma_multiplication(A-B, s_f1, C+D, s_f2);
		cout.setf(ios::fixed);
		cout << "Задание 4:" << endl;
		cout << "u=(a-b)(c+d)" << endl;
		cout << "a = " << A << endl;
		cout << "b = " << B << endl;
		cout << "c = " << C << endl;
		cout << "d = " << D << endl;
		cout << "U = " << U << endl;
		cout << "delta_U = " << dU << endl;
		cout << "sigma_U = " << sU << endl;
		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	CM::Ex1();
	CM::Ex2();
	CM::Ex3();
	CM::Ex4();
	return 0;
}