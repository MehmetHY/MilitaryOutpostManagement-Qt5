#include "soldier.h"
#include "../Data/datamanager.h"

Soldier::Soldier(const int id, const QString &name, const int rankId, const QString &role, const int teamId)
    : id(id), name(name), rankId(rankId), role(role), teamId(teamId)
{}

const int Soldier::getId() const
{
    return id;
}

const int Soldier::getRankId() const
{
    return rankId;
}

void Soldier::setRankId(const int newRankId)
{
    rankId = newRankId;
}

const QString &Soldier::getRole() const
{
    return role;
}

void Soldier::setRole(const QString &newRole)
{
    role = newRole;
}

const int Soldier::getTeamId() const
{
    return teamId;
}

const QString &Soldier::getName() const
{
    return name;
}

void Soldier::setName(const QString &newName)
{
    name = newName;
}

Soldier* Soldier::getSoldierByName(const int teamId, const QString& name)
{
    int id = getSoldierId(teamId, name);
    if (id)
    {
        const int rankId = getSoldierRankId(id);
        const QString role = getSoldierRole(id);
        return new Soldier(id, name, rankId, role, teamId);
    }
    return nullptr;
}

void Soldier::createSoldier(const QString &name, const int rankId, const QString &role, const int teamId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO soldier (name, rank_id, role, team_id) VALUES (:name, :rankId, :role, :teamId)");
    query.bindValue(":name", name);
    query.bindValue(":rankId", rankId);
    query.bindValue(":role", role);
    query.bindValue(":teamId", teamId);
    query.exec();
}

void Soldier::updateSoldier(const int id, const QString &name, const int rankId, const QString &role)
{
    QSqlQuery query;
    query.prepare("UPDATE soldier SET name = :name, rank_id = :rankId, role = :role WHERE id = :id;");
    query.bindValue(":name", name);
    query.bindValue(":rankId", rankId);
    query.bindValue(":role", role);
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

const QString Soldier::getSoldierRole(const int id)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM soldier WHERE id = " + QString::number(id) + ";";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int roleId = query.record().indexOf("role");
        return query.value(roleId).toString();
    }
    return "";
}

const int Soldier::getSoldierRankId(const int id)
{
    QSqlQuery query;
    const QString queryString = "SELECT  * FROM soldier WHERE id = " + QString::number(id) + ";";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int rankIdIndex = query.record().indexOf("rank_id");
        return query.value(rankIdIndex).toInt();
    }
    return 0;
}
