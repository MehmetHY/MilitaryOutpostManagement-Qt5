#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

class DataManager
{
public:     // enums
    enum class DatabaseType { JSON, SQLITE, MYSQL, MSSQL };

public:     // constructors
    explicit DataManager() = delete;

private:    // functions
    static bool ConnectSQLITE();
    static void CreateTables();
    static void CreateSquadTable();
    static void CreateTeamTable();
    static void CreateRankTable();
    static void CreateSoldierTable();
    static void CreateDutyTable();
    static void InsertRanks();

public:     // methods
    static void Initialize();
    static void End();
    static void CreateConnection(const DatabaseType type = DatabaseType::SQLITE);
    static void CloseConnection();
    static bool ExecuteQuery(class QSqlQuery& outQuery, const QString queryString);
};

#endif // DATAMANAGER_H
