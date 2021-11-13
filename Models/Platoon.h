#ifndef PLATOON_H
#define PLATOON_H

#include <QString>
#include <QList>

class Platoon
{
private:
    QList<class Squad*> squads;
    QList<class Duty*> duties;
public:
    Platoon();

    const QList<Squad *> &getSquads() const;
    const QList<Duty *> &getDuties() const;
};

#endif // PLATOON_H
