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
