#include <iostream>
#include <iomanip> 
#include <cstdio>  
#define Pi (3.1415926)

int main()
{
	setlocale(LC_ALL, "Rus"); //отображение кириллицы
	double x, a, b;	//параметры системы ур-й
	double z;		//вычисл€ема€ ф-ци€
	//	printf("¬ведите х, a, b:\n");
	//	scanf_s("%e,%e,%e", &x,&a,&b);
	std::cout << "¬ведите х, a, b:" << std::endl;
	std::cin >> x >> a >> b;
	//решение системы
	if (x <= a) //выч. 1 ур-€
		z = abs(pow(x, 5.7 / x) - pow(atan(x) *
		180 / Pi, 0.2) + sin((x*x)*Pi / 180));
	else
		if (x >= b) //выч. 3 ур-€
			z = (1 + 2 * x*x + 3 * x*x*x)*sinh(pow(x, pow(x, 1.5) + 7.3));
		else
			if (x > 0) //выч. 2 ур-€
				z = log(exp(x*x) + x*log10(x) + cos(x*Pi / 180));
			else
			{
				std::cout << "Ќет корней." << std::endl;
				//printf("Ќет корней.");
				system("pause");
				return 0;
			}				
	//экспотенциальный вывод чисел с плавающей зап€той
	std::cout.setf(std::ios::scientific);
	std::cout.precision(2);
	std::cout << "z = " << z << std::endl;
	//printf("z = %.2e\n", z);
	system("pause");
	return 0;
}