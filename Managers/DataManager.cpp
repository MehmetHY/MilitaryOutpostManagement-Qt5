#include "DataManager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "Models/Squad.h"
#include "Models/Team.h"
#include "Models/Soldier.h"
#include "Models/Duty.h"

DataManager::DataManager(QObject *parent) : QObject(parent)
{

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
