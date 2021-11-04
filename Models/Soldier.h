#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>

class Soldier : public QObject
{
    Q_OBJECT

public:     // enums
    enum class Rank
    {
        PRIVATE, CORPORAL, SERGEANT, STAFF_SERGEANT, SERGEANT_FIRST_CLASS, LIEUTENANT
    };
    enum class Role
    {
        PLATOON_LEADER, PLATOON_SERGEANT, SQUAD_LEADER, TEAM_LEADER,
        RIFLEMAN, GRENADIERS, AUTOMATIC_RIFLEMEN, MARKSMAN, ENGINEER
    };
    enum class ShiftTime
    {
        DAY, NIGHT
    };

private:    // fields
    unsigned int soldierId;
    QString soldierName;
    Rank soldierRank;
    Role soldierRole;
    ShiftTime soldierShiftTime;

public:     // constructors
    explicit Soldier(QObject *parent = nullptr);
    explicit Soldier(int id, QString name, Rank rank, Role role, ShiftTime shiftTime = ShiftTime::DAY, QObject *parent = nullptr);

public:     // properties
    int GetId() const;
    QString GetName() const;
    Rank GetRank() const;
    void SetRank(Rank rank);
    Role GetRole() const;
    void SetRole(Role role);
    ShiftTime GetShiftTime() const;
    void SetShiftTime(ShiftTime shiftTime);
};

#endif // SOLDIER_H
