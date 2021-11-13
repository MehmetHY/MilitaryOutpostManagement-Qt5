#ifndef RANKMANAGER_H
#define RANKMANAGER_H

#include <QString>
#include <QMap>

class RankManager
{
private:

    static void CreateRank(unsigned int id, const QString name, const QString abbr);
    static void DeleteRanks();

public:
//    static QMap<unsigned int, class Rank*> ranks;
    static void Initialize();
    static void End();
    static QString GetName(unsigned int id);
    static QString GetAbbr(unsigned int id);

};

#endif // RANKMANAGER_H
