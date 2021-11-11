#ifndef RANKMANAGER_H
#define RANKMANAGER_H

#include <QString>
#include <QMap>

class RankManager
{
private:
    static QMap<unsigned int, class Rank*> ranks;
public:
    static void CreateRank(const unsigned int id, const QString name, const QString abbr);
    static QString GetName(const unsigned int id);
    static QString GetAbbr(const unsigned int id);

};

#endif // RANKMANAGER_H
