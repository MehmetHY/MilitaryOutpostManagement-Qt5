#include "soldiermanager.h"
#include "../Models/Team.h"
#include "../Models/Soldier.h"
#include "DataManager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

SoldierManager::SoldierManager(Team *parent) : QObject(parent), team(parent), soldiers(new QList<Soldier*>())
{

}

SoldierManager::~SoldierManager()
{
    delete soldiers;
}

QList<Soldier *> *SoldierManager::GetSoldiers() const
{
    return soldiers;
}

void SoldierManager::LoadSoldiersFromDB()
{
    soldiers->clear();
    const QString queryString =
            "SELECT * FROM soldier "
            "WHERE "
            "   team_id = " + QString::number(team->GetId()) + ";";
    QSqlQuery query;
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        qDebug() << "Found soldiers.";
        int indexId = query.record().indexOf("id");
        int indexName = query.record().indexOf("name");
        int indexRankId = query.record().indexOf("rank_id");
        int indexRoleId = query.record().indexOf("role_id");
        do
        {
            unsigned int id = query.value(indexId).toUInt();
            QString name = query.value(indexName).toString();
            unsigned int rankId = query.value(indexRankId).toUInt();
            unsigned int roleId = query.value(indexRoleId).toUInt();
            qDebug() << "Soldier ID: " << id << ", NAME: " << name << ", RANK: " << rankId << ", ROLE: " << roleId;
            soldiers->append(new Soldier(id, name, rankId, roleId, team));
        } while (query.next());
    }
    else
        qDebug() << "No soldier found!";
}
