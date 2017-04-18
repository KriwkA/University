#include "FactoryesData.h"

namespace factory
{
	void add(FD& factoryes, Factory* _factory)
	{
		add(&factoryes.root, _factory,factoryes.sortPriority,compareFactory);
		factoryes.size++;
	}

	Factory* search(const FD& _factoryes, const size_t& _id)
	{
		return search(_factoryes.root, _id);
	}

	void del(FD& factoryes, const size_t& _id)
	{
        del(&factoryes.root, _id);
		factoryes.size--;
	}

    int cmpFuncInc(const Factory& _left, const Factory& _right, SP _sp)
    {
        return -compareFactory(_left, _right, _sp);
    }

    void sort(FD& factoryes, int cmpFlag)
	{
        if (!cmpFlag)
            //dec sort
            reBuild(&factoryes.root, factoryes.sortPriority, compareFactory);
        else
            //inc sort
            reBuild(&factoryes.root, factoryes.sortPriority, cmpFuncInc);

	}

    void clearData(FD& factoryes)
    {
        factory::clear(&factoryes.root);
        factoryes.size = 0;
    }
}
