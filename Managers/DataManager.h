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

private:    //fields
    const QStringList requiredTableNames {"squad", "team", "soldier", "duty"};

private:    // functions
    void CreateTables() const;
    bool ConnectSQLITE() const;

public:     // methods
    void CreateConnection(DatabaseType type = DatabaseType::SQLITE) const;
    void CloseConnection() const;
    class QSqlQuery* ExecuteQuery(const QString queryString) const;

};

#endif // DATAMANAGER_H
