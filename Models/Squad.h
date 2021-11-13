#ifndef SQUAD_H
#define SQUAD_H

#include <QString>
#include <QList>

class Squad
{
private:
    QString name;
    QList<class Team*> teams;

public:
    Squad(const QString &name);

    const QString &getName() const;
    void setName(const QString &newName);
    const QList<Team *> &getTeams() const;
};

#endif // SQUAD_H
