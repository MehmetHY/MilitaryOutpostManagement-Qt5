#include "platoon.h"

Platoon::Platoon()
{}

const QList<Squad *> &Platoon::getSquads() const
{
    return squads;
}

const QList<Duty *> &Platoon::getDuties() const
{
    return duties;
}
