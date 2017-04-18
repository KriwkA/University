#pragma once
#ifndef _WORKERSDATA_H_
#define _WORKERSDATA_H_
#include "Vector.h"
#include "macro.h"

namespace worker
{

#define WD WorkersData
    //данные о сотрудниках
    struct WorkersData
    {
        SP sortPriority; //приоритет сортировки сотрудников
        Worker* workers; //вектор сотрудников
        size_t size;     //кол-во сотрудников
        size_t capacity; //занимаемая вектором память/sizeof(worker)
    };

    /*добавление нового сотрудника
     *@param
     * workers - стурктура хранения сотрудников
     * _newWorker - новый сотрудник
    */
    void add(WD& workers, const Worker& _newWorker);

    /*поиск сотрудника
     *@param
     * workers - стурктура хранения сотрудников
     * _id - id сотрудника
     *@return
     * позиция в векторе или -1
    */
    long long search(const WD& workers, const size_t& _id);

    /*удаление сотрудника
     *@param
     * workers - стурктура хранения сотрудников
     * _dataPos - позиция в векторе
    */
    void del(WD& workers, const size_t& _dataPos);

    /*сортировка сотрудников
     *@param
     * workers - стурктура хранения сотрудников
     * sortFlag - 0-убывание, 1-возрастание
    */
    void sort(WD& workers, int sortFlag = 0);

    /*освобождение памяти
     *@param
     * workers - стурктура хранения сотрудников
    */
    void clear(WD& workers);
}

#endif
