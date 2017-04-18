#pragma once
#ifndef _WORKERSTATISTICSTREE_H_
#define _WORKERSTATISTICSTREE_H_
#include "Factory.h"
#include "macro.h"

namespace factory
{
    //дерево предприятий
    struct FNode
	{
		Factory* key;
        FNode* left;
        FNode* right;
	};

    /*добавление предприятия
     *@param
     * root - указатель на корень дерева
     * _key - добавляемое предприятие
     * _priority - текущий приоритет сортировки дерева
     * cmpfunc - функция сравнение ключей
    */
    void add(FNode** root, Factory* _key, SP _priority, CMPFUNC(cmpfunc));

    /*поиск предприятия в дереве
     *@param
     * root - указатель на корень дерева
     * _number - id предприятия
    */
    Factory* search(FNode* _root, const size_t& _number);

    /*удаление предприятия из дерева
     *@param
     * root - указатель на корень дерева
     * _number - id предприятия
     *@return
     * указатель на ключь или nullptr
    */
    void del(FNode** root, const size_t& _number);

    /*перестраивание дерева по новому приоритету
     *@param
     * root - указатель на корень дерева
     * _priority - приоритет
     * cmpfunc - функция сравнения ключей
    */
    void reBuild(FNode** root, SP _priority, CMPFUNC(cmpfunc));

    /*освобождение памяти
     *@param
     * root - указатель на корень дерева
    */
    void clear(FNode** root);
}

#endif
