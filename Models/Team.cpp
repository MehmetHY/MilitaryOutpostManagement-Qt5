#include "Team.h"
#include "Squad.h"
#include "../Managers/soldiermanager.h"

Team::Team(unsigned int id, QString name, Squad *parent)
    :   QObject(parent), teamId(id), teamName(name), soldierManager(new SoldierManager(this))
{
}
