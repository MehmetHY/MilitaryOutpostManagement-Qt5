#include "platoonmanager.h"
#include "DataManager.h"
#include "../Models/Platoon.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>

PlatoonManager::PlatoonManager(QObject *parent)
    : QObject(parent), platoon(nullptr)
{
    LoadPlatoonFromDB();
}

bool PlatoonManager::IsPlatoonExist() const
{
    return platoon != nullptr;
}

void PlatoonManager::LoadPlatoonFromDB()
{
    if (platoon) return;
    const QString queryString = "SELECT * FROM platoon;";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int indexId = query.record().indexOf("id");
        int indexName = query.record().indexOf("name");
        unsigned int id = query.value(indexId).toUInt();
        QString name = query.value(indexName).toString();
        platoon = new Platoon(id, name, this);
        qDebug() << "Platoon found. ID: " << id << ", NAME: " << name;
    }
    else
    {
        platoon = nullptr;
        qDebug() << "No platoon found!";
    }
}

Platoon *PlatoonManager::GetPlatoon() const
{
    return platoon;
}

void PlatoonManager::CreateNewPlatoon(const QString name)
{
    const QString queryString =
            "INSERT INTO platoon "
            "   (name) "
            "VALUES "
            "   (\"" + name + "\");";
    QSqlQuery query;
    if(!DataManager::ExecuteQuery(query, queryString))
        return;
    unsigned int id = query.lastInsertId().toUInt();
    platoon = new Platoon(id, name, this);
}
