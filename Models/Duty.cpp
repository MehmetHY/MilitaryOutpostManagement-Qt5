#include "duty.h"

Duty::Duty(const QString &name, Soldier *soldier, const QDateTime &startDate, const QDateTime &endDate)
    : name(name), soldier(soldier), startDate(startDate), endDate(endDate)
{}

Soldier *Duty::getSoldier() const
{
    return soldier;
}

void Duty::setSoldier(Soldier *newSoldier)
{
    soldier = newSoldier;
}

const QDateTime &Duty::getStartDate() const
{
    return startDate;
}

void Duty::setStartDate(const QDateTime &newStartDate)
{
    startDate = newStartDate;
}

const QDateTime &Duty::getEndDate() const
{
    return endDate;
}

void Duty::setEndDate(const QDateTime &newEndDate)
{
    endDate = newEndDate;
}

const QString &Duty::getName() const
{
    return name;
}

void Duty::setName(const QString &newName)
{
    name = newName;
}
