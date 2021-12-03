#include "team.h"
#include "../Data/datamanager.h"
#include "soldier.h"

void Team::populateSoldiers()
{
//    const QString queryString = "SELECT * FROM soldier WHERE team_id = " + QString::number(id) +";";
//    QSqlQuery query;
//    DataManager::ExecuteQuery(query, queryString);
//    if (query.next())
//    {
//        int nameId = query.record().indexOf("name");
//        int rankId = query.record().indexOf("rank");
//        int roleId = query.record().indexOf("role");
//        do
//        {
//            QString name = query.value(nameId).toString();
//            QString rank = query.value(rankId).toString();
//            QString role = query.value(roleId).toString();
//            Soldier* soldier = new Soldier(name, rank, role);
//            soldiers << soldier;
//        } while (query.next());
//    }
}

Team::Team(const QString &name) : name(name)
{}

const QString &Team::getName() const
{
    return name;
}

void Team::setName(const QString &newName)
{
    name = newName;
}

const QList<Soldier *> &Team::getSoldiers() const
{
    return soldiers;
}

bool Team::isTeamExist(const QString &name, const int squadId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM team WHERE name = :name AND squad_id = :squadId;");
    query.bindValue(":name", name);
    query.bindValue(":squadId", squadId);
    query.exec();
    return query.next() && query.value(0).toInt() > 0;
}

void Team::createTeam(const QString &name, const int squadId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO team (name, squad_id) VALUES (:name, :squadId)");
    query.bindValue(":name", name);
    query.bindValue(":squadId", squadId);
    query.exec();
}
