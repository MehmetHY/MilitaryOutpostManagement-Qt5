#ifndef RANK_H
#define RANK_H

#include "QString"

class Rank
{
private:
    int id;
    QString name;
public:
    Rank(const int id, const QString& name);

    static bool isRankExist(const QString& name);
    static bool isRankExist(const int id);
    static void createRank(const QString& name);
    static void deleteRank(const QString& name);
    static void getAllRankNames(QStringList& outList);
    static void updateRank(const QString& oldName, const QString& newName);
    static int getRankId(const QString& name);
    static const QString getRankName(const int id);
    static void setSoldierRanksNull(const int rankId);
    static const int getNullRankId();
    static Rank* getRankById(const int id);
};

#endif // RANK_H
