#include "Platoon.h"
#include "Models/Squad.h"
#include "Models/Duty.h"

Platoon::Platoon(QObject *parent) : QObject(parent)
{

}

Soldier *Platoon::GetLeader() const
{
    return leader;
}

void Platoon::SetLeader(Soldier *soldier)
{
    leader = soldier;
}

Soldier *Platoon::GetSergeant() const
{
    return sergeant;
}

void Platoon::SetSergeant(Soldier *soldier)
{
    sergeant = soldier;
}

Squad *Platoon::GetSquad(unsigned int id) const
{
    for (Squad* squad : squads)
    {
        if (squad->GetId() == id)
            return squad;
    }
    return nullptr;
}

Duty *Platoon::GetDuty(unsigned int id) const
{
    for (Duty* duty : duties)
    {
        if (duty->GetId() == id)
            return duty;
    }
    return nullptr;
}

void Platoon::AddSquad(Squad *squad)
{
    squads.append(squad);
}

void Platoon::AddDuty(Duty *duty)
{
    duties.append(duty);
}

void Platoon::UpdateSquad(Squad* oldSquad, Squad* newSquad)
{
    int oldId = squads.indexOf(oldSquad);
    squads.replace(oldId, newSquad);
}

void Platoon::UpdateDuty(Duty* oldDuty, Duty* newDuty)
{
    int oldId = duties.indexOf(oldDuty);
    duties.replace(oldId, newDuty);
}

void Platoon::DeleteSquad(Squad *squad)
{
    squads.removeAll(squad);
}

void Platoon::DeleteDuty(Duty *duty)
{
    duties.removeAll(duty);
}
