#include "Squad.h"

Squad::Squad(QObject *parent) : QObject(parent)
{

}

Squad::Squad(unsigned int id, QString name, QObject *parent)
    :   QObject(parent), squadId(id), squadName(name)
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
