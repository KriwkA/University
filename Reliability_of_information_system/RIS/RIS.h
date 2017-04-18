#ifndef RIS_H
#define RIS_H

#include "ris_global.h"

class RISSHARED_EXPORT RIS
{

public:
    static double reliabilities(const uint64_t& _count, const uint64_t& _failsCount, const double& _deltaTime);
    static double reliabilities(const uint64_t& _count, const uint64_t& _countLeft);
    static double reliabilities(const double& _failureIntensity, const double& _workTime);
    static double failureRate(const uint64_t& _count, const uint64_t& _failsCount);
    static double failureIntensity(const double& _failureRate, const double& _reliabilities);
    static double failureIntensity(const uint64_t& _count, const uint64_t& _failsCount, const double& _deltaTime);
    static double averageWorkTime(const uint64_t& _count, const uint64_t& _failsCount, const double& _deltaTime);
    static double averageWorkTime(const double& _failureIntensity);
};

#endif // RIS_H
