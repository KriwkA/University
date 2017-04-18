#pragma once
#ifndef _WORKER_H_
#define _WORKER_H_
#include "macro.h"
#include <string>

//дата
struct Date
{
    size_t year;
    size_t month;
    size_t day;
};

//преобразование даты в строку dd/mm/yyyy
std::string dateToString(Date);

//ФИО
struct FIO
{
    char name[20];
    char sername[20];
    char fathername[20];
};

namespace worker
{
    enum Gender{ MALE, FEMALE }; //пол

    struct Worker
    {
        size_t id;          //id сотрудника
        ::FIO fio;          //ФИО
        Date birthday;      //дата рождения
        Gender gender;      //пол
        char profession[20];//профессия
        size_t experience;  //опыт работы
        size_t rang;        //ранг
        size_t factory;     //id предприятия
        size_t sector;      //номер сектора
        double payment;     // З/П
    };

    enum SortPriority
    {
        ID,
        NAME,
        SERNAME,
        FATHERNAME,
        BIRTHDAY,
        GENDER,
        PROFFESSION,
        EXPERIENCE,
        RANG,
        FACTORY,
        SECTOR,
        PAYMENT
    };

    /*сравнение сотрудников
     *@param
     * _left - первый сотрудник
     * _right - второй сотрудник
     * SortPriority - приоритет сортировки
     * @return
     * -1 - first, 0 equals, 1 - second
    */
    int compareWorker(const Worker& _left, const Worker& _right, SP sortPriority);
    #define CMPFUNC(title) int(*(title))(const Worker&, const Worker&, SP)
}
#endif
