#include "rankmanager.h"
#include "../Models/rank.h"

void RankManager::Initialize()
{
}

void RankManager::End()
{
//    DeleteRanks();
}

void RankManager::CreateRank(unsigned int id, const QString name, const QString abbr)
{
//    ranks.insert(id, new Rank(name, abbr));
}

void RankManager::DeleteRanks()
{
//    foreach(Rank* rank, ranks)
//    {
//        delete rank;
//    }
//    ranks.clear();
}

QString RankManager::GetName(unsigned int id)
{
//    return ranks[id]->GetName();
    return "";
}

QString RankManager::GetAbbr(unsigned int id)
{
//    return ranks[id]->GetAbbr();
    return "";
}
