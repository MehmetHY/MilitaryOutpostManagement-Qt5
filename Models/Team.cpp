#include "team.h"
#include "../Data/datamanager.h"
#include "soldier.h"


Team::Team(const int id, const QString &name, const int squadId) : id(id), name(name), squadId(squadId)
{}

const int Team::getId() const
{
    return id;
}

const QString &Team::getName() const
{
    return name;
}

void Team::setName(const QString &newName)
{
    name = newName;
}

const int Team::getSquadId() const
{
    return squadId;
}

bool Team::isTeamExist(const QString &name, const int squadId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM team WHERE name = :name AND squad_id = :squadId;");
    query.bindValue(":name", name);
    query.bindValue(":squadId", squadId);
    DataManager::ExecuteQuery(query);
    return query.next() && query.value(0).toInt() > 0;
}

void Team::createTeam(const QString &name, const int squadId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO team (name, squad_id) VALUES (:name, :squadId)");
    query.bindValue(":name", name);
    query.bindValue(":squadId", squadId);
    DataManager::ExecuteQuery(query);
}

void Team::getAllTeamNames(const int squadId, QStringList& outList)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM team WHERE squad_id = " + QString::number(squadId) + ";";
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

void Team::deleteTeam(const int squadId, const QString &name)
{
    const QString queryString = "DELETE FROM team WHERE squad_id = " + QString::number(squadId) + " AND name = '" + name + "';";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
}

void Team::updateTeam(const int squadId, const QString &oldName, const QString &newName)
{
    QSqlQuery query;
    query.prepare("UPDATE team SET name = :newName WHERE squad_id = :squadId AND name = :oldName;");
    query.bindValue(":newName", newName);
    query.bindValue(":squadId", squadId);
    query.bindValue(":oldName", oldName);
    DataManager::ExecuteQuery(query);
}

int Team::getTeamId(const int squadId, const QString &name)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM team WHERE squad_id = " + QString::number(squadId) + " AND name = '" + name + "'";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int idId = query.record().indexOf("id");
        return query.value(idId).toInt();
    }
    return 0;
}

Team *Team::getTeamByName(const int squadId, const QString &name)
{
    int id = getTeamId(squadId, name);
    if (id) return new Team(id, name, squadId);
    return nullptr;
}

Team *Team::getTeamById(const int id)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM team WHERE id = " + QString::number(id) + ";";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int idIndex = query.record().indexOf("id");
        int nameIndex = query.record().indexOf("name");
        int squadIdIndex = query.record().indexOf("squad_id");

        int id = query.value(idIndex).toInt();
        QString name = query.value(nameIndex).toString();
        int squadId = query.value(squadIdIndex).toInt();
        return new Team(id, name, squadId);
    }
    return nullptr;
}
