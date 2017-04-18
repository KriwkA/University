#include <iostream>
#include <iomanip> 
#include <cstdio>  
#include <conio.h>
#define Pi 3.1415926

int main()
{
	setlocale(LC_ALL, "Russian"); //отображение кириллицы



	double x_begin, x_end;
	double dx;
	double a, b, z;
	//форматы вывода
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.setf(std::ios::left);
	std::cout.precision(2);
	std::cout << "Введите Xнач, Xкон, dx, a, b:" << std::endl;
	std::cin >> x_begin >> x_end >> dx >> a >> b;

	for (double x(x_begin); x <= x_end; x += dx)
	{
		if (x >= b) // 3 ур-е
			z = (1 + 2 * x*x + 3 * x*x*x)*sinh(pow(x, pow(x, 1.5) + 7.3));
		else
			if (x != 0) // наличие корней
				if (x <= a) //1 ур-е
					z = abs(pow(x, 5.7 / x) - pow(atan(x) *
					180 / Pi, 0.2) + sin((x*x)*Pi / 180));
				else //2 ур-е
					z = log(exp(x*x) + x*log10(x) + cos(x*Pi / 180));
			else 
			{
				std::cout << std::setw(10) << x << "Нет корней" << std::endl;
				continue;
			}
		std::cout << std::setw(10) << x << z << std::endl;
	}

	system("pause");
	return 0;
}