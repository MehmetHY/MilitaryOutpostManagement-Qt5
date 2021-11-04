#ifndef PLATOONCONTROLLER_H
#define PLATOONCONTROLLER_H

#include <QObject>

class PlatoonController : public QObject
{
    Q_OBJECT

private:    // fields
    class Soldier* PlatoonLeader;
    Soldier* PlatoonSergeant;
    QList<class Squad*>* squadList;
    QList<class Duty*>* dutyList;

public:     // constructors
    explicit PlatoonController(QObject *parent = nullptr);
    explicit PlatoonController(Soldier* leader, Soldier* sergeant, QList<Squad*>* squads = nullptr, QList<Duty*>* duties = nullptr, QObject *parent = nullptr);

public:     // properties
    Soldier* GetPlatoonLeader() const;
    void SetPlatoonLeader(Soldier* newLeader);

    Soldier* GetPlatoonSergeant() const;
    void SetPlatoonSergeant(Soldier* newSergeant);

    QList<Squad*>* GetSquadList() const;

    QList<Duty*>* GetDutyList() const;

public:     // methods
// todo:   Duty* CreateNewDuty(QString dutyName, Soldier* soldier, QDateTime* startDate, QDateTime* endDate) const;
// todo:   void DeleteDuty(Duty* duty);

// todo:   Squad* CreateNewSquad(QString squadName) const;
// todo:   void DeleteSquad(Squad* squad);
};

#endif // PLATOONCONTROLLER_H
