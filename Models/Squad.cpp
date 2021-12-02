#include "squad.h"
#include "../Data/datamanager.h"

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

void Squad::createSquad(const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO squad (name) VALUES (:name)");
    query.bindValue(":name", name);
    query.exec();
}

bool Squad::isSquadExist(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM squad WHERE name = (:name)");
    query.bindValue(":name", name);
    query.exec();
    if (query.next() && query.value(0).toInt() > 0)
        return true;
    return false;
}


