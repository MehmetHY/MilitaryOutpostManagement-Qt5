#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

class DataManager : public QObject
{
    Q_OBJECT

public:     // enums
    enum class Table { SQUAD, TEAM, SOLDIER, DUTY };

public:     // constructors
    explicit DataManager(QObject *parent = nullptr);

private:    //fields
    const QStringList requiredTableNames {"squad", "team", "soldier", "duty"};

private:    // functions
    void ValidateTables() const;
    void CreateAbsentTable(const QString tableName) const;
    class QSqlQuery* ExecuteQuery(const QString queryString) const;

public:     // methods
    void CreateConnection(const QString& driver, const QString& connectionString) const;
    void CloseConnection() const;

    QList<class Squad*>* GetSquads(const QString whereCondition) const;
    QList<class Team*>* GetTeams(const QString whereCondition) const;
    QList<class Soldier*>* GetSoldiers(const QString whereCondition) const;
    QList<class Duty*>* GetDuties(const QString whereCondition) const;

    Squad* GetSquadById(unsigned int id) const;
    Team* GetTeamById(unsigned int id) const;
    Soldier* GetSoldierById(unsigned int id) const;
    Duty* GetDutyById(unsigned int id) const;

    unsigned int InsertSquad(Squad* squad) const;
    unsigned int InsertTeam(Team* team) const;
    unsigned int InsertSoldier(Soldier* soldier) const;
    unsigned int InsertDuty(Duty* duty) const;

    void UpdateSquad(Squad* squad) const;
    void UpdateTeam(Team* team) const;
    void UpdateSoldier(Soldier* soldier) const;
    void UpdateDuty(Duty* duty) const;

    void DeleteSquad(Squad* squad) const;
    void DeleteTeam(Team* team) const;
    void DeleteSoldier(Soldier* soldier) const;
    void DeleteDuty(Duty* duty) const;

};

#endif // DATAMANAGER_H
