#include <iostream>
#include <ctime>

using namespace std;

//Инициализация и ввод элементов матрицы
int** Init_matrix(const int& n, const int& m)
{
	int **arr = new int*[n];			// выделение памяти под массив
	for (int i(0); i < n; i++)
	{
		arr[i] = new int[m];
		for (int j(0); j < m; j++)
			cin >> arr[i][j];
	}
	return arr;
}

//удаление матрицы из памяти
void Free_mem(int **arr, const int& n)
{
	for (int i(0); i < n; i++)
		delete[] arr[i];
	delete[] arr;
}

//Вывод количества отрицательных элементов в нулевых строках
void Print_Negative(int** arr, const int& n, const int& m)
{
	bool Enable = false; //наличие нулевых строк
	for (int i(0); i < n; i++) //поиск нулевых строк
	{
		bool flag = false;
		unsigned int counter = 0; //счетчик отр. эл-тов
		for (int j(0); j < m; j++)
		{
			if (arr[i][j] < 0) counter++;
			if (arr[i][j] == 0) flag = true;
		}
		if (flag)
		{
			Enable = true;
			cout << "В нулевой строке " << i+1 << ' '
			<< counter << " отрицательных чисел." << endl;
		}
	}
	if (!Enable)
		cout << "Нулевых строк нет." << endl;
}

//нахождение минимального элемента в несортированной строке
int MinInStr(int* arr, const int& n)
{
	int min = arr[0];
	for (int i(1); i < n; i++)
		if (min>arr[i]) min = arr[i];
	return min;
}

//вывод седловых точек матрицы
void Print_Saddles(int** arr, const int& n, const int& m)
{
	bool Enable = false; //наличие седловых точек
	int* max_in_col = new int[n]; //массив макс. эл-тов столбцов
	int* min_in_str = new int[m]; //массив мин. эл-тов строк
	for (int i(0); i < n; i++)    
		min_in_str[i] = MinInStr(arr[i], m);
	for (int j(0); j < m; j++)
	{
		max_in_col[j] = arr[0][j];
		for (int i(1); i < n; i++)
			if (max_in_col[j] < arr[i][j]) max_in_col[j] = arr[i][j];
	}
	for (int i(0); i < n; i++) //поиск седловых точек
		for (int j(0); j < m; j++) 
			if (min_in_str[i] == max_in_col[j])
			{
				Enable = true;
				cout << "Седловая точка: " << i+1 << ' ' << j+1 << endl;
			}
	if (!Enable)
		cout << "Седловых точек нет" << endl;
	delete[] max_in_col; //удаление массивов
	delete[] min_in_str;
}

// функция main
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian"); //отображение кириллицы
	int n, m; // размеры матрицы
	cout << "Введите размеры матрицы:" << endl;
	cin >> m >> n;
	cout << "Введите матрицу NxM:" << endl;
	int** arr=Init_matrix(n,m);  // двумерная матрица
	Print_Negative(arr, n, m);
	Print_Saddles(arr, n, m);
	Free_mem(arr,n);
	system("pause");
	return 0;
}