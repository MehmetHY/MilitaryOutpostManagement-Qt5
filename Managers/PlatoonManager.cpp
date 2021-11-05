#include "PlatoonManager.h"
#include "../Models/Duty.h"

PlatoonManager::PlatoonManager(QObject *parent) : QObject(parent)
{

}

PlatoonManager::PlatoonManager(Soldier *leader, Soldier *sergeant, QList<Squad *> *squads, QList<Duty *>* duties, QObject *parent)
    :   QObject(parent), PlatoonLeader(leader), PlatoonSergeant(sergeant), squadList(squads), dutyList(duties)
{

}

Soldier *PlatoonManager::GetPlatoonLeader() const
{
    return PlatoonLeader;
}

void PlatoonManager::SetPlatoonLeader(Soldier *newLeader)
{
    PlatoonLeader = newLeader;
}

Soldier *PlatoonManager::GetPlatoonSergeant() const
{
    return PlatoonSergeant;
}

void PlatoonManager::SetPlatoonSergeant(Soldier *newSergeant)
{
    PlatoonSergeant = newSergeant;
}

QList<Squad *> *PlatoonManager::GetSquadList() const
{
    return squadList;
}

QList<Duty *> *PlatoonManager::GetDutyList() const
{
    return dutyList;
}
