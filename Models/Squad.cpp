#include "Squad.h"

Squad::Squad(QObject *parent) : QObject(parent)
{

}

unsigned int Squad::GetId() const
{
    return squadId;
}

QString Squad::GetName() const
{
    return squadName;
}
