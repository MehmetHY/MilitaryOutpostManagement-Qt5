#include "rankmanager.h"
#include "../Models/rank.h"

void RankManager::Initialize()
{
    ranks = new QMap<unsigned int, Rank*>();
}

void RankManager::CreateRank(const unsigned int id, const QString name, const QString abbr)
{
    (*ranks)[id] = new Rank(name, abbr);
}

void RankManager::DeleteRanks()
{
    foreach(Rank* rank, *ranks)
    {
        delete rank;
    }
    ranks->clear();
}

QString RankManager::GetName(const unsigned int id)
{
    return (*ranks)[id]->GetName();
}

QString RankManager::GetAbbr(const unsigned int id)
{
    return (*ranks)[id]->GetAbbr();
}
