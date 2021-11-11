#ifndef RANKMANAGER_H
#define RANKMANAGER_H

#include <QString>
#include <QMap>

class RankManager
{
private:
    static QMap<unsigned int, class Rank*>* ranks;

    static void CreateRank(const unsigned int id, const QString name, const QString abbr);
    static void DeleteRanks();

public:
    static void Initialize();
    static void End();
    static QString GetName(const unsigned int id);
    static QString GetAbbr(const unsigned int id);

};

#endif // RANKMANAGER_H
