#include "platoonmanager.h"
#include "DataManager.h"
#include "../Models/Platoon.h"
#include <QSqlQuery>
#include <QVariant>

PlatoonManager::PlatoonManager(DataManager* manager, QObject *parent)
    : QObject(parent), dataManager(manager)
{
}

bool PlatoonManager::IsPlatoonExist() const
{
    const QString queryString = "SELECT * FROM platoon;";
    QSqlQuery query;
    dataManager->ExecuteQuery(query, queryString);
    return query.size() > 0;
}

void PlatoonManager::LoadPlatoonFromDB()
{
    const QString queryString = "SELECT * FROM platoon;";
    QSqlQuery query;
    dataManager->ExecuteQuery(query, queryString);
    unsigned int id = 0;
    QString name = "";

}

Platoon *PlatoonManager::GetPlatoon() const
{
    return platoon;
}

void PlatoonManager::CreateNewPlatoon(const QString name)
{
    QString queryString =
            "INSERT INTO platoon"
            "(" + name + ");";
    QSqlQuery query;
    if(!dataManager->ExecuteQuery(query, queryString))
        return;
    unsigned int id = query.lastInsertId().toUInt();
    platoon = new Platoon(id, name, this);
}
