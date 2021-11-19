#include "soldier.h"
#include "../Data/datamanager.h"

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

void Soldier::populateTeam(QList<Soldier *> outList, unsigned int id)
{
    const QString queryString = "SELECT * FROM soldier WHERE team_id = " + QString::number(id) +";";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int nameId = query.record().indexOf("name");
        int rankId = query.record().indexOf("rank");
        int roleId = query.record().indexOf("role");
        do
        {
            QString name = query.value(nameId).toString();
            QString rank = query.value(rankId).toString();
            QString role = query.value(roleId).toString();
            Soldier* soldier = new Soldier(name, rank, role);
            outList << soldier;
        } while (query.next());
    }
}
