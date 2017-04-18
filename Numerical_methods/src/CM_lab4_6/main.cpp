#include <iostream>
#include <iomanip>
#include "Matrix.h"

std::vector<double> Kramer(const Matrix<double>& _A, 
							const std::vector<double>& _b)
{
	double D = _A.determinant();
	size_t n = _A.heigh();
	Matrix<double> A;
	std::vector<double> answer;
	std::vector<double> b(_b);
	for (size_t i = 0; i < n; i++)
	{
		A = _A;
		A.set_col(i, b);
		answer.push_back(A.determinant() / D);
	}
	return answer;
}

std::vector<double> Gauss(Matrix<double> A, 
							const std::vector<double>& b)
{
	size_t n = A.heigh();
	std::vector<double> answer(n);
	double temp;
	A.push_right(b);
	for (size_t i = 0; i < n - 1; i++)			//прямой ход
		for (size_t j = i + 1; j < n; j++)
			for (size_t k = n; k > i; k--)
				A[j][k] = A[i][k] * A[j][i] - A[j][k] * A[i][i];
	for (size_t i = n - 1; i != size_t(-1); i--)		//обратный ход
	{
		temp = 0;
		for (size_t j = i + 1; j < n; j++)
			temp += answer[j] * A[i][j];
		answer[i] = (A[i][n] - temp) / A[i][i];
	}
	return answer;
}

std::vector<double> Cholesky(const Matrix<double>& _A, 
								const std::vector<double>& _b)
{
	size_t n = _A.heigh();
	Matrix<double> B;
	Matrix<double> C;
	_A.choleskyUL(B, C);
	std::vector<double> y(3);
	for (size_t i = 0; i < n; i++)
	{
		y[i] = _b[i];
		for (size_t j = 0; j < i; j++)
			y[i] -= B[i][j] * y[j];
		y[i] /= B[i][i];
	}
	std::vector<double> answer(n);
	for (size_t i = n-1; i != size_t(-1); i--)
	{
		answer[i] = y[i];
		for (size_t j = i + 1; j < n; j++)
			answer[i] -= C[i][j] * answer[j];
	}
	return answer;
}

std::vector<double> Gauss_Jordan(Matrix<double> A, 
								const std::vector<double>& _b)
{
	size_t n = A.heigh();
	std::vector<double> answer;
	A.push_right(_b);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
			for (size_t k = n; k > i; k--)
				A[j][k] = A[i][k] * A[j][i] - A[j][k] * A[i][i];
		for (size_t j = i - 1; j != size_t(-1); j--)
			for (size_t k = n; k != size_t(-1); k--)
				A[j][k] = A[i][k] * A[j][i] - A[j][k] * A[i][i];
	}
	for (size_t i = 0; i < n; i++)
		answer.push_back(A[i][n] / A[i][i]);
	return answer;
}

int main()
{
	setlocale(LC_ALL, "Russian");	
	Matrix<double> A =
	{
		{ 19.17, -4.5, 4.83 },
		{ -4.5, 4.83, -0.5 },
		{ 4.83, -0.5, 1 }
	};
	std::vector<double> b = { -3.217, 4.217, -1.983 };

	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << '|';
		for (size_t j = 0; j < 3; j++)
			std::cout<< std::setw(7) << A[i][j] <<' ';
		std::cout << "|  |" << std::setw(7) << b[i] << " |" << std::endl;
	}
	std::cout.precision(8);
	std::cout << "Метод Крамера:" << std::endl;
	std::vector<double> answer = Kramer(A, b);
	for (size_t i = 0; i < answer.size();i++)
		std::cout << "X" << i << " = " << answer[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Метод Гаусса:" << std::endl;
	answer = Gauss(A, b);
	for (size_t i = 0; i < answer.size(); i++)
		std::cout << "X" << i << " = " << answer[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Метод Холецкого:" << std::endl;
	answer = Cholesky(A, b);
	for (size_t i = 0; i < answer.size(); i++)
		std::cout << "X" << i << " = " << answer[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Метод Жордана:" << std::endl;
	answer = Gauss_Jordan(A, b);
	for (size_t i = 0; i < answer.size(); i++)
		std::cout << "X" << i << " = " << answer[i] << std::endl;
	system("pause");
	return 0;
}