#include "DataManager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "Models/Platoon.h"
#include "Models/Squad.h"
#include "Models/Team.h"
#include "Models/Soldier.h"
#include "Models/Duty.h"

DataManager::DataManager(QObject *parent) : QObject(parent)
{

}

void DataManager::CreateConnection(DatabaseType type) const
{
    bool success = false;
    switch (type)
    {
    case DataManager::DatabaseType::JSON:
        // todo: Handle JSON parsing
        break;
    case DataManager::DatabaseType::SQLITE:
        success = ConnectSQLITE();
        break;
    case DataManager::DatabaseType::MYSQL:
        // todo: Handle MYSQL / MariaDB connection
        break;
    case DataManager::DatabaseType::MSSQL:
        // todo: Handle MSSQL connection
        break;
    }
    if (success)
        CreateTables();
}

void DataManager::CloseConnection() const
{
    QSqlDatabase::database().close();
}

void DataManager::CreateTables() const
{
    QString queryString = R"(
-- squad
CREATE TABLE IF NOT EXISTS squad (
    id      INTEGER         PRIMARY KEY    AUTOINCREMENT,
    name    STRING (50)     UNIQUE         NOT NULL
);

-- team
CREATE TABLE IF NOT EXISTS team (
    id          INTEGER         PRIMARY KEY             AUTOINCREMENT,
    name        STRING (50)     NOT NULL                UNIQUE,
    squad_id    INTEGER         REFERENCES squad (id)   NOT NULL
);

-- rank
CREATE TABLE IF NOT EXISTS rank (
    id      INTEGER        PRIMARY KEY    AUTOINCREMENT,
    name    STRING (50)    NOT NULL       UNIQUE
);

-- role
CREATE TABLE IF NOT EXISTS role (
    id      INTEGER        PRIMARY KEY    AUTOINCREMENT,
    name    STRING (50)    NOT NULL       UNIQUE
);

-- soldier
CREATE TABLE IF NOT EXISTS soldier (
    id          INTEGER         PRIMARY KEY             AUTOINCREMENT,
    name        STRING (50)     UNIQUE                  NOT NULL,
    rank_id     INTEGER         REFERENCES rank (id)    NOT NULL,
    role_id     INTEGER         REFERENCES role (id)    NOT NULL,
    team_id     INTEGER         REFERENCES team (id)    DEFAULT NULL
);

-- duty
CREATE TABLE IF NOT EXISTS duty (
    id          INTEGER         PRIMARY KEY                 AUTOINCREMENT,
    name        STRING (50)     NOT NULL,
    soldier_id  INTEGER         REFERENCES soldier (id)     NOT NULL,
    start_date  DATETIME,
    end_date    DATETIME
);

-- platoon
CREATE TABLE IF NOT EXISTS platoon (
    id          INTEGER         PRIMARY KEY                 AUTOINCREMENT,
    name        STRING (50)     UNIQUE                      NOT NULL,
    leader_id   INTEGER         REFERENCES soldier (id),
    sergeant_id INTEGER         REFERENCES soldier (id)
);
    )";

    QSqlQuery* query = ExecuteQuery(queryString);
    delete query;
}

bool DataManager::ConnectSQLITE() const
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Data/MilitaryOutput.db");
    if (!db.open())
    {
        qDebug() << "Failed to connect to the database.";
        return false;
    }
    return true;
}

QSqlQuery *DataManager::ExecuteQuery(const QString queryString) const
{
    QSqlQuery* query = new QSqlQuery();
    if (!query->exec(queryString))
    {
        qDebug() << "Query failed: " << queryString;
        qDebug() << query->lastError().text();
    }
    return query;
}

Platoon *DataManager::GetPlatoon() const
{
    QString queryString = "SELECT * FROM platoon;";
    QSqlQuery* query = ExecuteQuery(queryString);
    Platoon* platoon = nullptr;
    if (query->size() < 1)
    {
        // todo: Redirect to Platoon Creation View
    }
    else
    {
        query->next();
        unsigned int id = query->value(0).toUInt();
        QString name = query->value(1).toString();
        unsigned int leader_id = NULL;
        Soldier* leader = nullptr;
        if (!query->value(2).isNull())
        {
            leader_id = query->value(2).toUInt();
            leader = GetSoldier(leader_id);
        }
        unsigned int sergeant_id = NULL;
        Soldier* sergeant = nullptr;
        if (!query->value(3).isNull())
        {
            sergeant_id = query->value(3).toUInt();
            sergeant = GetSoldier(sergeant_id);
        }
        platoon = new Platoon(id, name, leader, sergeant);
    }
    delete query;
    return platoon;
}

Soldier *DataManager::GetSoldier(unsigned int id) const
{
    Soldier* soldier = nullptr;
    QString queryString = "SELECT * FROM soldier WHERE id = " + QString::number(id) + ";";
    QSqlQuery* query = ExecuteQuery(queryString);
    if (query->size() > 0)
    {
        query->next();
        unsigned int id = query->value(0).toUInt();
        QString name = query->value(1).toString();
        unsigned int rankId = query->value(2).toUInt();
        unsigned int roleId = query->value(3).toUInt();
        soldier = new Soldier(id, name, rankId, roleId);
    }
    delete query;

    return soldier;
}

void DataManager::LoadSquads(Platoon* platoon) const
{
    platoon->squads.clear();
    QSqlQuery* query = ExecuteQuery(QString("SELECT * FROM squad;"));
    while (query->next())
    {
        unsigned int id = query->value(0).toUInt();
        QString name = query->value(1).toString();
        platoon->squads.append(new Squad(id, name, platoon));
    }
    delete query;
}

void DataManager::LoadTeams(Squad *squad) const
{
    squad->teams.clear();
    QString queryString = "SELECT * FROM team WHERE squad_id = " + QString::number(squad->squadId) + ";";
    QSqlQuery* query = ExecuteQuery(queryString);
    while (query->next())
    {
        unsigned int id = query->value(0).toUInt();
        QString name = query->value(1).toString();
        squad->teams.append(new Team(id, name, squad));
    }
    delete query;
}

void DataManager::LoadSoldiers(Team *team) const
{
    team->soldiers.clear();
    QString queryString = "SELECT * FROM soldier WHERE team_id = " + QString::number(team->teamId) + ";";
    QSqlQuery* query = ExecuteQuery(queryString);
    while (query->next())
    {
        unsigned int id = query->value(0).toUInt();
        QString name = query->value(1).toString();
        unsigned int rankId = query->value(2).toUInt();
        unsigned int roleId = query->value(3).toUInt();
        team->soldiers.append(new Soldier(id, name, rankId, roleId, team));
    }
    delete query;
}


