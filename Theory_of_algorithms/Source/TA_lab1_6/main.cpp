#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float nleft, nright, step, k;
	cout << "¬ведите левую и правую границы:" << endl;
	cin >> nleft >> nright;
	cout << "¬ведите шаг изменени€ агрумента:" << endl;
	cin >> step;
	cout << "¬ведите коэффициент кратности:" << endl;
	cin >> k;
	freopen("output.txt", "a", stdout);
	float phi = 3.1415926 / k;
	while (nleft <= nright)
	{
		float Fn = pow(nleft, log(nleft) / 2);
		float Gn = exp(1.5*sqrt(nleft));
		float ATg_FG = atan(Fn / Gn);
		float ATg_GF = atan(Gn / Fn);
		float pi = ATg_FG - ATg_GF;
		
		cout << nleft << ' ' << Fn << ' ' << Gn << ' ' << ATg_FG << ' ' << ATg_GF
		<< ' ' << pi << ' ' << phi - pi << ' ' << abs(pi) - phi << ' ' << pi + phi << endl;
		nleft += step;
	}
	cout << endl;
	fclose(stdout);
	return 0;
}