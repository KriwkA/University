#include <QString>
#include <QDebug>
#include <RIS.h>

int main()
{
    uint64_t count = 1000;
    uint64_t time = 7000;
    uint64_t deltaTime = 150;
    uint64_t failsT = 230;
    uint64_t failsDT = 100;

    double reliabilitiesDT = RIS::reliabilities(count, failsDT, deltaTime);
    qDebug() << "Reliabilities for the dt =" << QString("%1 (1/hour)").arg(reliabilitiesDT, 0, 'f', 7);

    double failureRateT = RIS::failureRate(count, failsT);
    qDebug() << "Failure rate for the t =" << QString("%1").arg(failureRateT, 0, 'f', 7);

    double failureRateTDT = RIS::failureRate(count, failsT + failsDT);
    qDebug() << "Failure rate for the t + dt =" << QString("%1").arg(failureRateTDT, 0, 'f', 7);

    double failureRateDT = failureRateTDT / failureRateT;
    qDebug() << "Failure rate for the dt =" << QString("%1").arg(failureRateDT, 0, 'f', 7);

    double failureIntensityT = RIS::failureIntensity(count, failsT, time);
    qDebug() << "Failure Intensity for the t =" << QString("%1 (1/hour)").arg(failureIntensityT, 0, 'f', 7);

    double failureIntensityDT = RIS::failureIntensity(reliabilitiesDT, failureRateDT);
    qDebug() << "Failure Intensity for the dt =" << QString("%1 (1/hour)").arg(failureIntensityDT, 0, 'f', 7);

    double avrWorkTime = RIS::averageWorkTime(failureIntensityDT);
    qDebug() << "Average time before failure = " << QString("%1 hours").arg(avrWorkTime, 0, 'f', 1);

    return 0;
}
