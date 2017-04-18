#pragma once

namespace CM
{

	class CalcError
	{
	public:
		static double delta_a(double, double);
		static double delta(double);
		static double delta(double, double);
		static double sigma(double, double);
		static double sigma_to_delta(double, double);
		static int TrueSimbolsNumber_A_delta(double, double);
		static int TrueSimbolsNumber_A_sigma(double, double);
		static double Round(double, int);
		static double delta_summ(double, double);
		static double delta_difference(double, double);
		static double delta_multiplication(double, double, double, double);
		static double delta_division(double, double, double, double);
		static double sigma_summ(double, double, double, double);
		static double sigma_difference(double, double, double, double);
		static double sigma_multiplication(double, double, double, double);
		static double sigma_division(double, double, double, double);
	};

}