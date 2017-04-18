#include"Factory.h"

namespace factory
{

	int compareFactory(const Factory& _left, const Factory& _right, SP sp)
	{
		switch (sp)
		{
		case NUMBER:
		{
			if (_left.number == _right.number)
				return 0;
            return _left.number > _right.number ? -1 : 1;
		} break;
		case ALL:
		{
			if (_left.count.all == _right.count.all)
				return 0;
            return _left.count.all > _right.count.all ? -1 : 1;
		} break;
		case MALE:
		{
			if (_left.count.male == _right.count.male)
				return 0;
            return _left.count.male > _right.count.male ? -1 : 1;
		} break;
		case FEMALE:
		{
			if (_left.count.female == _right.count.female)
				return 0;
            return _left.count.female > _right.count.female ? -1 : 1;
		} break;
		case P_ALL:
		{
			if (_left.persentCount.all == _right.persentCount.all)
				return 0;
            return _left.persentCount.all > _right.persentCount.all ? -1 : 1;
		} break;
		case P_MALE:
		{
			if (_left.persentCount.male == _right.persentCount.male)
				return 0;
            return _left.persentCount.male > _right.persentCount.male ? -1 : 1;
		} break;
		case P_FEMALE:
		{
			if (_left.persentCount.female == _right.persentCount.female)
				return 0;
            return _left.persentCount.female > _right.persentCount.female ? -1 : 1;
		} break;
		}
	}

}
