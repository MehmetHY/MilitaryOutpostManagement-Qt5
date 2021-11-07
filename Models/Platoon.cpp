#include "Platoon.h"
#include "../Managers/squadmanager.h"
#include "../Managers/dutymanager.h"

Platoon::Platoon(unsigned int id, const QString name, QObject *parent)
 : QObject(parent), platoonId(id), platoonName(name), platoonLeader(nullptr), platoonSergeant(nullptr), squadManager(new SquadManager(this)), dutyManager(new DutyManager(this))
{

}

void Platoon::SetName(const QString name)
{
    platoonName = name;
}
