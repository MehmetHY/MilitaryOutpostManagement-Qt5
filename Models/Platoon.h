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
    QList<class Squad*> squads;
    QList<class Duty*> duties;

public:     // constructors
    explicit Platoon(QObject *parent = nullptr);
    explicit Platoon(unsigned int id, QString name, Soldier* leader, Soldier* sergeant, QObject *parent = nullptr);

public:     // methods
    Soldier* GetLeader() const;
    void SetLeader(Soldier* soldier);

    Soldier* GetSergeant() const;
    void SetSergeant(Soldier* soldier);

    Squad* GetSquad(unsigned int id) const;
    Duty* GetDuty(unsigned int id) const;

    void AddSquad(Squad* squad);
    void AddDuty(Duty* duty);

    void UpdateSquad(Squad* oldSquad, Squad* newSquad);
    void UpdateDuty(Duty* oldDuty, Duty* newDuty);

    void DeleteSquad(Squad* squad);
    void DeleteDuty(Duty* duty);

    friend class DataManager;
};

#endif // PLATOON_H
