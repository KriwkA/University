#include "Vector.h"

namespace worker
{
	void resize(Worker** vector, const size_t& _size, const size_t& _newSize, size_t& capacity)
	{
		if (capacity >= _newSize)
			return;
		Worker* newVector = new Worker[_newSize];
		size_t temp = _size <= _newSize ? _size : _newSize;
		for (size_t i = 0; i < temp; ++i)
			newVector[i] = (*vector)[i];
		delete[](*vector);
		*vector = newVector;
		capacity = _newSize;
	}

	void erase(Worker** vector, size_t& size, const size_t& _first, const size_t& _last)
	{
		size_t delCount = _last - _first + 1;
		for (size_t i = _last + 1; i < size; ++i)
            (*vector)[i - delCount] = (*vector)[i];
		size -= delCount;
    }

	void insert(Worker** vector, size_t& size, size_t& capacity, const Worker& _new, const size_t& _pos)
	{
		resize(&(*vector), size, size + 2, capacity);
		for (size_t i = size; i > _pos; --i)
			(*vector)[i] = (*vector)[i - 1];
		size++;
		(*vector)[_pos] = _new;
	}

    void quickSort(Worker** arr, const int& _left, const int& _right, SP _priority, CMPFUNC(cmpfunc))
	{
        int i = _left, j = _right;
        Worker mid = (*arr)[(_left + _right) / 2];
		while (i <= j)
		{
            while (cmpfunc((*arr)[i], mid, _priority) < 0) i++;
            while (cmpfunc((*arr)[j], mid, _priority) > 0) j--;
            if (i <= j)
                std::swap((*arr)[i++],(*arr)[j--]);
		}
		if (_left < j)
			quickSort(&(*arr), _left, j, _priority, cmpfunc);
		if (i < _right)
			quickSort(&(*arr), i, _right, _priority, cmpfunc);
	}
}
