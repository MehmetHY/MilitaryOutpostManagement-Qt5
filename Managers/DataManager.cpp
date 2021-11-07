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

DataManager::~DataManager()
{
    CloseConnection();
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
    else
        qDebug() << "Database connection failed!";
}

void DataManager::CloseConnection() const
{
    QSqlDatabase::database().close();
}

bool DataManager::ConnectSQLITE() const
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

bool DataManager::ExecuteQuery(QSqlQuery& outQuery, const QString queryString) const
{
    if (!outQuery.exec(queryString))
    {
        qDebug() << "Query failed: " << queryString;
        qDebug() << outQuery.lastError().text();
        return false;
    }
    return true;
}

void DataManager::CreateTables() const
{
    CreateSquadTable();
    CreateTeamTable();
    CreateRankTable();
    CreateRoleTable();
    CreateSoldierTable();
    CreateDutyTable();
    CreatePlatoonTable();
}

void DataManager::CreateSquadTable() const
{
    QString queryString =
            "CREATE TABLE IF NOT EXISTS squad "
            "("
            "   id      INTEGER         PRIMARY KEY    AUTOINCREMENT,"
            "   name    STRING (50)     UNIQUE         NOT NULL"
            ");";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateTeamTable() const
{
    QString queryString =
            "CREATE TABLE IF NOT EXISTS team "
            "("
            "    id          INTEGER         PRIMARY KEY             AUTOINCREMENT,"
            "    name        STRING (50)     NOT NULL                UNIQUE,"
            "    squad_id    INTEGER         REFERENCES squad (id)   NOT NULL"
            ");";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateRankTable() const
{
    QString queryString =
            "CREATE TABLE IF NOT EXISTS rank"
            "("
            "    id      INTEGER        PRIMARY KEY    AUTOINCREMENT,"
            "    name    STRING (50)    NOT NULL       UNIQUE"
            ");";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateRoleTable() const
{
    QString queryString =
            "CREATE TABLE IF NOT EXISTS role"
            "("
            "    id      INTEGER        PRIMARY KEY    AUTOINCREMENT,"
            "    name    STRING (50)    NOT NULL       UNIQUE"
            ");";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateSoldierTable() const
{
    QString queryString =
            "CREATE TABLE IF NOT EXISTS soldier "
            "("
            "    id          INTEGER         PRIMARY KEY             AUTOINCREMENT,"
            "    name        STRING (50)     UNIQUE                  NOT NULL,"
            "    rank_id     INTEGER         REFERENCES rank (id)    NOT NULL,"
            "    role_id     INTEGER         REFERENCES role (id)    NOT NULL,"
            "    team_id     INTEGER         REFERENCES team (id)    DEFAULT NULL"
            ");";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreateDutyTable() const
{
    QString queryString =
            "CREATE TABLE IF NOT EXISTS duty "
            "("
            "    id          INTEGER         PRIMARY KEY                 AUTOINCREMENT,"
            "    name        STRING (50)     NOT NULL,"
            "    soldier_id  INTEGER         REFERENCES soldier (id)     NOT NULL,"
            "    start_date  DATETIME,"
            "    end_date    DATETIME"
            ");";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}

void DataManager::CreatePlatoonTable() const
{
    QString queryString =
            "CREATE TABLE IF NOT EXISTS platoon "
            "("
            "    id          INTEGER         PRIMARY KEY                 AUTOINCREMENT,"
            "    name        STRING (50)     UNIQUE                      NOT NULL,"
            "    leader_id   INTEGER         REFERENCES soldier (id),"
            "    sergeant_id INTEGER         REFERENCES soldier (id)"
            ");";
    QSqlQuery query;
    ExecuteQuery(query, queryString);
}
