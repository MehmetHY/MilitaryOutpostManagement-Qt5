#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QList>

class Team
{
private:
    QString name;
    QList<class Soldier*> soldiers;

public:
    Team(const QString &name);

    const QString &getName() const;
    void setName(const QString &newName);
    const QList<Soldier *> &getSoldiers() const;
};

#endif // TEAM_H
