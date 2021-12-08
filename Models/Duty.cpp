#include "duty.h"
#include "../Data/datamanager.h"
#include "soldier.h"

Duty::Duty(const QString &name, Soldier *soldier, const QDateTime &startDate, const QDateTime &endDate)
    : name(name), soldier(soldier), startDate(startDate), endDate(endDate)
{}

Soldier *Duty::getSoldier() const
{
    return soldier;
}

void Duty::setSoldier(Soldier *newSoldier)
{
    soldier = newSoldier;
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
//    QString queryString = "SELECT * FROM duty;";
//    QSqlQuery query;
//    DataManager::ExecuteQuery(query, queryString);
//    if (query.next())
//    {
//        int nameColumnId = query.record().indexOf("name");
//        int soldierColumnId = query.record().indexOf("soldier_id");
//        int startColumnId = query.record().indexOf("start_date");
//        int endColumnId = query.record().indexOf("end_date");
//        do
//        {
//            QString name = query.value(nameColumnId).toString();
//            int soldierId = query.value(soldierColumnId).toInt();
//            Soldier* soldier = Soldier::getSoldierById(soldierId);
//            QDateTime startDate = query.value(startColumnId).toDateTime();
//            QDateTime endDate = query.value(endColumnId).toDateTime();
//            outList << new Duty(name, soldier, startDate, endDate);
//        } while (query.next());
//    }

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
