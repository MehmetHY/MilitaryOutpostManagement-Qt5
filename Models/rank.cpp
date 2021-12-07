#include "rank.h"
#include "../Data/datamanager.h"

Rank::Rank(const int id, const QString& name)
    :   id(id), name(name)
{

}

bool Rank::isRankExist(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM rank WHERE name = :name");
    query.bindValue(":name", name);
    DataManager::ExecuteQuery(query);
    return query.next() && query.value(0).toInt() > 0;
}

bool Rank::isRankExist(const int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM rank WHERE id = :id");
    query.bindValue(":id", id);
    DataManager::ExecuteQuery(query);
    return query.next() && query.value(0).toInt() > 0;
}

void Rank::createRank(const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO rank (name) VALUES (:name);");
    query.bindValue(":name", name);
    DataManager::ExecuteQuery(query);
}

void Rank::deleteRank(const QString &name)
{
    int rankId = getRankId(name);
    if (rankId) setSoldierRanksNull(rankId);
    QSqlQuery query;
    const QString queryString = "DELETE FROM rank WHERE name = '" + name + "';";
    DataManager::ExecuteQuery(query, queryString);
}

void Rank::getAllRankNames(QStringList &outList)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM rank;";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int nameId = query.record().indexOf("name");
        do
        {
            outList << query.value(nameId).toString();
        } while (query.next());
    }
}

void Rank::updateRank(const QString &oldName, const QString &newName)
{
    QSqlQuery query;
    query.prepare("UPDATE rank SET name = :newName WHERE name = :oldName;");
    query.bindValue(":oldName", oldName);
    query.bindValue(":newName", newName);
    DataManager::ExecuteQuery(query);
}

int Rank::getRankId(const QString &name)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM rank WHERE name = '" + name + "';";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int idId = query.record().indexOf("id");
        return query.value(idId).toInt();
    }
    return getNullRankId();
}

const QString Rank::getRankName(const int id)
{
    QSqlQuery query;
    const QString queryString = "SELECT * FROM rank WHERE id = " + QString::number(id) + ";";
    DataManager::ExecuteQuery(query, queryString);
    if (query.next())
    {
        int nameId = query.record().indexOf("name");
        return query.value(nameId).toString();
    }
    return "";
}

void Rank::setSoldierRanksNull(const int rankId)
{
    QSqlQuery query;
    query.prepare("UPDATE soldier SET rank_id = :nullRankId WHERE rank_id = :rankId;");
    query.bindValue(":nullRankId", getNullRankId());
    query.bindValue(":rankId", rankId);
    DataManager::ExecuteQuery(query);
}

const int Rank::getNullRankId()
{
    return getRankId("No rank");
}

Rank *Rank::getRankById(const int id)
{
    const QString name = getRankName(id);
    return new Rank(id, name);
}
