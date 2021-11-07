#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <QObject>

class TeamManager : public QObject
{
    Q_OBJECT

private:
    QList<class Team*> teams;
public:
    explicit TeamManager(class Squad *parent = nullptr);

signals:

};

#endif // TEAMMANAGER_H
