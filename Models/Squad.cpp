#include "squad.h"

Squad::Squad(const QString &name) : name(name)
{}

const QList<Team *> &Squad::getTeams() const
{
    return teams;
}

const QString &Squad::getName() const
{
    return name;
}

void Squad::setName(const QString &newName)
{
    name = newName;
}
