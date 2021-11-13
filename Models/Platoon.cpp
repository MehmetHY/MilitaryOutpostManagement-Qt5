#include "platoon.h"

Platoon::Platoon(const QString &name) : name(name)
{}

const QList<Squad *> &Platoon::getSquads() const
{
    return squads;
}

const QList<Duty *> &Platoon::getDuties() const
{
    return duties;
}

const QString &Platoon::getName() const
{
    return name;
}

void Platoon::setName(const QString &newName)
{
    name = newName;
}
