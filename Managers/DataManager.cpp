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

void DataManager::CreateConnection(DatabaseType type)
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
    else
        qDebug() << "Database connection failed!";
}

void DataManager::CloseConnection()
{
    QSqlDatabase::database().close();
}

bool DataManager::ConnectSQLITE()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./MilitaryOutput.db");
    if (!db.open())
    {
        qDebug() << "Failed to connect to the database.";
        return false;
    }
    return true;
}

bool DataManager::ExecuteQuery(QSqlQuery& outQuery, const QString queryString)
{
    if (!outQuery.exec(queryString))
    {
        qDebug() << "Query failed: " << queryString;
        qDebug() << outQuery.lastError().text();
        return false;
    }
    return true;
}

void DataManager::CreateTables()
{
    CreatePlatoonTable();
    CreateSquadTable();
    CreateTeamTable();
    CreateRankTable();
    CreateRoleTable();
    CreateSoldierTable();
    CreateDutyTable();
    InsertRanks();
    InsertRoles();
}

void DataManager::CreatePlatoonTable()
{
    QString queryString = R"(
CREATE TABLE IF NOT EXISTS platoon
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name STRING(50) UNIQUE NOT NULL
);
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateSquadTable()
{
    QString queryString = R"(
CREATE TABLE IF NOT EXISTS squad
(
   id INTEGER PRIMARY KEY AUTOINCREMENT,
   name STRING(50) UNIQUE NOT NULL
);
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateTeamTable()
{
    QString queryString = R"(
CREATE TABLE IF NOT EXISTS team
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name STRING(50) NOT NULL UNIQUE,
    squad_id INTEGER REFERENCES squad(id) NOT NULL
);
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateRankTable()
{
    QString queryString = R"(
CREATE TABLE IF NOT EXISTS rank
(
    id INTEGER PRIMARY KEY NOT NULL,
    name STRING(50) NOT NULL UNIQUE,
    abbr STRING(50) NOT NULL UNIQUE
);
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateRoleTable()
{
    QString queryString = R"(
CREATE TABLE IF NOT EXISTS role
(
    id INTEGER PRIMARY KEY NOT NULL,
    name STRING(50) NOT NULL UNIQUE
);
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateSoldierTable()
{
    QString queryString = R"(
CREATE TABLE IF NOT EXISTS soldier
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name STRING(50) UNIQUE NOT NULL,
    rank_id INTEGER REFERENCES rank(id) NOT NULL,
    role_id INTEGER REFERENCES role(id) NOT NULL,
    team_id INTEGER REFERENCES team(id) DEFAULT NULL
);
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateDutyTable()
{
    QString queryString = R"(
CREATE TABLE IF NOT EXISTS duty
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name STRING(50) NOT NULL,
    soldier_id INTEGER REFERENCES soldier(id) NOT NULL,
    start_date DATETIME,
    end_date DATETIME
);
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::InsertRanks()
{
    QString queryString = R"(
INSERT OR IGNORE INTO rank
    (id, name, abbr)
VALUES
    (1, 'Private', 'PVT'),
    (2, 'Corporal', 'CPL'),
    (3, 'Sergeant', 'SGT'),
    (4, 'Staff Sergeant', 'SSG'),
    (5, 'Sergeant First Class', 'SFC'),
    (6, 'Lieutenant', 'LT');
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::InsertRoles()
{
    QString queryString = R"(
INSERT OR IGNORE INTO role
    (id, name)
VALUES
    (1, 'Rifleman'),
    (2, 'Automatic Rifleman'),
    (3, 'Grenadier'),
    (4, 'Marksman'),
    (5, 'Team Leader'),
    (6, 'Squad Leader'),
    (7, 'Platoon Sergeant'),
    (8, 'Platoon Leader');
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}
