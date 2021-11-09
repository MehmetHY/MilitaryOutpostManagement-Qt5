#include "Platoon.h"
#include "../Managers/squadmanager.h"
#include "../Managers/dutymanager.h"

Platoon::Platoon(const unsigned int id, const QString name, QObject *parent)
 : QObject(parent), platoonId(id), platoonName(name), squadManager(new SquadManager(this)), dutyManager(new DutyManager(this))
{

}

QString Platoon::GetName() const
{
    return platoonName;
}

void Platoon::SetName(const QString name)
{
    platoonName = name;
}

SquadManager *Platoon::GetSquadManager() const
{
    return squadManager;
}
