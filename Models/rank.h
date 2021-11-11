#ifndef RANK_H
#define RANK_H

#include <QString>

class Rank
{
private:
    const QString NAME;
    const QString ABBR;
public:
    Rank(QString name, QString abbr);

    QString GetName() const;
    QString GetAbbr() const;
};

#endif // RANK_H
