#include <fstream>
#include <iostream>
#include <iomanip>
#include "Data.h"

namespace data
{
    void __prepare(Data& _data)
    {
        if (_data.factoryesData.sortPriority != factory::SP::NUMBER)
        {
            _data.factoryesData.sortPriority = factory::SP::NUMBER;
            factory::sort(_data.factoryesData);
        }
    }

    void __persentCalculate(factory::FNode* root, const int& male, const int& female, const int& all)
    {
        if (root == nullptr)
            return;
        root->key->persentCount.all = bool(root->key->count.all) ? int(100.0 * double(root->key->count.all) / double(all)) : 0;
        root->key->persentCount.male = bool(root->key->count.male) ? int(100.0 * double(root->key->count.male) / double(male)) : 0;
        root->key->persentCount.female = bool(root->key->count.female) ? int(100.0 * double(root->key->count.female) / double(female)) : 0;
        __persentCalculate(root->left, male, female, all);
        __persentCalculate(root->right, male, female, all);
    }

    void addWorker(Data& _data, const worker::Worker& _newWorker)
    {
        worker::add(_data.workersData, _newWorker);
        __prepare(_data);

        factory::Factory* factory = factory::search(_data.factoryesData, _newWorker.factory);
        if (factory == nullptr)
        {
            factory = new factory::Factory;
            factory->number = _newWorker.factory;
            factory->count.all = 0;
            factory->count.male = 0;
            factory->count.female = 0;
            factory->persentCount.all = 0;
            factory->persentCount.male = 0;
            factory->persentCount.female = 0;
            factory::add(_data.factoryesData, factory);
        }

        _data.all++;

        if (_newWorker.gender == worker::MALE)
        {
            _data.male++;
            factory->count.all++;
            factory->count.male++;
        }
        else
        {
            _data.female++;
            factory->count.all++;
            factory->count.female++;
        }
        __persentCalculate(_data.factoryesData.root, _data.male, _data.female, _data.all);
    }

    void delWorker(Data& _data, const size_t& _dataPos)
    {
        worker::Worker& worker = _data.workersData.workers[_dataPos];
        __prepare(_data);

        factory::Factory* factory = factory::search(_data.factoryesData, worker.factory);
        worker::Gender gender = worker.gender;
        if (factory->count.all > 1)
        {
            factory->count.all--;
            if (gender == worker::MALE)
                factory->count.male--;
            else
                factory->count.female--;
        }
        else
        {
            factory::del(_data.factoryesData, factory->number);
        }
        _data.all--;
        if(gender == worker::MALE)
            _data.male--;
        else
            _data.female--;
         worker::del(_data.workersData, _dataPos);
         __persentCalculate(_data.factoryesData.root, _data.male, _data.female, _data.all);
    }

    void saveBinDataFile(const Data& _data, const std::string& _path)
    {
        std::ofstream fout(_path, std::ios::binary);
        int count = _data.workersData.size;
        fout.write(reinterpret_cast<char*>(&count), sizeof(int));
        for(int i = 0; i < count; ++i)
            fout.write(reinterpret_cast<char*>(&_data.workersData.workers[i]), sizeof(worker::Worker));
        fout.close();
    }

    void loadBinDataFile(Data& _data, const std::string& _path)
    {
        std::ifstream fin(_path, std::ios::binary);
        data::clearData(_data);
        _data.workersData.sortPriority = worker::SP::ID;
        _data.factoryesData.sortPriority = factory::SP::NUMBER;
        int countWorkers;
        fin.read(reinterpret_cast<char*>(&countWorkers), sizeof(int));
        worker::Worker worker;
        for(int i = 0; i < countWorkers; ++i)
        {
            fin.read(reinterpret_cast<char*>(&worker), sizeof(worker::Worker));
            data::addWorker(_data, worker);
        }
        fin.close();
    }

    void __print(const factory::FNode* root, std::ofstream& fout)
    {
        if (root == nullptr)
            return;
        __print(root->left, fout);
        fout << std::setw(6) << root->key->number << '|';
        fout << std::setw(8) << root->key->count.male << '|';
        fout << std::setw(8) << root->key->count.female << '|';
        fout << std::setw(8) << root->key->count.all << '|';
        fout << std::setw(8) << root->key->persentCount.male << '|';
        fout << std::setw(8) << root->key->persentCount.female << '|';
        fout << std::setw(8) << root->key->persentCount.all;
        fout << std::endl;
        __print(root->right, fout);
    }

    void printFactoryTableTextFile(const Data& _data, const std::string& _path)
    {
        std::ofstream fout(_path);
        fout.setf(std::ios::left);
        fout.setf(std::ios::fixed);
        fout.precision(0);
        fout << "      |          Count           |          Percent" << std::endl;
        fout << "  Id  |  Male  | Female |  All   |  Male  | Female |  All" << std::endl;
        __print(_data.factoryesData.root, fout);
        fout.close();
    }

    void clearData(Data& _data)
    {
        factory::clearData(_data.factoryesData);
        worker::clear(_data.workersData);
        _data.all = 0;
        _data.male = 0;
        _data.female = 0;
    }

    void initialize(Data& _data)
    {
        _data.all = 0;
        _data.female = 0;
        _data.male = 0;
        _data.workersData.workers = nullptr;
        _data.workersData.size = 0;
        _data.workersData.capacity = 0;
        _data.workersData.sortPriority = worker::SortPriority::ID;
        _data.factoryesData.root = nullptr;
        _data.factoryesData.size = 0;
        _data.factoryesData.sortPriority = factory::SortPriority::NUMBER;
    }
}
