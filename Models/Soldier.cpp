#include "Soldier.h"
#include "Team.h"

Soldier::Soldier(unsigned int id, QString name, unsigned int rankId, unsigned int roleId, Team *parent) : QObject(parent), soldierId(id), soldierName(name), soldierRankId(rankId), soldierRoleId(roleId)
{

}

QString Soldier::GetName() const
{
    return soldierName;
}
