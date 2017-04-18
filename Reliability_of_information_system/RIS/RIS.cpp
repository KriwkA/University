#include "RIS.h"
#include <cmath>

double RIS::reliabilities(const uint64_t& _count, const uint64_t& _failsCount, const double& _deltaTime)
{
    return _failsCount / double(_count * _deltaTime);
}

double RIS::reliabilities(const uint64_t& _count, const uint64_t& _countLeft)
{
    return (double)_countLeft / (double)_count;
}

double RIS::reliabilities(const double& _failureIntensity, const double& _workTime)
{
    return std::exp(-_failureIntensity * _workTime);
}

double RIS::failureRate(const uint64_t& _count, const uint64_t& _failsCount)
{
    return 1.0 - double(_failsCount) / double(_count);
}

double RIS::failureIntensity(const double& _failureRate, const double& _reliabilities)
{
    return _failureRate / _reliabilities;
}

double RIS::failureIntensity(const uint64_t& _count, const uint64_t& _failsCount, const double& _deltaTime)
{
    return 2.0 * double(_failsCount) / double(_count + _count - _failsCount) / double(_deltaTime);
}

double RIS::averageWorkTime(const uint64_t& _count, const uint64_t& _failsCount, const double& _deltaTime)
{
    return 1.0 / failureIntensity(_count, _failsCount, _deltaTime);
}

double RIS::averageWorkTime(const double& _failureIntensity)
{
    return 1.0 / _failureIntensity;
}
