#include <QDebug>
#include <QVector>
#include <RIS.h>


int main(int argc, char *argv[])
{
    int entityesCount = 200;
    QVector<double> timePassed = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500};
    QVector<uint64_t> failureOnTimeInterval = {25, 20, 15, 8, 8, 6, 9, 12, 30};
    QVector<double> timeInterval;
    QVector<uint64_t> entityesLeft;
    QVector<double> reliabilities;
    QVector<double> failureIntensity;
    for(int i = 0; i < timePassed.size(); ++i)
    {
        if(i)
        {
            timeInterval << ((timePassed[i] + timePassed[i - 1]) / 2.0);
            entityesLeft << (failureOnTimeInterval[i] <= entityesLeft[i - 1] ? entityesLeft[i - 1] - failureOnTimeInterval[i] : 0);
            failureIntensity << RIS::failureIntensity(entityesLeft[i - 1], failureOnTimeInterval[i], timePassed[i] - timePassed[i - 1]);
        }
        else
        {
            timeInterval << (timePassed[i] / 2.0);
            entityesLeft << (failureOnTimeInterval[i] <= entityesCount ? entityesCount - failureOnTimeInterval[i] : 0);
            failureIntensity << RIS::failureIntensity(entityesCount, failureOnTimeInterval[i], timePassed[i]);
        }
        reliabilities << RIS::reliabilities(entityesCount, entityesLeft[i]);
    }

    qDebug() << "Time intervals: " << timeInterval;
    qDebug() << "Entities left: " << entityesLeft;
    qDebug() << "Reliabilities: " << reliabilities;
    qDebug() << "Failure intensivity: " << failureIntensity;

    return 0;
}
