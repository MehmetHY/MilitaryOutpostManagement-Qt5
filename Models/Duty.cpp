#include "duty.h"
#include "../Data/datamanager.h"
#include "soldier.h"

const int Duty::getSoldierId() const
{
    return soldierId;
}

void Duty::setSoldierId(const int newSoldierId)
{
    soldierId = newSoldierId;
}

Duty::Duty(const int id, const QString &name, const int soldierId, const QDateTime &startDate, const QDateTime &endDate)
    : id(id), name(name), soldierId(soldierId), startDate(startDate), endDate(endDate)
{}

const int Duty::getId() const
{
    return id;
}

const QDateTime &Duty::getStartDate() const
{
    return startDate;
}

void Duty::setStartDate(const QDateTime &newStartDate)
{
    startDate = newStartDate;
}

const QDateTime &Duty::getEndDate() const
{
    return endDate;
}

void Duty::setEndDate(const QDateTime &newEndDate)
{
    endDate = newEndDate;
}

const QString &Duty::getName() const
{
    return name;
}

void Duty::setName(const QString &newName)
{
    name = newName;
}

void Duty::getAllDuties(QList<Duty*>& outList)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM duty;";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int idIndex = query.record().indexOf("id");
        int nameIndex = query.record().indexOf("name");
        int soldierIdIndex = query.record().indexOf("soldier_id");
        int startDateIndex = query.record().indexOf("start_date");
        int endDateIndex = query.record().indexOf("end_date");
        do
        {
            int id = query.value(idIndex).toInt();
            QString name = query.value(nameIndex).toString();
            int soldierId = query.value(soldierIdIndex).toInt();
            QDateTime startDate = query.value(startDateIndex).toDateTime();
            QDateTime endDate = query.value(endDateIndex).toDateTime();
            outList << new Duty(id, name, soldierId, startDate, endDate);
        } while (query.next());
    }
}

void Duty::getAllDutyNames(QStringList &outList)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM duty;";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int nameIndex = query.record().indexOf("name");
        do
        {
            outList << query.value(nameIndex).toString();
        } while (query.next());
    }
}

void Duty::createDuty(const QString &name, const int soldierId, const QDateTime &startDate, const QDateTime &endDate)
{
    QSqlQuery query;
    query.prepare("INSERT INTO duty (name, soldier_id, start_date, end_date) VALUES (:name, :soldierId, :startDate, :endDate);");
    query.bindValue(":name", name);
    query.bindValue(":soldierId", soldierId);
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);
    DataManager::ExecuteQuery(query);
}

bool Duty::isDutyExist(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM duty WHERE name = :name;");
    query.bindValue(":name", name);
    DataManager::ExecuteQuery(query);
    return query.next() && query.value(0).toInt() > 0;
}

void Duty::deleteDuty(const QString &name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM duty WHERE name = :name;");
    query.bindValue(":name", name);
    DataManager::ExecuteQuery(query);
}

Duty *Duty::getDutyByName(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM duty WHERE name = :name;");
    query.bindValue(":name", name);
    DataManager::ExecuteQuery(query);
    if (query.next())
    {
        int idIndex = query.record().indexOf("id");
        int nameIndex = query.record().indexOf("name");
        int soldierIdIndex = query.record().indexOf("soldier_id");
        int startDateIndex = query.record().indexOf("start_date");
        int endDateIndex = query.record().indexOf("end_date");

        int id = query.value(idIndex).toInt();
        QString name = query.value(nameIndex).toString();
        int soldierId = query.value(soldierIdIndex).toInt();
        QDateTime startDate = query.value(startDateIndex).toDateTime();
        QDateTime endDate = query.value(endDateIndex).toDateTime();
        return new Duty(id, name, soldierId, startDate, endDate);
    }
    return nullptr;
}

void Duty::updateDuty(const int id, const QString &name, const int soldierId, const QDateTime &startDate, const QDateTime &endDate)
{
    QSqlQuery query;
    query.prepare("UPDATE duty SET name = :name, soldier_id = :soldierId, start_date = :startDate, end_date = :endDate WHERE id = :id;");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":soldierId", soldierId);
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);
    DataManager::ExecuteQuery(query);
}
