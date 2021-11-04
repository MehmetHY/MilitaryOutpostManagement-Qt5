#include "PlatoonController.h"
#include "../Models/Duty.h"

PlatoonController::PlatoonController(QObject *parent) : QObject(parent)
{

}

PlatoonController::PlatoonController(Soldier *leader, Soldier *sergeant, QList<Squad *> *squads, QList<Duty *>* duties, QObject *parent)
    :   QObject(parent), PlatoonLeader(leader), PlatoonSergeant(sergeant), squadList(squads), dutyList(duties)
{

}

Soldier *PlatoonController::GetPlatoonLeader() const
{
    return PlatoonLeader;
}

void PlatoonController::SetPlatoonLeader(Soldier *newLeader)
{
    PlatoonLeader = newLeader;
}

Soldier *PlatoonController::GetPlatoonSergeant() const
{
    return PlatoonSergeant;
}

void PlatoonController::SetPlatoonSergeant(Soldier *newSergeant)
{
    PlatoonSergeant = newSergeant;
}

QList<Squad *> *PlatoonController::GetSquadList() const
{
    return squadList;
}

QList<Duty *> *PlatoonController::GetDutyList() const
{
    return dutyList;
}
