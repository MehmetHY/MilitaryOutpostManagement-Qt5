#ifndef PLATOON_H
#define PLATOON_H

#include <QString>
#include <QList>

class Platoon
{
private:
    QString name;
    QList<class Squad*> squads;
    QList<class Duty*> duties;
public:
    Platoon(const QString &name);

    const QString &getName() const;
    void setName(const QString &newName);
    const QList<Squad *> &getSquads() const;
    const QList<Duty *> &getDuties() const;
};

#endif // PLATOON_H
