#include "Team.h"

Team::Team(QObject *parent) : QObject(parent)
{

}

Team::Team(unsigned int id, QString name, Squad *squad, QObject *parent)
    :   QObject(parent), teamId(id), teamName(name), teamSquad(squad)
{

}

unsigned int Team::GetId() const
{
    return teamId;
}

QString Team::GetName() const
{
    return teamName;
}

Squad *Team::GetSquad() const
{
    return teamSquad;
}

void Team::SetSquad(Squad *squad)
{
    teamSquad = squad;
}
