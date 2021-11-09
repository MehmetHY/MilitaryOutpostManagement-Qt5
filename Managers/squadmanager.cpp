#include "squadmanager.h"
#include "DataManager.h"
#include "../Models/Platoon.h"
#include "../Models/Squad.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

SquadManager::SquadManager(Platoon *parent)
    : QObject(parent), platoon(parent), squads(new QList<Squad*>)
{
    LoadSquadsFromDB();
}

SquadManager::~SquadManager()
{
    delete squads;
}

int SquadManager::GetSquadCount() const
{
    return squads->size();
}

QList<Squad*> *SquadManager::GetSquads() const
{
    return squads;
}

void SquadManager::LoadSquadsFromDB()
{
    squads->clear();
    const QString queryString = "SELECT * FROM squad;";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        qDebug() << "Found squads";
        int indexId = query.record().indexOf("id");
        int indexName = query.record().indexOf("name");
        do
        {
            unsigned int id = query.value(indexId).toUInt();
            QString name = query.value(indexName).toString();
            qDebug() << "Squad ID: " << id << ", NAME: " << name;
            squads->append(new Squad(id, name, platoon));
        } while (query.next());
    }
    else
        qDebug() << "No squads found!";
}
