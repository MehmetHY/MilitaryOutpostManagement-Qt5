#ifndef PLATOON_H
#define PLATOON_H

#include <QObject>

class Platoon : public QObject
{
    Q_OBJECT
private:    // fields
    unsigned int platoonId;
    QString platoonName;
    class Soldier* platoonLeader;
    Soldier* platoonSergeant;

    class SquadManager* squadManager;
    class DutyManager* dutyManager;

public:     // constructors
    explicit Platoon(unsigned int id, const QString name, QObject *parent = nullptr);

public:     // methods
    void SetName(const QString name);
};

#endif // PLATOON_H
