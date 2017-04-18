#include "Vector.h"

Vector::Vector()
{
	arr_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

Vector::Vector(const size_t& _size):Vector()
{
	this->resize(_size);
}

Vector::Vector(const Vector& _copy)
{
	size_ = _copy.size_;
	capacity_ = _copy.capacity_;
	arr_ = new double[capacity_];
	for (size_t i = 0; i < size_; ++i)
		arr_[i] = _copy.arr_[i];
	for (size_t i = size_; i <= capacity_; ++i)
		arr_[i] = 0.0;
	checkCapacity();
}

void Vector::clear()
{
	delete[] arr_;
	capacity_ = 0;
	size_ = 0;
}

void Vector::checkCapacity()
{
	if (capacity_ < size_)
		capacity_ = size_;
}

size_t Vector::capacity() const
{
	return capacity_;
}

size_t Vector::size() const
{
	return size_;
}

void Vector::resize(const size_t& _size)
{
	if (capacity_ >= _size)
	{
		for (size_t i = _size; i < size_; ++i)
			arr_[i] = 0.0;
		size_ = _size;
		return;
	}
	double* newArr = new double[_size];
	for (size_t i = size_; i < _size; ++i)
		newArr[i] = 0.0;
	capacity_ = _size;
	for (size_t i = 0; i < size_; ++i)
		newArr[i] = arr_[i];
	delete[] arr_;
	arr_ = newArr;
	size_ = _size;
	checkCapacity();
}

void Vector::reserve(const size_t& _capacity)
{
	checkCapacity();
	if (_capacity <= capacity_)
		return;
	size_t temp = size_;
	resize(_capacity);
	capacity_ = _capacity;
	size_ = temp;
}

void Vector::push_back(const double& _val)
{
	this->resize(size_ + 1);
	arr_[size_ - 1] = _val;
}

void Vector::pop_back()
{
	if (size_ == 0)
		throw bad_Vector("pop_back(): vector is empty");
	this->resize(size_ - 1);
}

void Vector::operator=(const Vector& _right)
{
	size_ = _right.size_;
	capacity_ = _right.capacity_;
	arr_ = new double[capacity_];
	for (size_t i = 0; i < size_; ++i)
		arr_[i] = _right.arr_[i];
	for (size_t i = size_; i <= capacity_; ++i)
		arr_[i] = 0.0;
}

double& Vector::operator[](const size_t& _n)
{
	if (_n >= size_)
		throw bad_Vector("out of range");
	return arr_[_n];
}

double& Vector::operator[](const size_t& _n) const
{
	if (_n >= size_)
		throw bad_Vector("out of range");
	return arr_[_n];
}

Vector::~Vector()
{
	this->clear();
}