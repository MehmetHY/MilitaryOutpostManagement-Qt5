#include "rankmanager.h"
#include "../Models/rank.h"

void RankManager::CreateRank(const unsigned int id, const QString name, const QString abbr)
{
    ranks[id] = new Rank(name, abbr);
}

QString RankManager::GetName(const unsigned int id)
{

}

QString RankManager::GetAbbr(const unsigned int id)
{

}
