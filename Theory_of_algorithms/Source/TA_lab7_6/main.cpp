#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a,int b)
{
	if (a>b)
		swap(a, b);
	while (a)
	{
		b %= a;
		if (a>b)
			swap(a, b);
	}
	return b;
}

int searchXY(const int a, const int b,const int d, int& x_, int& y_)
{
	double x;
	for (int i(-1); i > -100000; i--)
	{
		x = double(d*i - b) / (a*i);
		if (x == int(x))
		{
			y_ = i;
			x_ = x;
			return 1;
		}
		if (d - a*i)
		{
			x = double(b) / (d-a*i);
			if (x == int(x))
			{
				y_ = x;
				x_ = i;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, d, x, y;
	cout << "Введите a,b" << endl;
	cin >> a >> b;
	d = gcd(a,b);
	cout << "НОД = " << d << endl;
	if (searchXY(a, b, d, x, y))
		cout << "x = " << x << " y = " << y << endl;
	else
		cout << "x и y не найдены." << endl;
	system("pause");
	return 0;
}