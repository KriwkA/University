#include "Worker.h"
#include <string>
#include <cstring>

std::string dateToString(Date _date)
{
    std::string date(10, ' ');
    date[0] = char(_date.day / 10 + int('0'));
    date[1] = char(_date.day % 10 + int('0'));
    date[2] = '/';
    date[3] = char(_date.month / 10 + int('0'));
    date[4] = char(_date.month % 10 + int('0'));
    date[5] = '/';
    date[6] = char(_date.year / 1000 + int('0'));
    _date.year %= 1000;
    date[7] = char(_date.year / 100 + int('0'));
    _date.year %= 100;
    date[8] = char(_date.year / 10 + int('0'));
    date[9] = char(_date.year % 10 + int('0'));
    return date;
}

namespace worker
{
	int compareWorker(const Worker& _left, const Worker& _right,SP sortPriority)
	{
		switch (sortPriority)
		{
		case ID:
		{
			if (_left.id == _right.id)
				return 0;
			return _left.id < _right.id ? -1 : 1;
		} break;

        case NAME:
        {
            return -std::strcmp(_left.fio.name, _right.fio.name);
        } break;

        case SERNAME:
        {
            return -std::strcmp(_left.fio.sername, _right.fio.sername);
        } break;

        case FATHERNAME:
        {
            return -std::strcmp(_left.fio.fathername, _right.fio.fathername);
        } break;

        case BIRTHDAY:
        {
            LL firstDate = _left.birthday.year * 10000 + _left.birthday.month * 100 + _left.birthday.day;
            LL secondDate = _right.birthday.year * 10000 + _right.birthday.month * 100 + _right.birthday.day;
            if(firstDate == secondDate)
                return 0;
            else if(firstDate > secondDate)
                return 1;
            else
                return -1;
		} break;

        case GENDER:
		{
			if (_left.gender == _right.gender)
				return 0;
			return _left.gender == MALE ? -1 : 1;
		} break;

		case PROFFESSION:
		{
            return -std::strcmp(_left.profession, _right.profession);
        }	break;

		case EXPERIENCE:
		{
			if (_left.experience == _right.experience)
				return 0;
			return _left.experience < _right.experience ? -1 : 1;
		} break;

		case RANG:
		{
			if (_left.rang == _right.rang)
				return 0;
			return _left.rang < _right.rang ? -1 : 1;
		} break;

		case FACTORY:
		{
			if (_left.factory == _right.factory)
				return 0;
			return _left.factory < _right.factory ? -1 : 1;
		} break;

		case SECTOR:
		{
			if (_left.sector == _right.sector)
				return 0;
			return _left.sector < _right.sector ? -1 : 1;
		} break;

		case PAYMENT:
		{
			if (_left.payment == _right.payment)
				return 0;
			return _left.payment < _right.payment ? -1 : 1;
		} break;
		}
	}
}
