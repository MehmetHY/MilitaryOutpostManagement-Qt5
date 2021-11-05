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

void DataManager::ValidateTables() const
{
    QStringList existingTableNames = QSqlDatabase::database().tables();
    for (const QString& table : requiredTableNames)
    {
        if (!existingTableNames.contains(table))
            qDebug() << "absent table found. Creating table: " << table;
            CreateAbsentTable(table);
    }
}

void DataManager::CreateAbsentTable(const QString tableName) const
{
    QString queryString;
    if (tableName == "squad")
        queryString = R"(
            CREATE TABLE squad (
                id          INTEGER     PRIMARY KEY AUTOINCREMENT,
                name        STRING(50)  NOT NULL
            );
            )";
    else if (tableName == "team")
        queryString = R"(
            CREATE TABLE team (
                id          INTEGER     PRIMARY KEY     AUTOINCREMENT,
                name        STRING(50)  NOT NULL,
                squad_id    INTEGER     REFERENCES squad(id)    NOT NULL
            );
            )";
    else if (tableName == "soldier")
        queryString = R"(
            CREATE TABLE soldier (
                id          INTEGER      PRIMARY KEY    AUTOINCREMENT,
                name        STRING(50)   NOT NULL,
                rank        INTEGER (20) NOT NULL,
                role        INTEGER (10) NOT NULL,
                shift_time  INTEGER (2),
                team_id     INTEGER      REFERENCES team (id)
            );
            )";
    else if (tableName == "duty")
        queryString = R"(
            CREATE TABLE duty (
                id          INTEGER         PRIMARY KEY     AUTOINCREMENT,
                name        STRING(50)      NOT NULL,
                soldier     INTEGER         REFERENCES soldier (id)     NOT NULL,
                start_date  DATETIME        NOT NULL,
                end_time    DATETIME        NOT NULL
            );
            )";

    QSqlQuery* query = ExecuteQuery(queryString);
    delete query;
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

void DataManager::CreateConnection(const QString &driver, const QString &connectionString) const
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Data/MilitaryOutput.db");
    if (!db.open())
    {
        qDebug() << "Failed to connect to the database.";
        return;
    }
    ValidateTables();
}

void DataManager::CloseConnection() const
{
    QSqlDatabase::database().close();
}

QList<Squad *>* DataManager::GetSquads(const QString whereCondition) const
{
    QList<Squad*>* squads = new QList<Squad*>();
    QString queryString = "select * from squad " + whereCondition + ";";
    QSqlQuery* query = ExecuteQuery(queryString);

    while (query->next())
    {
        unsigned int id = query->value(0).toUInt();
        QString name = query->value(1).toString();
        squads->append(new Squad(id, name));
    }

    delete query;
    return squads;
}

QList<Team *>* DataManager::GetTeams(const QString whereCondition) const
{
    QList<Team*>* teams = new QList<Team*>();
    QString queryString = "select * from team " + whereCondition + ";";
    QSqlQuery* query = ExecuteQuery(queryString);

    while (query->next())
    {
        unsigned int id = query->value(0).toUInt();
        QString name = query->value(1).toString();
        unsigned int squad_id = query->value(2).toUInt();
        QString squadQueryWhereCondition = "WHERE id = " + QString::number(squad_id);
        auto squadList = GetSquads(squadQueryWhereCondition);
        Squad* squad = (*squadList)[0];
        teams->append(new Team(id, name, squad));
        delete squadList;
    }

    delete query;
    return teams;

}

QList<Soldier *>* DataManager::GetSoldiers(const QString whereCondition) const
{

}

QList<Duty *>* DataManager::GetDuties(const QString whereCondition) const
{

}

unsigned int DataManager::InsertSquad(Squad *squad) const
{

}

unsigned int DataManager::InsertTeam(Team *team) const
{

}

unsigned int DataManager::InsertSoldier(Soldier *soldier) const
{

}

unsigned int DataManager::InsertDuty(Duty *duty) const
{

}

void DataManager::UpdateSquad(Squad *squad) const
{

}

void DataManager::UpdateTeam(Team *team) const
{

}

void DataManager::UpdateSoldier(Soldier *soldier) const
{

}

void DataManager::UpdateDuty(Duty *duty) const
{

}

void DataManager::DeleteSquad(Squad *squad) const
{

}

void DataManager::DeleteTeam(Team *team) const
{

}

void DataManager::DeleteSoldier(Soldier *soldier) const
{

}

void DataManager::DeleteDuty(Duty *duty) const
{

}
