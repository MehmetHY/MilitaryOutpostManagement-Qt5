#include "soldier.h"

Soldier::Soldier(const QString &name, const QString &rank, const QString &role)
    : name(name), rank(rank), role(role)
{}

const QString &Soldier::getRank() const
{
    return rank;
}

void Soldier::setRank(const QString &newRank)
{
    rank = newRank;
}

const QString &Soldier::getRole() const
{
    return role;
}

void Soldier::setRole(const QString &newRole)
{
    role = newRole;
}

const QString &Soldier::getName() const
{
    return name;
}

void Soldier::setName(const QString &newName)
{
    name = newName;
}
