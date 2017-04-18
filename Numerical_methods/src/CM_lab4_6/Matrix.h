#pragma once
#include <vector>
#include <cmath>

template < class T > 
class Matrix
{
private:
	std::vector<std::vector<T>> matrix_;
	size_t nRow_;
	size_t nCol_;
public:
	//класс обработки исключений
	class bad_Matrix
	{
	private:
		char* error_;
	public:
		bad_Matrix() :error_("unknown"){};

		bad_Matrix(char* error)
		{
			error_ = error;
		}

		bad_Matrix(const bad_Matrix& e)
		{
			error_ = e.what();
		}

		char* what() const
		{
			return error_;
		}
	};

	//конструктор по умолчанию
	Matrix() 
	{
		nRow_ = 0;
		nCol_ = 0;
	}

	//конструктор с размерами
	Matrix(const size_t& heigh, const size_t& width) 
	{

		if (heigh*width <= this->max_size())
		{
			nRow_ = heigh;
			nCol_ = width;
			matrix_ = std::vector<std::vector<T>>(nRow_);
			for (size_t i = 0; i < nRow_; i++)
				matrix_[i] = std::vector<T>(nCol_);
		}
		else
			throw bad_Matrix("matrix<T> too long");
		
	} 

	//конструктор копирования
	Matrix(const Matrix& matrixToCopy) 
	{
		nRow_ = matrixToCopy.heigh();
		nCol_ = matrixToCopy.width();
		matrix_ = std::vector<std::vector<T>>(nRow_);
		for (size_t i = 0; i < nRow_; i++)
			matrix_[i] = std::vector<T>(nCol_);
		for (size_t i = 0; i < nRow_; i++)
			for (size_t j = 0; j < nCol_; j++)
				matrix_[i][j] = matrixToCopy.matrix_[i][j];
	}

	// конструктор для инициализированной матрицы
	Matrix(const std::initializer_list<std::initializer_list<T>>& matrix) 
	{
		nRow_ = 0;
		nCol_ = 0;
		matrix_ = std::vector<std::vector<T>>(matrix.size());
		for (auto i : matrix)
		{
			for (auto j : i)
				matrix_[nRow_].push_back(j);
			if (matrix_[nRow_].size() > nCol_)
				nCol_ = matrix_[nRow_].size();
			nRow_++;
		}
		for (auto i : matrix_)
			if (i.size() < nCol_)
				i.resize(nCol_);
	}

	//деструктор
	~Matrix(){} 

	//возвращает кол-во строк
	size_t heigh() const
	{
		return nRow_;
	}

	//возвращает кол-во столбцов
	size_t width() const
	{
		return nCol_;
	}

	//вовращает максимальное кол-во элементов матрицы
	size_t max_size() const
	{
		std::vector<T> temp;
		return temp.max_size();
	}

	//изменение размера матрицы
	void resize(const size_t& heigh, const size_t& width) 
	{
		if (heigh == nRow_ && width == nCol_)
			return;
		else
			if (heigh*width < this->max_size())
			{
				nRow_ = heigh;
				nCol_ = width;
				matrix_.resize(nRow_);
				for (size_t i = 0; i < nRow_; i++)
					matrix_[i].resize(nCol_);
			}
			else
				throw bad_Matrix("matrix<T> too long");
	}

	//возвращает колонку number в виде вектора
	std::vector<T> get_col(const size_t& number) const 
	{
		if (number < nCol_)
		{
			std::vector<T> col(nRow_);
			for (size_t i = 0; i < nRow_; i++)
				col[i] = matrix_[i][number];
			return col;
		}
		else
			throw bad_Matrix("out of range");
	}

	//возвращает столбец number в виде вектора
	std::vector<T> get_row(const size_t& number) const 
	{
		if (number < nCol_)
			return matrix_[number];
		else
			throw bad_Matrix("out of range");
	}

	//заменяет столбец col вектором colToSet
	void set_col(const size_t& col, const std::vector<T>& colToSet)
	{
		size_t nAdded = colToSet.size();
		if (nAdded == nRow_)
		{
			for (size_t i = 0; i < nRow_; i++)
				matrix_[i][col] = colToSet[i];
		}
		else
			throw bad_Matrix("length of set vector are not equal to the heigh of matrix");
	}

	//заменяет строку row вектором rowToSet
	void set_row(const size_t& row, const std::vector<T>& rowToSet)
	{
		size_t nAdded = colToSet.size();
		if (nAdded == nCol_)
				matrix_[i] = rowToSet;
		else
			throw bad_Matrix("length of set vector are not equal to the heigh of matrix");
	}

	//удаляет колонку nubmer
	void delete_col(const size_t& number)
	{
		if (number < nCol_)
		{
			nCol_--;
			for (size_t i = 0; i < nRow_; i++)
				matrix_[i].erase(matrix_[i].begin() + number);
			if (matrix_[0].size() == 0)
			{
				nRow_ = 0;
				matrix_.erase(matrix_.begin(), matrix_.end());
			}
		}
		else
			throw bad_Matrix("out of range");
	}
	
	//удаляет  строку nubmer
	void delete_row(const size_t& number)
	{
		if (number < nRow_)
		{
			matrix_.erase(matrix_.begin() + number);
			nRow_--;
			if (nRow_ == 0)
				nCol_ = 0;
		}
		else
			throw bad_Matrix("out of range");
	}

	//добавляет столбцы принимаемой матрицы в правую часть данной
	void push_right(const Matrix<T>& colToAdd)
	{
		size_t nAdded = colToAdd.heigh();
		if (nAdded == nRow_)
		{
			size_t mAdded = colToAdd.width();
			size_t mOld = nCol_;
			this->resize(nRow_, nCol_ + mAdded);
			for (size_t i = 0; i < nRow_; i++)
				for (size_t j = 0; j < mAdded; j++)
					matrix_[i][mOld + j] = colToAdd[i][j];
		}
		else
			if (nRow_ == 0)
				(*this) = colToAdd;
			else
				if (nAdded != 0)
			throw bad_Matrix("heigh of added and this matrices are not equal");
	}

	//добавляет столбец элементов в виде вектора справа данной матрицы
	void push_right(const std::vector<T>& colToAdd)
	{
		size_t nAdded = colToAdd.size();
		if (nAdded == nRow_)
		{

			for (size_t i = 0; i < nAdded; i++)
				matrix_[i].push_back(colToAdd[i]);
			nCol_++;
		}
		else
			if (nRow_ == 0)
			{
				this->resize(nAdded, 1);
				for (size_t i = 0; i < nAdded; i++)
					matrix_[i][0] = colToAdd[i];
				nCol_ = 1;
			}
			else
				if (nAdded != 0)
					throw bad_Matrix("length of added vector are not equal to the heigh of matrix");
	}

	//добавляет слева от данной матрицы все столбцы матрицы columnsToAdd
	void push_left(Matrix<T> columnsToAdd)
	{
		size_t nAdded = columnsToAdd.heigh();
		if (nAdded == nRow_ || nRow_ == 0)
		{
			columnsToAdd.push_right(*this);
			(*this) = columnsToAdd;
		}
		else
			if (nAdded != 0)
				throw bad_Matrix("heigh of added and this matrices are not equal");
	}

	//добавляет столбец элементов в виде вектора слева данной матрицы
	void push_left(const std::vector<T>& colToAdd)
	{
		size_t nAdded = colToAdd.size();
		if (nAdded == nRow_)
		{
			Matrix<T> temp;
			temp.push_right(colToAdd);
			temp.push_right(*this);
			(*this) = temp;
		}
		else
			if (nRow_ == 0)
				this->push_right(colToAdd);
			else
				if (nAdded != 0)
					throw bad_Matrix("heigh of added and this matrices are not equal");
	}

	//возвращает количетсво строк эквивалентных вектору searchRow
	size_t rowCount(const std::vector<T>& searchRow) const
	{
		size_t sizeRow = searchRow.size();
		if (sizeRow != nCol_ || nCol_ == 0)
			return 0;
		size_t count = 0;
		for (size_t i = 0; i < nRow_; i++)
			if (searchRow == matrix_[i])
				count++;
		return count;
	}

	//возвращает количетсво столбцоы эквивалентных вектору searchСol
	size_t colCount(const std::vector<T>& searchCol) const
	{
		size_t sizeCol = searchCol.size();
		if (sizeCol != nRow_ || nRow_ == 0)
			return 0;
		size_t count = 0;
		for (size_t i = 0; i < nCol_; i++)
			if (searchCol == this->get_col(i))
				count++;
		return count;
	}

	//возвращает ранг матрицы
	size_t rank() const
	{
		size_t nRow = nRow_;
		size_t nCol = nCol_;
		{
			std::vector<T> nullRow(nCol_);
			std::vector<T> nullCol(nRow_);
			nRow -= this->rowCount(nullRow);
			nCol -= this->colCount(nullCol);
		}
		if (nRow <= nCol)
			return nRow;
		else
			return nCol;
	}

	//транспонирование матрицы
	Matrix transposition() const
	{
		Matrix<T> temp(nCol_, nRow_);
		for (size_t i = 0; i < nRow_; i++)
			for (size_t j = 0; j < nCol_; j++)
				temp[j][i] = matrix_[i][j];
		return temp;
	}

	//возвращает минор данной матрицы
	Matrix minor(const size_t& i, const size_t& j) const
	{
		Matrix<T> temp(*this);
		temp.delete_row(i);
		temp.delete_col(j);
		return temp;
	}

	//возвращает определитель матрицы
	T determinant() const
	{
		if (nRow_ == nCol_)
		{
			T value = 0;
			if (nRow_ > 1)
			{
				Matrix<T> U;
				{
					Matrix<T> L;
					this->choleskyUL(U, L);
				}
				value = 1;
				for (size_t i = 0; i < nRow_; i++)
					value *= U[i][i];
			}
			else
				if (nRow_ == 1)
					value = matrix_[0][0];
			return value;
		}
		else
			throw bad_Matrix("width and heigh of matrix not equal");
	}

	//возвращает матрицу обратную данной
	Matrix reverse_matrix() const
	{
		T det = this->determinant();
		if (det != 0)
		{
			Matrix<T> temp(nCol_,nRow_);
			for (size_t i = 0; i < nRow_; i++)
				for (size_t j = 0; j < nCol_; j++)
					temp[j][i] = pow(-1, i + j)*this->minor(i, j).determinant()/det;
			return temp;
		}
		else
			throw bad_Matrix("det equals zero");
	}
	
	//UL разложение Холецкого
	void choleskyUL(Matrix<double>& B, Matrix<double>& C) const
	{
		if (nRow_ == nCol_)
		{
			B.resize(nRow_, nRow_);
			C.resize(nCol_, nCol_);
			for (size_t i = 0; i < nRow_; i++)
			{
				for (size_t j = i; j < nRow_; j++)
				{
					B[j][i] = matrix_[j][i];
					for (size_t k = 0; k < i; k++)
						B[j][i] -= B[j][k] * C[k][i];
				}
				for (size_t j = i; j < nRow_; j++)
				{
					C[i][j] = matrix_[i][j];
					for (size_t k = 0; k < i; k++)
						C[i][j] -= B[i][k] * C[k][j];
					C[i][j] /= B[i][i];
				}
			}
		}
		else
			throw bad_Matrix("wrong size");
	}

	std::vector<T>& operator[](const size_t& pos)
	{
		if (pos < nRow_)
			return matrix_[pos];
		else
			throw bad_Matrix("out of range");
	}

	const std::vector<T> operator[](const size_t& pos) const
	{
		if (pos < nRow_)
			return matrix_[pos];
		else
			throw bad_Matrix("out of range");
	}

	Matrix operator+(const Matrix& a) const
	{
		if ((nRow_ == a.heigh()) && (nCol_ == a.width()))
		{
			Matrix<T> temp(nRow_,nCol_);
			for (size_t i = 0; i < nRow_; i++)
				for (size_t j = 0; j < nCol_; j++)
					temp_[i][j] = matrix_[i][j] + a[i][j];
			return temp;
		}
		else
			throw bad_Matrix("wrong size");
	}

	Matrix operator-(const Matrix& a) const
	{
		if ((nRow_ == a.heigh()) && (nCol_ == a.width()))
		{
			Matrix<T> temp(nRow_, nCol_);
			for (size_t i = 0; i < nRow_; i++)
				for (size_t j = 0; j < nCol_; j++)
					temp_[i][j] = matrix_[i][j] - a[i][j];
			return temp;
		}
		else
			throw bad_Matrix("wrong size");
	}

	Matrix operator*(const Matrix& a) const
	{
		if (nCol_ == a.heigh())
		{
			size_t nCol = a.width();
			Matrix<T> temp(nRow_, nCol);
			for (size_t i = 0; i < nRow_; i++)
				for (size_t j = 0; j < nCol; j++)
					for (size_t k = 0; k < nCol_; k++)
						temp[i][j] += matrix_[i][k] * a[k][j];
			return temp;
		}
		else
			throw bad_Matrix("wrong size");
	}

	Matrix operator*(const T& a) const
	{
		Matrix<T> temp;
		if (this->heigh() == 0)
			return (temp);
		temp = Matrix<T>(nRow_, nCol_);
		for (size_t i = 0; i < nRow_; i++)
			for (size_t j = 0; j < nCol_; j++)
				temp[i][j] = matrix_[i][j] * a;
		return temp;
	}

	friend Matrix<T> operator*(const T& a,const Matrix<T>& A)
	{
		return A*a;
	}

	Matrix operator/(const Matrix<T>& a) const
	{
		try
		{
			Matrix<T> temp = (*this)*a.reverse_matrix();
			return temp;
		}
		catch (bad_Matrix& e)
		{
			throw e;
		}
	}

	Matrix operator/(const T& a) const
	{
		if (a != 0.0)
		{
			Matrix<T> temp;
			if (this->heigh() == 0)
				return (temp);
			temp = Matrix<T>(nRow_, nCol_);
			for (size_t i = 0; i < nRow_; i++)
				for (size_t j = 0; j < nCol_; j++)
					temp[i][j] = matrix_[i][j] / a;
			return temp;
		}
		else
			throw bad_Matrix("zero divide");
	}

	bool operator==(const Matrix& a) const
	{
		if (this->heigh() == a.heigh() && this->width() == a.width())
		{
			for (size_t i = 0; i < nRow_; i++)
				for (size_t j = 0; j < nCol_; j++)
					if (a[i][j] != matrix_[i][j])
						return false;
			return true;
		}
		else
			return false;
	}
};