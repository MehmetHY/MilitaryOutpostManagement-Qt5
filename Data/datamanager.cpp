#include "datamanager.h"

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

void DataManager::Initialize()
{
    CreateConnection(DatabaseType::SQLITE);
}

void DataManager::End()
{
    CloseConnection();
}

bool DataManager::ConnectSQLITE()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./MilitaryOutpost.db");
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
    CreateSquadTable();
    CreateTeamTable();
    CreateRankTable();
    CreateSoldierTable();
    CreateDutyTable();
    InsertRanks();
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
    name STRING(50) NOT NULL,
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
    id INTEGER PRIMARY KEY AUTOINCREMENT,
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
    name STRING(50) NOT NULL,
    rank STRING(50) NOT NULL,
    role STRING(50) NOT NULL,
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
INSERT INTO rank
    (name)
VALUES
    ('Private'),
    ('Private First Class'),
    ('Corporal'),
    ('Sergeant'),
    ('Staff Sergeant'),
    ('Sergeant First Class'),
    ('Master Sergeant'),
    ('First Sergeant'),
    ('Sergeant Major'),
    ('Second Lieutenant'),
    ('First Lieutenant'),
    ('Captain');
)";
    QSqlQuery query;
    ExecuteQuery(query, queryString);

}
