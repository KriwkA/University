#include "WorkersData.h"

namespace worker
{
	void add(WorkersData& workers, const Worker& _newWorker)
	{
		size_t i;
		for (i = 0; i < workers.size; ++i)
			if (compareWorker(workers.workers[i], _newWorker, workers.sortPriority) == 1)
				break;
		insert(&workers.workers, workers.size, workers.capacity, _newWorker, i);
	}

	long long search(const WorkersData& _workers, const size_t& _id)
	{
		for (size_t i = 0; i < _workers.size; ++i)
			if (_workers.workers[i].id == _id)
				return i;
		return -1;
	}

	void del(WorkersData& workers, const size_t& _dataPos)
	{
		erase(&workers.workers, workers.size, _dataPos, _dataPos);
	}

    int cmpFuncInc(const Worker& _left, const Worker& _right, SP _sp)
    {
        return -compareWorker(_left, _right, _sp);
    }

    void sort(WorkersData& workers, int sortFlag)
	{
        if(workers.size > 1)
        {
            if(!sortFlag)
                quickSort(&workers.workers, 0, workers.size - 1, workers.sortPriority, compareWorker);
            else
                quickSort(&workers.workers, 0, workers.size - 1, workers.sortPriority, cmpFuncInc);
        }

    }

	void clear(WorkersData& _workers)
	{
		delete[] _workers.workers;
		_workers.workers = nullptr;
		_workers.capacity = 0;
		_workers.size = 0;
	}
}
