#include <QDebug>
#include <QVector>
#include <QTextStream>

int main()
{
    QVector<double> timeOfFailure = {1840, 2020, 2150, 2300, 2350, 2410, 2510,
                                     2680, 2760, 2820, 3090, 3120, 3310};
    QVector<double> deltaTime(timeOfFailure.size() - 1);
    QVector<double> reliabilities(timeOfFailure.size());
    QVector<double> failureIntensity(timeOfFailure.size() - 1);

    int entityesCount = timeOfFailure.size();
    for(int i = 0; i < entityesCount - 1; ++i)
    {
        reliabilities[i] = (entityesCount - i - 1 + 0.7) / (entityesCount + 0.4);
        deltaTime[i] = timeOfFailure[i + 1] - timeOfFailure[i];
        failureIntensity[i] = 1.0 / (deltaTime[i] * (sizeof(entityesCount - i - 1 - 0.7)));
    }
    reliabilities[entityesCount - 1] = (entityesCount - entityesCount + 0,7) / (entityesCount + 0.4);

    qDebug() << qSetRealNumberPrecision(7) << deltaTime;
    qDebug() << qSetRealNumberPrecision(7) << reliabilities;
    qDebug() << qSetRealNumberPrecision(7) << failureIntensity;

    return 0;
}
