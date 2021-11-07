#ifndef PLATOONMANAGER_H
#define PLATOONMANAGER_H

#include <QObject>

class PlatoonManager : public QObject
{
    Q_OBJECT
private:
    class Platoon* platoon;
    class DataManager* dataManager;

    void LoadPlatoonFromDB();
public:
    explicit PlatoonManager(DataManager* manager, QObject *parent = nullptr);

    bool IsPlatoonExist() const;
    Platoon* GetPlatoon() const;
    void CreateNewPlatoon(const QString name);
};

#endif // PLATOONMANAGER_H
