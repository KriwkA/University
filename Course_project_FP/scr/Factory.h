#pragma once
#ifndef _FACTORY_H_
#define _FACTORY_H_
#include "macro.h"

namespace factory
{
    //количество сотрудников на предприятии
    struct CountWorkers
	{
        size_t all;     //количесво всех сотрудников
        size_t male;    //кол-во мужчин
        size_t female;  //кол-во женщин
	};

    //процент работников на предприятии от общего
	struct PersentCountWorkers
	{
        size_t all;
		size_t male;
		size_t female;
	};

	struct Factory
	{
        size_t number; //номер предприятия
		CountWorkers count;
		PersentCountWorkers persentCount;
	};

    //выбор поля сортировки
	enum SortPriority
	{ 
		NUMBER,
		ALL,
		MALE,
		FEMALE,
		P_ALL,
		P_MALE,
		P_FEMALE
	};

    //функция равнения двух полей по приоритету
	int compareFactory(const Factory& _left, const Factory& _right, SP sortpriority);
	#define CMPFUNC(title) int(*(title))(const Factory&, const Factory&, SP)
}

#endif
