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

Soldier* Soldier::getSoldierById(int id)
{
    QString queryString = "SELECT * FROM soldier WHERE id = " + QString::number(id) + ";";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int nameId = query.record().indexOf("name");
        int rankId = query.record().indexOf("rank");
        int roleId = query.record().indexOf("role");
        QString name = query.value(nameId).toString();
        QString rank = query.value(rankId).toString();
        QString role = query.value(roleId).toString();
        Soldier* soldier = new Soldier(name, rank, role);
        return soldier;
    }
    qDebug() << "Couldn't find soldier with id: " + QString::number(id);
    return nullptr;
}

void Soldier::createSoldier(const QString &name, const QString &rank, const QString &role, const int teamId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO soldier (name, rank, role, team_id) VALUES (:name, :rank, :role, :teamId)");
    query.bindValue(":name", name);
    query.bindValue(":rank", rank);
    query.bindValue(":role", role);
    query.bindValue(":teamId", teamId);
    query.exec();
}

void Soldier::getAllSoldierNames(const int teamId, QStringList &outList)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM soldier WHERE team_id = " + QString::number(teamId) + ";";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int nameId = query.record().indexOf("name");
        do
        {
            outList << query.value(nameId).toString();
        } while (query.next());
    }
}

void Soldier::deleteSoldier(const QString &name, const int teamId)
{
    QSqlQuery query;
    const QString queryString = "DELETE FROM soldier WHERE team_id = " + QString::number(teamId) + " AND name = '" + name + "';";
    DataManager::ExecuteQuery(query, queryString);
}

int Soldier::getSoldierId(const int teamId, const QString &name)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM soldier WHERE team_id = " + QString::number(teamId) + " AND name = '" + name + "';";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int idId = query.record().indexOf("id");
        return query.value(idId).toInt();
    }
    return 0;
}
