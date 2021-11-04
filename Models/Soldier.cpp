#include "Soldier.h"

Soldier::Soldier(QObject *parent) : QObject(parent)
{

}

Soldier::Soldier(unsigned int id, QString name, Rank rank, Role role, ShiftTime shiftTime, QObject *parent)
    :   QObject(parent), soldierId(id), soldierName(name), soldierRank(rank), soldierRole(role), soldierShiftTime(shiftTime)
{

}

int Soldier::GetId() const
{
    return soldierId;
}

QString Soldier::GetName() const
{
    return soldierName;
}

Soldier::Rank Soldier::GetRank() const
{
    return soldierRank;
}

void Soldier::SetRank(Rank rank)
{
    soldierRank = rank;
}

Soldier::Role Soldier::GetRole() const
{
    return soldierRole;
}

void Soldier::SetRole(Role role)
{
    soldierRole = role;
}

Soldier::ShiftTime Soldier::GetShiftTime() const
{
    return soldierShiftTime;
}

void Soldier::SetShiftTime(ShiftTime shiftTime)
{
    soldierShiftTime = shiftTime;
}

Squad *Soldier::GetSquad() const
{
    return soldierSquad;
}

void Soldier::SetSquad(Squad *squad)
{
    soldierSquad = squad;
}
