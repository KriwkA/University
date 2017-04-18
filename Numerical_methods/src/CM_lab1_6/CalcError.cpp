#include "CalcError.h"
#include <math.h>
#include <string>
#include <iostream>

namespace CM
{
	double CalcError::Round(double a, const int n)
	{
		a *= pow(10.0, n);
		a = round(a+0.0000000001);
		return a*pow(10.0, -n);
	}

	double CalcError::delta(double A, double a)
	{
		return abs(A-a);
	}

	double CalcError::delta(double da)
	{
		return abs(da);
	}

	double CalcError::sigma_to_delta(double A, double s)
	{
		return s*abs(A);
	}

	double CalcError::delta_a(double A, double a)
	{
		return A - a;
	}

	double CalcError::sigma(double A, double d)
	{
		return (d/abs(A));
	}

	int CalcError::TrueSimbolsNumber_A_delta(double a, double d)
	{
		int true_count = 0;
		bool f = false;
		std::string A = std::to_string(a);
		std::string t1 = std::to_string(a+d);
		std::string t2 = std::to_string(a-d);
		for (int i(0); i < A.length(); i++)
		{
			if (A[i] == t1[i] && A[i] == t2[i] && f) true_count++;
			if ((A[i] != t1[i] || A[i] != t2[i]) && f) break;
			if (A[i] == '.') f=true;
		}
		return true_count;
	}

	int CalcError::TrueSimbolsNumber_A_sigma(double a, double s)
	{
		double d = s*abs(a);
		return TrueSimbolsNumber_A_delta(a, d);
	}

	double CalcError::delta_summ(double da, double db)
	{
		return da + db;
	}

	double CalcError::delta_difference(double da, double db)
	{
		return da + db;
	}

	double CalcError::delta_multiplication(double a, double da, double b, double db)
	{
		return abs(abs(b)*da + abs(a)*db);
	}

	double CalcError::delta_division(double a, double da, double b, double db)
	{
		return da / abs(b) - abs(a)*db / (b*b);
	}

	double CalcError::sigma_summ(double x, double sx, double y, double sy)
	{
		return abs(x/(x+y))*sx + abs(y/(x+y))*sy;
	}

	double CalcError::sigma_difference(double x, double sx, double y, double sy)
	{
		return abs(x / (x - y))*sx + abs(y / (x - y))*sy;
	}
	
	double CalcError::sigma_multiplication(double x, double sx, double y, double sy)
	{
		return sx+sy;
	}
}