#ifndef RANK_H
#define RANK_H

#include "QString"

class Rank
{
public:
    Rank();

    static bool isRankExist(const QString& name);
    static void createRank(const QString& name);
};

#endif // RANK_H
