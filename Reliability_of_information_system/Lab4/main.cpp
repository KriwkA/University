#include <RIS.h>
#include <QDebug>
#include <QString>

struct Entity
{
    Entity(): reliabilities(0), failureRate(0) {}
    Entity(const double& _reliabilities, const double& _failureRate)
        : reliabilities(_reliabilities),
          failureRate(_failureRate) {}
    double reliabilities;
    double failureRate;
};

int main()
{
    double workTime = 7000;
    //sheme view
    QVector<QVector<double>> sheme = {
                                        {0.000125, 0.000135, 0.00014},
                                        {0.000115},
                                        {0.00015},
                                        {0.00012, 0.00015, 0.000125, 0.000085},
                                        {0.000175}
                                     };
    QVector<Entity> entities;

    double fullReliabilities = 1.0;
    double fullFailureRate;

    for(auto& system : sheme)
    {
        double q = 1.0;
        for(auto& entityFailureIntensity : system)
        {
            double realiabilities = RIS::reliabilities(entityFailureIntensity, workTime);
            double failureRate = 1.0 - realiabilities;
            entities << Entity(realiabilities, failureRate);
            q *= failureRate;
        }
        fullReliabilities *= 1.0 - q;
    }

    fullFailureRate = 1.0 - fullReliabilities;

    qDebug() << "Reliabilities / Failure rate:";
    for(const Entity& entity : entities)
    {
        qDebug() << QString("%0 / %1").arg(entity.reliabilities, 0, 'f', 5).arg(entity.failureRate, 0, 'f', 5);
    }
    qDebug() << QString("Full reliability: %0").arg(fullReliabilities, 0, 'f', 5);
    qDebug() << QString("Full failure rate: %0").arg(fullFailureRate, 0, 'f', 5);

    return 0;
}
