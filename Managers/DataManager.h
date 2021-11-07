#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

class DataManager : public QObject
{
    Q_OBJECT

public:     // enums
    enum class DatabaseType { JSON, SQLITE, MYSQL, MSSQL };

public:     // constructors
    explicit DataManager(QObject *parent = nullptr);
    ~DataManager();

private:    // functions
    bool ConnectSQLITE() const;
    void CreateTables() const;
    void CreateSquadTable() const;
    void CreateTeamTable() const;
    void CreateRankTable() const;
    void CreateRoleTable() const;
    void CreateSoldierTable() const;
    void CreateDutyTable() const;
    void CreatePlatoonTable() const;

public:     // methods
    void CreateConnection(DatabaseType type = DatabaseType::SQLITE) const;
    void CloseConnection() const;
    bool ExecuteQuery(class QSqlQuery& outQuery, const QString queryString) const;
};

#endif // DATAMANAGER_H
