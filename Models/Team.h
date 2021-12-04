#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QList>

class Team
{
private:
    QString name;
    QList<class Soldier*> soldiers;

    void populateSoldiers();
public:
    Team(const QString &name);

    const QString &getName() const;
    void setName(const QString &newName);
    const QList<Soldier *> &getSoldiers() const;

    static bool isTeamExist(const QString& name, const int squadId);
    static void createTeam(const QString& name, const int squadId);
    static void getAllTeamNames(const int squadId, QStringList& outList);
    static void deleteTeam(const int squadId, const QString& name);
};

#endif // TEAM_H
