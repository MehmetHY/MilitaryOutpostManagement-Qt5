#ifndef PLATOONMANAGER_H
#define PLATOONMANAGER_H

#include <QObject>

class PlatoonManager : public QObject
{
    Q_OBJECT
private:
    class Platoon* platoon;
    class DataManager* dataManager;
public:
    explicit PlatoonManager(DataManager* manager, QObject *parent = nullptr);

    Platoon* GetPlatoon() const;

};

#endif // PLATOONMANAGER_H
