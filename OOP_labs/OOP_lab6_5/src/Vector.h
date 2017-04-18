#pragma once
#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <cstring>

class Vector
{
private:
	double* arr_;
	size_t size_;
	size_t capacity_;
	void checkCapacity();
public:
	class bad_Vector
	{
	private:
		char* error_;
	public:
		bad_Vector() :error_("unknown") {};
		bad_Vector(char* error)
		{
			error_ = error;
		}
		bad_Vector(const bad_Vector& e)
		{
			error_ = e.what();
		}
		char* what() const
		{
			return error_;
		}
	};
	Vector();
	Vector(const size_t& _size);
	Vector(const Vector& _copy);
	void clear();
	size_t capacity() const;
	size_t size() const;
	void resize(const size_t& _size);
	void reserve(const size_t& _capacity);
	void push_back(const double& _val);
	void pop_back();
	void operator=(const Vector& _right);
	double& operator[](const size_t& _n);
	double& operator[](const size_t& _n) const;
	~Vector();
};

#endif

