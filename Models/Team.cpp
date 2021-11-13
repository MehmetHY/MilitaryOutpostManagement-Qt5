#include "team.h"

Team::Team(const QString &name) : name(name)
{}

const QString &Team::getName() const
{
    return name;
}

void Team::setName(const QString &newName)
{
    name = newName;
}

const QList<Soldier *> &Team::getSoldiers() const
{
    return soldiers;
}
