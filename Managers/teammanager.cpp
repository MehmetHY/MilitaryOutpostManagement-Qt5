#include "teammanager.h"
#include "../Models/Squad.h"
#include "../Models/Team.h"
#include "DataManager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

TeamManager::TeamManager(Squad *parent) : QObject(parent), squad(parent), teams(new QList<Team*>)
{
    LoadTeamsFromDB();
}

TeamManager::~TeamManager()
{
    delete teams;
}

void TeamManager::LoadTeamsFromDB()
{
    teams->clear();
    const QString queryString =
            "SELECT * FROM team "
            "WHERE "
            "   squad_id = " + QString::number(squad->GetId()) + ";";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        qDebug() << "Found Teams.";
        int indexId = query.record().indexOf("id");
        int indexName = query.record().indexOf("name");
        do
        {
            unsigned int id = query.value(indexId).toUInt();
            QString name = query.value(indexName).toString();
            qDebug() << "Team ID: " << id << ", NAME: " << name;
            teams->append(new Team(id, name, squad));
        } while (query.next());
    }
    else
        qDebug() << "No team found!";
}

QList<Team *> *TeamManager::GetTeams() const
{
    return teams;
}
