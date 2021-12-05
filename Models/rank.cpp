#include "rank.h"
#include "../Data/datamanager.h"

Rank::Rank()
{

}

bool Rank::isRankExist(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM rank WHERE name = :name");
    query.bindValue(":name", name);
    query.exec();
    return query.next() && query.value(0).toInt() > 0;
}

void Rank::createRank(const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO rank (name) VALUES (:name);");
    query.bindValue(":name", name);
    query.exec();
}

void Rank::deleteRank(const QString &name)
{
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
