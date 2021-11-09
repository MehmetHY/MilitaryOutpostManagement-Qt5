#include "Squad.h"
#include "Platoon.h"
#include "../Managers/teammanager.h"

Squad::Squad(unsigned int id, QString name, Platoon *parent)
 : QObject(parent), squadId(id), squadName(name), teamManager(new TeamManager(this))
{

}

unsigned int Squad::GetId() const
{
    return squadId;
}

QString Squad::GetName() const
{
    return squadName;
}

TeamManager *Squad::GetTeamManager() const
{
    return teamManager;
}
