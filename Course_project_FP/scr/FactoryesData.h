#pragma once
#ifndef _FACTORYESDATA_H_
#define _FACTORYESDATA_H_
#include "Tree.h"
#include "macro.h"

namespace factory
{
#define FD FactoryData
    //данные о предприятиях
    struct FactoryData
    {
        SP sortPriority; //приоритет сортировки
        FNode* root;     //указатель на корень дерева
        size_t size;     //кол-во эл-тов дерева
    };

    /*добавление предприятия в FactoryData
     *@param
     * factoryes - структура хранения предприятий
     * _factory - добавляемое предприятие
    */
    void add(FD& factoryes, Factory* _factory);

    /*поиск предприятия по id
     *@param
     * factoryes - структура хранения предприятий
     * _id - id предприятия
     *@return
     *  указатель на преприятие or nullptr
    */
    Factory* search(const FD& _factoryes, const size_t& _id);

    /*поиск предприятия по id
     *@param
     * factoryes - структура хранения предприятий
     * _id - id предприятия
    */
    void del(FD& factoryes, const size_t& _id);

    /*сортировка предприятий
     *@param
     * factoryes - структура хранения предприятий
     * cmpFlag - 0(по убыванию), 1 (по возрастанию)
    */
    void sort(FD& factoryes, int cmpFlag = 0);

    /*освобождение памяти
     *@param
     * factoryes - структура хранения предприятий
    */
    void clearData(FD& factoryes);
}

#endif
