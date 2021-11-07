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
    class Soldier* GetSoldier(unsigned int id) const;
    void LoadSquads(class Platoon* platoon) const;
    void LoadTeams(class Squad* squad) const;
    void LoadSoldiers(class Team* team) const;

public:     // methods
    void CreateConnection(DatabaseType type = DatabaseType::SQLITE) const;
    void CloseConnection() const;
    class QSqlQuery* ExecuteQuery(const QString queryString) const;

    class Platoon* GetPlatoon() const;

};

#endif // DATAMANAGER_H
