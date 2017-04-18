#include <iostream>
#include <iomanip> 
#include <cstdio>  
#define Pi (3.1415926)

int main()
{
	setlocale(LC_ALL, "Rus"); //����������� ���������
	double x, a, b;	//��������� ������� ��-�
	double z;		//����������� �-���
	//	printf("������� �, a, b:\n");
	//	scanf_s("%e,%e,%e", &x,&a,&b);
	std::cout << "������� �, a, b:" << std::endl;
	std::cin >> x >> a >> b;
	//������� �������
	if (x <= a) //���. 1 ��-�
		z = abs(pow(x, 5.7 / x) - pow(atan(x) *
		180 / Pi, 0.2) + sin((x*x)*Pi / 180));
	else
		if (x >= b) //���. 3 ��-�
			z = (1 + 2 * x*x + 3 * x*x*x)*sinh(pow(x, pow(x, 1.5) + 7.3));
		else
			if (x > 0) //���. 2 ��-�
				z = log(exp(x*x) + x*log10(x) + cos(x*Pi / 180));
			else
			{
				std::cout << "��� ������." << std::endl;
				//printf("��� ������.");
				system("pause");
				return 0;
			}				
	//���������������� ����� ����� � ��������� �������
	std::cout.setf(std::ios::scientific);
	std::cout.precision(2);
	std::cout << "z = " << z << std::endl;
	//printf("z = %.2e\n", z);
	system("pause");
	return 0;
}