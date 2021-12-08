#include "squad.h"
#include "../Data/datamanager.h"

Squad::Squad(const int id, const QString &name) : id(id), name(name)
{}

const int Squad::getId() const
{
    return id;
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
    DataManager::ExecuteQuery(query);
}

bool Squad::isSquadExist(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM squad WHERE name = (:name)");
    query.bindValue(":name", name);
    DataManager::ExecuteQuery(query);
    return query.next() && query.value(0).toInt() > 0;
}

void Squad::getAllSquadNames(QStringList &outList)
{
    const QString queryString = "SELECT * FROM squad;";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int nameId = query.record().indexOf("name");
        do
        {
            QString name = query.value(nameId).toString();
            outList << name;
        } while (query.next());
    }
}

void Squad::deleteSquad(const QString &name)
{
    const QString queryString = "DELETE FROM squad WHERE name = '" + name + "';";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
}

void Squad::updateSquad(const QString &newName, const QString &oldName)
{
    QSqlQuery query;
    query.prepare("UPDATE squad SET name = :newName WHERE name = :oldName;");
    query.bindValue(":newName", newName);
    query.bindValue(":oldName", oldName);
    DataManager::ExecuteQuery(query);
}

int Squad::getIdByName(const QString &name)
{
    const QString queryString = "SELECT * FROM squad WHERE name = '" + name + "';";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        return query.value(0).toInt();
    }
    return 0;
}

Squad *Squad::getSquadByName(const QString &name)
{
    int id = getIdByName(name);
    if (id) return new Squad(id, name);
    return nullptr;
}

Squad *Squad::getSquadById(const int id)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM squad WHERE id = " + QString::number(id) + ";";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int idIndex = query.record().indexOf("id");
        int nameIndex = query.record().indexOf("name");

        int id = query.value(idIndex).toInt();
        QString name = query.value(nameIndex).toString();
        return new Squad(id, name);
    }
    return nullptr;
}


