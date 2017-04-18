#include <iomanip> //для setpresition()
#include <fstream> //для файлового ввода вывдода
#include <ctime>   //time(NULL), для организации рандома

using namespace std;


//функция нахождения индекса минимального значения в массиве
void MinInArray(int& imin, const int& n,const int *a, int& count)
{
	for (int i(0); i < n; i++)	// цикл перебора эл-тов массива
		if (a[i] < a[imin])		// сравнение эл-тов
		{
			imin = i;		
			count++;			//щетчик оп-ций переприсваивания
		}
}

// основная функция программы
int main()
{
	setlocale(LC_ALL, "Russian");	//отбр. кириллицы
	srand(time(NULL));				//вкл. псевдорандома
	ofstream fout("TA_lab2.txt", ios_base::app); //привязка файла

	int *a;
	int b[3] = { 100, 1000, 2000 }; //массив хранящий длинну основного массива
	for (int j(0); j < 3; j++)		//цикл смены массивов и их длинн
	{
		a = new int[b[j]];			//выделение памяти под массив
		fout << "Массив состоит из " << b[j] << " элементов." << endl;
		for (int i(0); i < b[j]; i++) //цикл заполнения массива
		{
			a[i] = rand() % 801;
			fout << a[i] << ' ';
		}
		int count = 0;	//cчетчик переприсваиваний
		int imin = 0;	//индекс мин. эл-та массива
		MinInArray(imin, b[j], a, count); //поиск imin
		fout << endl;
		fout << "Мин. элемент массива: " << a[imin] << endl;
		fout << "Кол-во переприсваиваний при поиске:" << count << endl;
		fout << setprecision(2) << "n-е гармоничное число: Hn=" << log(b[j]) + 0.57 << endl;
		fout << endl;
		delete [] a;	//удаление массива из памяти
	}

	system("pause");
	return 0;
}