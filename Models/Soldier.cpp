#include "Soldier.h"

Soldier::Soldier(QObject *parent) : QObject(parent)
{

}

int Soldier::GetId() const
{
    return soldierId;
}

QString Soldier::GetName() const
{
    return soldierName;
}
