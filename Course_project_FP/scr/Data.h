#pragma once
#ifndef _DATA_H_
#define _DATA_H_
#include "WorkersData.h"
#include "FactoryesData.h"
#include "macro.h"
#include <string>

namespace data
{
    struct Data
    {
        worker::WD workersData;
        factory::FD factoryesData;
        size_t all;
        size_t male;
        size_t female;
    };

    /*добавление нового работника
     *@param
     * _data - дынные о всех сотрудниках
     * _newWorker - добавляемый работник
    */
    void addWorker(Data& _data, const worker::Worker& _newWorker);

    /*удаление сотрудника из Data
     * по его позиции в списке
     *@param
     * _data - дынные о всех сотрудниках
     * _dataPos - розиция сотрудника в списке
    */
    void delWorker(Data& _data, const size_t& _dataPos);

    /*сохранение данных в двоичный файл
     * @param
     * _data - данные о всех сотрудниках
     * _path - путь к файлу сохранения
    */
    void saveBinDataFile(const Data& _data, const std::string& _path);

    /*загрузка данных из двоичного файла
     * @param
     * _data - данные о всех сотрудниках
     * _path - путь к файлу загрузки
    */
    void loadBinDataFile(Data& _data, const std::string& _path);

    /*вывод таблицы предприятий в текстовый файл
     * @param
     * _data - данные о всех сотрудниках
     * _path - путь к файлу сохранения
    */
    void printFactoryTableTextFile(const Data& _data, const std::string& _path);

    /*освобождение памяти
     * @param
     * _data - данные о всех сотрудниках
    */
    void clearData(Data& _data);

    /*инициализация данных
     * @param
     * _data - данные о всех сотрудниках
    */
    void initialize(Data& _data);
}

#endif
