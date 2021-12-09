#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QList>

class Team
{
private:
    int id;
    QString name;
    int squadId;

public:
    Team(const int id, const QString &name, const int squadId);

    const int getId() const;
    const QString &getName() const;
    void setName(const QString &newName);
    const int getSquadId() const;

    static bool isTeamExist(const QString& name, const int squadId);
    static void createTeam(const QString& name, const int squadId);
    static void getAllTeamNames(const int squadId, QStringList& outList);
    static void deleteTeam(const int squadId, const QString& name);
    static void updateTeam(const int squadId, const QString& oldName, const QString& newName);
    static int getTeamId(const int squadId, const QString& name);
    static Team* getTeamByName(const int squadId, const QString& name);
    static Team* getTeamById(const int id);
    static void deleteAllTeamsOfSquad(const int squadId);
};

#endif // TEAM_H
