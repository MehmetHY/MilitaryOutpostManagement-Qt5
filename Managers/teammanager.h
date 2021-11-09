#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <QObject>

class TeamManager : public QObject
{
    Q_OBJECT

private:
    class Squad* squad;
    QList<class Team*>* teams;
    void LoadTeamsFromDB();
public:
    explicit TeamManager(class Squad *parent = nullptr);
    ~TeamManager();

    QList<Team*>* GetTeams() const;

signals:

};

#endif // TEAMMANAGER_H
