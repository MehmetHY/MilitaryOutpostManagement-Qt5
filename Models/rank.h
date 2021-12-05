#ifndef RANK_H
#define RANK_H

#include "QString"

class Rank
{
public:
    Rank();

    static bool isRankExist(const QString& name);
    static void createRank(const QString& name);
    static void deleteRank(const QString& name);
    static void getAllRankNames(QStringList& outList);
    static void updateRank(const QString& oldName, const QString& newName);
};

#endif // RANK_H
