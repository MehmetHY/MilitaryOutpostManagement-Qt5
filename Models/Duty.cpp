#include "Duty.h"

Duty::Duty(QObject *parent) : QObject(parent)
{

}

Duty::Duty(unsigned int id, QString name, Soldier *soldier, QDateTime *startDate, QDateTime *endDate, QObject *parent)
    :   QObject(parent), dutyId(id), dutyName(name), dutyAssignedSoldier(soldier), dutyStartDate(startDate), dutyEndDate(endDate)
{

}

unsigned int Duty::GetId() const
{
    return dutyId;
}

QString Duty::GetName() const
{
    return dutyName;
}

Soldier *Duty::GetAssignedSoldier() const
{
    return dutyAssignedSoldier;
}

void Duty::SetAssignedSoldier(Soldier *soldier)
{
    dutyAssignedSoldier = soldier;
}

QDateTime *Duty::GetStartDate() const
{
    return dutyStartDate;
}

void Duty::SetStartDate(QDateTime *startDate)
{
    dutyStartDate = startDate;
}

QDateTime *Duty::GetEndDate() const
{
    return dutyEndDate;
}

void Duty::SetEndDate(QDateTime *endDate)
{
    dutyEndDate = endDate;
}
