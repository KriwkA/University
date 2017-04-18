#pragma once
#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_
#include "Worker.h"
#include "macro.h"

namespace worker
{
    /*изменение размера вектора
     *@param
     * vector - указатель на вектор
     * _size - текущий размер
     * _newSize - новый размер
     * _capacity - текущий занимаемый объем памяти
    */
	void resize(Worker** vector, const size_t& _size, 
		const size_t& _newSize, size_t& capacity);

    /*удаления части вектора
     *@param
     * vector - указатель на вектор
     * size - размер векора
     * _first - первый удаляемый эл-т
     * _last - последний удаляемый эл-т
    */
    void erase(Worker** vector, size_t& size,
		const size_t& _first, const size_t& _last);

    /*удаления части вектора
     *@param
     * vector - указатель на вектор
     * size - размер векора
     * capacity - занимаемый объем памяти
     * _new - новый работник
     * _pos - номер позиции, на которую будет вставлен новый сотрудник
    */
    void insert(Worker** vector, size_t& size,
		size_t& capacity, const Worker& _new, const size_t& _pos);

    /*сортировка вектора
     *@param
     * arr - указатель на вектор
     * _left - левая граница сортировки
     * _right - правая граница сортировки
     * _priority - приоритет сортировки
     * cmpfunc - функция сравнения двух работников по приоритету
    */
    void quickSort(Worker** arr, const int& _left,
        const int& _right, SP _priority, CMPFUNC(cmpfunc));
}
#endif
