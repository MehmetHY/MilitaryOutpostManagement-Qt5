#include "rank.h"

Rank::Rank(QString name, QString abbr)
    :   NAME(name), ABBR(abbr)
{
}

QString Rank::GetName() const
{
    return NAME;
}

QString Rank::GetAbbr() const
{
    return ABBR;
}
